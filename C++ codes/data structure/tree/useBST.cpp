#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
	BST<int> tree;
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);
	tree.insert(6);
	tree.insert(5);
	tree.insert(7);
	tree.insert(8);
	cout << "Tree formed..\n";	cout << tree;
	cout << "Height = " << tree.height() << "\n";
	cout << "Deleting 1..\n";	tree.remove(1);
	cout << "Deleting 4..\n";	tree.remove(4);
	cout << "Deleting 6..\n";	tree.remove(6);
	cout << tree;
	return 0;
}
