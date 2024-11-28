#include <iostream>


using std::cin, std::cout, std::string;


template<typename T>
class ListElement {
    public:
    T item;
    ListElement<T>* next;
};


template<typename T>
class MyList {

    private:
    ListElement<T> *head = nullptr;

    public:

    void AddSorted(T val) {

        ListElement<T> *el = this->head;

        ListElement<T> *add = new ListElement<T>;
        add->item = val;
        add->next = nullptr;

        if (el == nullptr) el = add;

        while (el->item < val && el->next != nullptr) el = el->next;

        if (el->next == nullptr) {
            el->next = add;
        }

        else {
            ListElement<T> *el2 = el->next;
            el->next = add;
            add->next = el2;
        }

    }

    void Print() {
        
        ListElement<T> *e1 = this->head;

        if (e1 == nullptr) {
            cout << "no elements in list\n";
            return;
        }

        ListElement<T> *e2 = e1->next;

        while (e1 != nullptr) {
            cout << e1->item << " ";
            e1 = e2;
            e2 = e1->next;
        }

        cout << "\n";
        return;

    }

    ~MyList() {
        ListElement<T> *e1 = this->head;

        if (e1 == nullptr) {
            return;
        }

        ListElement<T> *e2 = e1->next;

        while (e1 != nullptr) {
            delete(e1);
            e1 = e2;
            e2 = e1->next;
        }
    }

};


int main(void) {

    freopen("input", "r", stdin);

    return 0;

}