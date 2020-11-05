#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../Headers/student.h"


int main(){
    
    int choice;
    Student s[200];
    Student temp;
    int count = 0;
    int bda, ml, es = 0;
    int baseregNumber_BDA = 201046000;
    int baseregNumber_ML = 201056000;
    int baseregNumber_ES = 201036000;

     printf("Initialize the courses \n");
     printf("BDL Course: ");
     scanf("%d", &bda);
     printf("\nML Course: ");
     scanf("%d", &ml );
     printf("\nES Course: ");
     scanf("%d", &es );
     printf("\n");
    Program pg = program_seats(bda, ml, es);

    ch:
    printf("\nPress 1 to enter the student details\n");
    printf("Press 2 to display the student details\n");
    printf("Press 3 to Allot seats\n");
    printf("Press 4 to see seats filled in each program\n");
    printf("Press 5 to arrange the Student List as per Rank\n");
    printf("Press 6 to assign available to seats for Waitlisting students\n");
    scanf("%d", &choice);

    switch(choice){
        case 1: {
            printf("\nEnter the Student Details:\n");
            printf("\nEnter the Student Name: ");
            scanf("%64s", s[count].name);
            printf("Enter the Student Program Name (BDA/ML/ES): ");
            scanf("%22s", s[count].program);
            printf("Enter the Student Emai Id: ");
            scanf("%20s", s[count].email);
            printf("Enter the Student Entrance Test Rank: ");
            scanf("%d", &s[count].ent_test_rank);
            printf("Enter the Student UG Grade: ");
            scanf("%f", &s[count].ug_grade);
            printf("\n");
      
            count++;
            goto ch;
        }
        case 2: {
            printf("\nName\t\tEmail\t\t\tProgram\t\tRank\t\tUGGrade\t\tAdmissionStatus\t\tRegNumber\n");
            for (int i = 0; i < count; i++){           
                printf("%s\t\t%s\t\t%s\t\t%d\t\t%f\t\t%s\t\t%d", s[i].name,s[i].email, s[i].program, s[i].ent_test_rank, s[i].ug_grade, s[i].admission_status, s[i].regnumber);
                printf("\n");
            }
            printf("\n");
            goto ch;
        }
        case 3: {
            for(int i =0; i< count; i++){
                if ((strcmp(s[i].admission_status, "alloted") != 0 && strcmp(s[i].admission_status, "rejected") != 0) && (strcmp(s[i].program,"BDA") == 0 || strcmp(s[i].program, "bda") == 0 ) && (pg.filled_bda_seats < pg.big_data_seats)){
                if (s[i].ug_grade < 5.0) {
                    strcpy(s[i].admission_status, "rejected");
                }
                else {
                    strcpy(s[i].admission_status, "alloted");
                    pg.filled_bda_seats++;
                    baseregNumber_BDA++;
                    s[i].regnumber = baseregNumber_BDA;
                }
            }
            
            else if ((strcmp(s[i].admission_status, "alloted") != 0 && strcmp(s[i].admission_status, "rejected") != 0) && (strcmp(s[i].program,"ML") == 0 || strcmp(s[i].program, "ml") == 0 ) && pg.filled_ml_seats < pg.machine_learning_seats){
                if (s[i].ug_grade < 5.0) {
                    strcpy(s[i].admission_status, "rejected");
                }
                else {
                    strcpy(s[i].admission_status, "alloted");
                    pg.filled_ml_seats++;
                    baseregNumber_ML++;
                    s[i].regnumber = baseregNumber_ML;
                }

            }
            else if ((strcmp(s[i].admission_status, "alloted") != 0 && strcmp(s[i].admission_status, "rejected") != 0) && (strcmp(s[i].program,"ES") == 0 || strcmp(s[i].program, "es") == 0 ) && pg.filled_es_seats < pg.embedded_systems_seats){
                if (s[i].ug_grade < 5.0) {
                    strcpy(s[i].admission_status, "rejected");
                }
                else {
                    strcpy(s[i].admission_status, "alloted");
                    pg.filled_es_seats++;
                    baseregNumber_ES++;
                    s[i].regnumber = baseregNumber_ES;
                }

            }
            else if (s[i].ug_grade < 5.0) {
                    strcpy(s[i].admission_status, "rejected");
            }
            
            else {  
                if (strcmp(s[i].admission_status, "alloted") != 0 && strcmp(s[i].admission_status, "rejected") != 0) {
                     strcpy(s[i].admission_status, "waiting");
                }
            }
         }
         printf("Seat Alloted as per Students Rank");
         goto ch;
        }
        case 4: {
            printf("\nProgram\t\t\t\tSeats\t\tFilled Seats\tAvailable Seats\n");
            printf("\nBDA\t\t\t\t%d\t\t%d\t\t%d", pg.big_data_seats, pg.filled_bda_seats, (pg.big_data_seats-pg.filled_bda_seats));
            printf("\nML\t\t\t\t%d\t\t%d\t\t%d", pg.machine_learning_seats, pg.filled_ml_seats, (pg.machine_learning_seats-pg.filled_ml_seats));
            printf("\nES\t\t\t\t%d\t\t%d\t\t%d", pg.embedded_systems_seats, pg.filled_es_seats, (pg.embedded_systems_seats-pg.filled_es_seats));
            printf("\n");
            goto ch;
        }
        case 5: {
            for(int a=0;a<count;a++) {
              for(int b=a+1;b<count;b++){
                    if(s[a].ent_test_rank>s[b].ent_test_rank)
                    {
                        temp=s[a];
                        s[a]=s[b];
                        s[b]=temp;
                    }
                }
            }
            printf("Student List arranged as per Rank\n");
            goto ch;
        }
        case 6: {
                  int c = count;
                  for(int i=0; i < count; i++){
                      if (strcmp(s[i].admission_status, "waiting") == 0) {
                            s[c] = s[i];
                            printf("\nPlease enter the 2 additional programs for seat allotment (BDL/ML/ES)\n");
                            printf("Select course except %s \n", s[c].program);
                            printf("\nCourse 1: ");
                            strcpy(s[c].admission_status, "");
                            scanf("%22s", s[c].program);
                            c++;
                            s[c] = s[i];
                            printf("\nCourse 2: ");
                            strcpy(s[c].admission_status, "");
                            scanf("%22s", s[c].program);
                            c++;
                      }
                  }
                  count = c;
                  printf("\n");
                  goto ch;
        }
        default: {
            break;
        }

    }
    
      
  return 0;

}


