/*
 * UVa 12207 That is Your Queue
 * Author: Wang, Sheng-Yuan (Elirex)
 * Date: 2015-10-18
 */
#include <iostream>
#include <deque>
using namespace std;

deque<int> queue;
int main(int argc, const char *argv[]) {
	
	int p, c, x;
	int cases = 0;
	char command;
	while(1) {
		cin >> p >> c;
		if(p == 0 && c == 0) {
			break;
		}
		cases++;
		cout << "Case " << cases << ":" << endl;
		while(!queue.empty()) queue.pop_front();
		for(int i = 1; i <= p && i <= 1000; ++i) {
			queue.push_back(i);
		}

		while(c--) {
			cin >> command;
			if(command == 'N') {
				cout << queue.front() << endl;
				queue.push_back(queue.front());
				queue.pop_front();
			} else if(command == 'E') {
				cin >> x;
				deque<int>::iterator it;
				for(it = queue.begin(); it != queue.end(); ++it) {
					if((*it) == x) {
						queue.erase(it);
						break;
					}
				}
				queue.push_front(x);
			}
		}
	}

	return 0;
}
