#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

# Assign arguments to variables
filesdir="$1"
searchstr="$2"

if [ -d "$filesdir" ]; then
    file_count=$(find "$filesdir" -type f | wc -l)
    
    matched_file_count=$(find -type f -name "*.sh" -exec grep -Hi directory {} \; | wc -l)
    echo "The number of files are $file_count and the number of matching lines are $file_count"
else
    echo "The directory $filesdir does not exist."
    exit 1
fi