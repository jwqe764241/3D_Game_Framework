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
#include <Sources/Assets/Tool.h>

/*
	�ϴ� ����Ʈ 2���̰�, for�� 2������ �Ƹ� ��� �ذ� �� ����� ���� ���̴� ����...
	���� �ȵ�� ��

	���� �켱������ ��� ������ �� �ֳ� �������̱� �ѵ� (� �ֱ� �ϴ�)
	�ٵ� �̷��� ��ɵ��� �߰��ع����� ���� �űⰡ�� ĥ �� ��������
*/


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

private:
	std::vector<Tool *> m_Tools;
	std::vector<ICharacter *> m_ActorList;
	std::vector<IRenderable *> m_EnvironmentList;
	
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