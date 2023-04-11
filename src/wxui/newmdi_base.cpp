///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "newmdi_base.h"

bool NewMdiForm::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_3 = new wxStaticText(this, wxID_ANY,
        "These are initial values -- all of them can be changed after the frame is created.");
    staticText_3->Wrap(300);
    box_sizer_3->Add(staticText_3, wxSizerFlags().Border(wxALL));

    m_infoBar = new wxInfoBar(this);
    m_infoBar->SetShowHideEffects(wxSHOW_EFFECT_NONE, wxSHOW_EFFECT_NONE);
    m_infoBar->SetEffectDuration(500);
    box_sizer_3->Add(m_infoBar, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_9 = new wxStaticText(this, wxID_ANY, "&Base class name:");
    staticText_9->SetToolTip("Change this to something unique to your project.");
    box_sizer_2->Add(staticText_9, wxSizerFlags().Center().Border(wxALL));

    auto* classname = new wxTextCtrl(this, wxID_ANY, "MyMdiAppBase");
    classname->SetValidator(wxTextValidator(wxFILTER_NONE, &m_base_class));
    classname->SetToolTip("Change this to something unique to your project.");
    box_sizer_2->Add(classname, wxSizerFlags(1).Border(wxALL));

    box_sizer_3->Add(box_sizer_2, wxSizerFlags().Expand().Border(wxALL));

    auto* class_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText = new wxStaticText(this, wxID_ANY, "&Frame type:");
    class_sizer->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_choice_type = new wxChoice(this, wxID_ANY);
    m_choice_type->Append("wxAuiMDIParentFrame");
    m_choice_type->Append("wxDocMDIParentFrame");
    m_mdi_type = "wxDocMDIParentFrame";  // set validator variable
    m_choice_type->SetValidator(wxGenericValidator(&m_mdi_type));
    class_sizer->Add(m_choice_type, wxSizerFlags(1).Border(wxALL));

    box_sizer_3->Add(class_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* flex_grid_sizer = new wxFlexGridSizer(2, 0, 0);
    {
        flex_grid_sizer->AddGrowableCol(1, 1);
    }

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "&Description:");
    flex_grid_sizer->Add(staticText_2, wxSizerFlags().Center().Border(wxALL));

    auto* description = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    description->SetHint("Text");
    description->SetValidator(wxTextValidator(wxFILTER_NONE, &m_description));
    description->SetToolTip(
    "A short description of what the template is for. This string will be displayed in the file filter list of Windows file selectors. ");
    flex_grid_sizer->Add(description, wxSizerFlags().Expand().Border(wxALL));

    auto* staticText_6 = new wxStaticText(this, wxID_ANY, "&View Type:");
    flex_grid_sizer->Add(staticText_6, wxSizerFlags().Border(wxALL));

    auto* choice_view = new wxChoice(this, wxID_ANY);
    choice_view->Append("Text Control");
    choice_view->Append("Image");
    m_view_type = "Text Control";  // set validator variable
    choice_view->SetValidator(wxGenericValidator(&m_view_type));
    flex_grid_sizer->Add(choice_view, wxSizerFlags(1).Border(wxALL));

    auto* staticText_4 = new wxStaticText(this, wxID_ANY, "&Filter:");
    flex_grid_sizer->Add(staticText_4, wxSizerFlags().Center().Border(wxALL));

    auto* filter = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    filter->SetHint("*.txt");
    filter->SetValidator(wxTextValidator(wxFILTER_NONE, &m_filter));
    filter->SetToolTip("An appropriate file filter such as \"*.txt\". ");
    flex_grid_sizer->Add(filter, wxSizerFlags().Expand().Border(wxALL));

    auto* staticText_5 = new wxStaticText(this, wxID_ANY, "&Extension:");
    flex_grid_sizer->Add(staticText_5, wxSizerFlags().Center().Border(wxALL));

    auto* extension = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    extension->SetHint("txt");
    extension->SetValidator(wxTextValidator(wxFILTER_NONE, &m_default_extension));
    extension->SetToolTip("An appropriate file filter such as \"*.txt\". ");
    flex_grid_sizer->Add(extension, wxSizerFlags().Expand().Border(wxALL));

    auto* staticText_7 = new wxStaticText(this, wxID_ANY, "D&oc Name:");
    flex_grid_sizer->Add(staticText_7, wxSizerFlags().Border(wxALL));

    auto* doc_name = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    doc_name->SetHint("Text Document");
    doc_name->SetValidator(wxTextValidator(wxFILTER_NONE, &m_doc_name));
    doc_name->SetToolTip("An appropriate file filter such as \"*.txt\". ");
    flex_grid_sizer->Add(doc_name, wxSizerFlags().Expand().Border(wxALL));

    auto* staticText_8 = new wxStaticText(this, wxID_ANY, "V&iew Name:");
    flex_grid_sizer->Add(staticText_8, wxSizerFlags().Border(wxALL));

    auto* view_name = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    view_name->SetHint("Text View");
    view_name->SetValidator(wxTextValidator(wxFILTER_NONE, &m_view_name));
    view_name->SetToolTip("An appropriate file filter such as \"*.txt\". ");
    flex_grid_sizer->Add(view_name, wxSizerFlags().Expand().Border(wxALL));

    box_sizer_3->Add(flex_grid_sizer, wxSizerFlags(1).Expand().Border(wxALL));

    box_sizer->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    box_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(box_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_BUTTON, &NewMdiForm::OnOK, this, wxID_OK);
    choice_view->Bind(wxEVT_CHOICE, &NewMdiForm::OnViewType, this);
    Bind(wxEVT_INIT_DIALOG,
        [this](wxInitDialogEvent& event)
        {
            m_choice_type->SetFocus();
            event.Skip();
        });
    classname->Bind(wxEVT_TEXT,
        [this](wxCommandEvent&)
        {VerifyClassName();
        });

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
