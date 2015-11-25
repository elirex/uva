/*
 * UVa 11875 - Brick Game
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-25
 */
#include <cstdio>
using namespace std;

#define SIZE 12

int main(int argc, const char *argv[]) {

    int cases = 0;
    int length, n;
    scanf("%d\n", &cases);
    for(int t = 1; t <= cases; ++t) {
        int team[SIZE];
        scanf("%d", &length);
        for(int i = 0; i < length; ++i) {
            scanf("%d", &n);
            for(int k = 0; k <= i; k++) {
                if(n < team[i]) {
                    for(int j = length; j >= i; j--) {
                        team[j] = team[j-1];
                    }
                    break;
                }
            }
            team[i] = n;
        }

        printf("Case %d: %d\n", t, team[length /2]);
       
    }
    return 0;
}
