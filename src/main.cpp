#include <iostream>
#include "students.h"

int main(int argc, char** argv) {
  Calculator::Students students(argv[1]);
  students.get_scores();
  std::cout << "Average Score: " + std::to_string(students.calculate_average()) << std::endl;
  return 0;
}
