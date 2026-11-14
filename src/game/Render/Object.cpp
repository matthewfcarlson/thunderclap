// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001c49c0..0x001c5ae0 (kind game, layer game, confidence high), dominant class Render::Object
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/Render.h"
#include "gen/Render.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f4431f34 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f4431f34 {} using namespace fn_f4431f34;
namespace fn_f4431f34 {
void thunk_delete_0008d330(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
namespace fn_f4431f34 { extern "C" char DAT_003f6098[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_f4431f34 {
void *thunk_FUN_0008d690(unsigned int size);
class Channel_1c49c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetTag(unsigned int tag, int value);
};
struct Shader_nv_1c49c0 {
    pure3d::Shader *FUN_0028edb0();
};
class Reader_1c49c0 {
public:
    Reader_1c49c0 *FUN_001c49c0();

    int f00;
    int f04;
    int f08;
    char f0c;
    pure3d::Shader *stream;     // +0x10
    char f14;
    int f18;
    int f1c;
    int f20;
    char f24;
    int f28;
    int f2c;
    int f30;
    char f34;
};
struct Obj_1c4af0 {
    char pad[8];
    int a;
    int b;
};
struct Result { unsigned int a,b,c,d; };
struct Locator_1c4d30 { void FUN_001c4b50(Result*); void FUN_001c4d30(Result* out); };
class Obj_1c4d80 {
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
    virtual void f10(void*);
};
class Owner_1c4d80 {
  public:
    char pad[0x14];
    Obj_1c4d80* a;
    void* b;
    void run();
};
struct S_1c4db0 {
    unsigned int x[16];
};
class Object {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(unsigned int, unsigned int, unsigned int);
    virtual void g();
    virtual void h();
    virtual void i();
    char pad[0x2c];
    S_1c4db0 data;
};
class ResultThing {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();
};
struct B_1c4ea0 {
    void Fn_0027af70(int);
};
struct A_1c4ea0 {
    char pad[8];
    B_1c4ea0 b;
    void Forward(int);
};
extern void* hulk_at_004218c8[];
class Ref_1c4fb0 {
  public:
    virtual void F0();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int);
};
class GameDrawableInfo_1c4fb0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_1c4fb0 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_1c4fb0*) throw();
class Object_1c4fb0 : public GameDrawableInfo_1c4fb0 {
  public:
    char pad[4];
    Sub_1c4fb0 sub;
    char p2[7];
    Ref_1c4fb0* m10;
    Ref_1c4fb0* m14;
    Ref_1c4fb0* m18;
    ~Object_1c4fb0() throw();
};
class Item {
  public:
    virtual void f();
    virtual void FUN_00000004();
    char _m_pad_4[0x4];
    void Fng_001c4ea0(int);
};
struct Observer { virtual void FUN_00000000(); virtual void FUN_00000004(); virtual void FUN_00000008(); virtual void FUN_0000000c(); virtual void FUN_00000010(); virtual void FUN_00000014(); virtual void FUN_00000018(); virtual void FUN_0000001c(); virtual void FUN_00000020(); virtual void FUN_00000024(); virtual void FUN_00000028(Item *); };
class Item_1c5050 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_1c5050 {
  public:
    char pad[0x14];
    Item_1c5050* item;
    void Set(Item_1c5050* p);
};
struct Object_1c5130 {
  char pad0[0x8c]; unsigned char dirty;
  char pad1[3];
  float rate;
  float level;
  float invDuration;
  void FUN_001c5130(float target, float duration);
};
struct Data_1c51b0 {
    char pad[0x74];
    void* field74;
};
struct Item_1c51b0 {
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
    virtual void* v15();
};
struct Render_1c51b0 {
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
    virtual void v15(int);
    virtual int v16(int);
    virtual void v17(int, void*);
};
struct Parent_1c51b0 {
    char pad[0x23];
    unsigned char flag;
};
struct Object_1c51b0;
struct Context {
    void FUN_001c25c0(Item_1c51b0*, Object_1c51b0*, float);
};
struct Object_1c51b0 {
    char p0[0x10];
    Item_1c51b0* fallback;
    char p14[4];
    Parent_1c51b0* parent;
    Item_1c51b0* item;
    char p20[2];
    unsigned char enabled;
    char p23[0x0d];
    char state[0x50];
    float a;
    char p84[0x0c];
    float b;
    int target(Context* context);
};
struct Clock_1c52f0 {
    float FUN_00085f80();
};
} // namespace fn_f4431f34
struct World {
    char pad0[0x58];
    Clock_1c52f0 *clock;
};
namespace fn_f4431f34 {
struct ThisCall_001c5d30 {
    void FUN_001c5d30();
};
extern void thunk_FUN_00267090(CCollisionAction*);
class Store {
  public:
    virtual void* Fnf_001c57c0(char);
    void Cleanup2_001c7500();
    ~Store();
    int mData;
};
class StoreBase_1c56c0 {
  public:
    virtual void f0();
    virtual int f1(int);
    virtual void f2();
};
class Object_1c56c0 {};
class Obj_1c56d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c(int);
};
class Arg {
  public:
    int convert_001c5b70();
};
class X {
  public:
    void Fng_001c7870(int, Arg*);
    void f(Arg*);
};
struct StoreBase;
int __fastcall Helper_001c5b70(StoreBase* p);
class StoreBase_1c5790 {
  public:
    virtual void x();
    char pad[0x118];
    unsigned char flag;
};
class ObjectTemplate_1c5790 {
  public:
    void Fnf_001c5d30();
};
void __cdecl ReleaseTemplate_0008d330(ObjectTemplate_1c5790*);
extern int hulk_at_00421914;
struct Store_1c57c0 {
    void* m_vptr;
    void base2_dtor_001c7500();
    void* scalar_dtor(unsigned char flags);
};
extern int hulk_at_00421924;
struct Store_1c57f0 {
    void* m_vptr;
    void base2_dtor_001c7500();
    void* scalar_dtor(unsigned char flags);
};
extern "C" char DAT_00421914[];
extern "C" char DAT_00421924[];
extern "C" char DAT_00421934[];
typedef unsigned int u32_1c5840;
struct StoreBase {
    char pad[0x120];
    void Init_001c77e0(unsigned int, int);
};
struct ObjectManager {
    hulk_uintptr vft;
    char pad4[4];
    StoreBase objects;
    StoreBase templates;
    u32_1c5840 value;
};
typedef unsigned int u32_1c5900;
struct Obj_1c5900 {
    virtual void f();
    char pad[4];
    Obj_1c5900* Create_001c5c20(u32_1c5900);
    bool Check_001c4af0();
};
struct Finder_1c5900 {
    Obj_1c5900* Find_001c75e0(u32_1c5900);
};
struct Registry_1c5900 {
    void Register_001c7870(void*, Obj_1c5900*);
};
struct Manager_1c5900 {
    char p0[8];
    Registry_1c5900 registry;
    char p1[0x128 - 8 - sizeof(Registry_1c5900)];
    Finder_1c5900 finder;
    char p2[0x248 - 0x128 - sizeof(Finder_1c5900)];
    Obj_1c5900* saved;
    Obj_1c5900* Run(u32_1c5900, u32_1c5900);
};
class Object_1c5960 {
public:
    virtual void v0();
    char pad4[4];
    char sub8[1];
    char pad9[0xb0 - 9];
    Object_1c5960 *FUN_001c4eb0(int a, int b);
    char FUN_001c4af0();
};
class SubList {
public:
    void FUN_001c7870(void *a, Object_1c5960 *b);
};
class Mgr_1c5960 {
public:
    char pad0[8];
    SubList list;
    char pad_c[0x248 - 8 - 1];
    Object_1c5960 *f248;
    Object_1c5960 *FUN_001c5960(int a, int b);
};
struct A_1c59d0 {
    char pad[8];
};
struct B_1c59d0 {
    int FnF_001c75e0(int);
};
struct X_1c59d0 : A_1c59d0, B_1c59d0 {
    int G(hulk_intptr);
};
struct Elem_1c59e0 {
    void Fnf_001c52f0(int);
};
class Ref_1c5a20 {
  public:
    virtual void f0();
    virtual void Release();
};
class Sub_1c5a20 {
  public:
    Ref_1c5a20* Get_001c75e0(int);
    void Other_001c7550(int);
    char pad[0x240];
};
class Owner_1c5a20 {
  public:
    char pad0[8];
    Sub_1c5a20 sub;
    Ref_1c5a20* m248;
    void Target(int);
};
struct Object_nv_1c5a70 {
    void Update_001c4ea0(int);
};
class Container {
  public:
    Render::Object* Find_001c75e0(int);
    void Remove_001c7550(int);
    void Erase_001c7870(void*, Render::Object*);
};
class Owner {
  public:
    char _m_pad_0[0x8];
    Container items;
    char _m_pad_9[0x7];
    Observer *observer;
    char _m_pad_14[0x4];
    Item *item;
    void FUN_001c5010(Item *value);
    void Act(int, int);
};
class Obj {
    char pad[8];

