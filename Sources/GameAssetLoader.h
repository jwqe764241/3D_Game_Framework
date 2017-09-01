#pragma once

#include <vector>

#include <Sources/Assets/TestAsset.h>
#include <Sources/Assets/SpriteAsset.h>
#include <Sources/Assets/Player.h>
#include <Sources/Assets/Enemy1.h>
#include <Sources/Interface/ICharacter.h>
#include <Sources/GameDefs.h>

enum AssetID {
	//TetAsset�� �� �״�� �׽�Ʈ�̱� ������ �׽�Ʈ ������ ���̵� �߰��� ��
	ID_ASSET_TESTASSET = 50,
	ID_ASSET_SPRITEASSET = 60,
	ID_ASSET_PLAYER,
	ID_ASSET_ENEMY1
};

class CGameAssetLoader 
{
private:
	std::vector<IRenderable*> AllocationList;

	ID3D10Device* DeviceRef;

	int* ScreenWidthRef;
	int* ScreenHeightRef;

public:
	CGameAssetLoader();
	virtual ~CGameAssetLoader();
	
	static CGameAssetLoader& GetInstance();
	void Initialize(ID3D10Device* device, int* screenWidth, int* screenHeight);
	void Release();

	//���� �ҷ��� �� Map�� ����
	IRenderable* LoadAsset(int id, int bitmapWidth, int bitmapHeight);
};