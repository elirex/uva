/*
 * UVa 11716 Digital Fortress
 * Author: Elirex (Sheng-Yuan Wang)
 * Date: 2015-80-31
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, const char *argv[]) {
	int cases;
	int length;
	int sq;
	string str;
	cin >> cases;
	cin.ignore();
	while(cases--) {
		getline(cin, str);
		length = str.length();
		sq = sqrt(length);
		if(length != (sq * sq)) {
			cout << "INVALID" << endl;
			str = "";
			continue;
		}
		
		for(int i = 0; i < length; ++i) {
			for(int j = i; j < length; j += sq) {
				cout << str[j];
			}
			if(i == sq - 1) {
				break;
			}
		}
		cout << endl;
		str = "";
	}
	return 0;
}
