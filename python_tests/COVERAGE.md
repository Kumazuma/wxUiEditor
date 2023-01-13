# Contents

The following tables indicate whether or not code is being generated in the `pytest` or `cpptest` apps. A "???" indicates it is not currently used. "no" indcates that the language doesn't support it. "---" in the XRC column indicates that it could be generated, but there is no current testing for it.


XRC is listed, but there is currently no testing code for it. "---" in the XRC column means it could be generated. "no" indicates that XRC does not support the class.

# Categories

### Books

| Class | C++ | Python | XRC |file |
-----------|-----|--------|------|------|
| wxAuiNotebook | ??? | ??? | --- | ../src/generate/gen_aui_notebook.cpp |
| wxChoicebook | ??? | ??? | --- | ../src/generate/gen_choicebook.cpp |
| wxListbook | ??? | ??? | --- | ../src/generate/gen_listbook.cpp |
| wxNotebook | ??? | ??? | --- | ../src/generate/gen_notebook.cpp |
| wxSimplebook | ??? | ??? | --- | ../src/generate/gen_simplebook.cpp |
| wxToolbook | ??? | ??? | --- | ../src/generate/gen_toolbook.cpp |
| wxTreebook | ??? | ??? | --- | ../src/generate/gen_treebook.cpp |

### Forms

| Class | C++ | Python | XRC |file |
-----------|-----|--------|------|------|
| wxDialog | ??? | ??? | --- | ../src/generate/gen_dialog.cpp |
| wxFrame | ??? | ??? | --- | ../src/generate/gen_frame.cpp |
| wxMenu | ??? | ??? | --- | ../src/generate/menu_widgets.cpp |
| wxMenuBar | ??? | ??? | --- | ../src/generate/menu_widgets.cpp |
| wxPanel | ??? | ??? | --- | ../src/generate/gen_panel_form.cpp |
| wxPopupTransientWindow | ??? | ??? | no | ../src/generate/gen_popup_trans_win.cpp |
| wxRibbonBar | ??? | ??? | --- | ../src/generate/gen_ribbon_bar.cpp |
| wxToolBar | ??? | ??? | --- | ../src/generate/gen_toolbar.cpp |
| wxWizard | ??? | ??? | --- | ../src/generate/gen_wizard.cpp |

### Pickers

| Class | C++ | Python | XRC |file |
-----------|-----|--------|------|------|
| wxColourPickerCtrl | ??? | ??? | --- | ../src/generate/gen_clr_picker.cpp |
| wxDatePickerCtrl | ??? | ??? | --- | ../src/generate/gen_date_picker.cpp |
| wxDirPickerCtrl | ??? | ??? | --- | ../src/generate/gen_dir_picker.cpp |
| wxFilePickerCtrl | ??? | ??? | --- | ../src/generate/gen_file_picker.cpp |
| wxFontPickerCtrl | ??? | ??? | --- | ../src/generate/gen_font_picker.cpp |
| wxTimePickerCtrl | ??? | ??? | --- | ../src/generate/gen_time_picker.cpp |

### Sizers

| Class | C++ | Python | XRC |file |
-----------|-----|--------|------|------|
| wxBoxSizer | ??? | ??? | --- | ../src/generate/gen_box_sizer.cpp |
| wxCheckBoxSizer | ??? | no | --- | ../src/generate/gen_statchkbox_sizer.cpp |
| wxFlexGridSizer | ??? | ??? | --- | ../src/generate/gen_flexgrid_sizer.cpp |
| wxGridBagSizer | ??? | ??? | --- | ../src/generate/gen_gridbag_sizer.cpp |
| wxGridSizer | ??? | ??? | --- | ../src/generate/gen_grid_sizer.cpp |
| wxRadioButtonSizer | ??? | no | --- | ../src/generate/gen_statradiobox_sizer.cpp |
| wxStaticBoxSizer | ??? | ??? | --- | ../src/generate/gen_staticbox_sizer.cpp |
| wxStdDialogButtonSizer | ??? | ??? | --- | ../src/generate/gen_std_dlgbtn_sizer.cpp |
| wxWrapSizer | ??? | ??? | --- | ../src/generate/gen_wrap_sizer.cpp |

# Classes

