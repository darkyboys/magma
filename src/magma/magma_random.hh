/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * MAGMA - A Build System Which can simplyfy the Build process of a C++ project
 * Licensed under the MIT License
 * Checkout the README file for more information
*/

// This file contains the Magma Random Number Generator

// Source

namespace magma {
    std::string generate_random_string(std::size_t length) {
        const std::string chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, chars.size() - 1);

        std::string result;
        result.reserve(length);

        for (std::size_t i = 0; i < length; ++i) {
            result += chars[distrib(gen)];
        }

        return result;
    }

}