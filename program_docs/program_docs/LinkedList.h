/* Written by Justin Quan and Julia Shuieh
*/

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"


template <typename T>
class LinkedList
{
private:
	// int that represents how many Nodes are inside the list (not including head)
	int count;
	// Node<T> pointer for head pointer, which points to the first data node
	Node<T> *head;
public:
	/* 
	This default constructor initializes LinkedList. It defines count to be 0 and the head pointer points to NULL.
	*/
	LinkedList();

	/*
	This copy constructor initialized LinkedList using an existing LinkedList.
	*/
	LinkedList(const LinkedList<T> &l);

	/*
	This deconstructor frees each node pointer from memory.
	*/
	~LinkedList();

	/* This function creates a new Node<T> containing the specified data and points to NULL.
	Pre: d - data of generic data type T that is to be put in the new node
	Post: a new Node<T> object is created
	Return: a pointer to the Node<T> object
	*/
	Node<T>* newNode(T d);

	/* This function creates a new Node<T> object with the specified data and adds it in the list at the specified position.
	Pre: pos - an integer representing the position of the new Node<T> object. It must be greater than 0 and less than/equal to count + 1.
		 data - data of generic data type T that is to be put in the new node
	Post: a Node<T> object containing data is inserted in the list at position pos
	*/
	void insert(int pos, T data);

	/* This function creates a new Node<T> object with the specified data and adds it to the front of the list.
	Pre: data - data of a generic data type T that is to be put in the new node
	Post: a Node<T> object containing data is inserted in the beginning of the list
	*/
	void insertFirst(T data);

	/* This function creates a new Node<T> object with the specified data and adds it to the end of the list.
	Pre: data - data of a generic data type T that is to be put in the new node
	Post: a Node<T> object containing data is inserted in the end of the list
	*/
	void insertLast(T data);

	/* This function removes a node from the list at position pos and returns the data contained in that node.
	Pre: pos - an integer representing the position of the new Node<T> object. It must be greater than 0 and less than/equal to count.
		 the list must contain nodes other than head
	Post: the Node<T> object at position pos is removed from the list
	Return: the data of generic data type T that was contained in the removed node.
	*/
	T remove(int pos);

	/* This function removes the node at the front of the list and returns the data contained.
	Pre: the list must contain nodes other than head
	Return: the data of generic data type T that was contained in the removed node.
	*/
	T removeFirst();

	/* This function removes the node at the end of the list and returns the data contained.
	Pre: the list must contain nodes other than head
	Return: the data of generic data type T that was contained in the removed node.
	*/
	T removeLast();

	/* This function searches for the specified data and returns the position of the Node in the list. If it is not in the list, it 
		returns -1
	Pre: d - data of generic data type T that is searched for inside the list
	Return: position of node containing data d, or -1 if not found
	*/
	int find(T d);

	Node<T>* search(T d);

	/* This function removes all nodes in the list (except for the head node).
	Post: all Node<T> objects following the head node are removed from the list.
	*/
	void empty();

	/* This function returns how many nodes (other than head) are inside the list.
	Return: an integer
	*/
	int getCount();

	/* This function returns the node pointer to the head node.
	Return: Node<T> pointer
	*/
	Node<T>* getHead();

	/* This function returns the data at the specified position.
	Pre: pos - an int representing the position of the data, and must be between 1 and count inclusive
	Return: data of generic type T in node at position pos 
	*/
	T getData(int pos);

	/* This function returns a pointer to the node at the specified position.
	Pre: pos - an int representing the position of the node, and must be between 1 and count inclusive
	Return: pointer to Node<T> object
	*/
	Node<T>* getNode(int pos);

	void printList(std::ostream output);

	/* This overloaded output stream operator send data from each node to the output stream.
	Pre: output - ostream that the data is sent to
		 l - LinkedList with generic datatype
	Post: output has the data from LinkedList<U> l
	Return: ostream object
	*/
	template<typename U>
	friend std::ostream &operator<<(std::ostream& output, LinkedList<U>& l);
};

template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
	head = newNode(T());
	head->next = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &l) {
	count = l.count;
	head = l.head;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	empty();
	free(head);
}

