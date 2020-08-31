/*
  Kevin A. Roa
  Edited 8/29/2020
  A program to count the number of characters that are commented out. (Including tab, space, and newline)
  Usage (In shell):
    1. gcc countCommented.c -o countcommented
    2. ./countcommented < file
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
	char currChar = 0, prevChar = 0, commentType = '/';
  bool countChars = false;
  int  charCount = 0;

  while ((currChar = getchar()) != EOF) {
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

    if (countChars)
      charCount++;
    prevChar = currChar;
  }
  printf("Total Characters: %d\n", charCount);
}