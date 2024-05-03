
#ifndef ADMIN_H
#define ADMIN_H

#include "data.h"



void adminMode();
int validate_password(const char *input);
void addStudent();
void view_all_records();
void view_Student_record();
void delete_student_record();
void edit_student_grade();
void change_admin_password();
#endif // ADMIN_h
