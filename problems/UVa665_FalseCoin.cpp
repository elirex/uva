/*
 * UVa 665 False coin
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-12-10
 */
#include <cstdio>
#include <set>
using namespace std;

void readSide(const int &numPerSide, set<int> &coins) {
    coins.clear();
    int n;
    for(int coin = 0; coin < numPerSide; ++coin) {
        scanf("%d", &n);
        coins.insert(n);
    }
}

void remove(set<int> &target, const set<int> &removed) {
    for(set<int>::const_iterator it = removed.begin(); it != removed.end();
            ++it) {
        target.erase(*it);
    }
}

set<int> coinsUnion(const set<int> &left, const set<int> &right) {
    set<int> coins;
    for(set<int>::const_iterator it = left.begin(); it != left.end(); 
            ++it) {
        if(right.find(*it) != right.end()) {
            coins.insert(*it);
        }
    }
    return coins;
}

set<int> coinsCombine(const set<int> &left, const set<int> &right) {
    set<int> coins;
    for(set<int>::const_iterator it = left.begin(); it != left.end();
            ++it) {
        coins.insert(*it);
    }
    for(set<int>::const_iterator it = right.begin(); it != right.end();
            ++it) {
        coins.insert(*it);
    }
    return coins;
}

void interpreResult(const char &cmp, const set<int> &left, 
        const set<int> &right, set<int> &lessThan, set<int> &greater) {
    if(cmp == '=') {
        remove(lessThan, left);
        remove(lessThan, right);
        remove(greater, left);
        remove(greater, right);
    } else if(cmp == '<') {
        lessThan = coinsUnion(lessThan, right);
        remove(lessThan, left);
        greater = coinsUnion(greater, left);
        remove(greater, right);
    } else {
       lessThan = coinsUnion(lessThan, left);
       remove(lessThan, right);
       greater = coinsUnion(greater, right);
       remove(greater, left);
    }
} 

int main(int argc, const char *argv[]) {
    int cases;
    scanf("%d", &cases);

    bool first = true;
    while(cases--) {
        if(!first) printf("\n");
        first = false;

        int numCoins, numWeighing;
        scanf("%d%d", &numCoins, &numWeighing);

        set<int> lessThan, combined, greater;
        for(int i = 1; i <= numCoins; ++i) {
            lessThan.insert(i);
        }
        
        greater = lessThan;
        int numPerSide, falseCoin = 0;
        char cmp;
        set<int> left, right;
        for(int i = 0; i < numWeighing; ++i)  {
            scanf("%d", &numPerSide);
            readSide(numPerSide, left);
            readSide(numPerSide, right);
            scanf(" %c ", &cmp);
            if(falseCoin == 0) {
                interpreResult(cmp, left, right, lessThan, greater);
                combined = coinsCombine(lessThan, greater);
                if(combined.size() == 1) {
                    if(lessThan.size() == 1) {
                        falseCoin = *lessThan.begin();
                    } else {
                        falseCoin = *greater.begin();
                    }
                }
            }
        }
        printf("%d\n", falseCoin);
    }
    return 0;
}