  public:
    void Fnh_001c7870(Item*, void*);
    void fn(Item*, int);
};


// 0x001c49c0 FUN_001c49c0 (123 B): equivalent/0x001c49c0.cpp
// sym: ?FUN_001c49c0@Reader_1c49c0@fn_f4431f34@@QAEPAV12@XZ @62436bd00f45 @w519b552cd43b
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 6/6)
// FUN_001c49c0 @ 0x001c49c0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
Reader_1c49c0 *Reader_1c49c0::FUN_001c49c0() {
    f00 = 0;
    f04 = 0;
    f08 = 0;
    f0c = 0;
    stream = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f34 = 0;

    pure3d::Shader *created = 0;
    void *mem = thunk_FUN_0008d690(0x20);
    if (mem != 0) {
        created = ((Shader_nv_1c49c0*)(((pure3d::Shader *)mem)))->FUN_0028edb0();
    }
    if (created != 0) {
        created->vfunc_0();
    }
    if (stream != 0) {
        stream->vfunc_1();
    }
    stream = created;
    (*(Channel_1c49c0 * *)&created->f_10)->SetTag(0x444d4c42, 1);
    return this;
}

} // namespace fn_f4431f34

// 0x001c4ac0 FUN_001c4ac0 (33 B): matches/0x001c4ac0.cpp
// sym: ?FUN_001c4ac0@Obj_1c4ac0@owners@@QAEXPAII@Z
void owners::Obj_1c4ac0::FUN_001c4ac0(unsigned* p, unsigned v) {
    a = *p;
    b = v;
    unsigned* q = &b;
    c = *q;
}

