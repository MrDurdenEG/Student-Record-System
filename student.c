#include "student.h"

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
                view_record_id();
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
        Student *s = students[i];
        if (s->id == id && strcmp(s->password, password) == 0) {
            printf("Student Details:\n");
            printf("Name: %s\n", s->name);
            printf("ID: %d\n", s->id);
            printf("Age: %d\n", s->age);
            printf("Gender: %s\n",s->gender);
            printf("Total Grade: %d\n", s->totalGrade);
            return;
        }
    }

    printf("No student found with the given ID and password.\n");

}

