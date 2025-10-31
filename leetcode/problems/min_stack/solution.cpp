class MinStack {
     private:
         stack<pair<int, int>> st; // {value, min_at_this_level}

     public:
         MinStack() {}

         void push(int val) {
             if(st.empty()) {
                 st.push({val, val});
             } else {
                 st.push({val, min(val, st.top().second)});
             }
         }

         void pop() {
             st.pop();
         }

         int top() {
             return st.top().first;
         }

         int getMin() {
             return st.top().second;
         }
     };
