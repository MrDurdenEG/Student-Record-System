#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Function.h"

int main() {
    int choice;

    file();

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












