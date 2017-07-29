#include <Sources/GameApp.h>
#include <Sources/Utils/console.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK,__FILE__, __LINE__)
#endif

#define _COMMAND_OPEN_CONSOLE

#if defined(_MBCS)

	//For Multubyte

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR IpCmdLine, int nCmdShow) {

	///MessageBox(NULL, "YES!!", "TEST", MB_OK);

}

#elif defined(UNICODE) || defined(_UNICODE)

	//For Unicode	->	Use this

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
//������Ʈ ������ �����ڵ� �������� �̹Ƿ� wWinMain�� �����ε�
{
	//�޸� ���� �˻� ����
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_REPORT_FLAG);

	//����� ����� ��쿡 �ܼ� ����
	#if defined(_COMMAND_OPEN_CONSOLE)
		console::ConsoleBuffer consoleBuff = console::openConsole();
	#endif

	//���� �ν��Ͻ� ���� �� ����
	CGameApp::GetInstance().Initialize(hInstance, L"TEST", L"WND_CLASS_TEST", nCmdShow, 800, 600, 1000.0f, 0.1f);
	//CGameApp * pGameApp = new CGameApp(hInstance, L"TEST", L"WND_CLASS_TEST", nCmdShow, 800, 600, 1000.0f, 0.1f);
	CGameApp::GetInstance().Launch();
	CGameApp::GetInstance().Release();

	#if defined(_COMMAND_OPEN_CONSOLE)
		system("pause");
		console::closeConsole(consoleBuff);
	#endif

	return 0;
}

#else

	///No Settings 
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

}

#endif
