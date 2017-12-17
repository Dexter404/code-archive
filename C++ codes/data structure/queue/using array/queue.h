#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
//queue using dynamic array or vector
template <typename T>
class Queue {
	T *arr;
	unsigned int size;
	unsigned int capacity;
public:
	Queue() : size(0), capacity(2) {
		arr = new T[2];
	}
	Queue(unsigned int x, const T& element) : size(x), capacity(2*x) {
		arr = new T[capacity];
		for(int i=0;i<size;i++)
			arr[i] = element;
	}
	Queue(const T& original) : size(original.size), capacity(original.capacity) {
		arr = new T[capacity];
		for(int i=0;i<size;i++)
			arr[i] = original.arr[i];
	}
	~Queue() {
		delete [] arr;
	}
	
	unsigned getSize() const { return size; }
	
	T& front() { 
		if(size == 0)
			throw "Queue is empty!";
		return arr[0];
	}
	const T& front() const { 
		if(size == 0)
			throw "Queue is empty!";
		return arr[0];
	}
	
	T& back() {
		if(size == 0)
			throw "Queue is empty!";
		return arr[size-1];
	}
	const T& back() const { 
		if(size == 0)
			throw "Queue is empty!";
		return arr[size-1];
	}
		
	Queue& operator=(Queue &Q) {
		delete [] arr;
		size = Q.size;
		capacity = Q.capacity;
		arr = new T[capacity];
		for(int i=0;i<size;i++)
			arr[i] = Q.arr[i];
		
		return Q;
	}
	
	void enqueue(T element) {
		if(size==capacity) {
			capacity *= 2;
			T *temp = new T[capacity];
			for(int i=0;i<size;i++)
				temp[i] = arr[i];
			delete [] arr;
			arr = temp;
		}
		arr[size++] = element;
	}
	
	T dequeue() {
		if(size == 0) 
			throw "Underflow!!";

		T del = arr[0];
		for(int i=1;i<size;i++)
			arr[i-1] = arr[i];
		
		size--;		
		if(size==capacity/4) {
			capacity /= 4;
			T *temp = new T[capacity];
			for(int i=0;i<size;i++)
				temp[i] = arr[i];
			delete [] arr;
			arr = temp;
		}

		return del;
	}
	
	bool isEmpty() { return (size==0); }
	
	void empty() {
		delete [] arr;
		size = 0;
		capacity = 2;
		arr = new T[2];
	}

	template <typename P>
	friend ostream& operator<<(ostream& , const Queue<P>& );
};
template <typename P>
ostream& operator<<(ostream& out,const Queue<P>& Q) {
	if(Q.size==0)
		out << "\nQueue is empty!";
	else {
		for(int i=0; i<Q.getSize(); i++)
			out << Q.arr[i] << " ";
		out << endl;
	}
	return out;
}
#endif
