// main.cpp
#pragma once

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

	int size;
	Node *root;
	//Set the first node to a value
	//void initializeNode(int n);
	public:

	LinkedList();
	void insert(T n);
	void push_front(T n);
	void push_back(T n);
	void pop_front();
	void pop_back();
	void erase(T n);

};

template <typename T>
//Initialize
LinkedList<T>::LinkedList(){
	size = 0;
	x_head = nullptr;
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
	head = newNode;
	++size;
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
		head = newNode;
	}
	else
	{
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	++size;
}
//Remove the first element of the list
template <typename T>
void LinkedList<T>::pop_front()
{
	if (size == 0)
		return;
	Node<T>* tmp = root->next;
	delete root;
	root = tmp;
	--size;
}
//Remove the last element of the list
template <typename T>
void LinkedList<T>::pop_back()
{
	if (size == 0) return;
	--size;

	Node<T>* tmp = root;
	Node<T>* tmp2 = nullptr;

	while (tmp->next != nullptr)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	delete tmp;
	tmp2->next = nullptr;

}
//A specific value, or index of a node that is to be erased. 
template <typename T>
void LinkedList<T>::erase(T n)
{
	Node<T>* tmp = root;
	
	while (tmp->next != nullptr)
	{

	}
}

int main(int argc, char* argv[])
{
	
	return 0;
}