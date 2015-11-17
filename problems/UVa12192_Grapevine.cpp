/*
 * UVa 12192 Grapevine
 * Author: Elirex (Wang Sheng-Yuan)
 * Date: 2015-11-17
 */
#include <cstdio>
using namespace std;

#define SIZE 501

int H[SIZE][SIZE];

int findTopLeftWithBinarySearch(int key, int row, int length) {
    int left = 0, right = length - 1, mid;
    while(left != right) {
	    mid = ((unsigned int) left + (unsigned int) right) >> 1;
        if(H[row][mid] >= key) 
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int findBottomRightWithBinarySearch(int key, int l_row, int l_col, 
        int rl, int cl) {
    int r_row = l_row + (rl - 1 - l_col);
    if(r_row >= cl) r_row = cl - 1;
    int r_col = l_col + (r_row - l_row);
    int mid_row, mid_col;
    
    while(l_row != r_row) {
        mid_row = ((unsigned int) l_row + (unsigned int) (r_row +1)) >> 1;
        mid_col = ((unsigned int) l_col + (unsigned int) (r_col+1)) >> 1;
        if(H[mid_col][mid_row] <= key) {
            l_row = mid_row;
            l_col = mid_col;
        } else {
            r_row = mid_row - 1;
            r_col = mid_col - 1;
        }
    }
    return l_row;
}

int main(int argc, const char *argv[]) {
    int rows, cols, query;
    int L, U;
    int largestSide;
    int topLeft, bottomRight;
	while(scanf("%d %d", &rows, &cols) != EOF 
            && !(rows == 0 && cols == 0)) {
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                scanf("%d", &H[i][j]);
            }
        }

        scanf("%d", &query);
        while(query--) {
            scanf("%d %d", &L, &U);
            largestSide = 0;
            for(int i = 0; i < rows; ++i) {
                topLeft = findTopLeftWithBinarySearch(L, i, cols);
                if(H[i][topLeft] < L) continue;
                int bottomRight = findBottomRightWithBinarySearch(U, topLeft, 
                        i, rows, cols);
                if(H[i + (bottomRight - topLeft)][bottomRight] > U) continue;
                int length = bottomRight - topLeft + 1;
                if(length > largestSide) largestSide = length;
            }
            printf("%d\n", largestSide);
        }
        printf("-\n");
    }
    return 0;
}
