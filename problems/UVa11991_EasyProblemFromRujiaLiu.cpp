#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

	vector<int> arr[1000001];
int main(int argc, const char *argv[]) {
	int n, m, k, v;
	int input;
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 1; i <=n; ++i) {
			cin >> input;
			arr[input].push_back(i);
		}
		
		while(m--) {
			scanf("%d%d", &k, &v);
			if(k > arr[v].size()) {
				cout << "0" << endl;
			} else {
				cout << arr[v][k-1] << endl;
			}
		}

		for(int i = 1 ; i <= 1000000; ++i) {
			arr[i].clear();
		}
	}
	return 0;
}
