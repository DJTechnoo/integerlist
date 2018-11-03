#pragma once

#include "List.h"




// List functions
List * initList();
List * readFromFile();
void insertNewItem(List * l);
void displayAllLists(List * l);
void getLengthOf(List * l);
void hash1(List * l, int ar[], int arlen);
void writeToFile(List * l);


// menus
void menu();
void menu2();


// helpers
bool userDoesntQuit(char & ch, void(*func)(void));
bool userDoesntQuit(void(*func)(void));
int getNumberAbove(int n, const char * msg);
int getNumberBetween(int MIN, int MAX, const char * msg);