#include <iostream>
#include <string>
#include <vector>

using namespace std;

// all major queen problems

// 1.) Queen Combinations

void QueenCombinationBoxRespect1D(vector<bool> board, int col, int qpsf, int tq, string ans) {
    if(qpsf == tq) {
        cout<<ans<<endl;
        return;
    }
    if(col==board.size()) {
        return;
    }
    // each cell in the board will have 2 possibilities 
    // either a queen in the cell or an empty cell
    // place
    QueenCombinationBoxRespect1D(board,col+1,qpsf+1,tq,ans+" queen at box "+to_string(col));
    // not place
    QueenCombinationBoxRespect1D(board,col+1,qpsf,tq,ans);
}

void QueenCombinationQueenRespect1D(vector<bool> board, int col, int qpsf, int tq, string ans) {
    if(qpsf == tq) {
        cout<<ans<<endl;
        return;
    }
    if(col==board.size()) {
        return;
    }
    // each queen will have 2 possibilities : either not sit or sit (if sit, then on which cell)
    for(int i=col;i<board.size();i++){
        QueenCombinationQueenRespect1D(board,i+1,qpsf+1,tq,ans+" queen at box "+to_string(i));
    }
}

void QueenCombinationBoxRespect2D(vector<vector<bool>> board, int row, int col, int qpsf, int tq, string ans) {
    if(qpsf == tq) {
        cout<<ans<<endl;
        return;
    }
    if(row==board.size() || qpsf>tq) {
        return;
    }
    if(col==board[0].size()) {
        QueenCombinationBoxRespect2D(board,row+1,0,qpsf,tq,ans);
        return;
    }
    // place
    QueenCombinationBoxRespect2D(board,row,col+1,qpsf+1,tq,ans+" queen at cell ("+to_string(row)+","+to_string(col)+") ");
    // not place
    QueenCombinationBoxRespect2D(board,row,col+1,qpsf,tq,ans);
}

void QueenCombinationQueenRespect2D(vector<vector<bool>> board, int row, int col, int qpsf, int tq, string ans) {
    if(qpsf == tq) {
        cout<<ans<<endl;
        return;
    }

    for(int i=col+1;i<board[0].size();i++){
       QueenCombinationQueenRespect2D(board,row,i,qpsf+1,tq,ans+" queen at cell ("+to_string(row)+","+to_string(i)+") ");
    }

    for(int i=row+1;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            QueenCombinationQueenRespect2D(board,i,j,qpsf+1,tq,ans+" queen at cell ("+to_string(i)+","+to_string(j)+") ");
        }
    }
}

// 2.) Queen Permutations

void QueenPermutationsBoxRespect1D(vector<bool> queens, int col, int boardLength, int qpsf, string ans) {
    if(qpsf==queens.size()) {
        cout<<ans<<endl;
        return;
    }
    if(col==boardLength) {
        return;
    }
    // each box will have 2 options, either no queen or a queen would sit! if a queen sits, then which queen? coz they are distinct
    // place (and place which queen)
    for(int i=0;i<queens.size();i++){
        if(!queens[i]){
            queens[i] = true;
            QueenPermutationsBoxRespect1D(queens,col+1,boardLength,qpsf+1,ans+" queen "+to_string(i)+" at box "+to_string(col)+" ");
            queens[i] = false;
        }
    }
    
    // not place
    QueenPermutationsBoxRespect1D(queens,col+1,boardLength,qpsf,ans);
}

void QueenPermutationsQueenRespect1D(vector<bool> board, int qpsf, int tq, string ans) {
    if(qpsf==tq) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<board.size();i++){
        if(!board[i]){
            board[i] = true;
            QueenPermutationsQueenRespect1D(board,qpsf+1,tq,ans+" queen "+to_string(qpsf+1)+" at box "+to_string(i)+" ");
            board[i] = false;
        }
    }
    // there wont be any not place call because queen doesnt have an option to NOT SIT
}

