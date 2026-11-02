// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 22/22)
// pure3d::Image32::vfunc_12 @ 0x002c0a60
// pure3d::Image32::vfunc_12 @ 0x002c0a60
class Image32;

// equiv-conv: FUN_002c0360 eax ecx edx stack stack stack stack
extern "C" void FUN_002c0360(int rows, int srcStride, unsigned int* dst, unsigned int* src, int width, int dstStride, unsigned int key);
// equiv-conv: FUN_002c0200 eax edx ecx stack stack stack
extern "C" void __cdecl FUN_002c0200(const unsigned char *, unsigned char *, int, unsigned int, int, int);
// equiv-conv: FUN_002c0450 eax ecx edx stack stack stack stack stack
extern "C" void __cdecl FUN_002c0450(int, int, int, void *, unsigned *, int, int, unsigned);
// equiv-conv: FUN_002c03e0 eax ecx edx stack stack stack stack
extern "C" void __cdecl FUN_002c03e0(int, int, int, void *, unsigned int *, int, int);

class Image32 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual unsigned int vfunc_9(int x, int y);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(Image32* src, int srcX, int srcY, int width, int height, int dstX, int dstY);
    char pad04[0x10 - 4];
    int width;
    int height;
    int bpp;
    unsigned int colorKey;
    char pad20[4];
    unsigned int* pixels;
    char hasAlpha;
    char useColorKey;
};

void Image32::vfunc_12(Image32* src, int srcX, int srcY, int w, int h, int dstX, int dstY)
{
    hasAlpha = src->hasAlpha;
    if (dstX < 0) {
        srcX += dstX;
        w -= dstX;
        dstX = 0;
    }
    if (dstY < 0) {
        srcY += dstY;
        h -= dstY;
        dstY = 0;
    }
    if (w + dstX > width)
        w = width - dstX;
    if (h + dstY > height)
        h = height - dstY;
    if (w < 1 || h < 1)
        return;
    if (src->pixels == 0)
        return;
    unsigned int* dstPixels = pixels;
    if (dstPixels == 0)
        return;
    if (src->bpp == 32) {
        unsigned int* srcPtr = src->pixels + (src->width * srcY + srcX);
        unsigned int* dstPtr = dstPixels + (width * dstY + dstX);
        if (src->useColorKey) {
            FUN_002c0360(h, src->width, dstPtr, srcPtr, w, width, src->colorKey);
        } else {
            FUN_002c0200((const unsigned char *)(char *)((char*)srcPtr), (unsigned char *)(char *)((char*)dstPtr), h, (int)(w * 4), src->width * 4, width * 4);
        }
    } else {
        unsigned int* dstPtr = dstPixels + (width * dstY + dstX);
        if (src->useColorKey) {
            FUN_002c0450(srcY, w, h, (Image32 *)src, (unsigned *)(unsigned int *)dstPtr, srcX, width, (unsigned int)(src->colorKey));
        } else {
            FUN_002c03e0(w, h, width, (Image32 *)src, dstPtr, srcX, srcY);
        }
    }
}
