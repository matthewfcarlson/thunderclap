// STATUS: equivalent (tools/equiv.py level 3: 38 inputs, branch coverage 9/10, incomplete)
// FUN_0032fe00 @ 0x0032fe00
struct D3DLOCKED_RECT {
    int Pitch;
    unsigned int* pBits;
};
namespace D3D8 {
void __stdcall D3DTexture_LockRect(int texture, int level, D3DLOCKED_RECT* lr, const void* rect, int flags);
}
struct TexObj {
    char pad0[0x10];
    int handle;
};
class GradientTex {
  public:
    char pad0[0x80];
    TexObj* tex;
    char pad84[0xd4 - 0x84];
    int size;
    void Fill();
};
void GradientTex::Fill() {
    D3DLOCKED_RECT lr;
    D3D8::D3DTexture_LockRect(tex->handle, 0, &lr, 0, 0);
    unsigned int* p = lr.pBits;
    float step = 1.0f / (float)size;
    float x105 = step * 105.0f;
    float val = 150.0f;
    for (int i = 0; i < size; i++) {
        float k = step * 64.0f;
        if (0.0f < k) {
            int j = 0;
            do {
                *p++ = (signed char)(int)val * 0x10101 + 0xff000000;
                j++;
                k = 64.0f / (float)size;
            } while ((float)j < k);
        }
        val += x105;
        if (i >= size - 2)
            val = 255.0f;
    }
}
