/*
Description
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free (.) or reserved (∗), 
and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input Format
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (∗).

Output Format
Print one integer: the number of ways you can place the queens.

Constraints

Each line contains exactly 
8 characters.

There are exactly 8 lines.

Each character is either . (free square) or ∗ (reserved square).

Sample Input 1
........
........
..*.....
........
........
.....**.
...*....
........
Sample Output 1
65

Note
In this configuration, there are  65
65 ways to place the 8 queens on the chessboard without attacking each other, considering the reserved squares.
*/



#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> queensArr(8, vector<char>(8, '.'));

bool takencols[8], takendiag1[16], takendiag2[16];

int rec(int level) {
    
    //basecase
    if(level == 8)
        return 1;
    
    int ways = 0;
    //choices
    for(int col = 0; col < 8; col++) {
        if(queensArr[level][col] == '.') {
            if(!takencols[col] && !takendiag1[level - col + 8 - 1] && !takendiag2[level+col]) {
                takencols[col] = takendiag1[level - col + 8 - 1] = takendiag2[level+col] = true;
                ways += rec(level+1);
                takencols[col] = takendiag1[level - col + 8 - 1] = takendiag2[level+col] = false;
            }
        }
    }

    return ways;
}

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> queensArr[i][j];
        }
    }

    cout << rec(0) << endl;
    return 0;
}
