#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <filepath> <file content>"
    exit 1
fi

# assign arguments to veriables
filepath="$1"
file_content="$2"

# Extract the directory and filename
directory="$(dirname "$filepath")"
filename="$(basename "$filepath")"

if [ ! -d "$directory" ]; then
    mkdir -p "$directory"
fi

if [ -f "$filepath" ]; then
    echo "File exit! Exiting now!"
    exit 1
else
    touch $filepath
    echo "$file_content" >> "$filepath"
    echo "Adding $file_content to $filepath now."
fi

# Check if the file was created successfully
if [ -f "$filepath" ]; then
    echo "File $filepath created successfully."
else
    echo "Error: Unable to create file $filepath."
fi