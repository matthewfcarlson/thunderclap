// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001cc5e0..0x001d0360 (kind game, layer game, confidence high), dominant class CScenarioManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fdf9c5a9 {
#define TREE_TU_END }
namespace fn_fdf9c5a9 {} using namespace fn_fdf9c5a9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdf9c5a9 {
struct C_1cc600 {
    void run_000d6fb0(void*);
};
struct B_1cc600 {
    char pad[0x3c];
    C_1cc600* next;
};
struct A_1cc600 {
    char pad[0x0c];
    B_1cc600* child;
};
extern A_1cc600* hulk_at_004dd6ec;
struct Fader_1cc620 {
    void FUN_000d6fb0(char flag);
};
struct Panel_1cc620 {
    char pad0[0x3c];
    Fader_1cc620 *fader;
};
struct Counter_1cc620 {
    int FUN_00088fa0();
};
struct Stats_1cc620 {
    char pad0[0x80];
    Counter_1cc620 counter;
};
struct Hud_1cc620 {
    void FUN_000bc1e0(const char *name);
    void FUN_000b73b0();
    void FUN_000bce10();
    void FUN_000b7760();
    void FUN_000b89e0();
    void FUN_000bc750();
};
} // namespace fn_fdf9c5a9
struct Singleton_4dd6ec {
    char pad0[0xc];
    Panel_1cc620 *panel;
    char pad1[0x20 - 0x10];
    Hud_1cc620 *hud;
    char pad2[0x38 - 0x24];
    Stats_1cc620 *stats;
    Hud_1cc620 *FUN_00086280();
};
namespace fn_fdf9c5a9 {
void __fastcall FUN_001cc600(char flag);
class C_1cc860 {
    char pad[0x1198];

  public:
    float Get() { return *(float*)((char*)this + 0x1198); }
};
struct CScenarioManager_1cc880 {
    char pad[0x119c];
    float value;
    float Get();
};
class CScenarioManager_1cc890 {
  public:
    char pad[0x119c];
    int value;
    void Set(int x);
};
class C_1cc8a0 {
  public:
    char pad[0x1198];
    float a;
    float b;
};
class C_1cc900 {
    char pad[0x1194];

  public:
    int value;
};
struct Part_1cc910 {
    void FUN_001dcab0();
    void FUN_001fc790();
    void FUN_00025410();
};
struct Mgr_1cc910 {
    void FUN_001d1710();
};
struct Link_1cc910;
struct Sub_1cc910 {
    void FUN_00098ed0(Link_1cc910 *l);
};
struct Link_1cc910 {
    char pad0[8];
    Sub_1cc910 *f8;
    Part_1cc910 *fc;
    char pad10[0x20 - 0x10];
    Part_1cc910 *f20;
    char pad24[4];
    Part_1cc910 *f28;
};
class CScenarioManager_1cc910 {
public:
    char pad0[4];
    Link_1cc910 *link;
    char pad8[0x1194 - 8];
    int mode;
    void FUN_001cc910(int m);
};
Mgr_1cc910 *FUN_001d4c90();
class CScenarioManager_1cc990 {
  public:
    char pad[0x10];
    float values[0x40];
    float GetFloat(int index);
};
extern "C" void __cdecl FUN_00267830(char* destination, const char* source, int size);
struct Entry_1cc9d0 { float time; char text[256]; int id; };
struct CScenarioManager_1cc9d0 {
 char padding[0x110];
 Entry_1cc9d0 entries[16];
 int nextId;
 int FUN_001cc9d0(float time, const char* text);
};
struct C_1ccbc0 {
    char pad[0x54];
    int check();
};
struct B_1ccbc0 {
    int x;
    void* p;
};
struct A_1ccbc0 {
    char pad[0x3c];
    B_1ccbc0* b;
    char pad2[0x14];
    C_1ccbc0* c;
};
struct Obj_1ccbc0 {
    char pad[4];
    A_1ccbc0* a;
    hulk_intptr get();
};
class CScenarioManager_1ccc00 {
  public:
    char pad[0x11a4];
    float value;
    float Get();
};
class CScenarioManager_1ccc10 {
  public:
    char pad[0x11a4];
    int mVal;
    void Set(int v);
};
class C_1ccc20 {
    char pad[0x11a8];

  public:
    float value;
};
struct Check {
    int FUN_00086280();
};
struct Object {
    void FUN_000d4820(int zero, void* arg);
};
struct Entry {
    char pad0[4];
    Object* value;
};
class CScenarioManager_1ccca0 {
  public:
    char pad[0x11b0];
    float value;
    float GetValue();
};
class CScenarioManager_1cccb0 {
  public:
    char pad[0x11b0];
    int value;
    void Set(int x);
};
class CScenarioManager_1cce60 {
    char pad[0x13f8];
    char buf[32];

