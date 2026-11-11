// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e1960..0x002e5330 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcb4ee90 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcb4ee90 {} using namespace fn_fcb4ee90;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() {
    return p;
}
namespace fn_fcb4ee90 {
struct Hdr8;
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
void* __cdecl FUN_00266e00(int a, int b);
extern "C" void __cdecl FUN_00267090(void* p);
class NonCopyable_2e1960 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class AttrList {
  public:
    virtual void a0(float x, float y, float z);
    virtual void a1(float x, float y, float z);
    virtual void a2(float x, float y, float z);
    virtual void a3(float x, float y, float z);
    virtual void a4(unsigned int v, int w);
    virtual void a5();
    virtual void a6(float x, float y, unsigned int idx);
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10(int b3, int b2, int b1, int b0);
    virtual void a11(float x, float y, float z);
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
};
class Builder {
  public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual AttrList* b4();
    virtual void b5(AttrList* l);
    virtual void b6();
    virtual int b7();
    virtual void b8(int v);
    virtual void b9(void* buf, unsigned int n);
    virtual void b10();
    virtual AttrList* b11(unsigned int v);
    virtual void b12();
    virtual void b13(int id, unsigned int v);
};
class Factory_2e1960 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual Builder* f10(void* desc);
};
class Maker_2e1960 {
  public:
    virtual void m0();
    virtual void m1();
    virtual int m2(int a, int b, int c, int d, int e);
    virtual void m3();
    virtual char m4(int a, int b);
    virtual void m5(Builder* b, int r);
};
} // namespace fn_fcb4ee90
class Gfx {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual void g39();
    virtual void g40();
    virtual void g41();
    virtual void g42();
    virtual void g43();
    virtual void g44();
    virtual void g45();
    virtual void g46();
    virtual void g47();
    virtual void g48();
    virtual void g49();
    virtual void g50();
    virtual void g51();
    virtual void g52();
    virtual void g53();
    virtual void g54();
    virtual void g55();
    virtual void g56();
    virtual void g57();
    virtual void g58();
    virtual void g59();
    virtual void g60();
    virtual void g61();
    virtual void g62();
    virtual void g63();
    virtual void g64();
    virtual void g65();
    virtual void g66();
    virtual void g67();
    virtual void g68();
    virtual void g69();
    virtual void g70();
    virtual void g71();
    virtual void g72();
    virtual void g73();
    virtual void g74();
    virtual void g75();
    virtual void g76();
    virtual void g77();
    virtual void g78();
    virtual void g79();
    virtual void g80();
    virtual void g81();
    virtual void g82();
    virtual void g83();
    virtual void g84();
    virtual void g85();
    virtual void g86();
    virtual void g87();
    virtual void g88();
    virtual Maker_2e1960* g89(int id);
};
namespace fn_fcb4ee90 {
struct Desc_2e1960 {
    int f40;
    int f44;
    unsigned char c48[8];
    int f50;
    int f54;
    char b58;
    char b59;
    char pad5a[2];
    int f5c;
    int f60;
};
class PalList_2e1960 : public NonCopyable_2e1960 {
  public:
    char pad04[4];
    char* begin;
    char* end;
};
struct Hdr8 {
    char pad00[0x10];
    int f10;
};
class __declspec(novtable) PrimGroupBase {
  public:
    virtual void p0_00038290();
    virtual void p1_000382a0();
    virtual void* p2_002e14b0(char);
    virtual void p3_0027afe0();
    virtual void p4_0027aff0();
    virtual void p5_002df510();
    virtual void p6_002df540();
    virtual void p7_002df520();
    virtual void p8_002dfd70(Hdr8* v);
    PrimGroupBase();
};
class __declspec(novtable) PrimGroup : public PrimGroupBase {
  public:
    char pad04[0x40 - 4];
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    NonCopyable_2e1960* f58;
};
namespace pure3d {
class PrimGroupOptimized : public PrimGroup {
  public:
    PrimGroupOptimized(int a, int b) {
        f48 = a;
        f40 = 0;
        f44 = 0;
        f4c = b;
        f50 = -1;
        f58 = 0;
    }
};
}
class PrimGroupPalette_2e1960 : public PrimGroup {
  public:
    char pad5c[4];
    NonCopyable_2e1960* f60;
    NonCopyable_2e1960* f64;
    PrimGroupPalette_2e1960* FUN_002dffe0(int a, int b);
};
struct IntVec_2e1960 {
    int* data;
    int cap;
    void FUN_002e18c0(unsigned int n);
};
namespace pure3d {
class MatrixPaletteList : public NonCopyable_2e1960 {
  public:
    int f4;
    IntVec_2e1960 vec;
    MatrixPaletteList() {
        f4 = 0;
        vec.data = 0;
        vec.cap = 0;
    }
};
}
void *__cdecl FUN_00266e00(int a, unsigned int n);
struct RefObj_2e2a70 {
    virtual void AddRef();
    virtual void Release();
};
struct IntVec_2e2a70 {
    unsigned int *begin;
    unsigned int *end;
};
struct NonCopyable_2e2a70 {
    int refCount;
    NonCopyable_2e2a70() throw() { refCount = 0; }
};
class MatrixPaletteList : public NonCopyable_2e2a70 {
public:
    virtual void AddRef_00018b30();
    virtual void Release_00018b40();
    IntVec_2e2a70 vec;
    int pad10;
    MatrixPaletteList() { vec.begin = 0; vec.end = 0; }
};
struct VData {
    char pad00[0x18];
    char *f18;
    char *f1c;
    char pad20[8];
    char *f28;
    char pad2c[4];
    char *f30;
    char pad34[4];
    char *tex[4];
    char *uv[4];
    char *f58;
    void FUN_002d0a50(int a, RefObj_2e2a70 *b, MatrixPaletteList *c);
};
class Buffer_2e2a70 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void b2();
    virtual void b3();
    virtual int b4();
    virtual void b5(int v);
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9(unsigned short *buf, unsigned int n);
};
struct Desc_2e2a70 {
    unsigned int a;
    unsigned int flags;
    unsigned char tag[8];
    unsigned int c;
    unsigned int d;
    unsigned char e0;
    unsigned char e1;
    unsigned char pad[2];
    unsigned int f;
    unsigned int g;
};
class Factory_2e2a70 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual Buffer_2e2a70 *Create(Desc_2e2a70 *d);
};
struct Vec3_2e2a70 { float x, y, z; };
class PrimGroupSkinnedPC_2e2a70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void SetName(int v);
    char pad04[0x10];
    Vec3_2e2a70 v14;
    Vec3_2e2a70 v20;
    Vec3_2e2a70 v2c;
    float f38;
    char pad3c[8];
    unsigned int f44;
    char pad48[8];
    unsigned int f50;
    char pad54[4];
    Buffer_2e2a70 *vb;
    RefObj_2e2a70 *pal;
    RefObj_2e2a70 *palShared;
    MatrixPaletteList *list;
    VData *vdata;
    PrimGroupSkinnedPC_2e2a70 *FUN_002e0620(unsigned int a, unsigned int b, unsigned int c);
};
union Slot5_2e2a70 {
    const unsigned int *p;
    unsigned int u;
};
void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" void __cdecl FUN_0028fcc0(const char *fmt, ...);
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
class Shader_2e49a0 {
public:
    virtual void v0();
    virtual void v1();
    Shader_2e49a0 *FUN_0028edf0(const char *name, int flags);
};
class LoadContext_2e49a0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Shader_2e49a0 *lookup(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster,
                              unsigned __int64 id);
};
struct Frame_2e49a0 {
    int scratch;             // 0x08
    char pad[3];
    unsigned char len;       // 0x0f
    char name[0x100];        // 0x10
};
class Releasable_2e4d70 {
public:
    virtual void v0();
    virtual void Release();      // slot 1
};
class Dispatcher_2e4d70 {
public:
    char pad00[8];
    Releasable_2e4d70 *pending;     // 0x08
    char pad0c[5];
    char enabled;            // 0x11
    unsigned short mode;     // 0x12
    char FUN_002e49a0(int a, int b);
    void FUN_002e1960(int a, int b, int c, int d, int e);
    void FUN_002e22c0(int a, int b, int c, int d, int e);
    void FUN_002e4d70(int a, int b, int c, int d, char direct, int e);
};
struct Resource { virtual void unused(); virtual void release(); };
struct Controller {
    char pad[8];
    Resource* resource;
    bool FUN_002e4bd0(int second, int third);
    void FUN_002e3bd0(int first, int second, int third, int fourth);
    void FUN_002e30f0(int first, int second, int third, int fourth);
    void FUN_002e4e00(int first, int second, int third, int fourth, char flag);
};
namespace pure3d {
class Entity {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace pure3d {
class LightGroup : public Entity {
  public:
    LightGroup* Self();
    char pad2[0x40];
};
}
struct Inner_2e4fb0 {
    void sub_002c6d30();
};
struct Obj_2e4fb0 {
    char pad[4];
    Obj_2e4fb0* target();
};
class Part_2e5280 {
  public:
    void Cleanup_002c6d50();
};
class Thing_2e5280 {
  public:
    int v;
    Part_2e5280 part;
    Thing_2e5280* Run(unsigned char flags);
};
void DeleteThing_0008d330(Thing_2e5280*);
class Ref_2e5310 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2e5310 {
  public:
    char pad[0xc];
    Ref_2e5310* member;
    void clear();
};
struct Stream {
  public:
    char _m_pad_0[0x284];
    Reader *reader;
    int FUN_002647e0(void* buf, int count, int size, int flag);
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    unsigned int FUN_001c61c0();
    void FUN_001c6200(void *dst);
    float FUN_001c61e0();
    int FUN_00266c30();
};
struct Reader {
  public:
    char _m_pad_0[0x284];
    Stream* stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    unsigned int FUN_001c61c0();
    float FUN_001c61e0();
    void FUN_001c6200(void* v);
    void FUN_000f95e0();
    void FUN_000f9650(void* a, void* b, int c);
    void FUN_002647e0(void *dst, int count, int size, int flag);
};
struct Hdr_2e1960 {
    char pad00[8];
    Hdr8* f8;
    int fc;
    char b10;
    char pad11[0x1c - 0x11];
    unsigned int f1c;
    int f20;
    int f24;
    int f28;
    void FUN_002a46d0(int a1, void* obj);
    void FUN_002a4b00(int a1, Reader* r, int a3);
    void Load(int a1, Reader* R, int a3, PalList_2e1960* a4, unsigned int* a5);
};
struct Frame_2e1960 {
    unsigned int s0;
    Hdr_2e1960* self;
    PrimGroup* obj;
    unsigned int u12;
    unsigned int local20;
    PrimGroupPalette_2e1960* pal;
    unsigned int n24;
    unsigned int u28;
    unsigned int u32;
    unsigned int s36;
    unsigned int u40;
    Desc_2e1960 d;
    unsigned int s80;
    unsigned int v64;
    float v2[2];
    float v96[3];
    float v108[3];
    float v120[3];
    float v132[3];
    float v144[3];
};
union Slot2 {
    Stream *stream;
    unsigned short *buf;
    MatrixPaletteList *list;
    unsigned int cnt;
};
class PrimLoader {
public:
    char pad00[8];
    unsigned int f08;
    unsigned int f0c;
    char pad10[4];
    unsigned int f14;
    char pad18[4];
    unsigned int flags;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    void FUN_002a46d0(int a1, PrimGroupSkinnedPC_2e2a70 *o);
    void FUN_002a4b00(int a1, Stream *s, int a3);
    void FUN_002e2a70(int a1, Slot2 a2, int a3, RefObj_2e2a70 *a4, Slot5_2e2a70 a5);
};
struct Frame_2e2a70 {
    PrimGroupSkinnedPC_2e2a70 *obj;     // 0x10
    Buffer_2e2a70 *vb;        // 0x14
    unsigned int vA;   // 0x18
    unsigned int cnt;  // 0x1c
    PrimLoader *self;  // 0x20
    unsigned int lim;  // 0x24
    unsigned int tmpw; // 0x28
    unsigned int tmpd; // 0x2c
    unsigned int idx;  // 0x30
    Desc_2e2a70 d;            // 0x34
};
class ShaderLoader {
public:
    char pad0[8];
    Shader_2e49a0 *shader;       // 0x08
    int word0c;
    unsigned char flag10;
    unsigned char flag11;
    unsigned short short12;
    int word14;
    int word18;
    int word1c;
    int word20;
    int word24;
    int word28;
    char FUN_002e49a0(Stream *s, LoadContext_2e49a0 *ctx);
};


// 0x002e1960 FUN_002e1960 (2315 B): equivalent/0x002e1960.cpp
// sym: ?Load@Hdr_2e1960@fn_fcb4ee90@@QAEXHPAUReader@2@HPAVPalList_2e1960@2@PAI@Z @c0ddd16ec73d @w1f5ecd418e3a
// STATUS: equivalent (tools/equiv.py level 3: 2161 inputs, branch coverage 134/134)
// FUN_002e1960 @ 0x002e1960
// equiv-map: ??0PrimGroupBase@@QAE@XZ = 0x002a5060
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void Hdr_2e1960::Load(int a1, Reader* R, int a3, PalList_2e1960* a4, unsigned int* a5) {
    Frame_2e1960 f;
    f.self = this;
    unsigned int flags = f1c;
    if (flags & 0x20)
        f.local20 = 1;
    else if (flags & 0x4000)
        f.local20 = (flags >> 15) & 7;
    else
        f.local20 = 0;
    f.v64 = flags & 0xf;
    PrimGroup* obj;
    f.pal = 0;
    if (a4 != 0 && ((a4->end - a4->begin) >> 6) != 0) {
        void* m = thunk_FUN_0008d690(0x68);
        if (m) {
            f.pal = ((PrimGroupPalette_2e1960*)m)->FUN_002dffe0(f1c, f20);
            obj = f.pal;
        } else {
            f.pal = 0;
            obj = 0;
        }
    } else {
        void* m = thunk_FUN_0008d690(0x60);
        if (m)
            obj = new (m) pure3d::PrimGroupOptimized(f1c, f20);
        else
            obj = 0;
    }
    f.obj = obj;
    obj->p8_002dfd70(f8);
    obj->f44 = fc;
    FUN_002a46d0(a1, obj);

    Desc_2e1960& d = f.d;
    d.f40 = fc;
    d.f44 = f1c;
    d.f50 = f20;
    d.f54 = f24;
    for (int i = 0; i < 8; i++)
        d.c48[i] = 0x20;
    d.b59 = 0;
    d.f5c = 0;
    if (a5) {
        ((unsigned int*)d.c48)[0] = a5[0];
        ((unsigned int*)d.c48)[1] = a5[1];
    }
    d.b58 = b10;
    d.f60 = f28;
    Builder* B = (*(Factory_2e1960**)&DAT_0052c2a0)->f10(&d);
    if (B)
        ((NonCopyable_2e1960*)B)->AddRef();
    if (obj->f58)
        obj->f58->Release();
    obj->f58 = (NonCopyable_2e1960*)B;

    Maker_2e1960* mk = DAT_0052c2a8->g89(0x106);
    if (mk) {
        bool hasPal = (a4 != 0);
        if (mk->m4(f8->f10, hasPal)) {
            int r = mk->m2(f8->f10, fc, f1c, 1, hasPal);
            mk->m5(B, r);
        }
    }

    if (R->FUN_002669f0()) {
        do {
            int id = R->FUN_00266a30();
            if ((unsigned int)id > 0x1001c) {
                if (id == 0x121204)
                    FUN_002a4b00(a1, R, a3);
            } else if (id == 0x1001c) {
                if (f1c & 0x4000) {
                    R->stream->FUN_002647e0(&f.n24, 1, 4, 1);
                    R->stream->FUN_002647e0(&f.u12, 1, 4, 1);
                    if (f.u12 < f.local20) {
                        AttrList* l = B->b4();
                        for (unsigned int i = 0; i < f.n24; i++) {
                            R->stream->FUN_002647e0(&f.u32, 1, 4, 1);
                            l->a4(f.u32, f.u12);
                            l->a17();
                        }
                        B->b5(l);
                    }
                }
            } else {
                unsigned int idx = id - 0x10003;
                if (idx <= 0x13) {
                    switch (idx) {
                    case 0:
                        R->FUN_001c6200((char*)obj + 0x14);
                        R->FUN_001c6200((char*)obj + 0x20);
                        break;
                    case 1:
                        R->FUN_001c6200((char*)obj + 0x2c);
                        *(float*)((char*)obj + 0x38) = R->FUN_001c61e0();
                        break;
                    case 2:
                        if (f1c & 0x2000) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v144;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a0(v[0], v[1], v[2]);
                            }
                            B->b5(l);
                        }
                        break;
                    case 3:
                        if (f1c & 0x10) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v108;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a1(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 19:
                        if (f1c & 0x800) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v132;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a2(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 18:
                        if (f1c & 0x1000) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v96;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a3(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 5:
                        if (f1c & 0x20) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                unsigned int& v = f.u40;
                                R->stream->FUN_002647e0(&v, 1, 4, 1);
                                l->a4(v, 0);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 4:
                        if (f1c & 0xf) {
                            unsigned int cnt = R->FUN_001c61c0();
                            unsigned int ix = R->FUN_001c61c0();
                            if (ix < f.v64) {
                                AttrList* l = B->b4();
                                for (unsigned int i = cnt; i > 0; i--) {
                                    float (&v)[2] = f.v2;
                                    R->stream->FUN_002647e0(v, 2, 4, 1);
                                    l->a6(v[0], v[1], ix);
                                    l->a17();
                                }
                                B->b5(l);
                            }
                        }
                        break;
                    case 7: {
                        unsigned int n = R->FUN_001c61c0();
                        unsigned short* buf = (unsigned short*)FUN_00266e00(1, n * 2);
                        for (unsigned int i = 0; i < n; i++) {
                            unsigned int& v = f.u28;
                            R->stream->FUN_002647e0(&v, 1, 4, 1);
                            buf[i] = (unsigned short)v;
                        }
                        B->b9(buf, n);
                        FUN_00267090(buf);
                        break;
                    }
                    case 9:
                        if (f1c & 0x100) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                float (&v)[3] = f.v120;
                                R->stream->FUN_002647e0(v, 3, 4, 1);
                                l->a11(v[0], v[1], v[2]);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 8:
                        if (f1c & 0x80) {
                            unsigned int n = R->FUN_001c61c0();
                            AttrList* l = B->b4();
                            for (unsigned int i = 0; i < n; i++) {
                                unsigned int& v = f.u12;
                                R->stream->FUN_002647e0(&v, 1, 4, 1);
                                l->a10(v >> 24, (v >> 16) & 0xff, (v >> 8) & 0xff, v & 0xff);
                                l->a17();
                            }
                            B->b5(l);
                        }
                        break;
                    case 10:
                        if (f1c & 0x80) {
                            unsigned int n = R->FUN_001c61c0();
                            pure3d::MatrixPaletteList* mp;
                            void* mm = FUN_0008d690(0x14);
                            if (mm)
                                mp = new (mm) pure3d::MatrixPaletteList();
                            else
                                mp = 0;
                            mp->vec.FUN_002e18c0(n);
                            for (unsigned int i = 0; i < n; i++) {
                                unsigned int& v = f.u32;
                                R->stream->FUN_002647e0(&v, 1, 4, 1);
                                mp->vec.data[i] = v;
                            }
                            if (a4)
                                a4->AddRef();
                            if (f.pal->f60)
                                f.pal->f60->Release();
                            f.pal->f60 = a4;
                            if (mp)
                                mp->AddRef();
                            if (f.pal->f64)
                                f.pal->f64->Release();
                            f.pal->f64 = mp;
                        }
                        break;
                    case 15:
                    case 17: {
                        R->FUN_000f95e0();
                        unsigned int format = R->FUN_001c61c0();
                        hulk_uintptr size = R->FUN_001c61c0();
                        B->b13(R->FUN_00266c30(), format);
                        AttrList* l = B->b11(size);
                        R->FUN_000f9650(l, (void*)size, 1);
                        B->b12();
                        break;
                    }
                    case 16: {
                        R->FUN_000f95e0();
                        unsigned int format = R->FUN_001c61c0();
                        hulk_uintptr size = R->FUN_001c61c0();
                        B->b13(R->FUN_00266c30(), format);
                        hulk_intptr r = B->b7();
                        R->FUN_000f9650((void*)r, (void*)size, 1);
                        B->b8(f24);
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
            R->FUN_00266be0();
        } while (R->FUN_002669f0());
    }
    B->b6();
}


// 0x002e2a70 FUN_002e2a70 (1577 B): equivalent/0x002e2a70.cpp
// sym: ?FUN_002e2a70@PrimLoader@fn_fcb4ee90@@QAEXHTSlot2@2@HPAURefObj_2e2a70@2@TSlot5_2e2a70@2@@Z @73fb26f78a3b @w7eb61fa2b446
// STATUS: equivalent (tools/equiv.py level 3: 2670 inputs, branch coverage 119/124, incomplete)
// FUN_002e2a70 @ 0x002e2a70
// FUN_002e2a70 @ 0x002e2a70
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void PrimLoader::FUN_002e2a70(int a1, Slot2 a2, int a3, RefObj_2e2a70 *a4, Slot5_2e2a70 a5)
{
    Frame_2e2a70 f;
    unsigned int fl = flags;
    f.self = this;
    unsigned int vA;
    if (fl & 0x20)
        vA = 1;
    else if (fl & 0x4000)
        vA = (fl >> 15) & 7;
    else
        vA = 0;
    f.vA = vA;
    f.lim = fl & 0xf;
    void *mem = thunk_FUN_0008d690(0x70);
    PrimGroupSkinnedPC_2e2a70 *obj = 0;
    if (mem != 0)
        obj = ((PrimGroupSkinnedPC_2e2a70 *)mem)->FUN_002e0620(flags, f20, f24);
    f.obj = obj;
    obj->SetName(f08);
    obj->f44 = f0c;
    obj->f50 = f14;
    FUN_002a46d0(a1, obj);
    f.d.flags = flags & 0xfffffe7f;
    f.d.a = f0c;
    f.d.tag[3] = 0x20;
    f.d.tag[2] = 0x20;
    f.d.tag[1] = 0x20;
    f.d.tag[0] = 0x20;
    f.d.tag[4] = 0x20;
    f.d.tag[5] = 0x20;
    f.d.tag[6] = 0x20;
    f.d.c = f20;
    f.d.d = f24;
    f.d.e1 = 0;
    f.d.f = 0;
    f.d.e0 = 0;
    f.d.g = f28;
    if (a5.p != 0) {
        unsigned int lo = a5.p[0];
        unsigned int hi = a5.p[1];
        *(unsigned int *)&f.d.tag[0] = lo;
        *(unsigned int *)&f.d.tag[4] = hi;
    }
    Buffer_2e2a70 *vb = (*(Factory_2e2a70**)&DAT_0052c2a0)->Create(&f.d);
    f.vb = vb;
    if (vb != 0)
        vb->AddRef();
    if (obj->vb != 0)
        obj->vb->Release();
    obj->vb = f.vb;
    Stream *stream = a2.stream;
    VData *vd = obj->vdata;
    while (stream->FUN_002669f0()) {
        PrimLoader *self = f.self;
        unsigned int id = stream->FUN_00266a30();
        if (id > 0x1001c) {
            if (id == 0x121204)
                self->FUN_002a4b00(a1, stream, a3);
        } else if (id == 0x1001c) {
            if (self->flags & 0x4000) {
                ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.cnt), (hulk_intptr)1, 4, (hulk_intptr)1);
                ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.idx), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int index = f.idx;
                if (index < f.vA) {
                    if (f.cnt > 0) {
                        unsigned int i = 0;
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->uv[index] + i * 4), (hulk_intptr)1, 4, (hulk_intptr)1);
                            i++;
                        } while (i < f.cnt);
                    }
                }
            }
        } else {
            switch (id - 0x10003) {
            case 0:
                stream->FUN_001c6200(&obj->v14);
                stream->FUN_001c6200(&obj->v20);
                break;
            case 1:
                stream->FUN_001c6200(&obj->v2c);
                obj->f38 = stream->FUN_001c61e0();
                break;
            case 2:
                if (self->flags & 0x2000) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->f18 + off), (hulk_intptr)3, 4, (hulk_intptr)1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 3:
                if (self->flags & 0x10) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->f1c + off), (hulk_intptr)3, 4, (hulk_intptr)1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 4:
                if (self->flags & 0xf) {
                    unsigned int n = stream->FUN_001c61c0();
                    a2.cnt = stream->FUN_001c61c0();
                    if (a2.cnt < f.lim) {
                        unsigned int i = 0;
                        if (n > 0) {
                            do {
                                ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->tex[a2.cnt] + i * 8), (hulk_intptr)2, 4, (hulk_intptr)1);
                                i++;
                            } while (i < n);
                        }
                    }
                }
                break;
            case 5:
                if (self->flags & 0x20) {
                    unsigned int n = stream->FUN_001c61c0();
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->uv[0] + i * 4), (hulk_intptr)1, 4, (hulk_intptr)1);
                            i++;
                        } while (i < n);
                    }
                }
                break;
            case 7: {
                unsigned int n = stream->FUN_001c61c0();
                a2.buf = (unsigned short *)FUN_00266e00(1, n * 2);
                unsigned int i = 0;
                if (n > 0) {
                    do {
                        ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.tmpw), (hulk_intptr)1, 4, (hulk_intptr)1);
                        a2.buf[i] = (unsigned short)f.tmpw;
                        i++;
                    } while (i < n);
                }
                f.vb->b9(a2.buf, n);
                FUN_00267090(a2.buf);
                break;
            }
            case 9:
                if (self->flags & 0x100) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->uv[3] + off), (hulk_intptr)3, 4, (hulk_intptr)1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 8:
                if (self->flags & 0x80) {
                    unsigned int n = stream->FUN_001c61c0();
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&a5.u), (hulk_intptr)1, 4, (hulk_intptr)1);
                            vd->uv[2][i * 4] = (char)(a5.u >> 24);
                            vd->uv[2][i * 4 + 1] = (char)(a5.u >> 16);
                            vd->uv[2][i * 4 + 2] = (char)(a5.u >> 8);
                            vd->uv[2][i * 4 + 3] = (char)a5.u;
                            i++;
                        } while (i < n);
                    }
                }
                break;
            case 10:
                if (self->flags & 0x80) {
                    unsigned int n = stream->FUN_001c61c0();
                    void *m = FUN_0008d690((int)sizeof(MatrixPaletteList));
                    MatrixPaletteList *list = 0;
                    if (m != 0)
                        list = new (m) MatrixPaletteList();
                    a2.list = list;
                    ((owners::Object_2e18c0 *)&(a2.list->vec))->FUN_002e18c0((int)n);
                    unsigned int i = 0;
                    if (n > 0) {
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(&f.tmpd), (hulk_intptr)1, 4, (hulk_intptr)1);
                            a2.list->vec.begin[i] = f.tmpd;
                            i++;
                        } while (i < n);
                    }
                    RefObj_2e2a70 *p = a4;
                    if (p != 0)
                        p->AddRef();
                    PrimGroupSkinnedPC_2e2a70 *o = f.obj;
                    if (o->palShared != 0)
                        o->palShared->Release();
                    o->palShared = p;
                    MatrixPaletteList *l = a2.list;
                    if (l != 0)
                        l->AddRef_00018b30();
                    if (o->list != 0)
                        o->list->Release_00018b40();
                    o->list = l;
                }
                break;
            case 18:
                if (self->flags & 0x1000) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->f30 + off), (hulk_intptr)3, 4, (hulk_intptr)1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            case 19:
                if (self->flags & 0x800) {
                    unsigned int n = stream->FUN_001c61c0();
                    if (n > 0) {
                        unsigned int off = 0;
                        do {
                            ((owners::X_2647e0 *)(stream->reader))->FUN_002647e0((hulk_intptr)(vd->f28 + off), (hulk_intptr)3, 4, (hulk_intptr)1);
                            off += 0xc;
                        } while (--n != 0);
                    }
                }
                break;
            default:
                break;
            }
        }
        stream->FUN_00266be0();
        obj = f.obj;
    }
    MatrixPaletteList *pl = obj->list;
    int bufv;
    if ((unsigned int)(pl->vec.end - pl->vec.begin) > 0) {
        bufv = f.vb->b4();
        vd->FUN_002d0a50(bufv, obj->palShared, obj->list);
    } else {
        bufv = f.vb->b4();
        vd->FUN_002d0a50(bufv, 0, 0);
    }
    f.vb->b5(bufv);
}

} // namespace fn_fcb4ee90

