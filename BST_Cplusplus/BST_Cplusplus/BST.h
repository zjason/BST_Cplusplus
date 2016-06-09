#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"

using namespace::std;

template <typename T>
class BST
{
private:
	enum direction {left, right, none};
	Node<T>* root;
	int nodes;

	Node<T>* insertHelper(T data, Node<T>* node);
	Node<T>* findHelper(T data, Node<T>* node);
	Node<T>* removeHelper(T data, Node<T>* node, Node<T>* temp);
	void displayHelper(ostream& out, Node<T>* node, int level, direction d);
	int levelHelper(Node<T>* node) const;
	

	
public:
	BST();
	BST(const BST<T>& bst);
	~BST();

	void insert(T data);
	void remove(T data);
	void display(ostream& out);
	Node<T>* getRoot();
	T find(T key);
	Node<T>* findMin(Node<T>* node);
	Node<T>* findMax(Node<T>* node);
};