  public:
    void Copy(const void* p);
};
class CScenarioManager_1cce80 {
  public:
    char pad[0x11b4];
    int count;
    float values[16];
    char data[0x20];
    void Add(float value, const void* src);
};
extern void Copy_00267830(void*, const void*, int);
class CScenarioManager_1cced0 {
  public:
    char pad0[0x11a4];
    float value;
    int a;
    int b;
    int c;
    int d;
    int entries[16];
    char pad[0x13f8 - 0x11b8 - 64];
    char flag;
    void init();
};
} // namespace fn_fdf9c5a9
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_fdf9c5a9 {
class CScenarioManager_1ccf70 {
    char pad[0x1418];
    char names[4][32];

  public:
    void SetName(int i, const char* s);
};
class CScenarioManager_1ccfa0 {
  public:
    char pad[0x1498];
    int a[4];
    int f(int i);
};
class CScenarioManager_1ccfc0 {
  public:
    char pad[0x1498];
    int values[4];
    void Set(int index, int value);
};
class C_1ccff0 {
    char pad[0x14a8];

  public:
    unsigned char value;
};
class Target_1cd010 {
    char pad[0x14a9];

  public:
    unsigned char value;
};
extern void* hulk_at_00421e74[];
} // namespace fn_fdf9c5a9
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned);
#endif
namespace fn_fdf9c5a9 {
struct Slot_1cd150 {
    float f;
    char c;
    char pad[0xff];
    int m;
    Slot_1cd150() throw() {
        f = -1.0f;
        c = 0;
        m = -1;
    }
};
struct T_1cd150 {
    char b;
    char pad[0x1f];
};
struct Base_1cd150 {
    void* vptr;
    Base_1cd150() throw() { vptr = hulk_at_00421e74; }
};
class CScenarioManager_1cd150 : public Base_1cd150 {
  public:
    int m4;
    int m8;
    int mc;
    char buf[0x100];
    Slot_1cd150 s[16];
    int m1190;
    int m1194;
    int m1198;
    float m119c;
    char m11a0;
    char pad[0x1418 - 0x11a1];
    T_1cd150 t[4];
    int d[4];
    char m14a8;
    char m14a9;
    CScenarioManager_1cd150() throw();
    void Init_001cced0() throw();
};
struct Target_1cd5b0 {
    void FUN_000d4620(int a, void *buf, int count, int key, float scale);
};
struct P3c_1cd5b0 { char pad[4]; Target_1cd5b0 *target; };
struct P54 { int FUN_00086280(); };
struct Owner_1cd5b0 {
    char pad[0x3c];
    P3c_1cd5b0 *p3c;
    char pad40[0x54 - 0x40];
    P54 *p54;
};
struct Clock_1cd5b0 {  };
} // namespace fn_fdf9c5a9
struct World { char pad[0x20]; Clock_1cd5b0 *clock; };
namespace fn_fdf9c5a9 {
class CScenarioManager_1cd5b0 {
public:
    char pad0[4];
    Owner_1cd5b0 *owner;
    char pad8[0x11a4 - 8];
    int cur;
    int prev;
    int count;
    float acc;
    char pad11b4[0x13f8 - 0x11b4];
    char buf[1];
    void FUN_001cd5b0(float dt);
};
struct ThisCall_001cccc0 {
    void Stop_001cccc0();
};
class Dummy_1cd810 {
  public:
    void Call(void*);
};
class Function_1cd890 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_1cd9a0 {
  public:
    void Call(void*);
};
class CActorManager_1cda20 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1cda20::*MFn_1cda20)(unsigned char);
class Function_1cda20 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_1cdaa0;
typedef unsigned char(__fastcall* Fn_1cdaa0)(CActorManager_1cdaa0*);
class CActorManager_1cdb20;
typedef float (CActorManager_1cdb20::*Fn_1cdb20)(const char*);
class CActorManager_1cdb20 {
  public:
    float Get(const char* s);
};
class CFEManager_1cdbc0 {
  public:
    void Call(const char*, int);
};
class Function_1cdbc0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CScenarioManager_1cdc50 {
  public:
    int method(float, const char*);
};
struct Args {
    float a;
    const char* b;
};
class Function_1cdc50 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CFEManager_1cdcf0 {
  public:
    void Call(const char*, int);
};
class Function_1cdcf0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1cdd70 {
  public:
    void f();
};
class Dummy_1cdde0 {
  public:
    void Call(void*);
};
class CScenarioManager_1cde60 {
  public:
    int Run(const char*);
};
class Function_1cde60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class CFEManager_1cdef0 {
  public:
    void Call(const char*, int);
};
class Function_1cdef0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CScenarioManager_1cdf70 {
  public:
    int SetState(int);
};
class Arg {
  public:
    int value;
};
class Function_1cdf70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CScenarioManager_1cdf70*, Arg*, int*);
};
class CFEManager_1ce000 {
  public:
    void Call(const char*, int);
};
class Function_1ce000 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1ce0d0 {
  public:
    void invoke(const char*);
};
class CActorManager_1ce150 {
  public:
    int act();
};
class CActorManager_1ce1d0 {
  public:
    float Get();
};
typedef float (CActorManager_1ce1d0::*Fn_1ce1d0)();
class CActorManager_1ce270 {
  public:
    void invoke(const char*);
};
class Actor_1ce300 {
  public:
    void fn(unsigned char);
};
class CActorManager_1ce380;
typedef unsigned char(__fastcall* Fn_1ce380)(CActorManager_1ce380*);
class CActorManager_1ce410 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_1ce410::*Fn_1ce410)(const char*);
class CActorManager_1ce4c0 {
  public:
    void Method(const char*, float);
};
struct Pair_1ce4c0 {
    const char* s;
    float f;
};
struct CScenarioManager_1ce560 { char unused; };
struct Arguments { int value; float fraction; };
class CActorManager_1ce610 {
  public:
    void Method(const char*, float);
};
struct Pair_1ce610 {
    const char* s;
    float f;
};
class CActorManager_1ce690 {
  public:
    void run();
};
struct Item {
    int x;
};
extern "C" unsigned char check(Item*);
class Function_1ce6a0 {
  public:
    Function_1ce6a0(const char*, int);
    virtual void invoke();
    char pad[12];
    unsigned char f10;
    char pad2[7];
    unsigned char f18;
    char pad3[3];
    void* target;
};
class Method1_1ce6a0 : public Function_1ce6a0 {
  public:
    Method1_1ce6a0(const char*, void*);
    virtual void invoke();
};
inline Method1_1ce6a0::Method1_1ce6a0(const char* name, void* a) : Function_1ce6a0(name, 1) {
    target = a;
    f18 = check(((Item*)&DAT_0048e100));
    f10 = check(((Item*)&DAT_0048e0f0));
}
class Closure1_1ce6a0 : public Method1_1ce6a0 {
  public:
    Closure1_1ce6a0(const char*, void*, void*);
    virtual void invoke();
    void* arg;
};
class CActorManager_1ce710 {
  public:
    void invoke(const char*);
};
class CScenarioManager_1ce7a0 {
  public:
    int run(const char*);
};
class Function_1ce7a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, int*);
};
class Method1_1ce7a0 : public Function_1ce7a0 {
  public:
    char pad[0x18];
    int (CScenarioManager_1ce7a0::*fn)(const char*);
    CScenarioManager_1ce7a0* obj;
};
class CActorManager_1ce840 {
  public:
    void Method(const char*, float);
};
struct Pair_1ce840 {
    const char* s;
    float f;
};
class CActorManager_1ce970 {
  public:
    void Method(const char*, float);
};
struct Pair_1ce970 {
    const char* s;
    float f;
};
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
void __fastcall __security_check_cookie(unsigned int);
#endif
struct Closure2_1ced50 { char data[36]; void FUN_001ce440(int, int, int); void FUN_001d04a0(); };
struct Owner {
  public:
    char _m_pad_0[0x3c];
    Entry* entry;
    char _m_pad_40[0x14];
    Check* check;
    void FUN_001d26d0(int, Closure2_1ced50*);
    void FUN_001ced50(int a, int b, int c);
};
struct CScenarioManager_1ccc30 {
    char pad0[4];
    Owner* owner;
    char pad1[0x11a0];
    void* stored;
    void FUN_001ccc30(void* volatile arg);
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_fdf9c5a9
inline void* operator new(hulk_uintptr, void* p) throw() {
    return p;
}
namespace fn_fdf9c5a9 {
typedef void (Owner::*Fn_1cf500)(const char*);
class Registry_1cf500 {
  public:
    void FUN_001cf500(const char* a1, Owner* a2, Fn_1cf500 a3);
};
class Closure1_1cf500 {
  public:
    Closure1_1cf500(const char*, Owner*, Fn_1cf500);
};
class CAction_1d0340 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_1d0340* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CScenarioManager_1d0340 : public CAction_1d0340 {
  public:
    CScenarioManager_1d0340* vfunc_2(unsigned char);
};
struct CScenarioManager_nv_1d0340 {
    void FUN_001cf690();
};
extern void thunk_FUN_00267090(CScenarioManager_1d0340*);


// 0x001cc5e0 FUN_001cc5e0 (6 B): matches/0x001cc5e0.cpp
// sym: ?FUN_001cc5e0@fn_fdf9c5a9@@YAHXZ
int FUN_001cc5e0() {
    return 0x40;
}


// 0x001cc600 FUN_001cc600 (32 B): matches/0x001cc600.cpp
// sym: ?target@fn_fdf9c5a9@@YIXPAX@Z
void __fastcall target(void* p) {
    A_1cc600* a = hulk_at_004dd6ec;
    if (a && a->child && a->child->next)
        a->child->next->run_000d6fb0(p);
}

} // namespace fn_fdf9c5a9

// 0x001cc620 FUN_001cc620 (536 B): equivalent/0x001cc620.cpp
// sym: ?FUN_001cc620@CScenarioManager@@QAEXH@Z @b05f070edc4f @w69f26e9efe2a
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 40/40)
// FUN_001cc620 @ 0x001cc620
void CScenarioManager::FUN_001cc620(int next) {
    switch (next) {
    case 1:
        if (DAT_004dd6ec != 0 && DAT_004dd6ec->panel != 0 && DAT_004dd6ec->panel->fader != 0)
            DAT_004dd6ec->panel->fader->FUN_000d6fb0(0);
        this->f_0c = next;
        return;
    case 2: {
        if (DAT_004dd6ec != 0 && DAT_004dd6ec->panel != 0 && DAT_004dd6ec->panel->fader != 0)
            DAT_004dd6ec->panel->fader->FUN_000d6fb0(0);
        Stats_1cc620 *stats = ((Stats_1cc620 *)((owners::C_86310 *)DAT_004dd6ec)->FUN_00086310());
        if (stats->counter.FUN_00088fa0() >= 10) {
            DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("side_mission_fail");
            int cur = this->f_0c;
            this->f_0c = cur;
            return;
        }
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("story_mission_fail");
        DAT_004dd6ec->FUN_00086280()->FUN_000b89e0();
        int cur = this->f_0c;
        this->f_0c = cur;
        return;
    }
    case 9:
        if (DAT_004dd6ec != 0 && DAT_004dd6ec->panel != 0 && DAT_004dd6ec->panel->fader != 0)
            DAT_004dd6ec->panel->fader->FUN_000d6fb0(0);
        this->f_0c = 2;
        return;
    case 3: {
        FUN_001cc600(0);
        Stats_1cc620 *stats = ((Stats_1cc620 *)((owners::C_86310 *)DAT_004dd6ec)->FUN_00086310());
        if (stats->counter.FUN_00088fa0() >= 10) {
            DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("side_mission_success");
            this->f_0c = next;
            return;
        }
        DAT_004dd6ec->FUN_00086280()->FUN_000b7760();
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("story_mission_success");
        this->f_0c = next;
        return;
    }
    case 6: {
        DAT_004dd6ec->FUN_00086280()->FUN_000b73b0();
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("mission_accept");
        int cur = this->f_0c;
        this->f_0c = cur;
        return;
    }
    case 7: {
        DAT_004dd6ec->FUN_00086280()->FUN_000bce10();
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("jump_marker_select");
        int cur = this->f_0c;
        this->f_0c = cur;
        return;
    }
    case 10: {
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("fullscreen_message");
        int cur = this->f_0c;
        this->f_0c = cur;
        return;
    }
    case 11: {
        DAT_004dd6ec->FUN_00086280()->FUN_000bc1e0("fullscreen_question");
        int cur = this->f_0c;
        this->f_0c = cur;
        return;
    }
    case 12:
        DAT_004dd6ec->FUN_00086280()->FUN_000bc750();
        this->f_0c = 2;
        return;
    }
    this->f_0c = next;
}


// 0x001cc840 FUN_001cc840 (4 B): matches/0x001cc840.cpp
// sym: ?FUN_001cc840@CScenarioManager@@QAEIXZ
unsigned int CScenarioManager::FUN_001cc840() {
    return (*(unsigned int *)&this->f_0c);
}

namespace fn_fdf9c5a9 {

// 0x001cc860 FUN_001cc860 (7 B): matches/0x001cc860.cpp
// sym: ?FUN_001cc860@fn_fdf9c5a9@@YIMPAVC_1cc860@1@@Z
float __fastcall FUN_001cc860(C_1cc860* self) {
    return self->Get();
}

} // namespace fn_fdf9c5a9

// 0x001cc870 FUN_001cc870 (13 B): matches/0x001cc870.cpp
// sym: ?FUN_001cc870@CScenarioManager@@QAEXH@Z
void CScenarioManager::FUN_001cc870(int v) {
    this->f_1198 = v;
}

namespace fn_fdf9c5a9 {

// 0x001cc880 FUN_001cc880 (7 B): matches/0x001cc880.cpp
// sym: ?Get@CScenarioManager_1cc880@fn_fdf9c5a9@@QAEMXZ
float CScenarioManager_1cc880::Get() {
    return value;
}


// 0x001cc890 FUN_001cc890 (13 B): matches/0x001cc890.cpp
// sym: ?Set@CScenarioManager_1cc890@fn_fdf9c5a9@@QAEXH@Z
void CScenarioManager_1cc890::Set(int x) {
    value = x;
}


// 0x001cc8a0 FUN_001cc8a0 (53 B): matches/0x001cc8a0.cpp
// sym: ?FUN_001cc8a0@fn_fdf9c5a9@@YIMPAVC_1cc8a0@1@@Z
// data: gZero_1cc8a0 = DAT_003f32e0
hulk_freg __fastcall FUN_001cc8a0(C_1cc8a0* p) {
    if (*(int*)&p->b == (int)0xbf800000)
        return p->a;
    hulk_freg x = p->b - p->a;
    if (x < DAT_003f32e0)
        x = DAT_003f32e0;
    return x;
}

} // namespace fn_fdf9c5a9

