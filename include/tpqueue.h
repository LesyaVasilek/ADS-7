// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T val;
        Node* next;
    };
    Node* header;
public:
    TPQueue() : header(nullptr) {}
    T pop();
    void push(const T& res);
};
template<typename T>
void TPQueue<T>::push(const T& res) {
    if (header == NULL) {
        Node* str = new Node;
        str->val = res;
        str->next = NULL;
        header = str;
    }
    else {
        Node* c1 = header;
        Node* c2 = new Node;
        int n = 0;
        while (c1) {
            if (c1->val.prior < res.prior) {
                break;
            }
            else {
                c1 = c1->next;
                n++;
            }
        }
        if (n == 0) {
            c2->next = header;
            c2->val = res;
            header = c2;
        }
        else {
            c1 = header;
            for (int i = 1; i < n; i++) {
                c1 = c1->next;
            }
            c2->next = c1->next;
            c2->val = res;
            c1->next = c2;
        }
    }
}
template<typename T>
T TPQueue<T>::pop() {
    if (header == NULL) {
        throw std::string("!!!");
    }
    else {
        T res = header->val;
        Node* c = header->next;
        delete header;
        header = c;
        return res;
    }
}


struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
