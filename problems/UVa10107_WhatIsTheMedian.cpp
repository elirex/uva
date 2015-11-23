/*
 * UVa 10107 - What is the Median?
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-23
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned int> sequence;

int main(int argc, const char *argv[]) {
    
    unsigned int n;
    vector<unsigned int>::size_type length;
    while(scanf("%d", &n) != EOF) {
        sequence.push_back(n);
        sort(sequence.begin(), sequence.end());
        length = sequence.size();
        n = length / 2; 
        if(length % 2 == 0) {
            printf("%d\n", (sequence[n] + sequence[n-1]) / 2);
        } else {
            printf("%d\n", sequence[n]);
        }
    }

    return 0;
}
