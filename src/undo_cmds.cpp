/////////////////////////////////////////////////////////////////////////////
// Purpose:   Undoable command classes derived from UndoAction
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/wupdlock.h>  // wxWindowUpdateLocker prevents window redrawing

#include "undo_cmds.h"

#include "../panels/nav_panel.h"  // NavigationPanel -- Navigation Panel
#include "mainframe.h"            // MainFrame -- Main window frame
#include "node.h"                 // Node class
#include "node_creator.h"         // NodeCreator -- Class used to create nodes
#include "node_gridbag.h"         // GridBag -- Create and modify a node containing a wxGridBagSizer

///////////////////////////////// InsertNodeAction ////////////////////////////////////

InsertNodeAction::InsertNodeAction(Node* node, Node* parent, const ttlib::cstr& undo_str, int pos) :
    UndoAction(undo_str.c_str()), m_pos(pos)
{
    m_old_selected = wxGetFrame().GetSelectedNodePtr();
    m_node = node->GetSharedPtr();
    m_parent = parent->GetSharedPtr();
}

void InsertNodeAction::Change()
{
    m_node->SetParent(m_parent);

    ASSERT_MSG(!m_parent->isGen(gen_wxGridBagSizer),
               "Only use AppendGridBagAction or InsertGridBagAction to add items to a wxGridBagSizer!");

    if (m_pos == -1 && m_parent->IsSizer() && m_parent->GetChildCount() > 0 &&
        m_parent->GetChildPtr(m_parent->GetChildCount() - 1)->isGen(gen_wxStdDialogButtonSizer))
    {
        m_parent->AddChild(m_node);
        // Add the child BEFORE any wxStdDialogButtonSizer
        m_parent->ChangeChildPosition(m_node, m_parent->GetChildCount() - 2);
    }
    else
    {
        m_parent->AddChild(m_node);
        if (m_pos >= 0)
            m_parent->ChangeChildPosition(m_node, m_pos);
    }

    if (m_fix_duplicate_names)
    {
        // This needs to be done only once, even if the insertion is reverted and then changed again. The reason is that any
        // name changes to other nodes cannot be undone.

        m_node->FixDuplicateNodeNames();
        m_fix_duplicate_names = false;
    }

    // Probably not necessary, but with both parameters set to false, this simply ensures the mainframe has it's selection
    // node set correctly.
    wxGetFrame().SelectNode(m_node.get(), false, false);
}

void InsertNodeAction::Revert()
{
    m_parent->RemoveChild(m_node);
    m_node->SetParent(NodeSharedPtr());  // Remove the parent pointer
    wxGetFrame().SelectNode(m_old_selected.get());
}

///////////////////////////////// RemoveNodeAction ////////////////////////////////////

RemoveNodeAction::RemoveNodeAction(Node* node, const ttlib::cstr& undo_str, bool AddToClipboard) :
    UndoAction(undo_str.c_str())
{
    m_AddToClipboard = AddToClipboard;
    m_node = node->GetSharedPtr();
    m_parent = node->GetParentPtr();
    m_old_pos = m_parent->GetChildPosition(node);
    m_old_selected = wxGetFrame().GetSelectedNodePtr();

    m_RedoEventGenerated = true;
    m_RedoSelectEventGenerated = true;
}

void RemoveNodeAction::Change()
{
    if (m_AddToClipboard)
        wxGetFrame().CopyNode(m_node.get());

    m_parent->RemoveChild(m_node);
    m_node->SetParent(NodeSharedPtr());

    wxGetFrame().FireDeletedEvent(m_node.get());

    if (m_parent->GetChildCount())
    {
        auto pos = (m_old_pos < m_parent->GetChildCount() ? m_old_pos : m_parent->GetChildCount() - 1);
        wxGetFrame().SelectNode(m_parent->GetChild(pos));
    }
    else
    {
        wxGetFrame().SelectNode(m_parent.get());
    }
}

