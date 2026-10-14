// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 10/10)
// FUN_002c02b0 @ 0x002c02b0
class Surface_2c02b0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18();
    char pad04[0x10 - 4];
    int pitch;              // 0x10
    char pad14[0x24 - 0x14];
    char *pixels;           // 0x24
};

// equiv-conv: FUN_002c02b0 ecx eax stack stack stack stack stack stack
void FUN_002c02b0(Surface_2c02b0 *surf, int y0, char *dst, int x0, int width, int height, int dstPitch, char key)
{
    int stride = surf->pitch;
    char *src = surf->pixels + stride * y0 + x0;
    surf->v18();
    int xEnd = x0 + width;
    int rows = (y0 + height) - y0;
    if (y0 < y0 + height) {
        do {
            char *s = src;
            char *d = dst;
            for (int x = x0; x < xEnd; x++) {
                if (*s != key)
                    *d = *s;
                s++;
                d++;
            }
            src += stride;
            dst += dstPitch;
            rows--;
        } while (rows != 0);
    }
}
