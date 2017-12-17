#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>
using namespace std;
template<typename T>
class Node
{
public:
	T data;
	Node* left;
	Node* right;
	Node() : data(0), left(0), right(0) {}
	Node(T d) : data(d), left(0), right(0) {}
};
template<typename T>
class BST
{
	Node<T>* root;
	static Node<T>* insert(Node<T>* node, T ele)
	{
		if(node == NULL)
			return new Node<T>(ele);
		if(ele < node->data)
			node->left = insert(node->left, ele);
		else node->right = insert(node->right, ele);
		return node;
	}
	static Node<T>* remove(Node<T>* node, T ele)
	{
		if(node == NULL)
			return node;
		if(ele < node->data)
			node->left = remove(node->left, ele);
		else if(ele > node->data)
			node->right = remove(node->right, ele);
		else
		{
			if(!node->left && !node->right)
				node = NULL;
			else if(!node->left)
				node = node->right;
			else if(!node->right)
				node = node->left;
			else
			{
				Node<T>* min = node->right;
				while(min->left)
					min = min->left;
				min->right = remove(node->right, min->data);
				min->left = node->left;
				node = min;
			}
		}
		return node;
	}
	static int height(Node<T>* node)
	{
		if(node == NULL)
			return 0;
		if(!node->left && !node->right)
			return 1;
		return 1 + max(height(node->left), height(node->right));
	}
public:
	BST() : root(0)	{}
	void insertIter(T ele)
	{
		Node<T>* newnode = new Node<T>(ele);
		if(root == NULL)
		{
			root = newnode;
			return;
		}
		Node<T>* iter = root;
		Node<T>* parent = NULL;
		while(iter)
		{
			parent = iter;
			if(iter->data > ele)
				iter = iter->left;
			else iter = iter->right;
		}
		if(parent->data > ele)
			parent->left = newnode;
		else parent->right = newnode;
	}
	void removeIter(T ele)
	{
		if(!root)	return;
		Node<T>* iter = root;
		Node<T>* parent = NULL;
		while(iter->data != ele)
		{
			parent = iter;
			if(ele < iter->data)
				iter = iter->left;
			else iter = iter->right;
		}
		if(iter->data != ele)	return;

		Node<T>* delnode = iter;
		if(!iter->left || !iter->right)
		{
			if(iter->left)	iter = iter->left;
			else 			iter = iter->right;
			if(parent)
			{
				if(ele < parent->data)
					parent->left = iter;
				else parent->right = iter;
			}
			else root = iter;
		}
		else
		{
			Node<T>* p_iter = iter;
			iter = iter->right;
			while(iter->left)
			{
				p_iter = iter;
				iter = iter->left;
			}
			if(p_iter != delnode)
			{
				p_iter->left = iter->right;
				iter->right = delnode->right;
			}
			iter->left = delnode->left;
			if(parent && ele < parent->data)
				parent->left = iter;
			else if(parent)
				parent->right = iter;
			else root = iter;
		}
		delete delnode;
	}
	void insert(T ele)
	{
		root = insert(root, ele);
	}
	void remove(T ele)
	{
		if(find(ele) == NULL)
			throw "Element does not exist!";
		root = remove(root, ele);
	}
	Node<T>* find(T ele)
	{
		Node<T>* iter = root;
		while(iter->data != ele)
		{
			if(ele < iter->data)
				iter = iter->left;
			else iter = iter->right;
		}
		return iter;
	}
	int height()
	{
		return height(root);
	}
	template<typename U>
	friend ostream& operator<<(ostream& , const BST<U>& );
};
template<typename U>
ostream& operator<<(ostream& out, const BST<U>& tree)
{
	if(tree.root == NULL)
	{
		out << "Tree is empty!";
		return out;
	}
	queue<Node<U>*> q;
	q.push(tree.root);
	while(!q.empty())
	{
		int nodecount = q.size();
		while(nodecount--)
		{
			Node<U>* x = q.front();
			q.pop();
			out << x->data << " ";
			if(x->left)
				q.push(x->left);
			if(x->right)
				q.push(x->right);
		}
		out << endl;
	}
	return out;
}
#endif
