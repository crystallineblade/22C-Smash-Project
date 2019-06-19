#pragma once

template <typename T>
struct Node
{
	// generic data type T containing data
	T data;

	// pointer to the next Node<T> in the list
	Node<T> *next;

	Node() {
		next = NULL;
	}
};