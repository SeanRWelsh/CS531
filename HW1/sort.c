#include <string.h>
void ascendingSort(char choice){
	//qsort();
}

void qsort(char *v[], int left, int right, char direction){
	int i, last;
	void swap(char *v[], int i, int j);

	if(left >= right) /* do nothing if array contains*/
		return;   /* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(direction == 'a'){
			if(strcmp(v[i], v[left]) <0)
				swap(v, ++last, i);
		}else{
			if(strcmp(v[i], v[left]) >0)
				swap(v, ++last, i);
		}


	swap(v, left, last);
	qsort(v, left, last-1, direction);
	qsort(v, last+1, right, direction);
}

void swap(char *v[], int i, int j){
	char *temp;
	temp = v[i];
	v[i]= v[j];
	v[j] = temp;
}
