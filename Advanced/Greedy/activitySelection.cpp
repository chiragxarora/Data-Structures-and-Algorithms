#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// A machine can only do one activity at a time, we're given a set of activities time intervals(start,end),
// find maximum number of activities that can be performed
// if two intervals are overlapping, we can only do one of those

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

int activitySelection(vector<pair<int,int>> intervals){
    sort(intervals.begin(),intervals.end(),cmp);
    int cnt=1, lastEnd = intervals[0].second;
    for(int i=1;i<intervals.size();i++){
        if(intervals[i].first>lastEnd){
            cnt++;
            lastEnd = intervals[i].second;
        }
    }
    return cnt;
}

int main() {
    vector<pair<int,int>> intervals {{2,3}, {5,6}, {5,8}, {7,10}};
    cout<<activitySelection(intervals);
    return 0;
}