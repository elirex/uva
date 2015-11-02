/*
 * UVa 11462 Age Sort
 * Author: Elirex (Wang Sheng-Yuan)
 * Version: 1.0
 * Date: 2015-11-02
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 2000001

int array[SIZE];

// void quickSort(int *array, unsigned int length) {
// 	if(length < 2) return;	
// 	unsigned int mid = array[length >> 1];
// 	unsigned int left, right;
// 	for(left = 0, right = length - 1;;left++, right--) {
// 		while(array[left] < mid) {
// 			left++;
// 		}
// 		while(array[right] > mid) {
// 			right--;
// 		}
// 		if(left >= right) break;
// 		swap(array[left], array[right]);
// 	}
// 	quickSort(array, left);
// 	quickSort(array + left, length - left);
// }

int main(int argc, const char *argv[]) {

	unsigned int n;
	while(scanf("%u", &n) && n) {
		for(unsigned int i = 0; i < n; ++i) {
			scanf("%d", &array[i]);
		}
		sort(array, array+n);
		// quickSort(array, n);
		for(unsigned int i = 0; i < n; ++i) {
			printf("%d%s", array[i], i == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}
