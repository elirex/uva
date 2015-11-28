/*
 * UVa 496 Simple Subsets 
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-28
 */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[]) {
    stringstream ss (stringstream::in | stringstream::out);
    string str;
    int element;
    while(getline(cin, str)) {
        set<int> set1, set2, inter;
        ss.clear();
        ss << str;
        while(ss >> element) {
            set1.insert(element);
        }
        getline(cin, str);
        ss.clear();
        ss << str;
        while(ss >> element) {
            set2.insert(element);
        }

        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                insert_iterator< set<int>  >(inter, inter.begin()));
        if(set1 == set2) {
            printf("A equals B\n"); 
        } else if(set1 == inter) {
            printf("A is a proper subset of B\n");
        } else if(set2 == inter) {
            printf("B is a proper subset of A\n");
        } else if(inter.size() == 0) {
            printf("A and B are disjoint\n");
        } else {
            printf("I'm confused!\n");
        }
    }

    return 0;
}
