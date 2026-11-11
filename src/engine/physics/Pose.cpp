// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030eba0..0x00310130 (kind game, layer engine, confidence medium), dominant class physics::Pose
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f346547a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f346547a {} using namespace fn_f346547a;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f346547a {
typedef unsigned int u32_30eba0;
struct Child_30eba0 {
    char data[0x54];
    Child_30eba0();
};
struct T_30eba0 {
    u32_30eba0 a0;
    u32_30eba0 a1;
    u32_30eba0 a2;
    u32_30eba0 a3;
    u32_30eba0 a4;
    Child_30eba0 c1;
    Child_30eba0 c2;
    u32_30eba0 last;
    T_30eba0();
};
extern "C" void __cdecl thunk_FUN_00267090(int);
struct Target_30ebd0 {
    char pad[0x10];
    int value;
};
struct Block_30ebe0 {
    unsigned int x[0x15];
};
struct Obj_30ebe0 {
    char pad[0x14];
    Block_30ebe0 a;
    Block_30ebe0 b;
    unsigned int c;
    void Copy(Obj_30ebe0*);
};
extern "C" void* __cdecl Allocate(unsigned int);
class A_30ecb0 {
  public:
    char pad[0xc];
    int count;
    int* items;
    char pad2[0xa8];
    int state;
    void f();
};
class C_30ecf0 {
    char pad[0xbc];
    int x;

  public:
    void __fastcall f();
};
class Inner_30ed00 {
  public:
    int data[0x15];
    void Init();
};
class Obj_30ed00 {
  public:
    int z[5];
    Inner_30ed00 one;
    Inner_30ed00 two;
    int last;
    Obj_30ed00* Copy(Obj_30ed00* src);
};
class Node {
  public:
    char pad0[12];
    int count;
    Node** children;
    char pad1[0xa8];
    int state;
    void Step();
};
class Owner {
  public:
    char pad[12];
    int count;
    Node** children;
    void Traverse();
};
struct Data_30edc0 {
    unsigned int words[0x15];
};
class Thing_30edc0 {
  public:
    char pad0[0x14];
    Data_30edc0 block;
    char pad1[0xbc - 0x14 - sizeof(Data_30edc0)];
    int state;
    void Run(Data_30edc0* data);
    void Finish();
};
struct Block_30edf0 {
    int a[21];
    void Finish(int);
};
class Obj_30edf0 {
  public:
    char pad0[4];
    int value;
    char pad8[12];
    Block_30edf0 source;
    Block_30edf0 dest;
    int state;
};
extern int __fastcall clone(int);
extern void __fastcall notify(Obj_30edf0*);
struct Block_30ee40 {
    unsigned int x[0x15];
};
struct Obj_30ee40 {
    char pad[0x68];
    Block_30ee40 data;
    int state;
    void Update();
    void Copy(const Block_30ee40*);
};
struct B_30ee70 {
    void F(int);
};
struct B_30eed0 {
};
struct A_30eed0 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
struct B_30ef00 {
    void F(int);
};
struct A_30ef00 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
struct Blob_30ef30 {
    int d[21];
    void Fin();
    void Assign(const Blob_30ef30* o);
};
struct Src_30ef30 {
    Blob_30ef30* Get();
};
struct Obj_30ef30 {
    int p0;
    Src_30ef30* src;
    char pad[0x14 - 8];
    Blob_30ef30 cur;
    Blob_30ef30 saved;
    int state;
    Blob_30ef30* Update();
};
class C_30f000 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void third();
    void target(int);
};
class C_30f030 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void second(int);
    void third();
    void target(int);
};
typedef unsigned int u32_30f070;
struct Block_30f070 {
    u32_30f070 x[16];
};
struct Obj_30f070 {
    Block_30f070 block;
    u32_30f070 a, b, c, d, e;
    Obj_30f070* Copy(const Block_30f070* src);
};
struct Pair_30f0a0 {
    int a, b, c, d;
};
class Obj_30f0a0 {
  public:
    char pad[0x40];
    Pair_30f0a0 value;
    int flag;
    void First();
    Obj_30f0a0* Run(Pair_30f0a0* src, int x);
};
class Base_30f0e0 {
  public:
    void Init();
};
class Thing_30f0e0 : public Base_30f0e0 {
    char pad[0x40];
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
    volatile int e;

