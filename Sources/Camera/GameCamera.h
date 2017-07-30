#ifndef __GAMECAMERA_H
#define __GAMECAMERA_H

#include <D3DX10math.h>

class CGameCamera {
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

private:
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXMATRIX m_ViewMatrix;	
};

#endif