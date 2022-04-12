//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 1

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>

class MyTime
{
private:
	int hour; //The number of hours
	int min;  //The number of minutes
	int sec;  //The number of seconds
public:
	MyTime();
	MyTime(int h,int m,int s);
	MyTime(const MyTime&t);
	~MyTime();
	void set(const MyTime& t);
	bool set(int h, int m, int s);
	void add(int hour, int min, int sec);
	MyTime* early( MyTime& t);
	void printLong();
	void printShort();

};