#pragma once

#include <d3d10_1.h>

#include "Sources\Shaders\GameTexture.h"
#include "Sources\Geometries\GameBitmap.h"
#include "Sources\GameDefs.h"

class GameSprite : public GameBitmap
{
public:
	GameSprite(float framesPerSecond, float animationSpeed = 1.0f, bool isLooping = false);
	virtual ~GameSprite();

	void Initialize(ID3D10Device *device, wchar_t *filePath, int bitmapWidth, int bitmapHeight, float numberOfMotions);
	void Update(float dt);
	void Render(ID3D10Device* device, int screenWidth, int screenHeight, float posX, float posY);

	void SetMotion(float index);
	void SetLooping(bool condition);

	/*
		���� ������ ���Ͽ� 4�� �Լ� �߰��Ͽ���
	*/
	float GetMaxFrame() const;
	float GetMotionNumber() const;
	float GetFrameWidth() const;
	float GetFrameHeight() const;

protected:
	void UpdateBuffers(ID3D10Device *device);

private:
	float m_currentFrame;
	float m_previousFrame;
	float m_maxFrames;
	float m_animationSpeed;
	float m_currentSpeed;
	float m_framesPerSecond;

	float m_numOfMotions;
	float m_currentMotion;

	float m_frameWidth;
	float m_frameHeight;

	bool m_isLooping;
};