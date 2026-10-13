// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 46/50, incomplete)
// pure3d::TextureFontLoader::vfunc_5 @ 0x00295620
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void __cdecl thunk_FUN_00267090(void *p);
unsigned __int64 FUN_0027b020(const char *s);
unsigned __int64 FUN_002672f0(const char *s, int a, int b);
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Shader; }

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class ObjectLoader {
public:
    virtual void v0();
    virtual void v1();
};

class Texture {
public:
    virtual void v0();
    virtual void v1();
};

class TextureLoader : public ObjectLoader {
public:
    Texture *FUN_002c2370(Stream *s);
};

struct Registry {
    ObjectLoader *FUN_00265310(int id);
};
extern Registry *DAT_00527c58;
extern unsigned short DAT_00554be0;

struct ShaderSlots {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void set(int code, int flag);
};

namespace pure3d {
class Shader {
public:
    char pad0[0x10];
    ShaderSlots *slots;
    char pad14[0x20 - 0x14];
    Shader *FUN_0028edb0();
};
}

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d::Shader *f3(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, unsigned int lo,
                               unsigned int hi);
};

struct Glyph {
    float f0, f4, f8, fc;
    unsigned short w10;
    short pad12;
    int f14;
    float f18, f1c, f20, f24;
    void FUN_002c3aa0();
    void FUN_002c3ac0();
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    Name name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class TextureFont : public Entity {
public:
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void setShader(pure3d::Shader *sh);
    int f10, f14, f18, f1c, f20, f24, f28;
    unsigned int pageCount;
    Texture **pages;
    int defIdx;
    unsigned int glyphCount;
    Glyph *glyphs;
    unsigned short *codes;
    TextureFont() throw()
    {
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1c = 0;
        f20 = 0;
        f24 = -1;
        f28 = 0;
        pageCount = 0;
        pages = 0;
        defIdx = 0;
        glyphCount = 0;
        glyphs = 0;
        codes = 0;
    }
};
}

class TextureFontLoader {
public:
    void F(pure3d::TextureFont **out, unsigned __int64 *outId, Stream *s, Factory *fac);
};

