#include <iostream>


struct Node {
public:
	//variables
	int data;
	Node* next;

	//Node constructor
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}

	//Print function
	const void Print() 
	{
		std::cout << data;
		if (next != nullptr)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
};

class LinkedList {
private:
	Node* head, * tail;

public:
	LinkedList() { head = nullptr; tail = nullptr; }

	void Add(int data)
	{
		Node* temp = new Node(data);
		
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void Print()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp->Print();
				temp = temp->next;
			}
			temp->Print();
		}
		else
			std::cout << "LinkedList is empty!" << std::endl;
	}
};



int main()
{
	//create linked list
	LinkedList* linkedlist = new LinkedList();

	//add node to linked list
	linkedlist->Add(5);
	linkedlist->Add(7);
	linkedlist->Add(99);
	linkedlist->Add(24);
	linkedlist->Add(69);

	//print linked list
	linkedlist->Print();

	//delete node from linked list

	return 0;
}