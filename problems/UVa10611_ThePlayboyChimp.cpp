/*
 * UVa 10611 The Playboy Chimp
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-10
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned int> lady;
int mid;

void binarySearch(unsigned int key, int length) {
	int low = 0;
	int high = length -1;
	unsigned int midVal;
	while(low <= high) {
		mid = ((unsigned int) low + (unsigned int) high) >> 1;
		midVal = lady[mid];
		if(midVal < key) {
			low = mid + 1;
		} else if(midVal > key){
			high = mid - 1;
		} else {
			return;
		}
	}
}

int main(int argc, const char *argv[]) {

	int input;
	int length = 0;
	unsigned int q;
	vector<unsigned int>::iterator it;
	while(scanf("%d", &input) == 1) {
		for(int i = 0; i < input; ++i) {
			scanf("%d", &q);
			lady.push_back(q);
		}

		it = unique(lady.begin(), lady.end());
		lady.erase(it, lady.end());
		length = lady.size();
		scanf("%d", &input);
		for(int i = 0; i < input; ++i) {
			scanf("%d", &q);
			binarySearch(q, length);	
			if(lady[mid] == q) {
				if(mid -1 >= 0) printf("%d", lady[mid - 1]);
				else printf("X");

				if(mid + 1 < length) printf(" %d", lady[mid + 1]);
				else printf(" X");
			} else {
				if(mid + 1 != length && lady[mid] < q) printf("%d", lady[mid]);
				else if(mid-1 >= 0) printf("%d", lady[mid - 1]);	
				else printf("X");

				if(mid -1 != 0 && lady[mid] > q) printf(" %d", lady[mid]);
				else if(mid + 1 < length) printf(" %d", lady[mid + 1]);
				else printf(" X");
			}
			printf("\n");
		}

		lady.clear();
	}
	return 0;

}
