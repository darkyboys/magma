/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// Source


#ifndef MAGMA
#define MAGMA 7

// Including the depnedencies
#include "nedded.hh"

// Main program starts from here
int main(int argc, char* argv[]){
    if (!magma::is_dir("MagmaConfig")){
        std::system ("mkdir MagmaConfig");
    }
    if (argc == 1){
        // std::string path = "./" + magma::project_file_name;
        std::ifstream ifile_shell64("shell64.magma");
        if (ifile_shell64.is_open()){
            std::string temp;
            while (std::getline(ifile_shell64, temp)) {
                if (temp == "magma.call.show_logs=true"){
                    show_logs = true;
                    continue;
                }
                if (temp == "magma.call.show_logs=false"){
                    show_logs = false;
                    continue;
                }
                magma::log ("cli", "Executing `" + temp + "` command for the system shell.");
                std::system (temp.c_str());
            }
            std::exit ( 3 );
        }
        // std::ofstream magma_config_dir_check_ofile("MagmaConfig/exists");
        // std::ifstream magma_config_dir_check_ifile("MagmaConfig/exists");
        // if (not magma_config_dir_check_ifile.is_open()){
        //     std::system ("mkdir MagmaConfig");
        // }
        

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
        else {
            std::ifstream ifile_shell64(arg + "/shell64.magma");
            if (ifile_shell64.is_open()){
                std::string temp;
                while (std::getline(ifile_shell64, temp)) std::system (temp.c_str());
                std::exit ( 3 );
            }
            magma::parser(arg);
        }
    }
}

#endif