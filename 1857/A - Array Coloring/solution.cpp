#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n,count=0;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        if (v[i]%2==0)
            count++;
    }
    if ((n-count)%2==0)
        cout<<"YES
";
    else
        cout<<"NO
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}