template <typename T>
Node<T>* LinkedList<T>::newNode(T d) {
	Node<T>* newNode = new Node<T>();
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

/* 
Pseudocode:

Create pointer to node pointer called curr and points it to head
if (position is in bounds, ie between 1 and count + 1 inclusive)
	loop (decrement position by one to go through list)
		if (reached specified position)
			Create a new node with data
			Set new node's pointer to the node at the current position
			Set pointer for the current node to the new node
		end if
		else 
			set pointer curr to the next node pointer
		end else
	end loop
	increment count of nodes by one
end if

*/
template <typename T>
void LinkedList<T>::insert(int pos, T d) {
	Node<T>** curr = &head;
	if (pos > 0 && pos <= count + 1)
	{
		while (pos--) {

			if (pos == 0) {
				Node<T>* temp = newNode(d);
				temp->next = (*curr)->next;
				(*curr)->next = temp;
			}
			else  
				curr = &(*curr)->next;
		}
		count++;
	}
	else {
		throw "Position out of bounds.";
	}
}

template <typename T>
void LinkedList<T>::insertFirst(T d) {
	insert(1, d);
}

template <typename T>
void LinkedList<T>::insertLast(T d) {
	insert(count + 1, d);
}

/*
Psuedocode:

Create pointer to node pointer called curr and sets it to point
Declare data of generic type T
if (position is in bounds, ie between 1 and count inclusive)
	loop (decrement position by one to go through list)
		if (reached specified position)
			Create node pointer and set it to node pointer of current node
			Set data to current node data
			Set next node to the node after node that is to be removed
			Free current node memory
		end if
		else 
			Set pointer curr to the next node
		end else
	end loop
	decrement count by one
end if
return node data

*/
template <typename T>
T LinkedList<T>::remove(int pos) {
	Node<T>** curr = &head;
	T data;
	if (pos > 0 && pos <= count)
	{
		while (pos--) {

			if (pos == 0) {
				Node<T>* temp = (*curr)->next;
				data = temp->data;
				(*curr)->next = temp->next;
				free(temp);
			}
			else
				curr = &(*curr)->next;
		}
		count--;
	}
	else {
		throw "Position out of bounds.";
	}
	return data;
}

template <typename T>
T LinkedList<T>::removeFirst() {
	return remove(1);
}

template <typename T>
T LinkedList<T>::removeLast() {
	return remove(count);
}

/*
Pseudocode:

Create node pointer and sets it to next node after head
Declare position variable and set it to 1
loop (when node pointer is not null to go through list)
	if (node data is equal to specified data)
		return true
	end if
	Set current node to next node
	Increment position by one
end loop
return -1

*/
template <typename T>
int LinkedList<T>::find(T d) {
	Node<T>* curr = head->next;
	int position = 1;
	while (curr != NULL) {
		if (curr->data == d) {
			return position;
		}
		curr = curr->next;
		position++;
	}
	return -1;
}

template <typename T>
void LinkedList<T>::empty() {
	while (count > 0)
	{
		remove(1);
	}
}

template <typename T>
int LinkedList<T>::getCount() {
	return count;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() {
	return head;
}

/*
Pseudocode:

Declare pointer to Node<T> object and set it to the node after head
if (pos is out of bounds)
	throw an exception
end if 
else
	loop (decrement pos by one to go through list)
		if (current node is at the specified pos)
			return data in node
		end if
		set current node to next node
	end loop
end else
*/
template <typename T>
T LinkedList<T>::getData(int pos) {
	Node<T>* curr = head->next;
	if (pos <= 0 || pos > count) {
		throw "Position out of bounds.";
	}
	else {
		while (pos--) {
			if (pos == 0) {
				return curr->data;
			}
			curr = curr->next;
		}
	}
	return T();
}

/*
Pseudocode:

Declare pointer to Node<T> object and set it to next node after head
if (pos is out of bounds)
	throw an exception
end if 
else 
	loop (decrement pos by one to go through whole list)
		if (current node is at specified pos)
			return current node
		end if
	end loop
end else
return new pointer
*/
template <typename T>
Node<T>* LinkedList<T>::getNode(int pos) {
	Node<T>* curr = head->next;
	if (pos <= 0 || pos > count) {
		throw "Position out of bounds.";
	}
	else {
		while (pos--) {
			if (pos == 0) {
				return curr;
			}
			curr = curr->next;
		}
	}
	return new Node<T>;
}

/*
Pseudocode:
Declare a pointer to node of generic type U and set it to the node after head
loop (when pointer is not null to go through entire list)
	Send node data to output stream
	Set pointer to next node
end loop
return output stream
*/
template <typename U>
std::ostream &operator<<(std::ostream& output, LinkedList<U>& l) {
	Node<U>* curr = (l.getHead())->next;
	while (curr != NULL) {
		output << curr->data << " ";
		curr = curr->next;
	}
	return output;
}

template <typename T>
Node<T>* LinkedList<T>::search(T data) {
	int index = find(data);
	remove(index);
	insertFirst(data);
	return head->next;
}

template <typename T>
void LinkedList<T>::printList(std::ostream output) {
	Node<T>* curr = head;
	while (curr != NULL) {
		output << curr->data;
		curr = curr->next;
		output << std::endl;
	}
}
#endif