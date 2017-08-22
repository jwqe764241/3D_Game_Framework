#pragma once

#include <vector>
#include <Sources/GameApp.h>

#include <Sources/GameDefs.h>
#include <Sources/GameAssetLoader.h>
#include <Sources/Camera/GameCamera.h>
#include <Sources/Input/GameInput2.h>
#include <Sources/Interface/IRenderable.h>
#include <Sources/Interface/ILevel.h>

/*
	�ϴ� ����Ʈ 2���̰�, for�� 2������ �Ƹ� ��� �ذ� �� ����� ���� ���̴� ����...
	���� �ȵ�� ��

	���� �켱������ ��� ������ �� �ֳ� �������̱� �ѵ� (� �ֱ� �ϴ�)
	�ٵ� �̷��� ��ɵ��� �߰��ع����� ���� �űⰡ�� ĥ �� ��������
*/

//const D3DXVECTOR2 CameraPos[] = {
//	{ 0 ,0 },
//	{ 1920, 0 },
//	{ 3840, 0 },
//	{ 5760, 0 }
//};

class TestLevel1 : public ILevel{
private:
	const int cameraPosX[4] = {
		0, 1920, 3840, 5760
	};

	const int cameraPosY[4] = {
		0, -1080, -2160, -3240
	};
private:
	/*
		Ǯ ���� �͵�
	*/
	EnvironmentList m_EnvironmentList;
	/*
		���� ���� �͵�
	*/
	ActorList m_ActorList;
	Player* m_Player;
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
	virtual bool Render(ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight) override;

	virtual void onStart() override;
	virtual void onEnd() override;
};