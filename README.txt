Context:
There are 20 Students
Each student has 10 Disciplines
Each Discipline has 2 Exams
In each Discipline each Student has a final grade (1-20) that is obtained through the median of the two exams 
Student fails if grade < 9.5

Objective:
Generate a file for each Discipline with studentName#grade per line
File has to be ordered by alphabetical ordered
Generate the final grade file whit only the students that have passed at least 8 Disciplines


Files to read:
ClassificacoesAlunos.txt -> studentID#Discipline#NumberOfExam#Grade (per line)
NomeAlunos.txt -> studentName#studentID

RUN:
1. create folder and put all files in the folder
2. open folder in the terminal (or command line)
COMPILE
3. gcc -o main main.c
RUN EXE
4. ./main