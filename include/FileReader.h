/**
 * @file FileReader.h
 * @brief This file contains the implementation of the FileReader class.
 * 
 * The FileReader class is responsible for reading the content of files. It handles exceptions
 * related to file opening and reading, such as missing files, permissions errors, and other 
 * system-related issues.
 * 
 * Functions in this file make use of C++ Standard Library features such as ifstream, filesystem,
 * and exception handling.
 */

#pragma once
#include <string>

/**
 * @class FileReader
 * @brief Handles file reading operations.
 * 
 * The `FileReader` class provides static methods to read the contents of a file. 
 * It can be used to load the content of text files for further processing or display. 
 * The class is designed to be simple and only deals with file reading operations.
 */
class FileReader {
public:
    /**
     * @brief Reads the contents of a file.
     * 
     * This static method reads the entire content of the specified file and returns it as a string.
     * If the file cannot be opened or read, an exception will be thrown.
     *
     * @param filePath The path to the file to be read.
     * @return A string containing the contents of the file.
     * @throw std::ios_base::failure If the file cannot be opened or read.
     */
    static std::string readFile(const std::string& filePath);
};
