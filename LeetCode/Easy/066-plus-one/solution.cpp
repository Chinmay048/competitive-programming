#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(i==digits.size()-1)
                digits[i]++;
            if(digits[i]==10){
                digits[i]=0;
                if(i!=0)
                    digits[i-1]++;
                else{
                    digits.push_back(0);
                    digits[i]=1;
                }
            }
        }
        return digits;
    }
};
int main(){
    Solution object;

    //case1:
    vector<int> digits1={1,2,3};
    vector<int> output1=object.plusOne(digits1);
    for(int i=0;i<output1.size();i++)
        cout<<output1[i]<<" ";

    cout<<endl;
    //case2:
    vector<int> digits2={4,3,2,1};
    vector<int> output2=object.plusOne(digits2);
    for(int i=0;i<output2.size();i++)
        cout<<output2[i]<<" ";
    cout<<endl;

    //case 3:
    vector<int> digits3={9};
    vector<int> output3=object.plusOne(digits3);
    for(int i=0;i<output3.size();i++)
        cout<<output3[i]<<" ";
    cout<<endl;
    return 0;
}