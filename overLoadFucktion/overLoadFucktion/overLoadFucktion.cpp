#include <iostream>
using namespace std;

class Date {
public:
	int year;
	int month;
	int day;

	Date() {
		year = 0;
		month = 0;
		day = 0;
	}

	Date(int tmpYear, int tmpMonth, int tmpDays) {
		if (tmpDays > 0 && tmpDays <= 30) {
			day = tmpDays;
		}
		else {
			cout << "Ошибка, неверный ввода дня" << endl;
		}
		if (tmpMonth > 0 && tmpMonth <= 12) {
			month = tmpMonth;
		}
		else {
			cout << "Ошибка, неверный ввод месяц";
		}		
		if (tmpYear > 0) {
			year = tmpYear;
		}
		else {
			cout << "Ошибка, неверный ввод года";
		}
	}
};


Date operator - (Date date, int a) {
	Date result = Date();
	int addYears = (a / 30) / 12; 
	int addMonths = (a / 30) - addYears * 12; 
	int addDays = a - (30 * (a / 30)); 
	if (a < 30) {
		if (date.month != 1) {
			result.year = date.year;
			if (a - date.day < 0) {
				result.month = date.month;
				result.day = date.day - a;
			}
			else {
				result.month = date.month - 1;
				result.day = 30 - (a - date.day);
			}
		}
		else {
			if (a - date.day > 0) {
				result.year = date.year - 1;
				result.month = 12;
				result.day = 30 - (a - date.day);
			}
			else {
				result.year = date.year;
				result.month = date.month;
				result.day = date.day - a;
			}
		}
	}else{
		if (addYears > 0) {
			result.year = date.year - addYears;
			if (date.month - addMonths <= 0) {
				result.month = 12 - (addMonths - date.month);
			}
			else{
				result.month = date.month - addMonths;
			}
		}
		else if (date.month - addMonths <= 0) {
			result.year = date.year - 1;
			result.month = 12 - (addMonths - date.month);
		}
		else {
			result.year = date.year;
			result.month = date.month - addMonths;
		}
		if (date.day - addDays < 0) {
			result.day = 30 - (addDays - date.day);
		}
		else {
			result.day = date.day - addDays;
		}
	}

	return result;
}



Date operator + (Date date, int a)
{
	Date result = Date();
	int addYears = (a / 30) / 12;
	int addMonths = (a / 30) - addYears * 12;
	int addDays = a - (30 * (a / 30)); 

	if (a <= 30) {
		if (date.month != 12) {
			result.year = date.year;
			if (date.day + a > 30) {
				result.month = date.month + 1;
				result.day = a - (30 - date.day);
			}
			else {
				result.day = date.day + a;
				result.month = date.month;
			}
		}
		else {
			if (date.day + a > 30) {
				result.year = date.year + 1;
				result.month = 1;
				result.day = a - (30 - date.day);
			}
			else {
				result.year = date.year;
				result.month = 12;
				result.day = date.day + a;
			}
		}
	}
	else {
		if (addYears > 0) {
			result.year = date.year + addYears;
			if (date.month + addMonths > 12) {
				result.month = addMonths - (12 - date.month);
			}
			else {
				result.month = date.month + addMonths;
			}
		}
		else if(date.month + addMonths > 12) {
			result.year = date.year + 1;
			result.month = addMonths - (12 - date.month);
		}
		else {
			result.year = date.year;
			result.month = date.month + addMonths;
		}
		if (date.day + addDays > 30) {
			result.day = addDays - (30 - date.day);
		}
		else {
			result.day = date.day + addDays;
		}
	
	}
	return result;
}

void print(Date date1) {
	cout << date1.year << "\t" << date1.month << "\t" << date1.day << endl;
}

template <typename T1, typename T2>
T1 compair(T1 a, T2 b) {
	if (a > b) return 1;
	if (a == b) return 0;
	if (a < b) return -1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int yyyy, mm, dd, delta;
	Date date2;
	
	cout <<  "Введите год: ";
	cin >> yyyy;
	cout << "Введите месяц: ";
	cin >> mm;
	cout << "Введите день: ";
	cin >> dd;
	cout << "Введите на сколько прибавить дней: ";
	cin >> delta;

	Date date1(yyyy, mm, dd);

	date2 = date1 + delta;
	print(date2);
	date2 = date1 - delta;
	print(date2);
	     
	return 0;
}
