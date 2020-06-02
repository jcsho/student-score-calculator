#include <string>
#include <vector>

#ifndef STUDENTS_H
#define STUDENTS_H

namespace Calculator {

  // Parses a space delimited file of name and score
  // to calculate the average and prepend the file with the output
  // Example:
  //    Calculator::Students students("filename.txt");
  //    students.get_scores();
  //    students.calculate_average();
  //    students.write_to_file();
  class Students {
    private:
      // Keeps the file name for object in case it needs to be reused
      std::string filename;
      // Store the names from the file (mapped 1:1 with scores) / not in use for anything atm
      std::vector<std::string> student_names;
      // Store the scores from the file (mapped 1:1 with the names)
      std::vector<int> scores;
      int average_score;
    public:

      Students(std::string filename);

      // Parses file and stores the names and scores in memory
      // returns the scores in the same order
      // throws filenotfound error
      // throws unparseable error
      std::vector<int> get_scores();
      
      // Calculates mean value from all scores in the file and saves it in memory
      // returns the mean value
      int calculate_average();

      void write_to_file();

  };
}

#endif
