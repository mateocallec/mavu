/**
 * @file FileManager.h
 * @brief This file contains the implementation of the FileManager class.
 * 
 * The FileManager class is responsible for managing and processing files in a specified directory.
 * It includes functions for retrieving all files, checking if a file is hidden, and determining 
 * if a file has a binary extension. The class allows filtering files based on visibility 
 * settings for hidden and binary files.
 * 
 * The implementation uses the C++ Standard Library's filesystem and set functionality.
 */

#pragma once
#include <string>
#include <vector>
#include <filesystem>

/**
 * @class FileManager
 * @brief Manages file operations within a specified directory.
 * 
 * The `FileManager` class provides functionality to explore files in a specified directory.
 * It allows the retrieval of all regular files (excluding hidden or binary files, based on configuration)
 * and provides methods for identifying binary files and hidden files.
 * This class encapsulates file system operations, making it easier to interact with files
 * based on specific criteria like file extensions or visibility.
 */
class FileManager {
public:
    /**
     * @brief Constructs a FileManager object with a specific directory path.
     * 
     * This constructor initializes the `FileManager` with the given directory path.
     * The path is used for further file exploration.
     *
     * @param path The directory path to explore.
     */
    explicit FileManager(const std::string& path) : dirPath(path) {}

    std::string dirPath; ///< The directory path to explore.

    /**
     * @brief Retrieves all regular files in the directory and its subdirectories.
     * 
     * This method recursively explores the directory specified by `dirPath` and returns
     * a list of regular files, excluding binary and hidden files based on the current configuration.
     * 
     * @return A vector containing the paths of all regular files.
     */
    std::vector<std::filesystem::path> getAllFiles();

    /**
     * @brief Checks if a file has a binary extension.
     * 
     * This method checks the extension of the provided file path to determine whether the file
     * has a binary extension. It uses a predefined set of known binary extensions to perform the check.
     * 
     * @param filePath The path to the file.
     * @return `true` if the file has a binary extension, otherwise `false`.
     */
    bool hasBinaryExtension(const std::filesystem::path& filePath) const;

    /**
    * @brief Checks if a file has a text MIME type.
    *
    * This function checks the file extension against a predefined set of text file extensions.
    * Common text file extensions like .txt, .md, .html, etc., are included in this set.
    *
    * @param filePath The path of the file to check.
    * @return True if the file has a text MIME type, otherwise false.
    */
    bool isTextMimeType(const std::filesystem::path& filePath) const;

private:
    /**
     * @brief Checks if a file is hidden.
     * 
     * This method checks if a file is hidden based on its name. In Unix-like systems,
     * files starting with a dot (.) are considered hidden.
     * 
     * @param filePath The path to the file.
     * @return `true` if the file is hidden, otherwise `false`.
     */
    bool isHiddenFile(const std::filesystem::path& filePath) const;
};
