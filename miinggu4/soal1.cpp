#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

class Antrean {
private:
    Node* head;
    Node* tail;

public:
    Antrean() : head(nullptr), tail(nullptr) {}

    ~Antrean() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertLast(const string& nama) {
        Node* baru = new Node{nama, nullptr};
        if (head == nullptr) {
            head = tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    bool deleteFirst(string& nama) {
        if (head == nullptr) return false;
        Node* temp = head;
        nama = temp->nama;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        return true;
    }

    void tampilkan() const {
        cout << "Antrean:";
        if (head == nullptr) {
            cout << " (kosong)" << endl;
            return;
        }
        cout << " ";
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->nama;
            if (cur->next != nullptr) cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    Antrean antrean;
    int pilihan;

    while (cin >> pilihan && pilihan != 3) {
        if (pilihan == 1) {
            string nama;
            cin >> nama;
            antrean.insertLast(nama);
            antrean.tampilkan();
        } else if (pilihan == 2) {
            string nama;
            if (antrean.deleteFirst(nama)) {
                cout << "Melayani: " << nama << endl;
                antrean.tampilkan();
            } else {
                cout << "Antrean kosong" << endl;
            }
        }
    }

    return 0;
}
