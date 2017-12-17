#include <iostream>
#include "queue.h"
using namespace std;
main() {
	Queue<int> Q;
	
	cout<<"Insertion..";
	Q.enqueue(3);
	Q.enqueue(5);
	Q.enqueue(6);
	Q.enqueue(4);
	Q.enqueue(1);
	Q.enqueue(2);
	cout<<"\nQueue: "<<Q;
	cout<<"Front:"<<Q.getFront();
	cout<<"\nBack:"<<Q.getRear();
	
	cout<<"\n\nDeletion..";
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	cout<<"\nQueue: "<<Q;
	
	Queue<int> Q2;
	Q2 = Q;
	cout<<"\nQueue Assignment..";
	cout<<"\nQueue: "<<Q2;
	
	cout<<"\nEmptying Queue..";
	Q2.empty();
	if(Q2.isEmpty())
		cout<<"\nQueue is empty.";
	return 0;
}
