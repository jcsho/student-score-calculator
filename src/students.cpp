#include "students.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace Calculator {

  Students::Students(std::string filename) {
    this->filename = filename;
  }

  std::vector<int> Students::get_scores() {
    std::ifstream file;
    file.open(filename);
    
    if (file.is_open()) {
      std::string name;
      int score;
      while (file >> name >> score ) {
        student_names.push_back(name);
        scores.push_back(score);
        // debug output
        // std::cout << "Student: " + name + " Score: " + std::to_string(score) << std::endl;
      }
      file.close();
    } else {
      std::cout << "Cannot open " + filename << std::endl;
    }

    return scores;
  }

  int Students::calculate_average() {

    return average_score;
  }

  void Students::write_to_file() {

    return;
  }
}
