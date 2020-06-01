cmake_minimum_required( VERSION 3.10 )

project( student-score-calculator VERSION 1.0 )

include_directories( ./src )

add_executable ( calculator ./src/main.cpp )