// 0x001cc8e0 FUN_001cc8e0 (13 B): matches/0x001cc8e0.cpp
// sym: ?FUN_001cc8e0@CScenarioManager@@QAEXD@Z
void CScenarioManager::FUN_001cc8e0(char v) {
    this->f_11a0 = v;
}


// 0x001cc8f0 FUN_001cc8f0 (7 B): matches/0x001cc8f0.cpp
// sym: ?FUN_001cc8f0@CScenarioManager@@QAEDXZ
char CScenarioManager::FUN_001cc8f0() {
    return this->f_11a0;
}

namespace fn_fdf9c5a9 {

// 0x001cc900 FUN_001cc900 (7 B): matches/0x001cc900.cpp
// sym: ?target@fn_fdf9c5a9@@YIHPAVC_1cc900@1@@Z
int __fastcall target(C_1cc900* p) {
    return p->value;
}


// 0x001cc910 FUN_001cc910 (116 B): matches/0x001cc910.cpp
// sym: ?FUN_001cc910@CScenarioManager_1cc910@fn_fdf9c5a9@@QAEXH@Z
// FUN_001cc910 @ 0x001cc910
void CScenarioManager_1cc910::FUN_001cc910(int m)
{
    mode = m;
    if (link != 0 && link->fc != 0)
        link->fc->FUN_001dcab0();
    if (link != 0 && link->f28 != 0)
        link->f28->FUN_001fc790();
    if (link != 0 && link->f20 != 0)
        link->f20->FUN_00025410();
    Link_1cc910 *l = link;
    if (l != 0 && l->f8 != 0)
        l->f8->FUN_00098ed0(l);
    Mgr_1cc910 *mgr = FUN_001d4c90();
    if (mgr != 0)
        mgr->FUN_001d1710();
}


// 0x001cc990 FUN_001cc990 (29 B): matches/0x001cc990.cpp
// sym: ?GetFloat@CScenarioManager_1cc990@fn_fdf9c5a9@@QAEMH@Z
// data: gDefault = DAT_003f32e0
float CScenarioManager_1cc990::GetFloat(int index) {
    if (index >= 0 && index < 0x40)
        return values[index];
    return DAT_003f32e0;
}

} // namespace fn_fdf9c5a9

// 0x001cc9b0 FUN_001cc9b0 (24 B): matches/0x001cc9b0.cpp
// sym: ?FUN_001cc9b0@CScenarioManager@@QAEXHM@Z
void CScenarioManager::FUN_001cc9b0(int i, float v) {
    if (i >= 0 && i < 0x40)
        *(float*)((char*)this + i * 4 + 0x10) = v;
}

namespace fn_fdf9c5a9 {

// 0x001cc9d0 FUN_001cc9d0 (170 B): equivalent/0x001cc9d0.cpp
// sym: ?FUN_001cc9d0@CScenarioManager_1cc9d0@fn_fdf9c5a9@@QAEHMPBD@Z @a9b47858c903 @w8832aaff6254
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001cc9d0 @ 0x001cc9d0
int CScenarioManager_1cc9d0::FUN_001cc9d0(float time, const char* text) {
 if (time < 0.0f) return -1;
 const char* end = text;
 while (*end) ++end;
 if (end-text >= 256) return -1;
 for (int i=0; i<16; ++i) {
  if (entries[i].time == -1.0f) {
   entries[i].time = time;
   FUN_00267830(entries[i].text, text, 256);
   entries[i].id = nextId;
   ++nextId;
   return entries[i].id;
  }
 }
 return -1;
}

} // namespace fn_fdf9c5a9

// 0x001cca80 FUN_001cca80 (73 B): matches/0x001cca80.cpp
// sym: ?FUN_001cca80@CScenarioManager@@QAEXH@Z
void CScenarioManager::FUN_001cca80(int id) {
    int i;
    for (i = 0; i < 16; ++i) {
        if (*(int*)((char*)this + 0x214 + i * 0x108) == id) {
            char* p = (char*)this + 0x110 + i * 0x108;
            *(int*)p = (int)0xbf800000;
            p[4] = 0;
            *(int*)(p + 0x104) = -1;
            return;
        }
    }
}


// 0x001ccb80 FUN_001ccb80 (58 B): matches/0x001ccb80.cpp
// sym: ?FUN_001ccb80@C_1ccb80@owners@@QAEXXZ
void owners::C_1ccb80::FUN_001ccb80() {
    char* p = (char*)this + 0x214;
    int i = 0x10;
    do {
        *(int*)(p - 0x104) = (int)0xbf800000;
        *(char*)(p - 0x100) = 0;
        *(int*)p = -1;
        p += 0x108;
        --i;
    } while (i != 0);
    *(int*)((char*)this + 0x1190) = 0;
}

namespace fn_fdf9c5a9 {

// 0x001ccbc0 FUN_001ccbc0 (49 B): matches/0x001ccbc0.cpp
// sym: ?get@Obj_1ccbc0@fn_fdf9c5a9@@QAEHXZ
hulk_intptr Obj_1ccbc0::get() {
    if (this->a && this->a->c && this->a->c->check()) {
        A_1ccbc0* q = this->a;
        if (q->b) {
            void* p = q->b->p;
            if (p)
                return (hulk_intptr)p;
        }
    }
    return 0;
}


// 0x001ccc00 FUN_001ccc00 (7 B): matches/0x001ccc00.cpp
// sym: ?Get@CScenarioManager_1ccc00@fn_fdf9c5a9@@QAEMXZ
float CScenarioManager_1ccc00::Get() {
    return value;
}


// 0x001ccc10 FUN_001ccc10 (13 B): matches/0x001ccc10.cpp
// sym: ?Set@CScenarioManager_1ccc10@fn_fdf9c5a9@@QAEXH@Z
void CScenarioManager_1ccc10::Set(int v) {
    mVal = v;
}


// 0x001ccc20 FUN_001ccc20 (7 B): matches/0x001ccc20.cpp
// sym: ?target@fn_fdf9c5a9@@YIMPAVC_1ccc20@1@@Z
float __fastcall target(C_1ccc20* self) {
    return self->value;
}


// 0x001ccc30 FUN_001ccc30 (75 B): matches/0x001ccc30.cpp
// sym: ?FUN_001ccc30@CScenarioManager_1ccc30@fn_fdf9c5a9@@QAEXRAX@Z
void CScenarioManager_1ccc30::FUN_001ccc30(void* volatile arg) {
    stored = arg;
    Object* object;
    if (owner && owner->check && owner->check->FUN_00086280() && owner->entry && owner->entry->value)
        object = owner->entry->value;
    else
        object = 0;
    object->FUN_000d4820(0, arg);
}

} // namespace fn_fdf9c5a9

// 0x001ccc80 FUN_001ccc80 (7 B): matches/0x001ccc80.cpp
// sym: ?FUN_001ccc80@CScenarioManager@@QAEHXZ
int CScenarioManager::FUN_001ccc80() {
    return this->f_11ac;
}


// 0x001ccc90 FUN_001ccc90 (13 B): matches/0x001ccc90.cpp
// sym: ?FUN_001ccc90@CScenarioManager@@QAEXH@Z
void CScenarioManager::FUN_001ccc90(int x) {
    this->f_11ac = x;
}

namespace fn_fdf9c5a9 {

// 0x001ccca0 FUN_001ccca0 (7 B): matches/0x001ccca0.cpp
// sym: ?GetValue@CScenarioManager_1ccca0@fn_fdf9c5a9@@QAEMXZ
float CScenarioManager_1ccca0::GetValue() {
    return value;
}


// 0x001cccb0 FUN_001cccb0 (13 B): matches/0x001cccb0.cpp
// sym: ?Set@CScenarioManager_1cccb0@fn_fdf9c5a9@@QAEXH@Z
void CScenarioManager_1cccb0::Set(int x) {
    value = x;
}


// 0x001cce60 FUN_001cce60 (25 B): matches/0x001cce60.cpp
// sym: ?Copy@CScenarioManager_1cce60@fn_fdf9c5a9@@QAEXPBX@Z
void CScenarioManager_1cce60::Copy(const void* p) {
    CopyBytes(buf, p, 32);
}


// 0x001cce80 FUN_001cce80 (74 B): matches/0x001cce80.cpp
// sym: ?Add@CScenarioManager_1cce80@fn_fdf9c5a9@@QAEXMPBX@Z
void CScenarioManager_1cce80::Add(float value, const void* src) {
    if (count < 16) {
        values[count] = value;
        Copy_00267830(data + count * 0x20, src, 0x20);
        ++count;
    }
}


// 0x001cced0 FUN_001cced0 (77 B): matches/0x001cced0.cpp
// sym: ?init@CScenarioManager_1cced0@fn_fdf9c5a9@@QAEXXZ
void CScenarioManager_1cced0::init() {
    int i;
    for (i = 0; i < 16; i++) {
        entries[i] = 0;
        *((char*)this + 0x11f8 + i * 0x20) = 0;
    }
    flag = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    value = 0.75f;
}

} // namespace fn_fdf9c5a9

// 0x001ccf50 FUN_001ccf50 (31 B): matches/0x001ccf50.cpp
// sym: ?FUN_001ccf50@CScenarioManager@@QAEPAHH@Z
int* CScenarioManager::FUN_001ccf50(int x) {
    if (x >= 0 && x < 4)
        return (int*)((int*)((char*)this + x * 0x20 + 0x1418));
    return (int*)(0);
}

