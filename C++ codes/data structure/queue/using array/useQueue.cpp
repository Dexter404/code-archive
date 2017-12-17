#include<iostream>
#include"queue.h"
using namespace std;
int main() {
    Queue<int> Q;
    try {
    	cout << "Enqueuing.." << endl;
	    Q.enqueue(10);
	    Q.enqueue(20);
	    Q.enqueue(30);
	    Q.enqueue(40);
	    Q.enqueue(50);
	    cout << "Front: " << Q.front() << " Back:" << Q.back() << endl;
	    cout << "\nDequeuing.." << endl;
	    Q.dequeue();
	    cout << "Front: " << Q.front() << " Back:" << Q.back() << endl;
	    Q.dequeue();
	    cout << "Front: " << Q.front() << " Back:" << Q.back() << endl;
	    Q.dequeue();
	    cout << "Front: " << Q.front() << " Back:" << Q.back() << endl;
	    Q.dequeue();
	    Q.dequeue();
	    Q.dequeue();
	    Q.dequeue();
    } catch (const char * msg) {
		cerr << msg << endl;
    }
    return 0;
}
