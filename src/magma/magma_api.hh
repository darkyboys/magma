/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// Source

namespace magma {
    class string{
    public:
        func code_line; // this will store the code line
        string (func line) : code_line(line){}; // this will assign the code line

        func_ is_String(func_ index){ // this will check if the value is string or not
            func_ rval = 0;
            _func_ spos = 0;
            _func_ epos = 0;
            bool is_string_opened = false;
            for (_func_ i = 0;i < code_line.length();i++){
                // std::cout<<"token: "<<code_line[i]<<"\n"; // This line is for debugging
                if (code_line[i] == '`' && is_string_opened) {
                    is_string_opened = false;
                    // std::cout<<"Collision detected: Ended String!"<<"\n"; // This line is for debugging
                    epos = i;
                    // std::cout<<"Collision detected: Epos: "<<epos<<"\n"; // This line is for debugging
                }
                else if (code_line[i] == '`' && is_string_opened == false) {
                    is_string_opened = true;
                    // std::cout<<"Collision detected: Started String!"<<"\n"; // This line is for debugging
                    spos = i;
                    // std::cout<<"Collision detected: Spos: "<<spos<<"\n"; // This line is for debugging
                }
                if (is_string_opened == false && (index > spos and index < epos)){
                    rval = 1;
                    // std::cout<<"yes it was in an string!\n"; // This line is for debugging
                    break;
                }
            }
            return rval;
        }
    };



    int is_dir(const std::string& dir_name) {
        return std::filesystem::is_directory(dir_name) ? 1 : 0;
    }




    std::string get_file (std::string file){
        std::ifstream ifile (file);
        std::string temp, content;
        if (ifile.is_open()){
            while (std::getline (ifile, temp)) content += temp + '\n';
        }
        else {
            magma::error ("Magma Api can't find the file `" + file + "` to read, Please make sure that the file is accessible for the Magma API.");
        }
        return content;
    }
};