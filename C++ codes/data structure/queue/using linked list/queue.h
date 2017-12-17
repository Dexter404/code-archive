#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(): next(0) {}
    Node(T ele) : data(ele), next(0) {}
};
template <typename T>
class Queue {
    Node<T>* front;
    Node<T>* rear;
    int size;
public:
    Queue(): front(0), rear(0), size(0) {}
    int getSize() const {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(const T & ele) {
        Node<T>* temp = new Node<T>(ele);
        size++;
        if (!front) {
            front = rear = temp;
            return;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue() {
        if (isEmpty())
            throw "Queue is Empty";
        
        --size;
        Node<T>* temp = front;
        front = front->next;
        if (!front) 
            front = rear = NULL;
        
        delete temp;
    }

    T& getFront() {
        if (isEmpty())
            throw "Queue is Empty";
        return front->data;
    }
    const T& getFront() const {
        if (isEmpty())
            throw "Queue is Empty";
        return front->data;
    }
    T& getRear() {
        if (isEmpty())
            throw "Queue is Empty";
        return rear->data;
    }
    const T& getRear() const {
        if (isEmpty())
            throw "Queue is Empty";
        return rear->data;
    }
    
    void empty() {
    	while(front) {
    		Node<T>* save = front;
    		front = front->next;
    		delete save;
		}
		front = rear = NULL;
		size = 0;
	}

	template<typename U>
	friend ostream & operator<<(ostream& out, const Queue<U>& q);
};
template<typename U>
ostream& operator<<(ostream& out, const Queue<U>& q) {
    if (q.isEmpty()) {
        out << "Queue is Empty";
        return out;
    }
	Node<U>* iter = q.front;
	while(iter) {
		out << iter->data << " ";
		iter = iter->next;
	}
	out << endl;
	return out;
}
#endif
