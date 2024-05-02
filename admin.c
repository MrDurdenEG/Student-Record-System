#include "admin.h"

void adminMode() {
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
        printf("(3) View student record\n");
        printf("(4) View all records\n");
        printf("(5) Exit\n");
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
            view_Student_record();
            break;
        case 4:
            view_all_records();
            break;
        case 5:
            printf("Exiting Admin Mode\n");
        default:
            printf("invalid choice\n");
            break;
        }
    }
    while (choice != 5);
}

int validate_password(const char *input) {
    return strcmp(input, ADMIN_PASSWORD) == 0;
}



void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached MAX \n\n");
        return;
    }

    Student new_student;
    printf("Enter Student Name: ");
    scanf("%s", new_student.name);
    int flag;
    while(flag)
    {
        printf("Enter Student ID: ");
        scanf("%d", &new_student.id);

        for (int i = 0; i < studentCount; i++)
        {
            flag=0;
            if(new_student.id == students[i]->id)
            {
                printf("Id already exist !\n\n");
                flag=1;
                return;
            }

        }
    }
    printf("Enter Student Age: ");
    scanf("%d", &new_student.age);
    printf("Enter Student Gender: ");
    scanf("%s", new_student.gender);
    printf("Enter Student Total Grade: ");
    scanf("%d", &new_student.totalGrade);
    printf("Enter Student Password: ");
    scanf("%s", new_student.password);

    *students[studentCount++] = new_student;
    printf("Student added successfully.\n");

    savefile();
}

void view_all_records() {
    if (studentCount == 0) {
        printf("no students found\n");
        return;
    }

    printf("Student Records:\n");
    for (int i = 0; i < studentCount; i++) {
        Student *s = students[i];
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Total Grade: %d\n",
               s->id, s->name, s->age, s->gender, s->totalGrade);
    }
}

void view_Student_record() {
    int id;
    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i]->id == id) {
            Student *s = students[i];
            printf("Student Details:\n");
            printf("Name: %s\n", s->name);
            printf("ID: %d\n", s->id);
            printf("Age: %d\n", s->age);
            printf("Gender: %s\n", s->gender);
            printf("Total Grade: %d\n\n", s->totalGrade);
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}

void delete_student_record() {
    int id ;
    printf("enter student id to delete :");
    scanf("%d",&id);

    int pos=-1;

    for(int i=0 ; i < studentCount ; i++){
        if(students[i]->id == id){
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
