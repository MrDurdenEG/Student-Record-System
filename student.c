#include "student.h"

void userMode() {
    int choice;
    do {
        printf("User Mode:\n");
        printf("(1) Find Student by ID\n");
        printf("(2) edit student name\n");
        printf("(3) edit student password\n");
        printf("(4) back to the main menu\n");
        printf("(5) Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            view_record_id();
            break;
        case 2:
            edit_student_name();
            break;
        case 3:
            edit_student_password();
            break;
        case 4:
            main();
            break;
        case 5:
            printf("exiting User Mode\n");
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    } while (choice != 5);
}



void view_record_id()
{
    int id;
    char password[20];
    if(studentCount == 0){
        printf("there is no students \n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%d", &id);
    printf("Enter Student Password: ");
    scanf("%s", password);

    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        if (s.id == id && strcmp(s.password, password) == 0) {
            printf("Student Details:\n");
            printf("Name: %s\n", s.name);
            printf("ID: %d\n", s.id);
            printf("Age: %d\n", s.age);
            printf("Gender: %s\n",s.gender);
            printf("Total Grade: %d\n", s.totalGrade);
            return;
        }
    }

    printf("No student found with the given ID and password.\n");

}

void edit_student_name()
{
    int id;
    char new_name[20];
    if(studentCount == 0)
    {
        printf("there is no students \n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id) {

            printf("enter the new name : ");
            scanf("%s",new_name);
            strcpy(students[i].name,new_name);
            savefile();
            printf("Student name updated successfully \n\n");
            return;
        }
    }
    printf("Student with ID %d not found\n", id);
}
void edit_student_password()
{
    int id;
    char password[20];
    char new_password[20];
    if(studentCount == 0)
    {
        printf("there is no students \n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &id);
    printf("Enter Student passwrod: ");
    scanf("%s", &password);
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            if(strcmp(students[i].password,password)==0)
            {

                printf("enter the new password : ");
                scanf("%s",new_password);
                strcpy(students[i].password,new_password);
                savefile();
                printf("Student password updated successfully \n\n");
                return;
            }
                printf("you entered Wrong password !! \n");
                return;
        }
    }
    printf("Student with ID %d not found\n", id);
}
