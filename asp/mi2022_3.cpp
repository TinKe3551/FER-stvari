#include <iostream>


using namespace std;


template<typename T>
class ListElement {

    public:
    T val;
    ListElement<T>* next;
    ListElement<T>* prev;
    ListElement(T val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
    ~ListElement() {
        cout << "list element with value " << val << " goes oof\n";
    }

};


template<typename T>
class DoubleList {

    
    private:


    

    ListElement<T>* head;
    ListElement<T>* tail;


    public:

    DoubleList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void AddFirst(T val) {

        ListElement<T> *add = new ListElement<T>(val);

        if (this->tail == nullptr) {
            this->head = add;
            this->tail = add;
            return;
        }

        add->next = head;
        this->head->prev = add;
        this->head = add;

    }

    bool Find(T val) {

        if (this->tail == nullptr) return false;

        ListElement<T> *el = this->head;

        while (el != nullptr) {
            if (el->val == val) return true;
            el = el->next;
        }

        return false;
    }

    ~DoubleList() {
        
        ListElement<T> *el = this->head;
        if (el == nullptr) return;
        
        ListElement<T> *el2 = el->next;

        while (el != nullptr) {
            delete(el);
            el = el2;
            if (el2 != nullptr) el2 = el2->next;
        }

    }


};


int main(void) {

    freopen("input", "r", stdin);

    int n;
    cin >> n;

    DoubleList<int> lista;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        lista.AddFirst(m);
    }

    for (int i = -1 * n; i <= n; i++) {
        if (lista.Find(i)) {
            cout << "element " << i << " is in list\n";
        }
    }

    return 0;
}