// STATUS: equivalent (tools/equiv.py level 3: 154 inputs, branch coverage 52/54, incomplete)
// pure3d::AnimationLoader::vfunc_5 @ 0x00289500
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *__cdecl memset(void *, int, unsigned int);
extern "C" void __cdecl qsort(void *base, unsigned int count, unsigned int size,
                              int (__cdecl *cmp)(const void *, const void *));
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);
int FUN_00266da0(int token);
int __cdecl FUN_00289240(const void *a, const void *b);
int __cdecl FUN_00289270(const void *a, const void *b);

extern char DAT_00121002;
extern char DAT_00121006;
extern char DAT_00121401;
extern char DAT_00121402;

struct Pair_289500 {
    unsigned int lo;
    unsigned int hi;
};
Pair_289500 FUN_002672f0(const char *name, int a, int b);

struct Name_289500 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

class __declspec(novtable) NamedBase_289500 {
public:
    virtual void v0();
    char pad04[4];
    Name_289500 name;
    void FUN_0027b070();
    NamedBase_289500() { FUN_0027b070(); }
};

struct Alloc_289500 {
    virtual void v0();
    char pad4[0xc];
    unsigned int cur10;
    unsigned int cur14;
    char *base18;
    char *base1c;
};

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Reader {
    char pad0[0x284];
    Stream *stream;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

namespace pure3d {
class Animation : public NamedBase_289500 {
public:
    int f10;
    float f14;
    char f18;
    char pad19[3];
    int f1c;
    int f20;
    int f24;
    int f28;
    int *f2c;
    Alloc_289500 *f30;
    int f34;
    char *f38;
    virtual void v1();
    Animation()
        : f10(0), f14(30.0f), f18(0), f1c(0), f20(0), f24(0), f28(0), f2c(0), f30(0), f34(0), f38(0)
    {
    }
};
}

class Table_289500 {
public:
    float FUN_dummy();
};

namespace pure3d {
class AnimationLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(Animation **out, Pair_289500 *outId, Reader *r, int ctx);
    char pad04[0x14];
    int f18;
    int f1c;
    int f20;
    Alloc_289500 *FUN_00289070(Reader *r);
    int FUN_00288eb0(Reader *r, int ctx, Alloc_289500 *alloc);
};

void AnimationLoader::vfunc_5(Animation **out, Pair_289500 *outId, Reader *r, int ctx)
{
    struct Frame {
        char pad10[3];
        unsigned char len;
        int v;
        AnimationLoader *self;
        int row3;
        int rowOff;
        int token;
        int unused;
        float fa;
        unsigned int count;
        float fb;
        int b;
        int a;
        int dummy;
        int skip;
        char name[0x100];
        char name2[0xf0];
        char pad[0x40];
    } fr;
    fr.self = this;
    fr.token = -1;
    if (f1c != -1)
        fr.token = FUN_00266da0(f1c);

    int &unused = fr.unused;
    unsigned char &len = fr.len;
    int &v = fr.v;
    char *name = fr.name;
    r->stream->FUN_002647e0(&unused, 1, 4, 1);
    r->stream->FUN_002647e0(&len, 1, 1, 1);
    unsigned int n = len;
    r->stream->FUN_002647e0(name, n, 1, 1);
    name[n] = 0;

    void *mem = thunk_FUN_0008d690(0x40);
    Animation *anim = 0;
    if (mem)
        anim = new (mem) Animation();
    anim->name.FUN_0027b040(name);
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f1c = v;
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f10 = v;
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f14 = *(float *)&v;
    r->stream->FUN_002647e0(&v, 1, 4, 1);
    anim->f18 = (v == 1);
    anim->f24 = f18;

    if (r->FUN_002669f0()) {
        int &row3 = fr.row3;
        int &rowOff = fr.rowOff;
        row3 = 0;
        rowOff = 0;
        do {
            char *id = (char *)r->FUN_00266a30();
            if (id == &DAT_00121401) {
                if (anim->f38 == 0) {
                    if (anim->f30 != 0) {
                        anim->f30->v0();
                        Alloc_289500 *pool = anim->f30;
                        unsigned int bytes = anim->f34 * 24;
                        if (bytes > 0) {
                            unsigned int off = (pool->cur14 + 3) & 0xfffffffc;
                            char *p = pool->base1c + off;
                            pool->cur14 = off + bytes;
                            anim->f38 = p;
                        } else {
                            anim->f38 = 0;
                        }
                    } else {
                        anim->f38 = (char *)FUN_0008d6d0(anim->f34 * 24);
                    }
                }
                char *name2 = fr.name2;
                unsigned char &len2 = fr.len;
                int &skip = fr.skip;
                unsigned int &count = (unsigned int &)fr.v;
                float &fa = fr.fa;
                float &fb = fr.fb;
                r->stream->FUN_002647e0(&len2, 1, 1, 1);
                unsigned int n2 = len2;
                r->stream->FUN_002647e0(name2, n2, 1, 1);
                name2[n2] = 0;
                r->stream->FUN_002647e0(&skip, 1, 4, 1);
                Pair_289500 key = FUN_002672f0(name2, 0, 0);
                *(Pair_289500 *)(anim->f38 + rowOff) = key;
                r->stream->FUN_002647e0(&count, 1, 4, 1);
                unsigned int k = 0;
                int off = rowOff;
                if (count > 0) {
                    k = count;
                    fr.count = count;
                    do {
                        r->stream->FUN_002647e0(&fa, 1, 4, 1);
                        *(float *)(anim->f38 + off + 8) = fa + 1.0f;
                        r->stream->FUN_002647e0(&fb, 1, 4, 1);
                        *(float *)(anim->f38 + off + 12) = fb + 1.0f;
                        off += 8;
                        k--;
                    } while (k != 0);
                }
                if (count < 2) {
                    int start = row3 * 8 + count * 8;
                    for (int j = 2 - count; j != 0; j--) {
                        *(int *)(anim->f38 + start + 8) = 0;
                        *(int *)(anim->f38 + start + 12) = 0;
                        start += 8;
                    }
                }
                rowOff += 0x18;
                row3 += 3;
            } else if (id == &DAT_00121402) {
                r->stream->FUN_002647e0(&fr.dummy, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.unused, 1, 4, 1);
                anim->f20 = fr.unused;
            } else if (id == &DAT_00121002) {
                r->stream->FUN_002647e0(&fr.a, 1, 4, 1);
                r->stream->FUN_002647e0(&fr.b, 1, 4, 1);
                anim->f28 = fr.b;
                if (fr.b > 0) {
                    anim->f2c = (int *)FUN_0008d6d0(fr.b * 4);
                    memset(anim->f2c, 0, anim->f28 * 4);
                    int i = 0;
                    while (r->FUN_002669f0() && i < anim->f28) {
                        r->FUN_00266a30();
                        anim->f2c[i] = fr.self->FUN_00288eb0(r, ctx, anim->f30);
                        r->FUN_00266be0();
                        i++;
                    }
                }
            } else if (id == &DAT_00121006) {
                if (anim->f28 == 0) {
                    anim->f30 = fr.self->FUN_00289070(r);
                    if (anim->f30)
                        anim->f30->v0();
                    anim->f34 = fr.self->f20;
                }
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    if (anim->f28 > 0) {
        if (anim->f24 == 0)
            qsort(anim->f2c, anim->f28, 4, FUN_00289270);
        else if (anim->f24 == 1)
            qsort(anim->f2c, anim->f28, 4, FUN_00289240);
    }
    if (fr.self->f1c != -1)
        FUN_00266da0(fr.token);
    *out = anim;
    *outId = FUN_002672f0(name, 0, 0);
}
}
