#pragma once

#include <D3DX11.h>

#include <Sources/Geometries/GameBitmap.h>
#include <Sources/Interface/IRenderable.h>

class Button : public IRenderable{
private:
	GameBitmap* m_statusBitmap[2];
	GameBitmap* m_pCurrBitmap = nullptr;

	D3DXVECTOR2 m_pos;

public:
	Button();
	~Button();

	// IRenderable��(��) ���� ��ӵ�
	virtual void Load(ID3D11Device * device, int bitmapWidth, int bitmapHeight) override;
	virtual void Release() override;
	virtual void Reset() override;
	virtual void Update(float dt) override;
			void Update(bool selected);
	virtual void Render(ID3D11DeviceContext * deviceContext, int screenWidth, int screenHeight) override;
	virtual int GetIndexCount() override;
	virtual ID3D11ShaderResourceView * GetTexture() override;
	virtual D3DXVECTOR2 GetPosition() const override;
	virtual void SetPosition(const D3DXVECTOR2 pos) override;
	virtual GameSprite * GetSprite() override;
};