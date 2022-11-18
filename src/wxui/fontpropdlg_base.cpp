////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>

#include "fontpropdlg_base.h"

bool FontPropDlgBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    m_radioSystem = new wxRadioButton(this, wxID_ANY, "Default GUI Font");
    m_system_box = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY,m_radioSystem), wxVERTICAL);
    dlg_sizer->Add(m_system_box, wxSizerFlags().Expand().DoubleBorder(wxALL));

    auto* box_sizer_10 = new wxBoxSizer(wxHORIZONTAL);
    m_system_box->Add(box_sizer_10, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer_11 = new wxBoxSizer(wxVERTICAL);
    box_sizer_10->Add(box_sizer_11, wxSizerFlags().Border(wxALL));

    auto* staticText_7 = new wxStaticText(m_system_box->GetStaticBox(), wxID_ANY, "Si&ze:");
    box_sizer_11->Add(staticText_7, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboSymbolSize = new wxComboBox(m_system_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    box_sizer_11->Add(m_comboSymbolSize, wxSizerFlags().Border(wxALL));

    auto* box_sizer_15 = new wxBoxSizer(wxVERTICAL);
    box_sizer_10->Add(box_sizer_15, wxSizerFlags().Border(wxALL));

    auto* staticText_8 = new wxStaticText(m_system_box->GetStaticBox(), wxID_ANY, "&Style:");
    box_sizer_15->Add(staticText_8, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboSystemStyles = new wxComboBox(m_system_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    box_sizer_15->Add(m_comboSystemStyles, wxSizerFlags().Border(wxALL));

    auto* box_sizer_16 = new wxBoxSizer(wxVERTICAL);
    box_sizer_10->Add(box_sizer_16, wxSizerFlags().Border(wxALL));

    auto* staticText_9 = new wxStaticText(m_system_box->GetStaticBox(), wxID_ANY, "&Weight:");
    box_sizer_16->Add(staticText_9, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboSystemWeight = new wxComboBox(m_system_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    box_sizer_16->Add(m_comboSystemWeight, wxSizerFlags().Border(wxALL));

    auto* box_sizer_12 = new wxBoxSizer(wxVERTICAL);
    box_sizer_10->Add(box_sizer_12, wxSizerFlags(1).Expand().Border(wxALL));

    m_staticSystemSample = new wxStaticText(m_system_box->GetStaticBox(), wxID_ANY, "Sample");
    m_staticSystemSample->SetToolTip("This sample text will show you how the text will look on the current operating system. The font will be different when your program is used on a different operating systems.");
    box_sizer_12->Add(m_staticSystemSample, wxSizerFlags(1).Center().Border(wxALL));

    auto* box_sizer_19 = new wxBoxSizer(wxHORIZONTAL);
    m_system_box->Add(box_sizer_19, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer_17 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer_19->Add(box_sizer_17, wxSizerFlags().Expand().Border(wxALL));

    m_checkSystemUnderlined = new wxCheckBox(m_system_box->GetStaticBox(), wxID_ANY, "&Underlined");
    box_sizer_17->Add(m_checkSystemUnderlined, wxSizerFlags().Border(wxALL));

    m_checkSystemStrikeThrough = new wxCheckBox(m_system_box->GetStaticBox(), wxID_ANY, "S&trikethrough");
    box_sizer_17->Add(m_checkSystemStrikeThrough, wxSizerFlags().Border(wxALL));

    dlg_sizer->AddSpacer(20);

    m_radioCustom = new wxRadioButton(this, wxID_ANY, "Custom Font");
    m_custom_box = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY,m_radioCustom), wxVERTICAL);
    dlg_sizer->Add(m_custom_box, wxSizerFlags().Expand().DoubleBorder(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    m_custom_box->Add(box_sizer_3, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);
    box_sizer_3->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* staticText = new wxStaticText(m_custom_box->GetStaticBox(), wxID_ANY, "F&amily:");
    box_sizer->Add(staticText, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboFamily = new wxComboBox(m_custom_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    box_sizer->Add(m_comboFamily, wxSizerFlags().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);
    box_sizer_3->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    auto* staticText_2 = new wxStaticText(m_custom_box->GetStaticBox(), wxID_ANY, "Styl&e:");
    box_sizer_2->Add(staticText_2, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboCustomStyles = new wxComboBox(m_custom_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    box_sizer_2->Add(m_comboCustomStyles, wxSizerFlags().Border(wxALL));

    auto* box_sizer_4 = new wxBoxSizer(wxVERTICAL);
    box_sizer_3->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* staticText_3 = new wxStaticText(m_custom_box->GetStaticBox(), wxID_ANY, "We&ight:");
    box_sizer_4->Add(staticText_3, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboCustomWeight = new wxComboBox(m_custom_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    box_sizer_4->Add(m_comboCustomWeight, wxSizerFlags().Border(wxALL));

    auto* box_sizer_8 = new wxBoxSizer(wxVERTICAL);
    box_sizer_3->Add(box_sizer_8, wxSizerFlags(1).Expand().Border(wxALL));

    auto* staticText_5 = new wxStaticText(m_custom_box->GetStaticBox(), wxID_ANY, "Face&name:");
    box_sizer_8->Add(staticText_5, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_comboFacenames = new wxComboBox(m_custom_box->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY|wxCB_SORT);
    m_comboFacenames->Append("default");
    m_comboFacenames->SetStringSelection("default");
    m_comboFacenames->SetToolTip("Leave Facename set to default to create a font that isn\'t dependent on a user\'s installed fonts.");
    box_sizer_8->Add(m_comboFacenames, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxHORIZONTAL);
    m_custom_box->Add(box_sizer_5, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer_6 = new wxBoxSizer(wxVERTICAL);
    box_sizer_5->Add(box_sizer_6, wxSizerFlags().Border(wxALL));

    auto* staticText_4 = new wxStaticText(m_custom_box->GetStaticBox(), wxID_ANY, "&Point Size:");
    box_sizer_6->Add(staticText_4, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_spinCustomPointSize = new wxSpinCtrlDouble(m_custom_box->GetStaticBox(), wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 4, 72, 9, 0.5);
    m_spinCustomPointSize->SetDigits(1);
    box_sizer_6->Add(m_spinCustomPointSize, wxSizerFlags().Border(wxALL));

    auto* box_sizer_13 = new wxBoxSizer(wxVERTICAL);
    box_sizer_5->Add(box_sizer_13, wxSizerFlags().Border(wxALL));

    box_sizer_13->AddSpacer(20);

    auto* box_sizer_7 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer_13->Add(box_sizer_7, wxSizerFlags().Border(wxALL));

    m_checkCustomUnderlined = new wxCheckBox(m_custom_box->GetStaticBox(), wxID_ANY, "Un&derlined");
    box_sizer_7->Add(m_checkCustomUnderlined, wxSizerFlags().Border(wxALL));

    m_checkCustomStrikeThrough = new wxCheckBox(m_custom_box->GetStaticBox(), wxID_ANY, "Striket&hrough");
    box_sizer_7->Add(m_checkCustomStrikeThrough, wxSizerFlags().Border(wxALL));

    auto* box_sizer_9 = new wxBoxSizer(wxVERTICAL);
    box_sizer_5->Add(box_sizer_9, wxSizerFlags(1).Expand().Border(wxALL));

    m_staticCustomSample = new wxStaticText(m_custom_box->GetStaticBox(), wxID_ANY, "Sample");
    box_sizer_9->Add(m_staticCustomSample, wxSizerFlags(1).Center().Border(wxALL));

    dlg_sizer->AddSpacer(20);

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &FontPropDlgBase::OnInit, this);
    m_radioSystem->Bind(wxEVT_RADIOBUTTON, &FontPropDlgBase::OnSystemRadio, this);
    m_comboSymbolSize->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnSymbolSize, this);
    m_comboSystemStyles->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnStyle, this);
    m_comboSystemWeight->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnWeight, this);
    m_checkSystemUnderlined->Bind(wxEVT_CHECKBOX, &FontPropDlgBase::OnUnderlined, this);
    m_checkSystemStrikeThrough->Bind(wxEVT_CHECKBOX, &FontPropDlgBase::OnStrikeThrough, this);
    m_radioCustom->Bind(wxEVT_RADIOBUTTON, &FontPropDlgBase::OnCustomRadio, this);
    m_comboFamily->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnFamily, this);
    m_comboCustomStyles->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnStyle, this);
    m_comboCustomWeight->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnWeight, this);
    m_comboFacenames->Bind(wxEVT_COMBOBOX, &FontPropDlgBase::OnFacename, this);
    m_spinCustomPointSize->Bind(wxEVT_SPINCTRLDOUBLE, &FontPropDlgBase::OnPointSize, this);
    m_spinCustomPointSize->Bind(wxEVT_TEXT, &FontPropDlgBase::OnEditPointSize, this);
    m_checkCustomUnderlined->Bind(wxEVT_CHECKBOX, &FontPropDlgBase::OnUnderlined, this);
    m_checkCustomStrikeThrough->Bind(wxEVT_CHECKBOX, &FontPropDlgBase::OnStrikeThrough, this);
    Bind(wxEVT_BUTTON, &FontPropDlgBase::OnOK, this, wxID_OK);

    return true;
}
