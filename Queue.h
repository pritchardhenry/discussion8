#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H

template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;

        Node(T anElement, Node* aNextPointer = nullptr){
            element = anElement;
            next = aNextPointer;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************
template<class T>
Queue<T>::Queue(){
    front = nullptr;
    back = nullptr;
    numNodes = 0;
};

//************************************************
// Destructor                                    *
//************************************************
template <class T>
Queue<T>::~Queue(){
   clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template <class T>
void Queue<T>::enqueue(T value){
    Node temp = new Node(value);
    if(!isEmpty()){
        back -> next = temp;
        back = temp;
    }
    else{
        front = temp;
        back = temp;
    }
    numNodes++;
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template <class T>
void Queue<T>::dequeue(T & num) {
    if(numNodes != 0){
        num = front;
        front = front -> next;
        numNodes--;
    }
    else
        std::cout << "No element to remove" <<std::endl;
}
//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template <class T>
bool Queue<T>::isEmpty() {
    return numNodes <= 0;
}
//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template <class T>
void Queue<T>::clear(){
    T* ptr = front;
    while(ptr -> next != nullptr){
        T* temp = ptr;
        ptr = ptr -> next;
        delete temp;
    }
}

#endif //WEEK8_QUEUE_H
