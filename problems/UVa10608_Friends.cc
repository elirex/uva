/*
 * UVa 10608 Friends
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2016-01-06
 */
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_CITIZEN = 30001;
int group[MAX_CITIZEN], count[MAX_CITIZEN];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        group[i] = i;
        count[i] = 1;
    }
}

int findRootFriend(int x) {
    if(group[x] == x) return x;

    return group[x] = findRootFriend(group[x]);
}

void unionGroup(int a, int b) {
    int rootFriendOfA = findRootFriend(a);
    int rootFriendOfB = findRootFriend(b);
    if(rootFriendOfA != rootFriendOfB) {
        group[rootFriendOfA] = rootFriendOfB;
        count[rootFriendOfB] += count[rootFriendOfA]; 
    }
}

int main(int argc, const char *argv[]) {
   
    int cases, citizens, m, maxGroup;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &citizens, &m);
        init(citizens);

        int a, b;
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            unionGroup(a, b);
        }
        maxGroup = 0;
        for(int i = 1; i <= citizens; ++i) {
            maxGroup = max(maxGroup, count[i]);
        }
        printf("%d\n", maxGroup);
    }
    return 0;
}
