#include <iostream>

#include "Menu.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"

void Menu()
{
	system("cls");
	std::cout << "\n------------------------------MENU------------------------------";
	std::cout << "\n 1. View List\n 2. Add to list\n 3. Delete from list\n 4. Exit";
	std::cout << "\n Enter your choice.. ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: LinkedList::Display(); 
		std::cin.get(); 
		break;
	case 2: std::cout << "\n Enter a value to add to list : ";
		int value1;
		std::cin >> value1;
		LinkedList::New(value1);
		std::cin.get();
		break;
	case 3: std::cout << "\n Enter the value you want to delete from list : ";
		int value;
		std::cin >> value;
		LinkedList::Delete(value);
		std::cin.get();
		break;
	case 4: return;
	default: std::cout << "\n Invalid Entry! Try again";
		std::cin.get();
		//cin.get();
	}
	Menu();
}