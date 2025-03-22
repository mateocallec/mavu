#!/bin/bash

# Define the URL of the .deb package
PACKAGE_URL="https://resources.callec.net/open-source-projects/mavu/mavu.deb"

# Define the local file name for the downloaded package
PACKAGE_NAME="mavu.deb"

# Function to display an error message and exit
error_exit() {
    echo "Error: $1"
    exit 1
}

# Download the .deb package
echo "Downloading the package from $PACKAGE_URL..."
curl -LO "$PACKAGE_URL" || error_exit "Failed to download the package."

# Install the .deb package using dpkg
echo "Installing the package..."
sudo dpkg -i "$PACKAGE_NAME" || error_exit "Failed to install the package."

# Fix any missing dependencies
echo "Fixing missing dependencies..."
sudo apt-get install -f -y

# Clean up the downloaded package file
echo "Cleaning up..."
rm "$PACKAGE_NAME"

echo "Installation completed successfully!"
