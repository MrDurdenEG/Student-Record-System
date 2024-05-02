
#ifndef ADMIN_H
#define ADMIN_H

#include "data.h"
#include "student.h"

void adminMode();
int validate_password(const char *input);
void addStudent();
void view_all_records();
void view_Student_record();
void delete_student_record();



#endif // ADMIN_h
