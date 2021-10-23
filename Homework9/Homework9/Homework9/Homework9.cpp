//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 9
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// Includes - built-in libraries
//-----------------------------------------------------------------------
using namespace std;
#include <iostream>
#include <fstream>
#include<string>

//----------------------------------------------------
// User defined types
//----------------------------------------------------
typedef struct udtNode {
	int intValue;
	udtNode *pudtNextNode;
} udtNodeType;

//----------------------------------------------------
// Prototypes
//----------------------------------------------------
char* GetFileNameFromUser();
udtNodeType* LoadList(char* pstrFile);
bool OpenFile(const char* pstrFileName, ifstream &ifsDataFile);
void Print(udtNodeType* pudtCurrentNode);
void DeleteList(udtNodeType* &pudtHeadNode);


void main() {
	//Declare head node and new node.
	int intUserValue = 0;
	udtNodeType* pudtHeadNode = 0;
	udtNodeType* pudtCurrentNode = 0;
	udtNodeType* pudtNextNode = 0;
	int intIndex = 0;
	char* pstrFile = 0;
	int intValue = 0;
	
	pstrFile = GetFileNameFromUser();

	pudtHeadNode = LoadList(pstrFile);	
	//delete filename ref
	delete[] pstrFile;
	pstrFile = 0;
	//print to console
	Print(pudtHeadNode);
	//delete from mem
	DeleteList(pudtHeadNode);
	cout << "Head node after delete: " << pudtHeadNode << endl;
	
}

//----------------------------------------------------
// Name: GetFileNameFromUser
// Abstract: Gets file name from user
//----------------------------------------------------
char* GetFileNameFromUser() {
	char strFileName[255] = "";
	char* pstrFileName = 0;
	cout << "Enter File Name: " << endl;
	cin >> strFileName;
	//allocate
	pstrFileName = new char[strlen(strFileName) + 1];
	strcpy(pstrFileName, strFileName);
	return pstrFileName;
}

//----------------------------------------------------
// Name: LoadList
// Abstract: Loads list from given file
//----------------------------------------------------
udtNodeType* LoadList(char* pstrFile) {
	//cout << "Loading" << endl;
	bool blnResult = false;
	ifstream ifsDataFile;
	int intValue = 0;
	char buf[255] = "";
	udtNodeType* pudtHeadNode = 0;
	udtNodeType* pudtCurrentNode = 0;
	udtNodeType* pudtNextNode = 0;

	blnResult = OpenFile(pstrFile, ifsDataFile);

	// Success?
	if (blnResult == true)
	{
		// Yes

		// End of file?
		while (ifsDataFile.eof() == false)
		{
			// No, read next value to buffer
			ifsDataFile >> buf;

			if (atoi(buf) != 0) {

				//convert str back to int
				intValue = atoi(buf);
	
				pudtHeadNode = new udtNodeType;
				pudtHeadNode->intValue = intValue;
				pudtHeadNode->pudtNextNode = pudtNextNode;
				pudtNextNode = pudtHeadNode;
				//cout << intValue << endl;
			}
		}

		// All done
		ifsDataFile.close();
	}

	//system("pause");

	return pudtHeadNode;
}

// --------------------------------------------------------------------------------
// Name: OpenFile
// Abstract: Open conection and return boolean indicating if it was successful
// --------------------------------------------------------------------------------
bool OpenFile(const char* pstrFileName, ifstream &ifsDataFile)
{
	bool blnResult = false;

	// Open the file
	ifsDataFile.open(pstrFileName, istream::in);

	// Was the file open successfully?
	if (ifsDataFile.is_open() == true)
	{
		// Yes
		blnResult = true;
	}
	else
	{
		// No, display error message
		cout << "Error opening file: " << pstrFileName << endl;
	}

	return blnResult;
}

//----------------------------------------------------
// Name: Print
// Abstract: prints object to console
//----------------------------------------------------
void Print(udtNodeType* pudtCurrentNode) {
	int intIndex = 0;
	udtNodeType* pudtNextNode = 0;
	while (pudtCurrentNode != 0) {
		intIndex += 1;
		cout << "Value at node #" << intIndex << " is " << pudtCurrentNode->intValue << endl;

		pudtNextNode = pudtCurrentNode->pudtNextNode;
		pudtCurrentNode = pudtNextNode;
	}
}


//----------------------------------------------------
// Name: Delete
// Abstract: deletes object from mem
//----------------------------------------------------
void DeleteList(udtNodeType* &pudtHeadNode) {
	udtNodeType* pudtNextNode = 0;
	while (pudtHeadNode != 0) {
		pudtNextNode = pudtHeadNode->pudtNextNode;
		//delete
		delete [] pudtHeadNode;
		pudtHeadNode = 0;
		//move to next. last one will have 0 as next anyway
		pudtHeadNode = pudtNextNode;
	}
}