/*
 * UVa 673 Parentheses Balance
 * Author: Wang, Sheng-Yuan (Elirex)
 * Date: 2015-09-22
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> parentheses;

int main(int argc, const char *argv[]) {
	string str;
	int cases;
	int length;
	bool correct;
	while(cin >> cases) {
		cin.ignore();
		while(cases--) {
			correct = 1;
			while(!parentheses.empty()) parentheses.pop();
			getline(cin, str);
			length = str.length();
			for(int i = 0; i < length; ++i) {
				if(str[i] == '(' || str[i] == '[') {
					parentheses.push(str[i]);
				} else if(str[i] == ')') {
					if(parentheses.empty() || parentheses.top() != '(') {
						correct = 0;
						break;
					} 
					parentheses.pop();
				} else if(str[i] == ']') {
					if(parentheses.empty() || parentheses.top() != '[') {
						correct = 0;
						break;
					} 
					parentheses.pop();
				}
			}

			if(!parentheses.empty()) correct = 0;
			if(correct) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
