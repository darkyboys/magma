/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// Source

#ifndef MAGMA
#define MAGMA 1

// Including the depnedencies
#include "nedded.hh"

// Main program starts from here
int main(int argc, char* argv[]){
    if (argc == 1){
        // std::string path = "./" + magma::project_file_name;
        magma::parser(".");
        // std::ifstream file(path);
        // if (file.is_open()){
        //     std::cout<<"File found!\n";
        // }
        // else std::cout<<"File not found!\n";
    }
    else {
        std::string arg = argv[1];
        if (arg == "version" or arg == "-v" or arg == "--version" or arg == "v"){
            std::cout<<"MAGMA VERSION "<<MAGMA_VERSION;
            std::cout<<"\n";
        }
    }
}

#endif