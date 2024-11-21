#!/bin/bash
# This script runs the C program to fetch weather data for multiple cities.

# Define the location of your compiled C program
PROGRAM_PATH="./main"

# Check if the C program exists
if [ ! -f "$PROGRAM_PATH" ]; then
    echo "Error: $PROGRAM_PATH not found. Compile the C program first."
    exit 1
fi

# Run the C program
echo "Running the weather data fetching program..."
$PROGRAM_PATH

# Log the date and time when the script was run
echo "Data fetched at $(date)" >> fetch_log.txt

# Print a message to indicate the end of the script execution
echo "Task completed successfully."
