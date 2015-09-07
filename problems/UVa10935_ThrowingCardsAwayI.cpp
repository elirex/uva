/*
 * UVa 10935 Throwing cards away I
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-09-07
 */
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char *argv[]) {
	int input;
	queue<int> cards;
	bool comma;
	while(cin >> input) {
		if(input == 0) {
			break;
		}
		for(int i = 1; i <= input; ++i) {
			cards.push(i);
		}
		cout << "Discarded cards:";
		comma = false;
		while(cards.size() != 1) {
			if(comma) {
				cout << ",";
			}
			comma = true;
			cout << " ";
			cout << cards.front();
			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}
		cout << endl;
		cout << "Remaining card: " <<  cards.front() << endl;
		cards.pop();
	}
	return 0;
}
