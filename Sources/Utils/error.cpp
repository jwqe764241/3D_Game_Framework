/*
	jwqe764241 �ۼ�
*/

#include <Sources/Utils/error.h>

#include <iostream>
#include <stdlib.h>



void __cdecl ErrorHandler(
	_In_	char const * const	fileName,
	_In_	const unsigned		lineNumber,
	_In_	char const * const	condition
) {

	std::cerr << "-------------------------------------" << std::endl;
	std::cerr << "Assertion Get False" << std::endl;
	std::cerr << "      File : " << fileName << " : " << lineNumber << " at Line " << std::endl;
	std::cerr << "      Condition Expression �� " << condition << std::endl;
	std::cerr << "-------------------------------------" << std::endl;

	std::abort();
}

void __cdecl ErrorHandler2(
	_In_	char const * const	fileName,
	_In_	char const * const	funcName,
	_In_	const unsigned		lineNumber,
	_In_	char const * const	condition,
	_In_	char const * const	message
) {
	std::cerr << "-------------------------------------" << std::endl;
	std::cerr << "Assertion Get False" << std::endl;
	std::cerr << "      File : "<< fileName << " : " << lineNumber << " Line at " << funcName << std::endl;
	std::cerr << "      Condition Expression �� " << condition << std::endl;
	std::cerr << "      message : " << message << std::endl;
	std::cerr << "-------------------------------------" << std::endl;

	//�������� -> abort() ȣ��
	std::abort();
}