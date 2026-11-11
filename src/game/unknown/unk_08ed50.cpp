// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ed50..0x0008ff70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff1b4d41 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff1b4d41 {} using namespace fn_ff1b4d41;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_ff1b4d41 {
class pure3d_d3dToon2VertexShader_8ed50 {
  public:
    virtual void vfunc_0();
    virtual bool IsEnabled();
};
struct Stream {
    virtual void reset(int);
    virtual void flush();
    unsigned stride;
    unsigned char* current;
    unsigned char* auxiliary1;
    unsigned char* auxiliary2;
    unsigned char* auxiliary3;
    unsigned limit;
    unsigned index;
    int retained;
    unsigned char buffer[1];
    void FUN_0008ef00();
};
typedef unsigned int u32_8ef90;
} // namespace fn_ff1b4d41
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif
namespace fn_ff1b4d41 {
class Hash {
  public:
    hulk_intptr Calc(const char* s);
};
extern "C" void* __cdecl FUN_0008d6d0(int size);
class IntArray_8f0b0 {
public:
    int mA;
    int mOne;
    int mZero8;
    int mCount;
    int mZero10;
    int mB;
    int pad18;
    int pad1c;
    int* mData;
    IntArray_8f0b0(int count, int b, int a);
};
struct Obj_8f140 {
    char pad[0x20];
    int value;
};
struct Target_8f160 {
    char pad[0x18];
    long long value;
};
extern "C" long long __cdecl FUN_00267f40();
struct Context { char pad[16]; int handle; };
struct Vertex_8f3a0 { volatile float x,y,z; };
struct Buffer_8f3a0 { char pad[8]; Vertex_8f3a0* volatile vertex; int unused; unsigned int* volatile color; void FUN_0008ef00(); };
} // namespace fn_ff1b4d41
struct Gfx {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual Buffer_8f3a0* begin(int handle,int type,int flags,int count,int zero);
 virtual void end(Buffer_8f3a0* buffer);
};
namespace fn_ff1b4d41 {
struct Plot {
 unsigned int color; int head,tail,count,ticks; char pad[12]; float* values;
 Context* FUN_00085cd0();
 void target();
};
} // namespace fn_ff1b4d41
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *d, const void *s, unsigned int n);
#endif
namespace fn_ff1b4d41 {
extern double __cdecl FUN_003458c1(const char *s);
} // namespace fn_ff1b4d41
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned);
#endif
namespace fn_ff1b4d41 {
extern "C" int FUN_00266da0(int);
extern "C" void* FUN_0008d690(hulk_uintptr);
class CStaticAllocator {
  public:
    virtual void f0();
    CStaticAllocator(unsigned a, unsigned b, int c, int d);
    unsigned mA, mB;
    int mC;
    void* mData;
    void* mBits;
    int mZ;
};


// 0x0008ed50 FUN_0008ed50 (3 B): matches/0x0008ed50.cpp
// sym: ?IsEnabled@pure3d_d3dToon2VertexShader_8ed50@fn_ff1b4d41@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d_d3dToon2VertexShader_8ed50::IsEnabled() {
    return true;
}


// 0x0008ef00 FUN_0008ef00 (131 B): equivalent/0x0008ef00.cpp
// sym: ?FUN_0008ef00@Stream@fn_ff1b4d41@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 10/10)
// FUN_0008ef00 @ 0x0008ef00
void Stream::FUN_0008ef00() {
    ++index;
    if (index != limit) {
        unsigned step = stride;
        current += step;
        if (auxiliary1) auxiliary1 += step;
        if (auxiliary2) auxiliary2 += step;
        if (auxiliary3) auxiliary3 += step;
        return;
    }
    if (retained > 0) {
        unsigned bytes = stride * (unsigned)retained;
        unsigned char* source = current - stride * ((unsigned)retained - 1);
        unsigned char* dest = buffer;
        for (unsigned words = bytes >> 2; words; --words) {
            *(unsigned*)dest = *(unsigned*)source;
            dest += 4;
            source += 4;
        }
        for (unsigned tail = bytes & 3; tail; --tail) {
            *dest++ = *source++;
        }
    }
    flush();
    reset(1);
}

} // namespace fn_ff1b4d41

