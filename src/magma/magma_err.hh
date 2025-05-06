/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This file contains the code for the errors

// Source
namespace magma {
    void error(func message, func type = "s"){
        if (type == "s"){
            std::cout<<"\033[1;31m Error detected -> \033[1;97mMagma Syntax Error Detected ("<<message<<")\n\033[0m";
            std::exit ( 3 );
        }
        else {
            std::cout<<"\033[1;31m Error detected -> \033[1;97mMagma IO Error ("<<message<<")\n\033[0m";
            std::exit ( 3 );
        }
    }

    void log(std::string unit, std::string log){
        if (show_logs) std::cout << "\033[1;32m Magma "<<unit<<" Unit \033[1;36m> \033[1;97m"<<log<<"\n\033[0m"; // only for the logs
    }
}