/*
 * UVa 101 The Blocks Problem
 * Author: Wang, Sheng-Yuan (Elirex)
 * Date: 2015-09-17
 */
#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;

deque<int> blocks[25];
int position[25];

void initBlocks(int numBlocks) {
	for(int i = 0; i < numBlocks; ++i) {
		blocks[i].push_back(i);
		position[i] = i;
	}
} 

bool isAtSameBlock(int a, int b) {
	return position[a] == position[b];
}

void initPosition(int x) {
	while(blocks[position[x]].back() != x) {
		position[blocks[position[x]].back()] = blocks[position[x]].back();
		blocks[blocks[position[x]].back()].push_back(
				blocks[position[x]].back());
		blocks[position[x]].pop_back();
	}
}

void move(int a, int b) {
	int top = blocks[position[a]].back();
	stack<int> tmp;
	while(top != a) {
		blocks[position[a]].pop_back();
		tmp.push(top);
		position[top] = position[b];
		top = blocks[position[a]].back();
	}
	blocks[position[a]].pop_back();
	blocks[position[b]].push_back(top);
	position[a] = position[b];

	while(!tmp.empty()) {
		blocks[position[b]].push_back(tmp.top());
		tmp.pop();
	}

}

int main(int argc, const char *argv[]) {
	int numBlocks;
	string cmd1, cmd2;
	int a, b;
	cin >> numBlocks;
	initBlocks(numBlocks);

	while(cin >> cmd1) {
		if(cmd1 == "quit") break;
		cin >> a >> cmd2 >> b;
		if(a == b)	continue;
		if(isAtSameBlock(a, b)) continue;

		if(cmd1 == "move") {
			initPosition(a);
		}
		if(cmd2 == "onto") {
			initPosition(b);
		}
		move(a, b);
	}

	for(int i = 0; i < numBlocks; ++i) {
		cout << i <<":";
		for(int j = 0; j < blocks[i].size(); ++j) {
			cout << " " << blocks[i][j];
		}
		cout << endl;
	}

	return 0;
}