// 0x0008ef90 FUN_0008ef90 (42 B): matches/0x0008ef90.cpp
// sym: ?FUN_0008ef90@Obj_8ef90@owners@@QAEXPAII@Z
void owners::Obj_8ef90::FUN_0008ef90(u32_8ef90* src, u32_8ef90 val) {
    u32_8ef90* d = a;
    u32_8ef90* s = src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    u32_8ef90* q = b;
    *q = val;
    CopyTail();
}

namespace fn_ff1b4d41 {

// 0x0008f060 FUN_0008f060 (73 B): matches/0x0008f060.cpp
// sym: ?Calc@Hash@fn_ff1b4d41@@QAEHPBD@Z
hulk_intptr Hash::Calc(const char* s) {
    hulk_intptr n = strlen(s);
    hulk_intptr sum = n;
    int product = 1;
    for (int i = 0; i < n; ++i) {
        int v = (signed char)s[i];
        sum += v;
        product *= v;
    }
    return sum + product;
}


// 0x0008f0b0 FUN_0008f0b0 (131 B): equivalent/0x0008f0b0.cpp
// sym: ??0IntArray_8f0b0@fn_ff1b4d41@@QAE@HHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 288 inputs, branch coverage 8/8)
// FUN_0008f0b0 @ 0x0008f0b0
IntArray_8f0b0::IntArray_8f0b0(int count, int b, int a)
{
    mCount = count;
    mB = b;
    mA = a;
    mOne = 1;
    mZero8 = 0;
    mZero10 = 0;
    mData = (int*)FUN_0008d6d0(count * 4);
    for (int i = 0; i < count; i++)
        mData[i] = 0;
}


// 0x0008f140 FUN_0008f140 (24 B): matches/0x0008f140.cpp
// sym: ?target@fn_ff1b4d41@@YIXPAUObj_8f140@1@@Z
void __fastcall target(Obj_8f140* self) {
    thunk(self->value);
    self->value = 0;
}


// 0x0008f160 FUN_0008f160 (16 B): matches/0x0008f160.cpp
// sym: ?FUN_0008f160@fn_ff1b4d41@@YIXPAUTarget_8f160@1@@Z
void __fastcall FUN_0008f160(Target_8f160* self) {
    self->value = FUN_00267f40();
}


// 0x0008f3a0 FUN_0008f3a0 (275 B): equivalent/0x0008f3a0.cpp
// sym: ?target@Plot@fn_ff1b4d41@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 6/6)
// FUN_0008f3a0 @ 0x0008f3a0
void Plot::target() {
 ++ticks;
 Context* context=FUN_00085cd0();
 int n=count;
 Buffer_8f3a0* buffer=DAT_0052c2a8->begin(context->handle,3,0x2020,n,0);
 int start=head;
 if(n>0) {
 volatile float denominator=(float)n;
 for(int i=0;i<n;++i) {
 volatile float height=1.0f-values[(start+i)%count]*0.0000199998794f;
 if(height>1.1f) height=1.1f;
 unsigned int c=color;
 Vertex_8f3a0* v=buffer->vertex;
 v->z=1.0f;
 v->x=((float)i/denominator)*500.0f+70.0f;
 v->y=height*184.0f+20.0f;
 *buffer->color=c;
 buffer->FUN_0008ef00();
 }
 }
 DAT_0052c2a8->end(buffer);
 int divisor=count;
 head=(head+1)%divisor;
 tail=(tail+1)%divisor;
 values[tail]=0.0f;
}

} // namespace fn_ff1b4d41

