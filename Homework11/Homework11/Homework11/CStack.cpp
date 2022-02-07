//// --------------------------------------------------------------------------------
//// Name: CStack
//// Abstract: Class method definitions
//// --------------------------------------------------------------------------------
//
//// --------------------------------------------------------------------------------
//// Includes
//// --------------------------------------------------------------------------------
//#include "CStack.h"
//#include "CNode.h"
//// --------------------------------------------------------------------------------
//// Pre-compiler Directives
//// --------------------------------------------------------------------------------
//#ifndef CSTACK_CPP
//#define CSTACK_CPP
////------------------------------------------------------------------------
//// Name: CStack
//// Abstract: Constructors
////------------------------------------------------------------------------
//template <typename GenericDataType>
//CStack::CStack()
//{
//	Initialize();
//}
//template <typename GenericDataType>
//CStack::CStack(const CStack & clsOriginal)
//{
//	Initialize();
//	*this = clsOriginal;
//}
//template <typename GenericDataType>
//CStack::~CStack()
//{
//	CleanUp();
//}
////------------------------------------------------------------------------
//// Name: operator=
//// Abstract: Assignment override
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::operator=(const CStack & clsOriginal)
//{
//	if (this != &clsOriginal) {
//		CleanUp();
//		DeepCopy(clsOriginal);
//	}
//}
////------------------------------------------------------------------------
//// Name: Push
//// Abstract: Adds  value to front of stack
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::Push(int intValue)
//{
//	CNode* clsNewNode = 0;
//	clsNewNode = new CNode(intValue, m_pclsHeadNode);
//	m_pclsHeadNode = clsNewNode;
//}
////------------------------------------------------------------------------
//// Name: Pop
//// Abstract: Removes value from front of stack
////------------------------------------------------------------------------
//template <typename GenericDataType>
//int CStack::Pop()
//{
//	int intValue = 0;
//	CNode* pclsNext = 0;
//	if (!IsEmpty()) {
//		intValue = m_pclsHeadNode->GetValue();
//		pclsNext = m_pclsHeadNode->GetNextNode();
//		delete m_pclsHeadNode;
//		m_pclsHeadNode = 0;
//		m_pclsHeadNode = pclsNext;
//	}
//
//	return intValue;
//}
////------------------------------------------------------------------------
//// Name: IsEmpty
//// Abstract: Checks if stack is empty
////------------------------------------------------------------------------
//template <typename GenericDataType>
//bool CStack::IsEmpty() const
//{
//	bool blnEmpty = false;
//	if (m_pclsHeadNode == 0) {
//		blnEmpty = true;
//	}
//	return blnEmpty;
//}
////------------------------------------------------------------------------
//// Name: Print
//// Abstract: Prints without message
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::Print() const {
//
//	Print("");
//}
////------------------------------------------------------------------------
//// Name: Print
//// Abstract: Prints stack with message header
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::Print(const char* strMessage) const
//{
//	int intIndex = 0;
//	CNode* clsCurrentNode = 0;
//	if (!IsEmpty()) {
//		clsCurrentNode = m_pclsHeadNode;
//		if (strMessage != "") {
//
//			cout << "**************************" << endl;
//			cout << strMessage << endl;
//			cout << "**************************" << endl;
//		}
//		while (clsCurrentNode != 0) {
//			intIndex++;
//			cout << "Index " << (intIndex) << " = " << clsCurrentNode->GetValue() << endl;
//			clsCurrentNode = clsCurrentNode->GetNextNode();
//		}
//	}
//	else {
//		cout << "**************************" << endl;
//		cout << strMessage << endl;
//		cout << "**************************" << endl;
//		cout << "Nothing to see here" << endl;
//	}
//
//}
////------------------------------------------------------------------------
//// Name: Initialize
//// Abstract: Initialize
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::Initialize()
//{
//	m_pclsHeadNode = 0;
//}
////------------------------------------------------------------------------
//// Name: DeepCopy
//// Abstract: Copies stack by reference
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::DeepCopy(const CStack & clsOriginal)
//{
//	CNode* pclsOriginal = 0;
//	int intValue = 0;
//	CNode* pclsTail = 0;
//	pclsOriginal = clsOriginal.m_pclsHeadNode;
//
//	while (pclsOriginal != 0) {
//		intValue = pclsOriginal->GetValue();
//		if (pclsTail == 0) {
//			pclsTail = new CNode(intValue, 0);
//			m_pclsHeadNode = pclsTail;
//		}
//		else {
//			pclsTail->SetNextNode(new CNode(intValue, 0));
//			pclsTail = pclsTail->GetNextNode();
//		}
//		pclsOriginal = pclsOriginal->GetNextNode();
//	}
//}
////------------------------------------------------------------------------
//// Name: CleanUp
//// Abstract: Clears stack
////------------------------------------------------------------------------
//template <typename GenericDataType>
//void CStack::CleanUp()
//{
//	while (IsEmpty() == false) {
//		Pop();
//	}
//}
//#endif