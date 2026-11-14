// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000fdab0..0x000ff230 (kind game, layer game, confidence high), dominant class CCharacterGolem
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f54027db {
#define TREE_TU_END }
namespace fn_f54027db {} using namespace fn_f54027db;
namespace fn_f54027db { extern "C" char DAT_0040d12c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"
// (ren2) __RTtypeid's own name (CRT, C linkage)
extern "C" void* __cdecl __RTtypeid(void*);

// ---- declarations shared by the functions below
namespace fn_f54027db {
class Obj_fdab0 {
  public:
    char pad[0x1ce0];
    float value;
    float GetValue();
};
class Item_fdbd0 {
  public:
    virtual void F();
};
class Container_fdbd0 {
  public:
    char pad[8];
    int count;
    Item_fdbd0* items[1];
    int Add(Item_fdbd0* p);
};
class Item_fdc00 {
  public:
    virtual void f();
};
class Owner_fdc00 {
  public:
    char pad[8];
    int count;
    char pad2[0x50 - 12];
    int result;
    int add(Item_fdc00*);
};
class Thing_fdc30 {
  public:
    char pad0[0x0c];
    int values[17];
    int index;
};
struct Owner_fdc40 {
    char pad0[8];
    int count;
    void* items[1];
};
extern const int hulk_at_004a19e0;
extern const int hulk_at_004a1ad8;
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
    virtual void f9();
    virtual int Get();
    char pad[8];
    unsigned char match;
};
class Group {
  public:
    char pad[8];
    int count;
    Item* items[1];
    unsigned char Check(int id);
};
class Other_fdd30 {
  public:
    int Check(int v);
};
struct Vec3_fde80 {
    float x, y, z;
};
class Settings_fde80 {
public:
    char pad0[8];
    int f08;                // 0x08
    int f0c;                // 0x0c
    unsigned char flags10[4];   // 0x10
    float f14;              // 0x14
    float f18;              // 0x18
    Vec3_fde80 v1c;               // 0x1c
    Vec3_fde80 v28;               // 0x28
    float f34;              // 0x34
    Vec3_fde80 v38;               // 0x38
    unsigned char b44;      // 0x44
    unsigned char b45;      // 0x45
    unsigned char b46;      // 0x46
    char pad47;
    int f48;                // 0x48
    int f4c;                // 0x4c
    Vec3_fde80 v50;               // 0x50
    Vec3_fde80 v5c;               // 0x5c
    int f68;                // 0x68
    int f6c;                // 0x6c
    unsigned char b70;      // 0x70
    unsigned char b71;      // 0x71
    char pad72[2];
    int f74;                // 0x74
    Vec3_fde80 v78;               // 0x78
    float f84;              // 0x84
    float f88;              // 0x88

    void FUN_000fde80();
};
class Obj_fdf20 {
  public:
    char pad0[0x40];
    int a;
    int b;
    int c;
};
class Target_fdf20 {
  public:
    char pad0[0x0c];
    Obj_fdf20* source;
    char pad1[0x50 - 0x10];
    int a;
    int b;
    int c;
    void Run();
};
class Obj_fdf40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Set(int);
    virtual int Get();
    char pad[0x58 - 4];
    struct Block {
        char p[8];
        int key;
        char q[6];
        unsigned char flag12;
        int value14;
        char r[0x1c];
        float value34;
        char s[0x38];
        unsigned char flag70;
        unsigned char flag71;
    } block;
    void Target(int);
};
class A_fe000 {
  public:
    virtual void f();
    virtual void g();
};
class Obj {
  public:
    virtual void Add();
    virtual void Release();
    void method_0022d2b0(int, int);
};
class Item_fe230 {
  public:
    virtual void f();
    virtual void Release();
};
class Container_fe230 {
  public:
    char pad[8];
    int count;
    int entries[1];
    int Remove(int key);
};
struct Vec_fe300 { float x,y,z; };
struct State_fe300 {
 char pad[0x12]; unsigned char active; char pad13; float age; char pad18[4]; Vec_fe300 value;
 void update(const Vec_fe300* target, unsigned char flag, float rate, float threshold, float dt);
};
class CGolem_fe450 {
    char pad[0xf8];
};
struct Tgt_fe4d0 {
    char p[0x40];
    float x, y, z;
};
struct Sub_fe4d0 {
    char p[8];
    Tgt_fe4d0* t;
    char q[0x39];
    char flag;
    void Go_000fe300(float* v, int a, float s, int b, int c);
};
struct Base_fe4d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void SetN(int n);
    virtual int GetN();
    char pad[0x58 - 4];
    Sub_fe4d0 sub;
    void Fn(Tgt_fe4d0* t, char f);
};
extern void* hulk_at_0040d190[];
class Ref_fe540 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Vec_fe540 {
    int a;
    void Destroy_0027af50();
};
class CActorGolem_fe540 {
  public:
    void* vptr;
    char padb[0xf8 - 4];
    int mf8;
    ~CActorGolem_fe540() throw();
};
class CCharacterGolem_fe540 : public CActorGolem_fe540 {
  public:
    char padc[4];
    Ref_fe540* m100;
    Ref_fe540* m104;
    Ref_fe540* m108;
    Ref_fe540* m10c;
    Ref_fe540* m110;
    Ref_fe540* m114;
    Vec_fe540 m118;
    ~CCharacterGolem_fe540() throw();
};
struct CAgent_fe940 {
    virtual void AddRef();
    virtual void Release();
};
struct CRangedAgent_fe940 : CAgent_fe940 {
    CRangedAgent_fe940 *FUN_001076f0(struct AgentHost_fe940 *host);
};
struct AgentHost_fe940 {
};
extern char DAT_004a1b68;
int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);
struct CAgent_fe9e0 {
    virtual void AddRef();
    virtual void Release();
};
struct CHand2HandAgent_fe9e0 : CAgent_fe9e0 {
    CHand2HandAgent_fe9e0 *FUN_000ff180(struct AgentHost_fe9e0 *host);
};
struct AgentHost_fe9e0 {
};
extern char DAT_004a1b84;
struct CAgent_fea80 {
    virtual void AddRef();
    virtual void Release();
};
struct CChaseAgent_fea80 : CAgent_fea80 {
    CChaseAgent_fea80 *FUN_000fcb10(struct AgentHost_fea80 *host);
};
struct AgentHost_fea80 {
};
extern char DAT_004a1a44;
struct CAgent_feb20 {
    virtual void AddRef();
    virtual void Release();
};
struct CMoveAgent_feb20 : CAgent_feb20 {
    CMoveAgent_feb20 *FUN_00102ac0(struct AgentHost_feb20 *host);
};
struct AgentHost_feb20 {
};
extern char DAT_004a1ba4;
struct CAgent_fec60 {
    virtual void AddRef();
    virtual void Release();
};
struct CPathGraphAgent_fec60 : CAgent_fec60 {
    CPathGraphAgent_fec60 *FUN_00105f50(struct AgentHost_fec60 *host);
};
struct AgentHost_fec60 {
};
extern char DAT_004a1bdc;
extern void* hulk_at_0040d134[];
struct Sub_fed00 {
    void* vptr;
    void Init_000fde80() throw();
};
class CGolem_fed00 {
  public:
    void* vptr;
    int m4, m8;
    int mc[16];
    int m4c, m50;
    char pad[0x58 - 0x54];
    Sub_fed00 sub;
    char pad2[0xe8 - 0x58 - 4];
    char me8, me9;
    char pad3[0xf0 - 0xea];
    int mf0;
    char mf4;
    CGolem_fed00() throw();
};
extern "C" char DAT_0040d164[];
class CCharacterGolem_feda0 {
  public:
    void* vptr;
    char pad[0xF4];
    int value;
    void init_000fed00();
};
extern void Init_000feb20(owners::C_fefa0*, int*);
extern void __cdecl Init_000febc0(owners::Obj_fefc0*, int*);


