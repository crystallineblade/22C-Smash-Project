/* Written by Justin Quan
*/

#pragma once

template <typename T>
struct BSTNode {

	T data1;

	// pointer to the left node, data is less than current node
	BSTNode<T>* left;
	
	// pointer to the right node, data is greater than current node
	BSTNode<T>* right;

	/*
	This constructor initializes the pointers for the left and right nodes to be NULL.
	Post: left and right node pointers are set to NULL
	*/
	BSTNode() {
		left = NULL;
		right = NULL;
	}

	/*
	This deconstructor deletes the pointers for the left and right nodes.
	Post: left and right node pointers deleted
	*/
	~BSTNode() {
		delete left;
		delete right;
	}
	
};
