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

void LinkedList::New(int& data)
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
