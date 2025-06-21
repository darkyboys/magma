/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This file includes all the requirnments of the project
// Source

// Std Cxx17 STL
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <random>
#include <filesystem>

#define UNIDEF "unidefx000001";
#define MAGMA_VERSION 7;

// typedefinations
typedef std::string               func  ; // defination of the func keyword
typedef int                       func_ ; // defination of the func_ keyword
typedef unsigned long long        _func_; // defination of the _func_ keyword
typedef std::vector <std::string>   darr; // defination of the darr keyword

// keys
const char SEPERATOR = char(int(245));
bool show_logs = false;
bool increment = false,
     increment_possible = false,
     increment_checked = false;
bool parallel = false;
int  parallel_size = 6;
const std::string magma_incremental_directory = "MagmaConfig/increment/";
const std::string UNIDEF_STR = "unidefx000001";

// Local Project Files
#include "magma/magma_err.hh"
#include "magma/magma_random.hh"
#include "magma/magma_mcfgpl.hh"
#include "magma/magma_api.hh"
#include "magma/magma_lexer.hh"
#include "magma/magma_ir.hh"
#include "magma/magma_function.hh"
#include "magma/magma_executer.hh"
#include "magma/magma_parser.hh"
#include "main.hh"
