//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 3

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>

class Winners
{
private:
	char* first_name; //The first winner
	char* second_name;  //The second winner
	char* third_name;  //The third winner
	int first_score; //The score of the first winner
	int second_score; //The score of the second winner
	int third_score; //The score of the third winner

public:

	Winners(char* name1, char* name2, char* name3, int score1, int score2, int score3);
	Winners(const Winners& w);
	~Winners();
	void print();
	void Update(char* name, int score, char* name1, char* name2, char* name3, int* score1, int* score2, int* score3);
	int check(int num);
	void change(int num, int score, char* name);
	void order(char* name1, char* name2, char* name3, int& score1, int& score2, int& score3);
	void copy1(const char* string1);
	void copy2(const char* string2);
	void copy3(const char* string3);
	char* copy11();
	char* copy22();
	char* copy33();
};