#include <stdio.h>

void printValues();
int num, num2, *numPtr;

int main() {
  puts("Setting value of num to 0");
  puts("Setting value of num2 to 1");
  puts("Setting address of numPtr to num");
  num = 0;
  num2 = 1;
  numPtr = &num;
  printValues();

  puts("\nSetting value of num to 2");
  num = 2;
  printValues();

  puts("\nSetting value of numPtr to 3");
  *numPtr = 3;
  printValues();

  puts("\nSetting value of num2 to 4");
  num2 = 4;
  printValues();

  puts("\nSetting address of numPtr to num2");
  numPtr = &num2;
  printValues();

  puts("\nSetting value of num2 to numPtr");
  num2 = *numPtr;
  printValues();

  puts("\nSetting value of num2 to 5");
  num2 = 5;
  printValues();
}

void printValues() {
  printf("Num Value:      %d\n", num);
  printf("Num Address:    %p\n", (void *) &num);
  printf("Num2 Value:     %d\n", num2);
  printf("Num2 Address:   %p\n", (void *) &num2);
  printf("NumPtr Value:   %d\n", *numPtr);
  printf("NumPtr Address: %p\n", (void *) numPtr);
}