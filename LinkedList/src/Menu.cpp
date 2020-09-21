#include <iostream>

#include "Menu.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"

void Menu()
{
	system("cls");
	std::cout << "\n------------------------------MENU------------------------------";
	std::cout << "\n 1. View List\n 2. Add to end of list\n 3. Add from begining of list\n 4. Add in position\n 5. Delete position\n 6. Delete element\n 7. Exit";
	std::cout << "\n Enter your choice.. ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: LinkedList::Display();
		std::cin.get(); 
		break;
	case 2: std::cout << "\n Enter a value to add to end of list : ";
		int value1;
		std::cin >> value1;
		LinkedList::NewEnd(value1);
		std::cin.get();
		break;
	case 3: std::cout << "\n Enter a value to add to begining of list : ";
		int value2;
		std::cin >> value2;
		LinkedList::NewBegin(value2);
		std::cin.get();
		break;
	case 4: std::cout << "\n Enter the position you want to add in : ";
		int pos1;
		std::cin >> pos1;
		std::cout << "\n Enter a value to add to end of list : ";
		int value3;
		std::cin >> value3;
		LinkedList::NewPos(pos1, value3);
		std::cin.get();
		break;
	case 5: std::cout << "\n Enter the position you want to delete from list : ";
		int pos;
		std::cin >> pos;
		LinkedList::DeletePos(pos);
		std::cin.get();
		break;
	case 6: std::cout << "\n Enter the value you want to delete from list : ";
		int value;
		std::cin >> value;
		LinkedList::Delete(value);
		std::cin.get();
		break;
	case 7: return;
	default: std::cout << "\n Invalid Entry! Try again";
		std::cin.get();
		std::cin.get();
	}
	Menu();
}
