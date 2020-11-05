#include <stdint.h>
#include "appconst.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct _student_ {
    char name[STUDENT_NAME_LEN];
    char program[PROGRAM_NAME_LEN];
    char email[EMAIL_LEN];
    int32_t regnumber;
    int32_t ent_test_rank;
    float ug_grade;
    char admission_status[ADMISSION_STATUS];

};

typedef struct _student_ Student;


struct _program_ {
    int32_t big_data_seats;
    int32_t machine_learning_seats;
    int32_t embedded_systems_seats;

    int32_t filled_bda_seats;
    int32_t filled_ml_seats;
    int32_t filled_es_seats;


};

typedef struct _program_ Program;

Program program_seats(int8_t bda, int8_t ml, int8_t es);
Student student_new(char name[], char prg[], char email[]);
int32_t test_admission_status(Student s1);
int8_t  filled_seats(Program pg, char branch[]);

#endif // STUDENT_H_INCLUDED