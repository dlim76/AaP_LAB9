#ifndef АИП_ЛАБЫ_ABITURIENT_H
#define АИП_ЛАБЫ_ABITURIENT_H

#define MAX_NAME_LENGTH 100
#define MAX_SPECIALITY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH]; // ФИО
    char speciality[MAX_SPECIALITY_LENGTH]; // Специальность
    int exam_score;                     // Сумма баллов
    int rank;                           // Номер в рейтинге
    int original_document;              // Признак сдачи оригинала документа (1 - сдал, 0 - не сдал)
} Abiturient;

#endif //АИП_ЛАБЫ_ABITURIENT_H