// 0x000fdab0 FUN_000fdab0 (7 B): matches/0x000fdab0.cpp
// sym: ?GetValue@Obj_fdab0@fn_f54027db@@QAEMXZ
float Obj_fdab0::GetValue() {
    return value;
}

} // namespace fn_f54027db

// 0x000fdac0 CGolem::vfunc_3 (3 B): matches/0x000fdac0.cpp
// sym: ?vfunc_3@CGolem@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void CGolem::vfunc_3(int a, int b) {}


// 0x000fdad0 CGolem::vfunc_4 (201 B): matches/0x000fdad0.cpp [wrapped: conflict: CGolem]
// sym: ?vfunc_4@CGolem@fn_000fdad0@@UAEXHH@Z
namespace fn_000fdad0 {
struct GolemPart {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(int a, int b);
    virtual void vfunc_4(int a, int b, bool changed);
    virtual void vfunc_5(int a, int b);
    virtual void vfunc_6();
    virtual void vfunc_7(int enabled);
};
struct CGolem {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int a, int b);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    int field4;
    int count;
    GolemPart* parts[16];
    int selected;
    char pad50[0xa4];
    bool disabled;
};
void CGolem::vfunc_4(int a, int b) {
    int previous = selected;
    selected = -1;
    float best = 0.0f;
    int winner = -1;
    for (int i = 0; i < count; ++i) {
        float score = parts[i]->vfunc_3(a, b);
        if (score > best) {
            best = score;
            winner = i;
        }
    }
    if (previous >= 0 && previous != winner)
        parts[previous]->vfunc_5(a, b);
    if (winner >= 0) {
        selected = winner;
        if (!disabled)
            parts[winner]->vfunc_4(a, b, winner != previous);
        parts[selected]->vfunc_7(1);
    }
}
} // namespace fn_000fdad0


// 0x000fdba0 CGolem::vfunc_5 (3 B): matches/0x000fdba0.cpp
// sym: ?vfunc_5@CGolem@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void CGolem::vfunc_5(int a, int b) {}


// 0x000fdbb0 CGolem::vfunc_8 (22 B): matches/0x000fdbb0.cpp
// sym: ?vfunc_8@CGolem@@UAEXH@Z
void CGolem::vfunc_8(int x) {
    if (x >= 0 && x <= 4)
        this->f_f0 = x;
}

namespace fn_f54027db {

// 0x000fdbd0 FUN_000fdbd0 (34 B): matches/0x000fdbd0.cpp
// sym: ?Add@Container_fdbd0@fn_f54027db@@QAEHPAVItem_fdbd0@2@@Z
int Container_fdbd0::Add(Item_fdbd0* p) {
    items[count] = p;
    p->F();
    int n = ++count;
    return n - 1;
}


// 0x000fdc00 FUN_000fdc00 (35 B): matches/0x000fdc00.cpp
// sym: ?add@Owner_fdc00@fn_f54027db@@QAEHPAVItem_fdc00@2@@Z
int Owner_fdc00::add(Item_fdc00* p) {
    ((Item_fdc00**)this)[3 + count] = p;
    p->f();
    result = count;
    ++count;
    return result;
}


// 0x000fdc30 FUN_000fdc30 (16 B): matches/0x000fdc30.cpp
// sym: ?target@fn_f54027db@@YIHPAVThing_fdc30@1@@Z
hulk_intptr __fastcall target(Thing_fdc30* self) {
    int i = self->index;
    if (i == -1)
        return 0;
    return self->values[i];
}


// 0x000fdc40 FUN_000fdc40 (63 B): matches/0x000fdc40.cpp
// sym: ?Target@fn_f54027db@@YIHPAUOwner_fdc40@1@@Z
hulk_intptr __fastcall Target(Owner_fdc40* self) {
    int i = 0;
    if (self->count > 0) {
        void** p = self->items;
        do {
            int r = IsType(*p, 0, &hulk_at_004a19e0, &hulk_at_004a1ad8, 0);
            if (r != 0)
                return r;
            ++i;
            ++p;
        } while (i < self->count);
    }
    return 0;
}

} // namespace fn_f54027db

