/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This is the implementation of the magma file functions

// Source
// #include <vector>

namespace magma {
    func compiler = "g++ ",
         compiler_arguments = "",
         pkg_config = "",
         combine = "",
         main = "main.cc ",
         bin = "bin",
         main_out = "main ",
         main_bin_name = "main ";
    func exec_args = "";
    func temp;
    darr include, include_output;
    
    void function (func name, func value){ // This will execute the functions
        // system function declaration
        
        if (name.find("system") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::IR += value + "\n";
        }

        else if (name.find("compile_arguments") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::compiler_arguments = value + " ";
        }

        else if (name.find("compiler") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::compiler = value + " ";
        }



        else if (name.find("clean_main") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            magma::temp += "rm -rf " + magma::main_out + "\n";
        }

        else if (name.find("exec_args") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            exec_args = value;
        }

        else if (name.find("exec") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            magma::temp += "./" + magma::bin + "/" + magma::main_out + exec_args + "\n";
        }

        else if (name.find("pkg_config") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::pkg_config = "`pkg-config " + value + "` ";
        }

        else if (name.find("combine") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::combine = "-c " + value + " ";
        }


        else if (name.find("out") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::main_out = value + " ";
        }

        else if (name.find("main") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::main = value + " ";
        }

        else if (name.find("bin") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::bin = value;
        }

        else if (name.find("clean") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            IR += "clear\ncls";
        }

        else if (name.find("make") != std::string::npos){
            // Prepare the IR Finally!
            IR += "mkdir " + magma::bin + "\n";
            func main_file = magma::compiler + magma::combine + magma::main + "-o " + magma::bin + "/" + magma::main_out + magma::compiler_arguments + magma::pkg_config + "\n";
            // std::cout<<"command for main:\n"
            //          <<main_file<<temp
            //          <<"\n";
            IR += main_file + temp;
        }
    }
};