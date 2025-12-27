#include "Renderer.h"


bool Renderer::Initialize(HWND hWindow)
{
	//Windowに合わせてスクリーンサイズ初期化
	RECT rc;

	//クライアント領域の座標を取得
	GetClientRect(hWindow, &rc);

	//描画領域を指定
	screenWidth_ = rc.right - rc.left;
	screenHeight_ = rc.bottom - rc.top;

	initDeviceAndSwapChain(hWindow);

	initBackBuffer();

	return true;
}


bool Renderer::initDeviceAndSwapChain(HWND hWindow)
{
    // デバイスとスワップ・チェイン作成
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = backBufferNum_;        // バックバッファの数
    sd.BufferDesc.Width = screenWidth_;    // バックバッファの幅
    sd.BufferDesc.Height = screenHeight_;    // バックバッファの高さ
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;    // フォーマット
    sd.BufferDesc.RefreshRate.Numerator = 60;    // リフレッシュレート（分母）
    sd.BufferDesc.RefreshRate.Denominator = 1;    // リフレッシュレート（分子）
    sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
    sd.BufferDesc.Scaling = DXGI_MODE_SCALING_CENTERED;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;    // バックバッファの使用法
    sd.OutputWindow = hWindow;        // 関連付けるウィンドウ
    sd.SampleDesc.Count = 1;            // マルチサンプル（アンチエイリアス）の数
    sd.SampleDesc.Quality = 0;            // マルチサンプル（アンチエイリアス）のクオリティ
    sd.Windowed = TRUE;        // ウィンドウモード（TRUEがウィンドウモード）
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;        // モード自動切り替え

#if defined(DEBUG) || defined(_DEBUG)
    UINT createDeviceFlags = D3D11_CREATE_DEVICE_DEBUG;
#else
    UINT createDeviceFlags = 0;
#endif

    const D3D_DRIVER_TYPE DriverTypes[] = {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };

    HRESULT hr;
    for (auto type : DriverTypes) {
        // ハードウェアデバイスを作成
        hr = D3D11CreateDeviceAndSwapChain(
            nullptr, type, nullptr, createDeviceFlags,
            pFeatureLevels_, FEATURE_LEVELS_NUM, D3D11_SDK_VERSION, &sd,
            &pSwapChain_, &pD3DDevice_, &featureLevelsSupported_, &pImmediateContext_);
        if (SUCCEEDED(hr)) {
            break;
        }
    }
    if (FAILED(hr)) return false;

    return true;
}