namespace fn_f4431f34 {

// 0x001c4af0 FUN_001c4af0 (31 B): matches/0x001c4af0.cpp
// sym: ?target@fn_f4431f34@@YIHPAUObj_1c4af0@1@@Z
int __fastcall target(Obj_1c4af0* p) {
    if (p->a == (*(int*)&DAT_004e2330) && p->b == (*(int*)&DAT_004e2334))
        return 1;
    return 0;
}

} // namespace fn_f4431f34

// 0x001c4b20 FUN_001c4b20 (36 B): matches/0x001c4b20.cpp
// sym: ?FUN_001c4b20@Target_1c4b20@owners@@QAEXXZ
void owners::Target_1c4b20::FUN_001c4b20() {
    a80 = a84;
    a88 = 0;
    ++aac;
}


// 0x001c4b50 FUN_001c4b50 (480 B): equivalent/0x001c4b50.cpp [wrapped: conflict: FUN_0027b020]
// sym: ?FUN_001c4b50@Locator@fn_001c4b50@@QAEXPAUOut_1c4b50@2@@Z @0410547adce6 @wf4f66b38bd67
namespace fn_001c4b50 {
// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 38/38; --wine 668 inputs)
// FUN_001c4b50 @ 0x001c4b50

struct V3_1c4b50 {
    float x, y, z;
};

struct Out_1c4b50 : V3_1c4b50 {
    float w;
};

struct Mat_1c4b50 {
    float m[16];
};

struct Mgr_1c4b50 {
    char pad0[0xc];
    unsigned int count;
    char pad10[0x1c - 0x10];
    Mat_1c4b50 *elems;
    char pad20[3];
    char flag23;
    unsigned int FUN_002843a0(int lo, int hi);
};

struct HashPair {
    char pad0[8];
    unsigned int lo;
    unsigned int hi;
};

struct Info_1c4b50 {
    char pad0[0x84];
    char flag84;
    char flag85;
};

class Body_1c4b50 {
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
    virtual Mat_1c4b50 *v15();
    char pad4[0xec - 4];
    HashPair *hash;
    char FUN_001d64c0();
};

extern "C++" __declspec(nothrow) unsigned __int64 __cdecl FUN_0027b020(const char *name) throw();
extern "C++" __declspec(nothrow) unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

class Locator {
public:
    char pad0[0x18];
    Mgr_1c4b50 *mgr;
    Body_1c4b50 *body;
    char pad20[2];
    char hasBody;
    char pad23[0x30 - 0x23];
    Mat_1c4b50 mat30;
    V3_1c4b50 vec70;
    float f7c;

