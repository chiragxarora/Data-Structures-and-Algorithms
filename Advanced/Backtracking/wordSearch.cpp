#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Word Search : https://leetcode.com/problems/word-search/

bool helper(vector<vector<char>> &b, string &s, int i, int j, int id)
{
    if (s.length() == id)
        return true;
    if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() || b[i][j] != s[id] || b[i][j] == '\0')
    {
        return false;
    }
    bool ans = false;
    b[i][j] = '\0';
    if (helper(b, s, i + 1, j, id + 1) || helper(b, s, i, j + 1, id + 1) || helper(b, s, i - 1, j, id + 1) || helper(b, s, i, j - 1, id + 1))
    {
        return true;
    }
    b[i][j] = s[id];
    return ans;
}

int main()
{
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEEX";
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (helper(board, word, i, j, 0))
            {
                cout << true;
                return 0;
            }
        }
    }
    cout << false;
    return 0;
}