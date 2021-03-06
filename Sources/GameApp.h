#pragma once

#include <Windows.h>
#include <windowsx.h>
#include <d3d10_1.h>
#include <D3DX10.h>
#include <DXUT.h>
#include <vector>
#include <d3dx10math.h>

#include <iostream>
#include <sstream>

#include <Sources/GameDefs.h>
#include <Sources/GameTimer.h>
#include <Sources/Utils/error.h>

//#include <Sources/Input/GameInput.h>
#include <Sources/Input/GameInput2.h>

#include <Sources/GameAssetLoader.h>
#include <Sources/Level/GameLevelLoader.h>
#include <Sources/Level/LobbyLevel.h>
#include <Sources/Level/TestLevel1.h>
//#define TEST_RENDER_BOX

struct _WindowSize {
	int width;
	int height;
};

struct _AdapterInfo {
	LUID ID;
	std::wstring Description;
	//int Numerator;
	//int Denominator;
};

struct _AppInfo {
	ID3D10Device*			pD3D10Device;
	ID3D10RenderTargetView*	pRenderTargetView;
	IDXGISwapChain*			pSwapChain;
	ID3D10Texture2D*		pBackBuffer;
	ID3D10DepthStencilState*pDepthStencilState;
	ID3D10DepthStencilState*pDepthDisableStencilState;
	ID3D10DepthStencilView*	pDepthStencilView;
	ID3D10RasterizerState*	pRasterizeState;
	ID3D10BlendState*		pBlendState;
};

struct _AppMatrix {
	D3DXMATRIX projectionMatrix;
	D3DXMATRIX worldMatrix;
	D3DXMATRIX orthMatrix;
};

using AdapterInfo = _AdapterInfo;
using AppInfo     = _AppInfo;
using WINDOWSIZE  = _WindowSize;
using Matrix      = _AppMatrix;

class CGameApp
{
private:
	//--Components
	AppInfo		AppComponents = {nullptr};
	GameTimer	GameTimer;
	Matrix		GameMatrices;
	std::vector <IDXGIAdapter*> AdaptersList;
	std::vector <IDXGIOutput*> AdaptersOutputsList;
	//Compoenents--

	//--Settings
	//D3D_DRIVER_TYPE		m_DriverType   = D3D_DRIVER_TYPE_HARDWARE;
	//D3D_FEATURE_LEVEL	m_FeatureLevel = D3D_FEATURE_LEVEL_11_0;
	//UINT				m_SDKVersion = D3D10_SDK_VERSION;
	UINT				MultiSampleQualityLevel = 0;

	bool IsVsync    = false;
	bool IsWindowed = false;
	float ScreenDepth;
	float ScreenNear;
	//Settings--

	//--Window Val
	HWND		HWnd;
	HINSTANCE	HInstance;
	wchar_t*	FrameTitle;
	wchar_t*	WndClassName;
	int			CmdShow;
	WINDOWSIZE  Windowsize;
	//Window Val--

	//--Info Val
	std::vector<AdapterInfo> AdapterInfoList;
	//Info Val--
private:
	void CalculateFrameStatus();
	void LoadAssets();

public:
	CGameApp();
	virtual ~CGameApp();

	bool Initialize(HINSTANCE hInstance, wchar_t* frameTitle, wchar_t* wndClassName, int nCmdShow, int width, int height, float screenDepth, float screenNear);
	void Release();
	void Launch();
	void Update();
	bool Render();

	void onResize();
	void onShowWindow();

	void TurnOnZBuffer();
	void TurnOffZBuffer();

	D3DXMATRIX& GetProjectionMatrix();
	D3DXMATRIX& GetWorldMatrix();
	D3DXMATRIX& GetorthogonalMatrix();

	WINDOWSIZE GetWindowSize() const;
	HWND GetHWND() const;
	ID3D10Device* GetDevice() const;
	
	/*
		임시적인 함수임
	*/
	const AppInfo* GetAppInfo() const;

	static CGameApp& GetInstance();
};