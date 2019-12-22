#ifndef __TNode__
#define __TNode__
#include <iostream>

template <class T>
class TNode
{
public:

	T m_data;
	TNode<T>* next;			//NOTE::: We need to define TNode as type T, this is why we have <T> after TNode


};

template <class T>
class List
{
private:
	TNode<T>* m_head, * m_tail; // pointer to 1st and last node in list

public:
	List();//Constructor

	/*Member function declarations*/
	void Insert(T data); // add a new node to the end of the list
	void Delete(); // delete a node at the end
	T Get(T node_number); // get some data from the list e.g. 5th item etc
	void Print();

	~List()
	{
		std::cout << "Class List destructor being called\n\n";
		TNode<T>* curr = new TNode<T>;
		curr = m_head;
		while (m_head->next != NULL)
		{
			while (curr->next != m_tail)
			{
				curr = curr->next;
			}

			curr->next = NULL;
			delete m_tail;
			m_tail = curr;
			curr = m_head;
		}
			
		m_tail = NULL; curr = NULL;
		delete m_head, m_tail, curr;
	
	};


};

/******* Member function definitions ********/
template <class T>
void List<T>::Insert(T data)
{
	TNode<T>* temp = new TNode<T>;
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

}

template <class T>
void List<T>::Delete()
{
	TNode<T>* curr = new TNode<T>;
	TNode<T>* prev = new TNode<T>;
	curr = m_head;

	while (curr->next != NULL)		//Go to the end of the list
	{
		prev = curr;
		curr = curr->next;
	}

	m_tail = prev;				//Set tail pointer to node second from end
	prev->next = NULL;			//Set prev to be the end of the list

	delete curr;				//Free dangling Node from memory


}

template <class T>
T List<T>::Get(T node_number)
{
	TNode<T>* curr = new TNode<T>;
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
		return curr->mdata;
	}
	else
		std::cout << "List index is out of range..\n\n";

}

template <class T>
void List<T>::Print()
{
	TNode<T>* curr = new TNode<T>;

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

template <class T>
List<T>::List()
{
	std::cout << "template class List Constructor being called...\n\n";
	m_head = NULL;
	m_tail = NULL;
}


#endif
