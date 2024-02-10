# Final Grade Generator
Principles of Procedural Programming

## Project Overview

This project involves the development of a program to generate final grades from partial scores. It showcases handling of file input/output, error detection and handling, and dynamic data structures, specifically doubly linked lists.

## Key Features

- **Error Handling**: The program anticipates and manages errors gracefully. In cases where error recovery is complex or not feasible, it flags them clearly.
- **Data Input Requirements**: Input data must be sensible and include at least 100 entities. The input files must be part of the final submission.
- **Data Structure Interface**: The interface with the data structure used is well-defined. The implementation is contained in a separate source file with static variables, ensuring encapsulation.
- **Input File Format**: Reads from a text file, with one entity per line and attributes separated by the '#' character. The input file name is obtained from the command line.
- **Generating Final Grades**: The program calculates final grades based on partial scores for a list of students enrolled in multiple subjects. Each student must have entries for at least 20 students and 10 subjects per student, with two exams per subject. Final grades are the average of these exams.
- **Output Generation**: Produces subject-specific grade lists and a general list indicating students who passed the year (succeeding in at least 8 subjects). Outputs are written to a text file, with entities per line and attributes separated by '#'. The output file name is prompted from the user.

## Implementation Details

- Utilizes doubly linked lists for dynamic memory management.
- The program is structured to ensure clear separation between the data structure implementation and the main application logic.
  
## Environment

CLion

## Run
gcc -o main main.c

./main.c
