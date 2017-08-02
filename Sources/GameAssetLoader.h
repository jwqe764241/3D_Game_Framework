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

//TODO: Ȯ���� ���� �ش� ������ �����ϱ�
using TargetInterface = IRenderable;

class CGameAssetLoader {
	//����� �� �����Ƿ� 
public:
	CGameAssetLoader();
	~CGameAssetLoader();
	
	static CGameAssetLoader& GetInstance();
	void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, int* screenWidth, int* screenHeight);
	void Release();

	//���� �ҷ��� �� Map�� ����
	TargetInterface* LoadAsset(int id, int bitmapWidth, int bitmapHeight);
	//TargetInterface* GetAsset(std::string id);

private:
	//void ClearMap();

private:
	//ICharacter�� �´°�...
	/*std::map<std::string, TargetInterface*> m_AssetMap;*/

	std::vector<TargetInterface *> m_AllocList;

	ID3D11Device * m_DeviceRef;
	ID3D11DeviceContext* m_DeviceContextRef;

	int* m_ScreenWidthRef;
	int* m_ScreenHeightRef;	
};