#include <fstream>
#include <iostream>

using namespace std;

string read_input(string file_name) {
  string input;

  ifstream PuzzelInputFile(file_name);
  getline(PuzzelInputFile, input);
  PuzzelInputFile.close();

  return input;
}

int final_floor(string input) {
  int floor_count = 0;

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ')') {
      floor_count--;
    } else if (input[i] == '(') {
      floor_count++;
    }
  }

  return floor_count;
}

int first_basement(string input) {
  int floor_count = 0;

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ')') {
      floor_count--;
    } else if (input[i] == '(') {
      floor_count++;
    }

    if (floor_count == -1) {
      return i + 1;
    }
  }

  return -1;
}

int main() {
  string input;
  int final_floor_count;
  int first_basement_step;

  input = read_input("../input.txt");
  final_floor_count = final_floor(input);
  first_basement_step = first_basement(input);

  cout << final_floor_count;
  cout << "\n";
  cout << first_basement_step;
  return 0;
}
