#pragma once

class LinkedList
{
private:
	static Node* front;
	static Node* last;

public:
	LinkedList();
	static void New(int&);
	static void Delete(int&);
	static void Display();
};