  public:
    void Run();
};
struct Obj_30f100 {
    char pad[0x40];
    struct Sub {
        void F(Obj_30f100*);
    } sub;
    char pad2[0x0c];
    int state;
    Obj_30f100* target();
};
struct Data_30f120 {
    unsigned int a[16];
};
class C_30f120 {
  public:
    Data_30f120 d;
    char pad[0x10];
    int x;
    void Copy(C_30f120*);
};
struct Sub_30f190 {
    char pad[0x10];
};
struct C_30f190 {
    char pad[0x40];
    Sub_30f190 sub;
    int state;
    void* target();
};
struct Four_30f1b0 {
    int x, y, z, w;
};
class Obj_30f1b0 {
  public:
    char pad[0x40];
    Four_30f1b0 v;
    int flag;
    void Set(const Four_30f1b0& p);
};
struct Vec3_30f1e0 { float x,y,z; };
struct Quaternion_30f1e0 {
 float x,y,z; unsigned int w;
};
struct Object {
 char pad[0x30]; Vec3_30f1e0 position; char pad3c[4]; Quaternion_30f1e0 rotation; int state;
 void blend(float,Object*);
};
} // namespace fn_f346547a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f346547a {
class Obj_30f300;
class Sub_30f300 {
  public:
    void Fn(Obj_30f300*);
};
class Temp_30f300 {
  public:
    void Fn(Obj_30f300*, Obj_30f300*);
    char data[0x40];
};
class Obj_30f300 {
  public:
    char pad[0x40];
    Sub_30f300 sub;
    char pad2[0x0c];
    int state;
    void Run(Obj_30f300*);
};
struct Sub_30f370 {
    void call(struct Obj_30f370*);
};
struct Obj_30f370 {
    char pad[0x40];
    Sub_30f370 sub;
    char pad2[0xc];
    int state;
    void target();
};
extern "C" void __fastcall FUN_0022b980(void*);
class Obj_30f3a0 {
  public:
    char pad[0x40];
    volatile int a, b, c, d, e;
    Obj_30f3a0();
};
class Base_30f3d0 {
  public:
    Base_30f3d0();
    char pad[0x40];
};
class Thing_30f3d0 : public Base_30f3d0 {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing_30f3d0(int);
};
struct Info {
    char pad[16];
    int count;
};
struct Elem {
    char bytes[192];
};
class Table {
  public:
    char _m_pad_0[0x8];
    Info* info;
    Elem* entries;
    int count;
    char _m_pad_14[0x4];
    int *sizes;
    int **items;
    Elem* Get(int index);
    unsigned char FUN_0030fea0(int index, int position);
    unsigned char FUN_0030ff20(int index, int value);
};
extern void* vP[];
extern void* vR[];
extern "C++" __declspec(nothrow) void thunk_FUN_00267090(void*) throw();
struct Elem_30f810 {
    char pad[0xc0];
    void Fini() throw();
};
struct Ref_30f810 {
    virtual void a() throw();
    virtual void release() throw();
};
class Pose_30f810 {
  public:
    void* vptr;
    int pad;
    Ref_30f810* ref;
    Elem_30f810* arr;
    ~Pose_30f810() throw();
};
class Ref_30fc90 {
  public:
    virtual void A();
    virtual void B();
};
extern void* vt1_30fc90;
extern void* vt2_30fc90;
class PoseEngine_30fc90 {
  public:
    virtual void V();
    int a4;
    Ref_30fc90* obj8;
    Ref_30fc90* objc;
    int count;
    int a14;
    Ref_30fc90*** arr;
    Ref_30fc90*** rows;
};
void __cdecl drop(void*);
} // namespace fn_f346547a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
#endif
namespace fn_f346547a {
struct Item_30fda0 {
 virtual void retain();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual int key1();
 virtual int key2();
};
struct Container_30fda0 {
 char pad[16];
 int groupCount;
 int capacity;
 int* counts;
 Item_30fda0*** groups;
 bool insert(int group, Item_30fda0* item);
};
class Item_30fea0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_30fea0 {
  public:
    char pad0[0x10];
    int count;
    char pad14[4];
    int* counts;
    Item_30fea0*** items;
    bool Remove(int i, int j);
};
struct Pose_nv_30ff80 {
    void f650();
    void f4c0();
    void fa10(int);
};
class C_30ff80 {
    char pad0[8];
    int m8;
    physics::Pose* mc;

