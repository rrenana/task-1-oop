//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 2

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>

class Game
{
private:
	int code; //The code
	int guesses;  //The number of guesses
	int *history;  //The list of guesses
	bool score(int option);
public:
	Game();
	Game(const Game& g);
	~Game();
	bool update(int option);
	void print();
	
};
