#include <iostream>
#include <memory>

#include "Node.hpp"
#include "LinkedList.hpp"

Node* LinkedList::front;
Node* LinkedList::last;

LinkedList::LinkedList()
{
	front = nullptr;
	last = nullptr;
}

void LinkedList::NewEnd(int& data)
{
	Node* Newptr = new Node;
	if (Newptr == nullptr)
	{
		std::cout << "\nUnable to allocate memory! Insertion is aborted..";
		std::cin.get();
		return;
	}
	Newptr->Insert(data);
	if (front == nullptr)
	{
		front = Newptr;
		last = Newptr;
	}
	else
	{
		Newptr->SetPrevious(last);
		last = Newptr;
		Newptr->SetNext(nullptr);
		Newptr->GetPrevious()->SetNext(Newptr);
	}
	std::cout << "\nInsertion was successful!";
	std::cin.get();
}

void LinkedList::NewBegin(int& data)
{
	Node* Newptr = new Node;
	if (Newptr == nullptr)
	{
		std::cout << "\nUnable to allocate memory! Insertion is aborted..";
		std::cin.get();
		return;
	}
	Newptr->Insert(data);
	if (front == nullptr)
	{
		front = Newptr;
		last = Newptr;
	}
	else
	{
		Newptr->SetNext(front);
		front->SetPrevious(Newptr);
		front = Newptr;
	}
	std::cout << "\nInsertion was successful!";
	std::cin.get();
}

void LinkedList::NewPos(int& pos, int& data)
{
	Node* Newptr = new Node;
	if (Newptr == nullptr)
	{
		std::cout << "\nUnable to allocate memory! Insertion is aborted..";
		std::cin.get();
		return;
	}
	Newptr->Insert(data);
	if (front == nullptr)
	{
		if (pos != 1)
		{
			std::cout << "\nThe list is empty. Can't insert in " << pos;
			std::cout << "\nInserting " << data << " in the list..";
		}
		front = Newptr;
		last = Newptr;
	}
	else
	{
		int i = 0;
		for (auto iterator = front; iterator != nullptr; iterator = iterator->GetNext())
		{
			if (i == pos - 1)
			{
				if (iterator == front)
				{
					front->SetPrevious(Newptr);
					Newptr->SetNext(front);
					front = Newptr;
				}
				else if (iterator == last)
				{
					last->SetNext(Newptr);
					Newptr->SetPrevious(last);
					last = Newptr;
				}
				else
				{
					if (iterator->GetPrevious() != nullptr)
					{
						iterator->GetNext()->SetPrevious(Newptr);
						Newptr->SetNext(iterator->GetNext());
						iterator->SetNext(Newptr);
						Newptr->SetPrevious(iterator);
					}
				}
			}
			++i;
		}
	}
	std::cout << "\nInsertion was successful!";
	Display();
	std::cin.get();
}

void LinkedList::Display()
{
	if (front == nullptr)
	{
		std::cout << "\nThe list is empty! First add something to the list to view it.";
		std::cin.get();
		return;
	}
	std::cout << "\nThe current state of LinkedList is : ";
	for (auto iterator = front; iterator != nullptr; iterator = iterator->GetNext())
		std::cout << iterator->GetData() << " ";
	std::cin.get();
}

void LinkedList::Delete(int& data)
{
	if (front == nullptr)
	{
		std::cout << "\nThe list is empty. Can't delete from empty list.";
		std::cin.get();
		return;
	}
	Node* ToDelete = nullptr;
	for (auto iterator = front; iterator != nullptr; iterator = iterator->GetNext())
		if (iterator->GetData() == data)
		{
			ToDelete = iterator;
			break;
		}
	if (ToDelete == nullptr)
	{
		std::cout << "\n The entered element " << data << " was not found in the list. Aborting the deletion..";
		delete ToDelete;
		std::cin.get();
		return;
	}
	if (ToDelete == front)
	{
		front = ToDelete->GetNext();
		front->SetPrevious(nullptr);
		delete ToDelete;
	}
	else if (ToDelete == last)
	{
		last = ToDelete->GetPrevious();
		last->SetNext(nullptr);
		delete ToDelete;
	}
	else
	{
		if(ToDelete->GetPrevious() != nullptr)
			(ToDelete->GetPrevious())->SetNext(ToDelete->GetNext());
		if (ToDelete->GetNext() != nullptr)
			(ToDelete->GetNext())->SetPrevious(ToDelete->GetPrevious());
		delete ToDelete;
	}
	std::cout << "\nDeletion successful!";
	Display();
}

void LinkedList::DeletePos(int& pos)
{
	int i = 0;
	for (auto iterator = front; iterator != nullptr; iterator = iterator->GetNext())
	{
		if (i == pos - 1)
		{
			if (iterator == nullptr)
			{
				std::cout << "\n The entered element " << pos << " was not found in the list. Aborting the deletion..";
				delete iterator;
				std::cin.get();
				return;
			}
			if (iterator == front)
			{
				front = iterator->GetNext();
				front->SetPrevious(nullptr);
				delete iterator;
			}
			else if (iterator == last)
			{
				last = iterator->GetPrevious();
				last->SetNext(nullptr);
				delete iterator;
			}
			else
			{
				if (iterator->GetPrevious() != nullptr)
					(iterator->GetPrevious())->SetNext(iterator->GetNext());
				if (iterator->GetNext() != nullptr)
					(iterator->GetNext())->SetPrevious(iterator->GetPrevious());
				delete iterator;
			}
			std::cout << "\nDeletion successful!";
			Display();
			return;
		}
		++i;
	}
}