  public:
    void target(char b);
};
class Item_30ffb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void invoke(void*);
};
class Container_30ffb0 {
  public:
    char pad[16];
    int limit;
    char p[4];
    int* counts;
    Item_30ffb0*** items;
    void run(int, void*);
};
class Item {
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
    virtual void Act(void*);
    char pad[0xc];
    char active;
};
class Holder {
  public:
    char pad[0xc];
    void* context;
    int count;
    char pad2[4];
    int* sizes;
    Item*** items;
    void Run(int index);
};
typedef unsigned int u32_310070;
struct B_310070 {
    void F(u32_310070, u32_310070);
};
struct A_310070 {
    char pad[8];
    u32_310070 a;
    B_310070* b;
};
extern void* g_vftable_310080[];
} // namespace fn_f346547a
void* operator new(size_t);
void* operator new[](size_t);
namespace fn_f346547a {
class Res_310080 {
  public:
    virtual void F0();
};
struct Pose_nv_310080 {
    physics::Pose* Init(Res_310080* r);
};
class PoseEngine_310080 {
  public:
    void* vptr;
    int m4;
    Res_310080* m8;
    physics::Pose* mc;
    int m10;
    int m14;
    int** m18;
    int** m1c;
    PoseEngine_310080* ctor(Res_310080* a0, int a1, int a2);
};


// 0x0030eba0 FUN_0030eba0 (47 B): matches/0x0030eba0.cpp
// sym: ??0T_30eba0@fn_f346547a@@QAE@XZ
T_30eba0::T_30eba0() : a0(0), a1(0), a2(0), a3(0), a4(0), c1(), c2(), last(0) {}


// 0x0030ebd0 FUN_0030ebd0 (11 B): matches/0x0030ebd0.cpp
// sym: ?FUN_0030ebd0@fn_f346547a@@YIXPAUTarget_30ebd0@1@PAX@Z
void __fastcall FUN_0030ebd0(Target_30ebd0* self, void*) {
    thunk_FUN_00267090(self->value);
}


// 0x0030ebe0 FUN_0030ebe0 (51 B): matches/0x0030ebe0.cpp
// sym: ?Copy@Obj_30ebe0@fn_f346547a@@QAEXPAU12@@Z
void Obj_30ebe0::Copy(Obj_30ebe0* src) {
    a = src->a;
    b = src->b;
    c = src->c;
}

} // namespace fn_f346547a

// 0x0030ec20 FUN_0030ec20 (10 B): matches/0x0030ec20.cpp
// sym: ?FUN_0030ec20@A_30ec20@owners@@QAEXH@Z
// Same code shape as 0x00098e20 (propagated; names are from that function)
void owners::A_30ec20::FUN_0030ec20(int x) {
    value = x;
}


// 0x0030ec70 FUN_0030ec70 (57 B): matches/0x0030ec70.cpp
// sym: ?FUN_0030ec70@Buffer_30ec70@owners@@QAE_NI@Z
bool owners::Buffer_30ec70::FUN_0030ec70(hulk_uintptr value) {
    if (data == 0) {
        data = (unsigned int*)Allocate(count << 2);
        count = 0;
    }
    data[count] = ((unsigned int)value);
    ++count;
    return true;
}

namespace fn_f346547a {

// 0x0030ecb0 FUN_0030ecb0 (55 B): matches/0x0030ecb0.cpp
// sym: ?f@A_30ecb0@fn_f346547a@@QAEXXZ
void A_30ecb0::f() {
    if (state == 0) {
        state = 2;
        for (int i = 0; i < count; ++i) {
            ((A_30ecb0*)items[i])->f();
        }
    }
}


// 0x0030ecf0 FUN_0030ecf0 (11 B): matches/0x0030ecf0.cpp
// sym: ?f@C_30ecf0@fn_f346547a@@QAIXXZ
void __fastcall C_30ecf0::f() {
    x = 0;
}


// 0x0030ed00 FUN_0030ed00 (89 B): matches/0x0030ed00.cpp
// sym: ?Copy@Obj_30ed00@fn_f346547a@@QAEPAV12@PAV12@@Z
Obj_30ed00* Obj_30ed00::Copy(Obj_30ed00* src) {
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    z[4] = 0;
    one.Init();
    two.Init();
    one = src->one;
    two = src->two;
    last = src->last;
    return this;
}


// 0x0030ed60 FUN_0030ed60 (82 B): equivalent/0x0030ed60.cpp
// sym: ?Traverse@Owner@fn_f346547a@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 423 inputs, branch coverage 10/10)
// FUN_0030ed60 @ 0x0030ed60
// FUN_0030ed60 @ 0x0030ed60
// native13: the original keeps the node in edx across its call of 0x0030ecb0 (which never writes edx: whole-
// program register allocation); the byte-matched source read it back as the high half of a 64-bit return, which
// a native definition doesn't preserve. Here the node is an ordinary local (MSVC 7.1 can't emit the original's
// register use, so this is an equivalent, not a match).
void Owner::Traverse() {
    for (int i = 0; i < count; ++i) {
        Node* p = children[i];
        if (p->state == 0) {
            int n = p->count;
            p->state = 2;
            if (n > 0) {
                int j = 0;
                do {
                    p->children[j]->Step();
                    ++j;
                } while (j < p->count);
            }
        }
    }
}


// 0x0030edc0 FUN_0030edc0 (40 B): matches/0x0030edc0.cpp
// sym: ?Run@Thing_30edc0@fn_f346547a@@QAEXPAUData_30edc0@2@@Z
void Thing_30edc0::Run(Data_30edc0* data) {
    block = *data;
    state = 2;
    Finish();
}


// 0x0030edf0 FUN_0030edf0 (77 B): matches/0x0030edf0.cpp
// sym: ?target@fn_f346547a@@YIPAUBlock_30edf0@1@PAVObj_30edf0@1@@Z
Block_30edf0* __fastcall target(Obj_30edf0* p) {
    if (p->state == 2) {
        if (p->value) {
            p->dest = p->source;
            int x = clone(p->value);
            p->dest.Finish(x);
            notify(p);
        }
        p->state = 0;
    }
    return &p->dest;
}


// 0x0030ee40 FUN_0030ee40 (40 B): matches/0x0030ee40.cpp
// sym: ?Copy@Obj_30ee40@fn_f346547a@@QAEXPBUBlock_30ee40@2@@Z
void Obj_30ee40::Copy(const Block_30ee40* src) {
    data = *src;
    state = 1;
    Update();
}

} // namespace fn_f346547a

