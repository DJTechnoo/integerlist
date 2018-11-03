#include <iostream>
#include "List.h"


using namespace std;




List::List(int n = 10) {

	p = new int[n];
	for (int i = 0; i < n; i++) p[i] = 0;

	listNum = n;
	heads = new Node*[n];
	z = new Node;

	for (int i = 0; i < n; i++) {
		heads[i] = new Node;
		heads[i]->next = z;
	}
	z->next = z;
}



void List::add(int i, int t) {
	Node * node = new Node;
	node->item = t;

	Node * x = heads[i]->next;
	heads[i]->next = node;
	node->next = x;
	p[i]++;

	display(i);
}



void List::display(int i) {
	Node * t = heads[i]->next;
	cout << "\t( head[" << i << "] )-->";
	while (t != z) {
		cout << "( " << t->item << " )-->";
		t = t->next;
	}
	cout << "( z )\n";
}



int List::getListNum()
{
	return this->listNum;
}



int List::len(int i)
{
	return p[i];
}



void List::writeToFile(ofstream & o, int i)
{
	Node * t = heads[i]->next;
	o << '\t' << p[i] << endl;
	while (t != z) {
		o << "\t\t" << t->item << endl;
		t = t->next;
	}

}



List::List(ifstream & o, int len)
{
	p = new int[len];
	for (int i = 0; i < len; i++) p[i] = 0;

	listNum = len;
	heads = new Node*[len];
	z = new Node;

	for (int i = 0; i < len; i++) {
		heads[i] = new Node;
		heads[i]->next = z;
	}
	z->next = z;


	for (int i = 0; i < len; i++) {
		int * temp;
		int n;
		o >> n;
		temp = new int[n];

		for (int j = 0; j < n; j++) {
			int addedNum;
			o >> addedNum;
			temp[j] =  addedNum;
		}

		for (int j = n-1; j >= 0; j--) {
			this->add(i, temp[j]);
		}

		delete[] temp;
	}

}



List::~List()
{
	delete[] heads;
	delete z;
}