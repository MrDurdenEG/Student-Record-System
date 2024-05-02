#include "data.h"

void savefile(){
    FILE *file = fopen(DATA_FILE, "wb");
    if (file == NULL) {
        printf("Error !! \n");
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