// 0x0030ee70 FUN_0030ee70 (42 B): matches/0x0030ee70.cpp
// sym: ?FUN_0030ee70@A_30ee70@owners@@QAEXH@Z
void owners::A_30ee70::FUN_0030ee70(hulk_intptr x) {
    Init();
    ((B_30ee70*)((char*)this + 0x68))->F(((int)x));
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}

namespace fn_f346547a {

// 0x0030eed0 FUN_0030eed0 (42 B): matches/0x0030eed0.cpp
// sym: ?Target@A_30eed0@fn_f346547a@@QAEXH@Z
// Same code shape as 0x0030ee70 (propagated; names are from that function)
void A_30eed0::Target(int x) {
    Init();
    ((owners::Target_22be40 *)(((B_30eed0*)((char*)this + 0x68))))->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}


// 0x0030ef00 FUN_0030ef00 (42 B): matches/0x0030ef00.cpp
// sym: ?Target@A_30ef00@fn_f346547a@@QAEXH@Z
// Same code shape as 0x0030ee70 (propagated; names are from that function)
void A_30ef00::Target(int x) {
    Init();
    ((B_30ef00*)((char*)this + 0x68))->F(x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}


// 0x0030ef30 FUN_0030ef30 (98 B): matches/0x0030ef30.cpp
// sym: ?Update@Obj_30ef30@fn_f346547a@@QAEPAUBlob_30ef30@2@XZ
Blob_30ef30* Obj_30ef30::Update() {
    if (state == 1) {
        if (src) {
            Blob_30ef30 tmp = *src->Get();
            tmp.Fin();
            cur = saved;
            cur.Assign(&tmp);
        }
        state = 0;
    }
    return &cur;
}

} // namespace fn_f346547a

// 0x0030efa0 FUN_0030efa0 (42 B): matches/0x0030efa0.cpp
// sym: ?FUN_0030efa0@C_30efa0@owners@@QAEXH@Z
void owners::C_30efa0::FUN_0030efa0(hulk_intptr arg) {
    first();
    ((owners::C_30efa0*)((char*)this + 0x14))->second(((int)arg));
    value = 2;
    third();
}

namespace fn_f346547a {

// 0x0030f000 FUN_0030f000 (42 B): matches/0x0030f000.cpp
// sym: ?target@C_30f000@fn_f346547a@@QAEXH@Z
// Same code shape as 0x0030efa0 (propagated; names are from that function)
void C_30f000::target(int arg) {
    first();
    ((owners::Target_22be40 *)(((C_30f000*)((char*)this + 0x14))))->FUN_0022be40((const int *)(hulk_uintptr)(int)arg);
    value = 2;
    third();
}


// 0x0030f030 FUN_0030f030 (42 B): matches/0x0030f030.cpp
// sym: ?target@C_30f030@fn_f346547a@@QAEXH@Z
// Same code shape as 0x0030efa0 (propagated; names are from that function)
void C_30f030::target(int arg) {
    first();
    ((C_30f030*)((char*)this + 0x14))->second(arg);
    value = 2;
    third();
}


// 0x0030f070 FUN_0030f070 (47 B): matches/0x0030f070.cpp
// sym: ?Copy@Obj_30f070@fn_f346547a@@QAEPAU12@PBUBlock_30f070@2@@Z
// Same code shape as 0x00221b70 (propagated; names are from that function)
Obj_30f070* Obj_30f070::Copy(const Block_30f070* src) {
    block = *src;
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 2;
    return this;
}


// 0x0030f0a0 FUN_0030f0a0 (62 B): matches/0x0030f0a0.cpp
// sym: ?Run@Obj_30f0a0@fn_f346547a@@QAEPAV12@PAUPair_30f0a0@2@H@Z
Obj_30f0a0* Obj_30f0a0::Run(Pair_30f0a0* src, int x) {
    First();
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
    value = *src;
    flag = 1;
    return this;
}


// 0x0030f0e0 FUN_0030f0e0 (31 B): matches/0x0030f0e0.cpp
// sym: ?Run@Thing_30f0e0@fn_f346547a@@QAEXXZ
// Same code shape as 0x00221c20 (propagated; names are from that function)
void Thing_30f0e0::Run() {
    Init();
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}


// 0x0030f100 FUN_0030f100 (29 B): matches/0x0030f100.cpp
// sym: ?target@Obj_30f100@fn_f346547a@@QAEPAU12@XZ
// Same code shape as 0x00221c40 (propagated; names are from that function)
Obj_30f100* Obj_30f100::target() {
    if (state == 1) {
        sub.F(this);
        state = 0;
    }
    return this;
}


// 0x0030f120 FUN_0030f120 (29 B): matches/0x0030f120.cpp
// sym: ?Copy@C_30f120@fn_f346547a@@QAEXPAV12@@Z
// Same code shape as 0x00221c60 (propagated; names are from that function)
void C_30f120::Copy(C_30f120* src) {
    d = src->d;
    x = 2;
}

} // namespace fn_f346547a

// 0x0030f140 FUN_0030f140 (66 B): matches/0x0030f140.cpp
// sym: ?FUN_0030f140@Obj_30f140@owners@@QAEXPAU12@@Z
void owners::Obj_30f140::FUN_0030f140(owners::Obj_30f140* src) {
    a[0] = src->a[0];
    a[1] = src->a[1];
    a[2] = src->a[2];
    a[4] = src->a[4];
    a[5] = src->a[5];
    a[6] = src->a[6];
    a[8] = src->a[8];
    a[9] = src->a[9];
    a[10] = src->a[10];
    a[20] = 2;
}

namespace fn_f346547a {

// 0x0030f190 FUN_0030f190 (30 B): matches/0x0030f190.cpp
// sym: ?target@C_30f190@fn_f346547a@@QAEPAXXZ
// Same code shape as 0x00221cd0 (propagated; names are from that function)
void* C_30f190::target() {
    if (state == 2) {
        ((owners::Quat_22b370 *)&sub)->FUN_0022b370((const float *)(hulk_uintptr)(hulk_intptr)((hulk_intptr)this));
        state = 0;
    }
    return (void*)&sub;
}


// 0x0030f1b0 FUN_0030f1b0 (41 B): matches/0x0030f1b0.cpp
// sym: ?Set@Obj_30f1b0@fn_f346547a@@QAEXABUFour_30f1b0@2@@Z
// Same code shape as 0x00221cf0 (propagated; names are from that function)
void Obj_30f1b0::Set(const Four_30f1b0& p) {
    v = p;
    flag = 1;
}


// 0x0030f1e0 FUN_0030f1e0 (286 B): equivalent/0x0030f1e0.cpp
// sym: ?blend@Object@fn_f346547a@@QAEXMPAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0030f1e0 @ 0x0030f1e0
void Object::blend(float t,Object* other) {
 float one=1.0f;
 double a=one-(double)t;
 Vec3_30f1e0 v;
 Quaternion_30f1e0 result;
 volatile float sy=(float)(position.y*a);
 volatile float sz=(float)(position.z*a);
 result.x=other->position.x;
 result.y=other->position.y*t;
 result.z=other->position.z*t;
 v.x=(float)(result.x*(double)t+position.x*a);
 v.y=result.y+sy;
 v.z=result.z+sz;
 ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(Vec3_30f1e0 *)(&v));
 if(other->state==2) { ((owners::Quat_22b370 *)&(other->rotation))->FUN_0022b370((const float *)(Object *)other); other->state=0; }
 if(state==2) { ((owners::Quat_22b370 *)&rotation)->FUN_0022b370((const float *)(Object *)this); state=0; }
 ((owners::Quaternion_22b750 *)&result)->FUN_0022b750((const owners::Quaternion_22b750 *)(Quaternion_30f1e0 *)(&rotation), (const owners::Quaternion_22b750 *)(Quaternion_30f1e0 *)(&other->rotation), t);
 rotation=result;
 state=1;
}


// 0x0030f300 FUN_0030f300 (101 B): matches/0x0030f300.cpp
// sym: ?Run@Obj_30f300@fn_f346547a@@QAEXPAV12@@Z
void Obj_30f300::Run(Obj_30f300* other) {
    Obj_30f300* owner = this;
    if (owner->state == 1) {
        owner->sub.Fn(owner);
        owner->state = 0;
    }
    if (other->state == 1) {
        other->sub.Fn(other);
        other->state = 0;
    }
    Temp_30f300 t;
    t.Fn(owner, other);
    memcpy(owner, &t, 0x40);
    owner->state = 2;
}


// 0x0030f370 FUN_0030f370 (41 B): matches/0x0030f370.cpp
// sym: ?target@Obj_30f370@fn_f346547a@@QAEXXZ
// Same code shape as 0x00221eb0 (propagated; names are from that function)
void Obj_30f370::target() {
    if (state == 1) {
        sub.call(this);
        state = 0;
    }
    ((owners::Matrix_22c120 *)this)->FUN_0022c120();
    state = 2;
}


// 0x0030f3a0 FUN_0030f3a0 (33 B): matches/0x0030f3a0.cpp
// sym: ??0Obj_30f3a0@fn_f346547a@@QAE@XZ
// Same code shape as 0x00222050 (propagated; names are from that function)
Obj_30f3a0::Obj_30f3a0() {
    FUN_0022b980((void*)(this));
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}


// 0x0030f3d0 FUN_0030f3d0 (47 B): matches/0x0030f3d0.cpp
// sym: ??0Thing_30f3d0@fn_f346547a@@QAE@H@Z
Thing_30f3d0::Thing_30f3d0(int x) : Base_30f3d0() {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    int* q = &e;
    *q = 0;
    ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
}

} // namespace fn_f346547a

