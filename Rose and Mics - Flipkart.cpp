#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    cin>> n >> m;
    vector<int> arr;
    for(int i=0 ; i<n ; i++){
        int item;
        cin>> item;
        arr.push_back(item);
    }

    sort(arr.begin(), arr.end());

    if(arr.size() == m) cout<<arr[arr.size() - 1];
    else{
        int surplus = m - n;
        while(surplus > 0){
            int item;
            item = arr[arr.size() - 1];
            arr[arr.size() - 1] = item/2;
            arr.push_back(item/2 + item%2);
            sort(arr.begin(),arr.end());
            surplus--;
        }
        cout<<surplus;
        cout<<arr[arr.size() - 1];
    }
    return 0;
}
