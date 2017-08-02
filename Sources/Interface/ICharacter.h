#pragma once

#include <D3DX10math.h>

#include <Sources/Interface/IRenderable.h>

/*
	������ ICharacter �������̽��� ��ӹ޴� Ŭ���� �鵵
	���� ����̱� ������ IRenderable�� ��ӽ�Ŵ
*/

class ICharacter : public IRenderable
{
public:
	virtual void Idle()                      = 0;
	virtual void Move(D3DXVECTOR3 target)    = 0;
	virtual void Attack(void** target)       = 0; // attack close target or target attack.
	//virtual void Attack(XMVECTORF32 direction, Wepon wepon); // long target or non-target attack.
	/*
		���ϰ� Damage bool������ ���� �� ������ ���Ŀ�
		�ٷ� �޸����� ó�� ������
	*/
	virtual void Damage(int damage) = 0;
	virtual void Die()              = 0;

	virtual bool isDied() = 0;
};