#include "admin.h"

void adminMode() {
    char password[20];
    int attempts = 0;
    while (attempts < MAX_PASSWORD_ATTEMPTS)
        {
    printf("Enter Admin Password: ");
    scanf("%s", password);
    if (validate_password(password))
        {
            break;
        }
    attempts++;
        if (attempts < MAX_PASSWORD_ATTEMPTS) {
            printf("Wrong password. You have %d attempts left.\n", MAX_PASSWORD_ATTEMPTS - attempts);
        }
    }

    if (attempts == MAX_PASSWORD_ATTEMPTS) {
        printf("Too many failed attempts. Exiting Admin Mode.\n");
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
        printf("(5) Edit student grade\n");
        printf("(6) change admin password\n");
        printf("(7) back to the main menu\n");
        printf("(8) Exit\n");
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
            edit_student_grade();
            break;
        case 6:
            change_admin_password();
            break;
        case 7:
            main();
            break;
        case 8:
            printf("Exiting Admin Mode\n");
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
    while (choice != 8);
}


int validate_password(const char *input) {
    char stored_password[20];
    read_admin_password(stored_password);
    return strcmp(input, stored_password) == 0;
}

studentCount = 0;

void addStudent() {
    printf("%d\n",studentCount);
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached MAX \n\n");
        return;
    }
    Student new_student;

    printf("Enter Student Name: ");
    scanf("%s", new_student.name);
    int flag=0;
    do
    {
        printf("Enter Student ID: ");
        scanf("%d", &new_student.id);

        for (int i = 0; i < studentCount; i++)
        {
            flag=0;
            if(new_student.id == students[i].id)
            {
                printf("Id already exist !\n\n");
                flag=1;
                break;
            }

        }
    }while(flag);

    printf("Enter Student Age: ");
    scanf("%d", &new_student.age);
    printf("Enter Student Gender: ");
    scanf("%s", new_student.gender);
    do {
        printf("Enter Student Total Grade (0-100): ");
        scanf("%d", &new_student.totalGrade);

        if (new_student.totalGrade < 0 || new_student.totalGrade > 100) {
            printf("Invalid grade! Please enter a value between 0 and 100.\n");
        }
    } while (new_student.totalGrade < 0 || new_student.totalGrade > 100);

    printf("Enter Student Password: ");
    scanf("%s", new_student.password);

    students[studentCount++] = new_student;
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
            Student s = students[i];
            printf("ID: %d, Name: %s, Age: %d, Gender: %s, Total Grade: %d\n",
                   s.id,
                   s.name,
                   s.age,
                   s.gender,
                    s.totalGrade);

   }
}

void view_Student_record() {
    int id;
    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
                file();
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
void edit_student_grade()
{
    int id;
    int new_grade;
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
                 do {
            printf("enter the new grade (0-100): ");
            scanf("%d",&new_grade);
        if (new_grade < 0 || new_grade> 100) {
            printf("Invalid grade! Please enter a value between 0 and 100.\n");
        }
    } while (new_grade < 0 || new_grade > 100);
            students[i].totalGrade=new_grade;
            savefile();
            printf("Student grade updated successfully \n\n");
            return;
        }
    }
    printf("Student with ID %d not found\n", id);
}

void change_admin_password()
{
  char current_password[19];
    char new_password[19];
    char entered_password[19];
   read_admin_password(current_password);

    printf("enter the old password : ");
    scanf("%s",entered_password);
if (strcmp(entered_password, current_password) == 0) {
        printf("Enter the new password: ");
        scanf("%19s", new_password);

        write_admin_password(new_password);

        printf("Password changed successfully.\n");
        return;
    }
    printf("the old password is wrong !!\n\n");
}
