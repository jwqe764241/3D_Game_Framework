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

using EnvironmentList = std::vector<IRenderable *>;
using ActorList = std::vector<ICharacter *>;

class TestLevel1 : public ILevel{
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

	const D3DXVECTOR2 m_PosList[10] = {
		{ 30, 50 },
		{ 60, 400 },
		{ 100, 50 },
		{ 300, 60 },
		{ 700, 500 },
		{ 550, 300 },
		{ 340, 400 },
		{ 200, 350 },
		{ 200, 500 },
		{ 30, 500 },
	};
	const D3DXVECTOR2 m_SpawnPoint[5] = {
		{200, 0},
		{700, 500},
		{500, 40},
		{300, 300},
		{700, 500}
	};

	RECT m_LevelSize;

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