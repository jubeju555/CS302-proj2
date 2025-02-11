#!/bin/bash

# Compile the necessary files (including all sorting algorithms)
echo "Compiling sorting program..."
g++ -o volsort main.cpp list.cpp qsort.cpp quick.cpp merge.cpp stl.cpp -O2
if [[ $? -ne 0 ]]; then
    echo "Compilation failed!"
    exit 1
fi

# Define input file names explicitly
input_files=("input_100000.txt" "input_500000.txt" "input_1000000.txt" "input_10000000.txt" "input_25000000.txt")

# Initialize results file
echo "| Mode  | Input File        | Elapsed Time (s) | Memory (KB) |" > results.md
echo "|-------|-------------------|------------------|-------------|" >> results.md

# Run benchmark for each input file and each mode
for file in "${input_files[@]}"; do
    if [[ ! -f "$file" ]]; then
        echo "Warning: $file not found, skipping..."
        continue
    fi

    for mode in "stl" "qsort" "merge" "quick"; do
        echo "Running $mode sort on $file..."
        
        # Capture start time and memory usage
        start_time=$(date +%s%3N)  # Millisecond precision
        /usr/bin/time -v ./volsort -$mode < "$file" > /dev/null 2> time_output.txt

        # Capture elapsed time and memory from the time_output.txt
        elapsed_time=$(echo "$(($(date +%s%3N) - $start_time))" | awk '{print $1/1000}')  # Convert to seconds
        memory=$(grep "Maximum resident set size" time_output.txt | awk '{print $6}')

        # Print to terminal
        echo "$mode | File: $file | Time: $elapsed_time sec | Memory: $memory KB"

        # Save to results file
        echo "| $mode | $file | $elapsed_time | $memory |" >> results.md
    done
done

echo "Benchmarking complete! Results saved in results.md"
