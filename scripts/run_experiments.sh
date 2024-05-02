#!/bin/bash

# Directory for executable
BIN_DIR="./bin"
EXEC="hashgen"

# Output directory for logs
LOG_DIR="./logs"
mkdir -p $LOG_DIR

# Array of thread counts
declare -a threads=(1 4 16)

# Memory size in MB for SMALL configuration
memory_size=128

# Loop over thread counts for hash, sort, and write operations
for t_hash in "${threads[@]}"
do
  for t_sort in "${threads[@]}"
  do
    for t_write in "${threads[@]}"
    do
      echo "Running experiment with $t_hash hash threads, $t_sort sort threads, and $t_write write threads"
      start_time=$(date +%s%N)  # Get start time in nanoseconds
      ./$BIN_DIR/$EXEC -h $t_hash -s $t_sort -w $t_write -m $memory_size > "$LOG_DIR/experiment_h${t_hash}_s${t_sort}_w${t_write}.log"
      end_time=$(date +%s%N)    # Get end time in nanoseconds
      elapsed=$(( (end_time - start_time) / 1000000 )) # Convert to milliseconds
      echo "Experiment h${t_hash}_s${t_sort}_w${t_write} completed in $elapsed ms."
      echo "Time taken: $elapsed ms" >> "$LOG_DIR/experiment_h${t_hash}_s${t_sort}_w${t_write}.log"
    done
  done
done

echo "All experiments completed."
