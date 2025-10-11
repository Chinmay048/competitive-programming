class Solution {
public:
    
bool scoreBalance(string s) {
    vector<int> a;
    for(int j=0;j<s.length();j++)
        a.push_back((s[j])-96);
    int k=0;
    while(k<a.size()) {
        int sumr=0,suml=0;
        for (int i=0;i<=k;i++)
            suml+=a[i];
        for(int i=k+1;i<s.length();i++)
            sumr+=a[i];
        if(sumr==suml)
            return true;
        k++;
    }
    return false;
}
};