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

    bool insertAfter(int cari, int baru) {
        Node* cur = head;
        while (cur != nullptr && cur->data != cari) {
            cur = cur->next;
        }
        if (cur == nullptr) return false; 
        Node* nodeBaru = new Node{baru, cur->next};
        cur->next = nodeBaru;
        if (cur == tail) tail = nodeBaru;
        return true;
    }

    void tampilkan() const {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data;
            if (cur->next != nullptr) cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
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

    int cari, baru;
    cin >> cari >> baru;

    list.insertAfter(cari, baru);
    list.tampilkan();

    return 0;
}
