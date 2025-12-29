#pragma once

//1頂点を持たせる構造体
struct Vertex {
    DirectX::XMFLOAT3    Position = {};

    //デフォルトコンストラクタ
    Vertex() {}

	//引数付きコンストラクタ
    Vertex(float x, float y, float z) {
        Position.x = x;
        Position.y = y;
        Position.z = z;
    }
};
