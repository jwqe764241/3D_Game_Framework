#pragma once

#include <d3d10_1.h>
#include <Sources/Geometries/GameSprite.h>

class IRenderable
{
public:
	//��Ʈ��, ���� ��, ���� ������ �͵鿡 ���� �ڿ��� �ε�
	virtual void Load(ID3D10Device* device, int bitmapWidth, int bitmapHeight) = 0;
	//���� ������ �͵鿡�� ���� �ڿ� ����
	virtual void Release()        = 0;
	//���� ������ �͵��� ���¸� �ʱ�ȭ
	virtual void Reset()          = 0;
	//���� ������ �͵��� ���¸� ������Ʈ
	virtual void Update(float dt) = 0;
	
	//���� 1. ��� ���� Ŭ������ ��ǥ�� ������ ���� ��쿡
	//virtual void Render(ID3D11DeviceContext* deviceContext) = 0;
	virtual void Render(ID3D10Device* device, int screenWidth, int screenHeight) = 0;
	
	//�ε��� ���� ��������
	virtual int GetIndexCount() = 0;
	//������ �ؽ��� ��������
	virtual ID3D10ShaderResourceView* GetTexture() = 0;
	//������ ��������
	virtual D3DXVECTOR2 GetPosition() const = 0;
	//������ �����ϱ�
	virtual void SetPosition(const D3DXVECTOR2 pos) = 0;
	/*
		Renderable�� �⺻������ GameSprite��
		��������� ������ ���� ���̰�,
		GameSprite�� ���� �̿��Ͽ� Ÿ ������ ������ ��
		�����Ƿ� �ش� �Լ��� �߰��ϰ� ��
	*/
	virtual GameSprite* GetSprite() = 0;
};