// 0x002e30f0 FUN_002e30f0 (2657 B): equivalent/0x002e30f0.cpp [wrapped: conflict: Gfx; PrimGroup; pure3d::MatrixPaletteList]
// sym: ?Load@Hdr@fn_002e30f0@@QAEXHPAVReader@2@HPAVPalList_2e30f0@2@@Z @1cb189e2b0c6 @w1ada80326604
namespace fn_002e30f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2774 inputs, branch coverage 116/126, incomplete)
// FUN_002e30f0 @ 0x002e30f0
// equiv-map: ??0PrimGroupBase@@QAE@XZ = 0x002a5060
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


struct Hdr8;

void *thunk_FUN_0008d690(unsigned int size);
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_00266e00(int a, int b);
extern "C" void __cdecl FUN_00267090(void *p);

class Ref_2e30f0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    unsigned int FUN_001c61c0();
    float FUN_001c61e0();
    void FUN_001c6200(void *v);
    void FUN_000f95e0();
    void FUN_000f9650(void *a, void *b, int c);
};

// element list built by the loader
class AttrList {
public:
    virtual void a0(float x, float y, float z);
    virtual void a1(float x, float y, float z);
    virtual void a2(float x, float y, float z);
    virtual void a3(float x, float y, float z);
    virtual void a4(unsigned int v, int w);
    virtual void a5();
    virtual void a6(float x, float y, unsigned int idx);
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10(int b3, int b2, int b1, int b0);
    virtual void a11(float x, float y, float z);
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
};

