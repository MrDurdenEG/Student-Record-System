
#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "students.txt"
//extern char ADMIN_PASSWORD[20] ;

#define MAX_STUDENTS 100

#define PASSWORD_FILE "admin_password.txt"


extern int studentCount ;

typedef struct {
    char name[20];
    int totalGrade;
    int id;
    int age;
    char gender[10];
    char password[20];
} Student;

Student students[MAX_STUDENTS];

void savefile();
void file();
void read_admin_password(char *password);
void write_admin_password(char *password);

#endif // DATA_H


