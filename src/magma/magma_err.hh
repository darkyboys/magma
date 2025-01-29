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
            std::cout<<"Error detected -> Magma Syntax Error Detected ("<<message<<")\n";
            std::exit ( 3 );
        }
        else {
            std::cout<<"Error detected -> Magma IO Error ("<<message<<")\n";
            std::exit ( 3 );
        }
    }
}