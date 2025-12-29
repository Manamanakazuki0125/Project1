#pragma once
#pragma comment(lib, "d3d11.lib")
#include <d3d11.h>
#include <DirectXMath.h>
#include "Vertex.h"
#define DX_SAFE_RELEASE(x)    { if(x) { (x)->Release(); (x)=nullptr; } }

class Renderer;