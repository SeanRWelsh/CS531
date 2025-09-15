#ifndef CHECK_STRING_H
#define CHECK_STRING_H
#define MINLEN 2
#define MAXLEN 26

int checkStringLen(char *p);
int checkLegalCharacters(char *p);
int checkDuplicate(char *, char **, int);

void inputString();

void sort(char *p, char order);
void ascendingSort(char *p);
void descendingSor(char *p);
#endif
