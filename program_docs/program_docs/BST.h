#pragma once
#include <iostream>
#include "BSTNode.h"

template <typename T, typename U>
class BST {
protected:
	// node pointer to the root node
	BSTNode<T, U>* root;

	// boolean representing which data is used to sort (true means sorted by data1, false means sorted by data2)
	bool first;

	/*
	This function finds the node with the smallest value; used in the remove function.
	Pre: curr - the current node processed
	Return: node pointer containing the smallest data
	*/
	BSTNode<T, U>* minValue(BSTNode<T, U>* curr);

public:
	/*
	This constructor initializes the first boolean and the root node.
	Pre: f - a boolean representing if the tree is sorted by the first data type (data1)
	Post: root node pointer is set to NULL and first is set to f
	*/
	BST(bool f) {
		root = NULL;
		first = f;
	}

	/*
	This deconstructor deletes the pointer to the root node.
	Post: root node pointer deleted
	*/
	~BST() {
		delete root;
	}

	/*
	This function returns a pointer to a new node containing the two data variables entered.
	Pre: d1 - the first data (data1) to be added in the new node
		 d2 - the second data (data2) to be added in the new node
	Return: a node pointer to the new BSTNode object
	*/
	BSTNode<T, U>* newNode(T d1, U d2);

	/*
	This function inserts a node into the tree at its sorted place with the entered data.
	Pre: curr - a reference to a node pointer that shows current node in traversal
		 data1 - the first data to be added in the new node
		 data2 - the second data to be added in the new node
	Post: new node inserted into BST
	*/
	void insert(BSTNode<T, U>* &curr, T data1, U data2);

	/*
	This function searches for a node in a BST that matches the entered data.
	Pre: curr - a node pointer that shows current node in traversal
		 data1 - the first data to be compared with other nodes data1
		 data2 - the second data to be compared with other nodes data2
	Return: a node that matches the data enter (or NULL if not found)
	*/
	BSTNode<T,U>* search(BSTNode<T, U>* curr, T data1, U data2);

	/*
	This function searches for a node in a BST that matches the entered data.
	Pre: curr - a node pointer that shows current node in traversal
		 data1 - data to be compared with other nodes data1
	Return: data2 of a node that matches the data enter (or NULL if not found)
	*/
	U searchByFirst(BSTNode<T, U>* curr, T data1);

	/*
	This function searches for a node in a BST that matches the entered data2.
	Pre: curr - a node pointer that shows current node in traversal
		 data2 - data to be compared with other nodes data2
	Return: data1 of a node that matches the data enter (or NULL if not found)
	*/
	T searchBySecond(BSTNode<T, U>* curr, U data2);

	/*
	This function removes a node from a BST that matches the entered data.
	Pre: curr - a node pointer that shows current node in traversal
		 data1 - data to be compared with other nodes data1
		 data2 - data to be compared with other nodes data2
	Post: a BST re-organized with the removal of a node
	*/
	BSTNode<T,U>* remove(BSTNode<T, U>* curr, T data1, U data2);

	/*
	This function returns the root node of a BST
	Return: root node of a BST
	*/
	BSTNode<T, U>*& getRoot();

	/*
	This function sends the data from each node into the output stream using pre-order traversal.
	Pre: curr - pointer to current node in the traversal
		 output - output stream to send data to
	Post: data is sent into output stream (name then birthday)
	*/
	void printPreOrder(std::ostream &output, BSTNode<T,U>* curr);

	/*
	This function sends the data from each node into the output stream using post-order traversal.
	Pre: curr - pointer to current node in the traversal
		 output - output stream to send data to
	Post: data is sent into output stream (name then birthday)
	*/
	void printPostOrder(std::ostream &output, BSTNode<T,U>* curr);

	/*
	This function sends the data from each node into the output stream using in-order traversal.
	Pre: curr - pointer to current node in the traversal
		 output - output stream to send data to
	Post: data is sent into output stream (name then birthday)
	*/
	void printInOrder(std::ostream &output, BSTNode<T,U>* curr);

