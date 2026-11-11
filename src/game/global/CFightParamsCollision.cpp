// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00059260..0x0005a4c0 (kind game, layer game, confidence high), dominant class CFightParamsCollision
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8b0a0f7 {
#define TREE_TU_END }
namespace fn_f8b0a0f7 {} using namespace fn_f8b0a0f7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8b0a0f7 {
class Obj_59300 {
  public:
    virtual void a();
    virtual void Release();
};
class X_59300 {
  public:
    char p0[0x4c];
    Obj_59300* m4c;
    Obj_59300* m50;
    char p1[0xc];
    Obj_59300* m60;
    char p1b[8];
    Obj_59300* m6c;
    Obj_59300* m70;
    char p2[0x10];
    Obj_59300* m84;
    void F();
};
class RefCounted_59370 {
public:
    virtual void addRef();
    virtual void release();
};
struct Slots_59370 {
    int f00;  // 0x0
    int f04;  // 0x4
    int f08;  // 0x8
    int f0c;  // 0xc
    int f10;  // 0x10
    char b14;  // 0x14
    char skip15[0x3];
    int f18;  // 0x18
    int f1c;  // 0x1c
    int f20;  // 0x20
    char b24;  // 0x24
    char skip25[0x3];
    int f28;  // 0x28
    int f2c;  // 0x2c
    int f30;  // 0x30
    char b34;  // 0x34
    char skip35[0x3];
    int f38;  // 0x38
    int f3c;  // 0x3c
    int f40;  // 0x40
    char b44;  // 0x44
    char skip45[0x3];
    int f48;  // 0x48
    RefCounted_59370 * r4c;  // 0x4c
    RefCounted_59370 * r50;  // 0x50
    int f54;  // 0x54
    int f58;  // 0x58
    int f5c;  // 0x5c
    RefCounted_59370 * r60;  // 0x60
    int f64;  // 0x64
    int f68;  // 0x68
    RefCounted_59370 * r6c;  // 0x6c
    RefCounted_59370 * r70;  // 0x70
    int f74;  // 0x74
    int f78;  // 0x78
    int f7c;  // 0x7c
    int f80;  // 0x80
    RefCounted_59370 * r84;  // 0x84
    int f88;  // 0x88
    int f8c;  // 0x8c
    char b90;  // 0x90
    char b91;  // 0x91
    char tail[2];
    Slots_59370 *FUN_00059370(const Slots_59370 *other);
};
struct Resource_59510 {
 virtual void unused();
 virtual void release();
};
struct State_59510 {
 unsigned field00, field04;
 unsigned position[3];
 unsigned char flag14; char pad15[3];
 unsigned vector18[3];
 unsigned char enabled; char pad25[3];
 unsigned vector28[3];
 unsigned char flag34; char pad35[3];
 unsigned vector38[3];
 unsigned char flag44; char pad45[7];
 Resource_59510 *resource4c, *resource50;
 unsigned field54, field58, field5c;
 Resource_59510 *resource60;
 unsigned field64, field68;
 Resource_59510 *resource6c, *resource70;
 unsigned field74, field78, field7c, field80;
 Resource_59510 *resource84;
 unsigned field88, field8c;
 unsigned char flag90, flag91;
 void FUN_00059510();
};
struct Vec_595f0 { float x,y,z; };
} // namespace fn_f8b0a0f7
struct World { char pad[16]; Vec_595f0 value; };
namespace fn_f8b0a0f7 {
struct Obj_595f0 { char pad[0x28]; Vec_595f0 velocity; char pad2[0x28]; float duration; char pad3[4]; float acceleration;
void FUN_000595f0(const Vec_595f0* v, float scale, float time, float height);
};
extern void* hulk_at_003f9844[];
class Ref_59720 {
  public:
    virtual void F0();
    virtual void Release();
};
class Params_59720 {
  public:
    void* vptr;
    void Fin_00236a50();
};
class CFightParams_59720 : public Params_59720 {
  public:
    char pad[0xc - 4];
    Ref_59720* mc;
    Ref_59720* m10;
    ~CFightParams_59720();
};
class Ref_59760 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_59760 {
  public:
    char pad[12];
    Ref_59760* value;
    void Set(Ref_59760* p);
};
class Item_59790 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_59790 {
  public:
    char pad[0x10];
    Item_59790* item;
    void Set(Item_59790* p);
};
extern void* hulk_at_003f985c[];
extern void* gB_597c0[];
class Ref_597c0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct S_597c0 {
    int a;
    void Fini_00059300();
};
class CFightParams_597c0 {
  public:
    void* vptr;
    void Fin_00236a50();
};
class CFightParamsCollision_597c0 : public CFightParams_597c0 {
  public:
    char pad[0xc - 4];
    Ref_597c0* mc;
    Ref_597c0* m10;
    char pad2[4];
    S_597c0 s18;
    ~CFightParamsCollision_597c0();
};
struct ThisCall_00059510 {
    void Init_00059510();
};
class Obj_59820 {
  public:
    char pad[0x48];
    int id;
    int a4c;
    int a50;
    char gap[0x0c];
    int a60;
    char gap2[8];
    int a6c;
    int a70;
    char gap3[0x10];
    int a84;
};
class Obj_59a30 {
    char pad[0x10];

  public:
    unsigned int value;
};
struct Data_59a50 {
    char pad[0x40];
    unsigned a, b, c;
};
struct Out_59a50 {
    unsigned a, b, c;
};
class Obj_59a50 {
  public:
    char pad[4];
    unsigned a;
    unsigned b;
    unsigned c;
    char pad2[8];
    Data_59a50* p;
    bool Get(Out_59a50* out);
};
struct Src_59a90 {
    int a, b, c;
};
class Obj_59a90 {
  public:
    virtual ~Obj_59a90() {}
    int a, b, c;
    char Set(Src_59a90* src);
};
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
struct Entry_59ad0 {
    int f00, f04, f08, f0c, f10, f14, f18;
    int f1c, f20;
};
class EntryPool {
public:
    int f00;
    unsigned int count;
    Entry_59ad0 *entries;
    unsigned char *flags;
    EntryPool *FUN_00059ad0();
};
struct Entry {
    int id;
    char pad[32];
};
class Pool {
  public:
    int count;
    unsigned capacity;
    Entry* entries;
    char* used;
    hulk_intptr Allocate();
};
struct Item_59ba0 {
    int key;
    char pad[0x20];
};
class C_59ba0 {
  public:
    char pad0[4];
    unsigned int count;
    Item_59ba0* items;
    char* flags;
    Item_59ba0* Find(int key);
};
typedef unsigned int u32_59bf0;
struct Obj_59bf0 {
    char pad[0x18];
    u32_59bf0 value;
};
struct ThisWrap_00059bf0 {
    Obj_59bf0* FUN_00059ba0(u32_59bf0);
    hulk_uintptr FUN_00059bf0(u32_59bf0 param);
};
class Item_59c80 {
  public:
    virtual void F0();
    virtual void F1();
    void second_00222b90(int);
};
class A_59c80 {
  public:
    void first_0003b620(int);
    void second_00263e90();
};
class C_59c80 {
  public:
    char pad[0x10];
    A_59c80* a;
    char pad2[4];
    Item_59c80* b;
    void run();
};
class Item_59cd0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_59cd0 {
  public:
    char pad[0x10];
    Item_59cd0* item;
    void Set(Item_59cd0* p);
};
class Item_59d00 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_59d00 {
    char pad[0x18];

  public:
    Item_59d00* item;
    void Set(Item_59d00* p);
};
struct Buffer_59d30 {
    void FUN_0003b620(int arg);
    void FUN_00263e90();
};
class Resource_59d30 {
public:
    virtual void v0();
    virtual void Release();
    void FUN_00222b90(int arg);
};
struct Entry_59d30 {
    char pad0[0x10];
    Buffer_59d30 *buffer;
    char pad14[4];
    Resource_59d30 *resource;
    char pad1c[0x24 - 0x1c];
};
class EntryTable_59d30 {
public:
    void FUN_00059d30();

    char pad0[4];
    unsigned int count;
    Entry_59d30 *entries;
    char *used;
};
struct Effect_59e50 {
    void FUN_00222b90(int arg);
    virtual void vfunc_0();
    virtual void vfunc_1();     // release
};
struct Buffer_59e50 {
    void FUN_0003b620(int arg);
    void FUN_00263e90();
};
struct Entry_59e50 {
    void *key;              // 0x00
    char pad04[0xc];
    Buffer_59e50 *buffer;         // 0x10
    char pad14[4];
    Effect_59e50 *effect;         // 0x18
    char pad1c[8];
};
class EntryTable_59e50 {
public:
    char pad00[4];
    unsigned int count;     // 4
    Entry_59e50 *entries;         // 8
    char *used;             // 0xc
    void FUN_00059e50(void *key);
};
class Item_59ee0 {
  public:
    virtual void F0();
    virtual void F1();
    void second_00222b90(int);
};
class A_59ee0 {
  public:
    void first_0003b620(int);
    void second_00263e90();
};
class C_59ee0 {
  public:
    char pad[0x10];
    A_59ee0* a;
    char pad2[4];
    Item_59ee0* b;
    void run();
};
struct Resource_59f30 { void FUN_0003b620(int); void FUN_00263e90(); };
struct Object { virtual void slot0(); virtual void slot1(); void FUN_00222b90(int); };
struct Item_59f30 { char pad[16]; Resource_59f30* resource; int unused; Object* object; char tail[8]; void* FUN_00059f30(unsigned char flags); };
struct Inner_5a010 {
    void Fnf_00059f30(int);
};
struct Obj_5a010 {
    char pad[8];
    Inner_5a010* a;
    int b;
};
extern void __fastcall FUN_00059d30(Obj_5a010*);
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
struct V {
    int a;
    int b;
    int c;
};
class O_5a140 {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    char Set(V* v);
};
struct Vec3 {
    float x, y, z;
};
class Obj {
  public:
    virtual void First();
    virtual void Second();
    char _m_pad_4[0x30];
    float x;
    float y;
    float z;
    unsigned char FUN_0005a180(const Vec3* v);
};
struct Holder {
    Obj* mOld;
};
struct Vec3_5a1b0 {
    int x;
    int y;
    int z;
};
class Obj_5a1b0 {
  public:
    char pad[0x48];
    int m48;
    int m4c;
    int m50;
    bool Set(const Vec3_5a1b0* v);
};
struct S_5a240 {
    int a, b, c;
};
class C_5a240 {
  public:
    char pad[0x24];
    S_5a240 s;
    bool Set(const S_5a240* o);
};
struct S_5a330 {
    char pad[0xc];
    int value;
};
struct O_5a330 {
    char pad[0xc];
    S_5a330* Get();
};
class Obj_5a340 {
  public:
    char pad[0x18];
    int m18;
    bool SetFlag(int value);
};
class Obj_5a350 {
  public:
    char pad[0x1c];
    void* Get();
};
struct S_5a390 {
    int a;
    int b;
    int c;
};
class O_5a390 {
  public:
    char pad[0x20];
    int x;
    int y;
    int z;
    bool Set(S_5a390* p);
};
class X_5a3f0 {
  public:
};
class Y_5a3f0 {
  public:
    int FnB_00059a30();
};
struct Result { char pad[0x330]; void* fallback; void* preferred; };
struct Middle { Result* FUN_00059a30(); };
struct Leaf {
    char pad[0x104];
    int value;
};
struct Mid {
    char pad[0x330];
    Leaf* first;
    Leaf* second;
    inline Leaf* select() {
        if (second)
            return second;
        Leaf* p = first;
        if (!p)
            return 0;
        return p;
    }
};
class B {
  public:
    Mid* get_00059a30();
};
class A {
  public:
    B* get_000592a0();
};

} // namespace fn_f8b0a0f7

// 0x00059260 FUN_00059260 (35 B): matches/0x00059260.cpp [wrapped: conflict: CFightParams]
// sym: ?Init@CFightParams@fn_00059260@@QAEPAV12@H@Z
namespace fn_00059260 {
class CFightParams {
  public:
    virtual void V();
    int pad;
    int value;
    int x;
    int y;
    CFightParams* Init(int);
};
struct ThisCall_00236a60 {
    void BaseInit_00236a60();
};
extern "C++" { extern int fightvftable; }
CFightParams* CFightParams::Init(int v) {
    ((ThisCall_00236a60*)(this))->BaseInit_00236a60();
    value = v;
    x = 0;
    y = 0;
    *(hulk_intptr*)this = (hulk_intptr)&fightvftable;
    return this;
}
} // namespace fn_00059260

namespace fn_f8b0a0f7 {

// 0x00059290 CFightParams::vfunc_3 (3 B): matches/0x00059290.cpp
// sym: ?GetZero@fn_f8b0a0f7@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f8b0a0f7

// 0x000592c0 CFightParams::vfunc_4 (63 B): matches/0x000592c0.cpp [wrapped: conflict: CFightParams]
// sym: ?vfunc_4@CFightParams@fn_000592c0@@UAEPAV12@XZ
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_000592c0 {
extern void* Alloc_0008d690(hulk_uintptr);

class Params_592c0 {
  public:
    virtual void b0_00018b30();
    Params_592c0();
};
class CFightParams : public Params_592c0 {
  public:
    CFightParams(int x) : Params_592c0() {
        field8 = x;
        fieldc = 0;
        field10 = 0;
    }
    virtual void v1_00018b40();
    virtual void* v2_00059890(char);
    virtual void v3();
    virtual CFightParams* vfunc_4();
    int pad4;
    int field8;
    int fieldc;
    int field10;
};
CFightParams* CFightParams::vfunc_4() {
    void* mem = Alloc_0008d690(0x14);
    if (mem) {
        int x = field8;
        return new (mem) CFightParams(x);
    }
    return 0;
}
} // namespace fn_000592c0

namespace fn_f8b0a0f7 {

// 0x00059300 FUN_00059300 (105 B): matches/0x00059300.cpp
// sym: ?F@X_59300@fn_f8b0a0f7@@QAEXXZ
void X_59300::F() {
    if (m4c) {
        m4c->Release();
        m4c = 0;
    }
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m6c) {
        m6c->Release();
        m6c = 0;
    }
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
}


// 0x00059370 FUN_00059370 (414 B): matches/0x00059370.cpp
// sym: ?FUN_00059370@Slots_59370@fn_f8b0a0f7@@QAEPAU12@PBU12@@Z
// FUN_00059370 @ 0x00059370
Slots_59370 *Slots_59370::FUN_00059370(const Slots_59370 *other)
{
    f48 = other->f48;
    {
        RefCounted_59370 *p = other->r4c;
        if (p)
            p->addRef();
        if (r4c)
            r4c->release();
        r4c = p;
    }
    {
        RefCounted_59370 *p = other->r50;
        if (p)
            p->addRef();
        if (r50)
            r50->release();
        r50 = p;
    }
    {
        RefCounted_59370 *p = other->r6c;
        if (p)
            p->addRef();
        if (r6c)
            r6c->release();
        r6c = p;
    }
    {
        RefCounted_59370 *p = other->r70;
        if (p)
            p->addRef();
        if (r70)
            r70->release();
        r70 = p;
    }
    {
        RefCounted_59370 *p = other->r84;
        if (p)
            p->addRef();
        if (r84)
            r84->release();
        r84 = p;
    }
    {
        RefCounted_59370 *p = other->r60;
        if (p)
            p->addRef();
        if (r60)
            r60->release();
        r60 = p;
    }
    f74 = other->f74;
    f08 = other->f08;
    f0c = other->f0c;
    f10 = other->f10;
    f18 = other->f18;
    f1c = other->f1c;
    f20 = other->f20;
    f38 = other->f38;
    f3c = other->f3c;
    f40 = other->f40;
    f00 = other->f00;
    f04 = other->f04;
    f54 = other->f54;
    b24 = other->b24;
    f58 = other->f58;
    f5c = other->f5c;
    f28 = other->f28;
    f2c = other->f2c;
    f30 = other->f30;
    f64 = other->f64;
    f68 = other->f68;
    f78 = other->f78;
    f7c = other->f7c;
    f80 = other->f80;
    f88 = other->f88;
    f8c = other->f8c;
    b14 = other->b14;
    b34 = other->b34;
    b90 = other->b90;
    b44 = other->b44;
    b91 = other->b91;
    return this;
}


// 0x00059510 FUN_00059510 (213 B): equivalent/0x00059510.cpp
// sym: ?FUN_00059510@State_59510@fn_f8b0a0f7@@QAEXXZ @a85cd1c23154 @w0058107c670b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00059510 @ 0x00059510
void State_59510::FUN_00059510() {
 if (resource4c) { resource4c->release(); resource4c = 0; }
 if (resource50) { resource50->release(); resource50 = 0; }
 if (resource6c) { resource6c->release(); resource6c = 0; }
 if (resource70) { resource70->release(); resource70 = 0; }
 if (resource84) { resource84->release(); resource84 = 0; }
 if (resource60) { resource60->release(); resource60 = 0; }
 field74 = 0;
 position[2] = position[1] = position[0] = 0;
 vector18[2] = vector18[1] = vector18[0] = 0;
 vector38[2] = vector38[1] = vector38[0] = 0;
 field00 = 0; field04 = 0;
 field54 = 0; field58 = 0; field5c = 0;
 enabled = 1;
 vector28[2] = vector28[1] = vector28[0] = 0;
 field64 = 0; field68 = 0;
 field78 = 0; field7c = 0; field80 = 0;
 field88 = 0; field8c = 0;
 flag14 = 0; flag34 = 0; flag90 = 0; flag44 = 0; flag91 = 0;
}


// 0x000595f0 FUN_000595f0 (298 B): equivalent/0x000595f0.cpp
// sym: ?FUN_000595f0@Obj_595f0@fn_f8b0a0f7@@QAEXPBUVec_595f0@2@MMM@Z @7785552e5bf8 @w7272f812eaa5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000595f0 @ 0x000595f0
void Obj_595f0::FUN_000595f0(const Vec_595f0* v, float scale, float time, float height) {
 if (time <= 0.0f) { duration=0.0f; velocity.z=0.0f; velocity.y=0.0f; velocity.x=0.0f; acceleration=(*(World**)&DAT_00554c10)->value.y * -0.01f; return; }
 double inverse=1.0f / (double)time;
 duration=time; velocity=*v;
 double factor=(double)scale*inverse;
 velocity.x=(float)(factor*velocity.x);
 velocity.z=(float)(factor*velocity.z);
 union { float f; unsigned int u; } magnitude;
 magnitude.f=height; magnitude.u &= 0x7fffffff;
 if(magnitude.f<=1e-05f) {velocity.y=0.0f; acceleration=0.0f;return;}
 if(height<0.0f) {velocity.y=(float)(inverse*height); acceleration=(*(World**)&DAT_00554c10)->value.y * -0.01f;}
 else {velocity.y=(float)(inverse*height*4.0f); acceleration=(float)(((double)height*8.0f)/((double)time*time));}
}


// 0x00059720 FUN_00059720 (55 B): matches/0x00059720.cpp
// sym: ??1CFightParams_59720@fn_f8b0a0f7@@QAE@XZ
CFightParams_59720::~CFightParams_59720() {
    vptr = hulk_at_003f9844;
    _ReadWriteBarrier();
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    Fin_00236a50();
}


// 0x00059760 FUN_00059760 (38 B): matches/0x00059760.cpp
// sym: ?Set@Owner_59760@fn_f8b0a0f7@@QAEXPAVRef_59760@2@@Z
void Owner_59760::Set(Ref_59760* p) {
    if (p)
        p->A();
    if (value)
        value->B();
    value = p;
}


// 0x00059790 FUN_00059790 (38 B): matches/0x00059790.cpp
// sym: ?Set@Owner_59790@fn_f8b0a0f7@@QAEXPAVItem_59790@2@@Z
void Owner_59790::Set(Item_59790* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x000597c0 FUN_000597c0 (69 B): matches/0x000597c0.cpp
// sym: ??1CFightParamsCollision_597c0@fn_f8b0a0f7@@QAE@XZ
CFightParamsCollision_597c0::~CFightParamsCollision_597c0() {
    vptr = hulk_at_003f985c;
    s18.Fini_00059300();
    vptr = gB_597c0;
    _ReadWriteBarrier();
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    Fin_00236a50();
}

} // namespace fn_f8b0a0f7

// 0x00059810 CFightParamsCollision::vfunc_3 (4 B): matches/0x00059810.cpp
// sym: ?vfunc_3@CFightParamsCollision@@UAEPAXXZ
void* CFightParamsCollision::vfunc_3() {
    return (void*)((CFightParamsCollision*)((char*)this + 0x18));
}

namespace fn_f8b0a0f7 {

// 0x00059820 FUN_00059820 (61 B): matches/0x00059820.cpp
// sym: ?Target@fn_f8b0a0f7@@YIPAVObj_59820@1@PAV21@@Z
// data: gCount_59820 = DAT_00494b30
Obj_59820* __fastcall Target(Obj_59820* self) {
    self->a4c = 0;
    self->a50 = 0;
    self->a60 = 0;
    self->a6c = 0;
    self->a70 = 0;
    self->a84 = 0;
    ((ThisCall_00059510*)(self))->Init_00059510();
    self->id = DAT_00494b30;
    ++DAT_00494b30;
    if (DAT_00494b30 == 0)
        DAT_00494b30 = 1;
    return self;
}

} // namespace fn_f8b0a0f7

// 0x00059890 CFightParams::vfunc_2 (76 B): matches/0x00059890.cpp [wrapped: conflict: CFightParams]
// sym: ?vfunc_2@CFightParams@fn_00059890@@QAEPAV12@E@Z
namespace fn_00059890 {
class Res_59890 {
  public:
    virtual void f0();
    virtual void Release();
};

extern int gVftable_59890;
void __cdecl MyDelete_0008d330(void*);

class CFightParams {
  public:
    void BaseCall_00236a50();
    CFightParams* vfunc_2(unsigned char flag);
};

CFightParams* CFightParams::vfunc_2(unsigned char flag) {
    volatile void** vp = (volatile void**)this;
    *vp = (void**)&gVftable_59890;
    volatile Res_59890** dp = (volatile Res_59890**)((char*)this + 0x10);
    Res_59890* d = (Res_59890*)*dp;
    if (d) {
        d->Release();
        *dp = 0;
    }
    volatile Res_59890** cp = (volatile Res_59890**)((char*)this + 0xc);
    Res_59890* c = (Res_59890*)*cp;
    if (c) {
        c->Release();
        *cp = 0;
    }
    BaseCall_00236a50();
    if (flag & 1) {
        MyDelete_0008d330(this);
    }
    return this;
}
} // namespace fn_00059890


// 0x000598e0 FUN_000598e0 (69 B): matches/0x000598e0.cpp [wrapped: conflict: CFightParamsCollision]
// sym: ??0CFightParamsCollision@fn_000598e0@@QAE@HH@Z
namespace fn_000598e0 {
class Parent {
  public:
    Parent();
    virtual void f();
    char pad[4];
};
class CFightParams_598e0 : public Parent {
  public:
    int value;
    int x, y;
    char pad[4];
    CFightParams_598e0(int v) : Parent(), value(v), x(0), y(0) {}
};
class Sub {
  public:
    char pad0[0x4c];
    int a, b;
    char pad1[0xc];
    int c;
    char pad2[8];
    int d, e;
    char pad3[0x10];
    int f;
    void Init_00059370(int);
    Sub(int z) : a(0), b(0), c(0), d(0), e(0), f(0) { Init_00059370(z); }
};
class CFightParamsCollision : public CFightParams_598e0 {
  public:
    Sub sub;
    CFightParamsCollision(hulk_intptr, hulk_intptr);
    virtual void f();
};
CFightParamsCollision::CFightParamsCollision(hulk_intptr v, hulk_intptr n) : CFightParams_598e0(v), sub(n) {}
} // namespace fn_000598e0


// 0x00059930 CFightParamsCollision::vfunc_2 (90 B): matches/0x00059930.cpp [wrapped: conflict: CFightParams; CFightParamsCollision]
// sym: ?vfunc_2@CFightParamsCollision@fn_00059930@@QAEPAV12@E@Z
void operator delete(void* p);
namespace fn_00059930 {
extern char CFightParamsCollision_vftable[4];
extern char CFightParams_vftable[4];

class RefObj_59930 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

class SubObj_59930 {
  public:
    void destroy_00059300();
};

class CFightParams {
  public:
    void baseDtor_00236a50();
};



union VPtr {
    hulk_uintptr n;
    volatile hulk_uintptr v;
};

class CFightParamsCollision {
  public:
    VPtr m_vptr;
    char pad0[8];
    RefObj_59930* volatile m_pC;
    RefObj_59930* volatile m_p10;
    char pad1[4];
    SubObj_59930 m_sub;

    CFightParamsCollision* vfunc_2(unsigned char flag);
};

CFightParamsCollision* CFightParamsCollision::vfunc_2(unsigned char flag) {
    this->m_vptr.n = (hulk_uintptr)&CFightParamsCollision_vftable[0];
    this->m_sub.destroy_00059300();
    this->m_vptr.v = (hulk_uintptr)&CFightParams_vftable[0];
    RefObj_59930* p10 = this->m_p10;
    if (p10 != 0) {
        p10->vfunc_1();
        this->m_p10 = 0;
    }
    RefObj_59930* pc = this->m_pC;
    if (pc != 0) {
        pc->vfunc_1();
        this->m_pC = 0;
    }
    reinterpret_cast<CFightParams*>(this)->baseDtor_00236a50();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
} // namespace fn_00059930

namespace fn_f8b0a0f7 {

// 0x00059a30 FUN_00059a30 (4 B): matches/0x00059a30.cpp
// sym: @FUN_00059a30@4
extern "C" hulk_uintptr __fastcall FUN_00059a30(Obj_59a30* self) {
    return self->value;
}


// 0x00059a40 FUN_00059a40 (4 B): matches/0x00059a40.cpp
// sym: @FUN_00059a40@4
extern "C" hulk_intptr __fastcall FUN_00059a40(hulk_intptr object) {
    return *(int*)(object + 0x18);
}


// 0x00059a50 FUN_00059a50 (59 B): matches/0x00059a50.cpp
// sym: ?Get@Obj_59a50@fn_f8b0a0f7@@QAE_NPAUOut_59a50@2@@Z
bool Obj_59a50::Get(Out_59a50* out) {
    Data_59a50* d = p;
    if (d) {
        out->a = d->a;
        out->b = d->b;
        out->c = d->c;
        return true;
    }
    out->a = a;
    out->b = b;
    out->c = c;
    return true;
}


// 0x00059a90 FUN_00059a90 (26 B): matches/0x00059a90.cpp
// sym: ?Set@Obj_59a90@fn_f8b0a0f7@@QAEDPAUSrc_59a90@2@@Z
char Obj_59a90::Set(Src_59a90* src) {
    a = src->a;
    b = src->b;
    c = src->c;
    return 1;
}


// 0x00059ad0 FUN_00059ad0 (135 B): equivalent/0x00059ad0.cpp
// sym: ?FUN_00059ad0@EntryPool@fn_f8b0a0f7@@QAEPAV12@XZ @36070a07a279 @w8dbf87af1b22
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 8/8)
// FUN_00059ad0 @ 0x00059ad0
EntryPool *EntryPool::FUN_00059ad0()
{
    f00 = 1;
    count = 100;
    unsigned int *raw = (unsigned int *)FUN_0008d6d0(100 * sizeof(Entry_59ad0) + 4);
    Entry_59ad0 *array = 0;
    if (raw) {
        *raw = 100;
        array = (Entry_59ad0 *)(raw + 1);
        for (int i = 0; i < 100; i++) {
            Entry_59ad0 *e = &array[i];
            e->f00 = 0;
            e->f04 = 0;
            e->f08 = 0;
            e->f0c = 0;
            e->f10 = 0;
            e->f14 = 0;
            e->f18 = 0;
        }
    }
    entries = array;
    flags = (unsigned char *)FUN_0008d6d0(count);
    for (unsigned int i = 0; i < count; i++)
        flags[i] = 0;
    return this;
}


// 0x00059b60 FUN_00059b60 (53 B): matches/0x00059b60.cpp
// sym: ?Allocate@Pool@fn_f8b0a0f7@@QAEHXZ
hulk_intptr Pool::Allocate() {
    int result = 0;
    for (unsigned i = 0; i < capacity; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            result = count;
            entries[i].id = result;
            ++count;
            break;
        }
    }
    return result;
}


// 0x00059ba0 FUN_00059ba0 (69 B): matches/0x00059ba0.cpp
// sym: ?Find@C_59ba0@fn_f8b0a0f7@@QAEPAUItem_59ba0@2@H@Z
Item_59ba0* C_59ba0::Find(int key) {
    unsigned int i;
    for (i = 0; i < count; ++i) {
        if (flags[i] != 0 && items[i].key == key)
            return items + i;
    }
    return 0;
}


// 0x00059bf0 FUN_00059bf0 (25 B): matches/0x00059bf0.cpp
// sym: ?FUN_00059bf0@ThisWrap_00059bf0@fn_f8b0a0f7@@QAEII@Z
hulk_uintptr ThisWrap_00059bf0::FUN_00059bf0(u32_59bf0 param) {
    Obj_59bf0* p = this->FUN_00059ba0(param);
    if (p)
        return p->value;
    return 0;
}

} // namespace fn_f8b0a0f7

// 0x00059c10 FUN_00059c10 (25 B): matches/0x00059c10.cpp
// sym: ?FUN_00059c10@ThisWrap_00059c10@owners@@QAEIPAX@Z
hulk_uintptr owners::ThisWrap_00059c10::FUN_00059c10(void* p) {
    void* q = this->FUN_00059ba0(p);
    if (q)
        return *(unsigned int*)((char*)q + 0x10);
    return 0;
}

namespace fn_f8b0a0f7 {

// 0x00059c50 FUN_00059c50 (36 B): matches/0x00059c50.cpp
// sym: _FUN_00059c50
extern "C" void FUN_00059c50(Holder* h, Obj* n) {
    if (n)
        n->First();
    if (h->mOld)
        h->mOld->Second();
    h->mOld = n;
}


// 0x00059c80 FUN_00059c80 (67 B): matches/0x00059c80.cpp
// sym: ?run@C_59c80@fn_f8b0a0f7@@QAEXXZ
void C_59c80::run() {
    if (a) {
        a->first_0003b620(0);
        a->second_00263e90();
        a = 0;
    }
    if (b) {
        b->second_00222b90(1);
        if (b) {
            b->F1();
            b = 0;
        }
    }
}


// 0x00059cd0 FUN_00059cd0 (38 B): matches/0x00059cd0.cpp
// sym: ?Set@Owner_59cd0@fn_f8b0a0f7@@QAEXPAVItem_59cd0@2@@Z
// Same code shape as 0x00059790 (propagated; names are from that function)
void Owner_59cd0::Set(Item_59cd0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x00059d00 FUN_00059d00 (38 B): matches/0x00059d00.cpp
// sym: ?Set@Owner_59d00@fn_f8b0a0f7@@QAEXPAVItem_59d00@2@@Z
void Owner_59d00::Set(Item_59d00* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x00059d30 FUN_00059d30 (123 B): matches/0x00059d30.cpp
// sym: ?FUN_00059d30@EntryTable_59d30@fn_f8b0a0f7@@QAEXXZ
// FUN_00059d30 @ 0x00059d30
// Releases the buffer and resource of every entry that is marked used.
void EntryTable_59d30::FUN_00059d30() {
    for (unsigned int i = 0; i < count; i++) {
        if (used[i]) {
            Entry_59d30 *e = &entries[i];
            if (e->buffer != 0) {
                e->buffer->FUN_0003b620(0);
                e->buffer->FUN_00263e90();
                e->buffer = 0;
            }
            if (e->resource != 0) {
                e->resource->FUN_00222b90(1);
                if (e->resource != 0) {
                    e->resource->Release();
                    e->resource = 0;
                }
            }
            used[i] = 0;
        }
    }
}

} // namespace fn_f8b0a0f7

// 0x00059db0 FUN_00059db0 (149 B): equivalent/0x00059db0.cpp [wrapped: conflict: World]
// sym: ?FUN_00059db0@ItemList_59db0@fn_00059db0@@QAEXXZ @890cee28b6de @wdd90953071c8
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00059db0 {
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 16/16)
// FUN_00059db0 @ 0x00059db0
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

struct Res_59db0 {
    void FUN_0003b620(int v);
    void FUN_00263e90();
};

class Handle_59db0 {
public:
    virtual void v0();
    virtual void Release();
    void FUN_00222b90(int v);
};

struct Item_59db0 {
    char pad0[0x10];
    Res_59db0 *res;           // 0x10
    char pad14[4];
    Handle_59db0 *handle;     // 0x18
    char pad1c[8];
};

struct Current_59db0 {
    char pad0[0x124];
    Res_59db0 *res;           // 0x124
};

struct World {
    char pad0[0x20];
    Current_59db0 *current;   // 0x20
};


class ItemList_59db0 {
public:
    char pad0[4];
    unsigned int count;         // 4
    Item_59db0 *items;                // 8
    unsigned char *active;      // 0xc
    void FUN_00059db0();
};

void ItemList_59db0::FUN_00059db0()
{
    for (unsigned int i = 0; i < count; i++) {
        if (active[i] == 0)
            continue;
        Item_59db0 *item = &items[i];
        if (item->res != 0 && item->res == DAT_004dd700->current->res)
            continue;
        if (item->res != 0) {
            item->res->FUN_0003b620(0);
            item->res->FUN_00263e90();
            item->res = 0;
        }
        if (item->handle != 0) {
            item->handle->FUN_00222b90(1);
            if (item->handle != 0) {
                item->handle->Release();
                item->handle = 0;
            }
        }
        active[i] = 0;
    }
}
} // namespace fn_00059db0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8b0a0f7 {

// 0x00059e50 FUN_00059e50 (130 B): matches/0x00059e50.cpp
// sym: ?FUN_00059e50@EntryTable_59e50@fn_f8b0a0f7@@QAEXPAX@Z
// FUN_00059e50 @ 0x00059e50
void EntryTable_59e50::FUN_00059e50(void *key)
{
    for (unsigned int i = 0; i < count; i++) {
        if (used[i] && entries[i].key == key) {
            Entry_59e50 *e = &entries[i];
            if (e->buffer != 0) {
                e->buffer->FUN_0003b620(0);
                e->buffer->FUN_00263e90();
                e->buffer = 0;
            }
            if (e->effect != 0) {
                e->effect->FUN_00222b90(1);
                if (e->effect != 0) {
                    e->effect->vfunc_1();
                    e->effect = 0;
                }
            }
            used[i] = 0;
            return;
        }
    }
}


// 0x00059ee0 FUN_00059ee0 (67 B): matches/0x00059ee0.cpp
// sym: ?run@C_59ee0@fn_f8b0a0f7@@QAEXXZ
// Same code shape as 0x00059c80 (propagated; names are from that function)
void C_59ee0::run() {
    if (a) {
        a->first_0003b620(0);
        a->second_00263e90();
        a = 0;
    }
    if (b) {
        b->second_00222b90(1);
        if (b) {
            b->F1();
            b = 0;
        }
    }
}


// 0x00059f30 FUN_00059f30 (209 B): equivalent/0x00059f30.cpp
// sym: ?FUN_00059f30@Item_59f30@fn_f8b0a0f7@@QAEPAXE@Z @e9c52ee1ccd7 @wfb6445942925
// STATUS: equivalent (tools/equiv.py level 3: 294 inputs, branch coverage 22/22)
// FUN_00059f30 @ 0x00059f30
void* Item_59f30::FUN_00059f30(unsigned char flags) {
 if (flags & 2) {
  int* cookie = reinterpret_cast<int*>(this)-1;
  int count=*cookie;
  if(count>0) {
   Item_59f30* end=this+count;
   do {
    --end;
    if(end->resource) { end->resource->FUN_0003b620(0); end->resource->FUN_00263e90(); end->resource=0; }
    if(end->object) { end->object->FUN_00222b90(1); if(end->object) { end->object->slot1(); end->object=0; } }
   } while(--count);
  }
  if(flags & 1) FUN_0008d340(cookie);
  return cookie;
 }
 if(resource) { resource->FUN_0003b620(0); resource->FUN_00263e90(); resource=0; }
 if(object) { object->FUN_00222b90(1); if(object) { object->slot1(); object=0; } }
 if(flags & 1) FUN_0008d330(this);
 return this;
}


// 0x0005a010 FUN_0005a010 (50 B): matches/0x0005a010.cpp
// sym: ?FUN_0005a010@fn_f8b0a0f7@@YIXPAUObj_5a010@1@@Z
void __fastcall FUN_0005a010(Obj_5a010* self) {
    FUN_00059d30(self);
    if (self->a)
        self->a->Fnf_00059f30(3);
    int value = self->b;
    self->a = 0;
    thunk_FUN_00267090(value);
    self->b = 0;
}

} // namespace fn_f8b0a0f7

// 0x0005a0d0 FUN_0005a0d0 (12 B): matches/0x0005a0d0.cpp
// sym: ?FUN_0005a0d0@O_5a0d0@owners@@QAE_NH@Z
bool owners::O_5a0d0::FUN_0005a0d0(int x) {
    m = x;
    return true;
}


// 0x0005a0e0 FUN_0005a0e0 (12 B): matches/0x0005a0e0.cpp
// sym: ?FUN_0005a0e0@Obj_5a0e0@owners@@QAEDH@Z
char owners::Obj_5a0e0::FUN_0005a0e0(int a) {
    *(int*)((char*)this + 0x10) = a;
    return 1;
}


// 0x0005a0f0 FUN_0005a0f0 (12 B): matches/0x0005a0f0.cpp
// sym: ?FUN_0005a0f0@Obj_5a0f0@owners@@QAEDH@Z
char owners::Obj_5a0f0::FUN_0005a0f0(int x) {
    m70 = x;
    return 1;
}


// 0x0005a100 FUN_0005a100 (12 B): matches/0x0005a100.cpp
// sym: ?FUN_0005a100@Obj_5a100@owners@@QAEDH@Z
char owners::Obj_5a100::FUN_0005a100(int x) {
    value = x;
    return 1;
}


// 0x0005a110 FUN_0005a110 (12 B): matches/0x0005a110.cpp
// sym: ?FUN_0005a110@Obj_5a110@owners@@QAEDH@Z
char owners::Obj_5a110::FUN_0005a110(int v) {
    m78 = v;
    return 1;
}


// 0x0005a120 FUN_0005a120 (12 B): matches/0x0005a120.cpp
// sym: ?FUN_0005a120@C_5a120@owners@@QAE_NH@Z
bool owners::C_5a120::FUN_0005a120(int x) {
    m = x;
    return true;
}


// 0x0005a130 FUN_0005a130 (12 B): matches/0x0005a130.cpp
// sym: ?FUN_0005a130@Obj_5a130@owners@@QAEDD@Z
char owners::Obj_5a130::FUN_0005a130(char x) {
    m20 = x;
    return 1;
}

namespace fn_f8b0a0f7 {

// 0x0005a140 FUN_0005a140 (26 B): matches/0x0005a140.cpp
// sym: ?Set@O_5a140@fn_f8b0a0f7@@QAEDPAUV@2@@Z
char O_5a140::Set(V* v) {
    m24 = v->a;
    m28 = v->b;
    m2c = v->c;
    return 1;
}

} // namespace fn_f8b0a0f7

// 0x0005a160 FUN_0005a160 (18 B): matches/0x0005a160.cpp
// sym: ?FUN_0005a160@Obj_5a160@owners@@QAEDM@Z
char owners::Obj_5a160::FUN_0005a160(float x) {
    *(float*)((char*)this + 0x30) = x * 0.017453292f;
    return 1;
}

namespace fn_f8b0a0f7 {

// 0x0005a180 FUN_0005a180 (44 B): matches/0x0005a180.cpp
// sym: ?FUN_0005a180@Obj@fn_f8b0a0f7@@QAEEPBUVec3@2@@Z
unsigned char Obj::FUN_0005a180(const Vec3* v) {
    float a = v->z * 0.017453292f, b = v->y * 0.017453292f, c = v->x * 0.017453292f;
    x = c;
    y = b;
    z = a;
    return 1;
}


// 0x0005a1b0 FUN_0005a1b0 (26 B): matches/0x0005a1b0.cpp
// sym: ?Set@Obj_5a1b0@fn_f8b0a0f7@@QAE_NPBUVec3_5a1b0@2@@Z
bool Obj_5a1b0::Set(const Vec3_5a1b0* v) {
    m48 = v->x;
    m4c = v->y;
    m50 = v->z;
    return true;
}

} // namespace fn_f8b0a0f7

// 0x0005a1d0 FUN_0005a1d0 (12 B): matches/0x0005a1d0.cpp
// sym: ?FUN_0005a1d0@Obj_5a1d0@owners@@QAE_NH@Z
bool owners::Obj_5a1d0::FUN_0005a1d0(int v) {
    mVal = v;
    return true;
}


// 0x0005a1e0 FUN_0005a1e0 (12 B): matches/0x0005a1e0.cpp
// sym: ?FUN_0005a1e0@Obj_5a1e0@owners@@QAEDH@Z
char owners::Obj_5a1e0::FUN_0005a1e0(int value) {
    m58 = value;
    return 1;
}


// 0x0005a1f0 FUN_0005a1f0 (12 B): matches/0x0005a1f0.cpp
// sym: ?FUN_0005a1f0@Obj_5a1f0@owners@@QAEDE@Z
char owners::Obj_5a1f0::FUN_0005a1f0(unsigned char x) {
    m5c = x;
    return 1;
}


// 0x0005a200 FUN_0005a200 (12 B): matches/0x0005a200.cpp
// sym: ?FUN_0005a200@Obj_5a200@owners@@QAE_NH@Z
bool owners::Obj_5a200::FUN_0005a200(int value) {
    mFoo = value;
    return true;
}


// 0x0005a210 FUN_0005a210 (12 B): matches/0x0005a210.cpp
// sym: ?FUN_0005a210@Obj_5a210@owners@@QAEDH@Z
char owners::Obj_5a210::FUN_0005a210(int v) {
    m64 = v;
    return 1;
}


// 0x0005a220 FUN_0005a220 (12 B): matches/0x0005a220.cpp
// sym: ?FUN_0005a220@C_5a220@owners@@QAEDH@Z
char owners::C_5a220::FUN_0005a220(int a) {
    m = a;
    return 1;
}


// 0x0005a230 FUN_0005a230 (12 B): matches/0x0005a230.cpp
// sym: ?FUN_0005a230@O_5a230@owners@@QAEDD@Z
char owners::O_5a230::FUN_0005a230(char v) {
    m20 = v;
    return 1;
}

namespace fn_f8b0a0f7 {

// 0x0005a240 FUN_0005a240 (26 B): matches/0x0005a240.cpp
// sym: ?Set@C_5a240@fn_f8b0a0f7@@QAE_NPBUS_5a240@2@@Z
bool C_5a240::Set(const S_5a240* o) {
    s.a = o->a;
    s.b = o->b;
    s.c = o->c;
    return true;
}

} // namespace fn_f8b0a0f7

// 0x0005a260 FUN_0005a260 (18 B): matches/0x0005a260.cpp
// sym: ?FUN_0005a260@Thing_5a260@owners@@QAEDM@Z
char owners::Thing_5a260::FUN_0005a260(float a) {
    angle = a * 0.017453292f;
    return 1;
}


// 0x0005a280 FUN_0005a280 (12 B): matches/0x0005a280.cpp
// sym: ?FUN_0005a280@Obj_5a280@owners@@QAE_NH@Z
bool owners::Obj_5a280::FUN_0005a280(int x) {
    mVal = x;
    return true;
}


// 0x0005a290 FUN_0005a290 (12 B): matches/0x0005a290.cpp
// sym: ?FUN_0005a290@Obj_5a290@owners@@QAE_NH@Z
bool owners::Obj_5a290::FUN_0005a290(int v) {
    m38 = v;
    return true;
}


// 0x0005a2a0 FUN_0005a2a0 (12 B): matches/0x0005a2a0.cpp
// sym: ?FUN_0005a2a0@Obj_5a2a0@owners@@QAE_NH@Z
bool owners::Obj_5a2a0::FUN_0005a2a0(int value) {
    mField = value;
    return true;
}


// 0x0005a2b0 FUN_0005a2b0 (12 B): matches/0x0005a2b0.cpp
// sym: ?FUN_0005a2b0@Obj_5a2b0@owners@@QAE_NH@Z
bool owners::Obj_5a2b0::FUN_0005a2b0(int x) {
    mVal = x;
    return true;
}


// 0x0005a2c0 FUN_0005a2c0 (12 B): matches/0x0005a2c0.cpp
// sym: ?FUN_0005a2c0@Target_5a2c0@owners@@QAEDH@Z
char owners::Target_5a2c0::FUN_0005a2c0(int x) {
    value = x;
    return 1;
}


// 0x0005a2d0 FUN_0005a2d0 (12 B): matches/0x0005a2d0.cpp
// sym: ?FUN_0005a2d0@O_5a2d0@owners@@QAE_NH@Z
bool owners::O_5a2d0::FUN_0005a2d0(int x) {
    mVal = x;
    return true;
}


// 0x0005a2e0 FUN_0005a2e0 (12 B): matches/0x0005a2e0.cpp
// sym: ?FUN_0005a2e0@Obj_5a2e0@owners@@QAE_NH@Z
bool owners::Obj_5a2e0::FUN_0005a2e0(int x) {
    value = x;
    return true;
}


// 0x0005a2f0 FUN_0005a2f0 (12 B): matches/0x0005a2f0.cpp
// sym: ?FUN_0005a2f0@Obj_5a2f0@owners@@QAEDH@Z
char owners::Obj_5a2f0::FUN_0005a2f0(int v) {
    mValue = v;
    return 1;
}


// 0x0005a300 FUN_0005a300 (4 B): matches/0x0005a300.cpp
// sym: ?FUN_0005a300@Obj_5a300@owners@@QAEPAXXZ
void* owners::Obj_5a300::FUN_0005a300() {
    return (char*)this + 0x18;
}


// 0x0005a310 FUN_0005a310 (12 B): matches/0x0005a310.cpp
// sym: ?FUN_0005a310@Obj_5a310@owners@@QAE_NH@Z
bool owners::Obj_5a310::FUN_0005a310(int value) {
    m24 = value;
    return true;
}


// 0x0005a320 FUN_0005a320 (4 B): matches/0x0005a320.cpp
// sym: ?FUN_0005a320@O_5a320@owners@@QAEPAXXZ
void* owners::O_5a320::FUN_0005a320() {
    return (char*)this + 0x28;
}

namespace fn_f8b0a0f7 {

// 0x0005a330 FUN_0005a330 (4 B): matches/0x0005a330.cpp
// sym: ?Get@O_5a330@fn_f8b0a0f7@@QAEPAUS_5a330@2@XZ
S_5a330* O_5a330::Get() {
    return (S_5a330*)((char*)this + 0xc);
}


// 0x0005a340 FUN_0005a340 (12 B): matches/0x0005a340.cpp
// sym: ?SetFlag@Obj_5a340@fn_f8b0a0f7@@QAE_NH@Z
bool Obj_5a340::SetFlag(int value) {
    m18 = value;
    return true;
}


// 0x0005a350 FUN_0005a350 (4 B): matches/0x0005a350.cpp
// sym: ?Get@Obj_5a350@fn_f8b0a0f7@@QAEPAXXZ
void* Obj_5a350::Get() {
    return (char*)this + 0x1c;
}

} // namespace fn_f8b0a0f7

// 0x0005a360 FUN_0005a360 (12 B): matches/0x0005a360.cpp
// sym: ?FUN_0005a360@Obj_5a360@owners@@QAEDH@Z
char owners::Obj_5a360::FUN_0005a360(int value) {
    mValue = value;
    return 1;
}


// 0x0005a370 FUN_0005a370 (12 B): matches/0x0005a370.cpp
// sym: ?FUN_0005a370@Obj_5a370@owners@@QAEDH@Z
char owners::Obj_5a370::FUN_0005a370(int value) {
    mValue = value;
    return 1;
}


// 0x0005a380 FUN_0005a380 (4 B): matches/0x0005a380.cpp
// sym: ?FUN_0005a380@Obj_5a380@owners@@QAEPAXXZ
void* owners::Obj_5a380::FUN_0005a380() {
    return (void*)((char*)this + 0x18);
}

namespace fn_f8b0a0f7 {

// 0x0005a390 FUN_0005a390 (26 B): matches/0x0005a390.cpp
// sym: ?Set@O_5a390@fn_f8b0a0f7@@QAE_NPAUS_5a390@2@@Z
bool O_5a390::Set(S_5a390* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}

} // namespace fn_f8b0a0f7

// 0x0005a3b0 FUN_0005a3b0 (12 B): matches/0x0005a3b0.cpp
// sym: ?FUN_0005a3b0@O_5a3b0@owners@@QAEDH@Z
char owners::O_5a3b0::FUN_0005a3b0(int v) {
    mVal = v;
    return 1;
}


// 0x0005a3c0 FUN_0005a3c0 (12 B): matches/0x0005a3c0.cpp
// sym: ?FUN_0005a3c0@Obj_5a3c0@owners@@QAEDH@Z
char owners::Obj_5a3c0::FUN_0005a3c0(int x) {
    m30 = x;
    return 1;
}


// 0x0005a3d0 FUN_0005a3d0 (12 B): matches/0x0005a3d0.cpp
// sym: ?FUN_0005a3d0@Obj_5a3d0@owners@@QAEDH@Z
char owners::Obj_5a3d0::FUN_0005a3d0(int value) {
    m34 = (char)value;
    return 1;
}

namespace fn_f8b0a0f7 {

// 0x0005a3f0 FUN_0005a3f0 (64 B): matches/0x0005a3f0.cpp
// sym: _FUN_0005a3f0
extern "C" hulk_intptr __cdecl FUN_0005a3f0(X_5a3f0* param) {
    if (param != 0) {
        hulk_intptr a = ((int)((owners::Object_592a0 *)param)->FUN_000592a0());
        if (a != 0) {
            hulk_intptr b = ((Y_5a3f0*)a)->FnB_00059a30();
            if (b != 0) {
                int c = *(int*)(b + 0x334);
                if (c != 0)
                    return c + 0xdc;
                int d = *(int*)(b + 0x330);
                if (d != 0)
                    return d + 0xdc;
            }
        }
    }
    return 0;
}


// 0x0005a430 FUN_0005a430 (51 B): equivalent/0x0005a430.cpp
// sym: _FUN_0005a430 @c8424f0a9135 @wdad6db87ab83
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0005a430 @ 0x0005a430
extern "C" void* __cdecl FUN_0005a430(Input* input) { if (!input) return 0; Middle* middle = (Middle*)((void *)((owners::Object_592a0 *)input)->FUN_000592a0()); if (!middle) return 0; Result* result = middle->FUN_00059a30(); if (!result) return 0; return result->preferred ? result->preferred : result->fallback; }


// 0x0005a470 FUN_0005a470 (66 B): matches/0x0005a470.cpp
// sym: _FUN_0005a470
extern "C" int __cdecl FUN_0005a470(A* a) {
    if (!a)
        return 0;
    B* b = a->get_000592a0();
    if (!b)
        return 0;
    Mid* m = b->get_00059a30();
    if (!m)
        return 0;
    Leaf* p = m->select();
    if (!p)
        return 0;
    return p->value;
}

} // namespace fn_f8b0a0f7
