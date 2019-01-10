#include <stdio.h>

void swap(int *a, int *b) {

	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void insertionSort(int s[], int n) {

	int i, j;
	for (i = 0; i < n; i++) {
		j = i;
		while ((j > 0) && (s[j] < s[j-1])) {
			swap(&s[j], &s[j - 1]);
			j--;
		}
	}
	return;
}
int biSearch(int s[], int key, int left, int right) {

	if (left <= right) {
		int mid = (left + right) / 2;

		if (s[mid] == key) {
			return(mid);
		}

		if (key < s[mid]) {
			return(biSearch(s, key, left, mid - 1));
		} else {
			return(biSearch(s, key, mid + 1, right));
		}
	} 
	return(-1);
}


int main() {

	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	
	int arr2[] = {6, 7, 8, 9, 10, 11, 12, 13, 14};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	insertionSort(arr1, n1);
	insertionSort(arr2, n2);

	printf("\nElement is in list1 but not in list2 : \n");
	for (int i = 0; i < n1; i++) {
		if (biSearch(arr2, arr1[i], 0, n2 - 1) == -1) {
			printf("%d ", arr1[i]);
		}
	}
	
	return(0);
}
