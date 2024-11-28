#include <iostream>


using std::cin, std::cout, std::string;


template<typename T>
class ListElement {

    public:

    T item;
    ListElement<T>* next;

    ListElement(T val) {
        this->item = val;
        this->next = nullptr;
    }

    ~ListElement() {
        cout << "oof\n";
    }

};


template<typename T>
class MyList {

    private:
    ListElement<T> *head;

    public:

    MyList() { this->head = nullptr;}

    void AddSorted(T val) {

        ListElement<T> *el = this->head;

        ListElement<T> *add = new ListElement<T>(val);
        add->next = nullptr;

        if (el == nullptr) {
            this->head = add;
            return;
        }

        if (this->head->item > val) {
            add->next = this->head;
            this->head = add;
            return;
        }

        while (el->next != nullptr && el->next->item < val) el = el->next;

        if (el->next == nullptr) {
            el->next = add;
            return;
        }

       

        else {
            ListElement<T> *el2 = el->next;
            add->next = el2;
            el->next = add;
            return;
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
            if (e1 != nullptr) e2 = e1->next;
        }

        cout << "\n";
        return;

    }

    ~MyList() {
        ListElement<T> *e1 = this->head;

        int counter = 0;

        if (e1 == nullptr) {
            return;
        }

        ListElement<T> *e2 = e1->next;

        while (e1 != nullptr) {
            delete(e1);
            e1 = e2;
            if (e1 != nullptr) e2 = e1->next;
            counter++;
        }

        cout << "deleted list with " << counter << " items\n";
    }

};


int main(void) {

    freopen("input", "r", stdin);

    MyList<int> lista;
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        lista.AddSorted(n);
    }

    lista.Print();

    return 0;

}