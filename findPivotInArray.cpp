#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> vec){
    int start = 0;
    int end = vec.size() - 1;
    int mid;
    while(start < end){
        mid = start + (end - start) / 2;
        if(vec[mid] < vec[0]) end = mid-1;
        else start = mid + 1; 
    }
    return start;
}

int main(){
    vector<int> vec = {3,8,10,17,1};
    int ans = findPivot(vec);
    cout<<ans;
    return 0;
}