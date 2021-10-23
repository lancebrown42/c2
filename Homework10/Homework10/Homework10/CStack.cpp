// --------------------------------------------------------------------------------
// Name: CStack
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CStack.h"
#include "CNode.h"

CStack::CStack()
{
	Initialize();
}

CStack::CStack(const CStack & clsOriginal)
{
	Initialize();
	*this = clsOriginal;
}

CStack::~CStack()
{
	CleanUp();
}

void CStack::operator=(const CStack & clsOriginal)
{
	if (this != &clsOriginal) {
		CleanUp();
		DeepCopy(clsOriginal);
	}
}

void CStack::Push(int intValue)
{
	CNode* clsNewNode = 0;
	clsNewNode = new CNode(intValue, m_pclsHeadNode);
	m_pclsHeadNode = clsNewNode;
}

int CStack::Pop()
{
	int intValue = 0;
	CNode* pclsNext = 0;
	if (!IsEmpty()) {
		intValue = m_pclsHeadNode->GetValue();
		pclsNext = m_pclsHeadNode->GetNextNode();
		delete m_pclsHeadNode;
		m_pclsHeadNode = 0;
		m_pclsHeadNode = pclsNext;
	}

	return intValue;
}

bool CStack::IsEmpty() const
{
	bool blnEmpty = false;
	if (m_pclsHeadNode == 0) {
		blnEmpty = true;
	}
	return blnEmpty;
}
void CStack::Print() const {
	
	Print("");
}
void CStack::Print(const char* strMessage) const
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
		cout << "Nothing to see here" << endl;
	}
	
}

void CStack::Initialize()
{
	m_pclsHeadNode = 0;
}

void CStack::DeepCopy(const CStack & clsOriginal)
{
	CNode* clsCurrentNode = clsOriginal.m_pclsHeadNode;

	while (clsCurrentNode != nullptr && clsCurrentNode != 0) {
		Push(clsCurrentNode->GetValue());
		clsCurrentNode = clsCurrentNode->GetNextNode();
	}
	
}

void CStack::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}
