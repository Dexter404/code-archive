#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
template <typename T>
class Vector {
    T * arr;
    unsigned int size;
    unsigned int capacity;
    public:
    Vector() : size(0), capacity(2) {
        arr = new T[2];
    }
    Vector(unsigned int x, const T & element) : size(x), capacity(2*x) {
        arr = new T[capacity];
        for (int i = 0; i < x; i++) {
            arr[i] = element;
        }
    }
    Vector(const Vector & original) : size(original.size), capacity(original.capacity) {
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = original.arr[i];
        }
    }
    ~Vector() {
        delete [] arr;
    }
    Vector & operator=(Vector & B) {
        delete [] arr;	
        size = B.size;
        capacity = B.capacity;
        arr = new T[capacity];
        for(int i = 0 ; i < size; i++) {
            arr[i] = B.arr[i];
        }
        return B;
    }
    int getSize() const {
        return size;
    }
    void push_back(T element) {
        if (size == capacity) {
            capacity = 2*capacity;
            T * temp = new T[capacity];
            for (int i = 0 ; i < size; i++) {
                temp[i] = arr[i];
            }
            delete [] arr;
            arr = temp;
        }
        arr[size++] = element;
    }
    void pop_back() {
    	if(size == 0)
    		throw "vector is empty!";
        --size;
		if (size == capacity/4) {
            capacity = capacity/4;
            T * temp = new T[capacity];
            for (int i = 0 ; i < size; i++) {
                temp[i] = arr[i];
            }
            delete [] arr;
            arr = temp;
        }
    }

    const T & operator[](int index) const {
        return arr[index];
    }
    T & operator[](int index) {
        return arr[index];
    }
    
    Vector & operator+=(const Vector & B) {
        for(int i = 0; i < B.getSize(); i++) {
            push_back(B[i]);
        }
        return *this;   
    }

    template<typename U>
    friend ostream & operator<<(ostream &, const Vector<U>&);
};
template<typename T>
ostream & operator<<(ostream & out , const Vector<T> & V) {
	if(S.size==0)
		out << "Vector is empty!";
	else {
	    for (int i = 0 ; i < V.getSize(); i++) {
	        out << V[i] << " ";
	    }
	}
    return out;
}
#endif
