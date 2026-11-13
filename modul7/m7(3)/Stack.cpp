#include "stack.h"

void createStack(Stack &S) {
    S.top = -1; // stack kosong
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    cout << "Stack kosong!" << endl;
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    
    infotype temp[20];
    int n = S.top + 1;
    for (int i = 0; i < n; i++) {
        temp[i] = pop(S);   
    }
    for (int i = 0; i < n; i++) {
        push(S, temp[i]);   
    }
}

void pushAscending(Stack &S, infotype x) {
    
    infotype temp[20];
    int n = 0;
    while (S.top >= 0 && S.info[S.top] > x) {
        temp[n] = pop(S);
        n++;
    }
    push(S, x);
    for (int i = n - 1; i >= 0; i--) {
        push(S, temp[i]);
    }
}

void getInputStream(Stack &S) {
    char c;
    c = cin.get();

    while (c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }

        c = cin.get();
    }
}