class Builder {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual AttrList *b4();
    virtual void b5(AttrList *l);
    virtual void b6();
    virtual int b7();
    virtual void b8(int v);
    virtual void b9(void *buf, unsigned int n);
    virtual void b10();
    virtual AttrList *b11(unsigned int v);
    virtual void b12();
    virtual void b13(int id, unsigned int v);
};

class Factory_2e30f0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual Builder *f10(void *desc);
};

class Maker_2e30f0 {
public:
    virtual void m0();
    virtual void m1();
    virtual int m2(int a, int b, int c, int d, int e);
    virtual void m3();
    virtual char m4(int a, int b);
    virtual void m5(Builder *b, int r);
};

class Gfx {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual void g39();
    virtual void g40();
    virtual void g41();
    virtual void g42();
    virtual void g43();
    virtual void g44();
    virtual void g45();
    virtual void g46();
    virtual void g47();
    virtual void g48();
    virtual void g49();
    virtual void g50();
    virtual void g51();
    virtual void g52();
    virtual void g53();
    virtual void g54();
    virtual void g55();
    virtual void g56();
    virtual void g57();
    virtual void g58();
    virtual void g59();
    virtual void g60();
    virtual void g61();
    virtual void g62();
    virtual void g63();
    virtual void g64();
    virtual void g65();
    virtual void g66();
    virtual void g67();
    virtual void g68();
    virtual void g69();
    virtual void g70();
    virtual void g71();
    virtual void g72();
    virtual void g73();
    virtual void g74();
    virtual void g75();
    virtual void g76();
    virtual void g77();
    virtual void g78();
    virtual void g79();
    virtual void g80();
    virtual void g81();
    virtual void g82();
    virtual void g83();
    virtual void g84();
    virtual void g85();
    virtual void g86();
    virtual void g87();
    virtual void g88();
    virtual Maker_2e30f0 *g89(int id);
};


