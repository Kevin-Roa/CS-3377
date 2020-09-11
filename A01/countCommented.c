/*
  Kevin A. Roa
  Edited 9/11/2020
  A program to count the number of characters and words that are commented out in a file.
  (Including tab, space, and newline)
  Usage (In shell):
    1. gcc countCommented.c -o countcommented
    2. ./countcommented < fileToCount
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
	char currChar = 0, prevChar = 0, commentType = '/';
  bool countChars = false;
  int charCount = 0, wordCount = 0;

  while ((currChar = getchar()) != EOF) {
    // Test if at a comment
    if (currChar == '*' || currChar == '/') {
      // If in the form // or /*
      if (prevChar == '/') {
        // Then begin to count the characters
        countChars = true;
        commentType = currChar;
        continue;
      }
      // Stop counting /* */ type comments
      // Stops if encounters */
      else if (prevChar == '*') {
        charCount--;
        countChars = false;
        continue;
      }
    }
    // Stop counting // type comments
    // Stops if encounters newline
    else if (countChars && currChar == '\n' && commentType == '/') {
      charCount++;
      countChars = false;
    }

    if (countChars) {
      // Update word count
      if ((currChar != ' ' && currChar != '\n' && currChar != '*') && (prevChar == ' ' || prevChar == '\t'))
        wordCount++;
      
      // Update character count
      charCount++;
    }

    prevChar = currChar;
  }
  printf("Total Characters: %d\n", charCount);
  printf("Total Words:      %d\n", wordCount);
}