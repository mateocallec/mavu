/**
 * @file FileManager.cpp
 * @headerfile FileManager.h
 * @brief This file contains the implementation of the FileManager class.
 * 
 * The FileManager class is responsible for managing and processing files in a specified directory.
 * It includes functions for retrieving all files, checking if a file is hidden, and determining 
 * if a file has a binary extension. The class allows filtering files based on visibility 
 * settings for hidden and binary files.
 * 
 * The implementation uses the C++ Standard Library's filesystem and set functionality.
 */

#include <filesystem>
#include <iostream>
#include <set>
#include <vector>
#include "globals.h"
#include "FileManager.h"

/**
 * @brief Retrieves all regular files in the specified directory, recursively.
 * 
 * This function iterates over the directory and all of its subdirectories to collect all regular 
 * files. It filters files based on the configuration settings (whether hidden or binary files 
 * should be shown).
 * 
 * @return A vector of paths representing the files found in the directory.
 * 
 * @note If the directory cannot be accessed, an error message is printed, and an empty vector is returned.
 */
std::vector<std::filesystem::path> FileManager::getAllFiles() {
    std::vector<std::filesystem::path> files;
    try {
        // Iterate through the directory and its subdirectories
        for (auto it = std::filesystem::recursive_directory_iterator(dirPath); it != std::filesystem::recursive_directory_iterator(); ++it) {
            const auto& entry = *it;
            // Check if the entry is a regular file
            if (std::filesystem::is_regular_file(entry)) {
                // Skip hidden files if configured to do so
                if ((!Configuration::showHiddenFiles && isHiddenFile(entry.path())) ||
                    (!Configuration::showBinaryFiles && hasBinaryExtension(entry.path()))) {
                    continue; // Skip this file
                }
                files.push_back(entry.path()); // Add the file path to the vector
            } else if (std::filesystem::is_directory(entry)) {
                // Skip hidden directories if configured to do so
                if (!Configuration::showHiddenFiles && isHiddenFile(entry.path())) {
                    // Skip the contents of this directory
                    it.disable_recursion_pending();
                }
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        // Handle filesystem errors (e.g., directory not found, access issues)
        std::cerr << SOFTWARE_NAME << ": error: " << e.what() << " while accessing directory `" << dirPath << "`" << std::endl;
    }
    return files;
}

/**
 * @brief Checks if a file has a binary extension.
 * 
 * This function checks the file extension against a predefined set of binary file extensions.
 * Common binary file extensions like images, videos, and audio files are included in this set.
 * 
 * @param filePath The path of the file to check.
 * @return True if the file has a binary extension, otherwise false.
 */
bool FileManager::hasBinaryExtension(const std::filesystem::path& filePath) const {
    // Set of known binary file extensions
    const std::set<std::string> binaryExtensions = {
        ".png", ".jpg", ".jpeg", ".gif", ".bmp", ".webp", ".ico", ".tiff", ".raw", ".svg", ".eps", 
        ".ai", ".psd", ".flac", ".aac", ".ogg", ".mp3", ".wav", ".mkv", ".mp4", ".avi", ".mov", 
        ".wmv", ".flv", ".webm", ".mpg", ".mpeg", ".3gp", ".dmg", ".iso", ".bin", ".deb", ".tar", 
        ".gz", ".zip", ".rar", ".7z", ".tar.gz", ".tar.bz2", ".tar.xz", ".apk", ".mobi", ".epub", 
        ".chm", ".odt", ".ods", ".odp", ".pdf", ".csv", ".yml", ".xml", ".json", ".sqlite", ".db", 
        ".mdb", ".accdb", ".bak", ".vhd", ".vmdk", ".vdi", ".xpi", ".crx", ".jar", ".war", ".ear", 
        ".rpm", ".arj", ".lha", ".cab", ".xz", ".bz2", ".lz", ".lzma", ".z", ".cue", ".vob", ".ifo", 
        ".bup", ".sub", ".idx", ".dat", ".m3u", ".nrg", ".srt", ".ass", ".vtt", ".wmf", ".emf", 
        ".pcx", ".exr", ".hdr", ".raw", ".dng", ".jxr", ".heif", ".heic", ".3ds", ".obj", ".fbx", 
        ".stl", ".ply", ".dae", ".gltf", ".glb", ".x3d", ".xap", ".mdf", ".img", ".bin", ".cue", 
        ".iso", ".dmg", ".flac", ".ape", ".wv", ".m4a", ".aac", ".dts", ".mpc", ".spx", ".wma", 
        ".aiff", ".au", ".voc", ".tak", ".it", ".mod", ".xm", ".s3m", ".mtm", ".ahx", ".nsf", 
        ".kdm", ".m3u8", ".pls", ".cue", ".msi", ".cab", ".torrent", ".nzb", ".dat", ".vhdx", 
        ".vdi", ".vbox", ".vdmk", ".vmdk", ".fpk", ".sfs", ".wsf", ".odm", ".ods", ".odp", ".odg"
    };
    
    // Get the file's extension
    std::string extension = filePath.extension().string();

    // Check if the file extension is in the binaryExtensions set
    return binaryExtensions.find(extension) != binaryExtensions.end();
}

/**
 * @brief Checks if a file is a hidden file.
 * 
 * A file is considered hidden if its name starts with a dot (.) in Unix-like systems. 
 * This function checks the file name to determine if it is hidden.
 * 
 * @param filePath The path of the file to check.
 * @return True if the file is hidden, otherwise false.
 */
bool FileManager::isHiddenFile(const std::filesystem::path& filePath) const {
    // A file is hidden if its filename starts with a dot (.)
    return filePath.filename().string().front() == '.';
}
