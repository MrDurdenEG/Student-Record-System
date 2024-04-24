
#ifndef H_FUNCTION_H
#define H_FUNCTION_H

#define MAX_STUDENTS 100
#define ADMIN_PASSWORD "1234"
#define DATA_FILE "students.dat"
void adminMode();

void userMode();

void addStudent();

void viewStudents();

void findStudent();

int validate_password(const char *input);

void file();

void savefile();

void delete_student_record();

#endif // H_FUNCTION_H
