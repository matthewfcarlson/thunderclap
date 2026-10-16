// STATUS: equivalent (tools/equiv.py level 3: 300 inputs, branch coverage 68/86, incomplete)
// FUN_002acd70 @ 0x002acd70
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) { return p; }


class Ref_2acd70 {
public:
    virtual void AddRef();
    virtual void Release();
};

namespace content {
class ObjectLoader : public Ref_2acd70 {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
};
namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
}
}

namespace pure3d {
class Shader;
class AnimationLoader : public content::ObjectLoader {
public:
    virtual void *a5(int *out, int *id, void *reader, void *inv);
    int FUN_00288e90();
    void FUN_00288e80(int v);
};
}

void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d6d0(unsigned int size);
void *__cdecl FUN_002aa300(int a, int b, int c, int d, int e);

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class Inv_2acd70 {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void *i3(void *caster, unsigned __int64 key);
};

struct NameHolder_2acd70 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct Mat_2acd70 {
    float m[16];
    void FUN_0022b980();
};


class Child_2acd70 : public Ref_2acd70 {
public:
    Child_2acd70 *FUN_002d4040(void *r);
};

struct IntVec_2acd70 {
    Child_2acd70 **data;
    void FUN_002ab8e0(unsigned int n, int *fill);
};

class Yobj {
public:
    void *FUN_00288960(int a, int b);
};

class Xobj : public Ref_2acd70 {
public:
    char pad04[0x28 - 4];
    int f28;
    Yobj *FUN_00288a10(int i);
};

class Sink_2acd70 : public Ref_2acd70 {
public:
    char pad04[0x24 - 4];
    int f24;
    int f28;
};

class Wrap_2acd70 : public Ref_2acd70 {
public:
    Wrap_2acd70 *FUN_002d5640(Xobj *z, int a, float b);
};

class Tail_2acd70 : public Ref_2acd70 {
public:
    Tail_2acd70 *FUN_002d6760();
};

class Obj_2acd70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void *shader);
    char pad04[4];
    NameHolder_2acd70 name;
    char pad10[0x88 - 0x10];
    Ref_2acd70 *f88;
    Ref_2acd70 *f8c;
    Ref_2acd70 *f90;
    int f94;
    char pad98[0xa5 - 0x98];
    char ba5;
    char ba6;
    char pada7[0x130 - 0xa7];
    void *f130;
    void *f134;
    char pad138[4];
    void *f13c;
    Mat_2acd70 *f140;
    int f144;
    int f148;
    char pad14c[0x15c - 0x14c];
    char b15c;
    char pad15d[0x184 - 0x15d];
    int f184;
    float f188;
    char pad18c[0x1bc - 0x18c];
    Sink_2acd70 *f1bc;
    Ref_2acd70 *f1c0;
    Ref_2acd70 *f1c4;
    int *f1c8;
    int *f1cc;
    char pad1d0[4];
    IntVec_2acd70 vec1d4;
    Obj_2acd70 *FUN_002d63a0();
};

class Loader_2acd70 {
public:
    Ref_2acd70 *FUN_002ac180(Reader *r, Inv_2acd70 *i, int tag);
    Obj_2acd70 *FUN_002acd70(Reader *R, Inv_2acd70 *a1);
};

class Node {
public:
    virtual void n0();
};

class Pool_2acd70 {
public:
    Node *FUN_00265310(int v);
};
extern Pool_2acd70 *DAT_00527c58;

struct Frame_2acd70 {
    char len;           // 0x00
    char b21;           // 0x01
    char b22;           // 0x02
    char b13;           // 0x03
    int x4;             // 0x04
    Ref_2acd70 *x8;            // 0x08
    void *xc;           // 0x0c
    int x10;            // 0x10
    Ref_2acd70 *x14;           // 0x14
    int x18;            // 0x18
    void *x1c;          // 0x1c
    int x20;            // 0x20
    int x24;            // 0x24
    int x28;            // 0x28
    int x2c;            // 0x2c
    int x30;            // 0x30
    int x34;            // 0x34
    int x38;            // 0x38
    int x3c;            // 0x3c
    pure3d::AnimationLoader *x40;   // 0x40
    int x44;            // 0x44
    int x48;            // 0x48
    int x4c;            // 0x4c
    int x50;            // 0x50
    int x54;            // 0x54
    int x58;            // 0x58
    int id5c[2];        // 0x5c
    int id64[2];        // 0x64
    char name1[0x100];  // 0x6c
    char name2[0x100];  // 0x16c
    char name3[0x100];  // 0x26c
};

