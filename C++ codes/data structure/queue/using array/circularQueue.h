#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
//queue with fixed size array, Circular queue
template <typename T>
class CQueue {
	int size;
	T *queue;
	int Front;	//stores index of position from where next element to be deleted
	int Rear;	//stores index of position at where next element to be inserted
public:
	CQueue() : size(50), Front(-1), Rear(0) {
		queue = new int[size];
	}
	CQueue(int x) : size(x), Front(-1), Rear(0) {
		queue = new int[size];
	}
	CQueue(CQueue &q) : size(q.size), Front(q.Front), Rear(q.Rear) {
		queue = new int[size];
		for(int i=0; i<size; i++)
			queue[i] = q.queue[i];
	}
	
	void enqueue(T ele) {
		if(Front == Rear)
			throw "Overflow!";

		if(Front == -1)
			Front = 0;
		queue[Rear++] = ele;
		if(Rear == size)
			Rear = 0;
	}
	T dequeue() {
		if(Front == -1)
			throw "Underflow!";

		T temp = queue[Front++];		
		if(Front == size)
			Front = 0;
		if(Front == Rear) {
			Front = -1;
			Rear = 0;
		}			
		return temp;
	}
	
	bool isEmpty() const {
		return (Front == -1);
	}	
	bool isFull() const {	
		return (Front == Rear);	
	}
	
	T& front() {
		if(isEmpty())
			throw "Queue is empty!";
		return queue[Front];
	}
	const T& front() const {
		if(isEmpty())
			throw "Queue is empty!";
		return queue[Front];
	}
	T& rear() {
		if(isEmpty())
			throw "Queue is empty!";
		if(Rear == 0)
			return queue[size-1];
		return queue[Rear-1];
	}
	const T& rear() const {
		if(isEmpty())
			throw "Queue is empty!";
		if(Rear == 0)
			return queue[size-1];
		return queue[Rear-1];
	}

	template <typename P>
	friend ostream& operator<<(ostream& ,const CQueue<P>& );
};
template <typename P>
ostream& operator<<(ostream& out,const CQueue<P>& q) {
	if(q.isEmpty())
		out << "\nQueue is empty!";
	else {
		if(q.Front < q.Rear) {
			for(int i=q.Front; i<q.Rear; i++)
				out << q.queue[i] << " ";
			out << endl;
		}
		else if(q.Front > q.Rear || (q.Front == q.Rear && q.Front!=0)) {
			for(int i=q.Front; i<q.size; i++)
				out << q.queue[i] << " ";
			for(int i=0; i<q.Rear; i++)
				out << q.queue[i] << " ";
			out << endl;
		}
		else {
			for(int i=0; i<q.size; i++)
				out << q.queue[i] << " ";
			out << endl;			
		}
	}
	return out;
}
#endif
