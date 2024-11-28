#include <iostream>


using namespace std;


template<typename T>
class QueueItem {

    public:

    T val;
    QueueItem<T>* prev;
    QueueItem<T>* next;

    QueueItem(T val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }

};