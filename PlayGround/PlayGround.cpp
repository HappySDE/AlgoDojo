#include "StlHeaders.h"

void main()
{
	std::string str = "abc";
	const char* pch1 = &str[0];
	const char* pch2 = &str[str.size() - 1];
}

