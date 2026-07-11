#include <iostream>
#include <vector>
using namespace std;

// T.C :- O(n).   S.C :- O(1)
void sortTwoColor(vector<int> &nums){
    int st = 0, end = nums.size()-1;
    while(st <= end){
        if(nums[st] == 0) st++;
        else{
            swap(nums[st], nums[end]);
            end--;
        }
    }
    cout<<"After use of Sort two color function: ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}

void input(vector<int> &nums){
    cout<<"Enter array elements: ";
    for(int i=0; i<nums.size(); i++){
        cin>>nums[i];
    }
}

int main(){
    int n;
    cout<<"Enter number of size in array: ";
    cin>>n;

    vector<int> nums(n);
    input(nums);

    cout<<"Before use of Sort two color function: ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    sortTwoColor(nums);

    return 0;
}