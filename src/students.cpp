#include "students.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

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

    int total_score = 0;

    for (int i = 0; i < scores.size(); i++) {
      total_score += scores[i];
    }


    average_score = total_score / scores.size();

    return average_score;
  }

  // implementation creates an empty new file
  // inserts the resulting string as the first line
  // copies original file content into new file
  // deletes the original file
  // renames new file to original file
  // see https://stackoverflow.com/questions/11108238/adding-text-and-lines-to-the-beginning-of-a-file-c
  void Students::write_to_file() {

    std::string temp_filename = "temp_file.txt";
    std::ifstream base_file;
    std::ofstream dest_file;

    base_file.open(filename);
    dest_file.open(temp_filename);

    std::string output_string = output_text + std::to_string(average_score);

    if (base_file.is_open()) {
      dest_file << output_string << std::endl;
      dest_file << base_file.rdbuf();
    }

    base_file.close();
    dest_file.close();
    
    // remove() and rename() requires const char*
    // https://cplusplus.com/reference/string/string/c_str
    const char* c_filename = filename.c_str();
    const char* c_temp_filename = temp_filename.c_str();
    std::remove(c_filename);
    std::rename(c_temp_filename, c_filename);

    return;
  }
}
