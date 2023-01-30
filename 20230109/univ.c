#include "univ.h"
#include <stdlib.h>

/**
 * Inserisce le informazioni reletive ad un esame nella carriera dello studente
 * @param student [in/out] informazioni relative alla carriera di uno specifico studente
 * @return restituisce il numero di esami nella carriera dello studente fino a raggiungere MAX_EXAMS
 * se la soglia viene superata o se necessario gestire altri errori ritornare 0
**/
int insert_exam(Career *student, Evaluation exam) {
    if (student == NULL)
        return 0;

    if (student->num_exams < MAX_EXAMS) {
        student->exams[student->num_exams].mark = exam.mark;
        student->exams[student->num_exams].credits = exam.credits;

        student->num_exams++;
        return student->num_exams;
    }

    return 0;
}

/**
 * Calcola la media ponderata degli esami svolti da uno studente
 * @param student [in] informazioni relative alla carriera di uno specifico studente
 * @return media ponderata degli esami svolti da uno studente
 * se è necessario gestire errori, ritornare 0.0f
**/
float get_weighted_average(Career *student) {
    if (student == NULL)
        return 0.0f;

    float weighted_sum = 0.0f;
    float tot_credits = 0.0f;

    for (int i = 0; i < student->num_exams; i++)
    {
        weighted_sum += student->exams[i].mark * student->exams[i].credits;
        tot_credits += student->exams[i].credits;
    }
    
    if (tot_credits == 0.0f)
        return 0.0f;

    return weighted_sum / tot_credits;
}

/**
 * Calcola una statistica su quanti studenti superano una determinata soglia in media ponderata
 * @param students [in] informazioni relative alla carriera degli studenti dell'ateneo
 * @param num_students [in] numero di studenti presenti nell'ateneo
 * @param threshold [in] soglia rispetto alla quale si vuole ottenere l'informazione
 * @return numero di studenti con la media superiore alla soglia in input
**/
int statistics(Career *students, int num_students, float threshold) {
    int count = 0;
    for (int i = 0; i < num_students; i++) {
        print_student(&students[i], false);
        if (get_weighted_average(&students[i]) > threshold)
            count++;
    }
    
    return count;
}