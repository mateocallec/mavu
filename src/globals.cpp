/**
 * @file globals.cpp
 * @headerfile globals.h
 * @brief This file contains the definition of static member variables for the Configuration class.
 * 
 * The Configuration class provides control over the visibility of binary and hidden files during 
 * the file exploration process. These static member variables determine whether binary or hidden files
 * should be shown or excluded in the exploration.
 * 
 * By default, both variables are set to false, meaning binary and hidden files are not shown.
 */

#include "globals.h"

/**
 * @brief Static member variable to control the visibility of binary files.
 * 
 * This variable determines whether binary files should be shown during the file exploration.
 * By default, it is set to false, meaning binary files will not be shown.
 */
bool Configuration::showBinaryFiles = false;

/**
 * @brief Static member variable to control the visibility of hidden files.
 * 
 * This variable determines whether hidden files (e.g., files starting with a dot on Unix-like systems)
 * should be shown during the file exploration. By default, it is set to false, meaning hidden files
 * will not be shown.
 */
bool Configuration::showHiddenFiles = false;
