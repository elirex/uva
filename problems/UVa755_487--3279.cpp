/*
 * UVa 755 487--3279
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-10-27
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
using namespace std;

void quickSort(int array[], int left, int right) {
	if(left < right) {
		int change = left;
		for(int i = left + 1; i < right; ++i) {
			if(array[i] < array[left]) {
				change++;
				swap(array[i], array[change]);
			}
		}
		swap(array[left], array[change]);
		quickSort(array, left, change);
		quickSort(array, change + 1, right);
	}
}

int hashTable[10000001] = {0};

int main(int argc, const char *argv[]) {
	int datasets;
	int blank;
	while(cin >> datasets) {
		blank = 0;
		int numbers;
		while(datasets--) {
			cin >> numbers;
			getchar();
			memset(hashTable, 0, sizeof(hashTable));
			int output[100001] = {0};
			int saved = 0;
			for(int i = 0; i < numbers; ++i) {
				string phone;
				getline(cin, phone);

				int length = phone.length();
				int tempnum = 0;
				for(int j = 0; j < length; ++j) {
					if(isalnum(phone[j])) {
						tempnum *= 10;
						if(isdigit(phone[j])) {
							tempnum += phone[j] - '0';
						} else {
							switch(phone[j]) {
								case 'A':
								case 'B':
								case 'C':
									tempnum += 2;
									break;
								case 'D':
								case 'E':
								case 'F':
									tempnum += 3;
									break;
								case 'G':
								case 'H':
								case 'I':
									tempnum += 4;
									break;
								case 'J':
								case 'K':
								case 'L':
									tempnum += 5;
									break;
								case 'M':
								case 'N':
								case 'O':
									tempnum += 6;
									break;
								case 'P':
								case 'R':
								case 'S':
									tempnum += 7;
									break;
								case 'T':
								case 'U':
								case 'V':
									tempnum += 8;
									break;
								case 'W':
								case 'X':
								case 'Y':
									tempnum += 9;
									break;
							}
						}
					}
				}
				hashTable[tempnum]++;
				if(hashTable[tempnum] == 2) {
					output[saved++] = tempnum;
				}
			}

			// for(int i = 0; i < 10000001; ++i) {
			// 	if(hashTable[i] != 0) {
			// 		cout << i << " " << hashTable[i] << endl;
			// 	}
			// }
			quickSort(output, 0, saved);
			if(blank) {
				cout << endl;
			}
			blank = 1;

			for(int i = 0; i < saved; ++i) {
				printf("%03d-%04d %d\n", output[i]/10000, output[i]%10000,
						hashTable[output[i]]);
			}
			if(saved == 0) {
				cout << "No duplicates." << endl;
			}
		}
	}
	return 0;
}