// 0x0008f4c0 FUN_0008f4c0 (959 B): equivalent/0x0008f4c0.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_0008f4c0@DebugOverlay@fn_0008f4c0@@QAEXXZ
namespace fn_0008f4c0 {
// STATUS: equivalent (tools/equiv.py level 3: 581 inputs, branch coverage 10/10)
// FUN_0008f4c0 @ 0x0008f4c0
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

struct Vertex_8f4c0 {
    float x, y, z;
};

struct Mesh_8f4c0 {
    char pad00[8];
    Vertex_8f4c0* vert;
    char pad0c[4];
    unsigned int* color;
    void FUN_0008ef00();
};

class Res_8f4c0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int tag, int flag);
};

struct Gfx_8f4c0 {
    char pad00[0x10];
    Res_8f4c0* res;
};

class Gfx {
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
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(int v);
    virtual int vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual Mesh_8f4c0* vfunc_30(Res_8f4c0* res, int a, int b, int c, int d);
    virtual void vfunc_31(Mesh_8f4c0* m);
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54(unsigned int v);
    virtual int vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58(unsigned int v);
    virtual char vfunc_59();
};

class Holder_8f4c0 {
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
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(int v);
    virtual void vfunc_14();
    virtual void vfunc_15(int v);
    virtual void vfunc_16(int v);
};

struct Label_8f4c0 {
    void FUN_0008f3a0();
};

struct Overlay {
    char pad00[4];
    int count;
    Label_8f4c0* items[1];
};

extern "C" Gfx_8f4c0* FUN_00085cd0();
extern "C" void FUN_00085d30();

struct Frame_8f4c0 {
    union {
        int i;
        float y;
    } tmp;
    Overlay* self;
    int save1;
    union {
        char b;
        unsigned int w;
    } save2;
    int save3;
};

class DebugOverlay : public Overlay {
public:
    void FUN_0008f4c0();
};