    void FUN_001c4b50(Out_1c4b50 *out);
};

void Locator::FUN_001c4b50(Out_1c4b50 *out)
{
    if (!out)
        return;
    out->w = f7c;
    if (!mgr || mgr->count == 0) {
        ((owners::Mat_22c2b0 *)&mat30)->FUN_0022c2b0((float *)(const V3_1c4b50 *)(&vec70), (float *)(V3_1c4b50 *)out);
        return;
    }
    static unsigned __int64 cowHash = FUN_0027b020("cow_male_cow_male");
    bool match = false;
    if (hasBody && body) {
        if (body->FUN_001d64c0()) {
            HashPair *h = body->hash;
            if (h->lo == (unsigned int)cowHash && h->hi == (unsigned int)(cowHash >> 32))
                match = true;
            else
                match = false;
        } else {
            match = false;
        }
    }
    Mgr_1c4b50 *m = mgr;
    unsigned __int64 id = FUN_002672f0((*(const char**)&DAT_004c5188), 0, 0);
    unsigned int idx = m->FUN_002843a0((int)id, (int)(id >> 32));
    if (idx != 0xffff && !match) {
        Mat_1c4b50 *e = &mgr->elems[idx];
        const V3_1c4b50 *p = (const V3_1c4b50 *)&e->m[12];
        out->x = p->x;
        out->y = p->y;
        out->z = p->z;
        if (mgr->flag23)
            ((owners::V3_110d0 *)out)->FUN_000110d0((owners::V3_110d0 *)(const V3_1c4b50 *)((const V3_1c4b50 *)&mat30.m[12]));
        return;
    }
    V3_1c4b50 v;
    if (mgr->flag23) {
        ((owners::Mat_22c2b0 *)&mat30)->FUN_0022c2b0((float *)(const V3_1c4b50 *)(&vec70), (float *)(V3_1c4b50 *)(&v));
    } else {
        v.x = vec70.x;
        v.y = vec70.y;
        v.z = vec70.z;
    }
    if (hasBody && body) {
        Info_1c4b50 *info = ((Info_1c4b50 *)((owners::C_1d72e0 *)body)->FUN_001d72e0());
        if (!info || !((Info_1c4b50 *)((owners::C_1d72e0 *)body)->FUN_001d72e0())->flag84) {
            Info_1c4b50 *info2 = ((Info_1c4b50 *)((owners::C_1d72e0 *)body)->FUN_001d72e0());
            if (info2 && ((Info_1c4b50 *)((owners::C_1d72e0 *)body)->FUN_001d72e0())->flag85) {
                Mat_1c4b50 *bm = body->v15();
                ((owners::C_284820 *)mgr)->FUN_00284820((hulk_intptr)(Mat_1c4b50 *)bm);
            } else {
                ((owners::Mat_22c2b0 *)(body->v15()))->FUN_0022c2b0((float *)(const V3_1c4b50 *)(&vec70), (float *)(V3_1c4b50 *)out);
                return;
            }
        }
    }
    ((owners::Mat_22c2b0 *)(mgr->elems))->FUN_0022c2b0((float *)(const V3_1c4b50 *)(&v), (float *)(V3_1c4b50 *)out);
}
} // namespace fn_001c4b50

namespace fn_f4431f34 {

// 0x001c4d30 FUN_001c4d30 (43 B): equivalent/0x001c4d30.cpp
// sym: ?FUN_001c4d30@Locator_1c4d30@fn_f4431f34@@QAEXPAUResult@2@@Z @ba73dc1d3343 @w4db806125b5f
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_001c4d30 @ 0x001c4d30
void Locator_1c4d30::FUN_001c4d30(Result* out) { Result temp; FUN_001c4b50(&temp); out->a=temp.a; out->b=temp.b; out->c=temp.c; }

} // namespace fn_f4431f34

// 0x001c4d60 FUN_001c4d60 (21 B): matches/0x001c4d60.cpp
// sym: ?FUN_001c4d60@X_1c4d60@owners@@QAEXPAI@Z
void owners::X_1c4d60::FUN_001c4d60(unsigned int* p) {
    memcpy(data, p, 64);
}

namespace fn_f4431f34 {

// 0x001c4d80 FUN_001c4d80 (24 B): matches/0x001c4d80.cpp
// sym: ?run@Owner_1c4d80@fn_f4431f34@@QAEXXZ
void Owner_1c4d80::run() {
    if (a && b)
        a->f10(b);
}

} // namespace fn_f4431f34

// 0x001c4da0 Render::Object::vfunc_4 (4 B): matches/0x001c4da0.cpp
// sym: ?vfunc_4@Object@Render@@UAEPAXXZ
// Same code shape as 0x00196630 (propagated; names are from that function)
void* Render::Object::vfunc_4() {
    return (void*)((Render::Object*)((char*)this + 0x60));
}

namespace fn_f4431f34 {

// 0x001c4db0 Render::Object::vfunc_5 (66 B): matches/0x001c4db0.cpp
// sym: ?f@Object@fn_f4431f34@@UAEXIII@Z
void Object::f(unsigned int a, unsigned int b, unsigned int c) {
    S_1c4db0 t;
    t = data;
    t.x[12] = a;
    t.x[13] = b;
    t.x[14] = c;
    data = t;
}

} // namespace fn_f4431f34

// 0x001c4e00 Render::Object::vfunc_6 (21 B): matches/0x001c4e00.cpp
// sym: ?vfunc_6@Object@Render@@UAEXHHHHHHHHHHHHHHHH@Z
void Render::Object::vfunc_6(int a0, int , int , int , int , int , int , int , int , int , int , int , int , int , int , int ) {
    memcpy((char*)this + 0x30, &a0, 0x40);
}


// 0x001c4e20 Render::Object::vfunc_7 (4 B): matches/0x001c4e20.cpp
// sym: ?vfunc_7@Object@Render@@UAEPAXXZ
void* Render::Object::vfunc_7() {
    return (void*)((Render::Object*)((char*)this + 0x30));
}