void RemoveNodeAction::Revert()
{
    m_parent->AddChild(m_node);
    m_node->SetParent(m_parent);
    m_parent->ChangeChildPosition(m_node, m_old_pos);

    wxGetFrame().SelectNode(m_old_selected.get(), true, false);
}

///////////////////////////////// ModifyPropertyAction ////////////////////////////////////

ModifyPropertyAction::ModifyPropertyAction(NodeProperty* prop, ttlib::cview value) : m_property(prop)
{
    m_undo_string << "change " << prop->DeclName();

    m_change_value << value;
    m_revert_value = prop->as_string();
    m_RedoEventGenerated = true;
    m_UndoEventGenerated = true;
}

ModifyPropertyAction::ModifyPropertyAction(NodeProperty* prop, int value) : m_property(prop)
{
    m_undo_string << "change " << prop->DeclName();

    m_change_value << value;
    m_revert_value = prop->as_string();
}

void ModifyPropertyAction::Change()
{
    m_property->set_value(m_change_value);

    wxGetFrame().FirePropChangeEvent(m_property);
}

void ModifyPropertyAction::Revert()
{
    m_property->set_value(m_revert_value);

    wxGetFrame().FirePropChangeEvent(m_property);
}

///////////////////////////////// ModifyProperties ////////////////////////////////////

ModifyProperties::ModifyProperties(ttlib::cview undo_string, bool fire_events) : UndoAction(undo_string)
{
    m_fire_events = fire_events;
    m_RedoEventGenerated = true;
    m_UndoEventGenerated = true;
}

void ModifyProperties::AddProperty(NodeProperty* prop, ttlib::cview value)
{
    auto& entry = m_properties.emplace_back();
    entry.property = prop;
    entry.change_value = value;
    entry.revert_value = prop->as_string();
}

void ModifyProperties::AddProperty(NodeProperty* prop, int value)
{
    auto& entry = m_properties.emplace_back();
    entry.property = prop;
    entry.change_value << value;
    entry.revert_value = prop->as_string();
}

void ModifyProperties::Change()
{
    for (auto& iter: m_properties)
    {
        iter.property->set_value(iter.change_value);
    }

    if (m_fire_events)
        wxGetFrame().FireMultiPropEvent(this);
}

void ModifyProperties::Revert()
{
    for (auto& iter: m_properties)
    {
        iter.property->set_value(iter.revert_value);
    }

    if (m_fire_events)
        wxGetFrame().FireMultiPropEvent(this);
}

///////////////////////////////// ModifyEventAction ////////////////////////////////////

ModifyEventAction::ModifyEventAction(NodeEvent* event, ttlib::cview value) : m_event(event), m_change_value(value)
{
    m_undo_string << "change " << event->get_name() << " handler";

    m_revert_value = event->get_value();

    m_RedoEventGenerated = true;
    m_UndoEventGenerated = true;
}

void ModifyEventAction::Change()
{
    m_event->set_value(m_change_value);
    wxGetFrame().FireChangeEventHandler(m_event);
}

void ModifyEventAction::Revert()
{
    m_event->set_value(m_revert_value);
    wxGetFrame().FireChangeEventHandler(m_event);
}

///////////////////////////////// ChangePositionAction ////////////////////////////////////

ChangePositionAction::ChangePositionAction(Node* node, size_t position)
{
    m_undo_string << "change " << node->DeclName() << " position";

    m_node = node->GetSharedPtr();
    m_parent = node->GetParentPtr();

    m_change_pos = position;
    m_revert_pos = m_parent->GetChildPosition(node);

    m_UndoEventGenerated = true;
    m_RedoEventGenerated = true;
    m_UndoSelectEventGenerated = true;
    m_RedoSelectEventGenerated = true;
}

void ChangePositionAction::Change()
{
    m_parent->ChangeChildPosition(m_node, m_change_pos);
    wxGetFrame().FirePositionChangedEvent(this);
    wxGetFrame().SelectNode(m_node);
}

void ChangePositionAction::Revert()
{
    m_parent->ChangeChildPosition(m_node, m_revert_pos);
    wxGetFrame().FirePositionChangedEvent(this);
    wxGetFrame().SelectNode(m_node);
}

