/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxDialog generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/dialog.h>  // wxDialogBase class

#include "gen_base.h"       // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "gen_common.h"     // GeneratorLibrary -- Generator classes
#include "gen_xrc_utils.h"  // Common XRC generating functions
#include "node.h"           // Node class
#include "pugixml.hpp"      // xml read/write/create/process
#include "utils.h"          // Utility functions that work with properties
#include "write_code.h"     // WriteCode -- Write code to Scintilla or file

#include "gen_dialog.h"

bool DialogFormGenerator::GenConstruction(Node* node, BaseCodeGenerator* code_gen)
{
    auto src_code = code_gen->GetSrcWriter();

    ttlib::cstr code;

    code << "bool " << node->prop_as_string(prop_class_name)
         << "::Create(wxWindow* parent, wxWindowID id, const wxString& title,\n\t\tconst wxPoint& pos, const wxSize& size, "
            "long "
            "style, const wxString &name)\n{\n\tif (!wxDialog::Create(parent, id, title, pos, size, style, "
            "name))\n\t\treturn "
            "false;\n\n";

    src_code->writeLine(code, indent::none);
    src_code->Indent();
    code.clear();

    if (node->HasValue(prop_extra_style))
    {
        code << "SetExtraStyle(GetExtraStyle() | " << node->prop_as_string(prop_extra_style) << ");";
        src_code->writeLine(code);
        code.clear();
    }

    if (node->HasValue(prop_icon))
    {
        code_gen->GenerateHandlers();
        auto icon_code = GenerateIconCode(node->prop_as_string(prop_icon));
        src_code->writeLine(icon_code, indent::auto_keep_whitespace);
    }

    code << GenFontColourSettings(node);
    if (code.size())
    {
        src_code->writeLine(code);
        code.clear();
    }

    src_code->Unindent();
    src_code->writeLine();

    return true;
}

std::optional<ttlib::cstr> DialogFormGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    return GenEventCode(event, class_name);
}

std::optional<ttlib::cstr> DialogFormGenerator::GenAdditionalCode(GenEnum::GenCodeType cmd, Node* node)
{
    if (cmd == code_after_children)
    {
        ttlib::cstr code;

        Node* dlg;
        if (node->IsForm())
        {
            dlg = node;
            ASSERT_MSG(dlg->GetChildCount(), "Trying to generate code for a dialog with no children.")
            if (!dlg->GetChildCount())
                return {};  // empty dialog, so nothing to do
            ASSERT_MSG(dlg->GetChild(0)->IsSizer(), "Expected first child of a dialog to be a sizer.");
            if (dlg->GetChild(0)->IsSizer())
                node = dlg->GetChild(0);
        }
        else
        {
            dlg = node->get_form();
        }

        auto min_size = dlg->prop_as_wxSize(prop_minimum_size);
        auto max_size = dlg->prop_as_wxSize(prop_maximum_size);
        auto size = dlg->prop_as_wxSize(prop_size);

        if (min_size == wxDefaultSize && max_size == wxDefaultSize)
        {
            code << "\tSetSizerAndFit(" << node->get_node_name() << ");";
        }
        else
        {
            code << "\tSetSizer(" << node->get_node_name() << ");";
            if (min_size != wxDefaultSize)
            {
                code << "\n\tSetMinSize(wxSize(" << min_size.GetWidth() << ", " << min_size.GetHeight() << "));";
            }
            if (max_size != wxDefaultSize)
            {
                code << "\n\tSetMaxSize(wxSize(" << max_size.GetWidth() << ", " << max_size.GetHeight() << "));";
            }
            code << "\n\tFit();";
        }

        if (size != wxDefaultSize)
        {
            code << "\n\tSetSize(wxSize(" << size.GetWidth() << ", " << size.GetHeight() << "));";
        }

        auto& center = dlg->prop_as_string(prop_center);
        if (center.size() && !center.is_sameas("no"))
        {
            code << "\n\tCentre(" << center << ");";
        }

        return code;
    }
    else if (cmd == code_header)
    {
        ttlib::cstr code;
        code.reserve(256);

        code << node->get_node_name() << "() {}\n";
        code << node->get_node_name() << "(wxWindow *parent, ";
        code << "wxWindowID id = " << node->prop_as_string(prop_id) << ", ";
        code << "const wxString& title = " << GenerateQuotedString(node, prop_title) << ",\n\t";
        code << "const wxPoint& pos = ";

        auto position = node->prop_as_wxPoint(prop_pos);
        if (position == wxDefaultPosition)
            code << "wxDefaultPosition, ";
        else
            code << "wxPoint(" << position.x << ", " << position.y << "), ";

        code << "const wxSize& size = ";

        auto size = node->prop_as_wxSize(prop_size);
        if (size == wxDefaultSize)
            code << "wxDefaultSize";
        else
            code << "wxSize(" << size.x << ", " << size.y << ")";

        code << ",\n\tlong style = ";
        if (node->HasValue(prop_style))
            code << node->prop_as_string(prop_style);
        else
            code << "wxDEFAULT_DIALOG_STYLE";

        code << ", const wxString &name = ";
        if (node->HasValue(prop_window_name))
            code << GenerateQuotedString(node, prop_window_name);
        else
            code << "wxDialogNameStr";

        code << ")\n{\n\tCreate(parent, id, title, pos, size, style, name);\n}\n";

        code << "\nbool Create(wxWindow *parent, ";
        code << "wxWindowID id = " << node->prop_as_string(prop_id) << ", ";
        code << "const wxString& title = " << GenerateQuotedString(node, prop_title) << ",\n\t";
        code << "const wxPoint& pos = ";

        if (position == wxDefaultPosition)
            code << "wxDefaultPosition, ";
        else
            code << "wxPoint(" << position.x << ", " << position.y << "), ";

        code << "const wxSize& size = ";

        if (size == wxDefaultSize)
            code << "wxDefaultSize";
        else
            code << "wxSize(" << size.x << ", " << size.y << ")";

        code << ",\n\tlong style = ";
        if (node->HasValue(prop_style))
            code << node->prop_as_string(prop_style);
        else
            code << "wxDEFAULT_DIALOG_STYLE";

        code << ", const wxString &name = ";
        if (node->HasValue(prop_window_name))
            code << GenerateQuotedString(node, prop_window_name);
        else
            code << "wxDialogNameStr";

        code << ");\n\n";

        return code;
    }

    else
    {
        return GenFormCode(cmd, node);
    }
}

