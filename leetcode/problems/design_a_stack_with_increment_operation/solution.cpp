class CustomStack {
    vector<int> stk;
    vector<int> inc;
    int n;

public:
    CustomStack(int maxSize) { n = maxSize; }

    void push(int x) {
        if (stk.size() < n) {
            stk.push_back(x);
            inc.push_back(0);
        }
    }

    int pop() {
        int i = stk.size() - 1;
        if (i < 0)
            return -1;

        if (i > 0)
            inc[i - 1] += inc[i];

        int res = stk[i] + inc[i];
        stk.pop_back();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)stk.size()) - 1;
        if (i >= 0)
            inc[i] += val;
    }
};