#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    if(v.size() == 0) cout<<"[]"<<endl;
    else{
        for(int i=0 ; i<v.size() ; i++){
            cout<<"["<<v[i]<<"]"<<" ";
        }
    }
    cout<<endl;
    return;
}

void printAllSubSequences(int ind, int arr[], vector<int> &vec, int n){
    if(ind>=n){
        printVector(vec);
        return;
    }
    vec.push_back(arr[ind]);
    printAllSubSequences(ind+1, arr, vec, n);
    vec.pop_back();
    printAllSubSequences(ind+1, arr, vec, n);

}

void printSubArrays(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    if(ind == n){
        if(sum == s){
            printVector(ds);
        }
        return;
    }

    s += arr[ind];
    ds.push_back(arr[ind]);
    printSubArrays(ind+1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();
    printSubArrays(ind+1, ds, s, sum, arr, n);
}

int printNumberOfSubArrays(int ind, int s, int sum, int arr[], int n){
    if(ind == n){
        if(sum == s){
            return 1;
        }
        return 0;
    }

    s += arr[ind];
    int l = printNumberOfSubArrays(ind+1, s, sum, arr, n);

    s -= arr[ind];
    int r = printNumberOfSubArrays(ind+1, s, sum, arr, n);

    return l+r;
}

bool printOneSubArray(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    if(ind == n){
        if(s == sum){
            printVector(ds);
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printOneSubArray(ind+1, ds, s, sum, arr, n) == true) return true;

    ds.pop_back();
    s -= arr[ind];
    if(printOneSubArray(ind+1, ds, s, sum, arr, n) == true) return true;

    return false;
}

int main(){
    int arr[] = {1,1,2};
    vector<int> vec;
    int n=3;
    // printAllSubSequences(0, arr, vec, n);

    //printSubArrays(0, vec, 0, 2, arr, n);

    //printOneSubArray(0, vec, 0, 2, arr, n);

    //cout<<"Number of subarrays = "<<printNumberOfSubArrays(0, 0, 2, arr, n)<<endl;

    return 0;
}