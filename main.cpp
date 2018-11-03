#include <iostream>
#include <fstream>
#include "List.h"
#include "functions.h"


using namespace std;



int main() {

	List * list;

	list = initList();


	char ch;
	while (userDoesntQuit(ch, menu)) {
		switch (ch) {
			case 'A': insertNewItem(list);		break;
			case 'B': displayAllLists(list);	break;
			case 'C': getLengthOf(list);		break;
			default: cout << "\tNot an option! \n\n";
		}
	}

	writeToFile(list);
	return 0;
}




