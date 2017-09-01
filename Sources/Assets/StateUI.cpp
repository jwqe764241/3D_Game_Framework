#include <Sources/Assets/StateUI.h>


#include <Sources/GameApp.h>

StateUI::StateUI()
{

}

StateUI::~StateUI()
{
	Release();
}

void StateUI::Initialize(ID3D10Device * pDevice, std::vector<Tool *>* pToolList, std::vector<Item *>* pItemList)
{
	UIStateBar[0].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/HealthState.png", 200, 50, 100, 100);
	UIStateBar[1].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/WaterState.png", 200, 50, 100, 100);
	UIStateBar[2].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/FoodState.png", 200, 50, 100, 100);
	UIStateBar[3].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/SleepState.png", 200, 50, 100, 100);
	UIStateBar[4].Initialize(CGameApp::GetInstance().GetDevice(), L"../Resources/EmptyState.png", 200, 50, 100, 100);

	ToolList = pToolList;
	ItemList = pItemList;

	writer_48size.Initialize(pDevice, 48, 0);
	writer_25size.Initialize(pDevice, 25, 0);
}

void StateUI::Release()
{
	for (auto& target : UIStateBar)
	{
		target.Release();
	}
}

void StateUI::Update(int healthValue, int waterValue, int foodValue, int sleepValue)
{
	UIStateBar[0].SetValue(healthValue);
	UIStateBar[1].SetValue(waterValue);
	UIStateBar[2].SetValue(foodValue);
	UIStateBar[3].SetValue(sleepValue);
}

void StateUI::Render(ID3D10Device* device, int screenWidth, int screenHeight,
	D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX orthMatrix, D3DXVECTOR3 cameraPos, TextureShader& instance)
{
	for (int i = 0; i < 4; i++)
	{
		//�� ���� ���� ����
		UIStateBar[4].Render(device, screenWidth, screenHeight, (cameraPos.x + 25) + (225 * i), (cameraPos.y * -1) + 25);
		instance.Render(device, UIStateBar[i].GetIndexCount(), worldMatrix,
			viewMatrix, orthMatrix, UIStateBar[4].GetTexture());

		//���� ���� ����
		UIStateBar[i].Render(device, screenWidth, screenHeight, (cameraPos.x + 25) + (225 * i), (cameraPos.y * -1) + 25);
		instance.Render(device, UIStateBar[i].GetIndexCount(), worldMatrix,
			viewMatrix, orthMatrix, UIStateBar[i].GetTexture());
	}

	//if (GameInput2::GetInstance().IsPressed(0x54))
	//{
		for (int i = 0; i < ToolList->size(); i++)
		{
			(*ToolList)[i]->Render(device, screenWidth, screenHeight, (cameraPos.x + 25) + (75 * i), (cameraPos.y * -1) + 1000);

			instance.Render(device, (*ToolList)[i]->GetIndexCount(), worldMatrix,
				viewMatrix, orthMatrix, (*ToolList)[i]->GetTexture());
		}

		writer_48size.DrawString(L"���� ������", RECT{ 25, 925, 1920, 1080 }, DT_LEFT | DT_TOP, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//}

	//if (GameInput2::GetInstance().IsPressed(0x49))
	//{
		for (int i = 0; i < ItemList->size(); i++)
		{
			(*ItemList)[i]->Render(device, screenWidth, screenHeight,
				cameraPos.x + ItemRenderPosition[i].x, (cameraPos.y * -1) + ItemRenderPosition[i].y);

			instance.Render(device, (*ItemList)[i]->GetIndexCount(), worldMatrix,
				viewMatrix, orthMatrix, (*ItemList)[i]->GetTexture());

			wchar_t buff[10];
			_itow((*ItemList)[i]->GetAmount(), buff, 10);

			writer_25size.DrawString(buff, RECT{
				ItemRenderPosition[i].x + 25, ItemRenderPosition[i].y + 25,
				ItemRenderPosition[i].x + 50, ItemRenderPosition[i].y + 50 },
				DT_RIGHT | DT_BOTTOM, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}

		writer_48size.DrawString(L"�κ��丮", RECT{ ItemRenderBasePosX - 40, ItemRenderBasePosY - 70, 1920 - 20, ItemRenderBasePosY - 20 }, DT_CENTER, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//}
}