///////////////////////////////// ChangeSizerType ////////////////////////////////////

ChangeSizerType::ChangeSizerType(Node* node, GenEnum::GenName new_gen_sizer)
{
    m_undo_string << "change sizer type";

    m_old_node = node->GetSharedPtr();
    m_parent = node->GetParentPtr();
    m_new_gen_sizer = new_gen_sizer;

    m_node = g_NodeCreator.NewNode(m_new_gen_sizer);
    ASSERT(m_node);
    if (m_node)
    {
        if (m_new_gen_sizer == gen_wxFlexGridSizer &&
            (m_old_node->isGen(gen_wxBoxSizer) || m_old_node->isGen(gen_VerticalBoxSizer)))
        {
            if (m_old_node->prop_as_string(prop_orientation) == "wxHORIZONTAL")
            {
                m_node->prop_set_value(prop_cols, static_cast<int>(m_old_node->GetChildCount()));
            }
            else
            {
                m_node->prop_set_value(prop_cols, 0);
                m_node->prop_set_value(prop_rows, static_cast<int>(m_old_node->GetChildCount()));
            }
        }

        for (auto& iter: m_old_node->GetChildNodePtrs())
        {
            m_node->Adopt(g_NodeCreator.MakeCopy(iter.get()));
        }
    }
}

void ChangeSizerType::Change()
{
    auto pos = m_parent->GetChildPosition(m_old_node.get());
    m_parent->RemoveChild(m_old_node);
    m_old_node->SetParent(NodeSharedPtr());
    m_parent->Adopt(m_node);
    if (auto parent_form = m_parent->get_form(); parent_form)
    {
        parent_form->FixDuplicateNodeNames();
    }
    m_parent->ChangeChildPosition(m_node, pos);

    wxGetFrame().FireDeletedEvent(m_old_node.get());
    wxGetFrame().FireCreatedEvent(m_node);
    wxGetFrame().SelectNode(m_node.get());
    wxGetFrame().GetNavigationPanel()->ChangeExpansion(m_node.get(), true, true);
}

void ChangeSizerType::Revert()
{
    auto pos = m_parent->GetChildPosition(m_node.get());
    m_parent->RemoveChild(m_node);
    m_node->SetParent(NodeSharedPtr());
    m_parent->Adopt(m_old_node);
    m_parent->ChangeChildPosition(m_old_node, pos);

    wxGetFrame().FireDeletedEvent(m_node.get());
    wxGetFrame().FireCreatedEvent(m_old_node);
    wxGetFrame().SelectNode(m_old_node.get());
}

///////////////////////////////// ChangeParentAction ////////////////////////////////////

ChangeParentAction::ChangeParentAction(Node* node, Node* parent)
{
    m_undo_string << "change " << node->DeclName() << " parent";

    m_node = node->GetSharedPtr();
    m_change_parent = parent->GetSharedPtr();
    m_revert_parent = node->GetParentPtr();

    m_revert_position = m_revert_parent->GetChildPosition(node);
    m_revert_row = node->prop_as_int(prop_row);
    m_revert_col = node->prop_as_int(prop_column);

    m_UndoEventGenerated = true;
    m_RedoEventGenerated = true;
    m_UndoSelectEventGenerated = true;
    m_RedoSelectEventGenerated = true;
}

void ChangeParentAction::Change()
{
    m_revert_parent->RemoveChild(m_node);
    wxGetFrame().GetNavigationPanel()->DeleteNode(m_node.get());
    if (m_change_parent->isGen(gen_wxGridBagSizer))
    {
        GridBag grid_bag(m_change_parent.get());
        if (!grid_bag.InsertNode(m_change_parent.get(), m_node.get()))
        {
            m_node->SetParent(m_revert_parent);
            m_revert_parent->AddChild(m_node);
            m_revert_parent->ChangeChildPosition(m_node, m_revert_position);
            // Since we deleted it from Navigation Panel, need to add it back
            wxGetFrame().FireParentChangedEvent(this);
            wxGetFrame().SelectNode(m_node);
        }
    }
    else if (m_change_parent->AddChild(m_node))
    {
        m_node->SetParent(m_change_parent);

        wxGetFrame().FireParentChangedEvent(this);
        wxGetFrame().SelectNode(m_node);
    }
}

