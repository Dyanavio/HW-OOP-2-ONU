#include <iostream>
#include <list>
#include <string.h>
#include "color.hpp"

using namespace std;

struct Student
{
	string surname;
	int year;
	double calculus; // математический анализ
	double algebra;

	Student(string surname, int year, double calculus, double algebra)
	{
		this->surname = surname;
		this->year = year;
		this->calculus = calculus;
		this->algebra = algebra;
	}
};

void printList(list<Student>& students)
{
	std::list<Student>::iterator it;
	for (it = students.begin(); it != students.end(); it++)
	{
		cout << (*it).surname << " " << (*it).year << " | Calculus: " << (*it).calculus << " | Algebra: " << (*it).algebra << endl;
	}
	cout << endl;
}

bool surnamePredicate(const Student& first, const Student& second)
{
	/*int i = 0;
	while ((i < first.surname.length()) && (i < second.surname.length()))
	{
		if (tolower(first.surname[i]) < tolower(second.surname[i])) return true;
		else if (tolower(first.surname[i]) > tolower(second.surname[i])) return false;
		++i;
	}
	return (first.surname.length() < second.surname.length());*/
	if (first.surname <= second.surname) return true;
	else return false;
}

bool yearPredicate(const Student& first, const Student& second)
{
	if (first.year < second.year) return true;
	else return false;
}

void transfer(list<Student>& students)
{
	std::list<Student>::iterator it;
	for (it = students.begin(); it != students.end(); it++)
	{
		if ((*it).calculus >= 80 && (*it).algebra >= 80) (*it).year++; // Поменял условие на 80
	}
}

bool deletePredicate(const Student& student)
{
	if (student.algebra <= 80 || student.calculus <= 80) return true;
	return false;
}

int main()
{
	list<Student> students;

	students.push_back(Student("Cranel", 1, 85.5, 88.0));
	students.push_back(Student("Lion", 1, 90.0, 88.5));
	students.push_back(Student("Asahina", 1, 76.0, 82.3));
	students.push_back(Student("Aqua", 1, 92.1, 85.4));
	students.push_back(Student("Akane", 1, 80.5, 80.0));
	students.push_back(Student("Arima", 2, 88.0, 91.2));
	students.push_back(Student("Polnaref", 2, 65.5, 89.9));
	students.push_back(Student("Alhaitham", 2, 84.3, 87.7));
	students.push_back(Student("Sivukhin", 2, 91.8, 90.0));
	students.push_back(Student("Landau", 2, 86.6, 83.5));

	printList(students);

	cout << dye::light_blue("----- Sorted List Alphabetically -----") << endl;
	students.sort(surnamePredicate);
	printList(students);

	cout << dye::light_red("----- Sorted List By Year -----") << endl;
	students.sort(yearPredicate);
	printList(students);

	transfer(students);
	cout << dye::light_yellow("----- Transferred -----") << endl;
	printList(students);


	students.remove_if(deletePredicate);
	cout << dye::red("----- List After Deleting Students -----") << endl;
	printList(students);

}
