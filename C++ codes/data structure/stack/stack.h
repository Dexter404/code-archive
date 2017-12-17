#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
//stack using dynamic array or vector
template <typename T>
class Stack {
	T* arr;
	unsigned int size;
	unsigned int capacity;
public:
	Stack() : size(0), capacity(2) {
		arr = new T[2];
	}
	Stack(unsigned int x, const T &element) : size(x), capacity(2*x) {
		arr = new T[capacity];
		for(int i=0; i<x; i++)
			arr[i] = element;
	}
	Stack(Stack & original) : size(original.size), capacity(original.capacity) {
		arr = new T[capacity];
		for(int i=0;i<size;i++)
			arr[i] = original[i];
	}
	~Stack() {
		delete [] arr;
	}
	
	Stack & operator=(Stack & S) {
		delete [] arr;
		size = S.size;
		capacity = S.capacity;
		arr = new T[capacity];
		for(int i=0;i<size;i++)
			arr[i] = S.arr[i];
		return S;
	}
	
	unsigned getSize() const { return size; }
	
	T& top() { 
		if(size == 0)
			throw "Stack is empty!";
		return arr[size-1];
	}
	const T& top() const { 
		if(size == 0)
			throw "Stack is empty!";
		return arr[size-1];
	}
	
	void push(T element) {
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
	T pop() {
		if(size == 0)
			throw "\nUnderflow!!";
		
		T del = arr[--size];
		if(size == capacity/4) {
			capacity /= 4;
			T *temp = new T[capacity];
			for(int i=0;i<size;i++)
				temp[i] = arr[i];
			delete [] arr;
			arr = temp;
		}
		return del;
	}
	
	void empty() {
		delete [] arr;
		size = 0;
		capacity = 2;
		arr = new T[2];
	}
	
	template <typename P>
	friend ostream& operator<<(ostream& , const Stack<P>& );
};
template <typename P>
ostream& operator<<(ostream& out, const Stack<P>& S) {
	if(S.size==0)
		out << "Stack is empty!";
	else {
		out << S.arr[S.size-1] << "<-\n";
		for(int i=S.getSize()-2; i>=0; i--)
			out << S.arr[i] << endl;
	}
	return out;
}
#endif
