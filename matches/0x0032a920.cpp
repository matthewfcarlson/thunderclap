typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
} // namespace D3D8
struct Texture {
    void FUN_00326b00(int stage);
};
struct TextureState {
    char pad[8];
    Texture* tex[4];
    void FUN_00329bb0(int);
    void SetTextures(int mode, Texture* t0, Texture* t1, Texture* t2, Texture* t3);
};
void TextureState::SetTextures(int mode, Texture* t0, Texture* t1, Texture* t2, Texture* t3) {
    if (t0 != tex[0]) {
        tex[0] = t0;
        if (t0) {
            t0->FUN_00326b00(0);
        } else {
            D3D8::D3DDevice_SetTexture(0, 0);
            D3D8::D3DDevice_SetPalette(0, 0);
        }
    }
    if (t1 != tex[1]) {
        tex[1] = t1;
        if (t1) {
            t1->FUN_00326b00(1);
        } else {
            D3D8::D3DDevice_SetTexture(1, 0);
            D3D8::D3DDevice_SetPalette(1, 0);
        }
    }
    if (t2 != tex[2]) {
        tex[2] = t2;
        if (t2) {
            t2->FUN_00326b00(2);
        } else {
            D3D8::D3DDevice_SetTexture(2, 0);
            D3D8::D3DDevice_SetPalette(2, 0);
        }
    }
    if (t3 != tex[3]) {
        tex[3] = t3;
        if (t3) {
            t3->FUN_00326b00(3);
        } else {
            D3D8::D3DDevice_SetTexture(3, 0);
            D3D8::D3DDevice_SetPalette(3, 0);
        }
    }
    FUN_00329bb0(mode);
}