void ChangeParentAction::Revert()
{
    m_change_parent->RemoveChild(m_node);

    m_node->SetParent(m_revert_parent);
    m_revert_parent->AddChild(m_node);
    m_revert_parent->ChangeChildPosition(m_node, m_revert_position);
    if (auto prop = m_node->get_prop_ptr(prop_row); prop)
        prop->set_value(m_revert_row);
    if (auto prop = m_node->get_prop_ptr(prop_column); prop)
        prop->set_value(m_revert_col);

    wxGetFrame().FireParentChangedEvent(this);
    wxGetFrame().SelectNode(m_node);
}

///////////////////////////////// AppendGridBagAction ////////////////////////////////////

AppendGridBagAction::AppendGridBagAction(Node* node, Node* parent, int pos) : m_pos(pos)
{
    m_old_selected = wxGetFrame().GetSelectedNodePtr();
    m_node = node->GetSharedPtr();
    m_parent = parent->GetSharedPtr();
    m_old_pos = m_parent->GetChildPosition(node);

    m_undo_string << "Append " << map_GenNames[node->gen_name()];

    m_RedoEventGenerated = true;
    m_RedoSelectEventGenerated = true;
    m_UndoEventGenerated = true;
    m_UndoSelectEventGenerated = true;
}

void AppendGridBagAction::Change()
{
    m_node->SetParent(m_parent);
    if (m_pos == -1 && m_parent->GetChildCount() > 0 &&
        m_parent->GetChildPtr(m_parent->GetChildCount() - 1)->isGen(gen_wxStdDialogButtonSizer))
    {
        m_parent->AddChild(m_node);
        m_parent->ChangeChildPosition(m_node, m_parent->GetChildCount() - 2);
    }
    else
    {
        m_parent->AddChild(m_node);
        if (m_pos >= 0)
            m_parent->ChangeChildPosition(m_node, m_pos);
    }

    if (m_fix_duplicate_names)
    {
        // This needs to be done only once, even if the insertion is reverted and then changed again. The reason is that
        // any name changes to other nodes cannot be undone.

        m_node->FixDuplicateNodeNames();
        m_fix_duplicate_names = false;
    }

    wxGetFrame().FireCreatedEvent(m_node);
    wxGetFrame().SelectNode(m_node, true, true);
}

void AppendGridBagAction::Revert()
{
    m_parent->RemoveChild(m_node);
    m_node->SetParent(NodeSharedPtr());

    wxGetFrame().FireDeletedEvent(m_node.get());
    wxGetFrame().SelectNode(m_old_selected.get());
}

///////////////////////////////// GridBagAction ////////////////////////////////////

GridBagAction::GridBagAction(Node* cur_gbsizer, const ttlib::cstr& undo_str) : UndoAction(undo_str.c_str())
{
    m_RedoEventGenerated = true;
    m_RedoSelectEventGenerated = true;
    m_UndoEventGenerated = true;
    m_UndoSelectEventGenerated = true;

    m_cur_gbsizer = cur_gbsizer->GetSharedPtr();
    m_old_gbsizer = g_NodeCreator.MakeCopy(cur_gbsizer);

    auto nav_panel = wxGetFrame().GetNavigationPanel();

    // Thaw() is called when GridBagAction::Update() is called
    nav_panel->Freeze();

    for (size_t idx = 0; idx < cur_gbsizer->GetChildCount(); idx++)
    {
        nav_panel->EraseAllMaps(cur_gbsizer->GetChild(idx));
    }
}

