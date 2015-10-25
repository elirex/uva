/*
 * UVa 10810 Ultra-QuickSort
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-10-25
 */
#include <cstdio>
using namespace std;

#define MAX_SIZE 500001

long long int swapCount = 0;
int buffer[MAX_SIZE];


void merge(int array[], int left, int mid, int right) {
	int l = left, r = mid+1, bufCount = 0;
	while(l <= mid && r <= right) {
		if(array[l] > array[r]) {
			buffer[bufCount++] = array[r++];
			swapCount += (mid - l +1);
		} else {
			buffer[bufCount++] = array[l++];
		}
	}
	while(l <= mid) {
		buffer[bufCount++] = array[l++];
	}
	while(r <= right) {
		buffer[bufCount++] = array[r++];
	}
	for(bufCount = 0; left <= right; left++) {
		array[left] = buffer[bufCount++];
	}
}

void mergeSort(int array[], int left, int right) {
	if(left == right) return;
	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid+1, right);
	merge(array, left, mid, right);

}

int main(int argc, const char *argv[]) {
	
	int n;
	int array[MAX_SIZE] = {0};	
	while(scanf("%d", &n)) {
		if(n == 0) break;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &array[i]);
		}
		mergeSort(array, 0, n-1);
		printf("%lld\n", swapCount);
		swapCount = 0;
	}
	return 0;
}
