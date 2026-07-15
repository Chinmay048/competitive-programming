class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k); // Allocate fixed memory once
        capacity = k;
        head = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        // Use modulo math to find the wrap-around tail index!
        int tail = (head + count) % capacity;
        data[tail] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        // Move head forward circularly
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // Tail is one step behind (head + count), wrapped circularly
        int tail = (head + count - 1) % capacity;
        return data[tail];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};