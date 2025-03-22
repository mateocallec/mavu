/**
 * @file globals.h
 * @brief This file contains the definition of static member variables for the Configuration class.
 * 
 * The Configuration class provides control over the visibility of binary and hidden files during 
 * the file exploration process. These static member variables determine whether binary or hidden files
 * should be shown or excluded in the exploration.
 * 
 * By default, both variables are set to false, meaning binary and hidden files are not shown.
 */

#pragma once

#define SOFTWARE_NAME "mavu"
#define SOFTWARE_COMMAND "mavu"
#define SOFTWARE_VERSION "1.0.0"
#define SOFTWARE_AUTHOR "Mateo Florian Callec"
#define SOFTWARE_LICENSE "MIT License"
#define SOFTWARE_LICENSE_HEADER "The MIT License (MIT)"
#define SOFTWARE_COPYRIGHT_DATE "2025"

/**
 * @struct Configuration
 * @brief Stores configuration settings for the software.
 * 
 * This structure holds static boolean flags that control the visibility of binary
 * and hidden files during the file exploration process. These flags can be modified 
 * by the user through command-line arguments to configure the program's behavior.
 */
struct Configuration {
    /**
     * @brief Static member variable that controls the visibility of binary files.
     * 
     * If set to true, binary files will be shown during exploration; otherwise, they will be hidden.
     * By default, this is set to false.
     */
    static bool showBinaryFiles;

    /**
     * @brief Static member variable that controls the visibility of hidden files.
     * 
     * If set to true, hidden files (e.g., those starting with a dot on Unix-like systems) will be shown 
     * during exploration; otherwise, they will be hidden. By default, this is set to false.
     */
    static bool showHiddenFiles;
};
