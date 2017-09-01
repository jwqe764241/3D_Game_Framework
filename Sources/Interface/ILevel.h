#pragma once

#include <vector>
#include <d3d10_1.h>
#include <Sources/Interface/ICharacter.h>

class ILevel {
public:
	//������ �ʿ��� ���µ� �ε�
	virtual bool Load()           = 0;
	//�Ҵ��� ���µ� ���� �� ���� ����
	virtual void Unload()         = 0;
	//�Է¹��� Ű, ��ǥ�̵� ���� ������Ʈ
	virtual void Update(float dt) = 0;
	//�ش� ������ ���
	virtual bool Render(ID3D10Device* device, int screenWidth, int screenHeight) = 0;
	
	//���� ���� �� 
	virtual void onStart() = 0;
	//���� ���� �� -> ���� ���� ��
	virtual void onEnd() = 0;

};