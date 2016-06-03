#include "Node.h"


template<typename T>
Node<T>::Node()
{
	left = nullptr;
	right = nullptr;
}


template<typename T>
Node<T>::Node(T newData, Node<T>* newLeft, Node<T>* newRight)
{
	data = newData;
	left = newLeft;
	right = newRight;
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
void Node<T>::setData(T newData)
{
	data = newData;
}

template<typename T>
void Node<T>::setLeft(Node<T>* newLeft)
{
	left = newLeft;
}

template<typename T>
void Node<T>::setRight(Node<T>* newRight)
{
	right = newRight;
}

template<typename T>
T Node<T>::getItem()
{
	return data;
}

template<typename T>
Node<T>* Node<T>::getLeft()
{
	return left;
}

template<typename T>
Node<T>* Node<T>::getRight()
{
	return right;
}
