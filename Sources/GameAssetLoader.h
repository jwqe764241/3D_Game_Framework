#ifndef __GAMEASSETLOADER
#define __GAMEASSETLOADER

#include <map>

#include <Sources/Objects/IRenderable.h>

using TargetInterface = IRenderable;

class CGameAssetLoader {
	//����� �� �����Ƿ� 

public:
	CGameAssetLoader();
	~CGameAssetLoader();
	
	void Release();

	//���� �ҷ��� �� Map�� ����
	void LoadAsset(IRenderable* target, int id);
	TargetInterface* GetAsset(int id);

private:
	void ClearMap();

private:
	//ICharacter�� �´°�...
	std::map<int, TargetInterface*> m_AssetMap;
	
};

#endif