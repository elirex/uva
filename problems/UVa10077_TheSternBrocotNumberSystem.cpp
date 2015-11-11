#include <iostream>
#include <cstdio>
using namespace std;

struct Fraction {
	int m;
	int n;
};

bool lr(Fraction a, Fraction b) {
	return (a.m * b.n) < (b.m * a.n);
}

bool equals(Fraction a, Fraction b) {
	return (a.m == b.m) && (a.n == b.n);
}

int main(int argc, const char *argv[]) {

	Fraction target, now;
	Fraction left, right;
	string path;

	while(scanf("%d %d", &target.m, &target.n) != EOF 
			&& !(target.m == 1 && target.n == 1)) {
		path = "";
		left.m = 0;
		left.n = 1;
		right.m = 1;
		right.n = 0;
		
		now.m = 1;
		now.n = 1;

		do {
			if(lr(target, now)) {
				right = now;
				now.m += left.m;
				now.n += left.n;
				path += "L";
			} else {
				left = now;
				now.m += right.m;
				now.n += right.n;
				path += "R";
			}	
		} while(!equals(target, now));
		printf("%s\n", path.c_str());
	}
	return 0;

}
