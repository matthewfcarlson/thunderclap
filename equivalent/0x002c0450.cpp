// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 16/16)
// FUN_002c0450 @ 0x002c0450
class Surface_2c0450 {
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
    virtual unsigned GetPixel(int x, int y);
};

// Blits a source surface into a 32-bit ARGB buffer, alpha-blending each pixel.
// equiv-conv: FUN_002c0450 eax ecx edx stack stack stack stack stack
void FUN_002c0450(int y0, int width, int height, Surface_2c0450 *src, unsigned *dst, int x0, int stride, unsigned key)
{
    int yEnd = y0 + height;
    int xEnd = x0 + width;
    for (int y = y0; y < yEnd; y++) {
        unsigned *row = dst;
        for (int x = x0; x < xEnd; x++) {
            unsigned c = src->GetPixel(x, y);
            if ((c & 0xffffff) != key) {
                int a = (int)(c >> 24);
                if (a == 0xff) {
                    *row = c;
                } else if (a > 0) {
                    unsigned d = *row;
                    int dr = (d >> 16) & 0xff;
                    int dg = (d >> 8) & 0xff;
                    int db = d & 0xff;
                    int r = (((int)((c >> 16) & 0xff) - dr) * a >> 8) + dr;
                    int g = (((int)((c >> 8) & 0xff) - dg) * a >> 8) + dg;
                    int b = (((int)(c & 0xff) - db) * a >> 8) + db;
                    int na = (int)(d >> 24) + a;
                    if (na > 0xff)
                        na = 0xff;
                    *row = (na << 24) | (r << 16) | (g << 8) | b;
                }
            }
            row++;
        }
        dst += stride;
    }
}
