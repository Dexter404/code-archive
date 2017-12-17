#pragma once
#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <queue>
using namespace std;
template<typename T>
class AVLNode
{
public:
	T data;
	int height;
	AVLNode* left;
	AVLNode* right;
	AVLNode() : data(0), height(0), left(0), right(0) {}
	AVLNode(T d) : data(d), height(1), left(0), right(0) {}
};
template<typename T>
class AVLTree
{
	AVLNode<T>* root;
	static int height(AVLNode<T>* node)
	{
		if(node == NULL)
			return 0;
		if(node->left && node->right)
			return 1 + max(node->left->height, node->right->height);
		else if(node->left)
			return 1 + node->left->height;
		else if(node->right) 
			return 1 + node->right->height;
		else return 1;
	}
	static int balanceFactor(AVLNode<T>* node)
	{
		if(node == NULL)	return 0;
		int factor = 0;
		if(node->left)	factor -= node->left->height;
		if(node->right)	factor += node->right->height;
		return factor;
	}
	static void rotate(AVLNode<T>*& node, char type)
	{
		AVLNode<T>* root;
		if(type == 'l')	//left rotation
		{
			root = node->left;
			node->left = root->right;
			root->right = node;
		}
		if(type == 'r')	//right rotation
		{
			root = node->right;
			node->right = root->left;
			root->left = node;
		}
		node->height = height(node);
		root->height = height(root);
		node = root;
	}
	static AVLNode<T>* insert(AVLNode<T>* node, T ele)
	{
		if(node == NULL)
			return new AVLNode<T>(ele);
		if(ele < node->data)
			node->left = insert(node->left, ele);
		else node->right = insert(node->right, ele);
		node->height = height(node);
		
		if(balanceFactor(node) < -1)
		{
			//if left right case, first right rotation
			if(balanceFactor(node->left) == 1)
				rotate(node->left, 'r');
			//for left left case, just left rotation
			rotate(node, 'l');
		}
		if(balanceFactor(node) > 1)
		{
			//if right left case, first left rotation
			if(balanceFactor(node->right) == -1)
				rotate(node->right, 'l');
			//for right right case, just right rotation
			rotate(node, 'r');
		}
		return node;
	}
	static AVLNode<T>* remove(AVLNode<T>* node, T ele)
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
				AVLNode<T>* min = node->right;
				while(min->left)
					min = min->left;
				min->right = remove(node->right, min->data);
				min->left = node->left;
				node = min;
			}
		}
		if(node == NULL)	return node;
		
		node->height = height(node);
		
		if(balanceFactor(node) < -1)
		{
			//if left right case, first right rotation
			if(balanceFactor(node->left) == 1)
				rotate(node->left, 'r');
			//for left left case, just left rotation
			rotate(node, 'l');
		}
		if(balanceFactor(node) > 1)
		{
			//if right left case, first left rotation
			if(balanceFactor(node->right) == -1)
				rotate(node->right, 'l');
			//for right right case, just right rotation
			rotate(node, 'r');
		}
		return node;
	}
public:
	AVLTree() : root(0)	{}
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
	AVLNode<T>* find(T ele)
	{
		AVLNode<T>* iter = root;
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
		return root->height;
	}
	template<typename U>
	friend ostream& operator<<(ostream& , const AVLTree<U>& );
};
template<typename U>
ostream& operator<<(ostream& out, const AVLTree<U>& tree)
{
	if(tree.root == NULL)
	{
		out << "Tree is empty!";
		return out;
	}
	queue<AVLNode<U>*> q;
	q.push(tree.root);
	while(!q.empty())
	{
		int nodecount = q.size();
		while(nodecount--)
		{
			AVLNode<U>* x = q.front();
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
