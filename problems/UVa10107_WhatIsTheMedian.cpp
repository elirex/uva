/*
 * UVa 10107 What is the Median?
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-10-20
 */
#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
	int n, index;
	int array[10001];
	int size = 0;
	while(cin >> n) {
		for(index = 0; index < size; ++index) {
			if(n > array[index]) {
				for(int j = size; j >= index; --j) {
					array[j] = array[j-1];
				}
				break;
			}
		}
		array[index] = n;
		size++;

		if(size % 2) {
			cout << array[size/2] << endl;
		} else {
			cout << (array[size/2-1] + array[size/2]) / 2 << endl;
		}
	}

	return 0;
}
