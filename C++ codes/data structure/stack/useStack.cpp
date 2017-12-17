#include<iostream>
#include"stack.h"
using namespace std;
main() {
	Stack<int> S(4,5);
	S.push(9);
	S.push(5);
	S.push(6);
	cout << "Stack created..\n" << S;
	cout << "\nTop:" << S.top() << endl;
	cout << "\nPopped " << S.pop();
	cout << "\nPopped " << S.pop() << endl;
	cout<<S;
	
	Stack<int> S2;
	S2 = S;
	cout << "\nCopied stack..\n" << S2 << endl;
	
	S2.empty();
	cout << S2 << endl;
	return 0;
}
