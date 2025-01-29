/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This part is where lexical annalysis is implemented

// Source

namespace magma {
    darr lexer (func code_line){
        magma::string lexer_mstring = code_line;
        darr rval = {"unidefx000001", "unidefx000001"};
        bool is_function_opened = false, is_function_already_loaded = false;
        bool is_string_opened = false; // string flags
        func fname;
        bool is_comment = false;
        func value;
        for (_func_ i = 0;i < code_line.length();i++){
            // std::cout<<code_line[i]<<"\n";
            if (code_line[i] == '#' && lexer_mstring.is_String(i) == 0) is_comment = true;
            if (is_comment) continue;
            if (code_line[i] == '`' && is_string_opened && lexer_mstring.is_String(i) == 0) is_string_opened = false;
            else if (code_line[i] == '`' && is_string_opened == false && lexer_mstring.is_String(i) == 0) is_string_opened = true;
            else if (is_string_opened){
                value += code_line[i]; 
                // std::cout<<value<<"\n";
            } 
            else if (code_line[i] == ')' && is_function_opened && lexer_mstring.is_String(i) == 0){
                is_function_opened = false;
                is_function_already_loaded = true;
                // std::cout<<"Collision Detected : The Function is now closed\n";
            }
            else if (code_line[i] == '(' && is_function_opened == false && lexer_mstring.is_String(i) == 0){
                is_function_opened = true;
                func name;
                // std::cout<<"Collision Detected : The Function is now opened\n";
                for (_func_ x = i-1;true;x--){
                    // std::cout<<code_line[x]<<"\n";
                    if (x == 0){
                        // std::cout<<"x is now 0\n";
                        if (code_line[x] != ' ') {
                            name += code_line[x];
                            break;
                        }
                        else break;
                    }
                    else if (code_line[x] == ' ') continue;
                    else {
                        name += code_line[x];
                    }
                }

                // std::cout<<"y-start\n";
                for (_func_ y = name.length();true;y--){
                    if (y == 0) {
                        fname += name[0];
                        break;
                    }
                    // std::cout<<name[y]<<"\n";
                    fname += name[y];
                }
                
                // std::cout<<"The function name is : "<<rval[0]<<"\n";
            }

            // For The Syntax Errors!
            else if (code_line[i] == ')' && is_function_opened == false && lexer_mstring.is_String(i) == 0) magma::error("The Function was already declared so why re-closing it ?");
            else if (code_line[i] == '(' && is_function_opened && lexer_mstring.is_String(i) == 0) magma::error("The Function was already opened so why re-opening it ?");
        }
        rval[0] = fname;
        rval[1] = value;
        //         std::cout<<"The function name is : "<<rval[0]<<"\n";
        // std::cout<<"The function data is : "<<rval[1]<<"\n";

        return rval;
    }
}