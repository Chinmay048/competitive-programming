#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target)
                return {left+1,right+1};
            else if(numbers[left]+numbers[right]>target)
                right--;
            else
                left++;
        }
        return {0};
    }
};
int main() {
    Solution object;
    // Test case 1
    vector<int> v1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> sol1 = object.twoSum(v1, target1);
    cout << "Test 1 - Input: [2,7,11,15], Target:  9" << endl;
    cout << "Output: ";
    for(auto i : sol1)
        cout << i << " ";
    cout << endl;
    cout << "Expected: 1 2\n" << endl;
    // Test case 2
    vector<int> v2 = {2, 3, 4};
    int target2 = 6;
    vector<int> sol2 = object.twoSum(v2, target2);
    cout << "Test 2 - Input: [2,3,4], Target: 6" << endl;
    cout << "Output: ";
    for(auto i : sol2)
        cout << i << " ";
    cout << endl;
    cout << "Expected: 1 3\n" << endl;
    // Test case 3
    vector<int> v3 = {-1, 0};
    int target3 = -1;
    vector<int> sol3 = object.twoSum(v3, target3);
    cout << "Test 3 - Input: [-1,0], Target: -1" << endl;
    cout << "Output:  ";
    for(auto i :  sol3)
        cout << i << " ";
    cout << endl;
    cout << "Expected:  1 2" << endl;
    return 0;
}