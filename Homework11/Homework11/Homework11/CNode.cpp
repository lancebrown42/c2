// --------------------------------------------------------------------------------
// Name: CNode
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CNode.h"

// --------------------------------------------------------------------------------
// Name: CNode
// Abstract: Constructors
// --------------------------------------------------------------------------------
CNode::CNode()
{
	Initialize(0, 0);
}

CNode::CNode(int intValue)
{
	Initialize(intValue, 0);
}

CNode::CNode(int intValue, CNode* pclsNextNode)
{
	Initialize(intValue, pclsNextNode);
}

CNode::CNode(const CNode& clsOriginal)
{
	Initialize(0, 0);
	*this = clsOriginal;
}

void CNode::Initialize(int intValue, CNode * pclsNext)
{
	SetValue(intValue);
	SetNextNode(pclsNext);
}

CNode::~CNode()
{
	SetValue(0);
	SetNextNode(0);
}
// --------------------------------------------------------------------------------
// Name: SetValue
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CNode::operator=(const CNode & clsOriginal)
{
	ShallowCopy(clsOriginal);
}

// --------------------------------------------------------------------------------
// Name: SetValue
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CNode::SetValue(int intNewValue)
{
	// Boundary check
	if (intNewValue < 0)
	{
		// Clip to prevent negative value
		intNewValue = 0;
	}

	m_intValue = intNewValue;
}


// --------------------------------------------------------------------------------
// Name: GetValue
// Abstract: Get the Value
// --------------------------------------------------------------------------------
int CNode::GetValue()
{
	return m_intValue;
}
// --------------------------------------------------------------------------------
// Name: SetNextNode
// Abstract: Sext next node
// --------------------------------------------------------------------------------
void CNode::SetNextNode(CNode * pclsNextNode)
{
	m_pclsNextNode = pclsNextNode;
}
// --------------------------------------------------------------------------------
// Name: GetNextNode
// Abstract: Get next node
// --------------------------------------------------------------------------------
CNode * CNode::GetNextNode()
{
	return m_pclsNextNode;
}
// --------------------------------------------------------------------------------
// Name: ShallowCopy
// Abstract: Perform Shallow copy
// --------------------------------------------------------------------------------
void CNode::ShallowCopy(const CNode & clsOriginal)
{
	m_intValue = clsOriginal.m_intValue;

	m_pclsNextNode = clsOriginal.m_pclsNextNode;
}

// --------------------------------------------------------------------------------
// Name: GetValue
// Abstract: Get the Value
// --------------------------------------------------------------------------------

void CNode::CleanUp()
{
	//N/A
}




