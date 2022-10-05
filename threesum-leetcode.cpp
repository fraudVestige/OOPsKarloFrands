#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ansVector;
        map<pair<int,int>,int> map;
        for(int i=0 ; i<nums.size()-2 ; i++){
            vector<int> tempVec;
            int diff = 0 - nums[i];
            //bool isFound = false;
            int j = i+1;
            int k = nums.size() - 1;
            while(j<k){
                if(true){
                    break;
                }
                if(nums[j]+nums[k] == diff){
                    tempVec.push_back(nums[i]);
                    tempVec.push_back(nums[j]);
                    tempVec.push_back(nums[k]);
                    ansVector.push_back(tempVec);
                    map[make_pair(nums[i],nums[j])]++;
                    map[make_pair(nums[j],nums[k])]++;
                    map[make_pair(nums[i],nums[k])]++;
                    tempVec.clear();
                    j++;
                }
                else if(nums[j]+nums[k] < diff) j++;
                else k--;
            }
        }
        
        for(int i=0 ; i<ansVector.size() ; i++){
            sort(ansVector[i].begin(),ansVector[i].end());
        }
        
        set<vector<int>> s(ansVector.begin(), ansVector.end());
        
        ansVector.clear();
        
        for(auto& v : s){
            ansVector.push_back(v);
        }

        cout<<ansVector.size();

        for(int i=0 ; i<ansVector.size() ; i++){
            for(int j=0 ; j<ansVector[i].size() ; j++){
                cout<<ansVector[i][j] << " ";
            }
            cout<<endl;
        }
        
        for(int i=0 ; i<ansVector.size() ; i++){
            reverse(ansVector[i].end(),ansVector[i].begin());
        }

        return ansVector;
    }

int main(){
    int n;
    cin>> n;
    vector<int> nums;
    for(int i=0 ; i<n ; i++){
        int item;
        cin>> item;
        nums.push_back(item);
    }

    threeSum(nums);
    return 0;
}
