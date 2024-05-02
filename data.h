
#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "students.csv"
#define ADMIN_PASSWORD "1234"


#define MAX_STUDENTS 100


int studentCount = 0;
void savefile();
void file();
void save_admin_pass();
void call_admin_pass();

typedef struct {
    char *name;
    int totalGrade;
    int id;
    int age;
    char gender[10];
    char *password;
} Student;

Student *students[MAX_STUDENTS];
#endif // DATA_H


