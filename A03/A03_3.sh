# Kevin A. Roa
# Edited 9/23/2020
# A shell script to generate 2 random numbers calculate their average
# Assignment specified to:
# 	Generate numbers in the range -5 to 25 using $RANDOM
# 	Print "High Average" if it is greater than 10
#		Print "Low Average" if it is less than or equal to 10
# Usage (In shell):
#   1. ./A03_3.sh

#!/bin/bash

# Generate random numbers from -5 to 25
num1=$(($RANDOM % 31 - 5))
num2=$(($RANDOM % 31 - 5))

echo "Numbers: $num1, $num2"

# Calculate the average
avg=`echo "scale=1; $(($num1+$num2))/2" | bc -l`

# Print whether high(>10) or low(<=10) average
if (( $(echo "$avg > 10" | bc -l) ));then
	echo "High Average ($avg)"
else
	echo "Low Average ($avg)"
fi