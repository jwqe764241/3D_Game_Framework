#pragma once

#include <Windows.h>
#include <cassert>

/*
	GameInput�� �ٸ� ������
	���� GameInput�� ������ ������ ����.
	 1. Direct Input �� ����ϸ� �޽����� �ޱ� ���� �����尡 ���ο��� �����ȴ�.
	 2. ���콺 ������ �������� ������ �ִ�.
	 3.���콺 ��ǥ�� ���� ��ǥ �������̴�.

	�׷��� ������ �ش� ������ ���� ��ǥ���� ���ϱ⿡ ���� ������װ� ����� �ִ�.
	�����ڿ����� ���� ���ν������� ���� ������Ʈ �ϸ鼭 �Է°��� ��´�.
*/

class GameInput2 {
private:
	unsigned char m_KeyboardState[256];
	POINT m_MousePosition;

public:
	GameInput2();
	~GameInput2();
	
	static GameInput2& GetInstance();

	/*
		�ʱ�ȭ �������� ����� �� ���̱� ������
		�ش� ������ �ڵ��� �Ѱܹ޴´�.
	*/
	void Initialize(const HWND hWnd);

	/*
		�ش� �Լ� public���� ������ ���� �ƴ�
		������ ���ܾ� ��
	*/
	void PressKey(int keycode);
	void ReleaseKey(int keycode);
	void UpdateMousePosition(POINT pos);

	bool IsPressed(int keycode) const;
	POINT GetMousePosition() const;
};