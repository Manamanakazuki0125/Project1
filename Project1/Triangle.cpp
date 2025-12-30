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
   
    OutputDebugStringA(">>> CreateVertexBuffer() が呼ばれたよ <<<\n"); //デバック用の出力


    D3D11_BUFFER_DESC vertexBufferDesc = {};
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(Vertex) * 3;
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA vertexSubData;
    vertexSubData.pSysMem = Vertices;

    DX_CALL(renderer.GetDevice()->CreateBuffer(
        &vertexBufferDesc,
        &vertexSubData,
        &VertexBuffer
    ), "頂点バッファの作成に失敗しました。");
    
    return true;
}

void Triangle::Draw(Renderer& renderer)
{
    auto pDeviceContext = renderer.GetDeviceContext();
    uint32_t strides[1] = { sizeof(Vertex) };
    uint32_t offsets[1] = { 0 };
    pDeviceContext->IASetVertexBuffers(0, 1, &VertexBuffer, strides, offsets);
    pDeviceContext->Draw(VERTEX_NUM, 0);
}