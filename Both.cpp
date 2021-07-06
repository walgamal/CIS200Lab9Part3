/*
Program Name: Queue & Stack Tester
Programmer Name: Wasim Algamal
Description: Implement a stack using an array and a queue using a linked list
Date Created: 11/15/20
*/

#include "Combined.h"

//Description: Asks for input file name from a selection
//Post-condition: Returns a VALID input file name
string AskInFile() {
	string fileName;

	while (fileName != "intStackIn.txt" && fileName != "floatStackIn.txt" && fileName != "charStackIn.txt" &&
		fileName != "intQueueIn.txt" && fileName != "floatQueueIn.txt" && fileName != "charQueueIn.txt") {

		cout << "File Selection: \n";
		cout << "intStackIn.txt		floatStackIn.txt\n"
			<< "charStackIn.txt		intQueueIn.txt\n"
			<< "floatQueueIn.txt	charQueueIn.txt\n\n";
		cout << "Please enter a valid file name: ";
		getline(cin, fileName);

		if (fileName != "intStackIn.txt" && fileName != "floatStackIn.txt" && fileName != "charStackIn.txt" &&
			fileName != "intQueueIn.txt" && fileName != "floatQueueIn.txt" && fileName != "charQueueIn.txt") {
			cout << "NOT A VALID FILE! TRY AGAIN\n";
		}
	}
	cout << endl;

	return fileName;
}

//Description: Asks for output file name
//Post-condition: Returns an output file name
string AskOutFile() {
	string fileName;
	cout << "Please enter an output file name: ";
	getline(cin, fileName);
	cout << endl;
	return fileName;
}

