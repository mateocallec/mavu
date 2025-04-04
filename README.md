![Mavu logo](https://github.com/mateocallec/mavu/blob/main/docs/logo.png?raw=true)

# Mavu File Explorer

Mavu is a command-line utility written in C++ that allows you to explore and display the contents of files in a directory recursively. It provides options to include hidden and binary files, clear the terminal screen, and display help, version, and credits information.

## Features

- Recursively list and display all files in a directory.
- Optionally include hidden and binary files.
- Clear the terminal screen before displaying output.
- Display file contents in hexadecimal format for binary files.
- Support for glob patterns in directory paths.
- Display help, version, and credits information.

## Installation

### Method 1

1. Download the package:
   ```sh
   wget resources.callec.net/open-source-projects/mavu/mavu_latest.deb
   ```

2. Install the package:
   ```sh
   dpkg -i mavu_latest.deb
   ```

### Method 2

#### Prerequisites

- C++ compiler (e.g., g++)
- CMake (for building the project)
- GNU Make (for building the project)

#### Steps

1. Clone the repository:
   ```sh
   git clone https://github.com/mateocallec/mavu.git
   cd mavu
   ```

2. Build the project using CMake and Make:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Alternatively, use the provided installation script to install the package:
   ```sh
   ./scripts/install.sh
   ```

## Usage

```sh
mavu [options] <path>
```

### Options

- `-h`: Show hidden files.
- `-b`: Show binary files.
- `-a`: Show both hidden and binary files.
- `-c`: Clear the terminal screen before output.
- `--help`: Display help message.
- `--version`: Display software version.
- `--credits`: Display credits information.

### Example

```sh
mavu -a /path/to/directory
```

## Directory Structure

```
mavu/
├── CONTRIBUTING.md
├── docs/
│   └── logo.png
├── include/
│   └── (header files)
├── LICENSE
├── Makefile
├── README.md
├── scripts/
│   └── install.sh
├── SECURITY.md
├── CHANGELOG.md
├── src/
│   └── (source files)
└── tests/
    └── (test files and directories)
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Security

If you discover any security-related issues, please refer to our [SECURITY.md](SECURITY.md) file for guidelines on how to report them.

## Changelog

View the [CHANGELOG.md](CHANGELOG.md) file for a history of updates and changes to the project.

## Contact

For more information, please contact Mateo Florian Callec at [mateo@callec.net](mailto:mateo@callec.net).
