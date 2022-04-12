//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 3

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdlib>
#include "Winners.h"
#define SIZE 30

void main()
{
	char name1[SIZE];
	char name2[SIZE];
	char name3[SIZE];
	int score1;
	int score2;
	int score3;

	//The introduction of the three winners for the first time
	cout << "Enter the three names of the winners in order as well as the score of each in order:" << endl;
	cin >> name1 >> name2 >> name3 >> score1 >> score2 >> score3;
	Winners w(name1, name2, name3, score1, score2, score3);
	w.print();

	//Getting another winner name and updating the list
	char name [SIZE];
	int score;
	cout << "Enter an update of name and score:" << endl;
	cin >> name >> score;
	w.Update(name, score, name1, name2, name3, &score1, &score2, &score3);
	w.print();

	//Create a new object by Copy constructor
	Winners w1(w);
	cout << endl << "A copy of the object:" << endl;
	w1.print();

}