namespace fn_fdf9c5a9 {

// 0x001ccf70 FUN_001ccf70 (42 B): matches/0x001ccf70.cpp
// sym: ?SetName@CScenarioManager_1ccf70@fn_fdf9c5a9@@QAEXHPBD@Z
void CScenarioManager_1ccf70::SetName(int i, const char* s) {
    if (i >= 0 && i < 4)
        strncpy(names[i], s, 32);
}


// 0x001ccfa0 FUN_001ccfa0 (28 B): matches/0x001ccfa0.cpp
// sym: ?f@CScenarioManager_1ccfa0@fn_fdf9c5a9@@QAEHH@Z
int CScenarioManager_1ccfa0::f(int i) {
    if (i >= 0 && i < 4)
        return a[i];
    return 0;
}


// 0x001ccfc0 FUN_001ccfc0 (27 B): matches/0x001ccfc0.cpp
// sym: ?Set@CScenarioManager_1ccfc0@fn_fdf9c5a9@@QAEXHH@Z
void CScenarioManager_1ccfc0::Set(int index, int value) {
    if (index >= 0 && index < 4)
        values[index] = value;
}

} // namespace fn_fdf9c5a9

// 0x001ccfe0 FUN_001ccfe0 (13 B): matches/0x001ccfe0.cpp
// sym: ?FUN_001ccfe0@CScenarioManager@@QAEXE@Z
void CScenarioManager::FUN_001ccfe0(unsigned char v) {
    (*(unsigned char *)&this->f_14a8) = v;
}

namespace fn_fdf9c5a9 {

// 0x001ccff0 FUN_001ccff0 (7 B): matches/0x001ccff0.cpp
// sym: ?target@fn_fdf9c5a9@@YIEPAVC_1ccff0@1@@Z
unsigned char __fastcall target(C_1ccff0* self) {
    return self->value;
}


// 0x001cd010 FUN_001cd010 (7 B): matches/0x001cd010.cpp
// sym: ?FUN_001cd010@fn_fdf9c5a9@@YIEPAVTarget_1cd010@1@@Z
unsigned char __fastcall FUN_001cd010(Target_1cd010* self) {
    return self->value;
}


// 0x001cd150 FUN_001cd150 (202 B): matches/0x001cd150.cpp
// sym: ??0CScenarioManager_1cd150@fn_fdf9c5a9@@QAE@XZ
CScenarioManager_1cd150::CScenarioManager_1cd150() throw() {
    m4 = 0;
    mc = 0;
    m1198 = 0;
    m119c = -1.0f;
    m11a0 = 0;
    m1194 = 0;
    m14a8 = 0;
    m14a9 = 0;
    for (int i = 0; i < 0x40; i++)
        ((int*)buf)[i] = 0;
    {
        char* p = (char*)&s[0].m;
        for (int i = 0; i < 16; i++) {
            *(float*)(p - 0x104) = -1.0f;
            *(char*)(p - 0x100) = 0;
            *(int*)p = -1;
            p += 0x108;
        }
    }
    m1190 = 0;
    Init_001cced0();
    for (int i = 0; i < 4; i++) {
        t[i].b = 0;
        d[i] = 0;
    }
}

} // namespace fn_fdf9c5a9

// 0x001cd3d0 FUN_001cd3d0 (44 B): matches/0x001cd3d0.cpp
// sym: ?FUN_001cd3d0@Obj_1cd3d0@owners@@QAEXH@Z
void owners::Obj_1cd3d0::FUN_001cd3d0(hulk_intptr value) {
    field8 = ((int)value);
    for (int i = 0; i < 0x40; ++i)
        data[i] = 0;
    last = 0;
    Tail(1);
}

// 0x001cd400 thunk_FUN_001cced0 (5 B): not yet verified
namespace fn_fdf9c5a9 {

// 0x001cd5b0 FUN_001cd5b0 (153 B): equivalent/0x001cd5b0.cpp
// sym: ?FUN_001cd5b0@CScenarioManager_1cd5b0@fn_fdf9c5a9@@QAEXM@Z @4febb218ad13 @wba03d5f6f5a2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001cd5b0 @ 0x001cd5b0
void CScenarioManager_1cd5b0::FUN_001cd5b0(float dt)
{
    acc = dt + acc;
    prev = cur;
    count++;
    if (owner && owner->p54 && owner->p54->FUN_00086280()) {
        P3c_1cd5b0 *p = owner->p3c;
        if (p) {
            Target_1cd5b0 *t = p->target;
            if (t && count > 2)
                t->FUN_000d4620(0, buf, count, *((int *)((owners::Palette_25930 *)(DAT_004dd700->clock))->FUN_00025930((unsigned int *)(&dt), 3)), -1.0f);
        }
    }
}

} // namespace fn_fdf9c5a9

// 0x001cd650 FUN_001cd650 (92 B): matches/0x001cd650.cpp
// sym: ?FUN_001cd650@Thing_1cd650@owners@@QAEXM@Z
// data: Zero_1cd650 = DAT_003f32e0
void owners::Thing_1cd650::FUN_001cd650(float dt) {
    if (timer != (*(float*)&DAT_003f32e0)) {
        timer = timer - dt;
        if (timer <= (*(float*)&DAT_003f32e0)) {
            timer = 0.0f;
            ((ThisCall_001cccc0*)(this))->Stop_001cccc0();
            b = 0;
            a = 0;
        }
    }
}


// 0x001cd7f0 Method1<CScenarioManager,void,int>::vfunc_0 (30 B): matches/0x001cd7f0.cpp
// sym: ??_G?$Method1@VCScenarioManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager, void, int>::~Method1() {}