// 0x001c4e30 Render::Object::vfunc_8 (25 B): matches/0x001c4e30.cpp
// sym: ?vfunc_8@Object@Render@@UAEPAXXZ
void* Render::Object::vfunc_8() {
    if ((*(ResultThing * *)&this->f_10)->f5() == 4)
        return (void*)((*(ResultThing * *)&this->f_10));
    return (void*)(0);
}

namespace fn_f4431f34 {

// 0x001c4ea0 FUN_001c4ea0 (8 B): matches/0x001c4ea0.cpp
// sym: ?Forward@A_1c4ea0@fn_f4431f34@@QAEXH@Z
void A_1c4ea0::Forward(int a0) {
    b.Fn_0027af70(a0);
}

} // namespace fn_f4431f34

// 0x001c4eb0 FUN_001c4eb0 (252 B): equivalent/0x001c4eb0.cpp [wrapped: conflict: Render::Object]
// sym: ??0Object@Render@fn_001c4eb0@@QAE@PAXPAUResource_1c4eb0@2@@Z @713095b83149 @wb79ab23574a4
namespace fn_001c4eb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c4eb0 @ 0x001c4eb0

struct Resource_1c4eb0 {
 virtual void AddRef(); virtual void Release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual Resource_1c4eb0* GetResource();
 char padding[0x28]; unsigned int values[4];
};
struct Handle_1c4eb0 { char data[8]; void FUN_0027af30(void*); };
struct Matrix { char data[0x40]; void FUN_0022b980(); };
namespace Render {
struct Object {
 virtual void slot0_00018b30();
 unsigned int field4; Handle_1c4eb0 handle;
 Resource_1c4eb0* primary; unsigned int field14; Resource_1c4eb0* secondary; unsigned int field1c;
 unsigned char flags[4]; char padding24[12]; Matrix matrix;
 unsigned int values[4]; unsigned int field80, field84, field88;
 unsigned char field8c; char padding8d[3]; unsigned int field90, field94, field98;
 char padding9c[4]; unsigned int fielda0, fielda4;
 unsigned char fielda8, fielda9; char paddingaa[2]; unsigned int id;
 Object(void* arg, Resource_1c4eb0* source);
};
Object::Object(void* arg, Resource_1c4eb0* source) {
 field4=0; handle.FUN_0027af30(arg);
 primary=0; secondary=0;
 flags[0]=0; flags[1]=0; flags[2]=0; flags[3]=0;
 field80=0; field84=0; field88=0; field8c=0;
 field90=0; field94=0; field98=0; fielda0=0; fielda4=0;
 fielda8=1; fielda9=0; id=0;
 matrix.FUN_0022b980();
 volatile bool present=source!=0;
 values[0]=source->values[0]; values[1]=source->values[1]; values[2]=source->values[2]; values[3]=source->values[3];
 field1c=0; field14=0; secondary=0; primary=0;
 if(present) {
 source->AddRef();
 if(primary) primary->Release();
 primary=source;
 Resource_1c4eb0* other=source->GetResource();
 if(other) other->AddRef();
 if(secondary) secondary->Release();
 secondary=other;
 }
 unsigned int next=DAT_004e234c;
 id=next;
 DAT_004e234c=next+1;
}
}
} // namespace fn_001c4eb0

namespace fn_f4431f34 {

// 0x001c4fb0 FUN_001c4fb0 (96 B): matches/0x001c4fb0.cpp
// sym: ??1Object_1c4fb0@fn_f4431f34@@QAE@XZ
Object_1c4fb0::~Object_1c4fb0() throw() {
    vptr = hulk_at_004218c8;
    if (m14)
        m14->V10(0);
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    FUN_0027af50(&sub);
    vptr = ((void**)DAT_003f6098);
}


// 0x001c5010 FUN_001c5010 (53 B): equivalent/0x001c5010.cpp
// sym: ?FUN_001c5010@Owner@fn_f4431f34@@QAEXPAVItem@2@@Z @e741a8fe166d @w7a7c72a5f3c7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c5010 @ 0x001c5010
void Owner::FUN_001c5010(Item *value) { if (value) value->f(); if (item) item->FUN_00000004(); item = value; if (observer) observer->FUN_00000028(value); }


// 0x001c5050 FUN_001c5050 (38 B): matches/0x001c5050.cpp
// sym: ?Set@Owner_1c5050@fn_f4431f34@@QAEXPAVItem_1c5050@2@@Z
void Owner_1c5050::Set(Item_1c5050* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}

} // namespace fn_f4431f34

