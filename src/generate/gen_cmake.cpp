//////////////////////////////////////////////////////////////////////////
// Purpose:   Auto-generate a .cmake file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <fstream>

#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class

int WriteCMakeFile(Node* parent_node, std::vector<tt_string>& updated_files, std::vector<tt_string>& results)
{
    if (!Project.as_bool(prop_generate_cmake) || (parent_node->isGen(gen_Project) && !Project.HasValue(prop_cmake_file)))
    {
        return result::exists;
    }
    if (parent_node->isGen(gen_folder) && !parent_node->HasValue(prop_folder_cmake_file))
    {
        return result::exists;
    }

    tt_cwd cwd(true);

    // The generated files make be in a different directory then the project file, and if so, we
    // need to tread that directory as the root of the file.

    tt_string cmake_file = Project.value(prop_cmake_file);
    if (parent_node->isGen(gen_folder) && parent_node->HasValue(prop_folder_cmake_file))
    {
        cmake_file = parent_node->value(prop_folder_cmake_file);
    }
    if (cmake_file.starts_with(".."))
    {
        tt_string new_dir(cmake_file);
        new_dir.remove_filename();
        tt::ChangeDir(new_dir);
    }
    else
    {
        Project.ProjectPath().ChangeDir();
    }
    if (cmake_file.find('.') == tt::npos)
    {
        cmake_file << ".cmake";
    }

    tt_cwd cur_dir;
    cur_dir.make_absolute();

    cmake_file.make_relative(cur_dir.utf8_string());
    tt_string cmake_file_dir(cmake_file);
    cmake_file_dir.remove_filename();
    if (cmake_file.size())
        cmake_file_dir.make_absolute();

    tt_string_vector out;
    out.emplace_back("# Generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/");
    out.emplace_back("#");
    out.emplace_back("# DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!");
    out.emplace_back();

    out.emplace_back();
    tt_string var_name(Project.value(prop_cmake_varname));
    if (parent_node->isGen(gen_folder) && parent_node->HasValue(prop_folder_cmake_varname))
    {
        var_name = parent_node->value(prop_folder_cmake_varname);
    }
    out.at(out.size() - 1) << "set (" << var_name;
    out.emplace_back();

    std::set<tt_string> base_files;
    std::vector<Node*> forms;
    Project.CollectForms(forms, parent_node);

    for (const auto& form: forms)
    {
        if (!form->HasValue(prop_base_file) ||
            (form->HasProp(prop_generate_translation_unit) && !form->as_bool(prop_generate_translation_unit)))
        {
            continue;
        }

        if (parent_node == Project.ProjectNode())
        {
            if (auto* node_folder = form->get_folder(); node_folder && node_folder->HasValue(prop_folder_cmake_file))
            {
                // This file already got added to a different .cmake file
                continue;
            }
        }

        // tt_string path = form->prop_as_string(prop_base_file);
        tt_string path = Project.value(prop_base_directory);
        if (parent_node->isGen(gen_folder) && parent_node->HasValue(prop_folder_base_directory))
        {
            path = parent_node->value(prop_folder_base_directory);
        }
        if (path.size())
        {
            path.append_filename(form->value(prop_base_file).filename());
        }
        else
        {
            path = form->value(prop_base_file);
        }

        if (cmake_file_dir.size())
            path.make_relative(cmake_file_dir);
        path.backslashestoforward();
        base_files.emplace(path);
    }

    for (auto base_file: base_files)
    {
        base_file.make_relative(cur_dir.utf8_string());
        base_file.backslashestoforward();
        base_file.remove_extension();

        tt_string source_ext(".cpp");
        if (auto& extProp = Project.value(prop_source_ext); extProp.size())
        {
            source_ext = extProp;
        }
        base_file.replace_extension(source_ext);

        out.emplace_back();
        out.at(out.size() - 1) << "    ${CMAKE_CURRENT_LIST_DIR}/" << base_file;
    }

    out.emplace_back();
    out.emplace_back(")");

    tt_view_vector current;

    // The return value is ignored because if the file doesn't exist then it will be created,
    // returning result::fail if it cannot be written.
    current.ReadFile(cmake_file);

    if (out.is_sameas(current))
    {
        return result::exists;
    }

    if (!out.WriteFile(cmake_file))
    {
        results.emplace_back() << "Cannot create or write to the file " << cmake_file << '\n';
        return result::fail;
    }

    updated_files.emplace_back(cmake_file);
    return result::created;
}
