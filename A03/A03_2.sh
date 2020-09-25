# Kevin A. Roa
# Edited 9/23/2020
# A shell script to read in two numbers then perform and display +,-,*,/
# Usage (In shell):
#   1. ./A03_2.sh

#!/bin/bash

# Get user input
printf 'Enter a number: '
read x
printf 'Enter a number: '
read y

# Print calculations
echo
echo "Addition: $((x+y))"
echo "Subtraction: $((x-y))"
echo "Multiplication: $((x*y))"

# Test for divide by 0
if [ $y -eq 0 ];then
	# Print error on divide by 0
	echo 'Division: ERROR'
else
	# Print division
	div=`echo "scale=4; $x/$y"| bc -l | sed 's!\.0*$!!'`
	echo "Division: $div"
fi