// 0x001c5080 FUN_001c5080 (166 B): matches/0x001c5080.cpp
// sym: ?FUN_001c5080@Blend_1c5080@owners@@QAEXMM@Z
// FUN_001c5080 @ 0x001c5080
void owners::Blend_1c5080::FUN_001c5080(float input, float duration)
{
    float v;
    if (input >= 0.0f && input <= 1.0f)
        v = input;
    else if (input > 1.0f)
        v = 1.0f;
    else
        v = 0.0f;
    value = v;
    if (duration <= 0.0f)
        held = v;
    if (held == v) {
        rate = 0.0f;
    } else {
        float inv = 1.0f / duration;
        rate = inv;
        if (v < held)
            rate = -inv;
    }
}

namespace fn_f4431f34 {

// 0x001c5130 FUN_001c5130 (127 B): equivalent/0x001c5130.cpp
// sym: ?FUN_001c5130@Object_1c5130@fn_f4431f34@@QAEXMM@Z @dbe2fc02addc @w2c50a6aad2d9
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001c5130 @ 0x001c5130
void Object_1c5130::FUN_001c5130(float target, float duration) {
  dirty = 1;
  float v;
  if (0.0f <= target && target <= 1.0f) v = target;
  else if (target > 1.0f) v = 1.0f;
  else v = 0.0f;
  level = v;
  if (!(duration <= 0.0f)) {
    invDuration = 1.0f / duration;
  } else {
    rate = v;
    invDuration = 0.0f;
  }
}


// 0x001c51b0 FUN_001c51b0 (256 B): matches/0x001c51b0.cpp
// sym: ?target@Object_1c51b0@fn_f4431f34@@QAEHPAUContext@2@@Z
int Object_1c51b0::target(Context* context) {
    (*(*(Render_1c51b0***)&DAT_0052c2ac))->v15(0);
    if (!parent || parent->flag)
        (*(*(Render_1c51b0***)&DAT_0052c2ac))->v17(0, state);
    if (enabled && item) {
        if (!((Data_1c51b0 *)((owners::C_1d72e0 *)item)->FUN_001d72e0()) || !((Data_1c51b0 *)((owners::C_1d72e0 *)item)->FUN_001d72e0())->field74) {
            void* value = item->v15();
            (*(*(Render_1c51b0***)&DAT_0052c2ac))->v17(0, value);
        }
        float value = a < b ? b : a;
        context->FUN_001c25c0(item, this, value);
    } else {
        float value = a < b ? b : a;
        context->FUN_001c25c0(fallback, this, value);
    }
    return (*(*(Render_1c51b0***)&DAT_0052c2ac))->v16(0);
}

} // namespace fn_f4431f34

// 0x001c52d0 Render::Object::vfunc_2 (30 B): matches/0x001c52d0.cpp
// sym: ??_GObject@Render@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
Render::Object::~Object() {}


// 0x001c52f0 FUN_001c52f0 (354 B): matches/0x001c52f0.cpp
// sym: ?FUN_001c52f0@Blender_1c52f0@owners@@QAEXM@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_001c52f0 @ 0x001c52f0
void owners::Blender_1c52f0::FUN_001c52f0(float unused)
{
    hulk_freg dt = DAT_004dd700->clock->FUN_00085f80();
    if (!(dt < 0.1f))
        dt = 0.1f;

    if (accel != 0.0f) {
        hulk_freg v = dt * accel + value;
        value = v;
        if ((accel > 0.0f && v >= limit) || (accel < 0.0f && v <= limit)) {
            value = limit;
            accel = 0.0f;
        }
    }

    if (!fresh)
        target = 0.0f;
    fresh = 0;

    if (current != target) {
        hulk_freg s = dt * rate;
        if (!(s < 1.0f))
            s = 1.0f;
        hulk_freg c = s * (target - current) + current;
        current = c;
        union { float f; unsigned int u; } d;
        d.f = c - target;
        d.u &= 0x7fffffff;
        if (d.f < 0.00392156886f)
            current = target;
    }

    if (timer > 0.0f)
        timer = timer - dt;
}


// 0x001c5460 Render::Object::vfunc_3 (343 B): equivalent/0x001c5460.cpp [wrapped: conflict: Render::Object]
// sym: ?vfunc_3@Object@Render@fn_001c5460@@UAEXPAVRenderer_1c5460@3@H@Z @e46ed971f44d @w78986fabd616
namespace fn_001c5460 {
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 30/30)
// Render::Object::vfunc_3 @ 0x001c5460

extern "C" float __cdecl FUN_00018710(float *out, float *value);

class Gate_1c5460 {
public:
    char FUN_001d4e70();
};

struct Owner_1c5460 {
    char pad00[0xec];
    Gate_1c5460 *gate;
};

class Renderer_1c5460;

namespace Render {
class Object {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Renderer_1c5460 *r, int unused);
    char pad04[0xc];
    void *drawable;
    char pad14[8];
    Owner_1c5460 *owner;
    char pad20[2];
    unsigned char hasOwner;
    char pad23[0x80 - 0x23];
    float fade80;
    char pad84[0x90 - 0x84];
    float fade90;
    union {
        float f;
        unsigned int bits;
    } mode94;
    char pad98[4];
    int value9c;
    float duration;
    float period;
    unsigned char active;
    unsigned char flagA9;
    void FUN_001c5130(float a, float b);
    void FUN_001c51b0(Renderer_1c5460 *r);
};
}

