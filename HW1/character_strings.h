#ifndef CHECK_STRING_H
#define CHECK_STRING_H
#define MINLEN 2    //minimum length a string can be
#define MAXLEN 26   //for max visible characters of 25. the 26th character is for the '/0/
#define MAXINPUT 10 //total number of strings the user will enter

int checkStringLen(char *p);
int checkLegalCharacters(char *p);
int checkDuplicate(char *, char **, int);

void inputString();

//assignment called for void ascendingSort but qsort was a better name for its function in this case
void qsort(char *v[], int left, int right, char direction);
#endif
