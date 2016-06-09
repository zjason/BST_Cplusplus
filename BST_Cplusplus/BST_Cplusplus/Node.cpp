#include "Node.h"

template class Node<int>;

template<class T>
Node<T>::Node()
{
	left = nullptr;
	right = nullptr;
}


template<class T>
Node<T>::Node(T newData, Node<T>* newLeft, Node<T>* newRight)
{
	data = newData;
	left = newLeft;
	right = newRight;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
void Node<T>::setData(T newData)
{
	data = newData;
}

template<class T>
void Node<T>::setLeft(Node<T>* newLeft)
{
	left = newLeft;
}

template<class T>
void Node<T>::setRight(Node<T>* newRight)
{
	right = newRight;
}

template<class T>
T Node<T>::getItem()
{
	return data;
}

template<class T>
Node<T>* Node<T>::getLeft()
{
	return left;
}

template<class T>
Node<T>* Node<T>::getRight()
{
	return right;
}
