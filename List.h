#pragma once




#include <fstream>
using namespace std;


class List {


private:
	int * p;
	int listNum;
	struct Node {
		int item;
		Node * next;
	};
	Node ** heads;
	Node * z;


public:
	List(int n);
	List(ifstream & o, int len);
	void add(int i, int t);
	void display(int i);
	int getListNum();
	int len(int i);
	void writeToFile(ofstream & o, int i);
	~List();

};