// 0x001cd810 Method1<CScenarioManager,void,int>::vfunc_2 (19 B): matches/0x001cd810.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CScenarioManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1cd810* d = (Dummy_1cd810*)a;
    (d->*(*(void (Dummy_1cd810::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cd7f0)
#endif


// 0x001cd870 Method0<CScenarioManager,int>::vfunc_0 (30 B): matches/0x001cd870.cpp
// sym: ??_G?$Method0@VCScenarioManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CScenarioManager, int>::~Method0() {}


// 0x001cd890 Method0<CScenarioManager,int>::vfunc_2 (22 B): matches/0x001cd890.cpp
// sym: ?vfunc_2@?$Method0@VCScenarioManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CScenarioManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)&this->f_1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<CScenarioManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cd870)
#endif


// 0x001cd8f0 Method0<CScenarioManager,float>::vfunc_0 (30 B): matches/0x001cd8f0.cpp
// sym: ??_G?$Method0@VCScenarioManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CScenarioManager, float>::~Method0() {}
#if defined(HULK_PTR64)
template class Method0<CScenarioManager, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cd8f0)
#endif


// 0x001cd910 Method0<CScenarioManager,float>::vfunc_2 (34 B): matches/0x001cd910.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_1cd910@fn_001cd910@@UAEXPAX0PAM@Z
namespace fn_001cd910 {
// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_1cd910 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_1cd910::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_001cd910


// 0x001cd980 Method1<CScenarioManager,void,float>::vfunc_0 (30 B): matches/0x001cd980.cpp
// sym: ??_G?$Method1@VCScenarioManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager, void, float>::~Method1() {}


// 0x001cd9a0 Method1<CScenarioManager,void,float>::vfunc_2 (19 B): matches/0x001cd9a0.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CScenarioManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1cd9a0* d = (Dummy_1cd9a0*)a;
    (d->*(*(void (Dummy_1cd9a0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cd980)
#endif


// 0x001cda00 Method1<CScenarioManager,void,bool>::vfunc_0 (30 B): matches/0x001cda00.cpp
// sym: ??_G?$Method1@VCScenarioManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager, void, bool>::~Method1() {}


// 0x001cda20 Method1<CScenarioManager,void,bool>::vfunc_2 (21 B): matches/0x001cda20.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CScenarioManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cda20 * obj = (CActorManager_1cda20 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1cda20 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cda00)
#endif


// 0x001cda80 Method0<CScenarioManager,bool>::vfunc_0 (30 B): matches/0x001cda80.cpp
// sym: ??_G?$Method0@VCScenarioManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CScenarioManager, bool>::~Method0() {}


// 0x001cdaa0 Method0<CScenarioManager,bool>::vfunc_2 (22 B): matches/0x001cdaa0.cpp
// sym: ?vfunc_2@?$Method0@VCScenarioManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CScenarioManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cdaa0 * obj = (CActorManager_1cdaa0 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_1cdaa0 fn = (*(Fn_1cdaa0 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CScenarioManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cda80)
#endif


// 0x001cdb00 Method1<CScenarioManager,float,int>::vfunc_0 (30 B): matches/0x001cdb00.cpp
// sym: ??_G?$Method1@VCScenarioManager@@MH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager, float, int>::~Method1() {}


// 0x001cdb20 Method1<CScenarioManager,float,int>::vfunc_2 (42 B): matches/0x001cdb20.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@MH@@UAEXPAX00@Z
// Same code shape as 0x0002c760 (propagated; names are from that function)
template <> void Method1<CScenarioManager, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cdb20 * a = (CActorManager_1cdb20 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1cdb20 f = (*(Fn_1cdb20 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager, float, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdb00)
#endif


// 0x001cdba0 Method2<CScenarioManager,void,int,float>::vfunc_0 (30 B): matches/0x001cdba0.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XHM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CScenarioManager, void, int, float>::~Method2() {}


// 0x001cdbc0 Method2<CScenarioManager,void,int,float>::vfunc_2 (23 B): matches/0x001cdbc0.cpp
// sym: ?vfunc_2@?$Method2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CScenarioManager, void, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1cdbc0* m = (CFEManager_1cdbc0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1cdbc0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CScenarioManager, void, int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdba0)
#endif


// 0x001cdc30 Method2<CScenarioManager,int,float,const_char_*>::vfunc_0 (30 B): matches/0x001cdc30.cpp
// sym: ??_G?$Method2@VCScenarioManager@@HMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CScenarioManager, int, float, const char *>::~Method2() {}


// 0x001cdc50 Method2<CScenarioManager,int,float,const_char_*>::vfunc_2 (39 B): matches/0x001cdc50.cpp
// sym: ?vfunc_2@?$Method2@VCScenarioManager@@HMPBD@@UAEXPAX00@Z
template <> void Method2<CScenarioManager, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CScenarioManager_1cdc50 * obj = (CScenarioManager_1cdc50 *)__p0; Args * args = (Args *)__p1; int * result = (int *)__p2;

    int (CScenarioManager_1cdc50::*f)(float, const char*) = (*(int (CScenarioManager_1cdc50::**)(float, const char *))&this->f_1c);
    float a = args->a;
    const char* b = args->b;
    int r = (obj->*f)(a, b);
    if (result)
        *result = r;
}
#if defined(HULK_PTR64)
template class Method2<CScenarioManager, int, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdc30)
#endif


// 0x001cdcd0 Method2<CScenarioManager,void,float,const_char_*>::vfunc_0 (30 B): matches/0x001cdcd0.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CScenarioManager, void, float, const char *>::~Method2() {}


// 0x001cdcf0 Method2<CScenarioManager,void,float,const_char_*>::vfunc_2 (23 B): matches/0x001cdcf0.cpp
// sym: ?vfunc_2@?$Method2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CScenarioManager, void, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1cdcf0* m = (CFEManager_1cdcf0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1cdcf0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CScenarioManager, void, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdcd0)
#endif


// 0x001cdd50 Method0<CScenarioManager,void>::vfunc_0 (30 B): matches/0x001cdd50.cpp
// sym: ??_G?$Method0@VCScenarioManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CScenarioManager, void>::~Method0() {}


// 0x001cdd70 Method0<CScenarioManager,void>::vfunc_2 (12 B): matches/0x001cdd70.cpp
// sym: ?vfunc_2@?$Method0@VCScenarioManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CScenarioManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1cdd70 * a = (CActorManager_1cdd70 *)__p0;

    (a->*(*(void (CActorManager_1cdd70::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CScenarioManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdd50)
#endif


// 0x001cddc0 Method1<CScenarioManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001cddc0.cpp
// sym: ??_G?$Method1@VCScenarioManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager, void, const char *>::~Method1() {}


// 0x001cdde0 Method1<CScenarioManager,void,const_char_*>::vfunc_2 (19 B): matches/0x001cdde0.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CScenarioManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1cdde0* d = (Dummy_1cdde0*)a;
    (d->*(*(void (Dummy_1cdde0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cddc0)
#endif


// 0x001cde40 Method1<CScenarioManager,const_char_*,int>::vfunc_0 (30 B): matches/0x001cde40.cpp
// sym: ??_G?$Method1@VCScenarioManager@@PBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager, const char *, int>::~Method1() {}


// 0x001cde60 Method1<CScenarioManager,const_char_*,int>::vfunc_2 (29 B): matches/0x001cde60.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@PBDH@@UAEXPAX00@Z
template <> void Method1<CScenarioManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CScenarioManager_1cde60 * obj = (CScenarioManager_1cde60 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CScenarioManager_1cde60::*f)(const char*) = (*(int (CScenarioManager_1cde60::**)(const char *))&this->f_1c);
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cde40)
#endif


// 0x001cded0 Method2<CScenarioManager,void,int,const_char_*>::vfunc_0 (30 B): matches/0x001cded0.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CScenarioManager, void, int, const char *>::~Method2() {}


// 0x001cdef0 Method2<CScenarioManager,void,int,const_char_*>::vfunc_2 (23 B): matches/0x001cdef0.cpp
// sym: ?vfunc_2@?$Method2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CScenarioManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1cdef0* m = (CFEManager_1cdef0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1cdef0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CScenarioManager, void, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cded0)
#endif


// 0x001cdf50 Method1<CScenarioManager,eMissionObjectiveState,int>::vfunc_0 (30 B): matches/0x001cdf50.cpp
// sym: ??_G?$Method1@VCScenarioManager@@W4eMissionObjectiveState@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CScenarioManager,eMissionObjectiveState, int>::~Method1() {}


// 0x001cdf70 Method1<CScenarioManager,eMissionObjectiveState,int>::vfunc_2 (29 B): matches/0x001cdf70.cpp
// sym: ?vfunc_2@?$Method1@VCScenarioManager@@PBDH@@UAEXPAX00@Z
template <> void Method1<CScenarioManager,eMissionObjectiveState, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CScenarioManager_1cdf70 * obj = (CScenarioManager_1cdf70 *)__p0; Arg * arg = (Arg *)__p1; int * out = (int *)__p2;

    int (CScenarioManager_1cdf70::*fn)(int) = (*(int (CScenarioManager_1cdf70::**)(int))&this->f_1c);
    int v = arg->value;
    int r = (obj->*fn)(v);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CScenarioManager,eMissionObjectiveState, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdf50)
#endif


// 0x001cdfe0 Method2<CScenarioManager,void,int,int>::vfunc_0 (30 B): matches/0x001cdfe0.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CScenarioManager, void, int, int>::~Method2() {}


// 0x001ce000 Method2<CScenarioManager,void,int,int>::vfunc_2 (23 B): matches/0x001ce000.cpp
// sym: ?vfunc_2@?$Method2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CScenarioManager, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1ce000* m = (CFEManager_1ce000*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1ce000::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CScenarioManager, void, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1cdfe0)
#endif


// 0x001ce020 FUN_001ce020 (64 B): matches/0x001ce020.cpp
// sym: ?FUN_001ce020@Obj_1ce020@owners@@QAEXM@Z
void owners::Obj_1ce020::FUN_001ce020(float x) {
    if (Check()) {
        if (!flag)
            value += x;
        First(x);
        Second(x);
    }
}


// 0x001ce060 FUN_001ce060 (76 B): matches/0x001ce060.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ce060@@QAE@PAXHH@Z
namespace fn_001ce060 {
// data: labelA = DAT_0048e100, labelB = DAT_0048e134

extern "C++" __declspec(nothrow) unsigned char __cdecl getFlag_001d04d0(const char*);
class Function_1ce060 {
  public:
    virtual void f();
    Function_1ce060(void*, int);
    char pad[12];
};
class Method1 : public Function_1ce060 {
  public:
    virtual void f();
    char m10;
    char gap11[7];
    char m18;
    char gap19[3];
    int m1c;
    Method1(void*, int, int);
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    int m20;
    Closure1(void*, int, int);
};
inline Method1::Method1(void* p, int x, int y) : Function_1ce060(p, 1) {
    m1c = y;
    m18 = getFlag_001d04d0(((char*)&DAT_0048e100));
    m10 = getFlag_001d04d0(((char*)&DAT_0048e134));
}
Closure1::Closure1(void* p, int x, int y) : Method1(p, x, y) {
    m20 = x;
}
} // namespace fn_001ce060


// 0x001ce0b0 Closure1<CScenarioManager,void,int>::vfunc_0 (30 B): matches/0x001ce0b0.cpp
// sym: ??_G?$Method0@VCScenarioManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CScenarioManager, void, int>::~Closure1() {}


// 0x001ce0d0 Closure1<CScenarioManager,void,int>::vfunc_2 (18 B): matches/0x001ce0d0.cpp
// sym: ?vfunc_2@?$Closure1@VCScenarioManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CScenarioManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce0d0 * *)&this->f_20)->*(*(void (CActorManager_1ce0d0::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce0b0)
#endif


// 0x001ce130 Closure0<CScenarioManager,int>::vfunc_0 (30 B): matches/0x001ce130.cpp
// sym: ??_G?$Method1@VCScenarioManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CScenarioManager, int>::~Closure0() {}


// 0x001ce150 Closure0<CScenarioManager,int>::vfunc_2 (23 B): matches/0x001ce150.cpp
// sym: ?vfunc_2@?$Closure0@VCScenarioManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CScenarioManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_1ce150* obj = (*(CActorManager_1ce150 * *)&this->f_20);
    int (CActorManager_1ce150::*fn)() = (*(int (CActorManager_1ce150::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Closure0<CScenarioManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce130)
#endif


// 0x001ce1b0 Closure0<CScenarioManager,float>::vfunc_0 (30 B): matches/0x001ce1b0.cpp
// sym: ??_G?$Method1@VCScenarioManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CScenarioManager, float>::~Closure0() {}


// 0x001ce1d0 Closure0<CScenarioManager,float>::vfunc_2 (35 B): matches/0x001ce1d0.cpp
// sym: ?vfunc_2@?$Closure0@VCScenarioManager@@M@@UAEXPAX00@Z
// Same code shape as 0x0002fe60 (propagated; names are from that function)
template <> void Closure0<CScenarioManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_1ce1d0* m = (*(CActorManager_1ce1d0 * *)&this->f_20);
    Fn_1ce1d0 fn = (*(Fn_1ce1d0 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Closure0<CScenarioManager, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce1b0)
#endif


// 0x001ce200 FUN_001ce200 (76 B): matches/0x001ce200.cpp [wrapped: conflict: Closure1; Closure1::Closure1; Method1]
// sym: ??0Closure1@fn_001ce200@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce200 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1ce200 : public ScriptFunctionFields {
  public:
    virtual void Invoke(float);
    Function_1ce200(const char*, int);
};
class Method1 : public Function_1ce200 {
  public:
    virtual void Invoke(float);
    ScriptMemberFn fn;
    Method1(const char* p, ScriptMemberFn q) : Function_1ce200(p, 1) {
        fn = q;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    void* owner;
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* p, void* q, ScriptMemberFn r) : Method1(p, r) {
    owner = q;
}
} // namespace fn_001ce200
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce250 Closure1<CScenarioManager,void,float>::vfunc_0 (30 B): matches/0x001ce250.cpp
// sym: ??_G?$Method0@VCScenarioManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CScenarioManager, void, float>::~Closure1() {}


// 0x001ce270 Closure1<CScenarioManager,void,float>::vfunc_2 (18 B): matches/0x001ce270.cpp
// sym: ?vfunc_2@?$Closure1@VCScenarioManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CScenarioManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce270 * *)&this->f_20)->*(*(void (CActorManager_1ce270::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce250)
#endif


// 0x001ce290 FUN_001ce290 (76 B): matches/0x001ce290.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001ce290@@QAE@PAX00@Z
namespace fn_001ce290 {

char __cdecl lookup_001d04d0(const char*);
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
    char x;
    char pad2[7];
    char y;
    char pad3[3];
};
class Closure1_1ce290 : public Base {
  public:
    Closure1_1ce290(void*, void*);
    virtual void f();
    void* arg;
};
class Closure1 : public Closure1_1ce290 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* extra;
};
Closure1::Closure1(void* p, void* q, void* r) : Closure1_1ce290(p, r) {
    extra = q;
}
Closure1_1ce290::Closure1_1ce290(void* p, void* q) : Base(p, 1) {
    arg = q;
    y = lookup_001d04d0(((char*)&DAT_0048e100));
    x = lookup_001d04d0(((char*)&DAT_0048e0e4));
}
} // namespace fn_001ce290


// 0x001ce2e0 Closure1<CScenarioManager,void,bool>::vfunc_0 (30 B): matches/0x001ce2e0.cpp
// sym: ??_G?$Method1@VCScenarioManager@@MH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CScenarioManager, void, bool>::~Closure1() {}


// 0x001ce300 Closure1<CScenarioManager,void,bool>::vfunc_2 (20 B): matches/0x001ce300.cpp
// sym: ?vfunc_2@?$Closure1@VCScenarioManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CScenarioManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1ce300 * *)&this->f_20)->*(*(void (Actor_1ce300::**)(unsigned char))&this->f_1c))(*arg);
}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce2e0)
#endif


// 0x001ce360 Closure0<CScenarioManager,bool>::vfunc_0 (30 B): matches/0x001ce360.cpp
// sym: ??_G?$Method2@VCScenarioManager@@HMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CScenarioManager, bool>::~Closure0() {}


// 0x001ce380 Closure0<CScenarioManager,bool>::vfunc_2 (23 B): matches/0x001ce380.cpp
// sym: ?vfunc_2@?$Closure0@VCScenarioManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CScenarioManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_1ce380* o = (*(CActorManager_1ce380 * *)&this->f_20);
    Fn_1ce380 fn = (*(Fn_1ce380 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
#if defined(HULK_PTR64)
template class Closure0<CScenarioManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce360)
#endif


// 0x001ce3a0 FUN_001ce3a0 (76 B): matches/0x001ce3a0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ce3a0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce3a0 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1ce3a0 : public ScriptFunctionFields {
  public:
    Function_1ce3a0(const char*, int);
    virtual void f();
    ScriptMemberFn x;
    void* y;
};
class Method1 : public Function_1ce3a0 {
  public:
    Method1(const char* a, ScriptMemberFn c) : Function_1ce3a0(a, 1) {
        x = c;
        retType = FUN_001d04d0(((int*)&DAT_0048e128));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e134));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* a, void* b, ScriptMemberFn c);
    virtual void f();
};
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    y = b;
}
} // namespace fn_001ce3a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce3f0 Closure1<CScenarioManager,float,int>::vfunc_0 (30 B): matches/0x001ce3f0.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CScenarioManager, float, int>::~Closure1() {}


// 0x001ce410 Closure1<CScenarioManager,float,int>::vfunc_2 (43 B): matches/0x001ce410.cpp
// sym: ?vfunc_2@?$Closure1@VCScenarioManager@@MH@@UAEXPAX00@Z
// Same code shape as 0x0002e800 (propagated; names are from that function)
template <> void Closure1<CScenarioManager, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_1ce410* obj = (*(CActorManager_1ce410 * *)&this->f_20);
    Fn_1ce410 fn = (*(Fn_1ce410 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager, float, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce3f0)
#endif


// 0x001ce440 FUN_001ce440 (89 B): matches/0x001ce440.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ce440@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce440 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_00421f1c[2];
extern void* hulk_at_0042201c[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00421f1c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_0042201c;
    owner = a2;
}
} // namespace fn_001ce440
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce4a0 Closure2<CScenarioManager,void,int,float>::vfunc_0 (30 B): matches/0x001ce4a0.cpp
// sym: ??_G?$Method0@VCScenarioManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CScenarioManager, void, int, float>::~Closure2() {}


// 0x001ce4c0 Closure2<CScenarioManager,void,int,float>::vfunc_2 (22 B): matches/0x001ce4c0.cpp
// sym: ?vfunc_2@?$Closure2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CScenarioManager, void, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ce4c0 * p = (Pair_1ce4c0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce4c0 * *)&this->f_20)->*(*(void (CActorManager_1ce4c0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CScenarioManager, void, int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce4a0)
#endif


// 0x001ce4e0 FUN_001ce4e0 (89 B): matches/0x001ce4e0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ce4e0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce4e0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_00421f2c[2];
extern void* hulk_at_0042202c[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00421f2c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e128));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_0042202c;
    owner = a2;
}
} // namespace fn_001ce4e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce540 Closure2<CScenarioManager,int,float,const_char_*>::vfunc_0 (30 B): matches/0x001ce540.cpp
// sym: ??_G?$Method1@VCScenarioManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CScenarioManager, int, float, const char *>::~Closure2() {}


// 0x001ce560 Closure2<CScenarioManager,int,float,const_char_*>::vfunc_2 (42 B): equivalent/0x001ce560.cpp
// sym: ?vfunc_2@?$Closure2@VCScenarioManager@@HMPBD@@UAEXPAX00@Z @5f2db1ebe681 @wd20935a1da78
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CScenarioManager,int,float,const_char_*>::vfunc_2 @ 0x001ce560
template <> void Closure2<CScenarioManager, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; const char ** result = (const char **)__p2;

    const char* value = ((*(CScenarioManager_1ce560 * *)&this->f_20)->*(*(const char *(CScenarioManager_1ce560::**)(int, float))&this->f_1c))(args->value, args->fraction);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CScenarioManager, int, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce540)
