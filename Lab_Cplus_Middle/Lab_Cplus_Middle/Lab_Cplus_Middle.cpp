#include "pch.h"
#include <iostream>
#include <string>

struct date { // структура задания даты месяцом годом и днем 
	int day;
	int month;
	int year;
};
struct par { // первоначальная структура
	std::string name;
	date Date;
	int strokGod;
	double cost;
	int serialNumber;
	date godenDO;
};

void out(par arr[], int i) { // функция реализующая вывод срока годности 
	for (size_t j = 0; j < i; j++)
	{
		std::cout << "name: " << arr[j].name << "\n";
		std::cout << "Goden do: " << arr[j].godenDO.day << "." << arr[j].godenDO.month << "." << arr[j].godenDO.year << "\n";
		std::cout << "______________________\n";
	}
}

int main()
{
	int i = 0;
	par x[50];


	std::cout << "Enter kol tovara(not more 50)\n"; //задание количества тваров 
	std::cin >> i;
	for (size_t j = 0; j < i; j++) // ввод данных
	{
		std::cout << "Enter Name\n";
		std::cin >> x[j].name;
		std::cout << "Enter Date of manufacture(d,m,y)\n";
		std::cin >> x[j].Date.day >> x[j].Date.month >> x[j].Date.year;
		x[j].godenDO.day = x[j].Date.day;
		x[j].godenDO.month = x[j].Date.month;
		x[j].godenDO.year = x[j].Date.year;
		std::cout << "Enter strokGODN(day)\n";
		std::cin >> x[j].strokGod;
		std::cout << "Enter cost\n";
		std::cin >> x[j].cost;
		std::cout << "Enter erialnumbe\n";
		std::cin >> x[j].serialNumber;
	}



	for (size_t j = 0; j < i; j++) // проверки на переходы из месяца в месяц и года
	{
		if (x[j].Date.month == 2) {
			if ((x[j].strokGod + x[j].Date.day) > 28) {
				x[j].godenDO.day = (x[j].strokGod + x[j].Date.day) - 28;
				x[j].godenDO.month++;
			}
			else {
				x[j].godenDO.day = x[j].strokGod + x[j].Date.day;
			}


		}
		else if (x[j].Date.month == 1 || x[j].Date.month == 3 || x[j].Date.month == 5 || x[j].Date.month == 7 || x[j].Date.month == 8 || x[j].Date.month == 10 || x[j].Date.month == 12) {
			if ((x[j].strokGod + x[j].Date.day) > 31) {
				x[j].godenDO.day = (x[j].strokGod + x[j].Date.day) - 31;
				x[j].godenDO.month++;
			}
			else {
				x[j].godenDO.day = x[j].strokGod + x[j].Date.day;
			}
			if (x[j].godenDO.month > 12) {
				x[j].godenDO.year++;
				x[j].godenDO.month = x[j].godenDO.month - 12;
			}
		}
		else {
			if ((x[j].strokGod + x[j].Date.day) > 30) {
				x[j].godenDO.day = (x[j].strokGod + x[j].Date.day) - 30;
				x[j].godenDO.month++;
			}
			else {
				x[j].godenDO.day = x[j].strokGod + x[j].Date.day;
			}
			if (x[j].godenDO.month > 12) {
				x[j].godenDO.year++;
				x[j].godenDO.month = x[j].godenDO.month - 12;
			}
		}


	}


	out(x, i); // вывод годности 
}