// 0x000fdc80 FUN_000fdc80 (20 B): matches/0x000fdc80.cpp
// sym: ?FUN_000fdc80@C_fdc80@owners@@QAEHXZ
int owners::C_fdc80::FUN_000fdc80() {
    int i = index;
    if (i >= 0 && i < count)
        return *(int*)((char*)this + 0xc + i * 4);
    return 0;
}


// 0x000fdca0 FUN_000fdca0 (7 B): matches/0x000fdca0.cpp
// sym: ?FUN_000fdca0@Obj_fdca0@owners@@QAEHXZ
int owners::Obj_fdca0::FUN_000fdca0() {
    return value;
}

namespace fn_f54027db {

// 0x000fdcb0 FUN_000fdcb0 (69 B): matches/0x000fdcb0.cpp
// sym: ?Check@Group@fn_f54027db@@QAEEH@Z
unsigned char Group::Check(int id) {
    unsigned char found = 0;
    for (int i = 0; i < count; i++) {
        if (items[i]->Get() == id) {
            items[i]->match = 1;
            found = 1;
        } else {
            items[i]->match = 0;
        }
    }
    return found;
}

} // namespace fn_f54027db

// 0x000fdd30 FUN_000fdd30 (72 B): matches/0x000fdd30.cpp
// sym: ?FUN_000fdd30@Container_fdd30@owners@@QAEHH@Z
hulk_intptr owners::Container_fdd30::FUN_000fdd30(hulk_intptr arg) {
    Other_fdd30* o = (Other_fdd30*)((hulk_intptr)arg);
    int e;
    int i = 0;
    if (mCount > 0) {
        int* p = mArray;
        do {
            e = *p;
            if (o->Check(((int)(hulk_uintptr)__RTtypeid((void*)(hulk_uintptr)(e))))) {
                return e;
            }
            ++i;
            ++p;
        } while (i < mCount);
    }
    return 0;
}


// 0x000fddb0 FUN_000fddb0 (31 B): matches/0x000fddb0.cpp
// sym: ?FUN_000fddb0@Obj_fddb0@owners@@QAEXPAH@Z
void owners::Obj_fddb0::FUN_000fddb0(int* p) {
    zero = 0;
    a = p[0];
    b = p[1];
    c = p[2];
}


// 0x000fddf0 FUN_000fddf0 (38 B): matches/0x000fddf0.cpp
// sym: ?FUN_000fddf0@C_fddf0@owners@@QAEXPAXPAI@Z
void owners::C_fddf0::FUN_000fddf0(void* a, unsigned* b) {
    *(void**)(pad + 0x74) = a;
    if (!a) {
        *(unsigned*)(pad + 0x78) = b[0];
        *(unsigned*)(pad + 0x7c) = b[1];
        *(unsigned*)(pad + 0x80) = b[2];
    }
}


// 0x000fde20 FUN_000fde20 (30 B): matches/0x000fde20.cpp
// sym: ?FUN_000fde20@C_fde20@owners@@QAEHPAH@Z
hulk_intptr owners::C_fde20::FUN_000fde20(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return value;
}


// 0x000fde40 FUN_000fde40 (26 B): matches/0x000fde40.cpp
// sym: ?FUN_000fde40@C_fde40@owners@@QAE_NPAH@Z
bool owners::C_fde40::FUN_000fde40(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}


// 0x000fde60 FUN_000fde60 (26 B): matches/0x000fde60.cpp
// sym: ?FUN_000fde60@C_fde60@owners@@QAE_NPAH@Z
bool owners::C_fde60::FUN_000fde60(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}

namespace fn_f54027db {

// 0x000fde80 FUN_000fde80 (147 B): equivalent/0x000fde80.cpp
// sym: ?FUN_000fde80@Settings_fde80@fn_f54027db@@QAEXXZ @5842446318d9 @w2c2c404aa6af
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000fde80 @ 0x000fde80
void Settings_fde80::FUN_000fde80()
{
    f08 = 0;
    f0c = 0;
    flags10[0] = 0;
    flags10[1] = 0;
    flags10[2] = 0;
    flags10[3] = 0;
    f14 = 2.0f;
    f18 = 120.0f;
    v1c.z = 0.0f;
    v1c.y = 0.0f;
    v1c.x = 0.0f;
    v28.z = 0.0f;
    v28.y = 0.0f;
    v28.x = 0.0f;
    f34 = 120.0f;
    v38.z = 0.0f;
    v38.y = 0.0f;
    v38.x = 0.0f;
    b44 = 0;
    b45 = 0;
    b46 = 0;
    f48 = 0;
    f4c = 0;
    v50.z = 0.0f;
    v50.y = 0.0f;
    v50.x = 0.0f;
    v5c.z = 0.0f;
    v5c.y = 0.0f;
    v5c.x = 0.0f;
    f68 = 0;
    f6c = 0;
    b70 = 0;
    b71 = 1;
    f74 = 0;
    v78.z = 0.0f;
    v78.y = 0.0f;
    v78.x = 0.0f;
    f84 = 5.0f;
    f88 = 10.0f;
}


// 0x000fdf20 FUN_000fdf20 (26 B): matches/0x000fdf20.cpp
// sym: ?Run@Target_fdf20@fn_f54027db@@QAEXXZ
void Target_fdf20::Run() {
    if (source) {
        a = source->a;
        b = source->b;
        c = source->c;
    }
}


// 0x000fdf40 FUN_000fdf40 (74 B): matches/0x000fdf40.cpp
// sym: ?Target@Obj_fdf40@fn_f54027db@@QAEXH@Z
void Obj_fdf40::Target(int x) {
    Block* b = &block;
    if (x != 0 && b != 0 && b->key == x) {
        b->flag12 = 0;
        b->value14 = 0x40000000;
        b->value34 = 120.0f;
        b->flag70 = 0;
        b->flag71 = 1;
        int n = Get();
        if (n > 2)
            Set(2);
    }
}

} // namespace fn_f54027db

// 0x000fdf90 CCharacterGolem::vfunc_5 (3 B): matches/0x000fdf90.cpp
// sym: ?vfunc_5@CCharacterGolem@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void CCharacterGolem::vfunc_5(int a, int b) {}


