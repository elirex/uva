/*
 * UVa514 Rails
 * Author: Wang, Sheng-Yuan (Elirex)
 * Date: 2015-09-21
 */
#include <iostream>
#include <stack>
using namespace std;
int train[1001];
stack<int> station;
int main(int argc, const char *argv[]) {
	int num;
	int indexIn, indexOut;
	int possible;
	
	while(cin >> num && num ) {
		while(cin >> train[1]) {
			if(train[1] == 0) {
				cout << endl;
				break;
			}
			for(int i = 2; i <= num; ++i) {
				cin >> train[i];
			}
			indexIn = 1;
			indexOut = 1;
			possible = 1;
			while(indexOut <= num) {
				if(indexIn == train[indexOut]) {
					indexIn++;
					indexOut++;
				} else if(!station.empty() 
						&& station.top() == train[indexOut]) {
					station.pop();
					indexOut++;
				} else if(indexIn <= num) {
					station.push(indexIn++);
				} else {
					possible = 0;
					break;
				}
			}

			if(possible) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
			while(!station.empty()) station.pop();
		}
	}
	return 0;
}
