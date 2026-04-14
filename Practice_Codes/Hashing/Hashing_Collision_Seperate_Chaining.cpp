#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CollisionResolution {
private:
    vector<Node*> hashtable;
    int tablesize;
public:

    CollisionResolution(int size) {
        tablesize = size;
        hashtable.resize(tablesize, nullptr); 
    }

    void insert(int element) {
        int index = ((element % tablesize) + tablesize) % tablesize;
        Node* newNode = new Node(element);  
        newNode->next = hashtable[index]; 
        hashtable[index] = newNode;       
    }

    bool get(int element) {
        int index = ((element % tablesize) + tablesize) % tablesize;
        Node* current = hashtable[index];
        while (current != nullptr) {
            if (current->data == element)
                return true;
            current = current->next;
        }
        return false;
    }

    void del(int element) {
        int index = ((element % tablesize) + tablesize) % tablesize;
        Node* current = hashtable[index];
        Node* prev = nullptr; 
        while (current != nullptr) {
            if (current->data == element) { 
                if (prev == nullptr) 
                    hashtable[index] = current->next;
                else 
                    prev->next = current->next;       
                delete current; 
                cout << "Element " << element << " deleted\n";
                return; 
            }
            prev = current;
            current = current->next;
        }
        cout << "Element not found\n";
    }
};

// 3. Execution
int main() {
    CollisionResolution myTable(10); 
    myTable.insert(85);
    myTable.insert(50);
    myTable.insert(99);
    myTable.del(50); 
    return 0;
}