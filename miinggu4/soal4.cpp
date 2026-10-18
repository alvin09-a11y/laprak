#include <iostream>
#include <string>
using namespace std;

struct Node {
    string judul;
    int tahun;
    Node* next;
};

class DaftarBuku {
private:
    Node* head;
    Node* tail;

public:
    DaftarBuku() : head(nullptr), tail(nullptr) {}

    ~DaftarBuku() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertLast(const string& judul, int tahun) {
        Node* baru = new Node{judul, tahun, nullptr};
        if (head == nullptr) {
            head = tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }

    void deleteLast() {
        if (head == nullptr) return;      

        if (head == tail) {               
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* cur = head;
        while (cur->next != tail) {       
            cur = cur->next;
        }
        delete tail;
        tail = cur;
        tail->next = nullptr;
    }

    void tampilkan() const {
        cout << "Daftar Buku:" << endl;
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->judul << " (" << cur->tahun << ")" << endl;
            cur = cur->next;
        }
    }
};

int main() {
    DaftarBuku daftar;
    string baris;

    while (getline(cin, baris)) {
        while (!baris.empty() && (baris.back() == '\r' || baris.back() == ' ')) {
            baris.pop_back();
        }

        size_t pos = baris.find_last_of(' ');
        if (pos == string::npos) continue; 

        string judul = baris.substr(0, pos);
        int tahun = stoi(baris.substr(pos + 1));
        daftar.insertLast(judul, tahun);
    }

    daftar.deleteLast();   
    daftar.tampilkan();

    return 0;
}
