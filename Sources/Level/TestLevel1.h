#pragma once

#include <vector>
#include <algorithm>
#include <Sources/GameApp.h>
#include <Sources/GameDefs.h>
#include <Sources/GameAssetLoader.h>
#include <Sources/Camera/GameCamera.h>
#include <Sources/Input/GameInput2.h>
#include <Sources/Assets/StateUI.h>
#include <Sources/Interface/ILevel.h>
#include <Sources/Assets/Rock.h>
#include <Sources/Assets/Tool.h>

/*
	�ϴ� ����Ʈ 2���̰�, for�� 2������ �Ƹ� ��� �ذ� �� ����� ���� ���̴� ����...
	���� �ȵ�� ��

	���� �켱������ ��� ������ �� �ֳ� �������̱� �ѵ� (� �ֱ� �ϴ�)
	�ٵ� �̷��� ��ɵ��� �߰��ع����� ���� �űⰡ�� ĥ �� ��������
*/

struct environmentElement
{
	wchar_t * filePath;
	float width;
	float height;
	int x;
	int y;
};

class TestLevel1 : public ILevel {
private:
	const int cameraPosX[4] = {
		0, 1920, 3840, 5760
	};

	const int cameraPosY[4] = {
		0, -1080, -2160, -3240
	};

	const POINT toolsPosition[5] = {
		{3500, 2500},
		{1500, 100},
		{7300, 4000},
		{300, 4000},
		{6300, 1000}
	};
	
	const environmentElement environmentList[3] = {
		{ L"../Resources/Rock1.png", 171, 97, 1600, 100},
		{ L"../Resources/Rock2.png", 171, 125, 1700, 200},
		{ L"../Resources/Rock3.png", 165, 121, 1700, 300}
	};

private:
	std::vector<Tool *> m_Tools;
	std::vector<ICharacter *> m_ActorList;
	std::vector<IInteraction *> m_EnvironmentList;
	
	Player* m_Player;

	StateUI m_PlayerUI;

	CGameCamera m_Camera;

	GameBitmap m_Cursor;

	RECT m_LevelSize;
	GameBitmap m_LevelBitmap;


public:
	TestLevel1();
	~TestLevel1();

	virtual bool Load() override;
	virtual void Unload() override;
	virtual void Update(float dt) override;
	virtual bool Render(ID3D10Device* device, int screenWidth, int screenHeight) override;

	virtual void onStart() override;
	virtual void onEnd() override;
	void onGameOver();
};