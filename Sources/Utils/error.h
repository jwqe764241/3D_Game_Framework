/*
	jwqe764241 �ۼ�
*/

//TODO: C, C++ �Ѵ� ��� ����? __cplusplus

#ifndef ERROR_H
#define ERROR_H


#include <Sources/GameApp.h>

//����� ����϶�
#ifndef NDEBUG
	#define ERROR_TEST_ENABLE
#endif


typedef LONG ERROR__;

void __cdecl ErrorHandler(
	_In_	char const * const	fileName,
	_In_	char const * const	funcName,
	_In_	const unsigned		lineNumber,
	_In_	char const * const	condition,
	_In_	char const * const	message
);

#define HR(expression)														\
		{																	\
			HRESULT hr = (expression);										\
			if (FAILED(hr)) {												\
				abort();														\
			}																\
		}																	\

#define CUSTOM_ASSERT(condition, message)														\
	if (!(condition)) {																			\
		ErrorHandler(__FILE__, __FUNCTION__, __LINE__, #condition, message);	\
	}																							\

#define TEST____(message)					\
	{										\
		std::cout << "TEST : ";				\
		std::cout << message << std::endl;	\
	}										\

#ifdef ERROR_TEST_ENABLE
	#define GAME_ASSERT(condition, message) CUSTOM_ASSERT(condition, message)
	#define GAME_TEST_TEST_PRINT(message) TEST____(message)
	#define CHECK_HR(expression) HR(expression)
#else	//����� ��尡 �ƴϸ� �ƹ� ���� ���� ����
	#define GAME_ASSERT(condition, message)
	#define GAME_TEST_TEST_PRINT(message)
	#define CHECK_HR(expression)
#endif


#endif