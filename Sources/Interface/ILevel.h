#pragma once

#include <D3D11.h>
#include <vector>
#include <Sources/Interface/ICharacter.h>

using EnvironmentList = std::vector<IRenderable *>;
using ActorList = std::vector<ICharacter *>;

class ILevel {
public:
	//������ �ʿ��� ���µ� �ε�
	virtual bool Load()           = 0;
	//�Ҵ��� ���µ� ���� �� ���� ����
	virtual void Unload()         = 0;
	//�Է¹��� Ű, ��ǥ�̵� ���� ������Ʈ
	virtual void Update(float dt) = 0;
	//�ش� ������ ���
	virtual bool Render(ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight) = 0;
	
	//���� ���� �� 
	virtual void onStart() = 0;
	//���� ���� �� -> ���� ���� ��
	virtual void onEnd() = 0;

};