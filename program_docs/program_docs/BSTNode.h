#pragma once

template <typename T, typename U>
struct BSTNode {

	// first data stored in node, birthday for Lab 5
	T data1;

	// second data stored in node, name for Lab 5
	U data2;



	// pointer to the left node, data is less than current node
	BSTNode<T, U>* left;
	
	// pointer to the right node, data is greater than current node
	BSTNode<T, U>* right;

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
