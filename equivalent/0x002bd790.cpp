// STATUS: equivalent (tools/equiv.py level 3: 138 inputs, branch coverage 73/80, incomplete)
// FUN_002bd790 @ 0x002bd790
struct Rect_2bd790 {
    int left;      // 0
    int top;       // 4
    int right;     // 8
    int bottom;    // 0xc
};

class Surface_2bd790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setSize(int a, int b);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int getPixel(int row, int col);
    virtual void setPixel(int row, int col, int color);
    virtual void begin(int v);
    virtual void blit(int src, int srcY, int srcX, int h, int w, int dstY, int dstX);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int getPixel8(int row, int col);
    char pad04[0x14];
    int format;    // 0x18
};

class Image {
public:
    virtual void AddRef();
};

class Factory_2bd790 {
public:
    virtual void v0();
    virtual Image *create(Surface_2bd790 *s, int flag);
};

class Frame9 {
public:
    char pad0[0x48];
    Image **images;        // 0x48
    char pad4c[0x54 - 0x4c];
    int width;             // 0x54
    int height;            // 0x58
    int border;            // 0x5c
    char pad60[0xa0 - 0x60];
    unsigned char flagA0;
    void FUN_002bd790(int index, Rect_2bd790 *r, int a2, int a3, int src, Surface_2bd790 *s, Factory_2bd790 *f);
};

void Frame9::FUN_002bd790(int index, Rect_2bd790 *r, int a2, int a3, int src, Surface_2bd790 *s, Factory_2bd790 *f)
{
    s->setSize(a2, a3);
    s->begin(0);

    int b = border;
    int top = r->top;
    int t0 = top > b ? top - b : 0;
    int bot = r->bottom;
    int b1 = (height - bot > b) ? bot + b : height;
    int left = r->left;
    int l0 = left > b ? left - b : 0;
    int right = r->right;
    int r1 = (width - right > b) ? right + b : width;

    int h1 = b1 - t0;
    int w1 = r1 - l0;
    int tp = top > b ? 0 : b - top;
    int th = tp + h1;
    int lp = left > b ? 0 : b - left;
    int tw = lp + w1;

    s->blit(src, t0, l0, h1, w1, tp, lp);

    int i;
    if (h1 < a2) {
        if (tp > 0) {
            for (i = tp - 1; i >= 0; i--)
                s->blit(src, t0, l0, 1, w1, i, lp);
        }
        if (th < a2) {
            for (i = th; i < a2; i++)
                s->blit(src, b1 - 1, l0, 1, w1, i, lp);
        }
    }
    if (w1 < a3) {
        for (i = lp - 1; i >= 0; i--)
            s->blit(src, t0, l0, h1, 1, tp, i);
        if (tw < a3) {
            for (i = tw; i < a3; i++)
                s->blit(src, t0, r1 - 1, h1, 1, tp, i);
        }
    }
    if (tp > 0) {
        if (lp > 0) {
            int color = s->format == 8 ? s->getPixel8(tp, lp) : s->getPixel(tp, lp);
            for (int row = tp - 1; row >= 0; row--)
                for (int col = lp - 1; col >= 0; col--)
                    s->setPixel(row, col, color);
        }
        if (tw < a3) {
            int color = s->format == 8 ? s->getPixel8(tp, tw - 1) : s->getPixel(tp, tw - 1);
            for (int row = tp - 1; row >= 0; row--)
                for (int col = tw; col < a3; col++)
                    s->setPixel(row, col, color);
        }
    }
    if (th < a2) {
        if (lp > 0) {
            int color = s->format == 8 ? s->getPixel8(th - 1, lp) : s->getPixel(th - 1, lp);
            for (int row = th; row < a2; row++)
                for (int col = lp - 1; col >= 0; col--)
                    s->setPixel(row, col, color);
        }
        if (tw < a3) {
            int color = s->format == 8 ? s->getPixel8(th - 1, tw - 1) : s->getPixel(th - 1, tw - 1);
            for (int row = th; row < a2; row++)
                for (int col = tw; col < a3; col++)
                    s->setPixel(row, col, color);
        }
    }
    images[index] = f->create(s, flagA0);
    images[index]->AddRef();
}
