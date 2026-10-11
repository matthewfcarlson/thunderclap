// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 23/24, incomplete)
// pure3d::ImageConverter::vfunc_1 @ 0x002de250
extern char DAT_004d098c[];
extern char DAT_004d09a8[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_00263ea0(unsigned int size);

struct Sub {
    char data[8];
    void FUN_0027af70(Sub *src);
};

struct Image {
    char pad0[8];
    Sub sub;
    int width;
    int height;
    int format;
    char pad1c[4];
    int extra;
};

class Surface {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int GetKind();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void SetProperty(int key, int value);
    virtual void s12();
    virtual int s13(int a, int b);
    virtual void s14(int a);
};

class Source {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual int GetValue();
};

class Texture {
public:
    virtual void t0();
    virtual void Release();
    char pad4[4];
    Sub sub;
    Surface *surface;
    Texture *FUN_002c1c30();
    bool FUN_002c1c70(int w, int h, int fmt, int extra, int a, int mode, int b);
};

class Game {
public:
    virtual void g0();
    virtual void g1();
    virtual int GetState();
};
extern Game *DAT_0052c2a0;

class ImageConverter {
public:
    virtual void vfunc_0();
    virtual Texture *vfunc_1(Image *img, bool flag);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(Image *img, int value);
    virtual void vfunc_8();
};

Texture *ImageConverter::vfunc_1(Image *img, bool flag)
{
    Texture *tex;
    Texture *mem = (Texture *)FUN_00263ea0(0x18);
    if (mem)
        tex = mem->FUN_002c1c30();
    else
        tex = 0;

    if (img)
        tex->sub.FUN_0027af70(&img->sub);

    int mode = 0;
    if (img->format == 8)
        mode = 1;
    if (flag)
        mode = 0xb;

    if (!tex->FUN_002c1c70(img->width, img->height, img->format, img->extra, 0, mode, 0)) {
        if (DAT_0052c2a0->GetState() != 1) {
            tex->Release();
            return 0;
        }
    }

    if (tex) {
        Surface *s = tex->surface;
        vfunc_7(img, s->s13(0, 0));
        s->s14(0);
        Source *src = (Source *)FUN_00344e74(img, 0, DAT_004d098c, DAT_004d09a8, 0);
        if (src) {
            if (s->GetKind() == 7 || s->GetKind() == 8)
            {
                int v = src->GetValue();
                tex->surface->SetProperty(0x100, v);
            }
        }
    }
    return tex;
}
