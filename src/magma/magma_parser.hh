/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This part is where the parsing logic is been implemented

// Source

#include <fstream>
#include <string>

namespace magma {
    func project_file_name = "build.magma";
    void parser(func project_path){
        func fpath = project_path + "/" + project_file_name;
        // std::cout<<fpath<<"\n";
        std::ifstream ifile(fpath);
        if (!ifile.is_open()){
            magma::error("No Build File Found!", "fs"); // file system error
        }

        func code_current_line = "", temp;
        func_ spos, epos;
        bool is_string_opened = false;
        while (std::getline(ifile, temp)){
            for (_func_ i = 0;i < temp.length();i++){
                code_current_line += temp[i];
                if (temp[i] == '`' and is_string_opened == false){
                    spos = i;
                    is_string_opened = true;
                }
                else if (temp[i] == '`' and is_string_opened){
                    epos = i;
                    is_string_opened = false;
                }
                if (temp[i] == ';' and is_string_opened) continue;
                else if (temp[i] == ';' and is_string_opened == false){
                    // std::cout<<"The first collision is here : "<<code_current_line<<"\n";
                    magma::log ("parser", "Sending the line `" + code_current_line + "` to the lexer for lexcial Annalysis.");
                    darr tokens = magma::lexer(code_current_line);
                    // std::cout<<"The function name is "<<tokens[0]<<"\n";
                    // std::cout<<"The function value is "<<tokens[1]<<"\n";
                    magma::log ("parser", "Lexer returned the processed tokens!");
                    magma::log ("parser", "The function detected in the lexer tokens with name " + tokens[0] + " with value token to be " + tokens[1]);
                    magma::log ("parser", "Sending the tokens to the function unit");
                    magma::function(tokens[0], tokens[1]);
                    code_current_line.clear();
                    break;
                }
            }
        }
        magma::log ("parser", "Finally executing the final generated IR! Which is ```IR-of-magma\n" + IR + "\n```");
        magma::log ("parser", "Executing...");
        std::system(magma::IR.c_str());
    }
};