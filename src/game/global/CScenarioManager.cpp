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
#include "game/script_bind.h"

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
// sym: ?FUN_001cc620@CScenarioManager@@QAEXH@Z @b05f070edc4f @w69f26e9efe2a @v6a801333b857
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
// sym: ?FUN_001cc9d0@CScenarioManager_1cc9d0@fn_fdf9c5a9@@QAEHMPBD@Z @a9b47858c903 @w8832aaff6254 @vddd21d2a7660
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
// sym: ?FUN_001cd5b0@CScenarioManager_1cd5b0@fn_fdf9c5a9@@QAEXM@Z @4febb218ad13 @wba03d5f6f5a2 @v12161965b77c
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
// sym: ?vfunc_0@Method1_1cd7f0@fn_001cd7f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager, void, int>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cd7f0 {
struct Method1_1cd7f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cd7f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cd7f0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method0_1cd870@fn_001cd870@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CScenarioManager, int>::~Method0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cd870 {
struct Method0_1cd870 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1cd870::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cd870
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method0_1cd8f0@fn_001cd8f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method0<CScenarioManager, float>::~Method0() {}`
// stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then (flags & 1) operator
// delete.
namespace fn_001cd8f0 {
struct Method0_1cd8f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1cd8f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cd8f0
// the destructor itself, which other objects' code references natively:
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
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
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
// sym: ?vfunc_0@Method1_1cd980@fn_001cd980@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager, void, float>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cd980 {
struct Method1_1cd980 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cd980::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cd980
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method1_1cda00@fn_001cda00@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager, void, bool>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cda00 {
struct Method1_1cda00 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cda00::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cda00
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method0_1cda80@fn_001cda80@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CScenarioManager, bool>::~Method0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cda80 {
struct Method0_1cda80 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1cda80::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cda80
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method1_1cdb00@fn_001cdb00@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager, float, int>::~Method1() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdb00 {
struct Method1_1cdb00 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cdb00::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdb00
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method2_1cdba0@fn_001cdba0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CScenarioManager, void, int, float>::~Method2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdba0 {
struct Method2_1cdba0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1cdba0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdba0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method2_1cdc30@fn_001cdc30@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CScenarioManager, int, float, const char *>::~Method2() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdc30 {
struct Method2_1cdc30 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1cdc30::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdc30
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method2_1cdcd0@fn_001cdcd0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CScenarioManager, void, float, const char *>::~Method2()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdcd0 {
struct Method2_1cdcd0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1cdcd0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdcd0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method0_1cdd50@fn_001cdd50@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method0<CScenarioManager, void>::~Method0() {}` stood for it, which
// natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The
// destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdd50 {
struct Method0_1cdd50 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method0_1cdd50::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdd50
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method1_1cddc0@fn_001cddc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager, void, const char *>::~Method1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cddc0 {
struct Method1_1cddc0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cddc0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cddc0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method1_1cde40@fn_001cde40@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager, const char *, int>::~Method1() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cde40 {
struct Method1_1cde40 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cde40::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cde40
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method2_1cded0@fn_001cded0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CScenarioManager, void, int, const char *>::~Method2() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cded0 {
struct Method2_1cded0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1cded0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cded0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method1_1cdf50@fn_001cdf50@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CScenarioManager,eMissionObjectiveState, int>::~Method1()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdf50 {
struct Method1_1cdf50 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_1cdf50::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdf50
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Method2_1cdfe0@fn_001cdfe0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CScenarioManager, void, int, int>::~Method2() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001cdfe0 {
struct Method2_1cdfe0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_1cdfe0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001cdfe0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_001ce060@@QAE@PBDPAVOwner_1ce060@1@P821@AEXXZ@Z
namespace fn_001ce060 {
// (script1) Closure1<class CScenarioManager,void,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421eac[];   // Method1<class CScenarioManager,void,int>
extern "C" char DAT_00421fac[];   // Closure1<class CScenarioManager,void,int>
class Owner_1ce060 {};
typedef void (Owner_1ce060::*Fn_1ce060)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce060 fn;
    Owner_1ce060* owner;
    Closure1(const char* name, Owner_1ce060* object, Fn_1ce060 function);
};
Closure1::Closure1(const char* name, Owner_1ce060* object, Fn_1ce060 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421eac;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_00421fac;
    owner = object;
}
} // namespace fn_001ce060


// 0x001ce0b0 Closure1<CScenarioManager,void,int>::vfunc_0 (30 B): matches/0x001ce0b0.cpp
// sym: ?vfunc_0@Closure1_1ce0b0@fn_001ce0b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CScenarioManager, void, int>::~Closure1()
// {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then (flags & 1)
// operator delete.
namespace fn_001ce0b0 {
struct Closure1_1ce0b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce0b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce0b0
// the destructor itself, which other objects' code references natively:
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
// sym: ?vfunc_0@Closure0_1ce130@fn_001ce130@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CScenarioManager, int>::~Closure0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce130 {
struct Closure0_1ce130 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ce130::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce130
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Closure0_1ce1b0@fn_001ce1b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CScenarioManager, float>::~Closure0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce1b0 {
struct Closure0_1ce1b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ce1b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce1b0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_001ce200@@QAE@PBDPAVOwner_1ce200@1@P821@AEXXZ@Z
namespace fn_001ce200 {
// (script1) Closure1<class CScenarioManager,void,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421edc[];   // Method1<class CScenarioManager,void,float>
extern "C" char DAT_00421fdc[];   // Closure1<class CScenarioManager,void,float>
class Owner_1ce200 {};
typedef void (Owner_1ce200::*Fn_1ce200)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce200 fn;
    Owner_1ce200* owner;
    Closure1(const char* name, Owner_1ce200* object, Fn_1ce200 function);
};
Closure1::Closure1(const char* name, Owner_1ce200* object, Fn_1ce200 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421edc;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_00421fdc;
    owner = object;
}
} // namespace fn_001ce200
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce250 Closure1<CScenarioManager,void,float>::vfunc_0 (30 B): matches/0x001ce250.cpp
// sym: ?vfunc_0@Closure1_1ce250@fn_001ce250@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CScenarioManager, void, float>::~Closure1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce250 {
struct Closure1_1ce250 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce250::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce250
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_001ce290@@QAE@PBDPAVOwner_1ce290@1@P821@AEXXZ@Z
namespace fn_001ce290 {
// (script1) Closure1<class CScenarioManager,void,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421eec[];   // Method1<class CScenarioManager,void,bool>
extern "C" char DAT_00421fec[];   // Closure1<class CScenarioManager,void,bool>
class Owner_1ce290 {};
typedef void (Owner_1ce290::*Fn_1ce290)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce290 fn;
    Owner_1ce290* owner;
    Closure1(const char* name, Owner_1ce290* object, Fn_1ce290 function);
};
Closure1::Closure1(const char* name, Owner_1ce290* object, Fn_1ce290 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421eec;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_00421fec;
    owner = object;
}
} // namespace fn_001ce290


// 0x001ce2e0 Closure1<CScenarioManager,void,bool>::vfunc_0 (30 B): matches/0x001ce2e0.cpp
// sym: ?vfunc_0@Closure1_1ce2e0@fn_001ce2e0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CScenarioManager, void, bool>::~Closure1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce2e0 {
struct Closure1_1ce2e0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce2e0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce2e0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Closure0_1ce360@fn_001ce360@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CScenarioManager, bool>::~Closure0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce360 {
struct Closure0_1ce360 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ce360::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce360
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_001ce3a0@@QAE@PBDPAVOwner_1ce3a0@1@P821@AEXXZ@Z
namespace fn_001ce3a0 {
// (script1) Closure1<class CScenarioManager,float,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f0c[];   // Method1<class CScenarioManager,float,int>
extern "C" char DAT_0042200c[];   // Closure1<class CScenarioManager,float,int>
class Owner_1ce3a0 {};
typedef void (Owner_1ce3a0::*Fn_1ce3a0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce3a0 fn;
    Owner_1ce3a0* owner;
    Closure1(const char* name, Owner_1ce3a0* object, Fn_1ce3a0 function);
};
Closure1::Closure1(const char* name, Owner_1ce3a0* object, Fn_1ce3a0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421f0c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0042200c;
    owner = object;
}
} // namespace fn_001ce3a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce3f0 Closure1<CScenarioManager,float,int>::vfunc_0 (30 B): matches/0x001ce3f0.cpp
// sym: ?vfunc_0@Closure1_1ce3f0@fn_001ce3f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CScenarioManager, float, int>::~Closure1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce3f0 {
struct Closure1_1ce3f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce3f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce3f0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure2@fn_001ce440@@QAE@PBDPAVOwner_1ce440@1@P821@AEXXZ@Z
namespace fn_001ce440 {
// (script1) Closure2<class CScenarioManager,void,int,float>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f1c[];   // Method2<class CScenarioManager,void,int,float>
extern "C" char DAT_0042201c[];   // Closure2<class CScenarioManager,void,int,float>
class Owner_1ce440 {};
typedef void (Owner_1ce440::*Fn_1ce440)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ce440 fn;
    Owner_1ce440* owner;
    Closure2(const char* name, Owner_1ce440* object, Fn_1ce440 function);
};
Closure2::Closure2(const char* name, Owner_1ce440* object, Fn_1ce440 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00421f1c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    vftable = DAT_0042201c;
    owner = object;
}
} // namespace fn_001ce440
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce4a0 Closure2<CScenarioManager,void,int,float>::vfunc_0 (30 B): matches/0x001ce4a0.cpp
// sym: ?vfunc_0@Closure2_1ce4a0@fn_001ce4a0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CScenarioManager, void, int, float>::~Closure2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce4a0 {
struct Closure2_1ce4a0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1ce4a0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce4a0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure2@fn_001ce4e0@@QAE@PBDPAVOwner_1ce4e0@1@P821@AEXXZ@Z
namespace fn_001ce4e0 {
// (script1) Closure2<class CScenarioManager,int,float,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f2c[];   // Method2<class CScenarioManager,int,float,const char *>
extern "C" char DAT_0042202c[];   // Closure2<class CScenarioManager,int,float,const char *>
class Owner_1ce4e0 {};
typedef void (Owner_1ce4e0::*Fn_1ce4e0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ce4e0 fn;
    Owner_1ce4e0* owner;
    Closure2(const char* name, Owner_1ce4e0* object, Fn_1ce4e0 function);
};
Closure2::Closure2(const char* name, Owner_1ce4e0* object, Fn_1ce4e0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00421f2c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042202c;
    owner = object;
}
} // namespace fn_001ce4e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce540 Closure2<CScenarioManager,int,float,const_char_*>::vfunc_0 (30 B): matches/0x001ce540.cpp
// sym: ?vfunc_0@Closure2_1ce540@fn_001ce540@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CScenarioManager, int, float, const char *>::~Closure2()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce540 {
struct Closure2_1ce540 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1ce540::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce540
// (x64t21) the destructor itself, which other objects' code references:
template <> Closure2<CScenarioManager, int, float, const char *>::~Closure2() {}


// 0x001ce560 Closure2<CScenarioManager,int,float,const_char_*>::vfunc_2 (42 B): equivalent/0x001ce560.cpp
// sym: ?vfunc_2@?$Closure2@VCScenarioManager@@HMPBD@@UAEXPAX00@Z @5f2db1ebe681 @wd20935a1da78 @va68d08af75f4
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
// sym: ??0Closure2@fn_001ce590@@QAE@PBDPAVOwner_1ce590@1@P821@AEXXZ@Z
namespace fn_001ce590 {
// (script1) Closure2<class CScenarioManager,void,float,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f3c[];   // Method2<class CScenarioManager,void,float,const char *>
extern "C" char DAT_0042203c[];   // Closure2<class CScenarioManager,void,float,const char *>
class Owner_1ce590 {};
typedef void (Owner_1ce590::*Fn_1ce590)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ce590 fn;
    Owner_1ce590* owner;
    Closure2(const char* name, Owner_1ce590* object, Fn_1ce590 function);
};
Closure2::Closure2(const char* name, Owner_1ce590* object, Fn_1ce590 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00421f3c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042203c;
    owner = object;
}
} // namespace fn_001ce590
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce5f0 Closure2<CScenarioManager,void,float,const_char_*>::vfunc_0 (30 B): matches/0x001ce5f0.cpp
// sym: ?vfunc_0@Closure2_1ce5f0@fn_001ce5f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CScenarioManager, void, float, const char *>::~Closure2()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce5f0 {
struct Closure2_1ce5f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_1ce5f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce5f0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ?vfunc_0@Closure0_1ce670@fn_001ce670@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure0<CScenarioManager, void>::~Closure0() {}` stood for it,
// which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the slot).
// The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce670 {
struct Closure0_1ce670 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure0_1ce670::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce670
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_001ce6a0@fn_fdf9c5a9@@QAE@PBDPAVOwner_1ce6a0@12@P8312@AEXXZ@Z
namespace fn_001ce6a0 {
// (script1) Closure1<class CScenarioManager,void,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f5c[];   // Method1<class CScenarioManager,void,const char *>
extern "C" char DAT_0042205c[];   // Closure1<class CScenarioManager,void,const char *>
class Owner_1ce6a0 {};
typedef void (Owner_1ce6a0::*Fn_1ce6a0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce6a0 fn;
    Owner_1ce6a0* owner;
    Closure1(const char* name, Owner_1ce6a0* object, Fn_1ce6a0 function);
};
Closure1::Closure1(const char* name, Owner_1ce6a0* object, Fn_1ce6a0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421f5c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042205c;
    owner = object;
}
} // namespace fn_001ce6a0

} // namespace fn_fdf9c5a9

// 0x001ce6f0 Closure1<CScenarioManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001ce6f0.cpp
// sym: ?vfunc_0@Closure1_1ce6f0@fn_001ce6f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CScenarioManager, void, const char *>::~Closure1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce6f0 {
struct Closure1_1ce6f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce6f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce6f0
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure1@fn_001ce730@@QAE@PBDPAVOwner_1ce730@1@P821@AEXXZ@Z
namespace fn_001ce730 {
// (script1) Closure1<class CScenarioManager,const char *,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f6c[];   // Method1<class CScenarioManager,const char *,int>
extern "C" char DAT_0042206c[];   // Closure1<class CScenarioManager,const char *,int>
class Owner_1ce730 {};
typedef void (Owner_1ce730::*Fn_1ce730)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce730 fn;
    Owner_1ce730* owner;
    Closure1(const char* name, Owner_1ce730* object, Fn_1ce730 function);
};
Closure1::Closure1(const char* name, Owner_1ce730* object, Fn_1ce730 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421f6c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0042206c;
    owner = object;
}
} // namespace fn_001ce730
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ce780 Closure1<CScenarioManager,const_char_*,int>::vfunc_0 (30 B): matches/0x001ce780.cpp
// sym: ?vfunc_0@Closure1_1ce780@fn_001ce780@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure1<CScenarioManager, const char *, int>::~Closure1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_001ce780 {
struct Closure1_1ce780 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_1ce780::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001ce780
// (x64t21) the destructor itself, which other objects' code references:
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
// sym: ??0Closure2@fn_001ce7c0@@QAE@PBDPAVOwner_1ce7c0@1@P821@AEXXZ@Z
namespace fn_001ce7c0 {
// (script1) Closure2<class CScenarioManager,void,int,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f7c[];   // Method2<class CScenarioManager,void,int,const char *>
extern "C" char DAT_0042207c[];   // Closure2<class CScenarioManager,void,int,const char *>
class Owner_1ce7c0 {};
typedef void (Owner_1ce7c0::*Fn_1ce7c0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ce7c0 fn;
    Owner_1ce7c0* owner;
    Closure2(const char* name, Owner_1ce7c0* object, Fn_1ce7c0 function);
};
Closure2::Closure2(const char* name, Owner_1ce7c0* object, Fn_1ce7c0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00421f7c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0042207c;
    owner = object;
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
// sym: ??0Closure1@fn_001ce860@@QAE@PBDPAVOwner_1ce860@1@P821@AEXXZ@Z
namespace fn_001ce860 {
// (script1) Closure1<class CScenarioManager,enum eMissionObjectiveState,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f8c[];   // Method1<class CScenarioManager,enum eMissionObjectiveState,int>
extern "C" char DAT_0042208c[];   // Closure1<class CScenarioManager,enum eMissionObjectiveState,int>
extern char DAT_004c55f0[];
class Owner_1ce860 {};
typedef void (Owner_1ce860::*Fn_1ce860)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_1ce860 fn;
    Owner_1ce860* owner;
    Closure1(const char* name, Owner_1ce860* object, Fn_1ce860 function);
};
Closure1::Closure1(const char* name, Owner_1ce860* object, Fn_1ce860 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_00421f8c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(DAT_004c55f0);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0042208c;
    owner = object;
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
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
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
// sym: ??0Closure2@fn_001ce8f0@@QAE@PBDPAVOwner_1ce8f0@1@P821@AEXXZ@Z
namespace fn_001ce8f0 {
// (script1) Closure2<class CScenarioManager,void,int,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_00421f9c[];   // Method2<class CScenarioManager,void,int,int>
extern "C" char DAT_0042209c[];   // Closure2<class CScenarioManager,void,int,int>
class Owner_1ce8f0 {};
typedef void (Owner_1ce8f0::*Fn_1ce8f0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_1ce8f0 fn;
    Owner_1ce8f0* owner;
    Closure2(const char* name, Owner_1ce8f0* object, Fn_1ce8f0 function);
};
Closure2::Closure2(const char* name, Owner_1ce8f0* object, Fn_1ce8f0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_00421f9c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0042209c;
    owner = object;
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
// sym: ?FUN_001ced50@Owner@fn_fdf9c5a9@@QAEXHHH@Z @5ff6ebc4358d @w6e2521010d36 @v967ff7d0de36
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ced50 @ 0x001ced50
void Owner::FUN_001ced50(int a, int b, int c) { unsigned int cookie = DAT_004d9968; Closure2_1ced50 local; local.FUN_001ce440(a,b,c); FUN_001d26d0(a,&local); local.FUN_001d04a0(); __security_check_cookie(cookie); }

} // namespace fn_fdf9c5a9

// 0x001cf160 FUN_001cf160 (109 B): matches/0x001cf160.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf160@Registry_1cf160@fn_001cf160@@QAEXPBDPAVOwner_1cf160@2@P832@AEXXZ@Z
namespace fn_001cf160 {
// (script1) ScriptHandler's registration of a Closure0<class CScenarioManager,int>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00421ebc[];   // Method0<class CScenarioManager,int>
extern "C" char DAT_00421fbc[];   // Closure0<class CScenarioManager,int>
class Owner_1cf160 {};
typedef void (Owner_1cf160::*Fn_1cf160)();
struct Closure_1cf160 : hulk_script::ScriptFunction {
    Fn_1cf160 fn;
    Owner_1cf160* owner;
    Closure_1cf160(const char* name, Owner_1cf160* object, Fn_1cf160 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00421ebc;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
        vftable = DAT_00421fbc;
        owner = object;
    }
};
struct Registry_1cf160 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_001cf160(const char* name, Owner_1cf160* object, Fn_1cf160 function);
};
void Registry_1cf160::FUN_001cf160(const char* name, Owner_1cf160* object, Fn_1cf160 function) {
    Closure_1cf160* c = new Closure_1cf160(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf160
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cf1d0 FUN_001cf1d0 (109 B): matches/0x001cf1d0.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf1d0@Registry_1cf1d0@fn_001cf1d0@@QAEXPBDPAVOwner_1cf1d0@2@P832@AEXXZ@Z
namespace fn_001cf1d0 {
// (script1) ScriptHandler's registration of a Closure0<class CScenarioManager,float>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00421ecc[];   // Method0<class CScenarioManager,float>
extern "C" char DAT_00421fcc[];   // Closure0<class CScenarioManager,float>
class Owner_1cf1d0 {};
typedef void (Owner_1cf1d0::*Fn_1cf1d0)();
struct Closure_1cf1d0 : hulk_script::ScriptFunction {
    Fn_1cf1d0 fn;
    Owner_1cf1d0* owner;
    Closure_1cf1d0(const char* name, Owner_1cf1d0* object, Fn_1cf1d0 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00421ecc;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e128);
        vftable = DAT_00421fcc;
        owner = object;
    }
};
struct Registry_1cf1d0 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_001cf1d0(const char* name, Owner_1cf1d0* object, Fn_1cf1d0 function);
};
void Registry_1cf1d0::FUN_001cf1d0(const char* name, Owner_1cf1d0* object, Fn_1cf1d0 function) {
    Closure_1cf1d0* c = new Closure_1cf1d0(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf1d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cf2e0 FUN_001cf2e0 (109 B): matches/0x001cf2e0.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf2e0@Registry_1cf2e0@fn_001cf2e0@@QAEXPBDPAVOwner_1cf2e0@2@P832@AEXXZ@Z
namespace fn_001cf2e0 {
// (script1) ScriptHandler's registration of a Closure0<class CScenarioManager,bool>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00421efc[];   // Method0<class CScenarioManager,bool>
extern "C" char DAT_00421ffc[];   // Closure0<class CScenarioManager,bool>
class Owner_1cf2e0 {};
typedef void (Owner_1cf2e0::*Fn_1cf2e0)();
struct Closure_1cf2e0 : hulk_script::ScriptFunction {
    Fn_1cf2e0 fn;
    Owner_1cf2e0* owner;
    Closure_1cf2e0(const char* name, Owner_1cf2e0* object, Fn_1cf2e0 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00421efc;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
        vftable = DAT_00421ffc;
        owner = object;
    }
};
struct Registry_1cf2e0 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_001cf2e0(const char* name, Owner_1cf2e0* object, Fn_1cf2e0 function);
};
void Registry_1cf2e0::FUN_001cf2e0(const char* name, Owner_1cf2e0* object, Fn_1cf2e0 function) {
    Closure_1cf2e0* c = new Closure_1cf2e0(name, object, function);
    FUN_001d3b70(name, c);
}
} // namespace fn_001cf2e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cf490 FUN_001cf490 (109 B): matches/0x001cf490.cpp [wrapped: conflict: CScenarioManager; Closure0; Method0]
// sym: ?FUN_001cf490@Registry_1cf490@fn_001cf490@@QAEXPBDPAVOwner_1cf490@2@P832@AEXXZ@Z
namespace fn_001cf490 {
// (script1) ScriptHandler's registration of a Closure0<class CScenarioManager,void>:
// include/game/script_bind.h's records (operator new 0x0008d690, Function's constructor 0x001d0480, the game's
// vftables by address, the member-function pointer, the type codes, the object), then 0x001d3b70.
// throw(): under a TU's /GX (D24) the new-expression would otherwise get an unwind frame the game has none of.
extern "C" char DAT_00421f4c[];   // Method0<class CScenarioManager,void>
extern "C" char DAT_0042204c[];   // Closure0<class CScenarioManager,void>
class Owner_1cf490 {};
typedef void (Owner_1cf490::*Fn_1cf490)();
struct Closure_1cf490 : hulk_script::ScriptFunction {
    Fn_1cf490 fn;
    Owner_1cf490* owner;
    Closure_1cf490(const char* name, Owner_1cf490* object, Fn_1cf490 function) throw() : hulk_script::ScriptFunction(name, 0) {
        vftable = DAT_00421f4c;
        fn = function;
        f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
        vftable = DAT_0042204c;
        owner = object;
    }
};
struct Registry_1cf490 {
    void FUN_001d3b70(const char* name, void* function);
    void FUN_001cf490(const char* name, Owner_1cf490* object, Fn_1cf490 function);
};
void Registry_1cf490::FUN_001cf490(const char* name, Owner_1cf490* object, Fn_1cf490 function) {
    Closure_1cf490* c = new Closure_1cf490(name, object, function);
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
// sym: ?FUN_001cfb20@CScenarioManager@fn_001cfb20@@QAEXH@Z @9e34a37c5dd5 @w8de076da8212 @v5de0762bdcd0
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
inline const void* MissionObjectiveStateTag() { return &DAT_004c55f0; }

// (script2) Closure1 is include/game/script_bind.h's record: Method1<T,R,A>'s and Closure1<T,R,A>'s game vftables by
// address (Vft1), as the game's inlined constructors store them; no stand-in vftable.
template <class T, class R, class A> struct Vft1;
template <class T, class R, class A>
struct Closure1 : hulk_script::ScriptClosure<hulk_script::ScriptMethod1<T, R, A>, T> {
    Closure1(const char *name, T *o, R (T::*f)(A)) throw()
        : hulk_script::ScriptClosure<hulk_script::ScriptMethod1<T, R, A>, T>(name, o, f, Vft1<T, R, A>::mv(), Vft1<T, R, A>::cv()) {}
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
extern "C" char DAT_00421eac[], DAT_00421edc[], DAT_00421eec[], DAT_00421f0c[], DAT_00421f5c[], DAT_00421f6c[], DAT_00421f8c[];
extern "C" char DAT_00421fac[], DAT_00421fdc[], DAT_00421fec[], DAT_0042200c[], DAT_0042205c[], DAT_0042206c[], DAT_0042208c[];
#define VFT1(R, A, M, C) template <> struct Vft1<CScenarioManager, R, A> { static const void* mv() { return M; } static const void* cv() { return C; } };
VFT1(void, int, DAT_00421eac, DAT_00421fac)
VFT1(void, float, DAT_00421edc, DAT_00421fdc)
VFT1(void, bool, DAT_00421eec, DAT_00421fec)
VFT1(float, int, DAT_00421f0c, DAT_0042200c)
VFT1(void, const char *, DAT_00421f5c, DAT_0042205c)
VFT1(const char *, int, DAT_00421f6c, DAT_0042206c)
VFT1(eMissionObjectiveState, int, DAT_00421f8c, DAT_0042208c)
#undef VFT1
} // namespace fn_001cfb20
// (script2) eMissionObjectiveState's type_info 0x004c55f0 for the records' type codes
template <> struct hulk_script::ScriptType<fn_001cfb20::eMissionObjectiveState> { static const void* tag() { return fn_001cfb20::MissionObjectiveStateTag(); } };
namespace fn_001cfb20 {

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
