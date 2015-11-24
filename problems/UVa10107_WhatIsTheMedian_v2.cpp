/*
 * UVa 10107 - What is the Median?
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-24
 * Version: 2
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 10001

unsigned int sequence[SIZE];

int main(int argc, const char *argv[]) {
    
    unsigned int n;
    int length = 0;
    while(scanf("%d", &n) != EOF) {
        int i;
        for(i = 0; i < length; ++i) {
            if(n < sequence[i]) {
                for(int j = length; j >= i; j--) {
                    sequence[j] = sequence[j-1];
                }
                break;
            }
        }
        sequence[i] = n;
        length++;
        if(length % 2) {
            printf("%d\n", sequence[length/2]);
        } else {
            printf("%d\n", (sequence[length/2 -1] + sequence[length/2]) / 2);
        }
    }

    return 0;
}
