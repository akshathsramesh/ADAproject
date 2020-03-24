/*
Let A[i…n] be an array of n distinct real numbers.
A pair (A[i],A[j]) is said to be an index-value inversion if A[i]=j and A[j]=i.
Design an algorithm for counting the number of index-value inversions.
*/

#include<stdlib.h>
#include<stdio.h>

int checkAndOutput(int arr[], int l, int m, int r)
{
	int i, j, count = 0;
	i = l;
	while(i<=m){
		if(arr[i]>=m+1 && arr[i]<=r){
			j = arr[i];
			if(arr[j] == i)
				count++;
		}
		i++;
	}
  return count;
}


int checkIndexValueInversionFunction(int arr[], int l, int r){
  int left = 0, right = 0, count = 0;
	if (l < r){
		int m = l+(r-l)/2;

		left = checkIndexValueInversionFunction(arr, l, m);
		right = checkIndexValueInversionFunction(arr, m+1, r);

		count = checkAndOutput(arr, l, m, r);
		count = count + left + right;
	}
	return count;
}

void printArray(int A[], int size){
	int i;
	printf("Entered Array:\n");
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(){
	int *arr, i, count, size, mainOption;
	while(1){
		printf("Index Value Iversion Problem\n1. Check For New Input\n2. Exit\nEnter Option\n");
		scanf("%d", &mainOption);
		switch(mainOption){
			case 1:{
				printf("Enter Size\n");
				scanf("%d", &size);
				arr = (int*)malloc(size*sizeof(int));
				printf("Enter Array\n");
				for(i = 0; i<size; i++){
					scanf("%d", (arr + i));
				}
				printArray(arr, size);
				count = checkIndexValueInversionFunction(arr, 0, size - 1);
				printf("Index-Value Inversion Count: %d\n\n", count);
				break;
			}
			case 2:{
				exit(0);
			}
			default:{
				break;
			}
		}
	}
	return 0;
}
