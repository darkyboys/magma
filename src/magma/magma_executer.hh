/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

#include <cmath>
namespace magma {
    void executer (std::vector <std::vector <std::string>> IR_Val){
        // if (parallel){
        //     unsigned long long current_size = 1;
        //     for (unsigned long long i = 0;i < IR_Val.size();i++){
        //         if (current_size == parallel_size){
        //             // i--;
        //             continue;
        //         }
        //         else {
        //             std::cout << "Current_size: "<<current_size<<"\ni: "<<i<<"\n";
        //             current_size += 1;
        //             unsigned long long index = i;
        //             std::thread([IR_Val, &current_size, index](){
        //                 std::string arg = "Making The Target " + IR_Val[index][0];
        //                 arg += " (" + std::to_string(index+1) + "/" + std::to_string(IR_Val.size()) + ") [" + std::to_string((float(index+1)/float(IR_Val.size()))*100) + "%]";
        //                 magma::log("Executer", arg);
        //                 std::system (IR_Val[index][1].c_str());
        //                 current_size-=1;
        //             }).detach();
        //         }
        //     }
        // }
        // else {
            for (unsigned long long i = 0;i < IR_Val.size();i++){
                std::string arg = "Making The Target " + IR_Val[i][0];
                arg += " (" + std::to_string(i+1) + "/" + std::to_string(IR_Val.size()) + ") [" + std::to_string((float(i+1)/float(IR_Val.size()))*100) + "%]";
                magma::log("Executer", arg);
                std::system (IR_Val[i][1].c_str());
            }
        // }
    }
}