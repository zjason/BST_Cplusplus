#pragma once

// T is a generic data type
template <class T>
class Node
{
// private means only this class (base class) can access or modify the private field
private:
	T data;
	Node *left;
	Node *right;

// data or method in protected field means only this class and it's 
// child class (derived class) can access or modify
protected:

// 
public:
	Node();
	// overloading Node() function for more argument. Overloading means the same 
	// function name with different arguments
	Node(T newData, Node<T> *newLeft = nullptr, Node<T> *newRight = nullptr);
	~Node();

	void setData(T newData);
	void setLeft(Node<T> *newLeft);
	void setRight(Node<T> *newRight);

	T getItem();
	Node<T> *getLeft();
	Node<T> *getRight();
};