struct Desc2 {
    int f0;
    int f4;
    unsigned char c8[8];
    int f10;
    int f14;
    char b18;
    char b19;
    char pad1a[2];
    int f1c;
    int f20;
};

class PalList_2e30f0 : public Ref_2e30f0 {
public:
    char pad04[4];
    char *begin;
    char *end;
};

struct Hdr8 {
    char pad00[0x10];
    int f10;
};

struct Hdr {
    char pad00[8];
    Hdr8 *f8;
    int fc;
    char pad10[4];
    unsigned int flags;
    int f18;
    int f1c;
    int f20;
    void FUN_002a46d0(int a1, void *obj);
    void Load(int a1, Reader *R, int a3, PalList_2e30f0 *a4);
};

class __declspec(novtable) PrimGroupBase {
public:
    virtual void p0_00038290();
    virtual void p1_000382a0();
    virtual void* p2_002e14b0(char);
    virtual void p3_0027afe0();
    virtual void p4_0027aff0();
    virtual void p5_002df510();
    virtual void p6_002df540();
    virtual void p7_002df520();
    virtual void p8_002dfd70(Hdr8 *v);
    PrimGroupBase();
};

class __declspec(novtable) PrimGroup : public PrimGroupBase {
public:
    char pad04[0x40 - 4];
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    Ref_2e30f0 *f58;
};

