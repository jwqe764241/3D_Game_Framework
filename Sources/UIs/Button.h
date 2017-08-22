#pragma once

#include "Sources\Geometries\GameBitmap.h"
#include "Sources\Interface\IRenderable.h"

class Button : public IRenderable
{
public:
	Button(wchar_t* buttonText = L"Button", float x = 0, float y = 0, float width = 50, float height = 20);
	~Button();

	//��Ʈ��, ���� ��, ���� ������ �͵鿡 ���� �ڿ��� �ε�
	virtual void Load(ID3D11Device* device, int width, int height) override;
			void Load(ID3D11Device* device, wchar_t* normalImagePath, wchar_t* hoveredImagePath = nullptr, wchar_t* clickedImagePath = nullptr);
	//���� ������ �͵鿡�� ���� �ڿ� ����
	virtual void Release() override;
	//���� ������ �͵��� ���¸� �ʱ�ȭ
	virtual void Reset() override;
	//���� ������ �͵��� ���¸� ������Ʈ
	virtual void Update(float dt) override;
			void Update(float x, float y);

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

	virtual GameSprite* GetSprite() = 0;

private:
	bool IsHovered(float x, float y);


private:
	GameBitmap m_normalButtonImage,
			   m_hoveredButtonImage,
			   m_clickedButtonImage;

	wchar_t *m_normalButtonImagePath,
			*m_hoveredButtonImagePath,
			*m_clickedButtonImagePath;

	float m_posX, m_posY;

	float m_width, m_height;

	bool m_hovered, m_clicked;
};