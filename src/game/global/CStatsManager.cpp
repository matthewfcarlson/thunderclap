// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ffb0..0x00091af0 (kind game, layer game, confidence high), dominant class CStatsManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6df19d8 {
#define TREE_TU_END }
namespace fn_f6df19d8 {} using namespace fn_f6df19d8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6df19d8 {
class Obj_8ffb0 {
  public:
    char pad[0xc88];
    int mField;
    int Get();
};
class Obj_8ffe0 {
  public:
    char pad[0xc80];
    int count;
};
typedef unsigned int U32_90050;
typedef unsigned long long U64_90050;
} // namespace fn_f6df19d8
extern "C" U64_90050 __cdecl FUN_0027b020(char*);
namespace fn_f6df19d8 {
struct Stat {
    int value;
    char pad[0x3c];
};
struct Stats_900a0 {
    char pad[0x38];
    Stat stats[1];
    void FUN_000900a0(int amount);
};
struct ThisCall_00090050 {
};
class C {
  public:
    char pad[0x38];
    int Get(int id);
};
struct E {
    int v;
    char pad[60];
};
typedef unsigned int u32_901d0;
struct ThisCall_00090130 {
};
struct Entry { int value; char rest[60]; };
struct Owner {
    char header[0x38];
    Entry entries[1];
    int FUN_00090130(int value);
    int FUN_00090200(const char *name, int value);
};
class C_90250 {
  public:
    char pad[0xc80];
    int count;
};
struct Entry_90270 {
    int value;
    char name[0x20];
    char text[0x20];
};
class Registry_90270 {
public:
    char pad0[0xc8c];
    Entry_90270 entries[16];      // 0xc8c
    void FUN_00090270(const char *name, const char *text, int value);
};
struct Slot_90310 {
    int threshold;
    char name[0x40];
};
struct Table_90310 {
    char pad[0xc8c];
    Slot_90310 slot[16];
    const char* Find(int value);
};
struct Slot_903a0 {
    int threshold;
    char pad[0x20];
    char name[0x20];
};
struct Table_903a0 {
    char pad[0xc8c];
    Slot_903a0 slot[16];
    const char* Find(int value);
};
class C_90430 {
  public:
    char pad[0x10cc];
    void* m;
    void Set(void* v);
};
class C_90440 {
  public:
    char pad[0x10cc];
    int m;
};
class X_90450 {
  public:
    char pad[8];
    void Fnf_0027af00();
    X_90450* target();
};
class C_90470 {
    char pad[8];

