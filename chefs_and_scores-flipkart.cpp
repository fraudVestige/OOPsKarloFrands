#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int diff = 0;
    vector<int> arr;
    map<int,int> map;
    for(int i=0 ; i<n ; i++){
        int item;
        cin>> item;
        arr.push_back(item);
    }

    sort(arr.begin(), arr.end());
    if(arr[0] < 0 && arr[arr.size()-1] > 0){
        int negativeSum = 0;
        int positiveSum = 0;
        for(int i=0 ; i<arr.size() ; i++){
            map[arr[i]]++;
            if(arr[i] < 0) negativeSum += arr[i];
            if(arr[i] >= 0) positiveSum += arr[i];
        }
        diff = positiveSum - negativeSum;
    } else{
        int sum = 0;
        for(int i=0 ; i<arr.size() ; i++){
            map[arr[i]]++;
            sum += arr[i];
        }
        diff = sum;
    }

    for(auto iter : map){
        if(iter.second > 1) diff -= (iter.first*2);
    }
    cout<<diff;
    return 0;
}