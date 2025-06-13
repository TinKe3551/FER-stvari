#include <iostream>


using namespace std;

template<typename T>
class Stack{
private:
// privatne članske varijable koje se ne smiju
// koristiti/mijenjati
public:
bool push(T val){
// Dodavanje na stog.Vraća true ako je
// dodavanje
// uspjelo, a false inače
}
bool pop(T& val){
// Skidanje sa stoga. Vraća true ako je
// skidanje
// uspjelo, a false inače
}
};


template<typename T>
void insert_bottom(Stack<T>* s, T newEl){

    Stack<T> tmp;
    T el;

    while(s->Pop(el)){
        tmp.Push(el);
    }

    s->Push(newEl);

    while(tmp.Pop(el)){
        s->Push(el);
    }

}


template<typename T>
Stack<T>* copy_reverse(Stack<T>& s) {

    T el;
    Stack<T> *o = new Stack<T>;

    if (s.pop(el)) {
        o = copy_reverse(s);
        o.push(el);
        return o;
    }

    else {
        o.push(el);
        return o;
    }

    return ret;

}


int main(void) {

    freopen("input", "r", stdin);

    return 0;

}
