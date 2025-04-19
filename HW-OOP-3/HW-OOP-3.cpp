#include <iostream>
#include <list>
#include "color.hpp"

using namespace std;

bool lastDigitPredicate(int number) { return number % 10 > 4; }

static void printList(list<int>& list)
{
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	list<int> list;
	int input;
	cout << dye::yellow("----- Filling in the list -----") << endl;
	do
	{
		cout << "Enter value: ";
		cin >> input;
		list.push_back(input);
	} while (input);

	cout << dye::green("----- List Output -----") << endl;
	printList(list);

	for (int i = 0; i < 3; i++)
	{
		list.push_front(rand() % 25);
	}

	cout << dye::red("\n----- List Output After PUSH-FRONT -----") << endl;
	printList(list);
	
	list.sort();
	cout << dye::blue("\n----- Sorted List -----") << endl;
	printList(list);

	list.pop_front();
	cout << dye::light_aqua("\n----- List POP-FRONT -----") << endl;
	printList(list);

	cout << endl << dye::light_blue("Front list element: ") << list.front() << endl;

	list.pop_back();
	cout << dye::light_green("\n----- List POP-BACK -----") << endl;
	printList(list);

	cout << endl << dye::purple("Back list element: ") << list.back() << endl;
	cout << endl << dye::light_red("List size: ") << list.size() << endl;

	list.remove(0);
	cout << dye::aqua("\n----- Deleting all ZEROS -----") << endl;
	printList(list);

	list.remove_if(lastDigitPredicate);
	cout << dye::light_purple("\n----- Deleting all number with last digit greater than 4 -----") << endl;
	printList(list);

}
