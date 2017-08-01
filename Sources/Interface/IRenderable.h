#pragma once

#include <D3D11.h>
#include <Sources/Geometries/GameSprite.h>

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