/*
 * UVa 11462 Age Sort
 * Author: Elirex (Wang Sheng-Yuan)
 * Version: 2.0
 * Date: 2015-11-02
 */
#include <cstdio>
using namespace std;

#define SIZE 2000001
int array[SIZE];

int main(int argc, const char *argv[]) {
	
	unsigned int n, x;
	while(scanf("%u", &n) && n) {
		for(unsigned int i = 0; i <=n; ++i) {
			array[i] = 0;
		}
		for(unsigned int i = 0; i < n; ++i) {
			scanf("%u", &x);
			array[x]++;
		}
		int first = 1;
		for(unsigned int i = 1; i <=n; ++i) {
			if(array[i] != 0 && i != n) {
				while(array[i]--) {
					if(first) {
						printf("%u", i);
						first = 0;
					} else {
						printf(" %u", i);
					}
				}
			} else if(array[i] != 0 && i == n) {
				while(array[i]) {
					if(first) {
						printf("%u%s", i, array[i] == 1 ? "\n" : " ");
					} else {
						printf(" %u%s", i, array[i] == 1 ? "\n" : " ");
					}
					array[i]--;
				}
			} else if(i == n){
				printf("\n");	
			}
		}

	}

	return 0;
}
