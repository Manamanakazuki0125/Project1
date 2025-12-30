#pragma once
#pragma comment(lib, "d3d11.lib")
#include <d3d11.h>
#include "Debug.h"
#define DX_CALL(expr, msg)                                      \
    do {                                                        \
        HRESULT _hr = (expr);                                   \
        if (FAILED(_hr)) {                                      \
            Debug::LogDxError(msg, _hr, __FILE__, __LINE__);    \
            return false;                                       \
        }                                                       \
    } while (0)
#include <DirectXMath.h>
#define DX_SAFE_RELEASE(x)    { if(x) { (x)->Release(); (x)=nullptr; } }
#include "Vertex.h"


class Renderer;