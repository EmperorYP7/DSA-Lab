#pragma once

class LinkedList
{
private:
	static Node* front;
	static Node* last;

public:
	LinkedList();
	static void NewBegin(int&);
	static void NewEnd(int&);
	static void NewPos(int&, int&);
	static void Delete(int&);
	static void DeletePos(int&);
	static void Display();
};
