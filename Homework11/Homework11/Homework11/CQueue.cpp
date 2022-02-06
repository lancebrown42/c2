// --------------------------------------------------------------------------------
// Name: CQueue
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CQueue.h"
#include "CNode.h"
// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#ifndef CQUEUE_CPP
#define CQUEUE_CPP

//------------------------------------------------------------------------
// Name: CQueue
// Abstract: Constructors
//------------------------------------------------------------------------

CQueue::CQueue()
{
	Initialize();
}

CQueue::CQueue(const CQueue & clsOriginal)
{
	Initialize();
	*this = clsOriginal;
}

CQueue::~CQueue()
{
	CleanUp();
}
//------------------------------------------------------------------------
// Name: operator=
// Abstract: Assignment override
//------------------------------------------------------------------------
void CQueue::operator=(const CQueue & clsOriginal)
{
	if (this != &clsOriginal) {
		CleanUp();
		DeepCopy(clsOriginal);
	}
}
//------------------------------------------------------------------------
// Name: Push
// Abstract: Adds  value to end of queue
//------------------------------------------------------------------------
void CQueue::Push(int intValue)
{
	CNode* clsNewNode = 0;
	clsNewNode = new CNode(intValue);
	if (IsEmpty() == true) {
		m_pclsHeadNode = clsNewNode;
		m_pclsTailNode = clsNewNode;
	}
	else {
		m_pclsTailNode->SetNextNode(clsNewNode);
		m_pclsTailNode = clsNewNode;
	}
}
//------------------------------------------------------------------------
// Name: Pop
// Abstract: Removes value from front of Queue
//------------------------------------------------------------------------
int CQueue::Pop()
{
	int intValue = 0;
	CNode* pclsNext = 0;
	if (!IsEmpty() == true) {
		intValue = m_pclsHeadNode->GetValue();
		pclsNext = m_pclsHeadNode->GetNextNode();
		delete m_pclsHeadNode;
		m_pclsHeadNode = 0;
		m_pclsHeadNode = pclsNext;
		if (IsEmpty()) {
			m_pclsTailNode = 0;
		}
	}

	return intValue;
}
//------------------------------------------------------------------------
// Name: IsEmpty
// Abstract: Checks if Queue is empty
//------------------------------------------------------------------------
bool CQueue::IsEmpty() const
{
	bool blnEmpty = false;
	if (m_pclsHeadNode == 0) {
		blnEmpty = true;
	}
	return blnEmpty;
}
//------------------------------------------------------------------------
// Name: Print
// Abstract: Prints without message
//------------------------------------------------------------------------
void CQueue::Print() const {

	Print("");
}
//------------------------------------------------------------------------
// Name: Print
// Abstract: Prints Queue with message header
//------------------------------------------------------------------------
void CQueue::Print(const char* strMessage) const
{
	int intIndex = 0;
	CNode* clsCurrentNode = 0;
	if (!IsEmpty()) {
		clsCurrentNode = m_pclsHeadNode;
		if (strMessage != "") {

			cout << "**************************" << endl;
			cout << strMessage << endl;
			cout << "**************************" << endl;
		}
		while (clsCurrentNode != 0) {
			intIndex++;
			cout << "Index " << (intIndex) << " = " << clsCurrentNode->GetValue() << endl;
			clsCurrentNode = clsCurrentNode->GetNextNode();
		}
	}
	else {
		cout << "**************************" << endl;
		cout << strMessage << endl;
		cout << "**************************" << endl;
		cout << "Nothing to see here" << endl;
	}

}
//------------------------------------------------------------------------
// Name: Initialize
// Abstract: Initialize
//------------------------------------------------------------------------
void CQueue::Initialize()
{
	m_pclsHeadNode = 0;
	m_pclsTailNode = 0;
}
//------------------------------------------------------------------------
// Name: DeepCopy
// Abstract: Copies Queue by reference
//------------------------------------------------------------------------
void CQueue::DeepCopy(const CQueue &clsOriginal)
{
	CNode* pclsOriginal = 0;
	int intValue = 0;
	pclsOriginal = clsOriginal.m_pclsHeadNode;

	while (pclsOriginal != 0) {
		intValue = pclsOriginal->GetValue();
		Push(intValue);
		pclsOriginal = pclsOriginal->GetNextNode();
	}

}
//------------------------------------------------------------------------
// Name: CleanUp
// Abstract: Clears Queue
//------------------------------------------------------------------------
void CQueue::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}
#endif