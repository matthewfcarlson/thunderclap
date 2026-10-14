// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 8/8)
// FUN_002c0240 @ 0x002c0240
class Surface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    char pad4[0xc];
    int stride;         // 0x10
    char pad14[0x24 - 0x14];
    char *base;         // 0x24
};

// equiv-conv: FUN_002c0240 ecx eax ebx stack stack stack stack
void __cdecl FUN_002c0240(Surface *surf, int y, int x, char *dst, int w, int h, int dstStride)
{
    int stride = surf->stride;
    char *src = surf->base + stride * y + x;
    surf->v18();
    int endY = y + h;
    if (y < endY) {
        int rows = endY - y;
        int endX = w + x;
        do {
            for (int k = x; k < endX; k++)
                dst[k - x] = src[k - x];
            src += stride;
            dst += dstStride;
        } while (--rows != 0);
    }
}
