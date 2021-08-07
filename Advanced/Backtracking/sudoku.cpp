#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Sudoku : https://leetcode.com/problems/sudoku-solver/

bool isSafe(vector<vector<char>> &b, int cr, int cc, int val)
{
    for (int i = 0; i < 9; i++)
    {
        int cell = (int)b[cr][i] - 48;
        if (cell == val)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        int cell = (int)b[i][cc] - 48;
        if (cell == val)
            return false;
    }
    int sr = (cr / 3) * 3, sc = (cc / 3) * 3;
    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            int cell = (int)b[i][j] - 48;
            if (cell == val)
                return false;
        }
    }
    return true;
}
bool helper(vector<vector<char>> &b, vector<vector<int>> &visited, int cr, int cc, int cnt, int total)
{
    if (cnt == total)
    {
        return true;
    }
    if (cc == 9)
    {
        cr++;
        cc = 0;
    }
    if (cr == 9)
    {
        return false;
    }
    if (visited[cr][cc] == -1)
    {
        return helper(b, visited, cr, cc + 1, cnt, total);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(b, cr, cc, i))
        {

            visited[cr][cc] = 1;
            b[cr][cc] = to_string(i)[0];
            bool ans = helper(b, visited, cr, cc + 1, cnt + 1, total);
            visited[cr][cc] = 0;
            if (ans)
                return true;
            b[cr][cc] = '.';
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> visited;
    int total = 0;
    vector<vector<char>> b {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'.','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    for (int i = 0; i < 9; i++)
    {
        vector<int> v;
        for (int j = 0; j < 9; j++)
        {
            if (b[i][j] != '.')
            {
                v.push_back(-1);
            }
            else
            {
                total++;
                v.push_back(0);
            }
        }
        visited.push_back(v);
    }
    helper(b, visited, 0, 0, 0, total);
    for(auto s : b) {
        for(auto c : s){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}