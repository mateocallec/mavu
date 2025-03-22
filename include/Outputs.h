/**
 * @file Outputs.h
 * @brief Implements output and utility functions for the file exploration program.
 * 
 * This file contains the implementation of various utility functions used for
 * displaying output in the file exploration program. It includes functions for 
 * clearing the terminal screen, capitalizing text, converting text to hexadecimal,
 * and displaying formatted content. Additionally, the file provides functions for
 * displaying help, version, usage information, and credits to the user.
 */

#pragma once
#include <filesystem>
#include <string>

/**
 * @class Outputs
 * @brief Provides utility functions for displaying various outputs.
 * 
 * This class contains static methods to clear the terminal screen, capitalize strings, 
 * convert strings to their hexadecimal representation, and display various types of information
 * such as file content, program version, help, and credits.
 */
class Outputs {
public:
    /**
     * @brief Clears the terminal screen based on the platform.
     * 
     * This static function clears the terminal screen, using the platform-specific command:
     * - On Windows, it uses the `cls` command.
     * - On Unix-like systems (Linux, macOS), it uses the `clear` command.
     */
    static void clear();

    /**
     * @brief Capitalizes the first letter of each word in the input string.
     * 
     * This static function iterates through the input string, capitalizing the first letter of each
     * word, where a word is defined as any sequence of non-space characters.
     *
     * @param str The input string to be capitalized.
     * @return The capitalized version of the input string.
     */
    static std::string capitalize(const std::string& str);

    /**
     * @brief Converts the input string to its hexadecimal representation.
     * 
     * This static function converts each character of the input string into its corresponding
     * hexadecimal value. The resulting hexadecimal representation is returned as a string.
     *
     * @param content The input string to be converted to hexadecimal.
     * @return A string containing the hexadecimal representation of the input string.
     */
    static std::string convertToHex(const std::string& content);

    /**
     * @brief Displays the content of a file in a formatted manner.
     * 
     * This static function displays the content of a file, showing the relative path and content
     * in a formatted way. The file path is colorized, with directories shown in green and the file name
     * in white. The content is displayed in gray. It also adds separators for readability.
     *
     * @param baseDir The base directory to compute relative paths.
     * @param filePath The full path of the file to be displayed.
     * @param content The content of the file to be displayed.
     */
    static void displayFileContent(const std::filesystem::path& baseDir,
                                    const std::filesystem::path& filePath,
                                    const std::string& content);

    /**
     * @brief Displays an error message for an invalid argument.
     * 
     * This static function is used when the user provides an invalid argument to the program.
     *
     * @param argument The invalid argument provided by the user.
     */
    static void displayInvalidArgument(const std::string& argument);

    /**
     * @brief Displays the usage information for the program.
     * 
     * This static function displays the basic usage information of the program, including
     * the syntax for running the program and the expected arguments.
     */
    static void displayUsage();

    /**
     * @brief Displays the help message for the program.
     * 
     * This static function provides detailed help information, including the program's usage,
     * available options, and a description of each option.
     */
    static void displayHelp();

    /**
     * @brief Displays the version information for the program.
     * 
     * This static function displays the current version of the program, along with the
     * copyright date and the author's name.
     */
    static void displayVersion();

    /**
     * @brief Displays the credits and license information for the program.
     * 
     * This static function displays the program's credits, license information, author details,
     * and the full text of the license under which the software is released.
     */
    static void displayCredits();
};
