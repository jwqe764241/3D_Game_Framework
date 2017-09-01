#pragma once

#include <d3dx10math.h>

class CGameCamera 
{
private:
	D3DXVECTOR3 Position;
	D3DXVECTOR3 Rotation;
	D3DXMATRIX ViewMatrix;

public:
	CGameCamera();
	~CGameCamera();

	//ī�޶� ��ġ ���� -> x, y, z
	void SetPosition(float x, float y, float z);
	void SetPosition(const D3DXVECTOR3& position);

	//ī�޶� ȸ�� ���� -> �ǵ��� ��� ���� �ʱ�
	void SetRotation(float x, float y, float z);
	void SetRotation(const D3DXVECTOR3& rotation);

	//ī�޶� ���� ��������
	D3DXVECTOR3 GetPosition() const;
	D3DXVECTOR3 GetRotation() const;

	//ī�޶� ���� (��� ����)
	void Render();
	//�� ��� ��������
	D3DXMATRIX& GetViewMatrix();
};