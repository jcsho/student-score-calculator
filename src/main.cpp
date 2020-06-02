#include <iostream>
#include "students.h"

int main(int argc, char** argv) {
  Calculator::Students students(argv[1]);
  students.get_scores();
  return 0;
}
