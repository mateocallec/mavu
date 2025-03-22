/**
 * @file Outputs.cpp
 * @headerfile Outputs.h
 * @brief Implements output and utility functions for the file exploration program.
 * 
 * This file contains the implementation of various utility functions used for
 * displaying output in the file exploration program. It includes functions for 
 * clearing the terminal screen, capitalizing text, converting text to hexadecimal,
 * and displaying formatted content. Additionally, the file provides functions for
 * displaying help, version, usage information, and credits to the user.
 */

#include "globals.h"
#include "Outputs.h"
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

/**
 * @brief Clears the terminal screen based on the platform.
 * 
 * This function clears the terminal screen, using `cls` for Windows systems
 * and `clear` for Unix-like systems (Linux, macOS).
 */
void Outputs::clear() {
    #if defined(_WIN32) || defined(_WIN64)
        // Windows: Use 'cls' to clear the screen
        system("cls");
    #else
        // Unix-like (Linux, macOS): Use 'clear' to clear the screen
        system("clear");
    #endif
}

/**
 * @brief Capitalizes the first letter of each word in the string.
 * 
 * This function iterates through each character in the string, and if a character
 * is the first character of a word (preceded by a space), it is converted to uppercase.
 *
 * @param str The input string to capitalize.
 * @return The capitalized version of the input string.
 */
std::string Outputs::capitalize(const std::string& str) {
    std::string result = str;
    bool newWord = true;

    for (char& ch : result) {
        if (std::isspace(ch)) {
            newWord = true;
        } else if (newWord) {
            ch = std::toupper(ch);
            newWord = false;
        }
    }

    return result;
}

/**
 * @brief Converts a string to its hexadecimal representation.
 * 
 * This function converts each character of the string to its hexadecimal value,
 * with each byte formatted as two hexadecimal digits.
 *
 * @param content The string to convert to hexadecimal.
 * @return A string containing the hexadecimal representation of the input string.
 */
std::string Outputs::convertToHex(const std::string& content) {
    std::ostringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (unsigned char c : content) {
        hexStream << std::setw(2) << static_cast<int>(c) << ' ';
    }
    return hexStream.str();
}

/**
 * @brief Displays the content of a file in a formatted manner.
 * 
 * This function displays the content of a file with its path, followed by the file content.
 * The file path is shown with different color coding for folders and the file itself.
 * The content is printed in gray.
 *
 * @param baseDir The base directory to compute relative paths.
 * @param filePath The full path to the file to display.
 * @param content The content of the file to display.
 */
void Outputs::displayFileContent(const std::filesystem::path& baseDir,
                                  const std::filesystem::path& filePath,
                                  const std::string& content) {
    // Compute relative path from baseDir
    std::filesystem::path relativePath = std::filesystem::relative(filePath, baseDir);
    std::string pathStr = relativePath.string() + ":";

    // Line length for the top and bottom separators
    const int minEquals = 20;
    int lineLength = std::max(minEquals, static_cast<int>(pathStr.length()));

    // Display top line separator
    std::cout << "\033[1m" << std::string(lineLength, '=') << "\033[0m" << std::endl;

    // Display the path with color formatting
    std::cout << "\033[1m"; // Enable bold style
    size_t lastSlashPos = pathStr.find_last_of("/\\");  // Find last slash (path separator)

    if (lastSlashPos == std::string::npos) {
        // If no slash is found, treat as a file at root level
        std::cout << "\033[37m" << pathStr << "\033[0m" << std::endl;  // Print in white
    } else {
        // Colorize path with different colors for folders and file
        for (size_t i = 0; i < pathStr.length(); ++i) {
            if (pathStr[i] == '/' || pathStr[i] == '\\') {
                std::cout << "\033[32m" << pathStr[i] << "\033[37m";  // Green for '/'
            } else {
                if (i > lastSlashPos) {
                    std::cout << "\033[37m" << pathStr[i];  // White for the file
                } else {
                    std::cout << "\033[90m" << pathStr[i] << "\033[37m";  // Gray for folders
                }
            }
        }
        std::cout << "\033[0m" << std::endl; // Reset color and style
    }

    // Display bottom line separator
    std::cout << "\033[1m" << std::string(lineLength, '=') << "\033[0m" << std::endl;

    // Display the file content in gray
    std::cout << "\033[90m" << content << "\033[0m" << std::endl << std::endl;
}

/**
 * @brief Displays an error message for an invalid argument.
 * 
 * This function is called when the user provides an invalid argument to the program.
 *
 * @param argument The invalid argument provided.
 */
void Outputs::displayInvalidArgument(const std::string& argument) {
    std::cout << SOFTWARE_COMMAND << ": Invalid argument `" << argument << "`" << std::endl;
}

/**
 * @brief Displays the usage information for the program.
 * 
 * This function displays a brief usage message with the available options and their descriptions.
 */
void Outputs::displayUsage() {
    std::cout << "Usage: " << SOFTWARE_COMMAND << " [options] <path>\n";
}

/**
 * @brief Displays the help message for the program.
 * 
 * This function displays detailed help information, including usage instructions
 * and a list of available options for the user.
 */
void Outputs::displayHelp() {
    displayUsage();
    std::cout << "Options:" << std::endl
              << "  -h         Show hidden files" << std::endl
              << "  -b         Show binary files" << std::endl
              << "  -a         Show binary and hidden files" << std::endl
              << "  -c         Clear the previous terminal outputs" << std::endl
              << "  --version  Show program version" << std::endl
              << "  --help     Show this help message" << std::endl
              << "  --credits  Show the credits" << std::endl;
}

/**
 * @brief Displays the version information for the program.
 * 
 * This function displays the current version, copyright date, and author information.
 */
void Outputs::displayVersion() {
    std::cout << capitalize(SOFTWARE_NAME) << " v" << SOFTWARE_VERSION
              << " (c) " << SOFTWARE_COPYRIGHT_DATE
              << " by " << SOFTWARE_AUTHOR << std::endl;
}

/**
 * @brief Displays the credits and license information for the program.
 * 
 * This function shows the software credits, license, author information, and full license text.
 */
void Outputs::displayCredits() {
    std::string softwareFullLicense = std::string(SOFTWARE_LICENSE_HEADER) + "\n"
    "Copyright (c) " + SOFTWARE_COPYRIGHT_DATE + " " + SOFTWARE_AUTHOR + "\n"
    "Permission is hereby granted, free of charge, to any person obtaining a copy\n"
    "of this software and associated documentation files (the \"Software\"), to deal\n"
    "in the Software without restriction, including without limitation the rights\n"
    "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
    "copies of the Software, and to permit persons to whom the Software is\n"
    "furnished to do so, subject to the following conditions:\n"
    "The above copyright notice and this permission notice shall be included in\n"
    "all copies or substantial portions of the Software.\n"
    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
    "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
    "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
    "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n"
    "THE SOFTWARE.\n";

    std::cout << "Software credits:" << std::endl
              << capitalize(SOFTWARE_NAME) << " (c) " << SOFTWARE_COPYRIGHT_DATE << std::endl
              << "--------------------" << std::endl
              << "Author: " << SOFTWARE_AUTHOR << std::endl
              << "Version: " << SOFTWARE_VERSION << std::endl
              << "License: " << SOFTWARE_LICENSE << std::endl
              << "--------------------" << std::endl
              << softwareFullLicense << std::endl;
}