| Class | C++ | Python | XRC |file |
-----------|-----|--------|------|------|
| wxActivityIndicator | ??? | ??? | --- | ../src/generate/gen_activity.cpp |
| wxAnimationCtrl | ??? | ??? | --- | ../src/generate/gen_animation.cpp |
| wxAuiToolBar | ??? | ??? | --- | ../src/generate/gen_aui_toolbar.cpp |
| wxBannerWindow | ??? | ??? | --- | ../src/generate/gen_banner_window.cpp |
| wxBitmapComboBox | ??? | ??? | --- | ../src/generate/gen_bitmap_combo.cpp |
| wxButton | ??? | ??? | --- | ../src/generate/gen_button.cpp |
| wxCalendarCtrl | ??? | ??? | --- | ../src/generate/gen_calendar_ctrl.cpp |
| wxCheckBox | ??? | ??? | --- | ../src/generate/gen_checkbox.cpp |
| wxCheckListBox | ??? | ??? | --- | ../src/generate/gen_check_listbox.cpp |
| wxChoice | ??? | ??? | --- | ../src/generate/gen_choice.cpp |
| wxCollapsiblePane | ??? | ??? | --- | ../src/generate/gen_collapsible.cpp |
| wxComboBox | ??? | ??? | --- | ../src/generate/gen_combobox.cpp |
| wxCommandLinkButton | ??? | ??? | --- | ../src/generate/gen_cmd_link_btn.cpp |
| wxDataViewListCtrl | ??? | ??? | --- | ../src/generate/dataview_widgets.cpp |
| wxDataViewCtrl | ??? | ??? | --- | ../src/generate/dataview_widgets.cpp |
| wxEditableListBox | ??? | ??? | --- | ../src/generate/gen_edit_listbox.cpp |
| wxFileCtrl | ??? | ??? | --- | ../src/generate/gen_file_ctrl.cpp |
| wxGauge | ??? | ??? | --- | ../src/generate/gen_gauge.cpp |
| wxGenericDirCtrl | ??? | ??? | --- | ../src/generate/gen_dir_ctrl.cpp |
| wxGrid | ??? | ??? | --- | ../src/generate/gen_grid.cpp |
| wxHtmlWindow | ??? | ??? | --- | ../src/generate/gen_html_window.cpp |
| wxHyperlinkCtrl | ??? | ??? | --- | ../src/generate/gen_hyperlink.cpp |
| wxInfoBar | ??? | ??? | --- | ../src/generate/gen_infobar.cpp |
| wxListBox | ??? | ??? | --- | ../src/generate/gen_listbox.cpp |
| wxListView | ??? | ??? | --- | ../src/generate/gen_listview.cpp |
| wxMenu | ??? | ??? | --- | ../src/generate/gen_menu.cpp |
| wxMenuBar | ??? | ??? | --- | ../src/generate/menu_widgets.cpp |
| wxMenuItem | ??? | ??? | --- | ../src/generate/gen_menuitem.cpp |
| wxPanel | ??? | ??? | --- | ../src/generate/gen_panel.cpp |
| wxPropertyGrid | ??? | ??? | no | ../src/generate/gen_prop_grid.cpp |
| wxPropertyGridManager | ??? | ??? | no | ../src/generate/grid_widgets.cpp |
| wxRadioBox | ??? | ??? | --- | ../src/generate/gen_prop_grid.cpp |
| wxRadioButton | ??? | ??? | --- | ../src/generate/gen_radio_btn.cpp |
| wxRearrangeCtrl | ??? | ??? | no | ../src/generate/gen_rearrange.cpp |
| wxRibbonBar | ??? | ??? | --- | ../src/generate/gen_ribbon_bar.cpp |
| wxRibbonButtonBar | ??? | ??? | --- | ../src/generate/gen_ribbon_button.cpp |
| wxRibbonGallery | ??? | ??? | --- | ../src/generate/ribbon_widgets.cpp |
| wxRibbonPage | ??? | ??? | --- | ../src/generate/gen_ribbon_page.cpp |
| wxRibbonPanel | ??? | ??? | --- | ../src/generate/gen_ribbon_page.cpp |
| wxRibbonToolBar | ??? | ??? | --- | ../src/generate/ribbon_widgets.cpp |
| wxRichTextCtrl | ??? | ??? | --- | ../src/generate/gen_rich_text.cpp |
| wxScrollBar | ??? | ??? | --- | ../src/generate/gen_scrollbar.cpp |
| wxScrolled\<wxPanel\> | ??? | ??? | --- | ../src/generate/styled_text.cpp |
| wxScrolled\<wxWindow\> | ??? | ??? | --- | ../src/generate/styled_text.cpp |
| wxSearchCtrl | ??? | ??? | --- | ../src/generate/gen_search_ctrl.cpp |
| wxSimpleHtmlListBox | ??? | ??? | --- | ../src/generate/gen_html_listbox.cpp |
| wxSlider | ??? | ??? | --- | ../src/generate/gen_slider.cpp |
| wxSpinButton | ??? | ??? | --- | ../src/generate/gen_spin_btn.cpp |
| wxSpinCtrl | ??? | ??? | --- | ../src/generate/gen_spin_ctrl.cpp |
| wxSpinCtrlDouble | ??? | ??? | --- | ../src/generate/gen_spin_ctrl.cpp |
| wxSplitterWindow | ??? | ??? | --- | ../src/generate/gen_split_win.cpp |
| wxStaticBitmap | ??? | ??? | --- | ../src/generate/gen_static_bmp.cpp |
| wxStaticBox | ??? | ??? | --- | ../src/generate/gen_static_box.cpp |
| wxStaticLine | ??? | ??? | --- | ../src/generate/gen_static_line.cpp |
| wxStaticText | ??? | ??? | --- | ../src/generate/gen_static_text.cpp |
| wxStatusBar | ??? | ??? | --- | ../src/generate/gen_status_bar.cpp |
| wxStyledTextCtrl | ??? | ??? | --- | ../src/generate/styled_text.cpp |
| wxTextCtrl | ??? | ??? | --- | ../src/generate/gen_text_ctrl.cpp |
| wxToggleButton | ??? | ??? | --- | ../src/generate/gen_toggle_btn.cpp |
| wxToolBar | ??? | ??? | --- | ../src/generate/gen_toolbar.cpp |
| wxTreeCtrl | ??? | ??? | --- | ../src/generate/gen_tree_ctrl.cpp |
| wxTreeListCtrl | ??? | ??? | no | ../src/generate/gen_tree_list.cpp |
| wxWebView | ??? | ??? | no | ../src/generate/gen_web_view.cpp |
| wxWizardPageSimple | ??? | ??? | --- | ../src/generate/gen_wizard.cpp |

