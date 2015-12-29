/*
 * UVa 11218 KTV 
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-12-29
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define SIZE 512

struct Group {
    unsigned int combin;
    int score;
};

Group g[100];
int data[SIZE];

bool disjoint(unsigned int a, unsigned int b) {
    // unsigned int c = a | b;
    // int totalA = 0, totalB = 0, totalC = 0;
    // for(int i = 0; i < 9; ++i) {
    //     if(a & (1 << i)) ++totalA;
    //     if(b & (1 << i)) ++totalB;
    //     if(c & (1 << i)) ++totalC;
    // }
    // return totalA + totalB == totalC;
    unsigned int tmp1 = a | b;
    unsigned int tmp2 = a ^ b;
    return tmp1 == tmp2;
}

void compute(unsigned int combin, int score, int n) {
    for(int i = 0; i < n; ++i) {
        if(disjoint(combin, g[i].combin)) {
            unsigned combined = combin | g[i].combin;
            if(data[combined] < score + g[i].score) {
                data[combined] = score + g[i].score;
                compute(combined, data[combined], n);
            }
        }
    }
}

int main(int argc, const char *argv[]) {
   
    int numCombin, a, b, c, s;
    int cases = 1;

    while(scanf("%d", &numCombin) && numCombin) {
        for(int i = 0; i < numCombin; ++i) {
            scanf("%d %d %d %d", &a, &b, &c, &s);
            g[i].combin = (unsigned int)0 | (1 << (a -1)) | (1 << (b-1)) 
                    | (1 << (c-1));
            g[i].score = s;
        }
        
        memset(data, 0, sizeof(data));
        for(int i = 0; i < numCombin; ++i) {
            compute(g[i].combin, g[i].score, numCombin); 
        }

        
        printf("Case %d: ", cases++);
        if(data[SIZE-1] == 0) printf("-1\n");
        else printf("%d\n", data[SIZE-1]);

    }

    return 0;
}
