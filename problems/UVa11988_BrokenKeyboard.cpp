/*
 * UVa 11988 Broken Keyboard
 * Author: Elirex  (Sheng-Yuan, Wang)
 * Date: 2015-09-03
 */
#include <iostream>
#include <list>
using namespace std;

int main(int argc, const char *argv[]) {
	string str;
	int length;
	list<char> text;
	list<char>::iterator it;
	while(cin >> str) {
		length = str.length();
		text.clear();
		it = text.begin();
		for(int i = 0; i < length; ++i) {
			if(str[i] == '[') {
				it = text.begin();
			} else if(str[i] == ']') {
				it = text.end();
			} else {
				text.insert(it, str[i]);
			}
		}

		for(it = text.begin(); it != text.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