// 0x000fdfa0 CCharacterGolem::vfunc_4 (62 B): matches/0x000fdfa0.cpp [wrapped: conflict: CCharacterGolem]
// sym: ?vfunc_4@CCharacterGolem@fn_000fdfa0@@UAEXHH@Z
namespace fn_000fdfa0 {
class CActorGolem_fdfa0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4(int, int);
};
class CCharacterGolem : public CActorGolem_fdfa0 {
  public:
    char pad[0x124];
    unsigned char flag;
    virtual void x1();
    virtual int get();
    void vfunc_4(int, int);
};
void CCharacterGolem::vfunc_4(int a, int b) {
    CActorGolem_fdfa0::vfunc_4(a, b);
    if (flag) {
        hulk_intptr v = get();
        if (v) {
            int* p = (int*)(v + 0x1f58);
            if (p)
                *(int*)((char*)p + 0x118) = 0;
        }
    }
}
} // namespace fn_000fdfa0

namespace fn_f54027db {

// 0x000fe000 FUN_000fe000 (24 B): matches/0x000fe000.cpp
// sym: ?FUN_000fe000@fn_f54027db@@YAXPAPAVA_fe000@1@@Z
// Same code shape as 0x000187d0 (propagated; names are from that function)
void FUN_000fe000(A_fe000** p) {
    if (*p) {
        (*p)->g();
        *p = 0;
    }
}


// 0x000fe0c0 FUN_000fe0c0 (36 B): matches/0x000fe0c0.cpp
// sym: ?FUN_000fe0c0@fn_f54027db@@YAXPAPAVObj@1@PAV21@@Z
void __cdecl FUN_000fe0c0(Obj** slot, Obj* value) {
    if (value)
        value->Add();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}

} // namespace fn_f54027db

// 0x000fe1e0 FUN_000fe1e0 (59 B): matches/0x000fe1e0.cpp [wrapped: conflict: CGolem]
// sym: ?destroy@CGolem@fn_000fe1e0@@QAEXXZ
namespace fn_000fe1e0 {
extern int golemVtable;
extern int hulk_at_0040d12c;
extern int hulk_at_003f6098;
class IRefCount {
  public:
    virtual void f0();
    virtual void Release();
};
class CGolem {
  public:
    hulk_intptr vf;
    char pad04[8];
    IRefCount* items[16];
    char pad4c[12];
    hulk_intptr memory;
    void destroy();
};
void CGolem::destroy() {
    int i;
    vf = (hulk_intptr)&golemVtable;
    for (i = 0; i < 16; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    memory = (hulk_intptr)&hulk_at_0040d12c;
    vf = (hulk_intptr)&hulk_at_003f6098;
}
} // namespace fn_000fe1e0


// 0x000fe220 CGolem::vfunc_9 (7 B): matches/0x000fe220.cpp
// sym: ?vfunc_9@CGolem@@UAEIXZ
unsigned int CGolem::vfunc_9() {
    return (*(unsigned int *)&this->f_f0);
}

namespace fn_f54027db {

// 0x000fe230 FUN_000fe230 (96 B): matches/0x000fe230.cpp
// sym: ?Remove@Container_fe230@fn_f54027db@@QAEHH@Z
int Container_fe230::Remove(int key) {
    int i = 0;
    if (count > 0) {
        while (i < count) {
            if (entries[i] == key) {
                Item_fe230* p = (Item_fe230*)entries[i];
                if (p != 0) {
                    p->Release();
                    entries[i] = 0;
                }
                --count;
                break;
            }
            ++i;
        }
    }
    if (i < count) {
        do {
            entries[i] = entries[i + 1];
            ++i;
        } while (i < count);
    }
    return 1;
}

} // namespace fn_f54027db

// 0x000fe290 CGolem::vfunc_7 (52 B): equivalent/0x000fe290.cpp [wrapped: conflict: CGolem]
// sym: ?vfunc_7@CGolem@fn_000fe290@@UAEXXZ @8adc487fb377 @w3e357c820d5b
namespace fn_000fe290 {
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 5/6, incomplete)
// CGolem::vfunc_7 @ 0x000fe290
struct GolemItem { virtual void vfunc_0(); virtual void vfunc_1(); }; class CGolem { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); char unknown[4]; int count; GolemItem* items[16]; }; void CGolem::vfunc_7() { for (int i = 0; i < 16; ++i) { GolemItem* item = items[i]; if (item) { item->vfunc_1(); items[i] = 0; --count; } } }
} // namespace fn_000fe290


// 0x000fe2e0 CMemorySystem::vfunc_0 (31 B): matches/0x000fe2e0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000fe2e0@@UAEPAV123@E@Z
namespace fn_000fe2e0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0040d12c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000fe2e0

namespace fn_f54027db {

// 0x000fe300 FUN_000fe300 (289 B): equivalent/0x000fe300.cpp
// sym: ?update@State_fe300@fn_f54027db@@QAEXPBUVec_fe300@2@EMMM@Z @bb4aa128100e @wc42a2fab045c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000fe300 @ 0x000fe300
void State_fe300::update(const Vec_fe300* target, unsigned char flag, float rate, float threshold, float dt) {
 if (flag || age < threshold) {
  if (!active && threshold + threshold < age) {
   value.x=target->x; value.y=target->y; value.z=target->z;
  } else {
   volatile float a;
   if (rate >= 1.0f) a=1.0f;
   else {
    a=dt * 30.0003f * rate;
    if (a > 1.0f) a=1.0f;
    else if (!(0.0f < a)) a=0.0f;
   }
   volatile float tx=a*target->x, ty=a*target->y, tz=a*target->z;
   double b=(double)1.0f-(double)a;
   volatile float ox=(float)(b*value.x), oy=(float)(b*value.y);
   float z=(float)(b*value.z+(double)tz);
   value.x=ox+tx; value.y=oy+ty; value.z=z;
  }
 }
 if(flag != active) { active=flag; age=0.0f; } else active=flag;
}

} // namespace fn_f54027db

