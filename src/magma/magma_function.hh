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

#include <fstream>
#include <string>
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
    darr compairing_list = {};
    
    void function (func name, func value){ // This will execute the functions
        // system function declaration
        std::vector <std::string> array_value_tokens = {}; // array processor
        if (value.find(SEPERATOR) != std::string::npos){
            magma::log ("function", "Array Detected!");
            std::string token = "";
            for (unsigned long long i = 0;i < value.length();i++){
                if (value[i] == SEPERATOR){
                    array_value_tokens.push_back(token);
                    magma::log ("function", "Registering the Array Value Token " + token);
                    token.clear();
                    continue;
                }
                token += value[i];
            }
        }
        
        if (name.find("system") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::IR += value + "\n";
            magma::log ("function", "Converting the system command `" + value + "` into IR");
        }

        // else if (name.find("parallel_size") != std::string::npos){
        //     // std::cout<<"system function detected!\n";
        //     magma::log ("function", "Setting Parallel Size To `" + value + "`");
        //     if (!is_num(value)){
        //         magma::error("parallel_size function only expects integer datatypes please write all your string as integer like `0` `1` ...");
        //     }
        //     else {
        //         parallel_size = std::stoi(value);
        //     }
        // }

        // else if (name.find("parallel") != std::string::npos){
        //     // std::cout<<"system function detected!\n";
        //     if (value == "true")
        //         parallel = true;
        //     else if (value == "false")
        //         parallel = false;
        //     else 
        //         std::cout << "Magma Function Error _> (parallel only expects `true` or `false` values, You wrote: " + value + " which was unexpected so the process can't be continued!)\n",
        //         std::exit ( 3 );
        // }

        else if (name.find("show_logs") != std::string::npos){
            // std::cout<<"system function detected!\n";
            if (value == "true")
                show_logs = true;
            else if (value == "false")
                show_logs = false;
            else 
                std::cout << "Magma Function Error _> (show_logs only expects `true` or `false` values, You wrote: " + value + " which was unexpected so the process can't be continued!)\n",
                std::exit ( 3 );
        }

        else if (name.find("increment") != std::string::npos){
            // std::cout<<"system function detected!\n";
            if (value == "true")
                increment = true;
            else if (value == "false")
                increment = false;
            else 
                std::cout << "Magma Function Error _> (increment only expects `true` or `false` values, You wrote: " + value + " which was unexpected so the process can't be continued!)\n",
                std::exit ( 3 );
        }

        else if (name.find("compile_arguments") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::compiler_arguments = value + " ";
            magma::log ("function", "Set the compiler arguments to " + value);
        }

        else if (name.find("compiler_arguments") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::compiler_arguments = value + " ";
            magma::log ("function", "Set the compiler arguments to " + value);
        }

        else if (name.find("compiler") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::compiler = value + " ";
            magma::log ("function", "Set the compiler to " + compiler);
        }

        else if (name.find("include") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::log ("function", "including...");
            if (array_value_tokens.size() == 0){
                magma::error ("include needs an array but you passed a function to it! use '[', ']' instead of '(' ')' to avoid any unintended errors!");
            }
            std::string compile_value = "";
            for (unsigned long long i = 0;i < array_value_tokens.size();i++){
                compile_value += "-I" + array_value_tokens[i] + " ";
                magma::log ("function", "Including `" + array_value_tokens[i] + "`");
            }
            magma::compiler_arguments += compile_value;
            magma::log ("function", "including finished!");
        }

        else if (name.find("pkg_in") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::log ("function", "Importing packages defines as " + value + " (ignore any weird values)");
            if (array_value_tokens.size() == 0){
                magma::error ("pkg_in needs an array but you passed a function to it! use '[', ']' instead of '(' ')' to avoid any unintended errors!");
            }
            std::string compile_value = "";
            for (unsigned long long i = 0;i < array_value_tokens.size();i++){
                std::string command = "pkg-config --cflags --libs " + array_value_tokens[i] + " > MagmaConfig/pkg_in.out";
                std::system (command.c_str());
                std::ifstream pkg_in_ifile("MagmaConfig/pkg_in.out");
                if (not pkg_in_ifile.is_open()){
                    magma::error ("pkg_in was not accessible! Check if any configurations were harmed during the build process or if the magma has permissions to perform IO in MagmaConfig directory");
                }

                std::string pkg_in_output, temp;
                while (std::getline(pkg_in_ifile, temp))
                    pkg_in_output += temp;

                if (pkg_in_output == ""){
                    magma::error ("From pkg_in: The package `" + array_value_tokens[i] + "` was not found anywhere! make sure it's installed or present in the system.\n");
                }
                else 
                    compile_value += pkg_in_output + " ";
                // compile_value += "-I" + array_value_tokens[i] + " ";
            }
            magma::compiler_arguments += compile_value;
        }


        else if (name.find("compare") != std::string::npos){
            // std::cout<<"system function detected!\n";
            if (increment){
                magma::log ("function", "compairing files...");
                if (array_value_tokens.size() == 0){
                    magma::error ("compare needs an array but you passed a function to it! use '[', ']' instead of '(' ')' to avoid any unintended errors!");
                }
                bool is_cfg_just_created = false;
                std::ifstream ifile_increment("MagmaConfig/increment.mcfgpl");
                if (ifile_increment.is_open()){}
                else {
                    std::ofstream ofile_increment ("MagmaConfig/increment.mcfgpl");
                    is_cfg_just_created = true;
                }
                // std::cout << is_cfg_just_created << '\n';
                
                for (unsigned long long i = 0;i < array_value_tokens.size();i++){
                    if (is_cfg_just_created){
                        std::string file_code = magma::generate_random_string(64);
                        std::string prev_content = magma::get_file("MagmaConfig/increment.mcfgpl");
                        std::ofstream ofile_increment ("MagmaConfig/increment.mcfgpl");
                        ofile_increment << prev_content << array_value_tokens[i] << "*" << file_code;
                            if (is_dir(magma_incremental_directory)){
                                std::ofstream ofile_1 (magma_incremental_directory + "/" + file_code);
                                ofile_1 << magma::get_file(array_value_tokens[i]);
                            }
                            else {
                                std::system(std::string("mkdir -p " + magma_incremental_directory).c_str());
                                std::ofstream ofile_1 (magma_incremental_directory + "/" + file_code);
                                ofile_1 << magma::get_file(array_value_tokens[i]);
                            }
                        increment_possible = false;
                    }
                    else {
                        std::string value_fetched = magma::get_value("MagmaConfig/increment.mcfgpl", array_value_tokens[i]);
                        // std::cout << "Value Fetched : " << value_fetched << " for " << array_value_tokens[i] << "\n";
                        if (value_fetched != UNIDEF_STR){
                            if (is_dir(magma_incremental_directory)){
                                std::ifstream ifile (magma_incremental_directory + "/" + value_fetched);
                                if (!ifile.is_open()){
                                    std::ofstream ofile_1 (magma_incremental_directory + "/" + value_fetched);
                                    ofile_1 << magma::get_file(array_value_tokens[i]);
                                }
                                else {
                                    if (not increment_possible and increment_checked) {
                                        if (magma::get_file(magma_incremental_directory + "/" + value_fetched) != magma::get_file(array_value_tokens[i])){
                                            std::ofstream ofile_2(magma_incremental_directory + "/" + value_fetched);
                                            ofile_2 << magma::get_file(array_value_tokens[i]);
                                        }
                                        increment_possible = false;
                                    }
                                    else if (magma::get_file(magma_incremental_directory + "/" + value_fetched) == magma::get_file(array_value_tokens[i]))
                                        increment_possible = true;
                                    else {
                                        std::ofstream ofile_2(magma_incremental_directory + "/" + value_fetched);
                                        ofile_2 << magma::get_file(array_value_tokens[i]);
                                        increment_possible = false;
                                    }
                                    if (not increment_checked) increment_checked = true;
                                }
                                // std::cout <<"Increment: " << increment_possible <<'\n';
                            }
                            else {
                                std::system(std::string("mkdir -p " + magma_incremental_directory).c_str());
                                std::ofstream ofile_1 (magma_incremental_directory + "/" + value_fetched);
                                ofile_1 << magma::get_file(array_value_tokens[i]);
                            }
                        }
                        else {
                            std::string old_cfg = get_file ("MagmaConfig/increment.mcfgpl");
                            std::ofstream new_cfg ("MagmaConfig/increment.mcfgpl");
                            new_cfg << old_cfg << array_value_tokens[i] << "*" << magma::generate_random_string(64) << "\n" ;
                            if (is_dir(magma_incremental_directory)){
                                std::ofstream ofile_1 (magma_incremental_directory + "/" + value_fetched);
                                ofile_1 << magma::get_file(array_value_tokens[i]);
                            }
                            else {
                                std::system(std::string("mkdir -p " + magma_incremental_directory).c_str());
                                std::ofstream ofile_1 (magma_incremental_directory + "/" + value_fetched);
                                ofile_1 << magma::get_file(array_value_tokens[i]);
                            }
                        }
                    }
                    compairing_list.push_back (array_value_tokens[i]);
                    magma::log ("function", "Adding `" + array_value_tokens[i] + "` to the Compairing list");
                }
                magma::log ("function", "compairing finished!");
            }
        }


        else if (name.find("lib") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::log ("function", "adding library flags...");
            if (array_value_tokens.size() == 0){
                magma::error ("lib needs an array but you passed a function to it! use '[', ']' instead of '(' ')' to avoid any unintended errors!");
            }
            std::string compile_value = "";
            for (unsigned long long i = 0;i < array_value_tokens.size();i++){
                compile_value += "-l" + array_value_tokens[i] + " ";
                magma::log ("function", "Including Library Flag `" + array_value_tokens[i] + "`");
            }
            magma::compiler_arguments += compile_value;
            magma::log ("function", "Library Flag Added!");
        }



        else if (name.find("clean_main") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            magma::temp += "rm -rf " + magma::main_out + "\n";
            magma::log ("function", "Cleaning the output file " + main_out);
        }

        else if (name.find("exec_args") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            exec_args = value;
            magma::log ("function", "Adding executable arguments to the IR `" + value);
        }

        else if (name.find("exec") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            magma::temp += "./" + magma::bin + "/" + magma::main_out + exec_args + "\n";
            magma::log ("function", "Making executing rules in IR for executable " + value + "...");
        }

        else if (name.find("pkg_config") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::log ("function", "Making the IR for pkg_config on " + value);
            magma::pkg_config = "`pkg-config " + value + "` ";
        }

        else if (name.find("combine") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::combine += value + " ";
            magma::log ("function", "Adding combine source files rule to the IR for combining `" + value + "` with other files.");
        }


        else if (name.find("out") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::main_out = value + " ";
            magma::log ("function", "Set the output file name in IR to " + main_out);
        }

        else if (name.find("main") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::main = value + " ";
            magma::log ("function", "Set the source file name in the IR to " + main);
        }

        else if (name.find("bin") != std::string::npos){
            // std::cout<<"system function detected!\n";
            magma::bin = value;
            magma::log ("function", "Set the binary directory in the IR to " + bin);
        }

        else if (name.find("clean") != std::string::npos){
            // std::cout<<"system function detected!\n";
            // magma::include = value;
            IR += "clear\ncls";
            magma::log ("function", "Adding the clean cli rules in the IR");
        }

        else if (name.find("make") != std::string::npos){
            if (increment_possible){
                // do nothing for incremental builds
                magma::log ("function", "Incremental Build Detected, No Changes were found in codebase during comparision so not building any IR.");
                magma::log ("function", "Finished the IR for the current target " + main);
            }
            else {
                // Prepare the IR Finally!
                magma::log ("function", "Adding the make rules in the IR (Not related to make build system)");
                std::ofstream tofile (magma::bin + "/magma.destination"); // test out file
                std::ifstream tifile (magma::bin + "/magma.destination"); // test in file
                if (tifile.is_open()) IR += "rm -rf " + (magma::bin + "/magma.destination") + "\n";
                else IR += "mkdir " + magma::bin + "\n";
                // std::cout << "rm -rf " + (magma::bin + "/magma.destination")<<"\n";
                func main_file = magma::compiler + magma::main + magma::combine + "-o " + magma::bin + "/" + magma::main_out + magma::compiler_arguments + magma::pkg_config + "\n";
                // std::cout<<"command for main:\n"
                //          <<main_file<<temp
                //          <<"\n";
                magma::log ("function", "Generated commands : " + main_file + ", Converting to the IR!");
                IR += main_file + temp;
                magma::log ("function", "Finished the IR for the current target " + main);
                magma::log ("function", "Generating the IR Files for the current target " + main);
                IR_Files.push_back ({main, IR});
                std::cout << IR_Files[IR_Files.size()-1][0] <<"\n";
                magma::log ("function", "Finished the IR Files for the current target " + main);
                magma::log ("function", "Clearing the IR for the current target " + main);
                IR.clear();
                magma::log ("function", "Finished the IR Cleaning for the current target " + main);
            }
        }

        else if (name.find("run") != std::string::npos) std::system (value.c_str());
        
        array_value_tokens.clear(); // be sure to clear a used or uninitialised array
    }
};