	/*
	This function sends the data from each node into the output stream using breadth-first traversal.
	Pre: curr - pointer to current node in the traversal
		 output - output stream to send data to
	Post: data is sent into output stream (name then birthday)
	*/
	void printBreadthFirst(std::ostream &output, BSTNode<T, U> * curr);

	/*
	This function sends the data from each level of the BST to the output stream.
	Pre: curr - pointer to current node in the traversal
		 output- output stream to send data to
		 level - level number that is to be printed out
	Post: data from each level of BST is send to output stream
	*/
	void printGivenLevel(std::ostream &output, BSTNode<T, U> * curr, int level);

	/*
	This function returns the height of the tree.
	Pre: curr - pointer to current node in recursion
	Return: integer representing height or number of levels in BST
	*/
	int height(BSTNode <T, U> * curr);
};

template <typename T, typename U>
BSTNode<T, U>* BST<T, U>::newNode(T d1, U d2) {
	BSTNode<T, U>* newNode = new BSTNode<T, U>();
	newNode->data1 = d1;
	newNode->data2 = d2;
	return newNode;
}

/*
Pseudocode:
if (current node is NULL) set current node to a new node
else
	if (data is less than current node data)
		insert to the left of current node
	else
		insert to the right of current not
	end if
end if
*/
template <typename T, typename U>
void BST<T, U>::insert(BSTNode<T, U>* &curr, T data1, U data2) {
	if (curr == NULL) {
		curr = newNode(data1, data2);
	}
	else {
		if ((first && data1 < curr->data1) || (!first && data2 < curr->data2)) {
			insert(curr->left, data1, data2);
		}
		else {
			insert(curr->right, data1, data2);
		}
	}
}

/*
Pseudocode:
if (current node is NULL or data matches current node data) return current node
if (data is less than current node data) call search function using left node
else call search function using right node
*/
template <typename T, typename U>
BSTNode<T, U>* BST<T, U>::search(BSTNode <T, U>* curr, T data1, U data2) {
	if (curr == NULL || (first && curr->data1 == data1) || (!first && curr->data2 == data2)) {
		return curr;
	}
	if ((first && data1 < curr->data1) || (!first && data2 < curr->data2)) {
		return search(curr->left, data1, data2);
	}
	else {
		return search(curr->right, data1, data2);
	}
}

/*
Pseudocode:
if (not sorted by first data) throw exception
if (current node is NULL) throw exception
if (data matches current node) return data
else if (data is less than current node) call search function using left node
else call search function using right node
*/
template <typename T, typename U>
U BST<T, U>::searchByFirst(BSTNode<T, U>* curr, T data1) {
	if (!first) {
		throw "Cannot search using first data type.";
	}
	if (curr == NULL) {
		throw "Person not found.";
	}
	if(data1 == curr->data1) {
		return curr->data2;
	}
	else if (data1 < curr->data1) {
		return searchByFirst(curr->left, data1);
	}
	else {
		return searchByFirst(curr->right, data1);
	}
}

/*
if (not sorted by second data) throw exception
if (current node is NULL) throw exception
if (data matches current node) return data
else if (data is less than current node) call search function using left node
else call search function using right node
*/
template <typename T, typename U>
T BST<T, U>::searchBySecond(BSTNode<T, U>* curr, U data2) {
	if (first) {
		throw "Cannot search using second data type.";
	}
	if (curr == NULL) {
		throw "Person not found.";
	}
	if (data2 == curr->data2) {
		return curr->data1;
	}
	else if (data2 < curr->data2) {
		return searchBySecond(curr->left, data2);
	}
	else {
		return searchBySecond(curr->right, data2);
	}
}

template <typename T, typename U>
BSTNode<T, U>* BST<T, U>::minValue(BSTNode<T, U>* curr) {
	if (curr == NULL || curr->left == NULL) return curr;
	else return minValue(curr->left);
}