int main() {

	ifstream inFile;
	ofstream outFile;
	string inFileName = AskInFile();
	string outFileName = AskOutFile();
	inFile.open(inFileName);
	outFile.open(outFileName);
	
	Stack<int>IntStack;
	Queue<int>IntQueue;

	Stack<float>FloatStack;
	Queue<float>FloatQueue;

	Stack<char>CharStack;
	Queue<char>CharQueue;

	char read;
	int inputInt;
	float inputFloat;
	char inputChar;
	bool callStatus;

	inFile.get(read);

	if (read == 'I') {

		cout << "Integer ";
		outFile << "Integer ";

		inFile.get(read); 
		inFile.get(read);
		
		if (read == 'S') {

			cout << "Stack\n";
			outFile << "Stack\n";

			while (!inFile.eof()) {
				if (read == 'A') {
					inFile >> inputInt;

					cout << "Add " << inputInt << "			";
					outFile << "Add " << inputInt << "			";

					if (IntStack.Push(inputInt, outFile)) {
						cout << inputInt << " was added.\n";
						outFile << inputInt << " was added.\n";
					}
					else {
						cout << inputInt << " was NOT added.\n";
						outFile << inputInt << " was NOT added.\n";
					}

				}
				else if (read == 'R') {
					int whatsPoppin;

					cout << "Remove			";
					outFile << "Remove			";

					if (IntStack.Pop(whatsPoppin, outFile)) {
						cout << whatsPoppin << " was removed.\n";
						outFile << whatsPoppin << " was removed.\n";
					}
					else {
						cout << "Nothing was removed.\n";
						outFile << "Nothing was removed.\n";
					}
				}
				else if (read == 'L') {
					cout << "Length			";
					outFile << "Length			";

					cout << "The length of the stack is " << IntStack.length() << "." << endl;
					outFile << "The length of the stack is " << IntStack.length() << "." << endl;
				}
				else if (read == 'P') {
					cout << "Print			";
					outFile << "Print			";

					cout << "The stack contains: ";
					outFile << "The stack contains: ";
					IntStack.Print(outFile);
				}
				else if (read == 'T') {
					cout << "Top			";
					outFile << "Top			";

					int peekInt = IntStack.Peek(callStatus, outFile);
					
					if (callStatus == true) {
						cout << "Peek Successful. Top: " << peekInt << endl;
						outFile << "Peek Successful. Top: " << peekInt << endl;
					}
					else {
						cout << "Peek NOT Successful\n";
						outFile << "Peek NOT Successful\n";
					}
				}

				inFile.get(read);
				inFile.get(read);
			}

		}
		else if (read == 'Q') {
			cout << "Queue\n";
			outFile << "Queue\n";

			while (!inFile.eof()) {
				if (read == 'A') {
					inFile >> inputInt;

					cout << "Add " << inputInt << "			";
					outFile << "Add " << inputInt << "			";

					if (IntQueue.Enqueue(inputInt, outFile)) {
						cout << inputInt << " was added.\n";
						outFile << inputInt << " was added.\n";
					}
					else {
						cout << inputInt << " was NOT added.\n";
						outFile << inputInt << " was NOT added.\n";
					}

				}
				else if (read == 'R') {
					int whatsPoppin;

					cout << "Remove			";
					outFile << "Remove			";

					if (IntQueue.Dequeue(whatsPoppin, outFile)) {
						cout << whatsPoppin << " was removed.\n";
						outFile << whatsPoppin << " was removed.\n";
					}
					else {
						cout << "Nothing was removed.\n";
						outFile << "Nothing was removed.\n";
					}
				}
				else if (read == 'L') {
					cout << "Length			";
					outFile << "Length			";

					cout << "The length of the stack is " << IntQueue.length() << "." << endl;
					outFile << "The length of the stack is " << IntQueue.length() << "." << endl;
				}
				else if (read == 'P') {
					cout << "Print			";
					outFile << "Print			";

					cout << "The stack contains: ";
					outFile << "The stack contains: ";
					IntQueue.Print(outFile);
				}
				else if (read == 'T') {
					cout << "Top			";
					outFile << "Top			";

					int peekInt = IntQueue.FrontPeek(callStatus, outFile);

					if (callStatus == true) {
						cout << "Peek Successful. Top: " << peekInt << endl;
						outFile << "Peek Successful. Top: " << peekInt << endl;
					}
					else {
						cout << "Peek NOT Successful\n";
						outFile << "Peek NOT Successful\n";
					}
				}

				inFile.get(read);
				inFile.get(read);
			}

		}
		else {
			cout << "ERROR: NOT A STACK OR QUEUE";
			outFile << "ERROR: NOT A STACK OR QUEUE";
			return -1;
		}
	}
	else if (read == 'R') {

		cout << "Real Number ";
		outFile << "Real Number ";

		inFile.get(read);
		inFile.get(read);

		if (read == 'S') {

			cout << "Stack\n";
			outFile << "Stack\n";

			while (!inFile.eof()) {
				if (read == 'A') {
					inFile >> inputFloat;

					cout << "Add " << inputFloat << "			";
					outFile << "Add " << inputFloat << "			";

					if (FloatStack.Push(inputFloat, outFile)) {
						cout << inputFloat << " was added.\n";
						outFile << inputFloat << " was added.\n";
					}
					else {
						cout << inputFloat << " was NOT added.\n";
						outFile << inputFloat << " was NOT added.\n";
					}

				}
				else if (read == 'R') {
					float whatsPoppin;

					cout << "Remove			";
					outFile << "Remove			";

					if (FloatStack.Pop(whatsPoppin, outFile)) {
						cout << whatsPoppin << " was removed.\n";
						outFile << whatsPoppin << " was removed.\n";
					}
					else {
						cout << "Nothing was removed.\n";
						outFile << "Nothing was removed.\n";
					}
				}
				else if (read == 'L') {
					cout << "Length			";
					outFile << "Length			";

					cout << "The length of the stack is " << FloatStack.length() << "." << endl;
					outFile << "The length of the stack is " << FloatStack.length() << "." << endl;
				}
				else if (read == 'P') {
					cout << "Print			";
					outFile << "Print			";

					cout << "The stack contains: ";
					outFile << "The stack contains: ";
					FloatStack.Print(outFile);
				}
				else if (read == 'T') {
					cout << "Top			";
					outFile << "Top			";

					float peekFloat = FloatStack.Peek(callStatus, outFile);

					if (callStatus == true) {
						cout << "Peek Successful. Top: " << peekFloat << endl;
						outFile << "Peek Successful. Top: " << peekFloat << endl;
					}
					else {
						cout << "Peek NOT Successful\n";
						outFile << "Peek NOT Successful\n";
					}
				}

				inFile.get(read);
				inFile.get(read);
			}

		}
		else if (read == 'Q') {

			cout << "Queue\n";
			outFile << "Queue\n";

			while (!inFile.eof()) {
				if (read == 'A') {
					inFile >> inputFloat;

					cout << "Add " << inputFloat << "			";
					outFile << "Add " << inputFloat << "			";

					if (FloatQueue.Enqueue(inputFloat, outFile)) {
						cout << inputFloat << " was added.\n";
						outFile << inputFloat << " was added.\n";
					}
					else {
						cout << inputFloat << " was NOT added.\n";
						outFile << inputFloat << " was NOT added.\n";
					}

				}
				else if (read == 'R') {
					float whatsPoppin;

					cout << "Remove			";
					outFile << "Remove			";

					if (FloatQueue.Dequeue(whatsPoppin, outFile)) {
						cout << whatsPoppin << " was removed.\n";
						outFile << whatsPoppin << " was removed.\n";
					}
					else {
						cout << "Nothing was removed.\n";
						outFile << "Nothing was removed.\n";
					}
				}
				else if (read == 'L') {
					cout << "Length			";
					outFile << "Length			";

					cout << "The length of the stack is " << FloatQueue.length() << "." << endl;
					outFile << "The length of the stack is " << FloatQueue.length() << "." << endl;
				}
				else if (read == 'P') {
					cout << "Print			";
					outFile << "Print			";

					cout << "The stack contains: ";
					outFile << "The stack contains: ";
					FloatQueue.Print(outFile);
				}
				else if (read == 'T') {
					cout << "Top			";
					outFile << "Top			";

					float peekFloat = FloatQueue.FrontPeek(callStatus, outFile);

					if (callStatus == true) {
						cout << "Peek Successful. Top: " << peekFloat << endl;
						outFile << "Peek Successful. Top: " << peekFloat << endl;
					}
					else {
						cout << "Peek NOT Successful\n";
						outFile << "Peek NOT Successful\n";
					}
				}

				inFile.get(read);
				inFile.get(read);
			}

		}
		else {
			cout << "ERROR: NOT A STACK OR QUEUE";
			outFile << "ERROR: NOT A STACK OR QUEUE";
			return -1;
		}
	}
	else if (read == 'C') {
		
		cout << "Char ";
		outFile << "Char ";

		inFile.get(read);
		inFile.get(read);

		if (read == 'S') {

			cout << "Stack\n";
			outFile << "Stack\n";

			while (!inFile.eof()) {
				if (read == 'A') {
					inFile >> inputChar;

					cout << "Add " << inputChar << "			";
					outFile << "Add " << inputChar << "			";

					if (CharStack.Push(inputChar, outFile)) {
						cout << inputChar << " was added.\n";
						outFile << inputChar << " was added.\n";
					}
					else {
						cout << inputChar << " was NOT added.\n";
						outFile << inputChar << " was NOT added.\n";
					}

				}
				else if (read == 'R') {
					char whatsPoppin;

					cout << "Remove			";
					outFile << "Remove			";

					if (CharStack.Pop(whatsPoppin, outFile)) {
						cout << whatsPoppin << " was removed.\n";
						outFile << whatsPoppin << " was removed.\n";
					}
					else {
						cout << "Nothing was removed.\n";
						outFile << "Nothing was removed.\n";
					}
				}
				else if (read == 'L') {
					cout << "Length			";
					outFile << "Length			";

					cout << "The length of the stack is " << CharStack.length() << "." << endl;
					outFile << "The length of the stack is " << CharStack.length() << "." << endl;
				}
				else if (read == 'P') {
					cout << "Print			";
					outFile << "Print			";

					cout << "The stack contains: ";
					outFile << "The stack contains: ";
					CharStack.Print(outFile);
				}
				else if (read == 'T') {
					cout << "Top			";
					outFile << "Top			";

					char peekChar = CharStack.Peek(callStatus, outFile);

					if (callStatus == true) {
						cout << "Peek Successful. Top: " << peekChar << endl;
						outFile << "Peek Successful. Top: " << peekChar << endl;
					}
					else {
						cout << "Peek NOT Successful\n";
						outFile << "Peek NOT Successful\n";
					}
				}

				inFile.get(read);
				inFile.get(read);
			}

		}
		else if (read == 'Q') {

			cout << "Stack\n";
			outFile << "Stack\n";

			while (!inFile.eof()) {
				if (read == 'A') {
					inFile >> inputChar;

					cout << "Add " << inputChar << "			";
					outFile << "Add " << inputChar << "			";

					if (CharQueue.Enqueue(inputChar, outFile)) {
						cout << inputChar << " was added.\n";
						outFile << inputChar << " was added.\n";
					}
					else {
						cout << inputChar << " was NOT added.\n";
						outFile << inputChar << " was NOT added.\n";
					}

				}
				else if (read == 'R') {
					char whatsPoppin;

					cout << "Remove			";
					outFile << "Remove			";

					if (CharQueue.Dequeue(whatsPoppin, outFile)) {
						cout << whatsPoppin << " was removed.\n";
						outFile << whatsPoppin << " was removed.\n";
					}
					else {
						cout << "Nothing was removed.\n";
						outFile << "Nothing was removed.\n";
					}
				}
				else if (read == 'L') {
					cout << "Length			";
					outFile << "Length			";

					cout << "The length of the stack is " << CharQueue.length() << "." << endl;
					outFile << "The length of the stack is " << CharQueue.length() << "." << endl;
				}
				else if (read == 'P') {
					cout << "Print			";
					outFile << "Print			";

					cout << "The stack contains: ";
					outFile << "The stack contains: ";
					CharQueue.Print(outFile);
				}
				else if (read == 'T') {
					cout << "Top			";
					outFile << "Top			";

					char peekChar = CharQueue.FrontPeek(callStatus, outFile);

					if (callStatus == true) {
						cout << "Peek Successful. Top: " << peekChar << endl;
						outFile << "Peek Successful. Top: " << peekChar << endl;
					}
					else {
						cout << "Peek NOT Successful\n";
						outFile << "Peek NOT Successful\n";
					}
				}

				inFile.get(read);
				inFile.get(read);
			}

		}
		else {
			cout << "ERROR: NOT A STACK OR QUEUE";
			outFile << "ERROR: NOT A STACK OR QUEUE";
			return -1;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}