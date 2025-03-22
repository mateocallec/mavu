/**
 * @file main.cpp
 * @brief Main entry point for the file exploration application.
 * 
 * This file serves as the main entry point for the application. It handles the processing 
 * of command-line arguments, options, and initiates the exploration of directories and 
 * files based on the provided options. The program supports features like displaying hidden 
 * files, binary files, clearing the terminal screen, and displaying help, version, and credits.
 * 
 * It also includes functionality for expanding paths that may contain glob patterns.
 * The program uses `FileExplorer` to perform the actual file exploration.
 * 
 * The application supports the following options:
 * - `-h`: Show hidden files.
 * - `-b`: Show binary files.
 * - `-a`: Show both hidden and binary files.
 * - `-c`: Clear the terminal screen before output.
 * - `--help`: Display help message.
 * - `--version`: Display software version.
 * - `--credits`: Display credits information.
 */

#include "globals.h"
#include "FileExplorer.h"
#include "Outputs.h"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <glob.h>
#include <unistd.h>

/**
 * @brief Expands the given path to include all matching file paths based on glob patterns.
 * 
 * This function uses the glob() system call to expand the given path, supporting 
 * glob patterns (like wildcards). The resulting paths are returned as a vector of strings.
 *
 * @param path The path to expand, which may include glob patterns.
 * @return A vector of strings containing all expanded file paths.
 */
std::vector<std::string> expandPath(const std::string& path) {
    std::vector<std::string> expandedPaths;

    // Support for glob patterns
    glob_t globResult;
    glob(path.c_str(), GLOB_TILDE, nullptr, &globResult);

    // Add all found paths to the list
    for (size_t i = 0; i < globResult.gl_pathc; ++i) {
        expandedPaths.push_back(std::string(globResult.gl_pathv[i]));
    }

    globfree(&globResult);
    return expandedPaths;
}

/**
 * @brief The main entry point of the application.
 * 
 * This function processes command-line arguments, handles options, and manages the
 * exploration of file paths. It uses various options to control output and explore files.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments passed to the program.
 * @return Exit status code (0 for success, non-zero for failure).
 */
int main(int argc, char* argv[]) {
    // Process basic command-line options for help, version, and credits
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--help") {
            Outputs::displayHelp();
            return 0;
        } else if (std::string(argv[i]) == "--version") {
            Outputs::displayVersion();
            return 0;
        } else if (std::string(argv[i]) == "--credits") {
            Outputs::displayCredits();
            return 0;
        }
    }

    bool clearTerminal = false;
    int option;
    // Parse additional options with getopt
    while ((option = getopt(argc, argv, "hbac")) != -1) {
        switch (option) {
            case 'h':
                // Show hidden files
                Configuration::showHiddenFiles = true;
                break;
            case 'b':
                // Show binary files
                Configuration::showBinaryFiles = true;
                break;
            case 'a':
                // Show both hidden and binary files
                Configuration::showHiddenFiles = true;
                Configuration::showBinaryFiles = true;
                break;
            case 'c':
                // Clear terminal screen
                clearTerminal = true;
                break;
            default:
                // Handle invalid argument
                Outputs::displayInvalidArgument(std::string(1, (char)option));
                Outputs::displayUsage();
                return 1;
        }
    }

    // Determine the directory to explore, defaulting to current directory
    std::string directory = (optind < argc) ? argv[optind] : "./";

    // Expand any glob patterns in the given directory path
    std::vector<std::string> pathsToExplore = expandPath(directory);

    // Clear terminal screen if the option was selected
    if (clearTerminal) {
        Outputs::clear();
    }

    // Explore each of the expanded paths
    for (const std::string& path : pathsToExplore) {
        try {
            FileExplorer explorer(path);
            explorer.explore();  // Explore the file system at the given path
        } catch (const std::exception& e) {
            // Catch and display any errors during the exploration
            std::cerr << SOFTWARE_NAME << ": error: " << e.what() << " while processing path `" << path << "`" << std::endl;
        }
    }

    return 0;  // Exit successfully
}
