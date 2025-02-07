#!/bin/bash

# Compile only if volsort does not exist or if source files are updated
if [ ! -f volsort ] || [ main.cpp -nt volsort ] || [ qsort.cpp -nt volsort ] || [ quick.cpp -nt volsort ]; then
    echo "Compiling volsort..."
    g++ -o volsort main.cpp list.cpp qsort.cpp quick.cpp -O2
fi

# Define test input sizes
sizes=(100000 500000 1000000 10000000)

# Generate input files
generate_input() {
    for size in "${sizes[@]}"; do
        shuf -i 1-1000000000 -n $size > "input_$size.txt"
    done
}

# Run benchmarks and record results
run_benchmark() {
    echo "| Mode  | Size  | Elapsed Time (s) | Memory (KB) |" > results.md
    echo "|-------|-------|----------------|-------------|" >> results.md

    for mode in "qsort" "quick"; do
        for size in "${sizes[@]}"; do
            echo "Running $mode sort on $size numbers..."
            /usr/bin/time -f "%e %M" ./volsort -m $mode < "input_$size.txt" 2> temp.txt > /dev/null
            read -r time mem < temp.txt
            echo "| $mode | $size | $time | $mem |" >> results.md
            rm temp.txt
        done
    done
}

# Run the steps
generate_input
run_benchmark
echo "Benchmarking complete! Check results.md"
