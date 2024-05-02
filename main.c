

#include "student.h"

int main() {
    int choice;

    file();
    char admin_pass[20];
    strcpy(admin_pass ,ADMIN_PASSWORD);

    printf("Student Record System\n");
    printf("(1) Admin Mode\n");
    printf("(2) User Mode\n");
    printf("Choose mode: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            adminMode();
            break;
        case 2:
            userMode();
            break;
        default:
            printf("invalid choice\n");
            break;
    }

    return 0;
}
