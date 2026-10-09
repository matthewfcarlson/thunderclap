typedef unsigned int u32;
struct D3D8 { void SetRenderState_TextureFactor(u32); };
struct Device {
    char pad[0x108];
    u32 textureFactor;
    void Update(u32 value);
};
void Device::Update(u32 value) {
    if (value != textureFactor) {
        textureFactor = value;
        ((D3D8*)this)->SetRenderState_TextureFactor(value);
    }
}