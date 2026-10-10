// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 9/10, incomplete)
// FUN_00330ba0 @ 0x00330ba0
typedef unsigned long DWORD;
struct D3DLOCKED_RECT {
    int Pitch;
    void* pBits;
};
struct D3DTexture {
    char pad[0x10];
    DWORD Data;
};
namespace D3D8 {
void __stdcall D3DTexture_LockRect(DWORD, DWORD, D3DLOCKED_RECT*, void*, DWORD);
}
struct TextureHolder {
    char pad[0x94];
    D3DTexture* texture;
    char pad2[0xe4 - 0x98];
    int height;
    void FillGradient();
};
void TextureHolder::FillGradient() {
    D3DLOCKED_RECT lock;
    D3D8::D3DTexture_LockRect(texture->Data, 0, &lock, 0, 0);
    unsigned int* pixels = (unsigned int*)lock.pBits;
    float step = 1.0f / height;
    float stepScaled = step * 245.0f;
    float value = 10.0f;
    float limit = step * 64.0f;
    for (int row = 0; row < height; row++) {
        if (0.0f < limit) {
            int col = 0;
            do {
                signed char c = (signed char)(int)value;
                *pixels++ = 0xff000000 + c * 0x10101;
                col++;
                limit = 64.0f / height;
            } while ((float)col < limit);
        }
        value += stepScaled;
        if (row >= height - 2)
            value = 255.0f;
    }
}