  public:
    void f();
};
class S_90470 {
  public:
    void Fnh_0027af50();
};
struct V3_90490 {
    int x, y, z;
};
struct Sub_90490 {
    void Get_00059a50(V3_90490* out);
};
struct D {
    char p[0x10];
    Sub_90490* sub;
    char q[0x1b0c - 0x14];
    float f;
};
struct C_90490 {
    char p[0x124];
    D* d;
};
struct G_90490 {
    char p[0x20];
    C_90490* c;
};
extern G_90490* hulk_at_004dd700;
struct T_90490 {
    char pad[0x14];
    int mode;
    char flag;
    char pad2[3];
    V3_90490 a;
    V3_90490 b;
    int i34;
    int i38;
    void F();
};
class Obj_905f0 {
  public:
    char pad[0x19];
    unsigned char active;
    char rest[0xc80 - 0x1a];
    int count;
    void process_00090490();
    void target();
};
struct Text_90630 {
    unsigned int data;
    unsigned int size;
    Text_90630* FUN_0027b0e0(const char* s);
    void FUN_0027af70(Text_90630* other);
    void FUN_0027af50();
};
struct Entry_90630 {
    Text_90630 name;
    Text_90630 value;
    int fourth;
    int third;
    unsigned char spare;
    unsigned char enabled;
    char padding[30];
    int state;
    int fifth;
};
struct Table_90630 {
    Entry_90630 entries[50];
    int count;
    void FUN_00090630(const char* name, const char* value, int third, int fourth, int fifth, int sixth);
};
struct Entry_906f0 {
    void Act_00090490();
};
struct Ent_90720 {
    char pad[0x38];
    int val;
    char pad2[4];
};
struct Vec3_90790 {
    float x, y, z;
};
struct Body_90790 {
    void FUN_00059a50(Vec3_90790 *out);
};
struct Player_90790 {
    char pad00[0x10];
    Body_90790 *body;
};
struct Actor_90790 {
    char pad00[0x124];
    Player_90790 *player;
};
} // namespace fn_f6df19d8
struct World {
    char pad00[0x20];
    Actor_90790 *actor;
};
namespace fn_f6df19d8 {
struct Function_908e0 {
    virtual void f0();
    virtual void f1();
};
void FUN_00090900(const char*, const char*, const char*, int);
struct Callback {
    void invoke(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
class CFEManager_909b0 {
  public:
    void Call(const char*, int);
};
class Function_909b0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_90a30 {
  public:
    void Call(void*);
};
class Dummy_90ab0 {
  public:
    void Call(void*);
};
class Function_90b30 {
  public:
    virtual void f0();
    virtual void f1();
};
class CStatsManager_90bb0 {
  public:
    int Get(const char*);
};
typedef int (CStatsManager_90bb0::*StatsFn)(const char*);
class Function_90bb0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class CActorManager_90c30;
typedef unsigned char(__fastcall* Fn_90c30)(CActorManager_90c30*);
struct CStatsManager_90cd0 { void FUN_00090cd0(char *, char *, int); };
struct Arguments { char *first; char *second; int third; };
struct CStatsManager_90d50 {
    int FUN_00090d50(const char*);
};
struct Function_90d50 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
typedef const char* CP;
class C_90d70 {
  public:
    void Fnf_00090630(CP, CP, int, int, int, int);
    void target();
};
class Item_90db0 {
  public:
    char pad[0x19];
    unsigned char flag;
    char tail[0x26];
};
struct Entry_90df0 {
    void Act_00090790();
};
class CStatsManager_90e70 {
  public:
    void Action(const char*, const char*, int, int, int, int);
};
class CActorManager_90f30 {
  public:
    void Method(const char*, float);
};
struct Pair_90f30 {
    const char* s;
    float f;
};
class CActorManager_90fc0 {
  public:
    void invoke(const char*);
};
class CActorManager_91050 {
  public:
    void invoke(const char*);
};
class CActorManager_910d0 {
  public:
    int act();
};
struct CStatsManager_91160 {
    int invoke(const char*);
};
typedef int (CStatsManager_91160::*StatsMethod)(const char*);
class CActorManager_911e0;
typedef unsigned char(__fastcall* Fn_911e0)(CActorManager_911e0*);
struct CStatsManager_91250 {
    void FUN_00091250(char *, char *, int);
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f6df19d8
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f6df19d8 {
class CStatsManager_91300 {};
typedef void (CStatsManager_91300::*Fn_91300)(const char*, const char*, int, int, int, int);
class Registry_91300 { public:
    void FUN_00091300(const char* a1, CStatsManager_91300* a2, Fn_91300 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_91300;
template<> class Closure6_91300<CStatsManager_91300, void, const char*, const char*, int, int, int, int> : public ScriptFunctionFields { public: virtual void v(); Fn_91300 fn; CStatsManager_91300* owner; Closure6_91300(CStatsManager_91300* o) { owner = o; } };
class Raw_91300 { public: void FUN_00090840(const char*, Fn_91300); };
class CStatsManager_91580 {};
typedef void (CStatsManager_91580::*Fn_91580)(char*, char*, int);
class Registry_91580 { public:
    void FUN_00091580(const char* a1, CStatsManager_91580* a2, Fn_91580 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_91580;
template<> class Closure3_91580<CStatsManager_91580, void, char*, char*, int> : public ScriptFunctionFields { public: virtual void v(); Fn_91580 fn; CStatsManager_91580* owner; Closure3_91580(CStatsManager_91580* o) { owner = o; } };
class Raw_91580 { public: void FUN_00090c50(const char*, Fn_91580); };


// 0x0008ffb0 FUN_0008ffb0 (7 B): matches/0x0008ffb0.cpp
// sym: ?Get@Obj_8ffb0@fn_f6df19d8@@QAEHXZ
int Obj_8ffb0::Get() {
    return mField;
}


// 0x0008ffc0 FUN_0008ffc0 (6 B): matches/0x0008ffc0.cpp
// sym: _FUN_0008ffc0
// data: g_flag_8ffc0 = DAT_004dd838
extern "C" unsigned char FUN_0008ffc0() {
    return (*(unsigned char*)&DAT_004dd838);
}


// 0x0008ffe0 FUN_0008ffe0 (54 B): matches/0x0008ffe0.cpp
// sym: ?target@fn_f6df19d8@@YIXPAVObj_8ffe0@1@@Z
void __fastcall target(Obj_8ffe0* self) {
    int i = 2;
    if (i < self->count) {
        int* p = (int*)(self->pad + 0xb8);
        do {
            *p = 0;
            ++i;
            p += 0x10;
        } while (i < self->count);
    }
}

} // namespace fn_f6df19d8

// 0x00090050 FUN_00090050 (65 B): matches/0x00090050.cpp
// sym: ?FUN_00090050@Table_90050@owners@@QAEHPAD@Z
int owners::Table_90050::FUN_00090050(char* s) {
    if (s == 0 || *s == 0)
        return -1;
    U64_90050 key = FUN_0027b020(s);
    int i = 0;
    owners::Table_90050* p = this;
    while (i < 50) {
        if (key == *(U64_90050*)p)
            return i;
        ++i;
        p = (owners::Table_90050*)((char*)p + 0x40);
    }
    return -1;
}

namespace fn_f6df19d8 {

// 0x000900a0 FUN_000900a0 (109 B): equivalent/0x000900a0.cpp
// sym: ?FUN_000900a0@Stats_900a0@fn_f6df19d8@@QAEXH@Z @2a3cdb6ad24e @w60062e88388b
// STATUS: equivalent (tools/equiv.py level 3: 2676 inputs, branch coverage 10/10)
// FUN_000900a0 @ 0x000900a0
void Stats_900a0::FUN_000900a0(int amount)
{
    int idx = ((owners::Table_90050 *)this)->FUN_00090050((char *)"xp");
    if (idx == -1)
        return;
    int xp = stats[idx].value + amount;
    stats[idx].value = xp;
    if (xp > 999999999)
        stats[idx].value = 999999999;
    if (amount > 0) {
        idx = ((owners::Table_90050 *)this)->FUN_00090050((char *)"xpaccumulated");
        if (idx != -1) {
            int total = stats[idx].value + amount;
            stats[idx].value = total;
            if (total > 999999999)
                stats[idx].value = 999999999;
        }
    }
}


// 0x00090110 FUN_00090110 (31 B): matches/0x00090110.cpp
// sym: @FUN_00090110@4
extern "C" int __fastcall FUN_00090110(void* self) {
    int i = ((owners::Table_90050 *)(((ThisCall_00090050*)(self))))->FUN_00090050((char *)"xp");
    if (i == -1)
        return 0;
    return *(int*)((char*)self + i * 0x40 + 0x38);
}

} // namespace fn_f6df19d8

// 0x00090130 FUN_00090130 (106 B): matches/0x00090130.cpp
// sym: ?FUN_00090130@Stats_90130@owners@@QAEXH@Z
void owners::Stats_90130::FUN_00090130(int v) {
    int i = Find("xp");
    if (i != -1) {
        int* q = (int*)((char*)this + i * 0x40 + 0x38);
        *q = v;
        if (v > 999999999)
            *q = 999999999;
        i = Find("xpaccumulated");
        if (i != -1 && (v == 0 || v > *(int*)((char*)this + i * 0x40 + 0x38))) {
            q = (int*)((char*)this + i * 0x40 + 0x38);
            *q = v;
            if (v > 999999999)
                *q = 999999999;
        }
    }
}

namespace fn_f6df19d8 {

// 0x000901a0 FUN_000901a0 (35 B): matches/0x000901a0.cpp
// sym: ?Get@C@fn_f6df19d8@@QAEHH@Z
int C::Get(int id) {
    int r = ((owners::Table_90050 *)this)->FUN_00090050((char *)(hulk_uintptr)(int)id);
    if (r == -1)
        return 0;
    E* p = (E*)((char*)this + 0x38);
    return p[r].v;
}

} // namespace fn_f6df19d8

// 0x000901d0 FUN_000901d0 (42 B): matches/0x000901d0.cpp
// sym: ?FUN_000901d0@C_901d0@owners@@QAEXHI@Z
void owners::C_901d0::FUN_000901d0(int index, u32_901d0 value) {
    if (index == 0) {
        ((owners::Stats_90130 *)(((ThisCall_00090130*)(this))))->FUN_00090130((int)value);
        return;
    }
    if (index >= 0 && index < 0x32)
        *(u32_901d0*)((char*)this + index * 0x40 + 0x38) = value;
}

namespace fn_f6df19d8 {

// 0x00090200 FUN_00090200 (73 B): equivalent/0x00090200.cpp
// sym: ?FUN_00090200@Owner@fn_f6df19d8@@QAEHPBDH@Z @b0823c803d5b @w3b561952a6c7
// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 4/4)
// FUN_00090200 @ 0x00090200
int Owner::FUN_00090200(const char *name, int value)
{
    if (name[0] == 'x' && name[1] == 'p' && name[2] == '\0')
        return FUN_00090130(value);
    int index = ((owners::Table_90050 *)this)->FUN_00090050((char *)name);
    if (index != -1) {
        entries[index].value = value;
        return index * 64;
    }
    return index;
}


// 0x00090250 FUN_00090250 (29 B): matches/0x00090250.cpp
// sym: ?FUN_00090250@fn_f6df19d8@@YIPAXPAVC_90250@1@PAXH@Z
void* __fastcall FUN_00090250(C_90250* self, void* edx, int index) {
    if (index >= 0 && index < self->count)
        return (char*)self + index * 0x40;
    return 0;
}


// 0x00090270 FUN_00090270 (149 B): equivalent/0x00090270.cpp
// sym: ?FUN_00090270@Registry_90270@fn_f6df19d8@@QAEXPBD0H@Z @a0f0cd317d20 @w0d547cf003cd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// FUN_00090270 @ 0x00090270
// Stores a new named entry in the first free slot (an empty name marks a free slot).
void Registry_90270::FUN_00090270(const char *name, const char *text, int value)
{
    int i = 0;
    while (i < 16 && entries[i].name[0] != 0)
        i++;
    if (i >= 16)
        return;
    Entry_90270 *e = &entries[i];
    e->value = value;
    const char *src = text;
    char *dst = e->text;
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != 0);
    src = name;
    dst = e->name;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != 0);
}


// 0x00090310 FUN_00090310 (138 B): matches/0x00090310.cpp
// sym: ?Find@Table_90310@fn_f6df19d8@@QAEPBDH@Z
// FUN_00090310 @ 0x00090310
const char* Table_90310::Find(int value) {
    int found = -1;
    for (int i = 0; i < 16; i++) {
        if (slot[i].name[0] && value >= slot[i].threshold)
            found = i;
    }
    if (found == -1) return "none";
    return slot[found].name;
}


// 0x000903a0 FUN_000903a0 (138 B): matches/0x000903a0.cpp
// sym: ?Find@Table_903a0@fn_f6df19d8@@QAEPBDH@Z
// FUN_000903a0 @ 0x000903a0
const char* Table_903a0::Find(int value) {
    int found = -1;
    for (int i = 0; i < 16; i++) {
        if (slot[i].name[0] && value >= slot[i].threshold)
            found = i;
    }
    if (found == -1) return "none";
    return slot[found].name;
}


// 0x00090430 FUN_00090430 (13 B): matches/0x00090430.cpp
// sym: ?Set@C_90430@fn_f6df19d8@@QAEXPAX@Z
void C_90430::Set(void* v) {
    m = v;
}


// 0x00090440 FUN_00090440 (7 B): matches/0x00090440.cpp
// sym: @FUN_00090440@4
extern "C" int __fastcall FUN_00090440(C_90440* p) {
    return p->m;
}


// 0x00090450 FUN_00090450 (20 B): matches/0x00090450.cpp
// sym: ?target@X_90450@fn_f6df19d8@@QAEPAV12@XZ
X_90450* X_90450::target() {
    Fnf_0027af00();
    ((X_90450*)((char*)this + 8))->Fnf_0027af00();
    return this;
}


// 0x00090470 FUN_00090470 (19 B): matches/0x00090470.cpp
// sym: ?f@C_90470@fn_f6df19d8@@QAEXXZ
void C_90470::f() {
    ((S_90470*)((char*)this + 8))->Fnh_0027af50();
    ((S_90470*)this)->Fnh_0027af50();
}


// 0x00090490 FUN_00090490 (116 B): matches/0x00090490.cpp
// sym: ?F@T_90490@fn_f6df19d8@@QAEXXZ
void T_90490::F() {
    if (flag)
        return;
    int m = mode;
    flag = 1;
    i34 = 0;
    i38 = 0;
    if (m > 0) {
        if (m > 2) {
            if (m == 3)
                i34 = (int)hulk_at_004dd700->c->d->f;
        } else {
            V3_90490* p = &a;
            hulk_at_004dd700->c->d->sub->Get_00059a50(p);
            b.x = p->x;
            b.y = p->y;
            b.z = p->z;
        }
    }
}


// 0x000905f0 FUN_000905f0 (51 B): matches/0x000905f0.cpp
// sym: ?target@Obj_905f0@fn_f6df19d8@@QAEXXZ
void Obj_905f0::target() {
    int i;
    for (i = 0; i < count; ++i) {
        Obj_905f0* cur = (Obj_905f0*)((char*)this + i * 0x40);
        if (cur->active)
            cur->process_00090490();
    }
}


// 0x00090630 FUN_00090630 (178 B): equivalent/0x00090630.cpp
// sym: ?FUN_00090630@Table_90630@fn_f6df19d8@@QAEXPBD0HHHH@Z @79e7cde6f638 @w801f56583a25
// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 6/6)
// FUN_00090630 @ 0x00090630
void Table_90630::FUN_00090630(const char* name, const char* value, int third, int fourth, int fifth, int sixth) {
    int index = ((owners::Table_90050 *)this)->FUN_00090050((char *)name);
    if (index == -1) {
        index = count;
        if (index >= 50) return;
        Entry_90630& entry = entries[index];
        Text_90630 temp;
        entry.name.FUN_0027af70(temp.FUN_0027b0e0(name));
        temp.FUN_0027af50();
        entry.value.FUN_0027af70(temp.FUN_0027b0e0(value));
        temp.FUN_0027af50();
        ++count;
        entry.state = 0;
        entry.fifth = fifth;
    }
    Entry_90630& entry = entries[index];
    entry.enabled = sixth == 1;
    entry.third = third;
    entry.fourth = fourth;
}

} // namespace fn_f6df19d8

// 0x000906f0 FUN_000906f0 (34 B): matches/0x000906f0.cpp
// sym: ?FUN_000906f0@C_906f0@owners@@QAEXH@Z
void owners::C_906f0::FUN_000906f0(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry_906f0*)((char*)this + i * 64))->Act_00090490();
}


// 0x00090720 FUN_00090720 (106 B): matches/0x00090720.cpp
// sym: ?FUN_00090720@C_90720@owners@@QAEXPBDH@Z
void owners::C_90720::FUN_00090720(const char* s, int n) {
    if (s && *s) {
        if (!strcmp(s, "xp")) {
            Other(n);
            return;
        }
        int i = Find(s);
        if (i != -1) {
            int* p = (int*)((char*)this + i * 0x40 + 0x38);
            n = *p + n;
            *p = n;
            if (n > 999999999)
                *p = 999999999;
        }
    }
}


// 0x00090790 FUN_00090790 (161 B): equivalent/0x00090790.cpp
// sym: ?FUN_00090790@Measure_90790@owners@@QAEXXZ @4f18bd686e64 @w439ca2d18a2b
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 12/12)
// FUN_00090790 @ 0x00090790
// FUN_00090790 @ 0x00090790: measures the player's distance or height from a start point and keeps the best value
void owners::Measure_90790::FUN_00090790()
{
    if (!active)
        return;
    int m = mode;
    active = 0;
    if (m == 1) {
        Vec3_90790 p;
        DAT_004dd700->actor->player->body->FUN_00059a50(&p);
        if (kind == 1)
            value = (int)(__int64)(p.y - startY);
    } else if (m == 2) {
        Vec3_90790 p;
        DAT_004dd700->actor->player->body->FUN_00059a50(&p);
        if (kind == 1)
            value = (int)(__int64)sqrt((p.x - startX) * (p.x - startX) + (p.z - startZ) * (p.z - startZ));
    }
    if (value > best)
        best = value;
}


// 0x000908c0 Method6<CStatsManager,void,const_char_*,const_char_*,int,int,int,int>::vfunc_0 (30 B): matches/0x000908c0.cpp
// sym: ??_G?$Method6@VCStatsManager@@XPBDPBDHHHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CStatsManager, void, const char *, const char *, int, int, int, int>::~Method6() {}


// 0x000908e0 Method6<CStatsManager,void,const_char_*,const_char_*,int,int,int,int>::vfunc_2 (30 B): matches/0x000908e0.cpp
// sym: ?vfunc_2@?$Method6@VCStatsManager@@XPBDPBDHHHH@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CStatsManager, void, const char *, const char *, int, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_00090900(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CStatsManager, void, const char *, const char *, int, int, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x908c0)
#endif

namespace fn_f6df19d8 {

// 0x00090900 FUN_00090900 (53 B): matches/0x00090900.cpp
// sym: ?FUN_00090900@fn_f6df19d8@@YAXPAUCallback@1@PBIIP821@AEXIIIIII@Z@Z
void FUN_00090900(Callback* object, const unsigned* arguments, unsigned unused,
                  void (Callback::*callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned)) {
    unsigned a = *arguments++;
    unsigned b = *arguments++;
    unsigned c = *arguments++;
    unsigned d = *arguments++;
    unsigned e = *arguments++;
    unsigned f = *arguments++;
    (object->*callback)(a, b, c, d, e, f);
}

} // namespace fn_f6df19d8

// 0x00090990 Method2<CStatsManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x00090990.cpp
// sym: ??_G?$Method2@VCStatsManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CStatsManager, void, const char *, int>::~Method2() {}


// 0x000909b0 Method2<CStatsManager,void,const_char_*,int>::vfunc_2 (23 B): matches/0x000909b0.cpp
// sym: ?vfunc_2@?$Method2@VCStatsManager@@XPBDH@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CStatsManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_909b0* m = (CFEManager_909b0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_909b0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CStatsManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90990)
#endif


// 0x00090a10 Method1<CStatsManager,void,const_char_*>::vfunc_0 (30 B): matches/0x00090a10.cpp
// sym: ??_G?$Method1@VCStatsManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CStatsManager, void, const char *>::~Method1() {}


// 0x00090a30 Method1<CStatsManager,void,const_char_*>::vfunc_2 (19 B): matches/0x00090a30.cpp
// sym: ?vfunc_2@?$Method1@VCStatsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CStatsManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_90a30* d = (Dummy_90a30*)a;
    (d->*(*(void (Dummy_90a30::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CStatsManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90a10)
#endif


// 0x00090a90 Method1<CStatsManager,void,int>::vfunc_0 (30 B): matches/0x00090a90.cpp
// sym: ??_G?$Method1@VCStatsManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CStatsManager, void, int>::~Method1() {}


// 0x00090ab0 Method1<CStatsManager,void,int>::vfunc_2 (19 B): matches/0x00090ab0.cpp
// sym: ?vfunc_2@?$Method1@VCStatsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CStatsManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_90ab0* d = (Dummy_90ab0*)a;
    (d->*(*(void (Dummy_90ab0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CStatsManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90a90)
#endif


// 0x00090b10 Method0<CStatsManager,int>::vfunc_0 (30 B): matches/0x00090b10.cpp
// sym: ??_G?$Method0@VCStatsManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CStatsManager, int>::~Method0() {}


// 0x00090b30 Method0<CStatsManager,int>::vfunc_2 (22 B): matches/0x00090b30.cpp
// sym: ?vfunc_2@?$Method0@VCStatsManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CStatsManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<CStatsManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90b10)
#endif


// 0x00090b90 Method1<CStatsManager,int,const_char_*>::vfunc_0 (30 B): matches/0x00090b90.cpp
// sym: ??_G?$Method1@VCStatsManager@@HPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CStatsManager, int, const char *>::~Method1() {}


// 0x00090bb0 Method1<CStatsManager,int,const_char_*>::vfunc_2 (29 B): matches/0x00090bb0.cpp
// sym: ?vfunc_2@?$Method1@VCStatsManager@@HPBD@@UAEXPAX00@Z
template <> void Method1<CStatsManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CStatsManager_90bb0 * obj = (CStatsManager_90bb0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    StatsFn f = (*(StatsFn *)&this->f_1c);
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CStatsManager, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90b90)
#endif


// 0x00090c10 Method0<CStatsManager,bool>::vfunc_0 (30 B): matches/0x00090c10.cpp
// sym: ??_G?$Method0@VCStatsManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CStatsManager, bool>::~Method0() {}


// 0x00090c30 Method0<CStatsManager,bool>::vfunc_2 (22 B): matches/0x00090c30.cpp
// sym: ?vfunc_2@?$Method0@VCStatsManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CStatsManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_90c30 * obj = (CActorManager_90c30 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_90c30 fn = (*(Fn_90c30 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CStatsManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90c10)
#endif


// 0x00090c50 FUN_00090c50 (89 B): matches/0x00090c50.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_00090c50@@QAE@PAD0@Z
namespace fn_00090c50 {
// data: str1_90c50 = DAT_0048e100, str2_90c50 = DAT_0049cad8, str3 = DAT_0049cad8, str4 = DAT_0048e134

char convert_001d04d0(const char*);
class Function_90c50 {
  public:
    virtual void Invoke();
    Function_90c50(char*, int);
    char pad[12];
};
class Method3 : public Function_90c50 {
  public:
    virtual void Invoke();
    char a;
    char b;
    char c;
    char pad2[5];
    char d;
    char pad3[3];
    char* name;
    Method3(char*, char*);
};
Method3::Method3(char* arg, char* n) : Function_90c50(arg, 3) {
    name = n;
    d = convert_001d04d0(((char*)&DAT_0048e100));
    a = convert_001d04d0(((char*)&DAT_0049cad8));
    b = convert_001d04d0(((char*)&DAT_0049cad8));
    c = convert_001d04d0(((char*)&DAT_0048e134));
}
} // namespace fn_00090c50


// 0x00090cb0 Method3<CStatsManager,void,char_*,char_*,int>::vfunc_0 (30 B): matches/0x00090cb0.cpp
// sym: ??_G?$Method3@VCStatsManager@@XPADPADH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CStatsManager, void, char *, char *, int>::~Method3() {}


// 0x00090cd0 Method3<CStatsManager,void,char_*,char_*,int>::vfunc_2 (29 B): equivalent/0x00090cd0.cpp
// sym: ?vfunc_2@?$Method3@VCStatsManager@@XPADPADH@@UAEXPAX00@Z @a7a6d240b96d @w2ac42a573389
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CStatsManager,void,char_*,char_*,int>::vfunc_2 @ 0x00090cd0
template <> void Method3<CStatsManager, void, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CStatsManager_90cd0 * manager = (CStatsManager_90cd0 *)__p0; Arguments * args = (Arguments *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CStatsManager_90cd0::**)(char *, char *, int))&this->f_1c))(args->first, args->second, args->third);
}
#if defined(HULK_PTR64)
template class Method3<CStatsManager, void, char *, char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90cb0)
#endif


// 0x00090d30 Method1<CStatsManager,const_char_*,int>::vfunc_0 (30 B): matches/0x00090d30.cpp
// sym: ??_G?$Method1@VCStatsManager@@PBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CStatsManager, const char *, int>::~Method1() {}


// 0x00090d50 Method1<CStatsManager,const_char_*,int>::vfunc_2 (29 B): matches/0x00090d50.cpp
// sym: ?vfunc_2@?$Method1@VCStatsManager@@HPBD@@UAEXPAX00@Z
template <> void Method1<CStatsManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CStatsManager_90d50 * manager = (CStatsManager_90d50 *)__p0; const char ** argument = (const char **)__p1; int * result = (int *)__p2;

    int (CStatsManager_90d50::*fn)(const char*) = (*(int (CStatsManager_90d50::**)(const char *))&this->f_1c);
    const char* arg = *argument;
    int value = (manager->*fn)(arg);
    if (result)
        *result = value;
}
#if defined(HULK_PTR64)
template class Method1<CStatsManager, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90d30)
#endif

namespace fn_f6df19d8 {

// 0x00090d70 FUN_00090d70 (53 B): matches/0x00090d70.cpp
// sym: ?target@C_90d70@fn_f6df19d8@@QAEXXZ
void C_90d70::target() {
    Fnf_00090630("xp", "TBS_STATS_EXPERIENCE_POINTS", 0, 0, 0, 0);
    Fnf_00090630("xpaccumulated", "TBS_STATS_EXPERIENCE_POINTS", 0, 0, 0, 0);
}

} // namespace fn_f6df19d8

// 0x00090db0 FUN_00090db0 (53 B): matches/0x00090db0.cpp
// sym: ?FUN_00090db0@Obj_90db0@owners@@QAEXHH@Z
void owners::Obj_90db0::FUN_00090db0(int a, int b) {
    int i = 0;
    if (count > 0) {
        Item_90db0* p = (Item_90db0*)this;
        do {
            if (p->flag)
                ((owners::Measure_90790 *)p)->FUN_00090790();
            ++i;
            p = (Item_90db0*)((char*)p + 0x40);
        } while (i < count);
    }
}


// 0x00090df0 FUN_00090df0 (34 B): matches/0x00090df0.cpp
// sym: ?FUN_00090df0@C_90df0@owners@@QAEXH@Z
// Same code shape as 0x000906f0 (propagated; names are from that function)
void owners::C_90df0::FUN_00090df0(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry_90df0*)((char*)this + i * 64))->Act_00090790();
}


