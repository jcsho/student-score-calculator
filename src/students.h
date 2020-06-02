#include <string>
#include <vector>

#ifndef STUDENTS_H
#define STUDENTS_H

namespace Calculator {

  class Students {
    private:
      std::string filename;
      std::vector<std::string> student_names;
      std::vector<int> scores;
      int average_score;
    public:

      Students(std::string filename);

      std::vector<int> get_scores();

      int calculate_average();

      void write_to_file();

  };
}

#endif