class Renderer_1c5460 {
public:
    char pad00[0xc0];
    int state;
    char padc4[0xcc - 0xc4];
    unsigned char flagCC;
    char FUN_001c17d0(Render::Object *o);
    void FUN_001c24d0(void *drawable, int v, float f);
    void FUN_001c1330(int v);
};

void Render::Object::vfunc_3(Renderer_1c5460 *r, int unused)
{
    if (!active)
        return;
    if (!DAT_004c518c)
        return;

    if (r->flagCC && (mode94.f == 0.0f || mode94.bits == 0x3f000000) && flagA9) {
        bool skip = false;
        if (hasOwner && owner != 0) {
            if (owner->gate->FUN_001d4e70())
                skip = true;
        }
        if (!skip && r->FUN_001c17d0(this))
            FUN_001c5130(0.5f, 0.25f);
    }

    if (fade90 >= 1.0f)
        return;
    if (fade80 >= 1.0f)
        return;

    void *d = drawable;
    if (d == 0)
        return;

    float ratio = 0.0f;
    if (duration > 1e-5f) {
        float out = 0.0f;
        ratio = duration / period;
        ratio = FUN_00018710(&out, &ratio);
    }
    r->FUN_001c24d0(d, value9c, ratio);
    r->FUN_001c1330(r->state);
    if (drawable)
        FUN_001c51b0(r);
    r->FUN_001c1330(0);
}
} // namespace fn_001c5460

namespace fn_f4431f34 {

// 0x001c5600 FUN_001c5600 (30 B): matches/0x001c5600.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f4431f34@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_001c5d30*)(this))->FUN_001c5d30();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001c5640 FUN_001c5640 (22 B): matches/0x001c5640.cpp
// sym: ??1Store@fn_f4431f34@@QAE@XZ
Store::~Store() {
    ((Render::StoreBase *)this)->FUN_001c7720();
    Cleanup2_001c7500();
}

} // namespace fn_f4431f34

// 0x001c56c0 Render::Store<Render::Object>::vfunc_1 (10 B): matches/0x001c56c0.cpp
// sym: ?vfunc_1@?$Store@VObject@Render@@@Render@@UAEHH@Z
template <> int Render::Store<Render::Object>::vfunc_1(int value) {
    return value + 8;
}


// 0x001c56d0 Render::Store<Render::Object>::vfunc_2 (34 B): matches/0x001c56d0.cpp
// sym: ?vfunc_2@?$Store@VObject@Render@@@Render@@UAEXPAX@Z
template <> void Render::Store<Render::Object>::vfunc_2(void* __p0) { void * param = (void *)__p0;

    if (this->f_11c && param)
        ((Obj_1c56d0*)param)->c(1);
}

namespace fn_f4431f34 {

// 0x001c5740 FUN_001c5740 (25 B): matches/0x001c5740.cpp
// sym: ?f@X@fn_f4431f34@@QAEXPAVArg@2@@Z
void X::f(Arg* n) {
    Fng_001c7870(n->convert_001c5b70(), n);
}


// 0x001c5780 Render::Store<Render::ObjectTemplate>::vfunc_1 (12 B): matches/0x001c5780.cpp
// sym: ?vfunc_1@fn_f4431f34@@YGHPAUStoreBase@1@@Z
int __stdcall vfunc_1(StoreBase* p) {
    return Helper_001c5b70(p);
}

} // namespace fn_f4431f34

// 0x001c5790 Render::Store<Render::ObjectTemplate>::vfunc_2 (39 B): matches/0x001c5790.cpp
// sym: ?vfunc_2@?$Store@VObjectTemplate@Render@@@Render@@UAEXPAX@Z
template <> void Render::Store<Render::ObjectTemplate>::vfunc_2(void* __p0) { ObjectTemplate_1c5790 * p = (ObjectTemplate_1c5790 *)__p0;

    if (this->f_11c && p) {
        p->Fnf_001c5d30();
        ReleaseTemplate_0008d330(p);
    }
}

namespace fn_f4431f34 {

// 0x001c57c0 Render::Store<Render::Object>::vfunc_0 (43 B): matches/0x001c57c0.cpp
// sym: ?scalar_dtor@Store_1c57c0@fn_f4431f34@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* Store_1c57c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00421914;
    ((Render::StoreBase *)this)->FUN_001c7720();
    base2_dtor_001c7500();
    if (flags & 1)
        thunk_delete_0008d330(this);
    return this;
}


