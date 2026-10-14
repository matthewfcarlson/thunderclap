typedef unsigned int u32_329f20;
struct D3D8 {
    void SetRenderState_TextureFactor(u32_329f20);
};
struct Device_329f20 {
    char pad[0x108];
    u32_329f20 textureFactor;
    void Update(u32_329f20 value);
};
void Device_329f20::Update(u32_329f20 value) {
    if (value != textureFactor) {
        textureFactor = value;
        ((D3D8*)this)->SetRenderState_TextureFactor(value);
    }
}