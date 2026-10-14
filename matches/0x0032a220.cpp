struct Texture {
    void Bind(int);
};
struct DeviceState_32a220 {
    char pad[8];
    Texture* textures[8];
    void SetTexture(int, Texture*);
};
void __stdcall D3DDevice_SetTexture(int, int);
void __stdcall D3DDevice_SetPalette(int, int);
void DeviceState_32a220::SetTexture(int stage, Texture* value) {
    if (value != textures[stage]) {
        textures[stage] = value;
        if (value) {
            value->Bind(stage);
            return;
        }
        D3DDevice_SetTexture(stage, 0);
        D3DDevice_SetPalette(stage, 0);
    }
}