void QueenPermutationsBoxRespect2D(vector<bool> queens, int cr, int cc, int er, int ec, int qpsf, string ans) {
    if(qpsf==queens.size()) {
        cout<<ans<<endl;
        return;
    }
    if(cr==er+1) {
        return;
    }
    if(cc==ec+1) {
        QueenPermutationsBoxRespect2D(queens,cr+1,0,er,ec,qpsf,ans);
        return;
    }

    // each box will either have a queen or not have a queen! if it has a queen then which one? coz they distinct
    // place
    for(int i=0;i<queens.size();i++) {
        if(!queens[i]) {
            queens[i] = true;
            QueenPermutationsBoxRespect2D(queens,cr,cc+1,er,ec,qpsf+1,ans+" queen "+to_string(i+1)+" at cell ("+to_string(cr)+","+to_string(cc)+") ");
            queens[i] = false;
        }
    }
    // not place
    QueenPermutationsBoxRespect2D(queens,cr,cc+1,er,ec,qpsf,ans);
}

void QueenPermutationsQueenRespect2D(vector<vector<bool>> board2D, int qpsf, int tq, string ans) {
    if(qpsf==tq) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<board2D.size();i++) {
        for(int j=0;j<board2D[0].size();j++) {
            if(!board2D[i][j]) {
                board2D[i][j] = true;
                QueenPermutationsQueenRespect2D(board2D,qpsf+1,tq,ans+" queen "+to_string(qpsf+1)+" at cell ("+to_string(i)+","+to_string(j)+") ");
                board2D[i][j] = false;
            }
        }
    }
}

// N queens problem : https://leetcode.com/problems/n-queens/

bool isSafe(vector<vector<bool>> NNboard, int cr, int cc) {
    int i=cr,j=0;
    while(i>=0){
        if(NNboard[i][cc]) {
            return false;
        }
        i--;
    }
    i=cc;
    while(i>=0){
        if(NNboard[cr][i]) {
            return false;
        }
        i--;
    }
    i=cr;
    j=cc;
    while(i>=0 && j>=0) {
        if(NNboard[i][j]) {
            return false;
        }
        i--;
        j--;
    }
    i=cr;
    j=cc;
    while(i>=0 && j<NNboard[0].size()) {
        if(NNboard[i][j]) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void nQueens(vector<vector<bool>> NNboard, int cr, int cc, int qpsf, vector<vector<string>>& ans) {
    if(qpsf==NNboard.size()) {
        vector<string> a;
        for(int i=0;i<NNboard.size();i++){
            string aa = "";
            for(int j=0;j<NNboard[0].size();j++){
                if(NNboard[i][j]) {
                    aa +="Q";
                } else {
                    aa +=".";
                }
            }
            a.push_back(aa);
        }
        ans.push_back(a);
        return;
    }
    if(cc==NNboard[0].size()) {
        cr++;
        cc=0;
    }
    if(cr==NNboard.size()) {
        return;
    }
    
    // place
    if(!NNboard[cr][cc] && isSafe(NNboard,cr,cc)) {
        NNboard[cr][cc] = true;
        nQueens(NNboard,cr+1,0,qpsf+1,ans);
        NNboard[cr][cc] = false;
    }
    // not place
    nQueens(NNboard,cr,cc+1,qpsf,ans);
}

int main() {
    vector<bool> board {0,0,0};
    vector<bool> queens {0,0};
    vector<vector<bool>> board2D {{0,0},{0,0}};

    // 1D

    //QueenCombinationBoxRespect1D(board,0,0,2,"");
    //QueenCombinationQueenRespect1D(board,0,0,2,"");
    //QueenPermutationsBoxRespect1D(queens,0,3,0,"");
    //QueenPermutationsQueenRespect1D(board,0,2,"");
    
    // 2D

    //QueenCombinationBoxRespect2D(board2D,0,0,0,2,"");
    //QueenCombinationQueenRespect2D(board2D,0,-1,0,2,"");
    //QueenPermutationsBoxRespect2D(queens,0,0,1,1,0,"");
    //QueenPermutationsQueenRespect2D(board2D,0,2,"");

    vector<vector<bool>> NNboard {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    vector<vector<string>> ans;
    nQueens(NNboard,0,0,0,ans);
    for(auto ss : ans) {
        for(auto s : ss) {
            cout<<s<<"   ";
        }
        cout<<" - ";
    }


    return 0;
}