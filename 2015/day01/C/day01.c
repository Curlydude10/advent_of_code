#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *import_input(char *filename) {
  // These are needed for getlines, as it dynamically resizes the pointer
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  FILE *fptr = fopen(filename, "r");

  if (fptr != NULL) {
    // getlines only works on POSIXs systems
    read = getline(&line, &len, fptr);
  }

  free(line);
  fclose(fptr);
  return line;
}

int count_floor(char *input) {
  int floor = 0;
  int i;

  for (i = 0; i < strlen(input); i++) {
    if (input[i] == '(') {
      floor++;
    } else if (input[i] == ')') {
      floor--;
    }
  }

  return (floor);
}

int first_basement(char *input) {
  int floor = 0;
  int i;

  for (i = 0; i < strlen(input); i++) {
    if (input[i] == '(') {
      floor++;
    } else if (input[i] == ')') {
      floor--;
    }

    if (floor == -1) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  printf("Hello world!\n");
  char *input;
  int final_floor;
  int basement_index;

  input = import_input("../input.txt");

  final_floor = count_floor(input);
  basement_index = first_basement(input);

  printf("The Final Floor Santa Lands on is: %i\n", final_floor);
  printf("The index of the basement is: %i", basement_index);

  return 0;
}