void GridBagAction::Change()
{
    if (m_isReverted)
    {
        auto nav_panel = wxGetFrame().GetNavigationPanel();
        wxWindowUpdateLocker freeze(nav_panel);

        for (size_t idx = 0; idx < m_cur_gbsizer->GetChildCount(); idx++)
        {
            nav_panel->EraseAllMaps(m_cur_gbsizer->GetChild(idx));
        }

        auto save = g_NodeCreator.MakeCopy(m_cur_gbsizer);
        m_cur_gbsizer->RemoveAllChildren();
        for (size_t idx = 0; idx < m_old_gbsizer->GetChildCount(); ++idx)
        {
            m_cur_gbsizer->Adopt(g_NodeCreator.MakeCopy(m_old_gbsizer->GetChild(idx)));
        }
        m_old_gbsizer = std::move(save);
        m_isReverted = false;

        nav_panel->AddAllChildren(m_cur_gbsizer.get());
        nav_panel->ExpandAllNodes(m_cur_gbsizer.get());

        wxGetFrame().FireGridBagActionEvent(this);
        wxGetFrame().SelectNode(m_cur_gbsizer);
    }
}

void GridBagAction::Revert()
{
    auto nav_panel = wxGetFrame().GetNavigationPanel();
    wxWindowUpdateLocker freeze(nav_panel);

    for (size_t idx = 0; idx < m_cur_gbsizer->GetChildCount(); idx++)
    {
        nav_panel->EraseAllMaps(m_cur_gbsizer->GetChild(idx));
    }

    auto save = g_NodeCreator.MakeCopy(m_cur_gbsizer);
    m_cur_gbsizer->RemoveAllChildren();
    for (size_t idx = 0; idx < m_old_gbsizer->GetChildCount(); ++idx)
    {
        m_cur_gbsizer->Adopt(g_NodeCreator.MakeCopy(m_old_gbsizer->GetChild(idx)));
    }
    m_old_gbsizer = std::move(save);
    m_isReverted = true;

    nav_panel->AddAllChildren(m_cur_gbsizer.get());
    nav_panel->ExpandAllNodes(m_cur_gbsizer.get());

    wxGetFrame().FireGridBagActionEvent(this);
    wxGetFrame().SelectNode(m_cur_gbsizer);
}

void GridBagAction::Update()
{
    auto nav_panel = wxGetFrame().GetNavigationPanel();

    for (size_t idx = 0; idx < m_cur_gbsizer->GetChildCount(); idx++)
    {
        nav_panel->EraseAllMaps(m_cur_gbsizer->GetChild(idx));
    }

    nav_panel->AddAllChildren(m_cur_gbsizer.get());
    nav_panel->ExpandAllNodes(m_cur_gbsizer.get());
    nav_panel->Thaw();
}

///////////////////////////////// SortProjectAction ////////////////////////////////////

static bool CompareClassNames(NodeSharedPtr a, NodeSharedPtr b)
{
    return (a->prop_as_string(prop_class_name).compare(b->prop_as_string(prop_class_name)) < 0);
}

SortProjectAction::SortProjectAction()
{
    m_RedoEventGenerated = true;
    m_RedoSelectEventGenerated = true;
    m_UndoEventGenerated = true;
    m_UndoSelectEventGenerated = true;

    m_undo_string = "Sort Project";

    m_old_project = g_NodeCreator.MakeCopy(wxGetApp().GetProject());
}

void SortProjectAction::Change()
{
    m_old_project = g_NodeCreator.MakeCopy(wxGetApp().GetProjectPtr());
    auto project = wxGetApp().GetProject();

    auto& children = project->GetChildNodePtrs();
    std::sort(children.begin(), children.end(), CompareClassNames);

    wxGetFrame().FireProjectUpdatedEvent();
    wxGetFrame().SelectNode(project);
}

void SortProjectAction::Revert()
{
    auto project = wxGetApp().GetProject();
    project->RemoveAllChildren();
    for (size_t idx = 0; idx < m_old_project->GetChildCount(); ++idx)
    {
        project->Adopt(g_NodeCreator.MakeCopy(m_old_project->GetChild(idx)));
    }

    wxGetFrame().FireProjectUpdatedEvent();
    wxGetFrame().SelectNode(project);
}