/*
Pseudocode:
if (current node is NULL) return current node
if (data is less than current node) call remove function using left node
else if (data is greater than current node) call remove function using right node
else
	if (left node is NULL)
		delete current node
		return right node
	else if (right node is NULL)
		delete current node
		return left node
	else (there is two children nodes)
		get node with smallest data on right side
		set current node data to min value node data
		call remove function with the min value node data
	end if
end if
return current node
*/
template <typename T, typename U>
BSTNode<T, U>* BST<T, U>::remove(BSTNode <T, U>* curr, T data1, U data2) {
	if (curr == NULL) return curr;
	if ((first && data1 < curr->data1) || (!first && data2 < curr->data2)) {
		curr->left = remove(curr->left, data1, data2);
	}
	else if ((first && data1 > curr->data1) || (!first && data2 > curr->data2)) {
		curr->right = remove(curr->right, data1, data2);
	}
	else {
		if (curr->left == NULL) {
			BSTNode<T, U>* temp = curr->right;
			free(curr);
			return temp;
		}
		else if (curr->right == NULL) {
			BSTNode<T, U>* temp = curr->left;
			free(curr);
			return temp;
		}
		BSTNode<T, U>* temp = minValue(curr->right);
		curr->data1 = temp->data1;
		curr->data2 = temp->data2;
		curr->right = remove(curr->right, temp->data1, temp->data2);
	}
	return curr;
}

template <typename T, typename U>
BSTNode<T, U>*& BST<T,U>::getRoot()
{
	return root;
}

/*
Pseudocode:
if (current node is NULL) return
send current node data to output stream
call print function using left node
call print function using right node
*/
template <typename T, typename U>
void BST<T, U>::printPreOrder(std::ostream &output, BSTNode<T,U>* curr) {
	if (curr == NULL) return;
	output << curr->data2 << "\t" << curr->data1 << "\n";
	printPreOrder(output, curr->left);
	printPreOrder(output, curr->right);
}

/*
Pseudocode:
if (current node is NULL) return
call print function using left node
call print function using right node
send current node data to output stream
*/
template <typename T, typename U>
void BST<T, U>::printPostOrder(std::ostream &output, BSTNode<T, U>* curr) {
	if (curr == NULL) return;
	printPostOrder(output, curr->left);
	printPostOrder(output, curr->right);
	output << curr->data2 << "\t" << curr->data1 << "\n";
}

/*
Pseudocode:
if (current node is NULL) return
call print function using left node
send current node data to output stream
call print function using right node
*/
template <typename T, typename U>
void BST<T, U>::printInOrder(std::ostream &output, BSTNode<T, U>* curr) {
	if (curr == NULL) return;
	printInOrder(output, curr->left);
	output << curr->data2 << "\t" << curr->data1 << "\n";
	printInOrder(output, curr->right);
}

/*
Pseudocode:
get height of BST
loop (for every level of BST) print data of each node in said level
*/
template <typename T, typename U>
void BST<T, U>::printBreadthFirst(std::ostream &output, BSTNode<T, U> * curr)
{
	int h = height(curr);
	for (int i = 1; i <= h; i++)
	{
		printGivenLevel(output, curr, i);
	}
}

/*
Psuedocode:
if (current node is NULL) return
if (first level) send current node data to output stream
else if (level is greater than 1)
	call print function with left node and lower level
	call print function with right node and lower level
end if
*/
template <typename T, typename U>
void BST<T, U>::printGivenLevel(std::ostream &output, BSTNode<T, U> * curr, int level)
{
	if (curr == NULL)
	{
		return;
	}
	if (level == 1)
	{
		output << curr->data2 << "\t" << curr->data1 << "\n";
	}
	else if (level > 1)
	{
		printGivenLevel(output, curr->left, level - 1);
		printGivenLevel(output, curr->right, level - 1);
	}
}

/*
Pseudocode:
if (current node is NULL) return 0
else
	get height of left node
	get height of right node
	return the larger of the two heights + 1
end if
*/
template <typename T, typename U>
int BST<T, U>::height(BSTNode <T, U> * curr)
{
	if (curr == NULL)
		return 0;
	else
	{
		int lheight = height(curr->left);
		int rheight = height(curr->right);

		if (lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return (rheight + 1);
		}
	}
}
