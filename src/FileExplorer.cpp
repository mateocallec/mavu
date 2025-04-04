/**
 * @file FileExplorer.cpp
 * @headerfile FileExplorer.h
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

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include "globals.h"
#include "FileExplorer.h"
#include "FileReader.h"
#include "Outputs.h"

/**
 * @brief Explores all files in the specified directory and displays their content.
 * 
 * This function retrieves all files from the directory using the FileManager class. For each 
 * file, it reads the content using the FileReader class and displays it using the Outputs class. 
 * If the file is a binary file, it will be converted to a hexadecimal format before being displayed. 
 * Otherwise, the content is displayed as text.
 * 
 * @throws std::exception If an error occurs during file processing, an exception will be caught
 * and an error message will be displayed.
 */
void FileExplorer::explore() {
    // Retrieve all files from the directory
    std::vector<std::filesystem::path> files = fileManager.getAllFiles();

    // Iterate over all the files retrieved
    for (const auto& file : files) {
        try {
            // Read the content of the current file
            std::string content = FileReader::readFile(file.string());

            // Check if the file is binary
            if (fileManager.hasBinaryExtension(file) || !fileManager.isTextMimeType(file)) {
                // Convert the binary content to hexadecimal format
                std::string hexContent = Outputs::convertToHex(content);
                // Display the content in hexadecimal format
                Outputs::displayFileContent(fileManager.dirPath, file, hexContent);
            } else {
                // Display the text content as is
                Outputs::displayFileContent(fileManager.dirPath, file, content);
            }
        } catch (const std::exception& e) {
            // Handle any errors that occur during file processing
            std::cerr << SOFTWARE_NAME << ": error: " << e.what() << " while processing file `" << file << "`" << std::endl;
        }
    }
}
