/*
 * UVa 271 Simply Syntax
 * Author: Wang, Sheng-Yuan (Elirex)
 * Date 2015-09-25
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<string> characters;

int main(int argc, const char *argv[]) {
	string sentences, tmp;
	bool correct = 1;
	while(getline(cin, sentences)) {
		for(int i = sentences.length() - 1; i >= 0; --i) {
			if(sentences[i] >= 'p' && sentences[i] <= 'z') {
				tmp = sentences[i];
				characters.push(tmp);
			} else if(sentences[i] == 'N') {
				if(characters.empty()) {
					correct = 0;
					break;
				}
				tmp = characters.top();
				characters.pop();
				tmp = sentences[i] + tmp;
				characters.push(tmp);
			} else if(sentences[i] == 'C' || sentences[i] == 'D' 
					|| sentences[i] == 'E' || sentences[i] == 'I') {
				if(characters.empty()) {
					correct = 0;
					break;
				}
				tmp = characters.top();
				characters.pop();
				if(characters.empty()) {
					correct = 0;
					break;
				}
				tmp = characters.top() + tmp;
				characters.pop();
				tmp = sentences[i] + tmp;
				characters.push(tmp);
			} else {
				correct = 0;
				break;
			}

		}
		if(characters.size() != 1) correct = 0;
		cout << ((correct) ? "YES" : "NO") << endl;
		while(!characters.empty()) characters.pop();
		correct = 1;
	}
	return 0;
}
