/*
 * UVa 11995 I can guess the data structure!
 * Author: Elirex (Wang, Sheng-Yuan)
 * Date: 2015-09-09
 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, const char *argv[]) {
	int cases, cmd, x;
	stack<int> stack;
	queue<int> queue;
	priority_queue<int> priorityQueue;
	bool isStack, isQueue, isPriorityQueue;
	while(cin >> cases) {
		isStack = true;
		isQueue = true;
		isPriorityQueue = true;
		for(int i = 0; i < cases; ++i) {
			cin >> cmd >> x;
			if(cmd == 1) {
				stack.push(x);
				queue.push(x);
				priorityQueue.push(x);
			} else if(cmd == 2) {
				if(isStack) {
					if(!stack.empty() && stack.top() == x) {
						stack.pop();	
					} else {
						isStack = false;
					}
				} 
				if(isQueue) {
					if(!queue.empty() && queue.front() == x) {
						queue.pop();
					} else {
						isQueue = false;	
					}
				} 
				if(isPriorityQueue) {
					if(!priorityQueue.empty() && priorityQueue.top() == x) {
						priorityQueue.pop();
					} else {
						isPriorityQueue = false;	
					}	
				}
			}
		}

		if((isStack && isQueue) || (isQueue && isPriorityQueue)
				|| (isStack && isPriorityQueue)) {
			cout << "not sure" << endl;
		} else if(isStack) {
			cout << "stack" << endl;	
		} else if(isQueue) {
			cout << "queue" << endl;
		} else if(isPriorityQueue) {
			cout << "priority queue" << endl;
		} else {
			cout << "impossible" << endl;
		}

		while(!stack.empty()) stack.pop();
		while(!queue.empty()) queue.pop();
		while(!priorityQueue.empty()) priorityQueue.pop();
	}
	return 0;
}