namespace pure3d {
class PrimGroupOptimized : public PrimGroup {
public:
    PrimGroupOptimized(int a, int b)
    {
        f48 = a;
        f40 = 0;
        f44 = 0;
        f4c = b;
        f50 = -1;
        f58 = 0;
    }
};
}

class PrimGroupPalette_2e30f0 : public PrimGroup {
public:
    char pad5c[4];
    Ref_2e30f0 *f60;
    Ref_2e30f0 *f64;
    PrimGroupPalette_2e30f0 *FUN_002dffe0(int a, int b);
};

struct IntVec {
    int *data;
    int cap;
    void FUN_002e16f0(unsigned int n, unsigned int *fill);
};

namespace pure3d {
class MatrixPaletteList : public Ref_2e30f0 {
public:
    int f4;
    IntVec vec;
    MatrixPaletteList()
    {
        f4 = 0;
        vec.data = 0;
        vec.cap = 0;
    }
};
}



struct Frame_2e30f0 {
    unsigned int s0;                // 0
    union { unsigned int cnt; pure3d::MatrixPaletteList *mp; } u4;  // 4
    Hdr *self;                      // 8
    union { unsigned int y12; unsigned char hasPal; } u12;   // 12
    unsigned int n16;               // 16
    unsigned int v20;               // 20
    unsigned int local20;           // 24
    PrimGroupPalette_2e30f0 *pal;          // 28
    unsigned int y32;               // 32
    unsigned int v36;               // 36
    unsigned int n40;               // 40
    unsigned int c44;               // 44
    unsigned int v48;               // 48
    unsigned int c52;               // 52
    unsigned int n56;               // 56
    unsigned int c60;               // 60
    unsigned int n64;               // 64
    unsigned int n68;               // 68
    unsigned int zero72;            // 72
    unsigned int n76;               // 76
    unsigned int v80;               // 80
    unsigned int c84;               // 84
    unsigned int n88;               // 88
    unsigned int x92;               // 92
    unsigned int v64;               // 96
    unsigned int v100;              // 100
    unsigned int c104;              // 104
    unsigned int n108;              // 108
    unsigned int n112;              // 112
    unsigned int c116;              // 116
    Desc2 d;                        // 120
    char pad156[4];
    float v160[2];                  // 160
    float v168[3];                  // 168
    float v180[3];                  // 180
    float v192[3];                  // 192
    float v204[3];                  // 204
    float v216[3];                  // 216
    unsigned int c228;              // 228
    unsigned int c232;              // 232
    unsigned int c236;              // 236
};


