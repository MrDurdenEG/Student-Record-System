#include "Function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int totalGrade;
    int id;
    int age;
    char gender[10];
    char password[20];
} Student;

void adminMode()
{
    char password[20];
    printf("Enter Admin Password: ");
    scanf("%s", password);

    if (!validate_password(password))
    {
        printf("wrong password\n");
        return;
    }

    int choice;
    do
    {
        printf("Admin Mode:\n");
        printf("(1) Add student record\n");
        printf("(2) Remove student record \n");
        printf("(3) View all records\n");
        printf("(4) Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            delete_student_record();
            break;
        case 3:
            viewStudents();
            break;
        case 4:
            printf("Exiting Admin Mode.\n");
            break;
        default:
            printf("invalid choice.\n");
            break;
        }
    }
    while (choice != 3);
}


void userMode() {
    int choice;
    do {
        printf("User Mode:\n");
        printf("(1) Find Student by ID\n");
        printf("(2) Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findStudent();
                break;
            case 2:
                printf("exiting User Mode\n");
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    } while (choice != 2);
}


Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached MAX \n\n");
        return;
    }

    Student student_created;
    printf("Enter Student Name: ");
    scanf("%s", student_created.name);
    printf("Enter Student ID: ");
    scanf("%d", &student_created.id);

    int choice=0;
    do{
    for (int i = 0; i < studentCount; i++) {
        if(student_created.id == students[i].id){
            printf("Id already exist !\n\n");
            return;
        }
    }
    }while (choice != 3);

    printf("Enter Student Age: ");
    scanf("%d", &student_created.age);
    printf("Enter Student Gender: ");
    scanf("%s", student_created.gender);
    printf("Enter Student Total Grade: ");
    scanf("%d", &student_created.totalGrade);
    printf("Enter Student Password: ");
    scanf("%s", student_created.password);

    students[studentCount++] = student_created;
    printf("Student added successfully.\n");

    savefile();
}

void viewStudents() {
    if (studentCount == 0) {
        printf("no students found\n");
        return;
    }

    printf("Student Records:\n");
    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Total Grade: %d\n",
               s.id, s.name, s.age, s.gender, s.totalGrade);
    }
}

void findStudent() {
    int id;
    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            Student s = students[i];
            printf("Student Details:\n");
            printf("Name: %s\n", s.name);
            printf("ID: %d\n", s.id);
            printf("Age: %d\n", s.age);
            printf("Gender: %s\n", s.gender);
            printf("Total Grade: %d\n\n", s.totalGrade);
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}

int validate_password(const char *input) {
    return strcmp(input, ADMIN_PASSWORD) == 0;
}


void savefile(){
    FILE *file = fopen(DATA_FILE, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&studentCount, sizeof(studentCount), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
}

void file() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file == NULL) {

        return;
    }

    fread(&studentCount, sizeof(studentCount), 1, file);
    fread(students, sizeof(Student), studentCount, file);
    fclose(file);
}

void delete_student_record() {
    int id ;
    printf("enter student id to delete :");
    scanf("%d",&id);

    int pos=-1;

    for(int i=0 ; i < studentCount ; i++){
        if(students[i].id == id){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("the ID you entered doesnt exist !!\n\n");
        return;
    }

    for(int i = pos ; i < studentCount-1 ; i++){
            students[i] = students[i+1];
    }

    studentCount--;
    printf("Student record deleted :)\n\n");

    savefile();
}
