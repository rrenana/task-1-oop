//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 1 Exercise 3

#include<stdio.h>
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>
#include "Winners.h"



Winners::Winners(char* name1, char* name2, char* name3, int score1, int score2, int score3)// constructor
{
	this->first_name = new char[strlen(name1) + 1];
	this->second_name = new char[strlen(name2) + 1];
	this->third_name = new char[strlen(name3) + 1];
	copy1( name1);
	copy2( name2);
	copy3( name3);

	this->first_score = score1;
	this->second_score = score2;
	this->third_score = score3;
}

Winners::Winners(const Winners& w) // Copy constructor
{
	this->first_score = w.first_score;
	this->second_score = w.second_score;
	this->third_score = w.third_score;

	this->first_name = new char[strlen(w.first_name) + 1];
	for (int i = 0; i < strlen(w.first_name) + 1; ++i)
		this->first_name[i] = w.first_name[i];

	this->second_name = new char[strlen(w.second_name) + 1];
	for (int i = 0; i < strlen(w.second_name) + 1; ++i)
		this->second_name[i] = w.second_name[i];
	
	this->third_name = new char[strlen(w.third_name) + 1];
	for (int i = 0; i < strlen(w.third_name) + 1; ++i)
		this->third_name[i] = w.third_name[i];
}

Winners::~Winners() // Destructive function
{
	delete[]this->first_name;
	delete[]this->second_name;
	delete[]this->third_name;

	cout << "All functions have been released";
}

//Function for printing the three winners and their score
void Winners::print()
{
	cout << "The first winner is:" << this->first_name<<endl<< "his score is:" << this->first_score << endl;
	cout << "The second winner is:" << this->second_name << endl << "his score is:" << this->second_score << endl;
	cout << "The third winner is:" << this->third_name << endl << "his score is:" << this->third_score << endl;
}

//Function for updating the three winners
void Winners::Update(char* name, int score, char* name1, char* name2, char* name3, int* score1, int*score2, int* score3)
{

	if (strcmp(this->third_name, name)==0)
	{
		this->third_score = score;

		order(name1, name2, name3, *score1, *score2, *score3);
	}
	else
	{
		if (strcmp(this->second_name, name)==0)
		{
			this->second_score = score;

			order(name1, name2, name3, *score1, *score2, *score3);
		}
		else
		{

			if (strcmp(this->first_name, name)==0)
			{
				this->first_score = score;

				order(name1, name2, name3, *score1, *score2, *score3);
			}
			else
			{

				int num = check(score);
				change(num, score, name);
			}
		}
	}
	

}

//Checking the position of the new score in the list of three winners
int Winners::check(int num)
{
	if (num > this->third_score)
	{
		if (num > this->second_score)
		{
			if (num > this-> first_score)
			{
				return 1;

			}
			return 2;
		}
		return 3;
	}
	return 0;
}

//
void Winners::change(int num, int score, char* name)
{
	switch (num)
	{
	case 0:
		break;
	case 1:
		this->third_score = this->second_score;
		copy3( this->second_name);

		this->second_score = this->first_score;
		copy2( this->third_name);

		this->second_score = score;
		copy1( name);
		break;
	case 2:
		this->third_score = this->second_score;
		copy3(this->second_name);

		this->second_score = score;
		copy2( name);
		break;
	case 3:
		this->third_score = score;
		copy3( name);
		break;
	default:
		break;


	}
}


//Checking and defining the order of the winners and their points
void Winners::order(char* name1, char* name2, char* name3, int& score1, int& score2, int& score3)
{
	if (this->third_score > this->first_score)
	{
		if (this->second_score > this->third_score)
		{
			name1 = copy22();
			name2 = copy33();
			name3 = copy11();
			score1 = this->second_score;
			score2 = this->third_score;
			score3 = this->first_score;

			copy1(name1);
			copy2(name2);
			copy3(name3);
			this->first_score = score1;
			this->second_score = score2;
			this->third_score = score3;

		}
		else
		{
			if (this->second_score > this->first_score)
			{
				name1 = copy33();
				name2 = copy22();
				name3 = copy11();
				score1 = this->third_score;
				score2 = this->second_score;
				score3 = this->first_score;

				copy1(name1);
				copy2(name2);
				copy3(name3);
				this->first_score = score1;
				this->second_score = score2;
				this->third_score = score3;

			}
			else
			{
				name1 = copy33();
				name2 = copy11();
				name3 = copy22();
				score1 = this->third_score;
				score2 = this->first_score;
				score3 = this->second_score;

				copy1(name1);
				copy2(name2);
				copy3(name3);
				this->first_score = score1;
				this->second_score = score2;
				this->third_score = score3;

			}
		}
	}
	else
	{
		if (this->second_score > this->third_score)
		{
			if (this->second_score > this->first_score)
			{

				name1 = copy22();
				name2 = copy11();
				name3 = copy33();
				score1 = this->second_score;
				score2 = this->first_score;
				score3 = this->third_score;

				copy1(name1);
				copy2(name2);
				copy3(name3);
				this->first_score = score1;
				this->second_score = score2;
				this->third_score = score3;

			}
			else
			{
				name2 = copy11();
				name1 = copy22();
				name3 = copy33();
				score1 = this->first_score;
				score2 = this->second_score;
				score3 = this->third_score;

				copy1(name1);
				copy2(name2);
				copy3(name3);
				this->first_score = score1;
				this->second_score = score2;
				this->third_score = score3;

			}
		}
		else
		{
			name1 = copy11();
			name2 = copy33();
			name3 = copy22();
			score1 = this->first_score;
			score2 = this->third_score;
			score3 = this->second_score;

			copy1(name1);
			copy2(name2);
			copy3(name3);
			this->first_score = score1;
			this->second_score = score2;
			this->third_score = score3;
		}
	}
	
}


//Copy a string to the first private variable in the class
void Winners::copy1( const char* string1)
{
	delete[]this->first_name;
	this->first_name = new char[strlen(string1) + 1];
	for (int i = 0; i < strlen(string1) + 1; ++i)
		this->first_name[i] = string1[i];

}

//Copy a string to the second private variable in the class
void Winners::copy2(const char* string2)
{
	delete[]this->second_name;
	this->second_name = new char[strlen(string2) + 1];
	for (int i = 0; i < strlen(string2) + 1; ++i)
		this->second_name[i] = string2[i];

}

//Copy a string to the third private variable in the class
void Winners::copy3(const char* string3)
{
	delete[]this->third_name;
	this->third_name = new char[strlen(string3) + 1];
	for (int i = 0; i < strlen(string3) + 1; ++i)
		this->third_name[i] = string3[i];
}


//Copy the first private variable in the string class
char* Winners::copy11()
{
	char* string1 = NULL;
	string1 = new char[strlen(this->first_name) + 1];
	for (int i = 0; i < strlen(this->first_name) + 1; ++i)
		string1[i] = this->first_name[i];
	return string1;
}

//Copy the second private variable in the string class
char* Winners::copy22()
{
	char* string2 = NULL;
	string2 = new char[strlen(this->second_name) + 1];
	for (int i = 0; i < strlen(this->second_name) + 1; ++i)
		string2[i] = this->second_name[i];
	return string2;
}

//Copy the third private variable in the string class
char* Winners::copy33()
{
	char* string3 = NULL;
	string3 = new char[strlen(this->third_name) + 1];
	for (int i = 0; i < strlen(this->third_name) + 1; ++i)
		string3[i] = this->third_name[i];
	return string3;
}