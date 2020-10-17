# Kevin A. Roa
# Edited 10/17/2020
# A python script to read a file and print the # of words and sentences.
# Usage (In shell):
#   1. python3 DB05.py

#	Get file name from user
fileName = input("Enter a file name: ")

# Initialize counters
wordCount = sentenceCount = 0

# Open file
with open(fileName, 'r') as file:
	# Loop through every line in file
	for line in file:
		# Split the line on every word and get the count
		wordCount += len(line.split())
		# Count every occurance of .?! in the line and sum them up
		sentenceCount += sum([line.count(x) for x in ['.', '?', '!']])

# Print the word and sentence count
print(fileName, 'has', wordCount,'words and', sentenceCount, 'sentences.')
