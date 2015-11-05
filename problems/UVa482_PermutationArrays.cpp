/*
 * UVa 482 Permutation Arrays
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-05
 */
#include <iostream>
#include <string>
using namespace std;

#define SIZE 600001

string strlist[SIZE];
int order[SIZE];

int main(int argc, const char *argv[]) {

	int cases = 0;
	int x;
	int index;
	cin >> cases;
	while(cases--) {
		cin.get();
		cin.get();
		index = 0;
		while(cin >> x) {
			order[x -1] = index;
			index++;
			if(cin.get() == '\n' ) break;
		}
		for(int i = 0; i < index; ++i) {
			cin >> strlist[i];
		}
		
		for(int i = 0; i < index; ++i) {
			cout << strlist[order[i]] << endl;
			strlist[order[i]] = "";
			order[i] = 0;
		}
		if(cases != 0) cout << endl;

	}

	return 0;
}
