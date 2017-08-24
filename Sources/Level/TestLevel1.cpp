#include <Sources/Level/TestLevel1.h>

TestLevel1::TestLevel1()
{

}

TestLevel1::~TestLevel1()
{
	Unload();
}

bool TestLevel1::Load()
{
	m_EnvironmentList.reserve(20);
	m_ActorList.reserve(20);

	m_LevelBitmap.Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/background.png", 7680, 4320);

	m_LevelSize.top = 0;
	m_LevelSize.bottom = 4320;
	m_LevelSize.left = 0;
	m_LevelSize.right = 7680;

	//�÷��̾� ����
	m_Player = dynamic_cast<Player*>(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_PLAYER, 576, 256));

	WindowSize size = CGameApp::GetInstance().GetWindowSize();
	m_Camera.SetPosition(0.0f, 0.0f, -10.0f);
	
	m_Player->SetPositionLimit(&m_LevelSize);

	m_Cursor.Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/cursor.png", 50, 50);

	stateBar[0].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/HealthState.png", 200, 50, 100, 100);
	stateBar[1].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/WaterState.png", 200, 50, 100, 100);
	stateBar[2].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/FoodState.png", 200, 50, 100, 100);
	stateBar[3].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/SleepState.png", 200, 50, 100, 100);
	stateBar[4].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/EmptyState.png", 200, 50, 100, 100);

	onStart();

	return true;
}

void TestLevel1::Unload()
{
	m_LevelBitmap.Release();
	m_Cursor.Release();

	for (auto target : m_EnvironmentList)
	{
		target->Release();
	}

	for (auto target : m_ActorList)
	{
		target->Release();
	}
	
	for (auto& target : stateBar)
	{
		target.Release();
	}

	Utils::Release(&m_Player);
}

void TestLevel1::Update(float dt) 
{
	for (auto target : m_EnvironmentList)
	{ 
		target->Update(dt);
	}

	//for (auto target : m_ActorList)
	//{
	//	target->Update(dt);
	//}

	/*
		�����̽��� ���� �ÿ� ī�޶� Ʈ��ŷ
		��ġ ������ Player�� ȭ�� �߾ӿ� ������ ��
	*/
	//GameInput ����
	//if (GameInput::GetInstance().IsKeyPressed(DIK_SPACE))
	//{
	//	D3DXVECTOR2 pos = m_Player->GetPosition();
	//	float width  = CGameApp::GetInstance().GetWindowSize().width;
	//	float height = CGameApp::GetInstance().GetWindowSize().height;

	//	m_Camera.SetPosition(pos.x - ((width / 2) - m_Player->GetSprite()->GetFrameWidth()), 
	//		(pos.y - ((height / 2) - m_Player->GetSprite()->GetFrameHeight())) * -1 , -10.0f);
	//}

	//GameInput2 ����

	D3DXVECTOR2 pos  = m_Player->GetPosition();
	WindowSize size  = CGameApp::GetInstance().GetWindowSize();
	float halfWidth  = size.width / 2;
	float halfHeight = size.height / 2;
	//��ġ��

	int a1 = pos.x / 1920;
	int a2 = pos.y / 1080;

	m_Camera.SetPosition(cameraPosX[a1], cameraPosY[a2], -10.f);

	//if (pos.x + m_Player->GetSprite()->GetFrameWidth() >= (halfWidth) && pos.x <= m_LevelSize.right - (halfWidth) ||
	//	pos.y >= (halfHeight) && pos.y <= m_LevelSize.bottom - (halfHeight))
	//{
	//	m_Camera.SetPosition(pos.x - ((size.width / 2) - m_Player->GetSprite()->GetFrameWidth()),
	//		(pos.y - ((size.height / 2) - m_Player->GetSprite()->GetFrameHeight())) * -1, -10.0f);
	//}

	//float x = pos.x - ((size.width / 2) - m_Player->GetSprite()->GetFrameWidth());
	//float y = (pos.y - ((size.height / 2) - m_Player->GetSprite()->GetFrameHeight())) * -1;

	m_Player->Update(dt);
		stateBar[0].SetValue(m_Player->GetHealth());
		stateBar[1].SetValue(m_Player->GetWaterValue());
		stateBar[2].SetValue(m_Player->GetFoodValue());
		stateBar[3].SetValue(m_Player->GetSleepValue());
}

bool TestLevel1::Render(ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight)
{
	TextureShader& instance = TextureShader::GetInstance();
	D3DXMATRIX worldMatrix  = CGameApp::GetInstance().GetWorldMatrix();
	D3DXMATRIX orthMatrix   = CGameApp::GetInstance().GetorthogonalMatrix();
	WindowSize size         = CGameApp::GetInstance().GetWindowSize();
	D3DXVECTOR3 cameraPos   = m_Camera.GetPosition();
	POINT pos               = GameInput2::GetInstance().GetMousePosition();

	m_Camera.Render();

	m_LevelBitmap.Render(deviceContext, screenWidth, screenHeight, 0, 0);
	instance.Render(deviceContext, m_LevelBitmap.GetIndexCount(), worldMatrix, 
		m_Camera.GetViewMatrix(), orthMatrix, m_LevelBitmap.GetTexture());

	/*
		�׽�Ʈ �����̹Ƿ� �÷��̾� ���� ����
	*/
	m_Player->Render(deviceContext, screenWidth, screenHeight);
	instance.Render(deviceContext, m_Player->GetIndexCount(), worldMatrix, 
		m_Camera.GetViewMatrix(), orthMatrix, m_Player->GetTexture());

	/*
		���� ����Ʈ�� ��ϵ� ��������Ʈ ����
	*/
	for (auto target : m_EnvironmentList)
	{
		target->Render(deviceContext, screenWidth, screenHeight);

		instance.Render(deviceContext, target->GetIndexCount(), worldMatrix, 
			m_Camera.GetViewMatrix(), orthMatrix, target->GetTexture());
	}

	for (int i = 0; i < 4; i++)
	{
		//�� ���� ���� ����
		stateBar[4].Render(deviceContext, screenWidth, screenHeight, (cameraPos.x + 25) + (200 * i) + (25 * i), (cameraPos.y * -1) + 25);
		instance.Render(deviceContext, stateBar[i].GetIndexCount(), worldMatrix,
			m_Camera.GetViewMatrix(), orthMatrix, stateBar[4].GetTexture());

		//���� ���� ����
		stateBar[i].Render(deviceContext, screenWidth, screenHeight, (cameraPos.x + 25) + (200 * i) + (25 * i), (cameraPos.y * -1) + 25);
		instance.Render(deviceContext, stateBar[i].GetIndexCount(), worldMatrix,
			m_Camera.GetViewMatrix(), orthMatrix, stateBar[i].GetTexture());
	}

	m_Cursor.Render(deviceContext, size.width, size.height, pos.x + cameraPos.x, pos.y - cameraPos.y);

	instance.Render(deviceContext, m_Cursor.GetIndexCount(), worldMatrix, 
		m_Camera.GetViewMatrix(), orthMatrix, m_Cursor.GetTexture());

	return true;
}

void TestLevel1::onStart()
{

}

void TestLevel1::onEnd()
{

}