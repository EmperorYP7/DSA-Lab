#include "Node.hpp"

Node::Node()
	:data(0), previous(nullptr), next(nullptr)
{}

void Node::Insert(int& newdata)
{
	data = newdata;
}

void Node::SetNext(Node* newnext)
{
	next = newnext;
}

void Node::SetPrevious(Node* newprevious)
{
	previous = newprevious;
}

int Node::GetData()
{
	return data;
}

Node* Node::GetNext()
{
	return next;
}

Node* Node::GetPrevious()
{
	return previous;
}