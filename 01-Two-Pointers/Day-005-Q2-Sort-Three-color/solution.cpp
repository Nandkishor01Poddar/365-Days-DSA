#include <iostream>
using namespace std;

void input(vector<int> &nums){
    cout<<"Enter array elements: ";
    for(int i=0; i<nums.size(); i++){
        cin>>nums[i];
    }
}

void sortThreeColor(vector<int> &nums){
    int i,j,k;
    i = j = 0, k = nums.size()-1;
    while(j <= k){
        if(nums[j] == 0){
            swap(nums[i], nums[j]);
            j++, i++;
        }
        else if(nums[j] == 1) j++;
        else{
            swap(nums[j], nums[k]);
            k--;
        }
    }
    cout<<"After use of Sort three color function: ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter number of size in array: ";
    cin>>n;

    vector<int> nums(n);
    input(nums);

    cout<<"Before use of Sort three color function: ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    sortThreeColor(nums);

    return 0;
}