#ifndef CHECK_STRING_H
#define CHECK_STRING_H
#define MINLEN 2
#define MAXLEN 26
#define MAXINPUT 10

int checkStringLen(char *p);
int checkLegalCharacters(char *p);
int checkDuplicate(char *, char **, int);

void inputString();

void qsort(char *v[], int left, int right, char direction);
#endif
