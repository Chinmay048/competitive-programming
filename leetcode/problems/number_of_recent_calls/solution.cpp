class RecentCounter {
private:
    std::queue<int> q;

public:
    RecentCounter() {
        // Queue starts empty
    }
    
    int ping(int t) {
        // 1. Add the newest request to the back
        q.push(t);
        
        // 2. Remove all requests that fall outside the [t - 3000, t] window
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // 3. The remaining queue size is exactly the number of recent requests
        return q.size();
    }
};