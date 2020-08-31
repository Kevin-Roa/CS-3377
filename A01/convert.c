/*
  Kevin A. Roa
  Edited 8/29/2020
  A program to convert fahrenheit to celsius
	Assignment specified to display in range of 100-400 with step of 20F
  Usage (In shell):
    1. gcc convert.c -o convert
    2. ./convert
*/

#include <stdio.h>
#define STEP 20
#define LOWERLIMIT 100
#define UPPERLIMIT 400

int main() {
	float tempF = LOWERLIMIT;
	float tempC = 0;
	while (tempF <= UPPERLIMIT) {
		tempC = (tempF - 32.0) * (5.0 / 9.0);
		printf("%3.0f   %6.2f\n", tempF, tempC);
		tempF += STEP;
	}
}

