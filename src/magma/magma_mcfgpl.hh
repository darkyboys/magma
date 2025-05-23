/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This file contains the Magma Config Parallel List Format

namespace magma {
    std::string get_value (std::string file_name, std::string key){
        std::string value = UNIDEF_STR;
        std::ifstream ifile (file_name);
        if (ifile.is_open()){
            std::string content, temp;
            while (std::getline (ifile, temp)){
                std::size_t space = temp.find ("*");
                if (space == std::string::npos){
                    magma::error("MCFGPL Corrupted File couldn't be completed due to broken spacers", "i");
                }
                else {
                    if (temp.substr(0, space) == key){
                        value = temp.substr(space+1);
                    }
                }
            }
        }
        else {
            magma::error("MCFGPL File couldn't be opened", "i");
        }
        return value;
    }
}