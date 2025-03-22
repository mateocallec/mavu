/**
 * @file FileReader.cpp
 * @headerfile FileReader.h
 * @brief This file contains the implementation of the FileReader class.
 * 
 * The FileReader class is responsible for reading the content of files. It handles exceptions
 * related to file opening and reading, such as missing files, permissions errors, and other 
 * system-related issues.
 * 
 * Functions in this file make use of C++ Standard Library features such as ifstream, filesystem,
 * and exception handling.
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "globals.h"
#include "FileReader.h"

/**
 * @brief Reads the content of a file and returns it as a string.
 * 
 * This function opens the file specified by the given file path, reads its content, and returns
 * the content as a string. If the file cannot be opened, or if any error occurs during the reading
 * process, an error message is returned instead.
 * 
 * @param filePath The path to the file to be read.
 * @return A string containing the file content or an error message if the file cannot be read.
 * 
 * @throw std::filesystem::filesystem_error If the file cannot be opened due to system-related issues (e.g., missing file, permission denied).
 * @throw std::exception If any other error occurs during the reading process.
 */
std::string FileReader::readFile(const std::string& filePath) {
    try {
        // Attempt to open the file
        std::ifstream file(filePath);

        if (!file.is_open()) {
            // If the file cannot be opened, throw a filesystem error
            throw std::filesystem::filesystem_error("Cannot open file", std::filesystem::path(filePath), std::error_code());
        }

        // Read the entire file content into a string
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content;

    } catch (const std::filesystem::filesystem_error& e) {
        // Handle filesystem errors, e.g., file not found, permissions error
        std::cerr << SOFTWARE_NAME << ": error: " << e.what() << std::endl;
        return std::string(SOFTWARE_NAME) + ": cannot open file `" + filePath + "`";

    } catch (const std::exception& e) {
        // Handle other exceptions that may occur during file reading
        std::cerr << SOFTWARE_NAME << ": error: " << e.what() << std::endl;
        return std::string(SOFTWARE_NAME) + ": unknown error while reading file `" + filePath + "`";
    }
}
