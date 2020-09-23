# Kevin A. Roa
# Edited 9/23/2020
# A shell script to generate 2 random numbers then compare them
# Assignment specified to:
# 	Generate numbers in the range 1-10 using $RANDOM
# 	Print appropriate message to shell
# Usage (In shell):
#   1. ./compareRandom.sh

#!/bin/bash

# Generate random numbers 1-10
num1=$(($RANDOM % 10 + 1))
num2=$(($RANDOM % 10 + 1))

# Alternative to generating random numbers
# num1=$(shuf -i 1-10 -n 1 -r)
# num2=$(shuf -i 1-10 -n 1 -r)

# Print the numbers to shell
echo $num1
echo $num2

# Test if they are the same
if [ $num1 -eq $num2 ];then
	# If same then print match found
	echo 'Match Found.'
else
	# If different then print different numbers
	echo 'Different Numbers.'
fi