// 0x00090e50 Closure6<CStatsManager,void,const_char_*,const_char_*,int,int,int,int>::vfunc_0 (30 B): matches/0x00090e50.cpp
// sym: ??_G?$Method1@VCStatsManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CStatsManager, void, const char *, const char *, int, int, int, int>::~Closure6() {}


// 0x00090e70 Closure6<CStatsManager,void,const_char_*,const_char_*,int,int,int,int>::vfunc_2 (58 B): matches/0x00090e70.cpp
// sym: ?vfunc_2@?$Closure6@VCStatsManager@@XPBDPBDHHHH@@UAEXPAX00@Z
template <> void Closure6<CStatsManager, void, const char *, const char *, int, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const int * args = (const int *)__p1;

    const int* p = args;
    hulk_intptr a = *p++;
    hulk_intptr b = *p++;
    int c = *p++;
    int d = *p++;
    int e = *p++;
    int f = *p++;
    ((*(CStatsManager_90e70 * *)&this->f_20)->*(*(void (CStatsManager_90e70::**)(const char *, const char *, int, int, int, int))&this->f_1c))((const char*)a, (const char*)b, c, d, e, f);
}
#if defined(HULK_PTR64)
template class Closure6<CStatsManager, void, const char *, const char *, int, int, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90e50)
#endif


