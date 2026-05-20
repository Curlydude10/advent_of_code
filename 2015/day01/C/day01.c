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

int main() {
  printf("Hello world!\n");
  char *input;
  int final_floor;

  input = import_input("../input.txt");

  final_floor = count_floor(input);

  printf("The Final Floor Santa Lands on is: %i", final_floor);

  return 0;
}
