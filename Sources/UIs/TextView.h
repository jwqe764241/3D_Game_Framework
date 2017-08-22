#pragma once

#include "Sources\Interface\IRenderable.h"

class TextView : public IRenderable
{
public:
	TextView();
	~TextView();

	//��Ʈ��, ���� ��, ���� ������ �͵鿡 ���� �ڿ��� �ε�
	virtual void Load(ID3D11Device* device, int bitmapWidth, int bitmapHeight) override;
	//���� ������ �͵鿡�� ���� �ڿ� ����
	virtual void Release() override;
	//���� ������ �͵��� ���¸� �ʱ�ȭ
	virtual void Reset() override;
	//���� ������ �͵��� ���¸� ������Ʈ
	virtual void Update(float dt) override;

	//���� 1. ��� ���� Ŭ������ ��ǥ�� ������ ���� ��쿡
	//virtual void Render(ID3D11DeviceContext* deviceContext) override;
	virtual void Render(ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight) override;

	//�ε��� ���� ��������
	virtual int GetIndexCount() override;
	//������ �ؽ��� ��������
	virtual ID3D11ShaderResourceView* GetTexture() override;
	//������ ��������
	virtual D3DXVECTOR2 GetPosition() const override;
	//������ �����ϱ�
	virtual void SetPosition(const D3DXVECTOR2 pos) override;
	/*
	Renderable�� �⺻������ GameSprite��
	��������� ������ ���� ���̰�,
	GameSprite�� ���� �̿��Ͽ� Ÿ ������ ������ ��
	�����Ƿ� �ش� �Լ��� �߰��ϰ� ��
	*/
	virtual GameSprite* GetSprite() override;

private:
	wchar_t *m_text;
};