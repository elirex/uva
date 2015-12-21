/*
 * UVa 12650 Dangerous Dive
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-12-21
 */
#include <cstdio>
using namespace std;

#define SIZE 10001

struct mission {
    bool volunteers[SIZE];
    int count;
};

mission people;

int main(int argc, const char *argv[]) {
   
    int numVolunteers, numReturned;
    int returned;
    while(scanf("%d %d", &numVolunteers, &numReturned) != EOF) {
        for(int i = 1 ; i <= numVolunteers; ++i) {
            people.volunteers[i] = true;
        }
        people.count = numVolunteers;

        while(numReturned--) {
            scanf("%d", &returned);
            people.volunteers[returned] = false;
            people.count--;
        }
        
        if(people.count == 0) {
            printf("*\n");
        } else {
            for(int i = 1; i <= numVolunteers; ++i) {
                if(people.volunteers[i]) {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }

    }

    return 0;
}
