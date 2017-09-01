#pragma once

#include <Sources/GameApp.h>
#include <Sources/Camera/GameCamera.h>
#include <Sources/Geometries/GameSprite.h>
#include <Sources/GUI/Button.h>
#include <Sources/Interface/ILevel.h>
#include <Sources/Input/GameInput2.h>
#include <Sources/Level/GameLevelLoader.h>
#include <Sources/Level/LobbyLevel.h>

class DummyLevel : public ILevel{
private:
	GameBitmap LevelBitmap;
	CGameCamera Camera;

	Button MenuButton;

public:
	DummyLevel();
	~DummyLevel();

	// ILevel��(��) ���� ��ӵ�
	virtual bool Load() override;
	virtual void Unload() override;
	virtual void Update(float dt) override;
	virtual bool Render(ID3D10Device * device, int screenWidth, int screenHeight) override;
	virtual void onStart() override;
	virtual void onEnd() override;
};