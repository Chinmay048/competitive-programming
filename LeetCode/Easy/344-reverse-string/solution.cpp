#include<bits/stdc++.h>
using namespace std;
void reverseString(vector<char>& s) {
    int left=0,right=s.size()-1;
    while(left<right){
        char temp=s[left];
        s[left++]=s[right];
        s[right--]=temp;
    }
}
int main(){
    //case1
    vector<char> s1={'h','e','l','l','o'};
    reverseString(s1);
    for(int i=0;i<s1.size();i++)
      cout<<s1[i];
    cout<<endl;
    //case2
    vector<char> s2={'H','a','n','n','a','h'};
    reverseString(s2);
    for(int i=0;i<s2.size();i++)
      cout<<s2[i];
    cout<<endl;
    return 0;
}