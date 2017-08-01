#include <Sources/Level/TestLevel1.h>

TestLevel1::TestLevel1()
{

}

TestLevel1::~TestLevel1()
{

}

bool TestLevel1::Load()
{
	m_RenderList.reserve(20);

	/*
		�׽�Ʈ �������� ���� ���� 10�� �߰�
	*/
	D3DXVECTOR2 posList[10];
	posList[0] = { 30, 50 };
	posList[1] = { 60, 400 };
	posList[2] = { 100, 50 };
	posList[3] = { 300, 60 };
	posList[4] = { 700, 500 };
	posList[5] = { 550, 300 };
	posList[6] = { 340, 400 };
	posList[7] = { 200, 350 };
	posList[8] = { 200, 500 };
	posList[9] = { 30, 500 };

	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));
	m_RenderList.push_back(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_TESTASSET, 32, 32));

	for (int i = 0; i < 10; ++i)
	{
		m_RenderList[i]->SetPosition(posList[i]);
	}

	//�÷��̾� ����
	m_Player = dynamic_cast<Player*>(CGameAssetLoader::GetInstance().LoadAsset(ID_ASSET_PLAYER, 576, 256));
	m_Camera.SetPosition(0.0f, 0.0f, -10.0f);

	onStart();

	return true;
}

void TestLevel1::Unload()
{
	for (auto target : m_RenderList)
	{
		target->Release();
	}
	
	Utils::Release(&m_Player);
}

void TestLevel1::Update(float dt)
{
	for (std::vector<IRenderable*>::iterator idx = m_RenderList.begin(); idx != m_RenderList.end(); idx++)
	{
		(*idx)->Update(dt);
	}

	m_Player->Update(dt);
	/*
		�����̽��� ���� �ÿ� ī�޶� Ʈ��ŷ
		��ġ ������ Player�� ȭ�� �߾ӿ� ������ ��
	*/
	if (GameInput::GetInstance().IsPressed(DIK_SPACE))
	{
		D3DXVECTOR2 pos = m_Player->GetPosition();
		float width  = CGameApp::GetInstance().GetWindowSize().width;
		float height = CGameApp::GetInstance().GetWindowSize().height;

		m_Camera.SetPosition(pos.x - ((width / 2) - m_Player->GetSprite()->GetFrameWidth()), 
			(pos.y - ((height / 2) - m_Player->GetSprite()->GetFrameHeight())) * -1 , -10.0f);
	}
}

bool TestLevel1::Render(ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight)
{
	m_Camera.Render();

	/*
		�׽�Ʈ �����̹Ƿ� �÷��̾� ���� ����
	*/
	m_Player->Render(deviceContext, screenWidth, screenHeight);
	TextureShader::GetInstance().Render(deviceContext, m_Player->GetIndexCount(), CGameApp::GetInstance().GetWorldMatrix(), m_Camera.GetViewMatrix(),
		CGameApp::GetInstance().GetorthogonalMatrix(), m_Player->GetTexture());

	/*
		���� ����Ʈ�� ��ϵ� ��������Ʈ ����
	*/
	for (std::vector<IRenderable*>::iterator idx = m_RenderList.begin(); idx != m_RenderList.end(); idx++)
	{
		(*idx)->Render(deviceContext, screenWidth, screenHeight);

		TextureShader::GetInstance().Render(deviceContext, (*idx)->GetIndexCount(), CGameApp::GetInstance().GetWorldMatrix(), m_Camera.GetViewMatrix(),
			CGameApp::GetInstance().GetorthogonalMatrix(), (*idx)->GetTexture());
	}

	return true;
}


void TestLevel1::onStart()
{

}

void TestLevel1::onEnd()
{

}