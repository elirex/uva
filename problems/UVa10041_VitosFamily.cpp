/*
 * UVa 10041 Vito's Family
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-18
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[]) {
    int numRelatives, vito, sum;
    int streets[501];
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        sum = 0;
        scanf("%d", &numRelatives);
        for(int i = 0; i < numRelatives; ++i) {
            scanf("%d", &streets[i]);
        }
        sort(streets, streets + numRelatives);
        vito = streets[numRelatives / 2];
        for(int i = 0; i < numRelatives; ++i) {
            sum += abs(streets[i] - vito);
        }
        printf("%d\n", sum);
    }
    return 0;
}
