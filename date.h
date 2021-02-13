#pragma once
#ifndef MYDATE_H
#define MYDATE_H

#include <iostream>

using namespace std;

class myDate {
private:
	int day;
	int month;
	int year;

public:
	myDate(); //default constructor, this will set the date to the values
	myDate(int M, int D, int Y); //overloaded constructor. This will set the date to the values passed in through the 
								 //parameter list represented by Month, Day, and Year
	void display(); //display the date in the following format ( May 11, 1959)
	void increaseDate(int N); //increment the date by N days
	void decreaseDate(int N); //decrement the date by N days
	int daysBetween(myDate D); //return the number of dats between this date and the date D
	int getMonth(); //return the month in integer form
	int getDay(); //return the day of the month
	int getYear(); //return the year
	int dayOfYear(); //return the num of days since the current year began 
	string dayName(); //return Monday , Tuesday etc
};
#endif MYDATE_H