bool DialogFormGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/dialog.h>", set_src, set_hdr);
    return true;
}

int DialogFormGenerator::GenXrcObject(Node* node, pugi::xml_node& object, bool add_comments)
{
    // We use item so that the macros in base_generator.h work, and the code looks the same
    // as other widget XRC generatorsl
    auto item = object;
    GenXrcObjectAttributes(node, item, "wxDialog");

    ADD_ITEM_PROP(prop_title, "title")

    if (node->HasValue(prop_style))
    {
        if (add_comments && node->prop_as_string(prop_style).contains("wxWANTS_CHARS"))
        {
            item.append_child(pugi::node_comment)
                .set_value("The wxWANTS_CHARS style will be ignored when the XRC is loaded.");
        }
        if (!node->HasValue(prop_extra_style))
        {
            item.append_child("style").text().set(node->prop_as_string(prop_style));
        }
        else
        {
            ttlib::cstr all_styles = node->prop_as_string(prop_style);
            all_styles << '|' << node->prop_as_string(prop_extra_style);
            item.append_child("style").text().set(all_styles);
        }
    }

    if (node->HasValue(prop_pos))
        item.append_child("pos").text().set(node->prop_as_string(prop_pos));
    if (node->HasValue(prop_size))
        item.append_child("size").text().set(node->prop_as_string(prop_size));

    if (node->HasValue(prop_center))
    {
        if (node->prop_as_string(prop_center).is_sameas("wxVERTICAL") ||
            node->prop_as_string(prop_center).is_sameas("wxHORIZONTAL"))
        {
            if (add_comments)
            {
                item.append_child(pugi::node_comment)
                    .set_value((ttlib::cstr(node->prop_as_string(prop_center)) << " cannot be be set in the XRC file."));
            }
            item.append_child("centered").text().set(1);
        }
        else
        {
            item.append_child("centered").text().set(node->prop_as_string(prop_center).is_sameas("no") ? 0 : 1);
        }
    }

    if (node->HasValue(prop_icon))
    {
        ttlib::multistr parts(node->prop_as_string(prop_icon), ';', tt::TRIM::both);
        ASSERT(parts.size() > 1)
        if (parts[IndexType].is_sameas("Art"))
        {
            ttlib::multistr art_parts(parts[IndexArtID], '|');
            auto icon = item.append_child("icon");
            icon.append_attribute("stock_id").set_value(art_parts[0]);
            icon.append_attribute("stock_client").set_value(art_parts[1]);
        }
        else
        {
            // REVIEW: [KeyWorks - 05-13-2022] As of wxWidgets 3.1.6, SVG files do not work here
            item.append_child("icon").text().set(parts[IndexImage]);
        }
    }

    if (add_comments)
    {
        if (node->prop_as_bool(prop_persist))
            item.append_child(pugi::node_comment).set_value(" persist is not supported in the XRC file. ");

        GenXrcComments(node, item);
    }

    return xrc_updated;
}

void DialogFormGenerator::RequiredHandlers(Node* node, std::set<std::string>& handlers)
{
    handlers.emplace("wxDialogXmlHandler");
    if (node->HasValue(prop_icon))
    {
        handlers.emplace("wxIconXmlHandler");
        handlers.emplace("wxBitmapXmlHandler");
    }
}