// 0x000fe450 CActorGolem::vfunc_6 (7 B): matches/0x000fe450.cpp
// sym: ?vfunc_6@CActorGolem@@UAEHXZ
int CActorGolem::vfunc_6() {
    return *(int*)((char*)this + 0xf8);
}


// 0x000fe460 CActorGolem::vfunc_3 (109 B): equivalent/0x000fe460.cpp [wrapped: conflict: CActorGolem]
// sym: ?vfunc_3@CActorGolem@fn_000fe460@@UAEXHM@Z @d75feb4eb5fd @w67a8eb774480
namespace fn_000fe460 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CActorGolem::vfunc_3 @ 0x000fe460
struct IVec3 { int x, y, z; };
struct Inner_fe460 { char pad[0x40]; IVec3 v40; };
struct Sub_fe460 {
    char pad0[8];
    Inner_fe460 *p8;
    char pad1[0x14 - 0xc];
    float f14;
    char pad2[0x34 - 0x18];
    float f34;
    IVec3 v38;
    void FUN_000fe300(IVec3 *v, int a, int b, int c, float t);
};
class CActorGolem {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(int a1, float t);
    char pad04[0x58 - 4];
    Sub_fe460 sub;
};
void CActorGolem::vfunc_3(int a1, float t)
{
    Sub_fe460 *s = &sub;
    if (sub.p8 != 0) {
        IVec3 v = sub.p8->v40;
        s->FUN_000fe300(&v, 1, 0, 0, t);
        s->f34 = 0;
        s->v38 = v;
    }
    s->f14 = t + s->f14;
    s->f34 = t + s->f34;
}
} // namespace fn_000fe460

namespace fn_f54027db {

// 0x000fe4d0 FUN_000fe4d0 (112 B): matches/0x000fe4d0.cpp
// sym: ?Fn@Base_fe4d0@fn_f54027db@@QAEXPAUTgt_fe4d0@2@D@Z
void Base_fe4d0::Fn(Tgt_fe4d0* t, char f) {
    Sub_fe4d0* s = &sub;
    if (t && s && s->t == t) {
        float v[3];
        v[0] = t->x;
        v[1] = t->y;
        v[2] = t->z;
        s->Go_000fe300(v, 1, 1.0f, 0, 0);
        if (GetN() < 3)
            SetN(3);
        if (f)
            s->flag = 1;
    }
}


// 0x000fe540 FUN_000fe540 (170 B): matches/0x000fe540.cpp
// sym: ??1CCharacterGolem_fe540@fn_f54027db@@QAE@XZ
CCharacterGolem_fe540::~CCharacterGolem_fe540() throw() {
    vptr = hulk_at_0040d190;
    _ReadWriteBarrier();
    if (m100) {
        m100->Release();
        m100 = 0;
    }
    if (m104) {
        m104->Release();
        m104 = 0;
    }
    if (m108) {
        m108->Release();
        m108 = 0;
    }
    if (m10c) {
        m10c->Release();
        m10c = 0;
    }
    if (m110) {
        m110->Release();
        m110 = 0;
    }
    if (m114) {
        m114->Release();
        m114 = 0;
    }
    m118.Destroy_0027af50();
    mf8 = 0;
    vptr = ((void**)DAT_0040d164);
}

} // namespace fn_f54027db

// 0x000fe5f0 CCharacterGolem::vfunc_7 (140 B): matches/0x000fe5f0.cpp [wrapped: conflict: CActorGolem; CCharacterGolem; CGolem]
// sym: ?vfunc_7@CCharacterGolem@fn_000fe5f0@@UAEXXZ
namespace fn_000fe5f0 {
class CGolem {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
class CActorGolem : public CGolem {};
class CCharacterGolem : public CActorGolem {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[0x100 - 4];
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
};
void CCharacterGolem::vfunc_7() {
    CGolem::v7();
    if (p0) {
        ((CGolem*)p0)->v1();
        p0 = 0;
    }
    if (p1) {
        ((CGolem*)p1)->v1();
        p1 = 0;
    }
    if (p2) {
        ((CGolem*)p2)->v1();
        p2 = 0;
    }
    if (p3) {
        ((CGolem*)p3)->v1();
        p3 = 0;
    }
    if (p4) {
        ((CGolem*)p4)->v1();
        p4 = 0;
    }
    if (p5) {
        ((CGolem*)p5)->v1();
        p5 = 0;
    }
}
} // namespace fn_000fe5f0


// 0x000fe680 CCharacterGolem::vfunc_3 (700 B): equivalent/0x000fe680.cpp [wrapped: conflict: CCharacterGolem]
// sym: ?vfunc_3@CCharacterGolem@fn_000fe680@@UAEXPAUEntity@2@M@Z @29400653fba5 @w8dba29f047ad
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000fe680 {
// STATUS: equivalent (tools/equiv.py level 3: 20028 inputs, branch coverage 48/48)
// CCharacterGolem::vfunc_3 @ 0x000fe680
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



#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_fe680 {
    float x, y, z;
};

struct Rng_fe680 {
    hulk_freg FUN_00078780();
};
Rng_fe680 *FUN_000964d0();

struct Slot_fe680 {
    char pad0[8];
    int f08;
    int f0c;
    char pad10[0x30];
    V3_fe680 pos;
};

struct Link_fe680 {
    char pad0[0x12c];
    Slot_fe680 *slot;
};

struct Part54_fe680 {
    void FUN_00086310();
};

struct Target_fe680;

struct Sub20_fe680 {
    bool FUN_00025d30(Target_fe680 *t);
    bool FUN_00024300(Target_fe680 *t);
    Link_fe680 *FUN_00024280(unsigned __int64 id);
};

struct Entity {
    char pad0[0x20];
    Sub20_fe680 *sub20;
    char pad24[0x30];
    Part54_fe680 *part54;
};

struct Skel_fe680 {
    void FUN_00059a50(V3_fe680 *out);
};

struct Target_fe680 {
    char pad0[0x10];
    Skel_fe680 *skel;
    char pad14[0x1ccc];
    int f1ce0;
    int f1ce4;
    bool FUN_00042990(Entity *e, Slot_fe680 *q, float range, char *outB, char *outA);
};

struct PState {
    char pad0[8];
    Slot_fe680 *slot;         // 8
    char padc[6];
    char b12;
    char b13;
    float f14;
    float f18;
    char pad1c[0x18];
    float f34;
    V3_fe680 qpos;            // 0x38
    char b44;
    char b45;
    char b46;
    char pad47[0x9c - 0x47];
    void FUN_000fe300(V3_fe680 *p, int found, int a, int b, float dt);
    void FUN_000fdf20();
};

class CCharacterGolem {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Entity *a1, float dt);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual Target_fe680 *vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int v);
    virtual int vfunc_9();
    char pad4[0x54];
    PState p;           // 0x58
    char flagF4;
    char padf5[0x2f];
    float f124;
    char pad128[4];
    float f12c;
};

