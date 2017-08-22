#pragma once

#include <D3D11.h>

class ILevel {
public:
	//������ �ʿ��� ���µ� �ε�
	virtual bool Load()           = 0;
	//�Ҵ��� ���µ� ���� �� ���� ����
	virtual void Unload()         = 0;
	//�Է¹��� Ű, ��ǥ�̵� ���� ������Ʈ
	virtual void Update(float) = 0;
	//�ش� ������ ���
	virtual bool Render(ID3D11DeviceContext*, int, int) = 0;
	
	//���� ���� �� 
	virtual void onStart() = 0;
	//���� ���� �� -> ���� ���� ��
	virtual void onEnd() = 0;

};