class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); 
        stack<int> st; 
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {    
                int poppedIndex = st.top();
                st.pop();
                result[poppedIndex] = i - poppedIndex; 
            }
            st.push(i);
        }  
        return result;
    }
};