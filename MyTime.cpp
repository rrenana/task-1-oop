//Name:Renana Hoshen
//ID:319034757
//Firs Task Exercise 1 

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include "MyTime.h"

MyTime::MyTime() //defualt constructor
{
	hour = 0;
	min = 0;
	sec = 0;

}

MyTime::MyTime(int h, int m, int s=0) //constructor
{
	hour = h;
	min = m;
	sec = s;
}

MyTime::MyTime(const MyTime& t) //copy constructor
{
	this->hour = t.hour;
	this->min = t.min;
	this->sec = t.sec;
}

MyTime::~MyTime() //Destructive function
{
	cout << "All functions have been released";
}

//Copy data from an existing object
void MyTime::set(const MyTime& t)
{
	this->hour = t.hour;
	this->min = t.min;
	this->sec = t.sec;
}

//Copying data from parameters
bool MyTime::set(int h, int m, int s)
{
	bool check = false;
	if (h >= 0 && h <= 23 )
	{
		this->hour = h;
		if (m >= 0 && m < 60)
		{
			this->min = m;
			if (s >= 0 && s < 60)
			{
				this->sec = s;
				check = true;
			}
		}
	}
	return check;
}

//Add time to the current time
void MyTime::add(int hour, int min, int sec)
{
	int calculation = (this->sec + sec)/60;
	this->sec = (this->sec + sec) % 60;

	this->min = (calculation + this->min + min) % 60;

	this->hour = (((calculation + this->min + min) / 60) + this->hour + hour) % 24;

}

//Comparison between two hours, and checking who is earlier
MyTime* MyTime::early( MyTime& t)
{
	if (this->hour > t.hour)
		return &t;
	else
		if (this->hour < t.hour)
			return this;
		else
			if (this->min > t.min)
				return &t;
			else
				if (this->min < t.min)
					return this;
				else
					if (this->sec > t.sec)
						return &t;
					else
						if (this->sec < t.sec)
							return this;
						else
							return &t;

}

//Printing in the form of 0 to 12
void MyTime::printLong()
{
	cout << this->hour << ":" << this->min << ":" << this->sec<<endl;
}

//Print in the form of 1 to 12
void MyTime::printShort()
{
	if(this->hour % 12 == 0)
		cout<< "12" << ":" << this->min << ":" << this->sec << " ";
	else
		cout << this->hour % 12 << ":" << this->min << ":" << this->sec << " ";
	
	if (this->hour > 12)
		cout << "PM"<< endl;
	else
		cout << "AM" << endl;
}