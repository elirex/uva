/*
 * UVa 484 The Department of Redundancy Department
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-10-29
 */
#include <cstdio>
#include <list>
#include <map>
using namespace std;

int n;
list<int> sequence;
map<int, int> counting;

int main(int argc, const char *argv[]) {
	
	while(scanf("%d", &n) == 1) {
		if(counting[n] == 0) sequence.push_back(n);
		counting[n]++;
	}

	while(!sequence.empty()) {
		printf("%d %d\n", sequence.front(), counting[sequence.front()]);
		sequence.pop_front();
	}

	return 0;
}