#endif


// 0x001ce590 FUN_001ce590 (89 B): matches/0x001ce590.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ce590@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce590 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_00421f3c[2];
extern void* hulk_at_0042203c[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00421f3c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e128));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_0042203c;
    owner = a2;
}
} // namespace fn_001ce590
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce5f0 Closure2<CScenarioManager,void,float,const_char_*>::vfunc_0 (30 B): matches/0x001ce5f0.cpp
// sym: ??_G?$Method1@VCScenarioManager@@PBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CScenarioManager, void, float, const char *>::~Closure2() {}


// 0x001ce610 Closure2<CScenarioManager,void,float,const_char_*>::vfunc_2 (22 B): matches/0x001ce610.cpp
// sym: ?vfunc_2@?$Closure2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CScenarioManager, void, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ce610 * p = (Pair_1ce610 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce610 * *)&this->f_20)->*(*(void (CActorManager_1ce610::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CScenarioManager, void, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce5f0)
#endif


// 0x001ce670 Closure0<CScenarioManager,void>::vfunc_0 (30 B): matches/0x001ce670.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CScenarioManager, void>::~Closure0() {}


// 0x001ce690 Closure0<CScenarioManager,void>::vfunc_2 (11 B): matches/0x001ce690.cpp
// sym: ?vfunc_2@?$Closure0@VCScenarioManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CScenarioManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_1ce690 * *)&this->f_20)->*(*(void (CActorManager_1ce690::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CScenarioManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce670)
#endif

namespace fn_fdf9c5a9 {

// 0x001ce6a0 FUN_001ce6a0 (76 B): matches/0x001ce6a0.cpp
// sym: ??0Closure1_1ce6a0@fn_fdf9c5a9@@QAE@PBDPAX1@Z
Closure1_1ce6a0::Closure1_1ce6a0(const char* name, void* p, void* a) : Method1_1ce6a0(name, a) {
    arg = p;
}

} // namespace fn_fdf9c5a9

// 0x001ce6f0 Closure1<CScenarioManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001ce6f0.cpp
// sym: ??_G?$Method1@VCScenarioManager@@W4eMissionObjectiveState@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CScenarioManager, void, const char *>::~Closure1() {}


// 0x001ce710 Closure1<CScenarioManager,void,const_char_*>::vfunc_2 (18 B): matches/0x001ce710.cpp
// sym: ?vfunc_2@?$Closure1@VCScenarioManager@@XH@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CScenarioManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce710 * *)&this->f_20)->*(*(void (CActorManager_1ce710::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce6f0)
#endif


// 0x001ce730 FUN_001ce730 (76 B): matches/0x001ce730.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ce730@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce730 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class CScenarioManager;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
struct Function_1ce730 : public CtorV_001d0480 {
    Function_1ce730(const char* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Function_1ce730 {
  public:
    virtual void fn();
    ScriptMemberFn arg;
    Method1(const char*, ScriptMemberFn);
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    void* extra;
    Closure1(const char*, void*, ScriptMemberFn);
};
inline Method1::Method1(const char* a, ScriptMemberFn c) : Function_1ce730(a) {
    arg = c;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e134));
}
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    extra = b;
}
} // namespace fn_001ce730
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce780 Closure1<CScenarioManager,const_char_*,int>::vfunc_0 (30 B): matches/0x001ce780.cpp
// sym: ??_G?$Method2@VCScenarioManager@@XHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CScenarioManager, const char *, int>::~Closure1() {}


// 0x001ce7a0 Closure1<CScenarioManager,const_char_*,int>::vfunc_2 (30 B): matches/0x001ce7a0.cpp
// sym: ?vfunc_2@?$Closure1@VCScenarioManager@@PBDH@@UAEXPAX00@Z
template <> void Closure1<CScenarioManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * args = (void *)__p1; int * out = (int *)__p2;

    CScenarioManager_1ce7a0* o = (*(CScenarioManager_1ce7a0 * *)&this->f_20);
    int (CScenarioManager_1ce7a0::*f)(const char*) = (*(int (CScenarioManager_1ce7a0::**)(const char *))&this->f_1c);
    int r = (o->*f)(*(const char**)args);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Closure1<CScenarioManager, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ce780)
