#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
	int arr[] = {2, 3, 4, 6};
	BST<int> tree(arr, 4);
	tree.insert(1);
	tree.insert(5);
	tree.insert(7);
	tree.insert(8);
	cout << "Tree formed..\n";	cout << tree;
	cout << "Height = " << tree.height() << "\n";
	cout << "Deleting 1..\n";	tree.remove(1);
	cout << "Deleting 4..\n";	tree.remove(4);
	cout << "Deleting 3..\n";	tree.remove(3);
	cout << "Deleting 6..\n";	tree.remove(6);
	cout << tree;
	return 0;
}