void DebugOverlay::FUN_0008f4c0()
{
    Frame_8f4c0 f;
    f.self = this;
    if (!FUN_00085cd0())
        FUN_00085d30();
    f.save1 = DAT_0052c2a8->vfunc_25();
    f.save2.b = DAT_0052c2a8->vfunc_59();
    f.save3 = DAT_0052c2a8->vfunc_55();
    DAT_0052c2a8->vfunc_24(2);
    DAT_0052c2a8->vfunc_58(0);
    DAT_0052c2a8->vfunc_54(0);
    (*(*(Holder_8f4c0***)&DAT_0052c2ac))->vfunc_15(0);
    (*(*(Holder_8f4c0***)&DAT_0052c2ac))->vfunc_13(0);

    Gfx_8f4c0* gfx = FUN_00085cd0();
    gfx->res->vfunc_6(0x444d4c42, 1);

    Mesh_8f4c0* m = DAT_0052c2a8->vfunc_30(gfx->res, 1, 0x2020, 4, 0);
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 70.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 570.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 70.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 570.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    m = DAT_0052c2a8->vfunc_30(gfx->res, 3, 0x2020, 5, 0);
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 70.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 570.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 570.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 70.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex_8f4c0* v = m->vert;
        v->x = 70.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    m = DAT_0052c2a8->vfunc_30(gfx->res, 2, 0x2020, 0x14, 0);
    for (int i = 1; i <= 10; i++) {
        Vertex_8f4c0* v = m->vert;
        f.tmp.i = i;
        v->x = 70.0f;
        v->z = 1.0f;
        f.tmp.y = 204.0f - (float)f.tmp.i * 18.4f;
        v->y = f.tmp.y;
        *m->color = 0x40000000;
        m->FUN_0008ef00();
        v = m->vert;
        v->y = f.tmp.y;
        v->x = 570.0f;
        v->z = 1.0f;
        *m->color = 0x40000000;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    m = DAT_0052c2a8->vfunc_30(gfx->res, 2, 0x2020, 0xa, 0);
    for (int i = 1; i <= 5; i++) {
        Vertex_8f4c0* v = m->vert;
        f.tmp.i = i;
        v->x = 70.0f;
        v->z = 1.0f;
        f.tmp.y = 204.0f - (float)f.tmp.i * 36.8f;
        v->y = f.tmp.y;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
        v = m->vert;
        v->y = f.tmp.y;
        v->x = 570.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    Overlay* ov = f.self;
    for (int i = 0; i < ov->count; i++)
        ov->items[i]->FUN_0008f3a0();

    DAT_0052c2a8->vfunc_24(f.save1);
    DAT_0052c2a8->vfunc_58(f.save2.w);
    DAT_0052c2a8->vfunc_54(f.save3);
    (*(*(Holder_8f4c0***)&DAT_0052c2ac))->vfunc_16(0);
}
} // namespace fn_0008f4c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff1b4d41 {

// 0x0008f880 FUN_0008f880 (1020 B): matches/0x0008f880.cpp
// sym: _FUN_0008f880
// FUN_0008f880 @ 0x0008f880
extern "C" void FUN_0008f880(int argc, char **argv)
{
    int i;
    for (i = 1; i < argc; i++) {
        const char *arg = argv[i];
        if (strcmp(arg, "-nocd") == 0) {
            (*(char*)&DAT_0049caac) = 0;
        } else if (strcmp(arg, "-level") == 0) {
            i++;
            (*(char*)&DAT_004de950) = 1;
            (*(char*)&DAT_004dd8d0) = 1;
            if (i < argc) {
                const char *s = argv[i];
                char *d = ((char*)&DAT_004dd890);
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c != 0);
            }
        } else if (strcmp(arg, "-firewire") == 0) {
            (*(char*)&DAT_004dd83f) = 1;
        } else if (strcmp(arg, "-displaymemoryusage") == 0) {
            DAT_004dd83e = 1;
        } else if (strcmp(arg, "-nosound") == 0) {
        } else if (strcmp(arg, "-english") == 0) {
            memcpy(DAT_0049caa4, "english", 8);
        } else if (strcmp(arg, "-italian") == 0) {
            memcpy(DAT_0049caa4, "italian", 8);
        } else if (strcmp(arg, "-french") == 0) {
            memcpy(DAT_0049caa4, "french", 7);
        } else if (strcmp(arg, "-fakexp") == 0) {
            DAT_004dd838 = 1;
        } else if (strcmp(arg, "-savemissionstats") == 0) {
            (*(char*)&DAT_0049caad) = 1;
        } else if (strcmp(arg, "-pal") == 0) {
            DAT_004dd839 = 1;
        } else if (strcmp(arg, "-drawcode") == 0) {
            DAT_004dd8e7 = 1;
        } else if (strcmp(arg, "-lang") == 0) {
            i++;
            if (i < argc) {
                const char *s = argv[i];
                char *d = ((char*)&DAT_004dd8d4);
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c != 0);
            }
        } else if (strcmp(arg, "-fmvvol") == 0) {
            i++;
            if (i < argc) {
                DAT_0049cab0 = (float)FUN_003458c1(argv[i]);
            }
        } else if (strcmp(arg, "-difficulty") == 0) {
            i++;
            if (i < argc) {
                (*(long*)&DAT_0049cab4) = atol(argv[i]);
            }
        } else if (strcmp(arg, "-lighthack") == 0) {
            DAT_004dd8e5 = 1;
        } else if (strcmp(arg, "-autotester") == 0) {
            i++;
            (*(char*)&DAT_004dd841) = 1;
            if (i < argc) {
                const char *s = argv[i];
                char *d = ((char*)&DAT_004dd848);
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c != 0);
            }
        } else if (strcmp(arg, "-nofilenotfound") == 0) {
            DAT_004dd8e6 = 1;
        } else if (strcmp(arg, "-caminvertx") == 0) {
            DAT_004dd83a = 1;
        } else if (strcmp(arg, "-caminverty") == 0) {
            DAT_004dd83b = 1;
        } else if (strcmp(arg, "-caminvert1x") == 0) {
            DAT_004dd83c = 1;
        } else if (strcmp(arg, "-caminvert1y") == 0) {
            DAT_004dd83d = 1;
        } else if (strcmp(arg, "-notintextbible") == 0) {
            (*(char*)&DAT_004dd8e8) = ((*(char*)&DAT_004dd8e8) == 0);
        } else if (strcmp(arg, "-nodpad") == 0) {
            (*(char*)&DAT_0049caae) = 1;
        } else if (strcmp(arg, "-notargeticon") == 0) {
            (*(char*)&DAT_004dd888) = 1;
        } else if (strcmp(arg, "-framerateicon") == 0) {
            (*(char*)&DAT_004dd8e4) = 1;
        }
    }
}


