#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "BST.h"
#include "Node.h"

using namespace::std;

int main(){
	BST<int> a = BST<int>();

	a.insert(66);
	a.insert(616);
	a.insert(626);
	a.insert(55);
	a.insert(58);
	cout << "display tree" << endl;
	a.display(cout);
	a.find(626);
	a.findMin(a.getRoot());
	a.findMax(a.getRoot());
	a.remove(66);
	a.remove(58);
	a.display(cout);
}