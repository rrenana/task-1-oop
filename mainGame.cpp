//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 2

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdlib>
#include "Game.h"

void main()
{
	Game g;
	int guess;
	bool check = false;
	do
	{
		cout << "Please insert a guess" << endl;
		cin >> guess;
		check = g.update(guess);

	} while (check==false);
	
	cout << "Congratulations! You managed to guess the correct code!" << endl;
	g.print();
	g.~Game();

}