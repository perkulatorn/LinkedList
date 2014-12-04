// main.cpp
#pragma once
#include <assert.h>
#include <iostream>

template <typename T>
struct Node{
	
	T data;
	
	Node *next;

	Node()
	{
		next = nullptr;

	}
};

template <typename T>
class LinkedList{

	int m_size;
	Node<T> *root;
	//Set the first node to a value
	//void initializeNode(int n);
	public:

	LinkedList();
	void insert(T n);
	void push_front(T n);
	void push_back(T n);
	void pop_front();
	void pop_back();
	void erase(int index);
	int size();
	bool search(T n); 

	//Anthon Fredrikssons kod, thanks bruv.
	T& operator[](int i)
	{
		return at(i);
	}

	T& at(int i)
	{
		if (i >= m_size)
		{
			std::cout << "at(" << i << ") size " << m_size << ", returning last element" << std::endl;
			i = m_size - 1;
		}
		std::size_t c = 0;
		Node<T>* tmp = root;
		while (tmp != nullptr)
		{
			if (c == i)
				return tmp->data;
			tmp = tmp->next;
			++c;
		}
	}

};

template <typename T>
//Initialize
LinkedList<T>::LinkedList(){
	m_size = 0;
	root = nullptr;
}
//Insert an element into an index (currently does that same as push_back) <-- Note to self
template <typename T>
void LinkedList<T>::insert(T n) {
	//Node<T> *newNode = new Node<T>;
	//newNode->data = n;
	//newNode->next = nullptr;

	//Node *current = root;
	//while (current) {
	//	//Note to self -> byter 'next länken' varje loop
	//	if (current->next == nullptr) {
	//		current->next = newNode;
	//		return;
	//	}
	//	current = current->next;
	//}
	//++size;
}
//Add an element at the front of the list
template <typename T>
void LinkedList<T>::push_front(T n)
{
	Node<T> *newNode = new Node<T>;
	newNode->data = n;
	newNode->next = root;
	root = newNode;
	std::cout << "Added a new node, node: " << n << " at the front of the list" << std::endl;
	++m_size;
}
//Add an element at the end of the list
template <typename T>
void LinkedList<T>::push_back(T n)
{
	Node<T>* tmp = root;
	Node<T>* newNode = new Node<T>;
	newNode->data = n;
	if (tmp == nullptr)
	{
		root = newNode;
	}
	else
	{
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	std::cout << "Added a new node, node: " << n << " at the back of the list." << std::endl;
	++m_size;
}
//Remove the first element of the list
template <typename T>
void LinkedList<T>::pop_front()
{
	if (m_size == 0)
		return;
	Node<T>* tmp = root->next;
	std::cout << "Removing the first node of the list, Data: " << root->data << std::endl;
	delete root;
	root = tmp;
	--m_size;
}
//Remove the last element of the list
template <typename T>
void LinkedList<T>::pop_back()
{
	if (m_size == 0) return;
	//Specialcase in case you have only one element in the list
	if (m_size-- == 1)
	{
		delete root;
		root = nullptr;
		return;
	}

	Node<T>* tmp = root;
	Node<T>* tmp2 = nullptr;

	while (tmp->next != nullptr)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		
	}
	std::cout << "Removing the last node of the list, Data: " << tmp->data << std::endl;
	delete tmp;
	tmp2->next = nullptr;

}
//A specific value, or index of a node that is to be erased. 
template <typename T>
void LinkedList<T>::erase(int index)
{
	Node<T>* tmp = root;
	Node<T>* tmp2 = nullptr;

	int counter = 0;
	//Special case if the index is the root
	if (index == 0)
	{
		root = tmp->next;
		delete tmp;
		--m_size;
		std::cout << "Erased index " << index << std::endl;
		return;

	}
	while (tmp != nullptr)
	{
		if (counter == index)
		{
			tmp2->next = tmp->next;
			delete tmp;
			--m_size;
			std::cout << "Erased index " << index << std::endl;
			return;
		}

		tmp2 = tmp;
		tmp = tmp->next;
		
		++counter;
	}
}
//Returns the size of the linkedlist
template <typename T>
int LinkedList<T>::size()
{
	return m_size;
}
//Searches the linkedlist for a specific value
template <typename T>
bool LinkedList<T>::search(T n)
{
	Node<T>* node = root;
	int counter = 0;
	while (node != nullptr)
	{
		if (node->data == n)
		{
		 std::cout << "You found " << n << " on the " << counter << "th node of the linked list" << std::endl;
		 return true;
		}
		node = node->next;
		counter++;
	}
	std::cout << n << " does not exist in the linked list" << std::endl;
	return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// UNIT TESTING ////////////////////////////////////////////////////////////////////////

void testPushFront()
{
	LinkedList<int> list;
	list.push_front(1);
	assert(list[0] == 1);
	list.push_front(2);
	assert(list[0] == 2);
	list.push_front(3);
	assert(list[0] == 3);
	list.push_front(4);
	assert(list[0] == 4);
	list.push_front(5);
	assert(list[0] == 5);
}

void testPushBack()
{
	LinkedList<int> list;
	list.push_back(1);
	assert(list[list.size() - 1] == 1);
	list.push_back(2);
	assert(list[list.size() - 1] == 2);
	list.push_back(3);
	assert(list[list.size() - 1] == 3);
	list.push_back(4);
	assert(list[list.size() - 1] == 4);
	list.push_back(5);
	assert(list[list.size() - 1] == 5);
}


void testPopFront()
{
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);


	assert(list[0] == 1);
	list.pop_front();
	assert(list[0] == 2);
	list.pop_front();
	assert(list[0] == 3);
	list.pop_front();
	assert(list[0] == 4);
	list.pop_front();
	assert(list[0] == 5);
	list.pop_front();
	assert(list.size() == 0);
}


void testPopBack()
{
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	assert(list[list.size() - 1] == 5);
	list.pop_back();
	assert(list[list.size() - 1] == 4);
	list.pop_back();
	assert(list[list.size() - 1] == 3);
	list.pop_back();
	assert(list[list.size() - 1] == 2);
	list.pop_back();
	assert(list[list.size() - 1] == 1);
	list.pop_back();
	assert(list.size() == 0);
}

void testErase()
{
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	assert(list[0] == 1);
	list.erase(0);
	assert(list[0] == 2);
	list.erase(0);
	assert(list[0] == 3);
	list.erase(0);
	assert(list[0] == 4);
}

void testSearch()
{
	LinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	assert(list.search(1) == true);
	assert(list.search(2) == true);
	assert(list.search(3) == true);
	assert(list.search(4) == true);
}

void testSize()
{
	LinkedList<int> list;

	assert(list.size() == 0);
	list.push_back(1);

	assert(list.size() == 1);
	list.push_back(2);
	list.push_back(3);

	assert(list.size() == 3);
	list.erase(2);

	assert(list.size() == 2);
}


int main(int argc, char* argv[])
{
	testPushFront();
	testPushBack();
	testPopFront();
	testPopBack();
	testErase();
	testSearch();
	testSize();

	std::cout << "Eureka!" << std::endl;

	return 0;
}