// 0x0030f450 FUN_0030f450 (12 B): matches/0x0030f450.cpp
// sym: ?FUN_0030f450@C_30f450@owners@@QAEHXZ
int owners::C_30f450::FUN_0030f450() {
    if (!ptr)
        return 0;
    return *(int*)((char*)ptr + 0x10);
}

namespace fn_f346547a {

// 0x0030f490 FUN_0030f490 (41 B): matches/0x0030f490.cpp
// sym: ?Get@Table@fn_f346547a@@QAEPAUElem@2@H@Z
Elem* Table::Get(int index) {
    if (index >= 0) {
        hulk_intptr count = (hulk_intptr)info;
        if (count)
            count = ((Info*)count)->count;
        if (index < count)
            return &entries[index];
    }
    return 0;
}

} // namespace fn_f346547a

// 0x0030f510 FUN_0030f510 (314 B): matches/0x0030f510.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?run@Skeleton@fn_0030f510@@QAEXPAUOut_30f510@2@_N@Z
namespace fn_0030f510 {
// FUN_0030f510 @ 0x0030f510
struct Mat_30f510 {
    float m[16];
};

struct Pose {
    Mat_30f510* FUN_0030f100();
};

struct Item_30f510 {
    Pose* FUN_0030ef30();
    Pose* FUN_0030edf0();
    char pad[0xc0];
};

struct Group_30f510 {
    char pad[0x10];
    int count;
};

struct Out_30f510 {
    char pad[8];
    Group_30f510* group;
    char pad2[8];
    Mat_30f510* dstA;
    char pad3[4];
    Mat_30f510* dstB;
    char flag20;
    char flag21;
    char flag22;
    char flag23;
};

class Skeleton {
public:
    void run(Out_30f510* out, bool both);
    char p0[8];
    Group_30f510* group;
    Item_30f510* items;
};

void Skeleton::run(Out_30f510* out, bool both)
{
    if (out->group != group)
        return;

    int n = group == 0 ? 0 : group->count;
    if (both) {
        for (int i = 0; i < n; i++) {
            Item_30f510* it = &items[i];
            out->dstA[i] = *it->FUN_0030ef30()->FUN_0030f100();
            out->dstB[i] = *it->FUN_0030edf0()->FUN_0030f100();
            out->flag22 = 0;
            out->flag23 = 0;
            out->flag20 = 0;
            out->flag21 = 0;
        }
    } else {
        for (int i = 0; i < n; i++)
            out->dstB[i] = *items[i].FUN_0030edf0()->FUN_0030f100();
        out->flag22 = 0;
        out->flag23 = 0;
        out->flag20 = 0;
        out->flag21 = 0;
    }
}
} // namespace fn_0030f510


