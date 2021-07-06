#pragma once

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

template<class ItemType>

class Stack {
private:
	ItemType arrayStack[5];						// array with size 5 for stack            
	int topOfStack;
public:
	//Description: Default constructor
	//Post-condition: Stack is created and empty - topOfStack = -1  
	Stack() {
		arrayStack[5] = { };
		topOfStack = -1;
	}

	//Description: Copy constructor - implicitly called for a deep copy
	//Pre-condition: Input a stack that is already in use
	//Post-condition: Creates a deep copy of inputted stack
	Stack(const Stack<ItemType>& x) {

		if (x.topOfStack != -1)
		{
			for (int i = 0; i < x.topOfStack + 1; i++)
			{
				topOfStack = i;
				arrayStack[topOfStack] = x.arrayStack[i];
			}
		}
		else
		{
			topOfStack = -1;
		}
	}

	//Description: Empties out stack
	//Pre-condition: pass the output file
	//Post-condition: Stack is made empty
	void MakeEmpty(ofstream& outFile) {
		topOfStack = -1;
		cout << "Stack was emptied!\n";
		outFile << "Stack was emptied!\n";
	}

	//Description: Checks if stack is empty
	//Post-condition: Returns whether stack is empty or not
	bool IsEmpty() {
		if (topOfStack == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	//Description: Checks if stack is full (5 items MAX)
	//Post-condition: Returns whether stack is full or not
	bool IsFull() {
		if (topOfStack == 4) {
			return true;
		}
		else {
			return false;
		}
	}

	//Description: Tells stack's length size
	//Post-condition: return the number of elements in the stack
	int length() {
		return topOfStack + 1;
	}

	//Description: Prints stack
	//Pre-condition: pass the output file
	//Post-condition: Stack elements are all printed from the top to bottom
	void Print(ofstream& outFile) {
		if (topOfStack == -1) {
			cout << "Nothing!\n";
			outFile << "Nothing!\n";
		}
		else {
			for (int i = 0; i <= topOfStack; i++) {
				cout << arrayStack[i] << " ";
				outFile << arrayStack[i] << " ";
			}
			cout << endl;
			outFile << endl;
		}
	}

	//Description: Adds element to stack
	//Pre-condition: stack is not full - pass element to add and the output file
	//Post-condition: x is added to top of stack - false if cannot push and true if it can
	bool Push(ItemType x, ofstream& outFile) {
		if (topOfStack == 4) {
			cout << "ERROR: Stack overflow. ";
			outFile << "ERROR: Stack overflow. ";
			return false;
		}
		else {
			topOfStack++;
			arrayStack[topOfStack] = x;
			return true;
		}
	}

	//Description: Removes element from top of stack 
	//Pre-condition: Stack is not empty - pass in x and pass the output file
	//Post-condition: Deletes top element and returns true if element was popped and false if not popped - x is popped element
	bool Pop(ItemType& x, ofstream& outFile) {
		if (topOfStack == -1) {
			cout << "ERROR: Stack underflow. ";
			outFile << "ERROR: Stack underflow. ";
			return false;
		}
		else {
			x = arrayStack[topOfStack];
			topOfStack--;
			return true;
		}
	}

	//Description: Peeks at top element
	//Pre-condition: Stack cannot be empty - pass the output file and a bool for status
	//Post-condition: Returns top element - true if pass and false if empty
	ItemType Peek(bool& status, ofstream& outFile) {

		if (topOfStack == -1) {
			cout << "ERROR: Stack is empty. ";
			outFile << "ERROR: Stack is empty. ";
			status = false;
		}
		else {
			status = true;
			return arrayStack[topOfStack];
		}

	}

	//Description: Destructor
	//Post-condition: Does nothing since we use an array
	~Stack() {

	}
};

template<class ItemType>

struct NodeType {
	ItemType info;
	NodeType* next;
};

template<class ItemType>

class Queue {
private:
	NodeType<ItemType>* front;							// points to the front of a singly-linked 
	NodeType<ItemType>* rear;							// points to the end of a singly-linked list
	int count;
public:
	//Description: Default constructor
	//Post-condition: Pointers are created and NULL so Queue is created and empty - count = 0  
	Queue() {
		front = NULL;
		rear = NULL;
		count = 0;
	}

	//Description: Copy constructor - implicitly called for a deep copy
	//Pre-condition: Input a queue that is already in use
	//Post-condition: Creates a deep copy of inputted queue
	Queue(const Queue<ItemType>& x) {
		if (x.front == NULL)
		{
			front = NULL;
			rear = NULL;
		}
		else
		{
			NodeType<ItemType>* newNode = new NodeType <ItemType>;
			newNode->info = x.front->info;
			newNode->next = NULL;
			front = newNode;
			rear = newNode;

			NodeType<ItemType>* currentPos = x.front->next;
			while (currentPos != NULL)
			{
				newNode = new NodeType<ItemType>;
				newNode->info = currentPos->info;
				newNode->next = NULL;
				rear->next = newNode;
				rear = rear->next;
				currentPos = currentPos->next;
			}
		}
	}

	//Description: Empties out queue
	//Pre-condition: pass the output file
	//Post-condition: Stack is made empty
	void MakeEmpty(ofstream& outFile) {
		count = 0;
		front = NULL;
		cout << "Queue was emptied!\n";
		outFile << "Queue was emptied!\n";
	}

	//Description: Checks if queue is empty
	//Post-condition: Returns whether queue is empty or not
	bool IsEmpty() {
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//Description: Checks if queue is full (5 items MAX)
	//Post-condition: Returns whether queue is full or not
	bool IsFull() {
		if (count == 5) {
			return true;
		}
		else {
			return false;
		}
	}

	//Description: Tells queue's length size
	//Post-condition: return the number of elements in the queue
	int length() {
		return count;
	}

	//Description: Prints queue
	//Pre-condition: pass the output file
	//Post-condition: Queue elements are all printed from the front to rear
	void Print(ofstream& outFile) {
		NodeType<ItemType>* temp = front;

		if (front == NULL) {
			cout << "Nothing!\n";
			outFile << "Nothing!\n";
		}
		else {

			while (temp->next != NULL) {
				cout << temp->info << " ";
				outFile << temp->info << " ";
				temp = temp->next;
			}

			cout << temp->info << endl;
			outFile << temp->info << endl;
		}
	}

	//Description: Adds element to stack
	//Pre-condition: queue is not full - pass element to add and the output file
	//Post-condition: x is added to rear - false if cannot push and true if it can
	bool Enqueue(ItemType x, ofstream& outFile) {
		if (count == 5) {
			cout << "ERROR: Queue overflow. ";
			outFile << "ERROR: Queue overflow. ";
			return false;
		}
		else {
			if (front == NULL) {
				front = new NodeType<ItemType>;
				front->info = x;
				front->next = NULL;
				count++;
			}
			else {
				NodeType<ItemType>* temp = front;

				rear = new NodeType<ItemType>;
				rear->info = x;
				rear->next = NULL;

				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = rear;
				count++;
			}
			return true;
		}
	}

	//Description: Removes element from front of queue 
	//Pre-condition: Queue is not empty - pass in x and pass the output file
	//Post-condition: Deletes front element and returns true if element was popped and false if not popped - x is popped element
	bool Dequeue(ItemType& x, ofstream& outFile) {
		if (front == NULL) {
			cout << "ERROR: Queue underflow. ";
			outFile << "ERROR: Queue underflow. ";
			return false;
		}
		else {
			x = front->info;
			front = front->next;
			count--;
			return true;
		}
	}

	//Description: Peeks at front element
	//Pre-condition: Queue cannot be empty - pass the output file and a bool for status
	//Post-condition: Returns front element - true if pass and false if empty
	ItemType FrontPeek(bool& status, ofstream& outFile) {
		if (count == 0) {
			cout << "ERROR: Queue is empty. ";
			outFile << "ERROR: Queue is empty. ";
			status = false;
		}
		else {
			status = true;
			return front->info;
		}
	}

	//Description: Destructor
	//Post-condition: memory for the list is deallocated
	~Queue() {
		front = NULL;
		rear = NULL;
		delete front;
		delete rear;
	}
};