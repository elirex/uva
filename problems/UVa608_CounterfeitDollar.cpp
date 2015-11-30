/*
 * UVa 608 Counterfeit Dollar
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-30
 */
#include <cstdio>
using namespace std;

struct scale {
    char left[7], right[7], judge[5];
} scales[3]; 

int main(int argc, const char *argv[]) {
    
    int cases, i, j;

    scanf("%d", &cases);
    while(cases--) {
        for(i = 0; i < 3; ++i) {
            scanf("%s%s%s", scales[i].left, scales[i].right, 
                    scales[i].judge);
        }
        for(i = 0; i < 12; ++i) {
            for(j = 0; j < 3; ++j) {
                int sum_l = 0, sum_r = 0;
                for(int k = 0; scales[j].right[k]; ++k) {
                    sum_l += (scales[j].left[k] - 'A' != i);
                    sum_r += (scales[j].right[k] - 'A' !=i);
                }
                if(sum_l == sum_r && scales[j].judge[0] == 'e') continue;
                if(sum_l > sum_r && scales[j].judge[0] == 'u') continue;
                if(sum_l < sum_r && scales[j].judge[0] == 'd') continue;
                break;
            }
            if(j == 3) break;
        }

        if(i != 12) {
            printf("%c is the counterfeit coin and it is light.\n", i + 'A');
        } else {
            for(i = 0; i < 12; ++i) {
                for(j = 0; j < 3; ++j) {
                    int sum_l = 0, sum_r = 0;
                    for(int k = 0; scales[j].right[k]; ++k) {
                        sum_l += (scales[j].left[k] - 'A' == i);
                        sum_r += (scales[j].right[k] - 'A' == i);
                    }
                    if(sum_l == sum_r && scales[j].judge[0] == 'e') continue;
                    if(sum_l > sum_r && scales[j].judge[0] == 'u') continue;
                    if(sum_l < sum_r && scales[j].judge[0] == 'd') continue;
                    break;
                }
                if(j == 3) break;
            }
            printf("%c is the counterfeit coin and it is heavy.\n", i + 'A');
        }
    }
    return 0;
}