// 0x0030f650 FUN_0030f650 (55 B): matches/0x0030f650.cpp [wrapped: lost its match in the tree (codegen differs (11 of 27 instructions))]
// sym: ?Fn@Obj@fn_0030f650@@QAEXXZ
namespace fn_0030f650 {
struct Elem {
    char pad[0xc0];
    void Fn();
};
struct Count {
    char pad[0x10];
    int n;
};
class Obj {
    char pad[8];
    Count* count;
    Elem* elems;

  public:
    void Fn();
};
void Obj::Fn() {
    int n;
    if (count == 0)
        n = 0;
    else
        n = count->n;
    for (int i = 0; i < n; ++i)
        elems[i].Fn();
}
} // namespace fn_0030f650


// 0x0030f6b0 FUN_0030f6b0 (239 B): equivalent/0x0030f6b0.cpp [wrapped: conflict: physics::Pose]
// sym: ??0Pose@physics@fn_0030f6b0@@QAE@PAUSource_30f6b0@2@@Z
namespace fn_0030f6b0 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 12/12)
// FUN_0030f6b0 @ 0x0030f6b0
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
void __cdecl FUN_0030eba0();
void __stdcall FUN_00011520(void*, unsigned int, int, void (__cdecl*)());
struct Node {
 int index; Node* parent; int unused; int count; char pad[176];
 void FUN_0030ec20(int);
 void FUN_0030ec70(Node*);
};
struct Source_30f6b0 {
 virtual void retain();
 char pad[12]; int count; char pad2[20]; unsigned short* parents;
};
namespace physics { struct Pose {
 virtual void slot0();
 int state; Source_30f6b0* source; Node* nodes;
 Pose(Source_30f6b0*);
}; }
physics::Pose::Pose(Source_30f6b0* s) {
 state=0;
 if (!s) {source=0;nodes=0;return;}
 source=s; source->retain();
 int n=source->count;
 unsigned int* memory=(unsigned int*)FUN_0008d6d0((unsigned int)n*192+4);
 Node* array=0;
 if(memory) {memory[0]=n;array=(Node*)(memory+1);FUN_00011520(array,192,n,&FUN_0030eba0);}
 nodes=array;
 for(int i=1;i<n;++i) {
 nodes[i].index=i;
 Node* parent=&nodes[source->parents[i]];
 nodes[i].parent=parent;
 parent->FUN_0030ec20(parent->count+1);
 }
 for(int j=1;j<n;++j) {
 Node* child=&nodes[j];
 Node* parent=&nodes[source->parents[j]];
 parent->FUN_0030ec70(child);
 }
}
} // namespace fn_0030f6b0

