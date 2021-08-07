#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

// Job Sequencing Problem
// We are given n jobs with a deadline and each job gives us a profit on completion
// Only one job can be done at a time
// Each job takes unit time to complete
// Maximise the profit

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;
}

int jobSequencing(vector<int> deadline, vector<int> profit) {
    vector<pair<int,int>> jobs;
    for(int i=0;i<profit.size();i++){
        jobs.push_back(make_pair(deadline[i],profit[i]));
    }
    sort(jobs.begin(),jobs.end(),cmp);
    int slots[100];  // to assign the jobs to latest available slot
    // if a job has deadline 3, and slots for 2 and 3 are open, we assign that job to slot 3
    // that means it will be finished at 3 o clock ie latest time slot
    memset(slots,-1,sizeof(slots));
    slots[jobs[0].first] = 1;
    int jobNums = 1, currentProfit = jobs[0].second;
    for(int i=1;i<jobs.size();i++){
        if(slots[jobs[i].first]!=-1){
            for(int j=jobs[i].first-1;j>=1;j--){
                if(slots[j]==-1){
                    slots[j] = 1;
                    jobNums++;
                    currentProfit += jobs[i].second;
                    break;
                }
            }
        }
         else {
            slots[jobs[i].first] = 1;
            jobNums++;
            currentProfit += jobs[i].second;
        }
    }
    return 0;
}

int main() {
    vector<int> deadline {2, 1, 2, 1, 3};
    vector<int> profit {100, 50, 10, 20, 30};
    cout<<jobSequencing(deadline,profit);
    return 0;
}