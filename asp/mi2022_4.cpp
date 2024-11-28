// split (valjda) radi kako treba ali nešto ne valja sa klasom Queue ili QueueItem


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
        cout << this->val << '\n';
    }

    ~QueueItem() {
        cout << "queue item with value " << this->val << " was oofed\n";
    }

};


template<typename T>
class Queue {

    private:
    
    QueueItem<T>* head;
    QueueItem<T>* tail;

    public:

    bool enqueue(T val) {

        QueueItem<T> *add = new QueueItem<T>(val);

        if (this->tail == nullptr) {
            this->head = add;
            this->tail = add;
            return true;
        }

        this->tail->next = add;
        this->tail = add;

        return true;
    }

    bool dequeue(T& val) {

        if (this->head == nullptr) return false;

        val = this->head->val;
        cout << "value " << val << '\n';

        QueueItem<T> *del = this->head;
        this->head = this->head->next;
        //delete(del);

        return true;

    }

    ~Queue() {
        cout << "removing queue with address " << this << '\n';
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


int main(void) {

    freopen("input", "r", stdin);

    int n;
    cin >> n;

    Queue<int> red;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        red.enqueue(m);
    }

    Queue<int> r1, r2;

    split(&red, &r1, &r2);

}