namespace fn_f346547a {

// 0x0030f810 FUN_0030f810 (96 B): matches/0x0030f810.cpp
// sym: ??1Pose_30f810@fn_f346547a@@QAE@XZ
Pose_30f810::~Pose_30f810() throw() {
    Elem_30f810* a = arr;
    vptr = vP;
    if (a) {
        int n = ((int*)a)[-1];
        Elem_30f810* e = a + n;
        while (--n >= 0) {
            e--;
            e->Fini();
        }
        thunk_FUN_00267090((int*)a - 1);
    }
    if (ref)
        ref->release();
    vptr = vR;
}

} // namespace fn_f346547a

// 0x0030fc00 physics::Pose::vfunc_2 (30 B): matches/0x0030fc00.cpp
// sym: ??_GPose@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::Pose::~Pose() {}


// 0x0030fc50 FUN_0030fc50 (36 B): matches/0x0030fc50.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Make@Pose@fn_0030fc50@@QAEPAV12@H@Z
namespace fn_0030fc50 {
extern "C" char DAT_0043211c[];
class Pose {
  public:
    void* vf;
    int a, b, c;
    void Init(int);
    Pose* Make(int);
};
Pose* Pose::Make(int arg) {
    a = 0;
    b = 0;
    c = 0;
    vf = (void*)((hulk_intptr)DAT_0043211c);
    Init(arg);
    return this;
}
} // namespace fn_0030fc50

