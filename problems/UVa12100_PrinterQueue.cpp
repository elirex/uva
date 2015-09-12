/*
 * Author: Elirex (Wang, Sheng-Yuan)
 * Date: 2015-09-12
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
	int mPriority;
	bool mIsMyJob;
	Job(int priority, bool isMyJob) {
		mPriority = priority;
		mIsMyJob = isMyJob;
	}
};

int cmp(int a, int b) {
	return a > b;
}

int main(int argc, const char *argv[]) {
	int cases, jobs, jobPosition, priority;
	queue<Job> queue;
	vector<int> tmpQueue;
	cin >> cases;
	while(cases--) {
		cin >> jobs >> jobPosition;
		for(int i = 0; i < jobs; ++i) {
			cin >> priority;
			if(i == jobPosition) {
				queue.push(Job(priority, true));
			} else {
				queue.push(Job(priority, false));
			}
			tmpQueue.push_back(priority);
		}
	
		sort(tmpQueue.begin(), tmpQueue.end(), cmp);

		int minutes = 0;
		vector<int>::iterator it = tmpQueue.begin();
		while(true) {
			Job job = queue.front();
			queue.pop();
			if(job.mPriority == *it) {
				minutes++;
				it++;
				if(job.mIsMyJob) {
					break;
				}
			} else {
				queue.push(job);
			}

		}
		
		cout << minutes << endl;

		while(!queue.empty()) queue.pop();
		tmpQueue.clear();

	}

	return 0;
}
