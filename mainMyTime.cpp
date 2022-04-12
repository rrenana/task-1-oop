//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 1

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include "MyTime.h"

int main()
{
	//Set local variables and get user input
	int h1, m1, s1;
	int h2, m2, s2;

	cout << "Please enter the first hour" << endl;
	cin >> h1 >> m1 >> s1;
	cout << "Please enter the second hour" << endl;
	cin >> h2 >> m2 >> s2;
	
	//Definition of 2 objects by constructor with parameters
	MyTime t1(h1, m1, s1);
	MyTime t2(h2, m2, s2);

	//Print the 2 objects in a format of 1 to 12
	t1.printShort();
	t2.printShort();

	//Receiving input from the user in order to update the objects
	cout << "Please enter the changes for the first hour" << endl;
	cin >> h1 >> m1 >> s1;
	cout << "Please enter the changes for the second hour" << endl;
	cin >> h2 >> m2 >> s2;

	//Checking that the inputs are correct and placing objects
	if (t1.set(h1, m1, s1)==true)
		t1.set(h1, m1, s1);
	if (t2.set(h2, m2, s2) == true)
		t2.set(h2, m2, s2);

	//Checking the earlier time between the 2 objects, and creating a pointer that will point to the earlier time
	MyTime* p = NULL;
	p = t1.early(t2);

	//Printing the pointer to the early hour
	cout << "The early hour is" << " ";
	(*p).printLong();
	cout << endl;

	//Print the 2 objects in a format of 0 to 23
	t1.printLong();
	t2.printLong();

	return 0;
}