void Hdr::Load(int a1, Reader *R, int a3, PalList_2e30f0 *a4)
{
    Frame_2e30f0 f;
    f.self = this;
    unsigned int flags_ = flags;
    if (flags_ & 0x20)
        f.local20 = 1;
    else if (flags_ & 0x4000)
        f.local20 = (flags_ >> 15) & 7;
    else
        f.local20 = 0;
    f.v64 = flags_ & 0xf;
    PrimGroup *obj;
    f.pal = 0;
    if (a4 != 0 && ((a4->end - a4->begin) >> 6) != 0) {
        void *m = thunk_FUN_0008d690(0x68);
        if (m) {
            f.pal = ((PrimGroupPalette_2e30f0 *)m)->FUN_002dffe0(flags, f18);
            obj = f.pal;
        } else {
            f.pal = 0;
            obj = 0;
        }
    } else {
        void *m = thunk_FUN_0008d690(0x60);
        if (m) {
            f.u12.y12 = flags;
            obj = new (m) pure3d::PrimGroupOptimized(f.u12.y12, f18);
        }
        else
            obj = 0;
    }
    obj->p8_002dfd70(f8);
    obj->f44 = fc;
    FUN_002a46d0(a1, obj);

    Builder *B = 0;
    unsigned char flag = 0;
    if (R->FUN_002669f0()) {
        hulk_uintptr idx = R->FUN_00266a30() - 0x10005;
        if (idx <= 0x17) {
            if (idx == 13 || idx == 15)
                flag = 1;
        }
        f.d.f0 = fc;
        f.d.f4 = flags;
        f.d.c8[3] = 0x20;
        f.d.c8[2] = 0x20;
        f.d.c8[1] = 0x20;
        f.d.c8[0] = 0x20;
        f.d.c8[4] = 0x20;
        f.d.c8[5] = 0x20;
        f.d.c8[6] = 0x20;
        f.d.f10 = f18;
        f.d.f14 = f1c;
        f.d.b19 = 0;
        f.d.f1c = 0;
        f.d.f20 = f20;
        f.d.b18 = flag;
        B = (*(Factory_2e30f0**)&DAT_0052c2a0)->f10(&f.d);
        if (B)
            ((Ref_2e30f0 *)B)->AddRef();
        if (obj->f58)
            obj->f58->Release();
        obj->f58 = (Ref_2e30f0 *)B;

        Maker_2e30f0 *mk = DAT_0052c2a8->g89(0x106);
        if (mk) {
            f.u12.hasPal = (a4 != 0);
            if (mk->m4(f8->f10, f.u12.hasPal)) {
                int r = mk->m2(f8->f10, fc, flags, 1, f.u12.y12);
                mk->m5(B, r);
            }
        }
    }

    for (;;) {
        unsigned int idx = R->FUN_00266c30() - 0x10005;
        if (idx <= 0x17) {
            switch (idx) {
            case 0:
                if (flags & 0x2000) {
                    R->stream->FUN_002647e0(&f.n112, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n112; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v180, 3, 4, 1);
                        l->a0(f.v180[0], f.v180[1], f.v180[2]);
                    }
                    B->b5(l);
                }
                break;
            case 1:
                if (flags & 0x10) {
                    R->stream->FUN_002647e0(&f.n68, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n68; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v204, 3, 4, 1);
                        l->a1(f.v204[0], f.v204[1], f.v204[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 2:
                if (flags & 0xf) {
                    unsigned int &A1 = *(unsigned int *)&f.d;
                    R->stream->FUN_002647e0(&A1, 1, 4, 1);
                    R->stream->FUN_002647e0(&f.u12.y12, 1, 4, 1);
                    if (f.u12.y12 < f.v64) {
                        AttrList *l = B->b4();
                        for (unsigned int i = A1; i > 0; i--) {
                            R->stream->FUN_002647e0(f.v160, 2, 4, 1);
                            l->a6(f.v160[0], f.v160[1], f.u12.y12);
                            l->a17();
                        }
                        B->b5(l);
                    }
                }
                break;
            case 3:
                if (flags & 0x20) {
                    R->stream->FUN_002647e0(&f.n88, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n88; i > 0; i--) {
                        R->stream->FUN_002647e0(&f.v36, 1, 4, 1);
                        l->a4(f.v36, 0);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 5: {
                R->stream->FUN_002647e0(&f.n40, 1, 4, 1);
                unsigned int n = f.n40;
                unsigned short *buf = (unsigned short *)FUN_00266e00(1, n * 2);
                for (unsigned int i = 0; i < n; i++) {
                    R->stream->FUN_002647e0(&f.v48, 1, 4, 1);
                    buf[i] = (unsigned short)f.v48;
                }
                B->b9(buf, n);
                FUN_00267090(buf);
                break;
            }
            case 6:
                if (flags & 0x80) {
                    R->stream->FUN_002647e0(&f.n64, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n64; i > 0; i--) {
                        R->stream->FUN_002647e0(&f.v20, 1, 4, 1);
                        l->a10((signed char)(f.v20 >> 24), (signed char)(f.v20 >> 16),
                               (signed char)(f.v20 >> 8), (signed char)f.v20);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 7:
                if (flags & 0x100) {
                    R->stream->FUN_002647e0(&f.n56, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n56; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v216, 3, 4, 1);
                        l->a11(f.v216[0], f.v216[1], f.v216[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 8:
                if (flags & 0x80) {
                    R->stream->FUN_002647e0(&f.n16, 1, 4, 1);
                    pure3d::MatrixPaletteList *mp;
                    void *mm = FUN_0008d690(0x14);
                    if (mm)
                        mp = new (mm) pure3d::MatrixPaletteList();
                    else
                        mp = 0;
                    f.u4.mp = mp;
                    f.zero72 = 0;
                    unsigned int cnt = f.n16;
                    mp->vec.FUN_002e16f0(cnt, &f.zero72);
                    for (unsigned int i = 0; i < f.n16; i++) {
                        R->stream->FUN_002647e0(&f.v80, 1, 4, 1);
                        mp->vec.data[i] = f.v80;
                    }
                    if (a4)
                        a4->AddRef();
                    if (f.pal->f60)
                        f.pal->f60->Release();
                    f.pal->f60 = a4;
                    if (f.u4.mp)
                        f.u4.mp->AddRef();
                    if (f.pal->f64)
                        f.pal->f64->Release();
                    f.pal->f64 = f.u4.mp;
                }
                break;
            case 13: {
                R->stream->FUN_002647e0(&f.c236, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c104, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c52, 1, 4, 1);
                B->b13(R->FUN_00266c30(), f.c104);
                unsigned int c3 = f.c52;
                int *lst = (int *)B->b11(c3);
                R->stream->FUN_002647e0(lst, c3, 1, 1);
                B->b12();
                break;
            }
            case 14: {
                R->stream->FUN_002647e0(&f.c232, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c116, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c60, 1, 4, 1);
                B->b13(R->FUN_00266c30(), f.c116);
                hulk_intptr r = B->b7();
                R->stream->FUN_002647e0((void *)r, f.c60, 1, 1);
                B->b8(f1c);
                break;
            }
            case 15: {
                R->stream->FUN_002647e0(&f.c228, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c84, 1, 4, 1);
                R->stream->FUN_002647e0(&f.c44, 1, 4, 1);
                B->b13(R->FUN_00266c30(), f.c84);
                unsigned int c3 = f.c44;
                int *lst = (int *)B->b11(c3);
                R->stream->FUN_002647e0(lst, c3, 1, 1);
                B->b12();
                break;
            }
            case 16:
                if (flags & 0x1000) {
                    R->stream->FUN_002647e0(&f.n76, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n76; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v192, 3, 4, 1);
                        l->a3(f.v192[0], f.v192[1], f.v192[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 17:
                if (flags & 0x800) {
                    R->stream->FUN_002647e0(&f.n108, 1, 4, 1);
                    AttrList *l = B->b4();
                    for (unsigned int i = f.n108; i > 0; i--) {
                        R->stream->FUN_002647e0(f.v168, 3, 4, 1);
                        l->a2(f.v168[0], f.v168[1], f.v168[2]);
                        l->a17();
                    }
                    B->b5(l);
                }
                break;
            case 23:
                if (flags & 0x4000) {
                    R->stream->FUN_002647e0(&f.x92, 1, 4, 1);
                    R->stream->FUN_002647e0(&f.y32, 1, 4, 1);
                    if (f.y32 < f.local20) {
                        AttrList *l = B->b4();
                        for (unsigned int i = f.x92; i > 0; i--) {
                            R->stream->FUN_002647e0(&f.v100, 1, 4, 1);
                            l->a4(f.v100, f.y32);
                            l->a17();
                        }
                        B->b5(l);
                    }
                }
                break;
            default:
                break;
            }
        }
        R->FUN_00266be0();
        if (!R->FUN_002669f0())
            break;
        R->FUN_00266a30();
    }
    B->b6();
}
} // namespace fn_002e30f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002e3bd0 FUN_002e3bd0 (1657 B): equivalent/0x002e3bd0.cpp [wrapped: using-directive]
// sym: ?FUN_002e3bd0@Loader@fn_002e3bd0@@QAEXTSlot1@2@TSlot2@2@HPAUPalSrc@2@@Z @40b947a5bd8f @w2d702a468345
namespace fn_002e3bd0 {
// STATUS: equivalent (tools/equiv.py level 3: 2765 inputs, branch coverage 118/118)
// FUN_002e3bd0 @ 0x002e3bd0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


void *thunk_FUN_0008d690(unsigned int size);
extern "C" void *FUN_0008d690(unsigned int size);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


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

struct Named {
    char pad00[0x10];
    int f10;
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct IntVec {
    unsigned int *begin;
    unsigned int *end;
    void FUN_002e16f0(unsigned int n, const unsigned int *def);
};

namespace pure3d {
class MatrixPaletteList {
public:
    virtual void AddRef_00018b30();
    virtual void Release_00018b40();
    int pad4;
    IntVec vec;
    MatrixPaletteList() { vec.begin = 0; vec.end = 0; }
};
}
using pure3d::MatrixPaletteList;

struct PalSrc : RefObj {
    char pad04[4];
    char *begin;
    char *end;
};

struct VData {
    char pad00[0xc];
    unsigned int f0c;
    char pad10[4];
    unsigned short *f14;
    char *f18;
    char *f1c;
    char *f20;
    char pad24[4];
    char *f28;
    char pad2c[4];
    char *f30;
    char pad34[4];
    char *tex[4];
    char *uv[4];
    char pad58[4];
};

struct DevObj {
    virtual void d0();
    virtual void d1();
    virtual int Make(int a, unsigned int b, unsigned int c, int d, int e);
    virtual void d3();
    virtual char Check(int a, int b);
};



class Gfx {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual DevObj *Get(int id);
};

class __declspec(novtable) PrimGroupStreamed_2e3bd0 {
public:
    virtual void v0_00038290();
    virtual void v1_000382a0();
    virtual void v2();
    virtual void v3_002df6e0();
    virtual void v4_002e0540();
    virtual void v5_002df6d0();
    virtual void v6_002df5a0();
    virtual void v7_002df520();
    virtual void SetName_002dfd70(Named *v);
    char pad04[0x40];
    unsigned int f44;
    char pad48[0x10];
    int f58;
    VData *vdata;
    PrimGroupStreamed_2e3bd0 *FUN_002e01d0(unsigned int a, unsigned int b, unsigned int c);
    PrimGroupStreamed_2e3bd0(unsigned int a, unsigned int b, unsigned int c) { FUN_002e01d0(a, b, c); }
};

namespace pure3d {
class PrimGroupSkinnedStreamed : public PrimGroupStreamed_2e3bd0 {
public:
    virtual void s0_002df530();
    RefObj *pal;
    MatrixPaletteList *list;
    PrimGroupSkinnedStreamed(unsigned int a, unsigned int b, unsigned int c) : PrimGroupStreamed_2e3bd0(a, b, c)
    {
        pal = 0;
        list = 0;
    }
};
}

union Slot1 {
    int a;
    unsigned int u;
};
union Slot2 {
    Stream *s;
    unsigned int n;
};

class Loader {
public:
    char pad00[8];
    Named *f08;
    unsigned int f0c;
    char pad10[4];
    unsigned int flags;
    unsigned int f18;
    unsigned int f1c;
    void FUN_002a46d0(Slot1 a1, PrimGroupStreamed_2e3bd0 *g);
    void FUN_002e3bd0(Slot1 a1, Slot2 a2, int a3, PalSrc *a4);
};

struct Frame {
    unsigned int vA;     // 0x10
    pure3d::PrimGroupSkinnedStreamed *obj; // 0x14
    MatrixPaletteList *list; // 0x18
    Loader *self;        // 0x1c
    unsigned int cntA;   // 0x20
    unsigned int cntB;   // 0x24
    unsigned int cnt1;   // 0x28
    unsigned int cnt2;   // 0x2c
    unsigned int cnt3;   // 0x30
    unsigned int cnt4;   // 0x34
    unsigned int cnt5;   // 0x38
    unsigned int idxA;   // 0x3c
    unsigned int idxB;   // 0x40
    unsigned int lim;    // 0x44
    unsigned int cnt6;   // 0x48
    unsigned int tmp16;  // 0x4c
    unsigned int cnt7;   // 0x50
    unsigned int cnt8;   // 0x54
    unsigned int def0;   // 0x58
    unsigned int tmpL;   // 0x5c
};

void Loader::FUN_002e3bd0(Slot1 a1, Slot2 a2, int a3, PalSrc *a4)
{
    Frame f;
    unsigned int fl = flags;
    f.self = this;
    if (fl & 0x20)
        f.vA = 1;
    else if (fl & 0x4000)
        f.vA = (fl >> 15) & 7;
    else
        f.vA = 0;
    f.lim = fl & 0xf;
    f.obj = 0;
    PrimGroupStreamed_2e3bd0 *g;
    if (a4 != 0 && (unsigned int)((a4->end - a4->begin) >> 6) > 0) {
        void *mem = thunk_FUN_0008d690(0x68);
        pure3d::PrimGroupSkinnedStreamed *sg = 0;
        if (mem != 0)
            sg = new (mem) pure3d::PrimGroupSkinnedStreamed(flags, f18, f1c);
        g = sg;
        f.obj = sg;
    } else {
        void *mem = thunk_FUN_0008d690(0x60);
        g = 0;
        if (mem != 0)
            g = ((PrimGroupStreamed_2e3bd0 *)mem)->FUN_002e01d0(flags, f18, f1c);
    }
    g->SetName_002dfd70(f08);
    g->f44 = f0c;
    FUN_002a46d0(a1, g);
    DevObj *dev = DAT_0052c2a8->Get(0x106);
    if (dev != 0) {
        if (dev->Check(f08->f10, 0))
            g->f58 = dev->Make(f08->f10, f0c, flags, 0, 0);
    }
    Stream *stream = a2.s;
    VData *vd = g->vdata;
    while (stream->FUN_002669f0()) {
        Loader *self = f.self;
        unsigned int id = stream->FUN_00266a30();
        switch (id) {
        case 0x10005:
            if (self->flags & 0x2000) {
                stream->reader->FUN_002647e0(&f.cnt1, 1, 4, 1);
                unsigned int n = f.cnt1;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f18 + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
                if (f.self->flags & 0x80) {
                    if (vd->f20 != 0)
                        memcpy(vd->f20, vd->f18, vd->f0c * 12);
                }
            }
            break;
        case 0x10006:
            if (self->flags & 0x10) {
                stream->reader->FUN_002647e0(&f.cnt2, 1, 4, 1);
                unsigned int n = f.cnt2;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f1c + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x10016:
            if (self->flags & 0x800) {
                stream->reader->FUN_002647e0(&f.cnt3, 1, 4, 1);
                unsigned int n = f.cnt3;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f28 + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x10015:
            if (self->flags & 0x1000) {
                stream->reader->FUN_002647e0(&f.cnt4, 1, 4, 1);
                unsigned int n = f.cnt4;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->f30 + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x10008:
            if (self->flags & 0x20) {
                stream->reader->FUN_002647e0(&f.cnt5, 1, 4, 1);
                unsigned int n = f.cnt5;
                unsigned int i = 0;
                if (n > 0) {
                    do {
                        stream->reader->FUN_002647e0(vd->uv[0] + i * 4, 1, 4, 1);
                        i++;
                    } while (i < n);
                }
            }
            break;
        case 0x1001c:
            if (self->flags & 0x4000) {
                stream->reader->FUN_002647e0(&f.cntA, 1, 4, 1);
                stream->reader->FUN_002647e0(&f.idxA, 1, 4, 1);
                unsigned int index = f.idxA;
                if (index < f.vA) {
                    unsigned int i = 0;
                    if (f.cntA > 0) {
                        do {
                            stream->reader->FUN_002647e0(vd->uv[index] + i * 4, 1, 4, 1);
                            i++;
                        } while (i < f.cntA);
                    }
                }
            }
            break;
        case 0x10007:
            if (self->flags & 0xf) {
                stream->reader->FUN_002647e0(&f.cntB, 1, 4, 1);
                stream->reader->FUN_002647e0(&f.idxB, 1, 4, 1);
                unsigned int index = f.idxB;
                if (index < f.lim) {
                    unsigned int i = 0;
                    if (f.cntB > 0) {
                        do {
                            stream->reader->FUN_002647e0(vd->tex[index] + i * 8, 2, 4, 1);
                            i++;
                        } while (i < f.cntB);
                    }
                }
            }
            break;
        case 0x1000a: {
            stream->reader->FUN_002647e0(&f.cnt6, 1, 4, 1);
            unsigned int n = f.cnt6;
            unsigned int i = 0;
            if (n > 0) {
                do {
                    stream->reader->FUN_002647e0(&f.tmp16, 1, 4, 1);
                    vd->f14[i] = (unsigned short)f.tmp16;
                    i++;
                } while (i < n);
            }
            if (vd->f20 != 0)
                memcpy(vd->f20, vd->f18, vd->f0c * 12);
            break;
        }
        case 0x1000c:
            if (self->flags & 0x100) {
                stream->reader->FUN_002647e0(&f.cnt7, 1, 4, 1);
                unsigned int n = f.cnt7;
                if (n > 0) {
                    unsigned int off = 0;
                    do {
                        stream->reader->FUN_002647e0(vd->uv[3] + off, 3, 4, 1);
                        off += 0xc;
                    } while (--n != 0);
                }
            }
            break;
        case 0x1000b:
            if (self->flags & 0x80) {
                stream->reader->FUN_002647e0(&f.cnt8, 1, 4, 1);
                unsigned int n = f.cnt8;
                unsigned int i = 0;
                if (n > 0) {
                    do {
                        stream->reader->FUN_002647e0(&a1.u, 1, 4, 1);
                        vd->uv[2][i * 4] = (char)(a1.u >> 24);
                        vd->uv[2][i * 4 + 1] = (char)(a1.u >> 16);
                        vd->uv[2][i * 4 + 2] = (char)(a1.u >> 8);
                        vd->uv[2][i * 4 + 3] = (char)a1.u;
                        i++;
                    } while (i < n);
                }
            }
            break;
        case 0x1000d:
            if (self->flags & 0x80) {
                stream->reader->FUN_002647e0(&a2.n, 1, 4, 1);
                void *m = FUN_0008d690(0x14);
                MatrixPaletteList *l = 0;
                if (m != 0)
                    l = new (m) MatrixPaletteList();
                f.list = l;
                IntVec *v = &l->vec;
                f.def0 = 0;
                v->FUN_002e16f0(a2.n, &f.def0);
                unsigned int i = 0;
                if (a2.n > 0) {
                    do {
                        stream->reader->FUN_002647e0(&f.tmpL, 1, 4, 1);
                        v->begin[i] = f.tmpL;
                        i++;
                    } while (i < a2.n);
                }
                RefObj *p = a4;
                if (p != 0)
                    p->AddRef();
                pure3d::PrimGroupSkinnedStreamed *sg = f.obj;
                if (sg->pal != 0)
                    sg->pal->Release();
                sg->pal = p;
                MatrixPaletteList *l2 = f.list;
                if (l2 != 0)
                    l2->AddRef_00018b30();
                if (sg->list != 0)
                    sg->list->Release_00018b40();
                sg->list = l2;
            }
            break;
        default:
            break;
        }
        stream->FUN_00266be0();
    }
}
} // namespace fn_002e3bd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fcb4ee90 {

// 0x002e49a0 FUN_002e49a0 (545 B): equivalent/0x002e49a0.cpp
// sym: ?FUN_002e49a0@ShaderLoader@fn_fcb4ee90@@QAEDPAUStream@2@PAVLoadContext_2e49a0@2@@Z @00bfc8c126b8 @w3f69425a3527
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 12/12)
// FUN_002e49a0 @ 0x002e49a0
char ShaderLoader::FUN_002e49a0(Stream *s, LoadContext_2e49a0 *ctx)
{
    Frame_2e49a0 f;
    if (s->FUN_00266c30() != 0x10020)
        return 0;

    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    f.name[f.len] = 0;

    if (shader) {
        shader->v1();
        shader = 0;
    }
    unsigned __int64 id = FUN_0027b020(f.name);
    content::LoadInventory::DynamicCaster<pure3d::Shader> *caster =
        new (&f.scratch) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    shader = ctx->lookup(caster, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found during primgroup load\n", f.name);
        void *mem = FUN_00263ea0(0x20);
        Shader_2e49a0 *err = 0;
        if (mem)
            err = static_cast<Shader_2e49a0 *>(mem)->FUN_0028edf0("error", 0);
        shader = err;
    }
    shader->v0();

    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word0c = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word1c = word18 & f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word20 = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word24 = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word28 = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    flag10 = f.scratch != 0;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    flag11 = f.scratch != 0;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    short12 = (unsigned short)f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word1c |= 0x2000;
    word14 = f.scratch;
    return 1;
}

} // namespace fn_fcb4ee90

// 0x002e4bd0 FUN_002e4bd0 (413 B): equivalent/0x002e4bd0.cpp [wrapped: conflict: ShaderLoader]
// sym: ?FUN_002e4bd0@ShaderLoader@fn_002e4bd0@@QAEDPAUStream@2@PAVLoadContext_2e4bd0@2@@Z @dc6d7427eb9e @wcabe63468199
namespace fn_002e4bd0 {
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 8/8)
// FUN_002e4bd0 @ 0x002e4bd0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" void __cdecl FUN_0028fcc0(const char *fmt, ...);


namespace pure3d { class Shader; }

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

class Shader_2e4bd0 {
public:
    virtual void v0();
    virtual void v1();
    Shader_2e4bd0 *FUN_0028edf0(const char *name, int flags);
};

class LoadContext_2e4bd0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Shader_2e4bd0 *lookup(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster,
                              unsigned __int64 id);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    int FUN_00266c30();
};

struct Frame_2e4bd0 {
    int scratch;             // 0x08
    char pad[3];
    unsigned char len;       // 0x0f
    char name[0x100];        // 0x10
};

class ShaderLoader {
public:
    char pad0[8];
    Shader_2e4bd0 *shader;       // 0x08
    int word0c;
    int mask;                // 0x10
    int word14;
    int word18;
    int word1c;
    int word20;
    int word24;
    char FUN_002e4bd0(Stream *s, LoadContext_2e4bd0 *ctx);
};

char ShaderLoader::FUN_002e4bd0(Stream *s, LoadContext_2e4bd0 *ctx)
{
    Frame_2e4bd0 f;
    if (s->FUN_00266c30() != 0x10002)
        return 0;

    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    f.name[f.len] = 0;

    if (shader) {
        shader->v1();
        shader = 0;
    }
    unsigned __int64 id = FUN_0027b020(f.name);
    // The original reuses the scratch slot for the caster object.
    content::LoadInventory::DynamicCaster<pure3d::Shader> *caster =
        new (&f.scratch) content::LoadInventory::DynamicCaster<pure3d::Shader>();
    shader = ctx->lookup(caster, id);
    if (shader == 0) {
        FUN_0028fcc0("warning : shader \"%s\" not found during primgroup load\n", f.name);
        void *mem = FUN_00263ea0(0x20);
        Shader_2e4bd0 *err = 0;
        if (mem)
            err = static_cast<Shader_2e4bd0 *>(mem)->FUN_0028edf0("error", 0);
        shader = err;
    }
    shader->v0();

    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word0c = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word14 = mask & f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word18 = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word1c = f.scratch;
    s->reader->FUN_002647e0(&f.scratch, 1, 4, 1);
    word20 = f.scratch;
    word14 |= 0x2000;
    return 1;
}
} // namespace fn_002e4bd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fcb4ee90 {

// 0x002e4d70 FUN_002e4d70 (144 B): equivalent/0x002e4d70.cpp
// sym: ?FUN_002e4d70@Dispatcher_2e4d70@fn_fcb4ee90@@QAEXHHHHDH@Z @319dae267db2 @w73359ff32803
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// FUN_002e4d70 @ 0x002e4d70
void Dispatcher_2e4d70::FUN_002e4d70(int a, int b, int c, int d, char direct, int e) {
    if (!FUN_002e49a0(b, c))
        return;
    if (enabled && direct && mode == 0)
        FUN_002e1960(a, b, c, d, e);
    else
        FUN_002e22c0(a, b, c, d, e);
    if (pending != 0) {
        pending->Release();
        pending = 0;
    }
}


// 0x002e4e00 FUN_002e4e00 (83 B): equivalent/0x002e4e00.cpp
// sym: ?FUN_002e4e00@Controller@fn_fcb4ee90@@QAEXHHHHD@Z @ebb791c67697 @wbf79a91a5c8d
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_002e4e00 @ 0x002e4e00
void Controller::FUN_002e4e00(int first, int second, int third, int fourth, char flag) {
    if (FUN_002e4bd0(second, third)) {
        if (flag) FUN_002e30f0(first, second, third, fourth);
        else FUN_002e3bd0(first, second, third, fourth);
        if (resource) {
            resource->release();
            resource = 0;
        }
    }
}


// 0x002e4e90 FUN_002e4e90 (3 B): matches/0x002e4e90.cpp
// sym: ?Self@LightGroup@pure3d@fn_fcb4ee90@@QAEPAV123@XZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
namespace pure3d {
LightGroup* LightGroup::Self() {
    return this;
}
}


// 0x002e4ea0 FUN_002e4ea0 (1 B): matches/0x002e4ea0.cpp
// sym: ?FUN_002e4ea0@fn_fcb4ee90@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002e4ea0() {}


// 0x002e4fb0 FUN_002e4fb0 (15 B): matches/0x002e4fb0.cpp
// sym: ?target@Obj_2e4fb0@fn_fcb4ee90@@QAEPAU12@XZ
// Same code shape as 0x001c65a0 (propagated; names are from that function)
Obj_2e4fb0* Obj_2e4fb0::target() {
    ((Inner_2e4fb0*)((char*)this + 4))->sub_002c6d30();
    return this;
}


// 0x002e5280 FUN_002e5280 (33 B): matches/0x002e5280.cpp
// sym: ?Run@Thing_2e5280@fn_fcb4ee90@@QAEPAV12@E@Z
// Same code shape as 0x001c6c40 (propagated; names are from that function)
Thing_2e5280* Thing_2e5280::Run(unsigned char flags) {
    part.Cleanup_002c6d50();
    if (flags & 1)
        DeleteThing_0008d330(this);
    return this;
}


// 0x002e5310 FUN_002e5310 (24 B): matches/0x002e5310.cpp
// sym: ?clear@Owner_2e5310@fn_fcb4ee90@@QAEXXZ
void Owner_2e5310::clear() {
    if (member) {
        member->B();
        member = 0;
    }
}

} // namespace fn_fcb4ee90