// 0x00090eb0 FUN_00090eb0 (89 B): matches/0x00090eb0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00090eb0@@QAE@PBDPAVOwner_090eb0@1@P821@AEX0H@Z@Z
namespace fn_00090eb0 {
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


extern void* hulk_at_00400c60[2];
extern void* hulk_at_00400d0c[2];

// Closure2<Owner, void, const char*, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_090eb0 {};
typedef void (Owner_090eb0::*Fn_090eb0)(const char*, int);
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_090eb0 fn;            // 0x1c
    Owner_090eb0* owner;     // 0x20

    Closure2(const char* a1, Owner_090eb0* a2, Fn_090eb0 a3);
};

Closure2::Closure2(const char* a1, Owner_090eb0* a2, Fn_090eb0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00400c60;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_00400d0c;
    owner = a2;
}
} // namespace fn_00090eb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00090f10 Closure2<CStatsManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x00090f10.cpp
// sym: ??_G?$Method1@VCStatsManager@@HPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CStatsManager, void, const char *, int>::~Closure2() {}


// 0x00090f30 Closure2<CStatsManager,void,const_char_*,int>::vfunc_2 (22 B): matches/0x00090f30.cpp
// sym: ?vfunc_2@?$Closure2@VCStatsManager@@XPBDH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CStatsManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_90f30 * p = (Pair_90f30 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_90f30 * *)&this->f_20)->*(*(void (CActorManager_90f30::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CStatsManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90f10)
#endif