Obj_2acd70 *Loader_2acd70::FUN_002acd70(Reader *R, Inv_2acd70 *a1)
{
    Frame_2acd70 f;
    Obj_2acd70 *obj = 0;
    unsigned int n;

    f.x1c = this;
    R->stream->FUN_002647e0(&f.x24, 1, 4, 1);
    R->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = (unsigned char)f.len;
    R->stream->FUN_002647e0(f.name1, n, 1, 1);
    f.name1[n] = 0;
    R->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = (unsigned char)f.len;
    R->stream->FUN_002647e0(f.name2, n, 1, 1);
    f.name2[n] = 0;
    R->stream->FUN_002647e0(&f.x28, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x38, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x24, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x3c, 1, 4, 1);
    R->stream->FUN_002647e0(&f.x34, 1, 4, 1);
    if (!R->FUN_002669f0())
        return 0;
    do {
        int k = R->FUN_00266a30();
        if (k == 0x15805) {
            R->stream->FUN_002647e0(&f.x50, 1, 4, 1);
            R->stream->FUN_002647e0(&f.len, 1, 1, 1);
            n = (unsigned char)f.len;
            R->stream->FUN_002647e0(f.name3, n, 1, 1);
            f.name3[n] = 0;
            R->stream->FUN_002647e0(&f.x54, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x2c, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x4c, 1, 4, 1);
            f.b21 = (f.x4c != 0);
            R->stream->FUN_002647e0(&f.x48, 1, 4, 1);
            f.b22 = (f.x48 != 0);
            R->stream->FUN_002647e0(&f.x58, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x20, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x30, 1, 4, 1);
            f.b13 = (f.x30 != 0);
            R->stream->FUN_002647e0(&f.x10, 1, 4, 1);
            R->stream->FUN_002647e0(&f.x18, 1, 4, 1);

            void *mem = thunk_FUN_0008d690(0x1e0);
            if (mem != 0)
                obj = ((Obj_2acd70 *)mem)->FUN_002d63a0();
            else
                obj = 0;
            obj->name.FUN_0027b040(f.name1);
            unsigned __int64 key = FUN_0027b020(f.name2);
            obj->v8(a1->i3(new (&f.xc) content::LoadInventory::DynamicCaster<pure3d::Shader>, key));
            obj->f144 = f.x18;
            obj->f184 = f.x38;
            obj->ba5 = f.b21;
            obj->ba6 = f.b22;
            obj->f148 = f.x10;
            obj->b15c = f.b13;
            if (f.x28 == 0x444e4152)
                obj->f188 = 3.1415927410125732f;
            else
                obj->f188 = 0.0f;
            if (obj->f1c8 == 0) {
                unsigned int cnt = f.x20;
                if (cnt != 0) {
                    int *arr = (int *)FUN_0008d6d0(cnt * 4);
                    obj->f1c8 = arr;
                    if (arr != 0) {
                        obj->f1cc = (int *)((char *)arr + cnt * 4);
                        unsigned int c = f.x20;
                        do {
                            if (arr != 0)
                                *arr = 0;
                            arr++;
                            c--;
                        } while (c != 0);
                    } else {
                        obj->f1c8 = 0;
                        obj->f1cc = 0;
                    }
                } else {
                    obj->f1c8 = 0;
                    obj->f1cc = 0;
                }
            }
            if (*(float *)&f.x18 > 0.0f || *(float *)&f.x10 > 0.0f) {
                Mat_2acd70 *m = (Mat_2acd70 *)FUN_0008d690(0x40);
                obj->f140 = m;
                m->FUN_0022b980();
            }
            pure3d::AnimationLoader *ab = dynamic_cast<pure3d::AnimationLoader *>(
                (content::ObjectLoader *)DAT_00527c58->FUN_00265310(0x121000));
            f.x40 = ab;
            ab->AddRef();
            f.x44 = ab->FUN_00288e90();
            ab->FUN_00288e80(1);
            while (R->FUN_002669f0()) {
                int k2 = R->FUN_00266a30();
                if (k2 == 0x15808) {
                    R->FUN_00266a30();
                    f.x14 = 0;
                    ab->a5((int *)&f.x14, f.id5c, R, a1);
                    if (f.x14 != 0) {
                        Ref_2acd70 *z = f.x14;
                        z->AddRef();
                        if (obj->f1c4 != 0)
                            obj->f1c4->Release();
                        obj->f1c4 = z;
                        void *mem2 = FUN_0008d690(0x30);
                        Wrap_2acd70 *w;
                        if (mem2 != 0) {
                            unsigned int u = f.x34;
                            w = ((Wrap_2acd70 *)mem2)->FUN_002d5640((Xobj *)f.x14, f.x3c, (float)u);
                        } else {
                            w = 0;
                        }
                        if (w != 0)
                            w->AddRef();
                        if (obj->f1bc != 0)
                            obj->f1bc->Release();
                        obj->f1bc = (Sink_2acd70 *)w;
                    }
                    R->FUN_00266be0();
                } else if (k2 == 0x15809) {
                    R->FUN_00266a30();
                    f.x8 = 0;
                    ab->a5((int *)&f.x8, f.id64, R, a1);
                    if (f.x8 != 0) {
                        Xobj *X = (Xobj *)f.x8;
                        X->AddRef();
                        if (obj->f1c0 != 0)
                            obj->f1c0->Release();
                        obj->f1c0 = X;
                        f.xc = (void *)((Xobj *)f.x8)->f28;
                        f.x4 = 0;
                        obj->vec1d4.FUN_002ab8e0((unsigned int)f.xc, &f.x4);
                        int i;
                        for (i = 0; i < (int)f.xc; i++) {
                            void *mem3 = FUN_0008d690(0x4c);
                            f.x4 = (int)mem3;
                            Child_2acd70 *ch;
                            if (mem3 != 0)
                                ch = ((Child_2acd70 *)f.x4)->FUN_002d4040(((Xobj *)f.x8)->FUN_00288a10(i));
                            else
                                ch = 0;
                            obj->vec1d4.data[obj->f94] = ch;
                            obj->vec1d4.data[obj->f94]->AddRef();
                            obj->f94 = obj->f94 + 1;
                        }
                        Yobj *Y = ((Xobj *)f.x8)->FUN_00288a10(0);
                        obj->f130 = Y->FUN_00288960(0x415254, 0x54434556);
                        obj->f134 = Y->FUN_00288960(0x544f52, 0x544f52);
                        obj->f13c = Y->FUN_00288960(0x534956, 0x4c4f4f42);
                        ab = f.x40;
                    }
                    R->FUN_00266be0();
                } else if (k2 == 0x1580a) {
                    int tag;
                    if (f.x2c == 0x4e4c50)
                        tag = 0x15b01;
                    else if (f.x2c == 0x544e50)
                        tag = 0x15b00;
                    else if (f.x2c == 0x52485053)
                        tag = 0x15b02;
                    else
                        tag = 0;
                    if (tag != 0) {
                        obj->f88 = ((Loader_2acd70 *)f.x1c)->FUN_002ac180(R, a1, tag);
                        obj->f88->AddRef();
                    }
                }
                R->FUN_00266be0();
            }
            ab = f.x40;
            ab->FUN_00288e80(f.x44);
            ab->Release();
            void *mem4 = FUN_0008d690(8);
            Tail_2acd70 *tl;
            if (mem4 != 0)
                tl = ((Tail_2acd70 *)mem4)->FUN_002d6760();
            else
                tl = 0;
            obj->f90 = tl;
            tl->AddRef();
            unsigned int tag = 0x454e4f4e;
            Sink_2acd70 *sk = obj->f1bc;
            if (sk != 0) {
                if (sk->f24 != 0) {
                    if (sk->f28 != 0)
                        tag = 0x41424752;
                    else
                        tag = 0x424752;
                } else if (sk->f28 != 0) {
                    tag = 0x41;
                }
            }
            Ref_2acd70 *r = (Ref_2acd70 *)FUN_002aa300(f.x28, f.x24, tag, f.x18, f.x10);
            if (r != 0)
                r->AddRef();
            if (obj->f8c != 0)
                obj->f8c->Release();
            obj->f8c = r;
        }
        R->FUN_00266be0();
        if (obj != 0)
            break;
    } while (R->FUN_002669f0());
    return obj;
}
