#include "CTable.h"

CTable::CTable(const int& width, const int& height) :
	m_width(width), m_height(height)
{

}

bool CTable::IsLocationValid(const int& x, const int& y)
{
	return ((x >= 0) && (x <= (m_width - 1)) && (y >= 0) && (y <= (m_height - 1)));
}

