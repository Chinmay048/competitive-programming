class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string c:operations){
            if(c=="C"){
                if(!st.empty())
                    st.pop();
            } 
            else if(c=="D"){
                int num=st.top()*2;
                st.push(num);
            }
            else if(c=="+"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.push(num2);
                st.push(num1+num2);
            }  
            else{
                st.push(stoi(c));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};