namespace fn_f346547a {

// 0x0030fc90 FUN_0030fc90 (114 B): matches/0x0030fc90.cpp
// sym: ?V@PoseEngine_30fc90@fn_f346547a@@UAEXXZ
void PoseEngine_30fc90::V() {
    int i = count - 1;
    *(void**)this = &vt1_30fc90;
    if (i >= 0) {
        do {
            int j = ((int*)arr)[i] - 1;
            while (j >= 0) {
                Ref_30fc90* r = rows[i][j];
                r->B();
                --j;
            }
            drop(rows[i]);
            --i;
        } while (i >= 0);
    }
    drop(rows);
    drop(arr);
    obj8->B();
    objc->B();
    *(void**)this = &vt2_30fc90;
}


// 0x0030fda0 FUN_0030fda0 (241 B): equivalent/0x0030fda0.cpp
// sym: ?insert@Container_30fda0@fn_f346547a@@QAE_NHPAUItem_30fda0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 456 inputs, branch coverage 17/18, incomplete)
// FUN_0030fda0 @ 0x0030fda0
bool Container_30fda0::insert(int group, Item_30fda0* item) {
 if (!item || group < 0 || group >= groupCount || counts[group] >= capacity) return false;
 int first = item->key1();
 int second = item->key2();
 int pos = 0;
 while (pos < counts[group]) {
  Item_30fda0* current = groups[group][pos];
  int key = current->key1();
  if (first < key) break;
  if (first == key && second < current->key2()) break;
  ++pos;
 }
 Item_30fda0** at = groups[group] + pos;
 memmove(at + 1, at, (counts[group] - pos) * 4);
 ++counts[group];
 groups[group][pos] = item;
 groups[group][pos]->retain();
 return true;
}


// 0x0030fea0 FUN_0030fea0 (117 B): matches/0x0030fea0.cpp
// sym: ?Remove@Container_30fea0@fn_f346547a@@QAE_NHH@Z
bool Container_30fea0::Remove(int i, int j) {
    if (i < 0 || i >= count)
        return false;
    if (j < 0 || j >= counts[i])
        return false;
    items[i][j]->B();
    --counts[i];
    memmove(&items[i][j], &items[i][j + 1], (counts[i] - j) * 4);
    return true;
}


// 0x0030ff20 FUN_0030ff20 (85 B): equivalent/0x0030ff20.cpp
// sym: ?FUN_0030ff20@Table@fn_f346547a@@QAEEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_0030ff20 @ 0x0030ff20
unsigned char Table::FUN_0030ff20(int index, int value) { if (index < 0 || index >= count) return FUN_0030fea0(index, 0); int n = sizes[index]; if (n > 0) { int *list = items[index]; for (int i = 0; i < n; ++i) if (list[i] == value) return FUN_0030fea0(index, i); } return 0; }


// 0x0030ff80 FUN_0030ff80 (44 B): matches/0x0030ff80.cpp
// sym: ?target@C_30ff80@fn_f346547a@@QAEXD@Z
void C_30ff80::target(char b) {
    ((Pose_nv_30ff80*)(((physics::Pose*)(mc))))->f650();
    if (b) {
        ((Pose_nv_30ff80*)(((physics::Pose*)(mc))))->f4c0();
        return;
    }
    ((Pose_nv_30ff80*)(((physics::Pose*)(mc))))->fa10(m8);
}


// 0x0030ffb0 FUN_0030ffb0 (84 B): matches/0x0030ffb0.cpp
// sym: ?run@Container_30ffb0@fn_f346547a@@QAEXHPAX@Z
void Container_30ffb0::run(int index, void* arg) {
    if (index < 0 || index >= limit)
        return;
    int i = 0;
    if (counts[index] <= 0)
        return;
    do {
        if (*((char*)items[index][i] + 16))
            items[index][i]->invoke(arg);
        ++i;
    } while (i < counts[index]);
}


// 0x00310010 FUN_00310010 (83 B): matches/0x00310010.cpp
// sym: ?Run@Holder@fn_f346547a@@QAEXH@Z
void Holder::Run(int index) {
    if (index >= 0 && index < count) {
        for (int i = 0; i < sizes[index]; ++i) {
            if (items[index][i]->active)
                items[index][i]->Act(context);
        }
    }
}


// 0x00310070 FUN_00310070 (15 B): matches/0x00310070.cpp
// sym: ?FUN_00310070@fn_f346547a@@YIXPAUA_310070@1@@Z
void __fastcall FUN_00310070(A_310070* self) {
    self->b->F(self->a, 0);
}


// 0x00310080 FUN_00310080 (174 B): matches/0x00310080.cpp
// sym: ?ctor@PoseEngine_310080@fn_f346547a@@QAEPAV12@PAVRes_310080@2@HH@Z
PoseEngine_310080* PoseEngine_310080::ctor(Res_310080* a0, int a1, int a2) {
    m4 = 0;
    vptr = g_vftable_310080;
    m10 = a1;
    m14 = a2;
    physics::Pose* h = (physics::Pose*)operator new(0x10);
    if (h)
        h = ((Pose_nv_310080*)(((physics::Pose*)(h))))->Init(a0);
    else
        h = 0;
    mc = h;
    h->vfunc_0();
    m8 = a0;
    a0->F0();
    m18 = (int**)operator new[](m10 * 4);
    m1c = (int**)operator new[](m10 * 4);
    for (int i = 0; i < m10; i++) {
        m18[i] = 0;
        m1c[i] = (int*)operator new[](m14 * 4);
    }
    return this;
}

} // namespace fn_f346547a
