// STATUS: equivalent (tools/equiv.py level 3: 40 inputs, branch coverage 10/10)
// FUN_0031b230 @ 0x0031b230
#include "compat/ptr.h"
struct RECT { int left, top, right, bottom; };
struct D3DLOCKED_RECT { int Pitch; unsigned char* pBits; };
namespace D3D8 {
hulk_intptr __stdcall D3DDevice_GetBackBuffer2(int);
void __stdcall D3DDevice_CopyRects(hulk_intptr, int, int, int, int);
void __stdcall D3DSurface_LockRect(int, D3DLOCKED_RECT*, int, int);
void __stdcall D3DResource_Release(hulk_intptr);
}
extern int __stdcall FUN_00382400(int, int, int, int);
extern void __cdecl FUN_0031c230(int);
class d3dDisplay_31b230 {
public:
    char pad[0x478];
    int height;
    int width;
    int Capture(unsigned char* dest, int unused, const RECT* r, int which);
};
int d3dDisplay_31b230::Capture(unsigned char* dest, int unused, const RECT* r, int which) {
    int w = r->right - r->left;
    int h = r->bottom - r->top;
    int surf = FUN_00382400(w, h, 0, 0x12);
    FUN_0031c230((surf != 0) - 1 & 0x8007000e);
    hulk_intptr back = D3D8::D3DDevice_GetBackBuffer2(which == 0 ? -1 : 0);
    FUN_0031c230(0);
    D3D8::D3DDevice_CopyRects(back, 0, 0, surf, 0);
    D3DLOCKED_RECT lr;
    D3D8::D3DSurface_LockRect(surf, &lr, 0, 0x80);
    FUN_0031c230(0);
    const unsigned char* src = lr.pBits;
    for (int y = 0; y < h; y++) {
        for (int i = 0; i < w * 4; i++)
            dest[i] = src[i];
        dest += w * 4;
        src += lr.Pitch;
    }
    D3D8::D3DResource_Release(surf);
    D3D8::D3DResource_Release(back);
    return width * height * 4;
}
