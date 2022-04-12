//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 1 Exercise 2

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>
#include "Game.h"
#define SIZE 4


Game::Game() // Defualt constructor
{
	code = (rand() % (10000-1000))+1000;
	guesses = 0;
	history = NULL;

}

Game::Game(const Game& g) // Copy constructor
{
	this->code = g.code;
	this->guesses = g.guesses;

	if (this->guesses = 0)
	{
		history = NULL;
	}
	else
	{
		this->history = new int [guesses];
		for (int i = 0; i < guesses; ++i)
		{
			this->history[i] = g.history[i];
		}

	}


	for (int i = 0; i < guesses; ++i)
	{

	}
	
}

Game::~Game() // Destructive function
{
	delete[]history;
	cout << "All functions have been released";
}

bool Game::update(int option)
{
	//Update the amount of guesses
	this->guesses = this->guesses + 1;

	//Creating a new array and inserting all previous guesses
	int* arr = NULL;
	arr = new int[this->guesses];
	for (int i = 0; i < this->guesses - 1; ++i)
	{
		arr[i] = this->history[i];
	}
	arr[this->guesses - 1] = option;

	//Increasing the array of guess history and inserting the updated guesses into it
	delete[]this->history;
	this->history = NULL;
	this->history = new int[guesses];
	for (int i = 0; i < this->guesses; ++i)
	{
		this->history[i] = arr[i];
	}

	//Print the amount of guesses and the score
	cout << "The amount of guesswork so far:" << this->guesses << endl;
	cout << "The score of the guess is:" << endl;
	return score(option);


}

void Game::print()
{
	for (int i = 0; i < guesses; ++i)
	{
		cout << "The guess:" << this->history[i] << endl;
		cout << score(this->history[1]) << endl;
	}
}

bool Game::score(int option)
{
	//Setting Variables
	int bol = 0;
	int hit = 0;
	int real = this->code;
	int fake = option;

	//Enter data into 2 arrays
	int *arr1 = NULL;
	arr1 = new int[SIZE];
	int *arr2 = NULL;
	arr2 = new int[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		arr1[i] = real % 10;
		arr2[i] = fake % 10;
		real = real / 10;
		fake = fake / 10;
	}

	//Checking the amount of the bols
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr1[i] == arr2[i])
		{
			arr1[i] = NULL;
			arr2[i] = NULL;
			++bol;
		}
	}
	if (bol == SIZE)
		return true;

	//Checking the amount of the hits
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; i < SIZE; ++i)
		{
			if (arr1[i] == arr2[j])
			{
				arr1[i] = NULL;
				arr2[i] = NULL;
				++hit;
			}
		}
		
	}

	//Printing the quantities
	cout << "Bol:" << bol << endl;
	cout << "Hit:" << hit << endl;
	


	return false;
}