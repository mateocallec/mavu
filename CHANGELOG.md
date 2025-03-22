# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2023-10-01

### 🎉 Initial Release

- **Initial Release of Mavu**: This version introduces the core functionality of Mavu, a command-line utility for exploring and displaying the contents of files in a directory recursively.

- **Recursive File Listing**: Mavu can list all files in a directory and its subdirectories, providing a comprehensive view of the filesystem structure.

- **Hidden and Binary File Handling**: By default, Mavu does not display hidden or binary files. Users can enable these options to include hidden files (those starting with a dot on Unix-like systems) and binary files (identified by their extensions) in the output.

- **Clear Terminal Option**: Users can choose to clear the terminal screen before displaying the file list and contents. This feature enhances readability, especially when dealing with large outputs.

- **Hexadecimal Display for Binary Files**: When binary files are included in the output, their contents are displayed in hexadecimal format to prevent issues with unreadable characters.

- **Glob Pattern Support**: Mavu supports glob patterns in directory paths, allowing users to specify complex search criteria for file exploration.

- **Help, Version, and Credits Information**: The utility provides command-line options to display help information, version details, and credits, ensuring users have easy access to essential information about the tool.

This version lays the foundation for Mavu, offering a robust set of features for file exploration and display. Future updates will build upon this base, adding more functionality and improving existing features based on user feedback and contributions.
