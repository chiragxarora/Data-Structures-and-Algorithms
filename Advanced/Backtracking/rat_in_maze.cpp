#include <iostream>
#include <vector>
#include <string>

using namespace std;

// given a 2d maze with some blocked cells, find all ways a rat can reach (n,n) starting from (0,0)
// moves allowed : "right", "left", "up" and "down"

void ratEscape(int cr, int cc, vector<vector<int>> maze, vector<vector<bool>> visited, string ans) {
    if(cr==maze.size()-1 && cc==maze[0].size()-1) {
        cout<<ans<<endl;
        return;
    }
    if(cr==maze.size() || cc==maze[0].size() || cr<0 || cc<0 || maze[cr][cc]==1 || visited[cr][cc]) {
        return;  // checking visited condition is not necessary in this case | would be required if we have calls for all 4 directions
    }
    visited[cr][cc] = true;
    ratEscape(cr,cc+1,maze,visited,ans+"R");  // move to the RIGHT
    ratEscape(cr+1,cc,maze,visited,ans+"D");  // move DOWN
    ratEscape(cr-1,cc,maze,visited,ans+"U");  // move UP
    ratEscape(cr,cc-1,maze,visited,ans+"L");  // move to the LEFT
    // backtracking
    visited[cr][cc] = false;
}

int main() {
    vector<vector<bool>> visited {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    vector<vector<int>> maze {
        {0,0,0,0},
        {0,1,0,1},
        {0,0,0,0},
        {0,0,1,0}
    };
    ratEscape(0,0,maze,visited,"");
    return 0;
}