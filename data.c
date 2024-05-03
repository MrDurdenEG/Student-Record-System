#include "data.h"

void savefile() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }


    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s %d %d %s %d %s\n", students[i].name, students[i].id, students[i].age, students[i].gender, students[i].totalGrade, students[i].password);
    }

    fclose(file);
}

void file() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        printf("No student records found.\n");
        return;
    }

    while (fscanf(file, "%s %d %d %s %d %s", &(students[studentCount].name), &(students[studentCount].id), &(students[studentCount].age), &(students[studentCount].gender), &(students[studentCount].totalGrade), &(students[studentCount].password)) != EOF) {

        studentCount++;
    }
    fclose(file);
}

void read_admin_password(char *password) {
    FILE *file = fopen(PASSWORD_FILE, "r");
    if (file == NULL) {
        strcpy(password, "1234");
        *password = '\0';
        return;
    }

    fscanf(file, "%s", password);
    fclose(file);
}

void write_admin_password(char *password) {
    FILE *file = fopen(PASSWORD_FILE, "w");
    if (file == NULL) {
        printf("Error opening file to write password\n");
        return;
    }

    fprintf(file, "%s", password);
    fclose(file);
}