// 0x0008fde0 FUN_0008fde0 (164 B): matches/0x0008fde0.cpp
// sym: ??0CStaticAllocator@fn_ff1b4d41@@QAE@IIHH@Z
CStaticAllocator::CStaticAllocator(unsigned a, unsigned b, int c, int d) {
    mA = a;
    mB = b;
    mC = d;
    mZ = 0;
    int h = FUN_00266da0(c);
    unsigned n = mB * mA;
    mData = FUN_0008d690(n);
    memset(mData, 0xbb, n);
    unsigned w = (mB >> 5) + ((mB & 31) != 0);
    mBits = FUN_0008d690(w * 4);
    memset(mBits, 0, w * 4);
    FUN_00266da0(h);
}

} // namespace fn_ff1b4d41

// 0x0008fe90 FUN_0008fe90 (109 B): equivalent/0x0008fe90.cpp
// sym: ?FUN_0008fe90@BitPool_8fe90@owners@@QAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0008fe90 @ 0x0008fe90
hulk_intptr owners::BitPool_8fe90::FUN_0008fe90(int unused)
{
    unsigned int index = cursor;
    unsigned int mask = 1u << (index & 0x1f);
    unsigned int word = index >> 5;
    if (index < count) {
        unsigned int *p = bitmap + word;
        do {
            if ((*p & mask) == 0) {
                p = bitmap + word;
                *p |= mask;
                int taken = cursor;
                cursor = taken + 1;
                return elemSize * taken + base;
            }
            cursor = cursor + 1;
            if ((int)mask < 0) {
                word++;
                p++;
                mask = 1;
            } else {
                mask <<= 1;
            }
        } while (cursor < count);
    }
    return 0;
}


// 0x0008ff00 FUN_0008ff00 (60 B): matches/0x0008ff00.cpp
// sym: ?FUN_0008ff00@Thing_8ff00@owners@@QAEXHH@Z
void owners::Thing_8ff00::FUN_0008ff00(hulk_intptr value, int unused) {
    unsigned int index = (((int)value) - base) / divisor;
    bits[index >> 5] &= ~(1u << (index & 31));
    if (index < limit)
        limit = index;
}


// 0x0008ff50 FUN_0008ff50 (32 B): matches/0x0008ff50.cpp [wrapped: conflict: CStaticAllocator]
// sym: ?Reset@CStaticAllocator@fn_0008ff50@@QAEXXZ
namespace fn_0008ff50 {
extern "C" char DAT_00400c1c[];
struct CStaticAllocator {
    void* vf;
    char pad[0xC];
    int m10;
    int m14;
    void Reset();
};
void thunk_FUN_00267090(hulk_intptr);
void CStaticAllocator::Reset() {
    vf = (void*)((hulk_intptr)DAT_00400c1c);
    thunk_FUN_00267090(m14);
    thunk_FUN_00267090(m10);
}
} // namespace fn_0008ff50

