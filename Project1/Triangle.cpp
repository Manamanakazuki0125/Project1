#include "Renderer.h"
#include "Triangle.h"

Triangle::Triangle()
{
    Vertices[0] = { 0.f, 0.5f, 0.f };
    Vertices[1] = { 0.5f, -0.5f, 0.f };
    Vertices[2] = { -0.5f, -0.5f, 0.f };
}

//デストラクタ
Triangle::~Triangle()
{
    DX_SAFE_RELEASE(VertexBuffer);
}

//頂点バッファの作成
bool Triangle::CreateVertexBuffer(Renderer& renderer)
{
    D3D11_BUFFER_DESC vertexBufferDesc = {};
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(Vertex) * 3;
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA vertexSubData;
    vertexSubData.pSysMem = Vertices;

    auto hr = renderer.GetDevice()->CreateBuffer(
        &vertexBufferDesc,
        &vertexSubData,
        &VertexBuffer
    );

    if (FAILED(hr)) return false;

    return true;
}

void Triangle::Draw(Renderer& renderer)
{
    // 後述
}