# Objects

| Object | C++ | Python | XRC |file |
-----------|-----|--------|------|------|
| AuiTool | ??? | ??? | --- | ../src/generate/gen_aui_toolbar.cpp |
| AuiToolLabel | ??? | ??? | --- | ../src/generate/gen_aui_toolbar.cpp |
| AuiToolSpacer | ??? | ??? | --- | ../src/generate/gen_aui_toolbar.cpp |
| AuiToolStretchSpacer | ??? | ??? | --- | ../src/generate/gen_aui_toolbar.cpp |
| BookPage | ??? | ??? | --- | ../src/generate/gen_book_page.cpp |
| Check3State | ??? | ??? | --- | ../src/generate/gen_checkbox.cpp |
| CustomControl | ??? | no | --- | ../src/generate/gen_custom_ctrl.cpp |
| DataViewColumn | ??? | ??? | --- | ../src/generate/dataview_widgets.cpp |
| DataViewListColumn | ??? | ??? | --- | ../src/generate/dataview_widgets.cpp |
| NewCloseButton | ??? | ??? | --- | ../src/generate/gen_close_btn.cpp |
| PageCtrl | ??? | ??? | no | ../src/generate/gen_page_ctrl.cpp |
| PropertyGridItem | ??? | ??? | no | ../src/generate/gen_prop_item.cpp |
| PropertyGridPage | ??? | ??? | no | ../src/generate/grid_widgets.cpp |
| RibbonButton | ??? | ??? | --- | ../src/generate/ribbon_widgets.cpp |
| RibbonGalleryItem | ??? | ??? | --- | ../src/generate/ribbon_widgets.cpp |
| RibbonTool | ??? | ??? | --- | ../src/generate/ribbon_widgets.cpp |
| Separator | ??? | ??? | --- | ../src/generate/menu_widgets.cpp |
| Spacer | ??? | ??? | --- | ../src/generate/gen_spacer_sizer.cpp |
| SubMenu | ??? | ??? | --- | ../src/generate/gen_submenu.cpp |
| ToolDropDown | ??? | ??? | --- | ../src/generate/gen_toolbar.cpp |
| ToolGenerator | ??? | ??? | --- | ../src/generate/gen_toolbar.cpp |
| ToolSeparator | ??? | ??? | --- | ../src/generate/gen_toolbar.cpp |
| ToolStretchable | ??? | ??? | --- | ../src/generate/gen_toolbar.cpp |
| TreeListCtrlColumn | ??? | ??? | no | ../src/generate/gen_tree_list.cpp |
| wxContextMenuEvent | ??? | no | no | gen_ctx_menu.cpp |