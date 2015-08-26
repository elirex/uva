#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, const char *argv[]) {
	int cases = 0, num = 0;
	double avg = 0, input = 0;
	vector<double> score;
	cin >> cases;
	for(int i = 0; i < cases; ++i) {
		cin >> num;
		while(num--) {
			cin >> input;
			avg += input;
			score.push_back(input);
		}
		avg /= score.size();
		int count = 0;
		for(vector<double>::iterator iter = score.begin(); 
				iter != score.end(); ++iter) {
			if(*iter > avg) {
				count++;
			}	
		}
		cout << fixed << setprecision(3) 
			<< (count / (double)score.size()) * 100 << "%" << endl;
		avg = 0;
		score.clear();
		
	}
	return 0;
}
