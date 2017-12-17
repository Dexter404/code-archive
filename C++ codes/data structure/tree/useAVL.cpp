#include <iostream>
#include "AVL.h"
using namespace std;
int main()
{
	AVLTree<int> tree;
	for(int i=1; i<=15; i++)
		tree.insert(i);
	cout << "Tree formed..\n";	cout << tree;
	cout << "Height = " << tree.height() << "\n";
	cout << "Deleting 10..\n";	tree.remove(10);
	cout << "Deleting 11..\n";	tree.remove(11);
	cout << "Deleting 12..\n";	tree.remove(12);
	cout << "Deleting 13..\n";	tree.remove(13);
	cout << "Deleting 14..\n";	tree.remove(14);
	cout << "Deleting 15..\n";	tree.remove(15);
	cout << tree;
	cout << "Deleting all..\n";
	for(int i=1; i<=9; i++)
		tree.remove(i);
	cout << tree;
	return 0;
}
