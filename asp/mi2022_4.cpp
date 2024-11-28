#include <iostream>


using namespace std;


template<typename T>
class QueueItem {

    public:

    T val;
    QueueItem<T>* next;

    QueueItem(T val) {
        this->val = val;
        this->next = nullptr;
    }

    ~QueueItem() {
        cout << "queue item with value " << val << " was oofed\n";
    }

};


template<typename T>
class Queue {

    private:
    
    QueueItem<T> *head;
    QueueItem<T> *tail;

    public:

    bool enqueue(T val) {

        QueueItem<T> *add = new QueueItem<T>;

        if (this->tail == nullptr) {
            this->head = add;
            this->tail = add;
            return true;
        }

        this->tail->next = add;
        this->tail = add;

    }

    bool dequeue(T& val) {

        if (this->head == nullptr) return false;

        val = this->head->val;

        QueueItem<T> *del = this->head;
        this->head = this->head->next;
        delete(del);

    }

};


template<typename T>
void split(Queue<T>* sourceq, Queue<T>* queue1, Queue<T>* queue2) {

    T val;
    
    if (sourceq->dequeue(val)) {
        queue1->enqueue(val);
    }
    else return;

    if (sourceq->dequeue(val)) {
        queue2->enqueue(val);
    }
    else return;

    split(sourceq, queue1, queue2);

}