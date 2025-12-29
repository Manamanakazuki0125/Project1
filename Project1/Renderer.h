#pragma once
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#include "shader.h"
#include <d3d11.h>
#include "Triangle.h"
//マクロ定義
#define DX_SAFE_RELEASE(x) {if(x) { (x)->Release(); (x) = nullptr; }}


class Renderer
{
public:
	Renderer();
	~Renderer();

	bool Initialize(HWND wWindow);

	void Terminate();

	//シェーダーコンパイル、頂点シェーダーとピクセルシェーダーをセットで渡す
	bool CompileShader(const WCHAR* vsPath, const WCHAR* psPath, Shader& outShader);

	void Draw();

	void Swap();


	ID3D11Device* GetDevice() { return pD3DDevice_; }
	ID3D11DeviceContext* GetDeviceContext() { return pImmediateContext_; }

private:
	bool initDeviceAndSwapChain(HWND wWindow);
	bool initBackBuffer();

private:

	//! 機能レベルの配列
	static const UINT FEATURE_LEVELS_NUM = 5;

	D3D_FEATURE_LEVEL pFeatureLevels_[FEATURE_LEVELS_NUM] = {
	D3D_FEATURE_LEVEL_11_0,
	D3D_FEATURE_LEVEL_10_1,
	D3D_FEATURE_LEVEL_10_0,
	D3D_FEATURE_LEVEL_9_3,
	D3D_FEATURE_LEVEL_9_1,
	};

	//! デバイス作成時に返される機能レベル
	D3D_FEATURE_LEVEL featureLevelsSupported_;


	//↓　initDeviceAndSwapChain(HWND hWindow)で以下が取得される
	//!デバイス
	ID3D11Device* pD3DDevice_ = nullptr;

	//!デバイスコンテキスト
	ID3D11DeviceContext* pImmediateContext_ = nullptr;
	
	//!スワップチェイン
	IDXGISwapChain* pSwapChain_ = nullptr;

	//↑　ここまでが取得される。

	//!描画ターゲット・ビュー
	ID3D11RenderTargetView* pRenderTargetView_ = nullptr;

	//!ビューポート
	D3D11_VIEWPORT viewPort_[1];

	UINT    backBufferNum_ = 1;
	UINT    screenWidth_ = 0;
	UINT    screenHeight_ = 0;

private:
	Shader  defaultShader_;
	Triangle sampleTriangle_;

};

