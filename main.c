/*
Name: Naiwumbwe Assumpta
Registration Number: 23/U/08557/PE
*/

#include <stdio.h>

int main(void) {

    /* Declare variables here */
    const char *sem1_codes[8]  = {"TEMB 1101","TEMB 1102","TEMB 1103","TEMB 1104",
                                   "TEMB 1105","TEMB 1106","TEMB 1107","TEMB 1108"};
    const char *sem1_names[8]  = {"Fundamentals of Engineering Mathematics",
                                   "Biochemistry and Medical Physics",
                                   "Electrical Engineering Science",
                                   "Mechanics I","Computing I",
                                   "Mechanical Drawing","Engineering Profession",
                                   "Functional Anatomy and Physiology I"};
    const int   sem1_credits[8] = {4, 3, 3, 3, 3, 3, 2, 3};

    const char *sem2_codes[8]  = {"TEMB 1201","TEMB 1202","TEMB 1203","TEMB 1204",
                                   "TEMB 1205","TEMB 1206","TEMB 1207","TEMB 1208"};
    const char *sem2_names[8]  = {"Further Engineering Mathematics",
                                   "Computing II","Mechatronics Drawing",
                                   "Fluid Mechanics","Thermodynamics",
                                   "Workshop Practice",
                                   "Functional Anatomy and Physiology II",
                                   "Electronics I"};
    const int   sem2_credits[8] = {4, 3, 3, 3, 3, 3, 3, 3};

    int    sem1_scores[8], sem2_scores[8];
    int    sem1_gp[8],     sem2_gp[8];
    char   sem1_grade[8],  sem2_grade[8];
    double sem1_weighted[8], sem2_weighted[8];
    double sem1_weighted_sum = 0.0, sem2_weighted_sum = 0.0;
    int    sem1_total_credits = 0,  sem2_total_credits = 0;
    double sem1_gpa, sem2_gpa, cgpa;
    const char *classification;
    int i;

    /* Read 16 scores */
    printf("========================================\n");
    printf("    GPA / CGPA CALCULATOR - YEAR ONE    \n");
    printf("========================================\n\n");

    printf("--- Enter Semester I Scores ---\n");
    for (i = 0; i < 8; i++) {
        printf("Score for %s (%s): ", sem1_codes[i], sem1_names[i]);
        scanf("%d", &sem1_scores[i]);
    }

    printf("\n--- Enter Semester II Scores ---\n");
    for (i = 0; i < 8; i++) {
        printf("Score for %s (%s): ", sem2_codes[i], sem2_names[i]);
        scanf("%d", &sem2_scores[i]);
    }

    /* Validate input */
    for (i = 0; i < 8; i++) {
        if (sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }

    /* Determine grades and grade points */
    for (i = 0; i < 8; i++) {
        if      (sem1_scores[i] >= 80) { sem1_grade[i] = 'A'; sem1_gp[i] = 5; }
        else if (sem1_scores[i] >= 70) { sem1_grade[i] = 'B'; sem1_gp[i] = 4; }
        else if (sem1_scores[i] >= 60) { sem1_grade[i] = 'C'; sem1_gp[i] = 3; }
        else if (sem1_scores[i] >= 50) { sem1_grade[i] = 'D'; sem1_gp[i] = 2; }
        else                           { sem1_grade[i] = 'F'; sem1_gp[i] = 0; }
    }
    for (i = 0; i < 8; i++) {
        if      (sem2_scores[i] >= 80) { sem2_grade[i] = 'A'; sem2_gp[i] = 5; }
        else if (sem2_scores[i] >= 70) { sem2_grade[i] = 'B'; sem2_gp[i] = 4; }
        else if (sem2_scores[i] >= 60) { sem2_grade[i] = 'C'; sem2_gp[i] = 3; }
        else if (sem2_scores[i] >= 50) { sem2_grade[i] = 'D'; sem2_gp[i] = 2; }
        else                           { sem2_grade[i] = 'F'; sem2_gp[i] = 0; }
    }

    /* Compute Semester I GPA */
    for (i = 0; i < 8; i++) {
        sem1_weighted[i]    = (double)(sem1_credits[i] * sem1_gp[i]);
        sem1_weighted_sum  += sem1_weighted[i];
        sem1_total_credits += sem1_credits[i];
    }
    sem1_gpa = sem1_weighted_sum / sem1_total_credits;

    /* Compute Semester II GPA */
    for (i = 0; i < 8; i++) {
        sem2_weighted[i]    = (double)(sem2_credits[i] * sem2_gp[i]);
        sem2_weighted_sum  += sem2_weighted[i];
        sem2_total_credits += sem2_credits[i];
    }
    sem2_gpa = sem2_weighted_sum / sem2_total_credits;

    /* Compute CGPA */
    cgpa = (sem1_weighted_sum + sem2_weighted_sum) /
           (sem1_total_credits + sem2_total_credits);

    /* Determine classification */
    if      (cgpa >= 4.40) classification = "First Class";
    else if (cgpa >= 3.60) classification = "Second Class Upper";
    else if (cgpa >= 2.80) classification = "Second Class Lower";
    else if (cgpa >= 2.00) classification = "Pass";
    else                   classification = "Fail";

    /* Display full academic report */
    printf("\n\n========================================\n");
    printf("      ACADEMIC REPORT - YEAR ONE        \n");
    printf("========================================\n\n");

    printf("--- SEMESTER I ---\n");
    printf("%-12s %-42s %6s %6s %6s %10s\n",
           "Code","Course Name","Score","Grade","GP","CU x GP");
    printf("%-12s %-42s %6s %6s %6s %10s\n",
           "------------","------------------------------------------",
           "------","-----","----","----------");
    for (i = 0; i < 8; i++) {
        printf("%-12s %-42s %6d %6c %6d %10.2f\n",
               sem1_codes[i], sem1_names[i],
               sem1_scores[i], sem1_grade[i], sem1_gp[i], sem1_weighted[i]);
    }

    printf("\n--- SEMESTER II ---\n");
    printf("%-12s %-42s %6s %6s %6s %10s\n",
           "Code","Course Name","Score","Grade","GP","CU x GP");
    printf("%-12s %-42s %6s %6s %6s %10s\n",
           "------------","------------------------------------------",
           "------","-----","----","----------");
    for (i = 0; i < 8; i++) {
        printf("%-12s %-42s %6d %6c %6d %10.2f\n",
               sem2_codes[i], sem2_names[i],
               sem2_scores[i], sem2_grade[i], sem2_gp[i], sem2_weighted[i]);
    }

    printf("\n========================================\n");
    printf("             FINAL SUMMARY              \n");
    printf("========================================\n");
    printf("Semester I GPA: %.2f\n", sem1_gpa);
    printf("Semester II GPA: %.2f\n", sem2_gpa);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
    printf("========================================\n");

    return 0;
}
