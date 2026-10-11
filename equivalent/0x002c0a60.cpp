// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 22/22)
// pure3d::Image32::vfunc_12 @ 0x002c0a60
class Image32;

// equiv-conv: FUN_002c0360 eax ecx edx stack stack stack stack
void FUN_002c0360(int rows, int srcStride, unsigned int* dst, unsigned int* src, int width, int dstStride, unsigned int key);
// equiv-conv: FUN_002c0200 ecx eax edx stack stack stack
void FUN_002c0200(int rows, char* src, char* dst, int widthBytes, int srcStrideBytes, int dstStrideBytes);
// equiv-conv: FUN_002c0450 eax ecx edx stack stack stack stack stack
void FUN_002c0450(int y0, int width, int rows, Image32* src, unsigned int* dst, int x0, int dstStride, unsigned int key);
// equiv-conv: FUN_002c03e0 eax ecx edx stack stack stack stack
void FUN_002c03e0(int width, int rows, int dstStride, Image32* src, unsigned int* dst, int x0, int y0);

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
            FUN_002c0200(h, (char*)srcPtr, (char*)dstPtr, w * 4, src->width * 4, width * 4);
        }
    } else {
        unsigned int* dstPtr = dstPixels + (width * dstY + dstX);
        if (src->useColorKey) {
            FUN_002c0450(srcY, w, h, src, dstPtr, srcX, width, src->colorKey);
        } else {
            FUN_002c03e0(w, h, width, src, dstPtr, srcX, srcY);
        }
    }
}
