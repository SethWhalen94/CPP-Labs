#ifndef __Node__
#define __Node__

class Node
{
public:

	int m_data;
	Node* next;

};

class List {
private:
	Node* m_head, *m_tail; // pointer to 1st node in list

public:
	List();
	//List(int data); // default constructor sets ptr to null
	void Insert(int data); // add a new node to the end of the list
	void Delete(); // delete a node at the end
	void Get(int element); // get some data from the list e.g. 5th item etc
	void print();

	~List();
};



#endif // !__Node__