#endif


// 0x001ce7c0 FUN_001ce7c0 (89 B): matches/0x001ce7c0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ce7c0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce7c0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_00421f7c[2];
extern void* hulk_at_0042207c[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00421f7c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_0042207c;
    owner = a2;
}
} // namespace fn_001ce7c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce840 Closure2<CScenarioManager,void,int,const_char_*>::vfunc_2 (22 B): matches/0x001ce840.cpp
// sym: ?vfunc_2@?$Closure2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CScenarioManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ce840 * p = (Pair_1ce840 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce840 * *)&this->f_20)->*(*(void (CActorManager_1ce840::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x001ce860 FUN_001ce860 (76 B): matches/0x001ce860.cpp [wrapped: conflict: Closure1; Closure1::Closure1; Method1]
// sym: ??0Closure1@fn_001ce860@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce860 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_1ce860 : public ScriptFunctionFields {
  public:
    Function_1ce860(const char*, int);
    virtual void f();
    ScriptMemberFn c;
};
class Method1 : public Function_1ce860 {
  public:
    Method1(const char* x, ScriptMemberFn y) : Function_1ce860(x, 1) {
        c = y;
        retType = FUN_001d04d0(&DAT_004c55f0);
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* x, void* y, ScriptMemberFn z);
    virtual void f();
    void* d;
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Method1(x, z) {
    d = y;
}
} // namespace fn_001ce860
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce8d0 Closure1<CScenarioManager,eMissionObjectiveState,int>::vfunc_2 (30 B): matches/0x001ce8d0.cpp [wrapped: conflict: CScenarioManager; Closure1; Function; eMissionObjectiveState]
// sym: ?vfunc_2@Closure1@fn_001ce8d0@@UAEXPAXPAW4eMissionObjectiveState@2@PAH@Z
namespace fn_001ce8d0 {
enum eMissionObjectiveState { dummy };
class CScenarioManager {
  public:
    int method(eMissionObjectiveState);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Closure1 : public Function {
  public:
    char pad[0x18];
    int (CScenarioManager::*method)(eMissionObjectiveState);
    CScenarioManager* object;
    virtual void vfunc_2(void*, eMissionObjectiveState*, int*);
};
void Closure1::vfunc_2(void*, eMissionObjectiveState* arg, int* out) {
    CScenarioManager* obj = object;
    int (CScenarioManager::*fn)(eMissionObjectiveState) = method;
    eMissionObjectiveState value = *arg;
    int result = (obj->*fn)(value);
    if (out)
        *out = result;
}
} // namespace fn_001ce8d0


// 0x001ce8f0 FUN_001ce8f0 (89 B): matches/0x001ce8f0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001ce8f0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ce8f0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_00421f9c[2];
extern void* hulk_at_0042209c[2];

struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

// Closure2's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method2's member-function pointer and Closure2's object.
class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    ScriptMemberFn fn;       // 0x1c
    void* owner;             // 0x20

    Closure2(const char* a1, void* a2, ScriptMemberFn a3);
};

Closure2::Closure2(const char* a1, void* a2, ScriptMemberFn a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00421f9c;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_0042209c;
    owner = a2;
}
} // namespace fn_001ce8f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce970 Closure2<CScenarioManager,void,int,int>::vfunc_2 (22 B): matches/0x001ce970.cpp
// sym: ?vfunc_2@?$Closure2@VCScenarioManager@@XHM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CScenarioManager, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1ce970 * p = (Pair_1ce970 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ce970 * *)&this->f_20)->*(*(void (CActorManager_1ce970::**)(const char *, float))&this->f_1c))(p->s, p->f);
}

namespace fn_fdf9c5a9 {

// 0x001ced50 FUN_001ced50 (79 B): equivalent/0x001ced50.cpp
// sym: ?FUN_001ced50@Owner@fn_fdf9c5a9@@QAEXHHH@Z @5ff6ebc4358d @w6e2521010d36
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ced50 @ 0x001ced50
void Owner::FUN_001ced50(int a, int b, int c) { unsigned int cookie = DAT_004d9968; Closure2_1ced50 local; local.FUN_001ce440(a,b,c); FUN_001d26d0(a,&local); local.FUN_001d04a0(); __security_check_cookie(cookie); }

} // namespace fn_fdf9c5a9

// 0x001cf160 FUN_001cf160 (109 B): equivalent/0x001cf160.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf160@Registry_1cf160@fn_001cf160@@QAEXPBDPAVCScenarioManager@2@P832@AEHXZ@Z @830ac16c753e @we925279f24ad
namespace fn_001cf160 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001cf160 @ 0x001cf160
// FUN_001cf160 @ 0x001cf160  (generated by work/closure/gen.py)
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


class CScenarioManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cf160 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cf160(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1cf160 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1cf160(name, 0) {
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

struct Registry_1cf160 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001cf160(const char* name, CScenarioManager* owner, int (CScenarioManager::*fn)());
};

void Registry_1cf160::FUN_001cf160(const char* name, CScenarioManager* owner, int (CScenarioManager::*fn)()) {
    typedef Closure0<CScenarioManager, int> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CScenarioManager, int>));
    Closure0<CScenarioManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CScenarioManager, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf160
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cf1d0 FUN_001cf1d0 (109 B): equivalent/0x001cf1d0.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf1d0@Registry_1cf1d0@fn_001cf1d0@@QAEXPBDPAVCScenarioManager@2@P832@AEMXZ@Z @6ea773c58bb8 @w6e64564d399b
namespace fn_001cf1d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001cf1d0 @ 0x001cf1d0
// FUN_001cf1d0 @ 0x001cf1d0  (generated by work/closure/gen.py)
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


class CScenarioManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cf1d0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cf1d0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1cf1d0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1cf1d0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1cf1d0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001cf1d0(const char* name, CScenarioManager* owner, float (CScenarioManager::*fn)());
};

void Registry_1cf1d0::FUN_001cf1d0(const char* name, CScenarioManager* owner, float (CScenarioManager::*fn)()) {
    typedef Closure0<CScenarioManager, float> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CScenarioManager, float>));
    Closure0<CScenarioManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CScenarioManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf1d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cf2e0 FUN_001cf2e0 (109 B): equivalent/0x001cf2e0.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf2e0@Registry_1cf2e0@fn_001cf2e0@@QAEXPBDPAVCScenarioManager@2@P832@AE_NXZ@Z @bd6e1f4a23f5 @w97494324307e
namespace fn_001cf2e0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001cf2e0 @ 0x001cf2e0
// FUN_001cf2e0 @ 0x001cf2e0  (generated by work/closure/gen.py)
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


class CScenarioManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cf2e0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cf2e0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1cf2e0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1cf2e0(name, 0) {
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

struct Registry_1cf2e0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001cf2e0(const char* name, CScenarioManager* owner, bool (CScenarioManager::*fn)());
};

void Registry_1cf2e0::FUN_001cf2e0(const char* name, CScenarioManager* owner, bool (CScenarioManager::*fn)()) {
    typedef Closure0<CScenarioManager, bool> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CScenarioManager, bool>));
    Closure0<CScenarioManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CScenarioManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf2e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cf490 FUN_001cf490 (109 B): equivalent/0x001cf490.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf490@Registry_1cf490@fn_001cf490@@QAEXPBDPAVCScenarioManager@2@P832@AEXXZ@Z @fb299c66de49 @w097b4dfbf22f
namespace fn_001cf490 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001cf490 @ 0x001cf490
// FUN_001cf490 @ 0x001cf490  (generated by work/closure/gen.py)
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


class CScenarioManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cf490 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cf490(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_1cf490 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_1cf490(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_1cf490 {
    void FUN_001d3b70(const char*, void*);
    void FUN_001cf490(const char* name, CScenarioManager* owner, void (CScenarioManager::*fn)());
};

void Registry_1cf490::FUN_001cf490(const char* name, CScenarioManager* owner, void (CScenarioManager::*fn)()) {
    typedef Closure0<CScenarioManager, void> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CScenarioManager, void>));
    Closure0<CScenarioManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CScenarioManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf490
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fdf9c5a9 {

// 0x001cf500 FUN_001cf500 (70 B): matches/0x001cf500.cpp
// sym: ?FUN_001cf500@Registry_1cf500@fn_fdf9c5a9@@QAEXPBDPAUOwner@2@P832@AEX0@Z@Z
void Registry_1cf500::FUN_001cf500(const char* a1, Owner* a2, Fn_1cf500 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_1cf500* e = new (FUN_0008d690((int)sizeof(ScriptClosureView))) Closure1_1cf500(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}

} // namespace fn_fdf9c5a9

// 0x001cfb20 FUN_001cfb20 (2080 B): equivalent/0x001cfb20.cpp [wrapped: conflict: CScenarioManager; Closure1; FUN_001d4c90; Method1 (+1)]
// sym: ?FUN_001cfb20@CScenarioManager@fn_001cfb20@@QAEXH@Z @338f5aa0fd1e @w6704f0fb56c7
namespace fn_001cfb20 {
// STATUS: equivalent (tools/equiv.py level 3: 581 inputs, branch coverage 44/44)
// FUN_001cfb20 @ 0x001cfb20
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


enum eMissionObjectiveState { eMOS_dummy };

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<eMissionObjectiveState> { static const void *get() { return &DAT_004c55f0; } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cfb20 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char *, int);
    MethodBase_1cfb20(const char *n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cfb20 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1cfb20(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

class CScenarioManager {
  public:
    virtual void v0();
    int f4;
    int FUN_001cc5e0();
    void FUN_001cc620(int);
    int FUN_001cc840();
    float FUN_001cc860();
    void FUN_001cc870(float);
    float FUN_001cc880();
    void FUN_001cc890(float);
    float FUN_001cc8a0();
    void FUN_001cc8e0(bool);
    bool FUN_001cc8f0();
    int FUN_001cc900();
    void FUN_001cc910(int);
    float FUN_001cc990(int);
    void FUN_001cc9b0(int, float);
    int FUN_001cc9d0(float, const char *);
    void FUN_001cca80(int);
    float FUN_001ccc00();
    void FUN_001ccc10(float);
    float FUN_001ccc20();
    void FUN_001ccc30(float);
    int FUN_001ccc80();
    void FUN_001ccc90(int);
    float FUN_001ccca0();
    void FUN_001cccb0(float);
    void FUN_001cce60(const char *);
    void FUN_001cce80(float, const char *);
    void FUN_001cced0();
    const char * FUN_001ccf50(int);
    void FUN_001ccf70(int, const char *);
    eMissionObjectiveState FUN_001ccfa0(int);
    void FUN_001ccfc0(int, int);
    void FUN_001ccfe0(bool);
    bool FUN_001ccff0();
    void FUN_001cd5b0(float);
    void FUN_001cfb20(int arg);
};

// The out-of-line Closure2 initializers (matches/0x001ce440.cpp ...): allocated as ScriptClosureView.
struct Raw_1cfb20 {
    void *FUN_001ce440(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(int, float));
    void *FUN_001ce4e0(const char *name, CScenarioManager *o, int (CScenarioManager::*fn)(float, const char *));
    void *FUN_001ce590(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(float, const char *));
    void *FUN_001ce7c0(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(int, const char *));
    void *FUN_001ce8f0(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)(int, int));
};

struct Registry_1cfb20 {
    void FUN_001d3b70(const char *name, void *closure);
    void FUN_001cf160(const char *name, CScenarioManager *o, int (CScenarioManager::*fn)());
    void FUN_001cf1d0(const char *name, CScenarioManager *o, float (CScenarioManager::*fn)());
    void FUN_001cf2e0(const char *name, CScenarioManager *o, bool (CScenarioManager::*fn)());
    void FUN_001cf490(const char *name, CScenarioManager *o, void (CScenarioManager::*fn)());
};
Registry_1cfb20 *FUN_001d4c90();

void CScenarioManager::FUN_001cfb20(int arg)
{
    f4 = arg;
    Registry_1cfb20 *reg = FUN_001d4c90();
    if (reg) {
    typedef Closure1<CScenarioManager, void, int> Closure_0;
    HULK_SIZE32(Closure_0, 0x24);
    typedef Closure1<CScenarioManager, void, float> Closure_1;
    HULK_SIZE32(Closure_1, 0x24);
    typedef Closure1<CScenarioManager, void, bool> Closure_2;
    HULK_SIZE32(Closure_2, 0x24);
    typedef Closure1<CScenarioManager, float, int> Closure_3;
    HULK_SIZE32(Closure_3, 0x24);
    typedef Closure1<CScenarioManager, void, const char *> Closure_4;
    HULK_SIZE32(Closure_4, 0x24);
    typedef Closure1<CScenarioManager, const char *, int> Closure_5;
    HULK_SIZE32(Closure_5, 0x24);
    typedef Closure1<CScenarioManager, eMissionObjectiveState, int> Closure_6;
    HULK_SIZE32(Closure_6, 0x24);
    HULK_SIZE32(ScriptClosureView, 0x24);
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_0));
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_SetMissionState", this, &CScenarioManager::FUN_001cc620);
        reg->FUN_001d3b70("sm_SetMissionState", c);
    }
    reg->FUN_001cf160("sm_GetMissionState", this, &CScenarioManager::FUN_001cc840);
    reg->FUN_001cf1d0("sm_GetTimeElapsed", this, &CScenarioManager::FUN_001cc860);
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_1));
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetTimeElapsed", this, &CScenarioManager::FUN_001cc870);
        reg->FUN_001d3b70("sm_SetTimeElapsed", c);
    }
    reg->FUN_001cf1d0("sm_GetTime", this, &CScenarioManager::FUN_001cc8a0);
    reg->FUN_001cf1d0("sm_GetScenarioEndTime", this, &CScenarioManager::FUN_001cc880);
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_1));
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetScenarioEndTime", this, &CScenarioManager::FUN_001cc890);
        reg->FUN_001d3b70("sm_SetScenarioEndTime", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_2));
        Closure1<CScenarioManager, void, bool> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, bool>("sm_FreezeTime", this, &CScenarioManager::FUN_001cc8e0);
        reg->FUN_001d3b70("sm_FreezeTime", c);
    }
    reg->FUN_001cf2e0("sm_IsTimeFrozen", this, &CScenarioManager::FUN_001cc8f0);
    reg->FUN_001cf160("sm_GetCheckpoint", this, &CScenarioManager::FUN_001cc900);
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_0));
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_SetCheckpoint", this, &CScenarioManager::FUN_001cc910);
        reg->FUN_001d3b70("sm_SetCheckpoint", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_3));
        Closure1<CScenarioManager, float, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, float, int>("sm_GetVar", this, &CScenarioManager::FUN_001cc990);
        reg->FUN_001d3b70("sm_GetVar", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(ScriptClosureView));
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce440("sm_SetVar", this, &CScenarioManager::FUN_001cc9b0);
        else
            c = 0;
        reg->FUN_001d3b70("sm_SetVar", c);
    }
    reg->FUN_001cf160("sm_GetMaxVarCount", this, &CScenarioManager::FUN_001cc5e0);
    {
        void *mem = FUN_0008d690((int)sizeof(ScriptClosureView));
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce4e0("sm_StartTimer", this, &CScenarioManager::FUN_001cc9d0);
        else
            c = 0;
        reg->FUN_001d3b70("sm_StartTimer", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_0));
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_CancelTimer", this, &CScenarioManager::FUN_001cca80);
        reg->FUN_001d3b70("sm_CancelTimer", c);
    }
    reg->FUN_001cf1d0("sm_GetComboTimerLimit", this, &CScenarioManager::FUN_001ccc00);
    reg->FUN_001cf1d0("sm_GetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc20);
    reg->FUN_001cf160("sm_GetComboHitCount", this, &CScenarioManager::FUN_001ccc80);
    reg->FUN_001cf1d0("sm_GetComboScore", this, &CScenarioManager::FUN_001ccca0);
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_1));
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetComboTimerLimit", this, &CScenarioManager::FUN_001ccc10);
        reg->FUN_001d3b70("sm_SetComboTimerLimit", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_1));
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc30);
        reg->FUN_001d3b70("sm_SetComboTimerCurrent", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_0));
        Closure1<CScenarioManager, void, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, int>("sm_SetComboHitCount", this, &CScenarioManager::FUN_001ccc90);
        reg->FUN_001d3b70("sm_SetComboHitCount", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_1));
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_SetComboScore", this, &CScenarioManager::FUN_001cccb0);
        reg->FUN_001d3b70("sm_SetComboScore", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_1));
        Closure1<CScenarioManager, void, float> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, float>("sm_Combo", this, &CScenarioManager::FUN_001cd5b0);
        reg->FUN_001d3b70("sm_Combo", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(ScriptClosureView));
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce590("sm_AddComboGrade", this, &CScenarioManager::FUN_001cce80);
        else
            c = 0;
        reg->FUN_001d3b70("sm_AddComboGrade", c);
    }
    reg->FUN_001cf490("sm_ResetComboSystem", this, &CScenarioManager::FUN_001cced0);
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_4));
        Closure1<CScenarioManager, void, const char *> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, const char *>("sm_SetComboHitText", this, &CScenarioManager::FUN_001cce60);
        reg->FUN_001d3b70("sm_SetComboHitText", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_5));
        Closure1<CScenarioManager, const char *, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, const char *, int>("sm_GetMissionObjective", this, &CScenarioManager::FUN_001ccf50);
        reg->FUN_001d3b70("sm_GetMissionObjective", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(ScriptClosureView));
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce7c0("sm_SetMissionObjective", this, &CScenarioManager::FUN_001ccf70);
        else
            c = 0;
        reg->FUN_001d3b70("sm_SetMissionObjective", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_6));
        Closure1<CScenarioManager, eMissionObjectiveState, int> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, eMissionObjectiveState, int>("sm_GetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfa0);
        reg->FUN_001d3b70("sm_GetMissionObjectiveState", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(ScriptClosureView));
        void *c;
        if (mem)
            c = ((Raw_1cfb20 *)mem)->FUN_001ce8f0("sm_SetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfc0);
        else
            c = 0;
        reg->FUN_001d3b70("sm_SetMissionObjectiveState", c);
    }
    {
        void *mem = FUN_0008d690((int)sizeof(Closure_2));
        Closure1<CScenarioManager, void, bool> *c = 0;
        if (mem)
            c = new (mem) Closure1<CScenarioManager, void, bool>("sm_SetTutorialMode", this, &CScenarioManager::FUN_001ccfe0);
        reg->FUN_001d3b70("sm_SetTutorialMode", c);
    }
    reg->FUN_001cf2e0("sm_GetTutorialMode", this, &CScenarioManager::FUN_001ccff0);
    }
}
} // namespace fn_001cfb20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fdf9c5a9 {

// 0x001d0340 CScenarioManager::vfunc_0 (30 B): matches/0x001d0340.cpp
// sym: ?vfunc_2@CScenarioManager_1d0340@fn_fdf9c5a9@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CScenarioManager_1d0340* CScenarioManager_1d0340::vfunc_2(unsigned char flags) {
    ((CScenarioManager_nv_1d0340*)(((CScenarioManager*)(this))))->FUN_001cf690();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fdf9c5a9
