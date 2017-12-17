#include <iostream>
#include "circularQueue.h"
using namespace std;
main() {
	CQueue<int> cq;
	try {
		for(int i=1; i<51; i++)
			cq.enqueue(i);
		cout << "Queue: " << endl << cq;
		cout << "Front: " << cq.front() << endl;
		cout << "Rear: " << cq.rear() << endl;
		for(int i=0; i<45; i++)
			cq.dequeue();
		
		cq.enqueue(51);
		cq.dequeue();
		cq.enqueue(52);
		cq.enqueue(53);
		cout << "\nQueue: " << endl << cq;
		cout << "Front: " << cq.front() << endl;
		cout << "Rear: " << cq.rear() << endl;
	} 
	catch(const char *ex) {
		cout<<ex;
	}
	return 0;
}
