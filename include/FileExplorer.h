/**
 * @file FileExplorer.h
 * @brief This file contains the implementation of the FileExplorer class.
 * 
 * The FileExplorer class is responsible for exploring files in a directory. It interacts with 
 * FileManager to retrieve the list of files, uses FileReader to read the contents of the files, 
 * and displays the file contents using the Outputs class. Binary files are displayed in hexadecimal 
 * format, while text files are displayed as they are.
 * 
 * The implementation relies on C++ Standard Library's filesystem and string classes for file 
 * handling and reading.
 */

#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include "FileManager.h"

/**
 * @class FileExplorer
 * @brief Handles the exploration of files within a directory.
 * 
 * The `FileExplorer` class utilizes the `FileManager` class to manage the file exploration process.
 * It provides functionality to explore a specified directory and apply any filters or actions
 * such as excluding binary files or hidden files. The main purpose of this class is to control
 * the exploration logic and delegate specific file operations to the `FileManager`.
 */
class FileExplorer {
public:
    /**
     * @brief Constructs a FileExplorer object with a specific directory path.
     * 
     * This constructor initializes the `FileExplorer` with a `FileManager` instance, passing the given
     * directory path to it for file exploration.
     *
     * @param path The directory path to explore.
     */
    explicit FileExplorer(const std::string& path) : fileManager(path) {}

    /**
     * @brief Explores the files in the specified directory.
     * 
     * This method uses the `FileManager` to retrieve all files in the directory and then applies
     * any necessary logic (e.g., filtering binary or hidden files) based on the current configuration.
     * The method handles the display and organization of the exploration results.
     */
    void explore();

private:
    FileManager fileManager; ///< The `FileManager` instance used to handle file operations.
};