void CCharacterGolem::vfunc_3(Entity *a1, float dt)
{
    Target_fe680 *t = vfunc_6();
    a1->part54->FUN_00086310();
    if (!a1->sub20->FUN_00025d30(t)) {
        hulk_freg x = dt + f12c;
        f12c = x;
        if (x < (*(float*)&DAT_0040d0f4))
            return;
        dt = x;
        f12c = 0;
    }
    if (flagF4 != 0)
        return;
    struct Frame {
        char pad10[2];
        char b12;
        char b13;
        char found;
        char pad15[3];
        float dist;
        Rng_fe680 *rng;
        V3_fe680 qpos;
        V3_fe680 pos0;
    } fr;
    PState *ps = &p;
    fr.rng = FUN_000964d0();
    if ((*(bool*)&DAT_004e0a98) && t != 0) {
        Sub20_fe680 *s20 = a1->sub20;
        unsigned __int64 id = FUN_002672f0("hulk", 0, 0);
        ps->slot = s20->FUN_00024280(id)->slot;
    }
    Slot_fe680 *q = ps->slot;
    if (q != 0 && t != 0) {
        t->skel->FUN_00059a50(&fr.pos0);
        fr.qpos = q->pos;
        hulk_freg dx = fr.qpos.x - fr.pos0.x;
        hulk_freg dy = fr.qpos.y - fr.pos0.y;
        hulk_freg dz = fr.qpos.z - fr.pos0.z;
        fr.dist = (float)sqrt((double)(dz * dz + dy * dy + dx * dx));
        bool near = false;
        if (t->FUN_00042990(a1, q, 100.0f, &fr.b12, &fr.b13)) {
            if (vfunc_9() != 0 || fr.dist < 3.0f)
                near = true;
        }
        fr.found = 0;
        if (near) {
            if (fr.dist <= 100.0f) {
                fr.found = 1;
                if (ps->b12 == 0 && ps->f14 > 3.0f)
                    f124 = 0;
            }
        }
        hulk_freg rem = f124 - dt;
        f124 = rem;
        if (rem <= 0.0f && !a1->sub20->FUN_00024300(t))
            f124 = (fr.rng->FUN_00078780() + 1.0f) * (*(float*)&DAT_0040d0e8);
        if (q->f0c == 1 && q->f08 != 0) {
            ps->b44 = 1;
            if (fr.found) {
                ps->b45 = 1;
                if (vfunc_9() < 3)
                    vfunc_8(3);
            }
        } else {
            ps->b44 = 0;
        }
        ps->FUN_000fe300(&fr.qpos, *(int *)&fr.found, t->f1ce0, t->f1ce4, dt);
        if (fr.found)
            ps->b45 = 1;
        if (ps->b13 != fr.b12) {
            ps->f18 = 0;
            ps->b13 = fr.b12;
        }
        ps->qpos = fr.qpos;
        ps->f34 = 0;
        if (vfunc_9() < 2)
            vfunc_8(2);
        if (ps->b46)
            ps->FUN_000fdf20();
    }
    ps->f14 = dt + ps->f14;
    ps->f34 = dt + ps->f34;
}
} // namespace fn_000fe680
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f54027db {

// 0x000fe940 FUN_000fe940 (158 B): equivalent/0x000fe940.cpp
// sym: ?FUN_000fe940@fn_f54027db@@YAXPAUAgentHost_fe940@1@PAPAUCAgent_fe940@1@@Z @f495c85e4087 @wcf34ade08564
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fe940 @ 0x000fe940
// 0x000fe940: fetch (or lazily create) the CRangedAgent in *slot
void __cdecl FUN_000fe940(AgentHost_fe940 *host, CAgent_fe940 **slot)
{
    CAgent_fe940 *found = ((CAgent_fe940 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1b68)));
    if (found) {
        CRangedAgent_fe940 *agent = dynamic_cast<CRangedAgent_fe940 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CRangedAgent_fe940 *agent = (CRangedAgent_fe940 *)FUN_0008d690(0xb0);
        if (agent)
            agent = agent->FUN_001076f0(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}


// 0x000fe9e0 FUN_000fe9e0 (158 B): equivalent/0x000fe9e0.cpp
// sym: ?FUN_000fe9e0@fn_f54027db@@YAXPAUAgentHost_fe9e0@1@PAPAUCAgent_fe9e0@1@@Z @81254826d8f5 @w5216876a5c3f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fe9e0 @ 0x000fe9e0
// 0x000fe9e0: fetch (or lazily create) the CHand2HandAgent in *slot
void __cdecl FUN_000fe9e0(AgentHost_fe9e0 *host, CAgent_fe9e0 **slot)
{
    CAgent_fe9e0 *found = ((CAgent_fe9e0 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1b84)));
    if (found) {
        CHand2HandAgent_fe9e0 *agent = dynamic_cast<CHand2HandAgent_fe9e0 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CHand2HandAgent_fe9e0 *agent = (CHand2HandAgent_fe9e0 *)FUN_0008d690(0x1a0);
        if (agent)
            agent = agent->FUN_000ff180(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}


// 0x000fea80 FUN_000fea80 (155 B): equivalent/0x000fea80.cpp
// sym: ?FUN_000fea80@fn_f54027db@@YAXPAUAgentHost_fea80@1@PAPAUCAgent_fea80@1@@Z @b58418138aa5 @we6704b07ca29
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000fea80 @ 0x000fea80
// FUN_000fea80: fetch (or lazily create) the CChaseAgent in *slot
void __cdecl FUN_000fea80(AgentHost_fea80 *host, CAgent_fea80 **slot)
{
    CAgent_fea80 *found = ((CAgent_fea80 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1a44)));
    if (found) {
        CChaseAgent_fea80 *agent = dynamic_cast<CChaseAgent_fea80 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CChaseAgent_fea80 *agent = (CChaseAgent_fea80 *)FUN_0008d690(0x74);
        if (agent)
            agent = agent->FUN_000fcb10(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}


// 0x000feb20 FUN_000feb20 (155 B): equivalent/0x000feb20.cpp
// sym: ?FUN_000feb20@fn_f54027db@@YAXPAUAgentHost_feb20@1@PAPAUCAgent_feb20@1@@Z @8ac8ef787f81 @wa5805ce61916
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000feb20 @ 0x000feb20
// FUN_000feb20: fetch (or lazily create) the CMoveAgent in *slot
void __cdecl FUN_000feb20(AgentHost_feb20 *host, CAgent_feb20 **slot)
{
    CAgent_feb20 *found = ((CAgent_feb20 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1ba4)));
    if (found) {
        CMoveAgent_feb20 *agent = dynamic_cast<CMoveAgent_feb20 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CMoveAgent_feb20 *agent = (CMoveAgent_feb20 *)FUN_0008d690(0x78);
        if (agent)
            agent = agent->FUN_00102ac0(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}


// 0x000fec60 FUN_000fec60 (158 B): equivalent/0x000fec60.cpp
// sym: ?FUN_000fec60@fn_f54027db@@YAXPAUAgentHost_fec60@1@PAPAUCAgent_fec60@1@@Z @be3a21ae190d @wf1c57f8a92f9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fec60 @ 0x000fec60
// 0x000fec60: fetch (or lazily create) the CPathGraphAgent in *slot
void __cdecl FUN_000fec60(AgentHost_fec60 *host, CAgent_fec60 **slot)
{
    CAgent_fec60 *found = ((CAgent_fec60 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1bdc)));
    if (found) {
        CPathGraphAgent_fec60 *agent = dynamic_cast<CPathGraphAgent_fec60 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CPathGraphAgent_fec60 *agent = (CPathGraphAgent_fec60 *)FUN_0008d690(0xf4);
        if (agent)
            agent = agent->FUN_00105f50(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}


// 0x000fed00 FUN_000fed00 (125 B): matches/0x000fed00.cpp
// sym: ??0CGolem_fed00@fn_f54027db@@QAE@XZ
CGolem_fed00::CGolem_fed00() throw() {
    m4 = 0;
    vptr = hulk_at_0040d134;
    m8 = 0;
    m4c = -1;
    m50 = -1;
    sub.vptr = (void**)DAT_0040d12c;
    sub.Init_000fde80();
    me8 = 0;
    me9 = 1;
    for (int i = 0; i < 16; i++)
        mc[i] = 0;
    mf0 = 1;
    mf4 = 0;
}

} // namespace fn_f54027db

// 0x000fed80 CGolem::vfunc_2 (30 B): matches/0x000fed80.cpp
// sym: ??_GCGolem@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGolem::~CGolem() {}

namespace fn_f54027db {

// 0x000feda0 FUN_000feda0 (28 B): matches/0x000feda0.cpp
// sym: ?FUN_000feda0@fn_f54027db@@YIPAVCCharacterGolem_feda0@1@PAV21@@Z
CCharacterGolem_feda0* __fastcall FUN_000feda0(CCharacterGolem_feda0* self) {
    self->init_000fed00();
    self->vptr = (void*)((hulk_intptr)DAT_0040d164);
    self->value = 0;
    return self;
}

} // namespace fn_f54027db

// 0x000fedc0 CActorGolem::vfunc_2 (46 B): matches/0x000fedc0.cpp [wrapped: conflict: CActorGolem; CGolem]
// sym: ?vfunc_2@CActorGolem@fn_000fedc0@@UAEPAV12@E@Z
namespace fn_000fedc0 {
extern "C" char DAT_0040d164[];
class CGolem {
    char pad[0xf8];
};
class CActorGolem : public CGolem {
  public:
    virtual void f0();
    virtual void f1();
    virtual CActorGolem* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
struct ThisCall_000fe1e0 {
    void FUN_000fe1e0();
};
void thunk_FUN_00267090(CActorGolem*);
CActorGolem* CActorGolem::vfunc_2(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0040d164);
    *(int*)((char*)this + 0xf8) = 0;
    ((ThisCall_000fe1e0*)(this))->FUN_000fe1e0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000fedc0


// 0x000fedf0 FUN_000fedf0 (30 B): matches/0x000fedf0.cpp [wrapped: conflict: CActorGolem]
// sym: ?Init@CActorGolem@fn_000fedf0@@QAEPAV12@PAX@Z
namespace fn_000fedf0 {
extern int hulk_at_0040d164;
class CActorGolem {
  public:
    virtual void f();
    char pad[0xf4];
    void* m;
    void InitBase_000fed00();
    CActorGolem* Init(void*);
};
CActorGolem* CActorGolem::Init(void* p) {
    InitBase_000fed00();
    m = p;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0040d164;
    return this;
}
} // namespace fn_000fedf0


// 0x000fee10 FUN_000fee10 (258 B): equivalent/0x000fee10.cpp [wrapped: conflict: CCharacterGolem; FUN_000964d0]
// sym: ?FUN_000fee10@CCharacterGolem@fn_000fee10@@QAEPAV12@H@Z @73d92583846a @w17a0eb871bfc
inline void *operator new(size_t, void *p) { return p; }
namespace fn_000fee10 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// FUN_000fee10 @ 0x000fee10



struct Name8 {
    int lo, hi;
    void FUN_0027af00();
};

struct CCharacterGolem_fee10 {
    void FUN_000fed00();
};

struct Rng_fee10 {
    unsigned int s0;
    unsigned int s1;
};

Rng_fee10 *FUN_000964d0();

class CCharacterGolem {
public:
    virtual void vfunc_0_00018b30();
    char pad04[0xf4];
    int f0f8;
    char pad0fc[4];
    int f100, f104, f108, f10c, f110, f114;
    Name8 n118;
    char pad120;
    char b121;
    char pad122[2];
    float f124;
    char b128, b129;
    char pad12a[2];
    float f12c;

    CCharacterGolem() {}
    CCharacterGolem *FUN_000fee10(int arg);
};

CCharacterGolem *CCharacterGolem::FUN_000fee10(int arg)
{
    ((CCharacterGolem_fee10 *)this)->FUN_000fed00();
    f0f8 = arg;
    new (this) CCharacterGolem;
    f100 = 0;
    f104 = 0;
    f108 = 0;
    f10c = 0;
    f110 = 0;
    f114 = 0;
    n118.FUN_0027af00();
    b121 = 0;

    // random float in [1, 2) from the shared multiply-with-carry generator
    Rng_fee10 *rng = FUN_000964d0();
    rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
    rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
    union {
        unsigned int bits;
        float value;
    } r;
    r.bits = (((rng->s0 << 16) + (rng->s1 & 0xffff)) & 0x7fffff) | 0x3f800000;
    b128 = 0;
    b129 = 0;
    f124 = r.value - 1.0f;
    f12c = -DAT_004e0a94;
    double next = DAT_004e0a94 + 0.03333333507180214f;
    DAT_004e0a94 = (float)next;
    if (next >= (*(float*)&DAT_0040d0f0))
        DAT_004e0a94 = DAT_004e0a94 - (*(float*)&DAT_0040d0f0);
    return this;
}
} // namespace fn_000fee10


// 0x000fef20 CCharacterGolem::vfunc_2 (30 B): matches/0x000fef20.cpp
// sym: ??_GCCharacterGolem@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CCharacterGolem::~CCharacterGolem() {}


// 0x000fefa0 FUN_000fefa0 (31 B): matches/0x000fefa0.cpp
// sym: ?FUN_000fefa0@C_fefa0@owners@@QAEHXZ
hulk_intptr owners::C_fefa0::FUN_000fefa0() {
    if (!value)
        Init_000feb20(this, &value);
    return value;
}


// 0x000fefc0 FUN_000fefc0 (31 B): matches/0x000fefc0.cpp
// sym: ?FUN_000fefc0@Obj_fefc0@owners@@QAEHXZ
hulk_intptr owners::Obj_fefc0::FUN_000fefc0() {
    if (value == 0)
        Init_000febc0(this, &value);
    return value;
}

namespace fn_f54027db {

// 0x000ff000 FUN_000ff000 (20 B): matches/0x000ff000.cpp
// sym: ?FUN_000ff000@fn_f54027db@@YAXPAVObj@1@H@Z
void FUN_000ff000(Obj* p, int x) {
    p->method_0022d2b0(x, 0x3727c5ac);
}

} // namespace fn_f54027db

// 0x000ff180 FUN_000ff180 (161 B): equivalent/0x000ff180.cpp [wrapped: conflict: CHand2HandAgent]
// sym: ??0CHand2HandAgent@fn_000ff180@@QAE@H@Z @3b989f0bb5ed @wceb1c3a0fcee
namespace fn_000ff180 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000ff180 @ 0x000ff180
// CHand2HandAgent::CHand2HandAgent @ 0x000ff180
void *__cdecl FUN_0008d690(unsigned int size);

class CAvoidBehaviour_ff180 {
public:
    virtual void AddRef();
    CAvoidBehaviour_ff180 *FUN_00109ba0();
};

class CCharacterAgent_ff180 {
public:
    CCharacterAgent_ff180(int arg);
    virtual void v0_00018b30();
    virtual void v1_00018b40();
    virtual void* v2_000ffeb0(char);
    virtual double v3_000ff2d0(int, int);
    virtual void v4_00102590(int, float, int);
    virtual void v5_000fc4a0(int, int);
    virtual void v6_000ff230(int);
    virtual void v7_000ffde0(char);
    virtual void v8_000fc600(int, int, int);
    virtual void vfunc_9();
    char pad4[0x5c - 4];
};

// equiv-map: ??0AgentBase@@QAE@H@Z = 0x000fc760
class CHand2HandAgent : public CCharacterAgent_ff180 {
public:
    CHand2HandAgent(hulk_intptr arg);
    virtual void vfunc_9();
    CAvoidBehaviour_ff180 *f5c;
    unsigned char b60;
    char pad61[3];
    int f64;
    float f68;
    int f6c;
    float f70;
    char pad74[4];
    unsigned char b78;
    unsigned char b79;
    unsigned char b7a;
    unsigned char b7b;
    unsigned char b7c;
    unsigned char b7d;
    unsigned char b7e;
    unsigned char b7f;
    int f80;
    float f84;
    char pad88[0x174 - 0x88];
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
};

CHand2HandAgent::CHand2HandAgent(hulk_intptr arg) : CCharacterAgent_ff180(arg)
{
    CAvoidBehaviour_ff180 *w = 0;
    void *mem = FUN_0008d690(0x38);
    if (mem != 0)
        w = ((CAvoidBehaviour_ff180 *)mem)->FUN_00109ba0();
    f5c = w;
    w->AddRef();
    b60 = 0;
    f64 = 0;
    f6c = 0;
    b7a = 0;
    b7b = 0;
    b7c = 0;
    b78 = 0;
    f80 = 0;
    b79 = 0;
    f70 = -1.0f;
    b7d = 1;
    b7e = 1;
    b7f = 1;
    f68 = 999.0f;
    f84 = 999.0f;
    f17c = 0;
    f178 = 0;
    f174 = 0;
    f18c = 0;
    f188 = 0;
    f184 = 0;
}
} // namespace fn_000ff180

