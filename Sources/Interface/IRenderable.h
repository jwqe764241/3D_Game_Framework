#pragma once

#include <D3D11.h>

class IRenderable
{
public:
	//��Ʈ��, ���� ��, ���� ������ �͵鿡 ���� �ڿ��� �ε�
	virtual void Load(ID3D11Device* device, int bitmapWidth, int bitmapHeight) = 0;
	//���� ������ �͵鿡�� ���� �ڿ� ����
	virtual void Release()        = 0;
	//���� ������ �͵��� ���¸� �ʱ�ȭ
	virtual void Reset()          = 0;
	//���� ������ �͵��� ���¸� ������Ʈ
	virtual void Update(float dt) = 0;
	
	//���� 1. ��� ���� Ŭ������ ��ǥ�� ������ ���� ��쿡
	//virtual void Render(ID3D11DeviceContext* deviceContext) = 0;
	virtual void Render(ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight) = 0;
	
	//�ε��� ���� ��������
	virtual int GetIndexCount() = 0;
	//������ �ؽ��� ��������
	virtual ID3D11ShaderResourceView* GetTexture() = 0;
};