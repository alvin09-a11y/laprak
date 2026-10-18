    #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertLast(int nilai) {
        Node* baru = new Node{nilai, nullptr};
        if (head == nullptr) {
            head = tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    long long hitungSum() const {
        long long total = 0;
        Node* cur = head;
        while (cur != nullptr) {
            total += cur->data;
            cur = cur->next;
        }
        return total;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.insertLast(x);
    }

    cout << list.hitungSum() << endl;

    return 0;
}
