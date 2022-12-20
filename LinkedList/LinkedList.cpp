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
	int size = 0;

public:
	LinkedList() { head = nullptr; tail = nullptr; }

	//Adds node as the head (if not created) or end of the list
	void Add(int data)
	{
		Node* temp = new Node(data);

		if (head == nullptr)
			head = temp;
		else
			tail->next = temp;

		//tail is the latest node added
		tail = temp;

		size++;
	}

	//Deletes node on given index (starts at 0)
	void Delete(int index)
	{
		//Change head if index 0
		if (index == 0)
		{
			Node* temp = head;
			head = head->next;

			//free up space
			delete temp;
			size--;
			return;
		}

		//find node to delete
		Node* prev, *temp;
		prev = head;
		temp = head;

		for (int i = 0; i < index; i++)
		{
			prev = temp;
			temp = temp->next;
		}
		
		//truncate previous with next node
		prev->next = temp->next;
		
		//delete on index (frees up space)
		delete temp;

		size--;
	}

	//Prints data of all nodes
	void Print()
	{
		if (size > 0)
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

	//Size of linked list
	int Size() { return size; }
};



int main()
{
	//create linked list
	LinkedList* linkedList = new LinkedList();

	//add node to linked list
	linkedList->Add(5);
	linkedList->Add(77);
	linkedList->Add(8);
	linkedList->Add(24);
	linkedList->Add(69);

	//print linked list
	std::cout << "Size: " << linkedList->Size() << std::endl;
	linkedList->Print();

	//delete node from linked list
	linkedList->Delete(2);

	//print linked list
	std::cout << "Size: " << linkedList->Size() << std::endl;
	linkedList->Print();

	return 0;
}