void TextureFontLoader::F(pure3d::TextureFont **out, unsigned __int64 *outId, Stream *s, Factory *fac)
{
    struct Frame {
        char pad10[3];
        unsigned char len;
        int v14, v18, v1c, v20, v24, v28, v2c, v30, v34, v38, v3c, v40, v44, v48, v4c;
        char N[0x100];
        char N2[0x100];
    } fr;

    s->reader->FUN_002647e0(&fr.v20, 1, 4, 1);
    void *mem = thunk_FUN_0008d690(0x48);
    pure3d::TextureFont *font = 0;
    if (mem)
        font = new (mem) pure3d::TextureFont();
    s->reader->FUN_002647e0(&fr.len, 1, 1, 1);
    int n = fr.len;
    s->reader->FUN_002647e0(fr.N, n, 1, 1);
    fr.N[n] = 0;
    font->name.FUN_0027b040(fr.N);
    s->reader->FUN_002647e0(&fr.len, 1, 1, 1);
    n = fr.len;
    s->reader->FUN_002647e0(fr.N2, n, 1, 1);
    fr.N2[n] = 0;
    unsigned __int64 h = FUN_0027b020(fr.N2);
    new (&fr.v14) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    pure3d::Shader *sh = fac->f3((content::LoadInventory::DynamicCaster<pure3d::Shader> *)&fr.v14,
                                 (unsigned int)h, (unsigned int)(h >> 32));
    if (!sh) {
        void *m2 = thunk_FUN_0008d690(0x20);
        if (m2)
            sh = ((pure3d::Shader *)m2)->FUN_0028edb0();
        else
            sh = 0;
        sh->slots->set(0x54494c, 0);
        sh->slots->set(0x444d4c42, 1);
        sh->slots->set(0x444d4946, 1);
        sh->slots->set(0x54535441, 0);
    }
    font->setShader(sh);
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f10 = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f14 = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f18 = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    font->f1c = fr.v14;
    s->reader->FUN_002647e0(&fr.v14, 1, 4, 1);
    unsigned int cnt = fr.v14;
    font->pageCount = cnt;
    font->pages = (Texture **)FUN_0008d6d0(cnt * 4);
    memset(font->pages, 0, font->pageCount * 4);
    TextureLoader *tl = dynamic_cast<TextureLoader *>(DAT_00527c58->FUN_00265310(0x19000));
    tl->v0();
    if (s->FUN_002669f0()) {
        fr.v1c = 0;
        do {
            int id = s->FUN_00266a30();
            if (id == 0x19000) {
                Texture *tex = tl->FUN_002c2370(s);
                Texture **slot = (Texture **)((char *)font->pages + fr.v1c);
                if (tex)
                    tex->v0();
                if (*slot)
                    (*slot)->v1();
                fr.v1c += 4;
                *slot = tex;
            } else if (id == 0x22001) {
                if (font->glyphs) {
                    int *raw = (int *)font->glyphs - 1;
                    int gc = *raw;
                    Glyph *end = font->glyphs + gc;
                    for (int i = gc; i > 0; i--) {
                        end--;
                        end->FUN_002c3ac0();
                    }
                    thunk_FUN_00267090(raw);
                    thunk_FUN_00267090(font->codes);
                }
                s->reader->FUN_002647e0(&fr.v4c, 1, 4, 1);
                unsigned int g = fr.v4c;
                font->glyphCount = g;
                int *blk = (int *)FUN_0008d6d0(g * 40 + 4);
                Glyph *arr = 0;
                if (blk) {
                    *blk = g;
                    arr = (Glyph *)(blk + 1);
                    for (int i = 0; i < (int)g; i++) {
                        arr[i].FUN_002c3aa0();
                        arr[i].f14 = 0;
                        arr[i].f18 = 0;
                        arr[i].f1c = 0;
                        arr[i].f20 = 1.0f;
                        arr[i].f24 = 1.0f;
                    }
                }
                font->glyphs = arr;
                font->codes = (unsigned short *)FUN_0008d6d0(font->glyphCount * 2);
                unsigned int k = 0;
                unsigned int off = 0;
                if (font->glyphCount != 0) {
                    do {
                        s->reader->FUN_002647e0(&fr.v40, 1, 4, 1);
                        *(int *)((char *)font->glyphs + off + 0x14) = fr.v40;
                        s->reader->FUN_002647e0(&fr.v30, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x18) = *(float *)&fr.v30;
                        s->reader->FUN_002647e0(&fr.v24, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x1c) = *(float *)&fr.v24;
                        s->reader->FUN_002647e0(&fr.v38, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x20) = *(float *)&fr.v38;
                        s->reader->FUN_002647e0(&fr.v48, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0x24) = *(float *)&fr.v48;
                        s->reader->FUN_002647e0(&fr.v28, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0) = *(float *)&fr.v28;
                        s->reader->FUN_002647e0(&fr.v2c, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 4) = *(float *)&fr.v2c;
                        s->reader->FUN_002647e0(&fr.v34, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 8) = *(float *)&fr.v34;
                        s->reader->FUN_002647e0(&fr.v3c, 1, 4, 1);
                        *(float *)((char *)font->glyphs + off + 0xc) = *(float *)&fr.v3c;
                        s->reader->FUN_002647e0(&fr.v20, 1, 4, 1);
                        *(unsigned short *)((char *)font->glyphs + off + 0x10) = (unsigned short)fr.v20;
                        Glyph *gl = (Glyph *)((char *)font->glyphs + off);
                        if (gl->w10 == 0x76)
                            gl->fc = gl->fc - 2.0f;
                        Glyph *gl2 = (Glyph *)((char *)font->glyphs + off);
                        unsigned short wc = gl2->w10;
                        if (wc == 0x6f || wc == 0x72)
                            gl2->fc = gl2->fc - 1.0f;
                        font->codes[k] = *(unsigned short *)((char *)font->glyphs + off + 0x10);
                        k++;
                        off += 0x28;
                    } while (k < font->glyphCount);
                }
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }
    tl->v1();
    int hi = (int)font->glyphCount - 1;
    int lo = 0;
    if (hi >= 0) {
        unsigned short *codes = font->codes;
        unsigned short key = DAT_00554be0;
        do {
            int mid = (hi + lo) >> 1;
            unsigned short c = codes[mid];
            if (key == c) {
                if (mid >= 0)
                    font->defIdx = mid;
                break;
            }
            if (key < c)
                hi = mid - 1;
            else
                lo = mid + 1;
        } while (lo <= hi);
    }
    *out = font;
    *outId = FUN_002672f0(fr.N, 0, 0);
}