// 0x001c57f0 Render::Store<Render::ObjectTemplate>::vfunc_0 (43 B): matches/0x001c57f0.cpp
// sym: ?scalar_dtor@Store_1c57f0@fn_f4431f34@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* Store_1c57f0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00421924;
    ((Render::StoreBase *)this)->FUN_001c7720();
    base2_dtor_001c7500();
    if (flags & 1)
        thunk_delete_0008d330(this);
    return this;
}


// 0x001c5840 FUN_001c5840 (68 B): matches/0x001c5840.cpp
// sym: ?Target@fn_f4431f34@@YIPAUObjectManager@1@PAU21@@Z
ObjectManager* __fastcall Target(ObjectManager* self) {
    self->vft = ((hulk_intptr)DAT_00421934);
    self->objects.Init_001c77e0(0x40, 0);
    *(hulk_uintptr*)&self->objects = ((hulk_intptr)DAT_00421914);
    self->templates.Init_001c77e0(0x40, 1);
    *(hulk_uintptr*)&self->templates = ((hulk_intptr)DAT_00421924);
    self->value = 0;
    return self;
}


// 0x001c5900 FUN_001c5900 (87 B): matches/0x001c5900.cpp
// sym: ?Run@Manager_1c5900@fn_f4431f34@@QAEPAUObj_1c5900@2@II@Z
Obj_1c5900* Manager_1c5900::Run(u32_1c5900 a, u32_1c5900 b) {
    Obj_1c5900* p = finder.Find_001c75e0(b);
    if (p) {
        p = p->Create_001c5c20(a);
        p->f();
        registry.Register_001c7870((char*)p + 8, p);
        if (p->Check_001c4af0())
            saved = p;
        return p;
    }
    return 0;
}


// 0x001c5960 FUN_001c5960 (100 B): equivalent/0x001c5960.cpp
// sym: ?FUN_001c5960@Mgr_1c5960@fn_f4431f34@@QAEPAVObject_1c5960@2@HH@Z @27096ed8726c @wc0545ededdc7
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 5/6, incomplete)
// FUN_001c5960 @ 0x001c5960
Object_1c5960 *Mgr_1c5960::FUN_001c5960(int a, int b)
{
    void *mem = FUN_0008d690((int)sizeof(Object_1c5960));
    if (mem == 0)
        return 0;
    Object_1c5960 *n = ((Object_1c5960 *)mem)->FUN_001c4eb0(a, b);
    if (n == 0)
        return n;
    n->v0();
    list.FUN_001c7870(n->sub8, n);
    if (n->FUN_001c4af0())
        f248 = n;
    return n;
}


// 0x001c59d0 FUN_001c59d0 (8 B): matches/0x001c59d0.cpp
// sym: ?G@X_1c59d0@fn_f4431f34@@QAEHH@Z
int X_1c59d0::G(hulk_intptr a0) {
    return B_1c59d0::FnF_001c75e0(a0);
}

} // namespace fn_f4431f34

// 0x001c59e0 FUN_001c59e0 (52 B): matches/0x001c59e0.cpp
// sym: ?FUN_001c59e0@Obj_1c59e0@owners@@QAEXH@Z
void owners::Obj_1c59e0::FUN_001c59e0(int arg) {
    int n = count;
    for (int i = 0; i <= n; ++i) {
        if ((unsigned)i < limit && items[i] != 0)
            ((Elem_1c59e0*)items[i])->Fnf_001c52f0(arg);
    }
}

namespace fn_f4431f34 {

// 0x001c5a20 FUN_001c5a20 (67 B): matches/0x001c5a20.cpp
// sym: ?Target@Owner_1c5a20@fn_f4431f34@@QAEXH@Z
void Owner_1c5a20::Target(int arg) {
    Ref_1c5a20* p = sub.Get_001c75e0(arg);
    sub.Other_001c7550(arg);
    if (p == m248)
        m248 = 0;
    if (p)
        p->Release();
}


// 0x001c5a70 FUN_001c5a70 (62 B): matches/0x001c5a70.cpp
// sym: ?Act@Owner@fn_f4431f34@@QAEXHH@Z
void Owner::Act(int key, int value) {
    Container* c = &items;
    Render::Object* n = c->Find_001c75e0(key);
    if (n) {
        c->Remove_001c7550(key);
        ((Object_nv_1c5a70*)(n))->Update_001c4ea0(value);
        c->Erase_001c7870((char*)n + 8, n);
    }
}


// 0x001c5ab0 FUN_001c5ab0 (48 B): matches/0x001c5ab0.cpp
// sym: ?fn@Obj@fn_f4431f34@@QAEXPAVItem@2@H@Z
void Obj::fn(Item* p, int x) {
    if (p) {
        p->f();
        p->Fng_001c4ea0(x);
        ((Obj*)((char*)this + 8))->Fnh_001c7870((Item*)((char*)p + 8), p);
    }
}

} // namespace fn_f4431f34
