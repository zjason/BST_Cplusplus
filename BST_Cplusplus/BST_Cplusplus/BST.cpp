#include "BST.h"

template class BST<int>;

template<typename T>
Node<T>* BST<T>::insertHelper(T data, Node<T>* node)
{
	if (node == nullptr) {
		node = new Node<T>(data);
	}
	else
	{
		if (data < node->getItem()) {
			node->setLeft(insertHelper(data, node->getLeft()));
			nodes--;
		}
		else {
			node->setRight(insertHelper(data, node->getRight()));
			nodes--;
		}
	}
	nodes++;
	return node;
}

template<typename T>
Node<T>* BST<T>::findHelper(T data, Node<T>* node)
{
	if (node->getItem() == data) {
		return node;
	}
	else if (data < node->getItem()) {
		if (node->getLeft() != nullptr){
			return findHelper(data, node->getLeft());
		}	  
	}
	else
	{
		if (node->getRight() != nullptr) {
			return findHelper(data, node->getRight());
		}
	}	
	return nullptr;
}

template<typename T>
Node<T>* BST<T>::removeHelper(T data, Node<T>* node, Node<T>* temp)
{
	if (node != nullptr) {
		if (data < node->getItem()) {
			node->setLeft(removeHelper(data, node->getLeft(), temp));
		}else if (data > node->getItem()){
			node->setRight(removeHelper(data, node->getRight(), temp));
		}else{
			if (node->getLeft() && node->getRight()) {
				temp = findMax(node->getLeft());
				node->setData(temp->getItem());
				node->setLeft(removeHelper(node->getItem(), node->getLeft(), temp));
			}else{
				temp = node;
				if (node->getLeft() == nullptr) {
					node = node->getRight();
				}else if (node->getRight() == nullptr) {
					node = node->getLeft();
				}
				delete temp;
			}
		}
	}
	return node;
}

template<typename T>
void BST<T>::displayHelper(ostream & out, Node<T>* node, int level, direction d)
{
	if (node != nullptr) {
		displayHelper(out, node->getLeft(), level - 1, left);
		out << endl;
		out << setw(5 * level) << node->getItem();
		if (d == right) {
			out << "/" << endl;
		}else if(d == left){
			out << "\\" << endl;
		}else{
			out << "-" << endl;
		}
		out << endl;
		displayHelper(out, node->getRight(), level - 1, right);
	}

}

template<typename T>
int BST<T>::levelHelper(Node<T>* node) const
{
	int left;
	int right;
	if (node != nullptr) {
		left = levelHelper(node->getLeft()) + 1;
		right = levelHelper(node->getRight()) + 1;
		if (left > right) {
			return left;
		}else{
			return right;
		}
	}else{
		return 0;
	}
	return 0;
}

template<typename T>
BST<T>::BST()
{
	root = nullptr;
	nodes = 0;
}

template<typename T>
BST<T>::BST(const BST<T>& bst)
{
	
}

template<typename T>
BST<T>::~BST()
{
}

template<typename T>
void BST<T>::insert(T data)
{
	root = insertHelper(data, root);
}

template<typename T>
void BST<T>::remove(T data)
{
	Node<T> *removed = nullptr;
	if (root != nullptr) {
		root = removeHelper(data, root, removed);
	}
}

template<typename T>
void BST<T>::display(ostream & out)
{
	int level = levelHelper(root);
	cout << "level is: " << level << endl;
	displayHelper(out, root, level, none);
}

template<typename T>
Node<T>* BST<T>::getRoot()
{
	return root;
}

template<typename T>
T BST<T>::find(T key)
{
	if (root != nullptr) {
		Node<T>* result = findHelper(key, root);
		if (result != nullptr) {
			cout << "Data: " << result->getItem() << endl;
			return result->getItem();
		}
		else
		{
			cout << "Data: " << key << " did not exist!" << endl;
		}
	}
	return key;
}

template<typename T>
Node<T>* BST<T>::findMin(Node<T>* node)
{
	if (node == nullptr) {
		cout << "tree is empty" << endl;
		return nullptr;
	}else if(node->getLeft() == nullptr){
		cout << "min is: " << node->getItem() << endl;
		return node;
	}else{
		return findMin(node->getLeft());
	}
}

template<typename T>
Node<T>* BST<T>::findMax(Node<T>* node)
{
	if (node == nullptr) {
		cout << "Tree is empty!" << endl;
		return nullptr;
	}else if (node->getRight() == nullptr){
		cout << "Max is: " << node->getItem() << endl;
		return node;
	}else{
		return findMax(node->getRight());
	}
	return nullptr;
}
