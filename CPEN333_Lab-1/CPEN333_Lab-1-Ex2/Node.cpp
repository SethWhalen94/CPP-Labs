#include "Node.h"
#include <iostream>
#include <stdio.h>

/*Constructor*/
List::List() { m_head = NULL; m_tail = NULL;
std::cout << "Node constructor being called \n\n"; }

//List::List(int data = 0) : m_data(data) 
//{
//	std::cout << "Node constructor being call with data = " << data << "\n\n";
//}
/*End of constructors*/

/*Node member function definitions*/

void List::Insert(int data)
{
	Node *temp = new Node;
	temp->m_data = data;
	temp->next = NULL;

	if (m_head == NULL)		//No items in the linked list
	{
		m_head = temp;
		m_tail = temp;
		temp = NULL;
	}
	else
	{
		m_tail->next = temp;
		m_tail = temp;		//set tail node equal to the new node
	}
};
void List::Delete()
{
	Node* curr = new Node;
	Node* prev = new Node;
	curr = m_head;

	while (curr->next != NULL)		//Go to the end of the list
	{
		prev = curr;
		curr = curr->next;
	}

	m_tail = prev;				//Set tail pointer to node second from end
	prev->next = NULL;			//Set prev to be the end of the list

	delete curr;				//Free dangling Node from memory

};
void List::Get(int node_number)
{
	Node* curr = new Node;
	curr = m_head;
	int i = 0;
	bool found = false;
	while (curr != NULL)
	{
		if (i == node_number)
		{
			found = true;
			break;
		}
		else
		{
			curr = curr->next;
			i++;
		}
	}

	if (found)
	{
		std::cout << "The value at list location " <<
			node_number <<
			" is " <<
			curr->m_data << "\n\n";
	}
	else
		std::cout << "List index is out of range..\n\n";
};

void List::print()
{
	Node* curr = new Node;

	curr = m_head;

	std::cout << "-------------------------------------------------------------\n";
	std::cout << "--------------Displaying All nodes in list ------------------\n";
	std::cout << "-------------------------------------------------------------\n";

	while (curr != NULL)
	{
		std::cout << curr->m_data << '\t';
		curr = curr->next;
	}
	std::cout << "\n-------------------------------------------------------------\n\n";


}

/* End of definitions */

List::~List() {};


int main()
{
	List L1;
	L1.Insert(1);
	L1.print();
	L1.Insert(2);
	L1.Insert(3);
	L1.print();
	L1.Insert(4);
	L1.print();
	L1.Delete();
	L1.Insert(10);
	L1.Get(3);
	L1.print();


	return 0;
}