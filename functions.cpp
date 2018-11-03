#include <iostream>
#include "functions.h"

using namespace std;

void menu()
{
	cout << "A) insert new item.\n"
		<< "B) display all lists\n"
		<< "C) show lenghts\n"
		<< "Q) quit\n\n";
}



int getNumberAbove(int n, const char * msg)
{
	int input;
	cout << msg << '\n';
	cin >> input;

	while (input <= n) {
		cout << "\tMust be higher than " << n << '\n';
		cin >> input;
	}
	return input;
}



int getNumberBetween(int MIN, int MAX, const char * msg)
{
	int input;
	cout << msg << '\n';
	cin >> input;

	while (!(input >= MIN) || !(input < MAX)) {
		cout << "must be a number between " << MIN << " and " << MAX - 1 << '\n';
		cin >> input;
	}

	return input;
}







bool userDoesntQuit(char & ch, void(*func)(void))
{

	func();
	cin >> ch; ch = toupper(ch);

	return (ch != 'Q');
}



void menu2() {
	cout << "Any key to insert more or \n"
		<< "Q to quit\n";
}



bool userDoesntQuit(void(*func)(void))
{
	char ch;
	func();
	cin >> ch; ch = toupper(ch);

	return (ch != 'Q');
}



List * initList()
{
	char ch;
	do {
		cout << "A) Read from existing file: \n"
			<< "B) Create new List \n\n";
		cin >> ch; ch = toupper(ch);
	} while (ch != 'A' && ch != 'B');

	switch (ch) {
	case 'A': return readFromFile(); break;
	case 'B':
		int listNum;
		listNum = getNumberAbove(0, "\tHow many lists?: ");
		return new List(listNum);
		break;
	default: "this is impossible\n\n";
	}
}



void insertNewItem(List * l)
{
	int i;
	i = getNumberBetween(0, l->getListNum(), "Which list you want to operate on?: ");

	do {
		int v;
		cout << "Value to insert: ";
		cin >> v;
		l->add(i, v);
	} while (userDoesntQuit(menu2));
}



void displayAllLists(List * l)
{
	for (int i = 0; i < l->getListNum(); i++)
		l->display(i);
	cout << "\n\n";
}



void getLengthOf(List * l) {
	for (int i = 0; i < l->getListNum(); i++)
		cout << "\tList[" << i << "]---" << l->len(i) << '\n';
	cout << "\n\n";
}



void hash1(List * l, int ar[], int arlen)
{
	int len = l->getListNum();

	for (int i = 0; i < arlen; i++) {
		int index = ar[i] % len;
		l->add(index, ar[i]);
	}
}



void writeToFile(List * l)
{
	ofstream o("LIST.DTA");
	int len = l->getListNum();

	o << len << endl;
	for (int i = 0; i < len; i++)
		l->writeToFile(o, i);
}



List * readFromFile()
{
	ifstream o("LIST.DTA");

	int len;
	o >> len;

	List * l;

	l = new List(o, len);

	return l;
}