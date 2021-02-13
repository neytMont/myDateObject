//Nathaniel Monte de Ramos
//CECS 282-07
//Program 2 - myDate Object
//Oct 2, 2019
#include "myDate.h"

int Greg2Julian(int month, int day, int year)  {//Gregorian to Julian conversion from prompt
	int I, J, K, JN;
	I = year;
	J = month;
	K = day;
	JN = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return JN;
}
void Julian2Greg(int JN, int& month, int& day, int& year) {//Julian to Gregorian conversion from prompt
	int I, J, K, L, N;
	L = JN + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	year = I;
	month = J;
	day = K;
	
	return;
}
myDate::myDate() {
	month = 5;
	day = 11;
	year = 1959;
}

myDate::myDate(int M, int D, int Y) {
	if (month > 12) {
		month = 5;
		day = 11;
		year = 1959;
	}
	else {
		month = M;
		day = D;
		year = Y;
	}
}

void myDate::display() {
	if (month > 12) {
		month = 5;
		day = 11;
		year = 1959;

	}
		switch (month)
		{
		case 1:
			cout << "January " << day << ", " << year;
			break;
		case 2:
			cout << "February " << day << ", " << year;
			break;
		case 3:
			cout << "March " << day << ", " << year;
			break;
		case 4:
			cout << "April " << day << ", " << year;
			break;
		case 5:
			cout << "May " << day << ", " << year;
			break;
		case 6:
			cout << "June " << day << ", " << year;
			break;
		case 7:
			cout << "July " << day << ", " << year;
			break;
		case 8:
			cout << "August " << day << ", " << year;
			break;
		case 9:
			cout << "September " << day << ", " << year;
			break;
		case 10:
			cout << "October " << day << ", " << year;
			break;
		case 11:
			cout << "November " << day << ", " << year;
			break;
		case 12:
			cout << "December " << day << ", " << year;
			break;
		}
	
}

void myDate::increaseDate(int N) {
	int g2j = Greg2Julian(month, day, year);
	g2j += N;
	Julian2Greg(g2j,month,day,year);
}

void myDate::decreaseDate(int N) {
	int g2j = Greg2Julian(month, day, year);
	g2j -= N;
	Julian2Greg(g2j, month, day, year);
}

int myDate::daysBetween(myDate D) {

	int x = Greg2Julian(month, day, year);
	int j = Greg2Julian(D.month, D.day, D.year);
	if (j > x) {
		j -= x;
		return j;
	}
}

int myDate::getMonth() {
	return month;
}

int myDate::getDay() {
	return day;
}

int myDate::getYear() {
	return year;
}

int myDate::dayOfYear() {
	int g2j = Greg2Julian(1, 1, year);
	int jdate = Greg2Julian(month, day, year);
	return jdate - g2j + 1;
}

string myDate::dayName() {
	int g2j = Greg2Julian(month, day, year);
	int x = g2j % 7;

	if (x == 0)
		return "Monday";
	else if (x == 1)
		return "Tuesday";
	else if (x == 2)
		return "Wednesday";
	else if (x == 3)
		return "Thursday";
	else if (x == 4)
		return "Friday";
	else if (x == 5)
		return "Saturday";
	else
		return "Sunday";
}