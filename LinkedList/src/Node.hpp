#pragma once

class Node
{
public:
	Node();

	void Insert(int&);
	void SetPrevious(Node*);
	void SetNext(Node*);

	Node* GetNext();
	Node* GetPrevious();
	int GetData();

private:
	int data;
	Node* previous;
	Node* next;
};