// 0x00090f50 FUN_00090f50 (76 B): matches/0x00090f50.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00090f50@@QAE@PBDPAVOwner_90f50@1@P821@AEX0@Z@Z
namespace fn_00090f50 {
// data: key1 = DAT_0048e100, key2 = DAT_0048e0f0

// Closure1<Owner, void, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_90f50 {};
typedef void (Owner_90f50::*Fn_90f50)(const char*);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char lookup_001d04d0(const char*);
class Function_90f50 : public CtorV_001d0480 {
  public:
    Function_90f50(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_90f50 {
  public:
    virtual void fn();
    Fn_90f50 arg2;
    Owner_90f50* arg3;
    Method1(const char* p, Fn_90f50 a) : Function_90f50(p) {
        arg2 = a;
        retType = lookup_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = lookup_001d04d0(((char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    Closure1(const char* p, Owner_90f50* a, Fn_90f50 b);
};
Closure1::Closure1(const char* p, Owner_90f50* a, Fn_90f50 b) : Method1(p, b) {
    arg3 = a;
}
} // namespace fn_00090f50


// 0x00090fa0 Closure1<CStatsManager,void,const_char_*>::vfunc_0 (30 B): matches/0x00090fa0.cpp
// sym: ??_G?$Method0@VCStatsManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CStatsManager, void, const char *>::~Closure1() {}


// 0x00090fc0 Closure1<CStatsManager,void,const_char_*>::vfunc_2 (18 B): matches/0x00090fc0.cpp
// sym: ?vfunc_2@?$Closure1@VCStatsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CStatsManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_90fc0 * *)&this->f_20)->*(*(void (CActorManager_90fc0::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CStatsManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x90fa0)
#endif


// 0x00090fe0 FUN_00090fe0 (76 B): matches/0x00090fe0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_00090fe0@@QAE@PBDPAVCStatsManager@1@P821@AEXH@Z@Z
namespace fn_00090fe0 {
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

// Closure1<Owner, void, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class CStatsManager {};
typedef void (CStatsManager::*Fn_90fe0)(int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(const char* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_90fe0 : public Base {
  public:
    virtual void Invoke(int);
    Fn_90fe0 manager;
    Closure1_90fe0(const char*, Fn_90fe0);
};
Closure1_90fe0::Closure1_90fe0(const char* p, Fn_90fe0 m) : Base(p) {
    manager = m;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
}
class Closure1 : public Closure1_90fe0 {
  public:
    virtual void Invoke(int);
    CStatsManager* extra;
    Closure1(const char*, CStatsManager*, Fn_90fe0);
};
Closure1::Closure1(const char* p, CStatsManager* x, Fn_90fe0 m) : Closure1_90fe0(p, m) {
    extra = x;
}
} // namespace fn_00090fe0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00091030 Closure1<CStatsManager,void,int>::vfunc_0 (30 B): matches/0x00091030.cpp
// sym: ??_G?$Method1@VCStatsManager@@PBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CStatsManager, void, int>::~Closure1() {}


// 0x00091050 Closure1<CStatsManager,void,int>::vfunc_2 (18 B): matches/0x00091050.cpp
// sym: ?vfunc_2@?$Closure1@VCStatsManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CStatsManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_91050 * *)&this->f_20)->*(*(void (CActorManager_91050::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CStatsManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x91030)
#endif


// 0x000910d0 Closure0<CStatsManager,int>::vfunc_2 (23 B): matches/0x000910d0.cpp
// sym: ?vfunc_2@?$Closure0@VCStatsManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CStatsManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_910d0* obj = (*(CActorManager_910d0 * *)&this->f_20);
    int (CActorManager_910d0::*fn)() = (*(int (CActorManager_910d0::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}


// 0x000910f0 FUN_000910f0 (76 B): matches/0x000910f0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000910f0@@QAE@PBDPAVOwner_910f0@1@P821@AEH0@Z@Z
namespace fn_000910f0 {
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

// Closure1<Owner, int, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_910f0 {};
typedef int (Owner_910f0::*Fn_910f0)(const char*);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_910f0 : public CtorV_001d0480 {
  public:
    Function_910f0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_910f0 {
  public:
    virtual void f();
    Fn_910f0 z;
    Method1(const char* s, Fn_910f0 n) : Function_910f0(s) {
        z = n;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void g();
    Owner_910f0* w;
    Closure1(const char*, Owner_910f0*, Fn_910f0);
};
Closure1::Closure1(const char* s, Owner_910f0* n, Fn_910f0 v) : Method1(s, v) {
    w = n;
}
} // namespace fn_000910f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00091160 Closure1<CStatsManager,int,const_char_*>::vfunc_2 (30 B): matches/0x00091160.cpp
// sym: ?vfunc_2@?$Closure1@VCStatsManager@@HPBD@@UAEXPAX00@Z
template <> void Closure1<CStatsManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; int * result = (int *)__p2;

    CStatsManager_91160* obj = (*(CStatsManager_91160 * *)&this->f_20);
    StatsMethod fn = (*(StatsMethod *)&this->f_1c);
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}


// 0x000911e0 Closure0<CStatsManager,bool>::vfunc_2 (23 B): matches/0x000911e0.cpp
// sym: ?vfunc_2@?$Closure0@VCStatsManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CStatsManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_911e0* o = (*(CActorManager_911e0 * *)&this->f_20);
    Fn_911e0 fn = (*(Fn_911e0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}


// 0x00091250 Closure3<CStatsManager,void,char_*,char_*,int>::vfunc_2 (28 B): equivalent/0x00091250.cpp
// sym: ?vfunc_2@?$Closure3@VCStatsManager@@XPADPADH@@UAEXPAX00@Z @737c210bc5da @wcba24441da01
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CStatsManager,void,char_*,char_*,int>::vfunc_2 @ 0x00091250
template <> void Closure3<CStatsManager, void, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * arguments = (Arguments *)__p1;

    ((*(CStatsManager_91250 * *)&this->f_20)->*(*(void (CStatsManager_91250::**)(char *, char *, int))&this->f_1c))(arguments->first, arguments->second, arguments->third);
}


// 0x00091270 FUN_00091270 (76 B): matches/0x00091270.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00091270@@QAE@PBDPAVOwner_91270@1@P821@AEPBDH@Z@Z
namespace fn_00091270 {
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

// Closure1<Owner, const char*, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_91270 {};
typedef const char* (Owner_91270::*Fn_91270)(int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_91270 : public CtorV_001d0480 {
  public:
    Function_91270(const char* s) : CtorV_001d0480(s, 1) { }
    Fn_91270 f1c;
};
class Method1 : public Function_91270 {
  public:
    virtual void invoke();
    Method1(const char* s, Fn_91270 n) : Function_91270(s) {
        f1c = n;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    Owner_91270* f20;
    Closure1(const char* s, Owner_91270* n, Fn_91270 m);
};
Closure1::Closure1(const char* s, Owner_91270* n, Fn_91270 m) : Method1(s, m), f20(n) {}
} // namespace fn_00091270
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000912e0 Closure1<CStatsManager,const_char_*,int>::vfunc_2 (30 B): equivalent/0x000912e0.cpp [wrapped: conflict: CStatsManager; Closure1]
// sym: ?vfunc_2@Closure1@fn_000912e0@@UAEXPAXPAPBDPAH@Z @d5fcbfd9f63b @we4f4b20fb77e
namespace fn_000912e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CStatsManager,const_char_*,int>::vfunc_2 @ 0x000912e0
struct CStatsManager { int FUN_00000000(const char *); };
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const char **value, int *result);
    char pad[0x18];
    int (CStatsManager::*method)(const char *);
    CStatsManager *object;
};
void Closure1::vfunc_2(void *, const char **value, int *result) {
    int resultValue = (object->*method)(*value);
    if (result) *result = resultValue;
}
} // namespace fn_000912e0

namespace fn_f6df19d8 {

// 0x00091300 FUN_00091300 (83 B): equivalent/0x00091300.cpp
// sym: ?FUN_00091300@Registry_91300@fn_f6df19d8@@QAEXPBDPAVCStatsManager_91300@2@P832@AEX00HHHH@Z@Z @4bc1e3274995 @w9c0726dc1580
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00091300 @ 0x00091300
// FUN_00091300 @ 0x00091300  (generated by tools/equiv_gen/reg_helper.py)
void Registry_91300::FUN_00091300(const char* a1, CStatsManager_91300* a2, Fn_91300 a3) {
    typedef Closure6_91300<CStatsManager_91300, void, const char*, const char*, int, int, int, int> Alloc_91300;
    HULK_SIZE32(Alloc_91300, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_91300));
    void* x = 0;
    if (m) {
        ((Raw_91300*)m)->FUN_00090840(a1, a3);
        x = new (m) Closure6_91300<CStatsManager_91300, void, const char*, const char*, int, int, int, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f6df19d8

// 0x00091450 FUN_00091450 (109 B): equivalent/0x00091450.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_00091450@Registry_91450@fn_00091450@@QAEXPBDPAVCStatsManager@2@P832@AEHXZ@Z @3ff288ff63d7 @w803d9112fd6b
namespace fn_00091450 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00091450 @ 0x00091450
// FUN_00091450 @ 0x00091450  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CStatsManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_91450 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_91450(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_91450 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_91450(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_91450 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00091450(const char* name, CStatsManager* owner, int (CStatsManager::*fn)());
};

void Registry_91450::FUN_00091450(const char* name, CStatsManager* owner, int (CStatsManager::*fn)()) {
    typedef Closure0<CStatsManager, int> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CStatsManager, int>));
    Closure0<CStatsManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CStatsManager, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00091450
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00091510 FUN_00091510 (109 B): equivalent/0x00091510.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_00091510@Registry_91510@fn_00091510@@QAEXPBDPAVCStatsManager@2@P832@AE_NXZ@Z @c765d2c34845 @wc15f99b83b98
namespace fn_00091510 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00091510 @ 0x00091510
// FUN_00091510 @ 0x00091510  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CStatsManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_91510 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_91510(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_91510 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_91510(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_91510 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00091510(const char* name, CStatsManager* owner, bool (CStatsManager::*fn)());
};

void Registry_91510::FUN_00091510(const char* name, CStatsManager* owner, bool (CStatsManager::*fn)()) {
    typedef Closure0<CStatsManager, bool> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CStatsManager, bool>));
    Closure0<CStatsManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CStatsManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00091510
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f6df19d8 {

// 0x00091580 FUN_00091580 (83 B): equivalent/0x00091580.cpp
// sym: ?FUN_00091580@Registry_91580@fn_f6df19d8@@QAEXPBDPAVCStatsManager_91580@2@P832@AEXPAD2H@Z@Z @e59dabc869ed @wc27374eea328
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00091580 @ 0x00091580
// FUN_00091580 @ 0x00091580  (generated by tools/equiv_gen/reg_helper.py)
void Registry_91580::FUN_00091580(const char* a1, CStatsManager_91580* a2, Fn_91580 a3) {
    typedef Closure3_91580<CStatsManager_91580, void, char*, char*, int> Alloc_91580;
    HULK_SIZE32(Alloc_91580, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_91580));
    void* x = 0;
    if (m) {
        ((Raw_91580*)m)->FUN_00090c50(a1, a3);
        x = new (m) Closure3_91580<CStatsManager_91580, void, char*, char*, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f6df19d8
