// --------------------------------------------------------------------------------
// Name: CNode
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CNode.h"


CNode::CNode()
{
	CNode(0, 0);
}

CNode::CNode(int intValue)
{
	CNode(intValue, 0);
}

CNode::CNode(int intValue, CNode * pclsNextNode)
{
	
	SetValue(intValue);
	SetNextNode(pclsNextNode);
}

CNode::CNode(const CNode& clsOriginal)
{
	ShallowCopy(clsOriginal);
}

CNode::~CNode()
{
	SetValue(0);
	SetNextNode(0);
}

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

void CNode::SetNextNode(CNode * pclsNextNode)
{
	m_pclsNextNode = pclsNextNode;
}

CNode * CNode::GetNextNode()
{
	return m_pclsNextNode;
}

void CNode::ShallowCopy(const CNode & clsOriginal)
{
	m_intValue = clsOriginal.m_intValue;

	m_pclsNextNode = clsOriginal.m_pclsNextNode;
}




