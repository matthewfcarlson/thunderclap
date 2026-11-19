// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093600..0x000964d0 (kind game, layer game, confidence high), dominant class CUnlockablesManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8b63219 {
#define TREE_TU_END }
namespace fn_f8b63219 {} using namespace fn_f8b63219;
#include "game/global.h"
#include "game/script_bind.h"

// ---- declarations shared by the functions below
namespace fn_f8b63219 {
class CUnlockable_93950 {
public:
    virtual void v0();
    char pad04[4];
    char flag;
    char pad09[0x10 - 9];
    int pos0;
    int pos1;
    void *obj18;
};
class CUnlockableCheat_93950 : public CUnlockable_93950 {
public:
    char pad1c[0x24 - 0x1c];
    int link;
    char name[1];
};
class FEObject_93950 {
public:
    virtual void vfunc_0();
};
class TextSelector_93950 : public FEObject_93950 {
public:
    char pad04[0x141 - 4];
    char marked;
};
struct Mgr_93950 {
};
struct Holder_93950 {
    Mgr_93950 *FUN_000b5000();
};
struct Menu_93950 {
    CUnlockable_93950 *slots[0x266];
    char pad[0xd88 - 0x998];
    Holder_93950 *holder;

    void FUN_00093600(int index, int arg);
    void FUN_00093950(const char *name, char wait, unsigned char *outFound, char *outLinked, unsigned char *outPicked, int *outPos);
};
FEObject_93950 *__cdecl FUN_000fc260(void *name);
extern "C" int __cdecl FUN_00345804(const char*, const char*, ...);
struct TypeInfo_93c40 { unsigned int data; };
extern TypeInfo_93c40 DAT_0049dab8, DAT_0049dafc, DAT_0049db1c;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo_93c40*, TypeInfo_93c40*, int);
struct State_93c40 { char pad[8]; unsigned char flag; };
struct CastState { char pad[32]; unsigned char flag; };
struct Entry_93c40 { unsigned int a,b; int chapter,mission; int ids[16]; };
struct Game_93c40 {
 char pad0[0x74]; State_93c40* state; char pad1[0xd90-0x78]; Entry_93c40 entries[32];
 void FUN_00093600(int,int);
 void target(const char* text);
};
struct ThisWrap_00093db0 {
    void Other_00093600(int, int);
    void Target(int n, int unused);
};
class CUnlockablesManager_93e30 {
  public:
    bool Get(int);
};
class Function_93e30 {
  public:
    virtual void v0();
    virtual void v1();
};
class CUnlockablesManager_93ec0 {
  public:
    void Unlock(int, bool);
};
struct Args {
    int n;
    bool b;
};
class Function_93ec0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CUnlockablesManager_93ec0*, Args*, void*);
};
class CFEManager_93f50 {
  public:
    void Call(const char*, int);
};
class Function_93f50 {
  public:
    virtual void f0();
    virtual void f1();
};
class CFEManager_93fe0 {
  public:
    void Call(const char*, int);
};
class Function_93fe0 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" bool __cdecl CheckString_001d04d0(const char** ppStr);
class Function_94000 {
  public:
    virtual void* Invoke_00094080(int);
    virtual bool AddRef_001d04c0(int, int);
    virtual void Release_000940a0(void*, void*, void*);
    int m_base1;
    int m_base2;
    int m_base3;
    Function_94000(const char* name, int index);
};
class Method6_94000 : public Function_94000 {
    char m_flag1; // 0x10
    char m_flag2; // 0x11
    char m_flag3; // 0x12
    char m_flag4; // 0x13
    char m_flag5; // 0x14
    char m_flag6; // 0x15
    char pad[2];  // 0x16-0x17
    char m_flag7; // 0x18
    int m_data;   // 0x1c
  public:
    Method6_94000(const char* name, hulk_intptr data);
};
struct Function_940a0 {
    virtual void f0();
    virtual void f1();
};
void FUN_000940c0(const char*, const char*, const char*, int);
struct Function_941a0 {
    virtual void f0();
    virtual void f1();
};
void FUN_000941c0(const char*, const char*, const char*, int);
struct Obj {
    void Run(int, int, int, int, int, int);
};
typedef void (Obj::*Fn)(int, int, int, int, int, int);
extern "C" char DAT_004046dc[];
class Owner_94200 {};
typedef void (Owner_94200::*Fn_94200)(int, int, bool);
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
extern char __cdecl Query_001d04d0(const char*);
class Method3_94200 : public FUN_001d0480 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_94200 value;
    Method3_94200(const char* a, Fn_94200 b);
};
struct CUnlockablesManager_94280 { };
struct Arguments {
  public:
    int first;
    int second;
    unsigned char third;
    char _m_pad_9[0x7];
};
class CUnlockablesManager_943a0 {
  public:
    int Run(const char*);
};
class Function_943a0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
extern "C" char DAT_0040470c[];
class Owner_943c0 {};
typedef void (Owner_943c0::*Fn_943c0)(const char*, int, const char*, const char*, const char*, const char*, int);
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Method7_943c0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_943c0 func;
    Method7_943c0* Init(const char* name, Fn_943c0 fn);
};
struct Function_94470 {
    virtual void f0();
    virtual void f1();
};
void FUN_00094490(const char*, const char*, const char*, int);
struct Obj_94490;
typedef void (Obj_94490::*Fn_94490)(int, int, int, int, int, int, int);
struct Obj_94490 {
    int x;
};
struct CUnlockablesManager_94560 {};
struct Function_94560 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
struct Arg_946d0 {
    const char* s;
    unsigned char b;
};
class Actor_946d0 {
  public:
    void invoke(const char*, unsigned char);
};
class CActorManager_94770 {
  public:
    void Method(const char*, float);
};
struct Pair_94770 {
    const char* s;
    float f;
};
class CActorManager_94810 {
  public:
    void Method(const char*, float);
};
struct Pair_94810 {
    const char* s;
    float f;
};
class CUnlockablesManager_94910 { public: void FUN_00094910(int, const char*, const char*, const char*, const char*, int); };
struct CallArgs { int id; const char *a; const char *b; const char *c; const char *d; int value; };
struct CUnlockablesManager_94aa0 {
    char unused;
    int FUN_00094aa0(const char*);
};
struct CUnlockablesManager_94b10 { void FUN_00000000(const char *, int, const char *, const char *, const char *, const char *, int); };
struct CUnlockablesManager_94bb0 {
    char dummy;
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f8b63219
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f8b63219 {
class CUnlockablesManager_94d20 {};
typedef void (CUnlockablesManager_94d20::*Fn_94d20)(const char*, int, const char*, const char*, const char*, const char*);
class Registry_94d20 { public:
    void FUN_00094d20(const char* a1, CUnlockablesManager_94d20* a2, Fn_94d20 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_94d20;
template<> class Closure6_94d20<CUnlockablesManager_94d20, void, const char*, int, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_94d20 fn; CUnlockablesManager_94d20* owner; Closure6_94d20(CUnlockablesManager_94d20* o) { owner = o; } };
class Raw_94d20 { public: void FUN_00094000(const char*, Fn_94d20); };
class CUnlockablesManager_94d80 {};
typedef void (CUnlockablesManager_94d80::*Fn_94d80)(int, const char*, const char*, const char*, const char*, int);
class Registry_94d80 { public:
    void FUN_00094d80(const char* a1, CUnlockablesManager_94d80* a2, Fn_94d80 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_94d80;
template<> class Closure6_94d80<CUnlockablesManager_94d80, void, int, const char*, const char*, const char*, const char*, int> : public ScriptFunctionFields { public: virtual void v(); Fn_94d80 fn; CUnlockablesManager_94d80* owner; Closure6_94d80(CUnlockablesManager_94d80* o) { owner = o; } };
class Raw_94d80 { public: void FUN_00094100(const char*, Fn_94d80); };
class CUnlockablesManager_94de0 {};
typedef void (CUnlockablesManager_94de0::*Fn_94de0)(int, int, bool);
class Registry_94de0 { public:
    void FUN_00094de0(const char* a1, CUnlockablesManager_94de0* a2, Fn_94de0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_94de0;
template<> class Closure3_94de0<CUnlockablesManager_94de0, void, int, int, bool> : public ScriptFunctionFields { public: virtual void* Fnv_00094980(int); Fn_94de0 fn; CUnlockablesManager_94de0* owner; Closure3_94de0(CUnlockablesManager_94de0* o) { owner = o; } };
class Raw_94de0 { public: void FUN_00094200(const char*, Fn_94de0); };
class CUnlockablesManager_94e40 {};
typedef void (CUnlockablesManager_94e40::*Fn_94e40)(int, const char*, const char*);
class Registry_94e40 { public:
    void FUN_00094e40(const char* a1, CUnlockablesManager_94e40* a2, Fn_94e40 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_94e40;
template<> class Closure3_94e40<CUnlockablesManager_94e40, void, int, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_94e40 fn; CUnlockablesManager_94e40* owner; Closure3_94e40(CUnlockablesManager_94e40* o) { owner = o; } };
class Raw_94e40 { public: void FUN_000942a0(const char*, Fn_94e40); };
class CUnlockablesManager_94ef0 {};
typedef void (CUnlockablesManager_94ef0::*Fn_94ef0)(const char*, int, const char*, const char*, const char*, const char*, int);
class Registry_94ef0 { public:
    void FUN_00094ef0(const char* a1, CUnlockablesManager_94ef0* a2, Fn_94ef0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7_94ef0;
template<> class Closure7_94ef0<CUnlockablesManager_94ef0, void, const char*, int, const char*, const char*, const char*, const char*, int> : public ScriptFunctionFields { public: virtual void v(); Fn_94ef0 fn; CUnlockablesManager_94ef0* owner; Closure7_94ef0(CUnlockablesManager_94ef0* o) { owner = o; } };
class Raw_94ef0 { public: void FUN_000943c0(const char*, Fn_94ef0); };
class CUnlockablesManager_94f50 {};
typedef void (CUnlockablesManager_94f50::*Fn_94f50)(const char*, int, const char*, const char*);
class Registry_94f50 { public:
    void FUN_00094f50(const char* a1, CUnlockablesManager_94f50* a2, Fn_94f50 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_94f50;
template<> class Closure4_94f50<CUnlockablesManager_94f50, void, const char*, int, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_94f50 fn; CUnlockablesManager_94f50* owner; Closure4_94f50(CUnlockablesManager_94f50* o) { owner = o; } };
class Raw_94f50 { public: void FUN_000944d0(const char*, Fn_94f50); };
typedef unsigned int u32_95f50;
struct Obj_95f50 {
    u32_95f50 a;
    u32_95f50 b;
};
extern "C" u32_95f50 __cdecl FUN_00267f80();
extern "C" unsigned int __cdecl tick_00267f80();
struct Timer {
    float scale;
    unsigned int last;
    hulk_freg Delta();
};
} // namespace fn_f8b63219
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif
namespace fn_f8b63219 {
struct Vec_96020 { float x,y,z; };
struct Matrix { float m[12]; };
struct Vec3 { float x, y, z; };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);

} // namespace fn_f8b63219

// 0x00093600 FUN_00093600 (846 B): equivalent/0x00093600.cpp [wrapped: conflict: CUnlockable; CUnlockableBlonskyFile; CUnlockableGallery; CUnlockableMove]
// sym: ?FUN_00093600@Menu_93600@fn_00093600@@QAEXHD@Z @6d03cc7c5669 @w5126dbf49d98 @v9924b8e19616
namespace fn_00093600 {
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 85/86, incomplete)
// FUN_00093600 @ 0x00093600
// equiv-map: ??_R0?AVCUnlockableBlonskyFile@@@8 = 0x0049dad4
// equiv-map: ??_R0?AVCUnlockableMove@@@8 = 0x0049db1c
class CUnlockable {
public:
    virtual void v0();
    char pad04[4];
    char flag;
};

class CUnlockableGallery : public CUnlockable {
public:
    char pad0c[0xb0 - 0xc];
    char hidden;
};

class CUnlockableMove : public CUnlockable {
public:
    char pad0c[0x2d - 0xc];
    char hidden;
};

class CUnlockableBlonskyFile : public CUnlockable {
public:
    char pad0c[0xa8 - 0xc];
    char hidden;
};

struct Sound_93600 {
    void FUN_000900a0(int id);
};

struct Env {
    char pad0[0x50];
    Sound_93600 *sound;
    void FUN_000c2c10(int id);
};

struct Menu_93600 {
    CUnlockable *slots[0x266];
    char pad998[0xd88 - 0x998];
    Env *env;
    void FUN_00093600(int index, char on);
    char FUN_00092940(int index);
    void FUN_00092870(int index, int v);
};

void Menu_93600::FUN_00093600(int index, char on)
{
    int id = index;
    if (id == 0x2de || id == 0x2df || id == 0x2e0) {
        if (!on) {
            env->sound->FUN_000900a0(0x1f4);
            return;
        }
    } else if (id == 0x2c || id == 0x2d || id == 0x2e) {
        if (!on && !FUN_00092940(id)) {
            slots[id]->flag = 0;
            FUN_00092870(id, 1);
            env->sound->FUN_000900a0(id == 0x2c ? 0x1388 : id == 0x2d ? 0x2710 : 0x3a98);
            return;
        }
    } else if (id >= 0x1bf && id <= 0x247) {
        CUnlockable **p = &slots[id];
        for (int k = 0; k < 10; k++, p++, id++) {
            CUnlockable *u = *p;
            if (u->flag != on) {
                u->flag = on;
                CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(*p);
                if (g)
                    g->hidden = on == 0;
                if (env)
                    env->FUN_000c2c10(id);
            }
            if (id == 0x1f0 || id == 0x209 || id == 0x22d || id == 0x243 || id == 0x247)
                break;
        }
        return;
    } else if (id == 0x1c) {
        CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(slots[0x1c]);
        if (g)
            g->hidden = on == 0;
        int i;
        for (i = 0x248; i <= 0x257; i++) {
            FUN_00093600(i, 0);
            if (env)
                env->FUN_000c2c10(i);
        }
        for (i = 0x258; i <= 0x260; i++) {
            FUN_00093600(i, 0);
            if (env)
                env->FUN_000c2c10(i);
        }
        return;
    }

    CUnlockable *u = slots[id];
    if (u->flag == on)
        return;
    u->flag = on;
    CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(slots[id]);
    if (g)
        g->hidden = on == 0;
    CUnlockableMove *m = dynamic_cast<CUnlockableMove *>(slots[id]);
    if (m)
        m->hidden = on == 0;
    CUnlockableBlonskyFile *b = dynamic_cast<CUnlockableBlonskyFile *>(slots[id]);
    if (b)
        b->hidden = on == 0;
    if (env)
        env->FUN_000c2c10(id);
}
} // namespace fn_00093600

namespace fn_f8b63219 {

// 0x00093950 FUN_00093950 (647 B): equivalent/0x00093950.cpp
// sym: ?FUN_00093950@Menu_93950@fn_f8b63219@@QAEXPBDDPAEPAD1PAH@Z @d069d1b555a1 @w5ce309bb2228 @veccedd4bf8e3
// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 51/58, incomplete)
// FUN_00093950 @ 0x00093950
void Menu_93950::FUN_00093950(const char *name, char wait, unsigned char *outFound, char *outLinked, unsigned char *outPicked, int *outPos)
{
    unsigned __int64 h = FUN_0027b020(name);
    *outFound = 0;
    *outLinked = 0;
    *outPicked = 0;
    char ready = 0;
    Mgr_93950 *mgr = 0;
    if (holder)
        mgr = holder->FUN_000b5000();

    int i;
    for (i = 0x261; i <= 0x265; i++) {
        CUnlockableCheat_93950 *c = dynamic_cast<CUnlockableCheat_93950 *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (wait)
                return;
            *outPicked = 1;
            CUnlockable_93950 *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            return;
        }
    }

    for (i = 0; i <= 0x1e; i++) {
        CUnlockableCheat_93950 *c = dynamic_cast<CUnlockableCheat_93950 *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (i == 4 || i == 3) {
                *outLinked = 1;
                if (mgr && ((char)((owners::Target_893c0 *)mgr)->FUN_000893c0()))
                    ready = 1;
            }
            if (c->link != -1) {
                *outLinked = 1;
                if (slots[c->link]->flag == 0)
                    ready = 1;
            }
            if (wait)
                return;
            if (*outLinked != 0 && !ready)
                return;
            *outPicked = 1;
            CUnlockable_93950 *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            TextSelector_93950 *t = dynamic_cast<TextSelector_93950 *>(FUN_000fc260(slots[i]->obj18));
            if (t)
                t->marked = 1;
            return;
        }
    }

    for (i = 0x1f; i <= 0x32; i++) {
        CUnlockableCheat_93950 *c = dynamic_cast<CUnlockableCheat_93950 *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (c->link != -1) {
                *outLinked = 1;
                if (slots[c->link]->flag == 0)
                    ready = 1;
            }
            if (wait)
                return;
            if (*outLinked != 0 && !ready)
                return;
            *outPicked = 1;
            CUnlockable_93950 *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            return;
        }
    }
}


// 0x00093c40 FUN_00093c40 (358 B): equivalent/0x00093c40.cpp
// sym: ?target@Game_93c40@fn_f8b63219@@QAEXPBD@Z @8e2b810d9b4a @w1a69eea3438b @v39989c1f75a3
// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 51/52, incomplete)
// FUN_00093c40 @ 0x00093c40
void Game_93c40::target(const char* text) {
 int chapter, mission;
 if(FUN_00345804(text,"c%dm%d",&chapter,&mission)!=2) return;
 for(int i=0;i<32;++i) {
  Entry_93c40& e=entries[i];
  if(!(e.a|e.b)) break;
  bool restricted = chapter>7 ||
   (chapter==1 && mission==10) ||
   (chapter==4 && (mission==10 || mission==11)) ||
   (chapter==2 && mission==3 && e.chapter==2 && e.mission==2) ||
   e.chapter>chapter || (e.chapter==chapter && e.mission>mission);
  if(!restricted) {
   for(int j=0;j<16;++j) {
    int id=e.ids[j];
    if(id==-1) break;
    FUN_00093600(id,0);
   }
  } else {
   for(int j=0;j<16;++j) {
    if(e.ids[j]==-1) break;
    bool allow=false;
    if(!state->flag) {
     CastState* s=static_cast<CastState*>(FUN_00344e74(state,0,&DAT_0049dab8,&DAT_0049dafc,0));
     if(!s) s=static_cast<CastState*>(FUN_00344e74(state,0,&DAT_0049dab8,&DAT_0049db1c,0));
     if(s && s->flag) allow=true;
    }
    if(allow || (chapter==0 && mission==10)) {
     int id=e.ids[j];
     if(id>=0x266 && id<=0x2c9) FUN_00093600(id,0);
    }
   }
  }
 }
}


// 0x00093db0 FUN_00093db0 (27 B): matches/0x00093db0.cpp
// sym: ?Target@ThisWrap_00093db0@fn_f8b63219@@QAEXHH@Z
void ThisWrap_00093db0::Target(int n, int unused) {
    if (n >= 0 && n < 0x2fe)
        this->Other_00093600(n, unused);
}

} // namespace fn_f8b63219

// 0x00093e10 Method1<CUnlockablesManager,bool,int>::vfunc_0 (30 B): matches/0x00093e10.cpp
// sym: ?vfunc_0@Method1_93e10@fn_00093e10@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CUnlockablesManager, bool, int>::~Method1() {}` stood for
// it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00093e10 {
struct Method1_93e10 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_93e10::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00093e10
// (x64t21) the destructor itself, which other objects' code references:
template <> Method1<CUnlockablesManager, bool, int>::~Method1() {}


// 0x00093e30 Method1<CUnlockablesManager,bool,int>::vfunc_2 (29 B): matches/0x00093e30.cpp
// sym: ?vfunc_2@?$Method1@VCUnlockablesManager@@_NH@@UAEXPAX00@Z
template <> void Method1<CUnlockablesManager, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_93e30 * obj = (CUnlockablesManager_93e30 *)__p0; int * arg = (int *)__p1; bool * out = (bool *)__p2;

    bool (CUnlockablesManager_93e30::*f)(int) = (*(bool (CUnlockablesManager_93e30::**)(int))&this->f_1c);
    int v = *arg;
    bool r = (obj->*f)(v);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CUnlockablesManager, bool, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x93e10)
#endif


// 0x00093ea0 Method2<CUnlockablesManager,void,int,bool>::vfunc_0 (30 B): matches/0x00093ea0.cpp
// sym: ?vfunc_0@Method2_93ea0@fn_00093ea0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CUnlockablesManager, void, int, bool>::~Method2() {}` stood
// for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call the
// slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00093ea0 {
struct Method2_93ea0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_93ea0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00093ea0
// (x64t21) the destructor itself, which other objects' code references:
template <> Method2<CUnlockablesManager, void, int, bool>::~Method2() {}


// 0x00093ec0 Method2<CUnlockablesManager,void,int,bool>::vfunc_2 (25 B): matches/0x00093ec0.cpp
// sym: ?vfunc_2@?$Method2@VCUnlockablesManager@@XH_N@@UAEXPAX00@Z
template <> void Method2<CUnlockablesManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_93ec0 * obj = (CUnlockablesManager_93ec0 *)__p0; Args * args = (Args *)__p1; void * result = (void *)__p2;

    (obj->*(*(void (CUnlockablesManager_93ec0::**)(int, bool))&this->f_1c))(args->n, args->b);
}
#if defined(HULK_PTR64)
template class Method2<CUnlockablesManager, void, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x93ea0)
#endif


// 0x00093f30 Method2<CUnlockablesManager,void,int,int>::vfunc_0 (30 B): matches/0x00093f30.cpp
// sym: ?vfunc_0@Method2_93f30@fn_00093f30@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method2<CUnlockablesManager, void, int,
// int>::~Method2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_00093f30 {
struct Method2_93f30 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_93f30::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00093f30
// the destructor itself, which other objects' code references natively:
template <> Method2<CUnlockablesManager, void, int, int>::~Method2() {}


// 0x00093f50 Method2<CUnlockablesManager,void,int,int>::vfunc_2 (23 B): matches/0x00093f50.cpp
// sym: ?vfunc_2@?$Method2@VCUnlockablesManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CUnlockablesManager, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_93f50* m = (CFEManager_93f50*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_93f50::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CUnlockablesManager, void, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x93f30)
#endif


// 0x00093fc0 Method2<CUnlockablesManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x00093fc0.cpp
// sym: ?vfunc_0@Method2_93fc0@fn_00093fc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method2<CUnlockablesManager, void, const char *, int>::~Method2()
// {}` stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views
// call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00093fc0 {
struct Method2_93fc0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method2_93fc0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00093fc0
// (x64t21) the destructor itself, which other objects' code references:
template <> Method2<CUnlockablesManager, void, const char *, int>::~Method2() {}


// 0x00093fe0 Method2<CUnlockablesManager,void,const_char_*,int>::vfunc_2 (23 B): matches/0x00093fe0.cpp
// sym: ?vfunc_2@?$Method2@VCUnlockablesManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CUnlockablesManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_93fe0* m = (CFEManager_93fe0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_93fe0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CUnlockablesManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x93fc0)
#endif

namespace fn_f8b63219 {

// 0x00094000 FUN_00094000 (128 B): matches/0x00094000.cpp
// sym: ??0Method6@fn_00094000@fn_f8b63219@@QAE@PBDP8Owner_94000@12@AEXXZ@Z
namespace fn_00094000 {
// (script1) Method6<class CUnlockablesManager,void,const char *,int,const char *,const char *,const char *,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_004046bc[];   // Method6<class CUnlockablesManager,void,const char *,int,const char *,const char *,const char *,const char *>
class Owner_94000 {};
typedef void (Owner_94000::*Fn_94000)();
struct Method6 : hulk_script::ScriptFunction {
    Fn_94000 fn;
    Method6(const char* name, Fn_94000 function);
};
Method6::Method6(const char* name, Fn_94000 function) : hulk_script::ScriptFunction(name, 6) {
    vftable = DAT_004046bc;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[4] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[5] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
}
} // namespace fn_00094000

} // namespace fn_f8b63219

// 0x00094080 Method6<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00094080.cpp
// sym: ?vfunc_0@Method6_94080@fn_00094080@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method6<CUnlockablesManager, void, const char *, int, const char *,
// const char *, const char *, const char *>::~Method6() {}` stood for it, which natively defines no function for the
// vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags
// & 1) operator delete.
namespace fn_00094080 {
struct Method6_94080 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method6_94080::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094080
// (x64t21) the destructor itself, which other objects' code references:
template <> Method6<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *>::~Method6() {}


// 0x000940a0 Method6<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x000940a0.cpp
// sym: ?vfunc_2@?$Method6@VCUnlockablesManager@@XPBDHPBDPBDPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_000940c0(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94080)
#endif


// 0x000940c0 FUN_000940c0 (53 B): matches/0x000940c0.cpp [wrapped: conflict: Args]
// sym: ?invoke@fn_000940c0@@YAXPAVObj@1@PAUArgs@1@HP821@AEXHHHHHH@Z@Z
namespace fn_000940c0 {
struct Args {
    int a, b, c, d, e, f;
};
class Obj {
  public:
    void method(int, int, int, int, int, int);
};
typedef void (Obj::*Callback)(int, int, int, int, int, int);
void invoke(Obj* o, Args* p, int unused, Callback cb) {
    int* q = (int*)p;
    int a = *q++;
    int b = *q++;
    int c = *q++;
    int d = *q++;
    int e = *q++;
    int f = *q++;
    (o->*cb)(a, b, c, d, e, f);
}
} // namespace fn_000940c0


// 0x00094100 FUN_00094100 (128 B): matches/0x00094100.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0Method6@fn_00094100@@QAE@PBDP8Owner_94100@1@AEXXZ@Z
namespace fn_00094100 {
// (script1) Method6<class CUnlockablesManager,void,int,const char *,const char *,const char *,const char *,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_004046cc[];   // Method6<class CUnlockablesManager,void,int,const char *,const char *,const char *,const char *,int>
class Owner_94100 {};
typedef void (Owner_94100::*Fn_94100)();
struct Method6 : hulk_script::ScriptFunction {
    Fn_94100 fn;
    Method6(const char* name, Fn_94100 function);
};
Method6::Method6(const char* name, Fn_94100 function) : hulk_script::ScriptFunction(name, 6) {
    vftable = DAT_004046cc;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[4] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[5] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
}
} // namespace fn_00094100


// 0x00094180 Method6<CUnlockablesManager,void,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_0 (30 B): matches/0x00094180.cpp
// sym: ?vfunc_0@Method6_94180@fn_00094180@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method6<CUnlockablesManager, void, int, const char *, const char *,
// const char *, const char *, int>::~Method6() {}` stood for it, which natively defines no function for the vftable
// slot (with the `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1)
// operator delete.
namespace fn_00094180 {
struct Method6_94180 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method6_94180::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094180
// (x64t21) the destructor itself, which other objects' code references:
template <> Method6<CUnlockablesManager, void, int, const char *, const char *, const char *, const char *, int>::~Method6() {}


// 0x000941a0 Method6<CUnlockablesManager,void,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 (30 B): matches/0x000941a0.cpp
// sym: ?vfunc_2@?$Method6@VCUnlockablesManager@@XHPBDPBDPBDPBDH@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CUnlockablesManager, void, int, const char *, const char *, const char *, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_000941c0(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CUnlockablesManager, void, int, const char *, const char *, const char *, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94180)
#endif

namespace fn_f8b63219 {

// 0x000941c0 FUN_000941c0 (53 B): matches/0x000941c0.cpp
// sym: ?dispatch@fn_f8b63219@@YAXPAUObj@1@PAHHP821@AEXHHHHHH@Z@Z
void dispatch(Obj* obj, int* a, int unused, Fn fn) {
    int x0 = *a;
    ++a;
    int x1 = *a;
    ++a;
    int x2 = *a;
    ++a;
    int x3 = *a;
    ++a;
    int x4 = *a;
    int x5 = a[1];
    (obj->*fn)(x0, x1, x2, x3, x4, x5);
}


// 0x00094200 FUN_00094200 (89 B): matches/0x00094200.cpp
// sym: ??0Method3@fn_00094200@fn_f8b63219@@QAE@PBDP8Owner_94200@12@AEXXZ@Z
namespace fn_00094200 {
// (script1) Method3<class CUnlockablesManager,void,int,int,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_004046dc[];   // Method3<class CUnlockablesManager,void,int,int,bool>
class Owner_94200 {};
typedef void (Owner_94200::*Fn_94200)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_94200 fn;
    Method3(const char* name, Fn_94200 function);
};
Method3::Method3(const char* name, Fn_94200 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_004046dc;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
}
} // namespace fn_00094200

} // namespace fn_f8b63219

// 0x00094260 Method3<CUnlockablesManager,void,int,int,bool>::vfunc_0 (30 B): matches/0x00094260.cpp
// sym: ?vfunc_0@Method3_94260@fn_00094260@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method3<CUnlockablesManager, void, int, int, bool>::~Method3() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00094260 {
struct Method3_94260 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_94260::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094260
// (x64t21) the destructor itself, which other objects' code references:
template <> Method3<CUnlockablesManager, void, int, int, bool>::~Method3() {}


// 0x00094280 Method3<CUnlockablesManager,void,int,int,bool>::vfunc_2 (31 B): equivalent/0x00094280.cpp
// sym: ?vfunc_2@?$Method3@VCUnlockablesManager@@XHH_N@@UAEXPAX00@Z @df298f4335fd @w022c10218034 @ve490d974e069
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CUnlockablesManager,void,int,int,bool>::vfunc_2 @ 0x00094280
template <> void Method3<CUnlockablesManager, void, int, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_94280 * object = (CUnlockablesManager_94280 *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CUnlockablesManager_94280::**)(int, int, int))&this->f_1c))(arguments->first, arguments->second, arguments->third);
}
#if defined(HULK_PTR64)
template class Method3<CUnlockablesManager, void, int, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94260)
#endif


// 0x000942a0 FUN_000942a0 (89 B): matches/0x000942a0.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_000942a0@@QAE@PBDP8Owner_942a0@1@AEXXZ@Z
namespace fn_000942a0 {
// (script1) Method3<class CUnlockablesManager,void,int,const char *,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_004046ec[];   // Method3<class CUnlockablesManager,void,int,const char *,const char *>
class Owner_942a0 {};
typedef void (Owner_942a0::*Fn_942a0)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_942a0 fn;
    Method3(const char* name, Fn_942a0 function);
};
Method3::Method3(const char* name, Fn_942a0 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_004046ec;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
}
} // namespace fn_000942a0


// 0x00094300 Method3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00094300.cpp
// sym: ?vfunc_0@Method3_94300@fn_00094300@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method3<CUnlockablesManager, void, int, const char
// *, const char *>::~Method3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00094300 {
struct Method3_94300 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_94300::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094300
// the destructor itself, which other objects' code references natively:
template <> Method3<CUnlockablesManager, void, int, const char *, const char *>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CUnlockablesManager, void, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94300)
#endif


// 0x00094320 Method3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 (29 B): equivalent/0x00094320.cpp [wrapped: conflict: Arguments; Method3]
// sym: ?vfunc_2@Method3@fn_00094320@@UAEXPAUCUnlockablesManager@2@PAUArguments@2@PAX@Z @a7a6d240b96d @w9b83a8b8e93b @v4989fed05a58
namespace fn_00094320 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094320
struct CUnlockablesManager { char unused; };
struct Arguments { int number; const char *first; const char *second; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CUnlockablesManager *manager, Arguments *args, void *unused);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
    void (CUnlockablesManager::*method)(int, const char *, const char *);
};
void Method3::vfunc_2(CUnlockablesManager *manager, Arguments *args, void *unused) {
    (manager->*method)(args->number, args->first, args->second);
}
} // namespace fn_00094320


// 0x00094380 Method1<CUnlockablesManager,const_char_*,int>::vfunc_0 (30 B): matches/0x00094380.cpp
// sym: ?vfunc_0@Method1_94380@fn_00094380@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method1<CUnlockablesManager, const char *,
// int>::~Method1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_00094380 {
struct Method1_94380 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_94380::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094380
// the destructor itself, which other objects' code references natively:
template <> Method1<CUnlockablesManager, const char *, int>::~Method1() {}


// 0x000943a0 Method1<CUnlockablesManager,const_char_*,int>::vfunc_2 (29 B): matches/0x000943a0.cpp
// sym: ?vfunc_2@?$Method1@VCUnlockablesManager@@PBDH@@UAEXPAX00@Z
template <> void Method1<CUnlockablesManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_943a0 * obj = (CUnlockablesManager_943a0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CUnlockablesManager_943a0::*f)(const char*) = (*(int (CUnlockablesManager_943a0::**)(const char *))&this->f_1c);
    const char* p = *arg;
    int v = (obj->*f)(p);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method1<CUnlockablesManager, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94380)
#endif

namespace fn_f8b63219 {

// 0x000943c0 FUN_000943c0 (141 B): matches/0x000943c0.cpp
// sym: ?Init@Method7_943c0@fn_f8b63219@@QAEPAV12@PBDP8Owner_943c0@2@AEX0H0000H@Z@Z
// FUN_000943c0 @ 0x000943c0
Method7_943c0* Method7_943c0::Init(const char* name, Fn_943c0 fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (void*)DAT_0040470c;
    func = fn;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    return this;
}

} // namespace fn_f8b63219

// 0x00094450 Method7<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_0 (30 B): matches/0x00094450.cpp
// sym: ?vfunc_0@Method7_94450@fn_00094450@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method7<CUnlockablesManager, void, const char *, int, const char *,
// const char *, const char *, const char *, int>::~Method7() {}` stood for it, which natively defines no function for
// the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_00094450 {
struct Method7_94450 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method7_94450::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094450
// (x64t21) the destructor itself, which other objects' code references:
template <> Method7<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *, int>::~Method7() {}


// 0x00094470 Method7<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 (30 B): matches/0x00094470.cpp
// sym: ?vfunc_2@?$Method7@VCUnlockablesManager@@XPBDHPBDPBDPBDPBDH@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method7<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_00094490(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method7<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94450)
#endif

namespace fn_f8b63219 {

// 0x00094490 FUN_00094490 (62 B): matches/0x00094490.cpp
// sym: ?FUN_00094490@fn_f8b63219@@YAXPAUObj_94490@1@PAHHP821@AEXHHHHHHH@Z@Z
void __cdecl FUN_00094490(Obj_94490* a, int* p, int b, Fn_94490 fn) {
    int* q = p;
    int v0 = *q;
    q++;
    int v1 = *q;
    q++;
    int v2 = *q;
    q++;
    int v3 = *q;
    q++;
    int v4 = *q;
    q++;
    int v5 = *q;
    q++;
    int v6 = *q;
    (a->*fn)(v0, v1, v2, v3, v4, v5, v6);
}

} // namespace fn_f8b63219

// 0x000944d0 FUN_000944d0 (102 B): matches/0x000944d0.cpp [wrapped: conflict: CUnlockablesManager; Method4]
// sym: ??0Method4@fn_000944d0@@QAE@PBDP8Owner_944d0@1@AEXXZ@Z
namespace fn_000944d0 {
// (script1) Method4<class CUnlockablesManager,void,const char *,int,const char *,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_0040471c[];   // Method4<class CUnlockablesManager,void,const char *,int,const char *,const char *>
class Owner_944d0 {};
typedef void (Owner_944d0::*Fn_944d0)();
struct Method4 : hulk_script::ScriptFunction {
    Fn_944d0 fn;
    Method4(const char* name, Fn_944d0 function);
};
Method4::Method4(const char* name, Fn_944d0 function) : hulk_script::ScriptFunction(name, 4) {
    vftable = DAT_0040471c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[3] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
}
} // namespace fn_000944d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00094540 Method4<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00094540.cpp
// sym: ?vfunc_0@Method4_94540@fn_00094540@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method4<CUnlockablesManager, void, const char *, int, const char *,
// const char *>::~Method4() {}` stood for it, which natively defines no function for the vftable slot (with the `??_G`
// signature, as other views call the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00094540 {
struct Method4_94540 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method4_94540::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094540
// (x64t21) the destructor itself, which other objects' code references:
template <> Method4<CUnlockablesManager, void, const char *, int, const char *, const char *>::~Method4() {}


// 0x00094560 Method4<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*>::vfunc_2 (40 B): matches/0x00094560.cpp
// sym: ?vfunc_2@?$Method4@VCUnlockablesManager@@XPBDHPBDPBD@@UAEXPAX00@Z
template <> void Method4<CUnlockablesManager, void, const char *, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_94560 * object = (CUnlockablesManager_94560 *)__p0; const char ** args = (const char **)__p1; void * unused = (void *)__p2;

    const char* a = *args++;
    int b = *(const int*)args++;
    const char* c = *args++;
    const char* d = *args;
    (object->*(*(void (CUnlockablesManager_94560::**)(const char *, int, const char *, const char *))&this->f_1c))(a, b, c, d);
}
#if defined(HULK_PTR64)
template class Method4<CUnlockablesManager, void, const char *, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94540)
#endif


// 0x00094590 FUN_00094590 (45 B): matches/0x00094590.cpp
// sym: ?FUN_00094590@Obj_94590@owners@@QAEXXZ
void owners::Obj_94590::FUN_00094590() {
    int i = 0;
    do {
        if (i != 0x1b && i >= 0 && i < 0x2fe)
            Do(i, 0);
        ++i;
    } while (i < 0x2fe);
}


// 0x000945c0 FUN_000945c0 (76 B): matches/0x000945c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_000945c0@@QAE@PBDPAVOwner_945c0@1@P821@AEXXZ@Z
namespace fn_000945c0 {
// (script1) Closure1<class CUnlockablesManager,bool,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040467c[];   // Method1<class CUnlockablesManager,bool,int>
extern "C" char DAT_0040472c[];   // Closure1<class CUnlockablesManager,bool,int>
class Owner_945c0 {};
typedef void (Owner_945c0::*Fn_945c0)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_945c0 fn;
    Owner_945c0* owner;
    Closure1(const char* name, Owner_945c0* object, Fn_945c0 function);
};
Closure1::Closure1(const char* name, Owner_945c0* object, Fn_945c0 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040467c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0040472c;
    owner = object;
}
} // namespace fn_000945c0


// 0x00094610 Closure1<CUnlockablesManager,bool,int>::vfunc_0 (30 B): matches/0x00094610.cpp
// sym: ?vfunc_0@Closure1_94610@fn_00094610@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure1<CUnlockablesManager, bool,
// int>::~Closure1() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_00094610 {
struct Closure1_94610 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure1_94610::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094610
// the destructor itself, which other objects' code references natively:
template <> Closure1<CUnlockablesManager, bool, int>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CUnlockablesManager, bool, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94610)
#endif


// 0x00094630 Closure1<CUnlockablesManager,bool,int>::vfunc_2 (30 B): matches/0x00094630.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_00094630@@UAEXPAXPAPBDPA_N@Z
namespace fn_00094630 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x18])
    typedef bool(__fastcall* Fn)(void*, const char*, const char*);
    Fn mFn;
    void* mObj;
};
void Closure1::V2(void* a, const char** p, bool* out) {
    void* obj = mObj;
    Fn fn = mFn;
    bool r = fn(obj, *p, *p);
    if (out)
        *out = r;
}
} // namespace fn_00094630


// 0x00094650 FUN_00094650 (89 B): matches/0x00094650.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00094650@@QAE@PBDPAVOwner_94650@1@P821@AEXXZ@Z
namespace fn_00094650 {
// (script1) Closure2<class CUnlockablesManager,void,int,bool>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040468c[];   // Method2<class CUnlockablesManager,void,int,bool>
extern "C" char DAT_0040473c[];   // Closure2<class CUnlockablesManager,void,int,bool>
class Owner_94650 {};
typedef void (Owner_94650::*Fn_94650)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_94650 fn;
    Owner_94650* owner;
    Closure2(const char* name, Owner_94650* object, Fn_94650 function);
};
Closure2::Closure2(const char* name, Owner_94650* object, Fn_94650 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_0040468c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    vftable = DAT_0040473c;
    owner = object;
}
} // namespace fn_00094650
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000946b0 Closure2<CUnlockablesManager,void,int,bool>::vfunc_0 (30 B): matches/0x000946b0.cpp
// sym: ?vfunc_0@Closure2_946b0@fn_000946b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CUnlockablesManager, void, int, bool>::~Closure2() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_000946b0 {
struct Closure2_946b0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_946b0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000946b0
// (x64t21) the destructor itself, which other objects' code references:
template <> Closure2<CUnlockablesManager, void, int, bool>::~Closure2() {}


// 0x000946d0 Closure2<CUnlockablesManager,void,int,bool>::vfunc_2 (24 B): matches/0x000946d0.cpp
// sym: ?vfunc_2@?$Closure2@VCUnlockablesManager@@XH_N@@UAEXPAX00@Z
// Same code shape as 0x0002ec60 (propagated; names are from that function)
template <> void Closure2<CUnlockablesManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_946d0 * p = (Arg_946d0 *)__p1;

    ((*(Actor_946d0 * *)&this->f_20)->*(*(void (Actor_946d0::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
#if defined(HULK_PTR64)
template class Closure2<CUnlockablesManager, void, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x946b0)
#endif


// 0x000946f0 FUN_000946f0 (89 B): matches/0x000946f0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_000946f0@@QAE@PBDPAVOwner_946f0@1@P821@AEXXZ@Z
namespace fn_000946f0 {
// (script1) Closure2<class CUnlockablesManager,void,int,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040469c[];   // Method2<class CUnlockablesManager,void,int,int>
extern "C" char DAT_0040474c[];   // Closure2<class CUnlockablesManager,void,int,int>
class Owner_946f0 {};
typedef void (Owner_946f0::*Fn_946f0)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_946f0 fn;
    Owner_946f0* owner;
    Closure2(const char* name, Owner_946f0* object, Fn_946f0 function);
};
Closure2::Closure2(const char* name, Owner_946f0* object, Fn_946f0 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_0040469c;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0040474c;
    owner = object;
}
} // namespace fn_000946f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00094750 Closure2<CUnlockablesManager,void,int,int>::vfunc_0 (30 B): matches/0x00094750.cpp
// sym: ?vfunc_0@Closure2_94750@fn_00094750@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Closure2<CUnlockablesManager, void, int, int>::~Closure2() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00094750 {
struct Closure2_94750 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_94750::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094750
// (x64t21) the destructor itself, which other objects' code references:
template <> Closure2<CUnlockablesManager, void, int, int>::~Closure2() {}


// 0x00094770 Closure2<CUnlockablesManager,void,int,int>::vfunc_2 (22 B): matches/0x00094770.cpp
// sym: ?vfunc_2@?$Closure2@VCUnlockablesManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CUnlockablesManager, void, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_94770 * p = (Pair_94770 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_94770 * *)&this->f_20)->*(*(void (CActorManager_94770::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CUnlockablesManager, void, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94750)
#endif


// 0x00094790 FUN_00094790 (89 B): matches/0x00094790.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00094790@@QAE@PBDPAVOwner_94790@1@P821@AEXXZ@Z
namespace fn_00094790 {
// (script1) Closure2<class CUnlockablesManager,void,const char *,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004046ac[];   // Method2<class CUnlockablesManager,void,const char *,int>
extern "C" char DAT_0040475c[];   // Closure2<class CUnlockablesManager,void,const char *,int>
class Owner_94790 {};
typedef void (Owner_94790::*Fn_94790)();
struct Closure2 : hulk_script::ScriptFunction {
    Fn_94790 fn;
    Owner_94790* owner;
    Closure2(const char* name, Owner_94790* object, Fn_94790 function);
};
Closure2::Closure2(const char* name, Owner_94790* object, Fn_94790 function) : hulk_script::ScriptFunction(name, 2) {
    vftable = DAT_004046ac;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e100);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_0040475c;
    owner = object;
}
} // namespace fn_00094790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000947f0 Closure2<CUnlockablesManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x000947f0.cpp
// sym: ?vfunc_0@Closure2_947f0@fn_000947f0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure2<CUnlockablesManager, void, const char *,
// int>::~Closure2() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0, then
// (flags & 1) operator delete.
namespace fn_000947f0 {
struct Closure2_947f0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure2_947f0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000947f0
// the destructor itself, which other objects' code references natively:
template <> Closure2<CUnlockablesManager, void, const char *, int>::~Closure2() {}


// 0x00094810 Closure2<CUnlockablesManager,void,const_char_*,int>::vfunc_2 (22 B): matches/0x00094810.cpp
// sym: ?vfunc_2@?$Closure2@VCUnlockablesManager@@XHH@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CUnlockablesManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_94810 * p = (Pair_94810 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_94810 * *)&this->f_20)->*(*(void (CActorManager_94810::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CUnlockablesManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x947f0)
#endif


// 0x00094860 Closure6<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00094860.cpp
// sym: ?vfunc_0@Closure6_94860@fn_00094860@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure6<CUnlockablesManager, void, const char *,
// int, const char *, const char *, const char *, const char *>::~Closure6() {}` stood for it, whose MSVC `??_G` matched
// only under /GX. The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00094860 {
struct Closure6_94860 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure6_94860::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00094860
// the destructor itself, which other objects' code references natively:
template <> Closure6<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *>::~Closure6() {}
#if defined(HULK_PTR64)
template class Closure6<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94860)
#endif


// 0x00094910 Closure6<CUnlockablesManager,void,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 (58 B): equivalent/0x00094910.cpp
// sym: ?vfunc_2@?$Closure6@VCUnlockablesManager@@XHPBDPBDPBDPBDH@@UAEXPAX00@Z @d87f9086673d @w3c3165c7de60 @v4be7ecf75931
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CUnlockablesManager,void,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 @ 0x00094910
template <> void Closure6<CUnlockablesManager, void, int, const char *, const char *, const char *, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const CallArgs * args = (const CallArgs *)__p1;
 ((*(CUnlockablesManager_94910 * *)&this->f_20)->*(*(void (CUnlockablesManager_94910::**)(int, const char *, const char *, const char *, const char *, int))&this->f_1c))(args->id,args->a,args->b,args->c,args->d,args->value); }


// 0x00094a30 FUN_00094a30 (76 B): matches/0x00094a30.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00094a30@@QAE@PBDPAVOwner_94a30@1@P821@AEXXZ@Z
namespace fn_00094a30 {
// (script1) Closure1<class CUnlockablesManager,const char *,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_004046fc[];   // Method1<class CUnlockablesManager,const char *,int>
extern "C" char DAT_004047ac[];   // Closure1<class CUnlockablesManager,const char *,int>
class Owner_94a30 {};
typedef void (Owner_94a30::*Fn_94a30)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_94a30 fn;
    Owner_94a30* owner;
    Closure1(const char* name, Owner_94a30* object, Fn_94a30 function);
};
Closure1::Closure1(const char* name, Owner_94a30* object, Fn_94a30 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_004046fc;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    vftable = DAT_004047ac;
    owner = object;
}
} // namespace fn_00094a30


// 0x00094aa0 Closure1<CUnlockablesManager,const_char_*,int>::vfunc_2 (30 B): matches/0x00094aa0.cpp
// sym: ?vfunc_2@?$Closure1@VCUnlockablesManager@@PBDH@@UAEXPAX00@Z
template <> void Closure1<CUnlockablesManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; int * result = (int *)__p2;

    CUnlockablesManager_94aa0* obj = (*(CUnlockablesManager_94aa0 * *)&this->f_20);
    int (CUnlockablesManager_94aa0::*fn)(const char*) = (*(int (CUnlockablesManager_94aa0::**)(const char *))&this->f_1c);
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}


// 0x00094b10 Closure7<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 (73 B): equivalent/0x00094b10.cpp
// sym: ?vfunc_2@?$Closure7@VCUnlockablesManager@@XPBDHPBDPBDPBDPBDH@@UAEXPAX00@Z @c0251080410d @waf7fe9cdae89 @ve14be1a471f1
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure7<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 @ 0x00094b10
template <> void Closure7<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const unsigned int * args = (const unsigned int *)__p1; void * unused2 = (void *)__p2;

    ((*(CUnlockablesManager_94b10 * *)&this->f_20)->*(*(void (CUnlockablesManager_94b10::**)(const char *, int, const char *, const char *, const char *, const char *, int))&this->f_1c))((const char *)args[0], (int)args[1], (const char *)args[2], (const char *)args[3], (const char *)args[4], (const char *)args[5], (int)args[6]);
}


// 0x00094bb0 Closure4<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*>::vfunc_2 (39 B): matches/0x00094bb0.cpp
// sym: ?vfunc_2@?$Closure4@VCUnlockablesManager@@XPBDHPBDPBD@@UAEXPAX00@Z
template <> void Closure4<CUnlockablesManager, void, const char *, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * arguments = (const Arguments *)__p1;

    const char** p = (const char**)arguments;
    const char* a = *p++;
    int b = *(int*)p++;
    const char* c = *p++;
    const char* d = *p++;
    ((*(CUnlockablesManager_94bb0 * *)&this->f_20)->*(*(void (CUnlockablesManager_94bb0::**)(const char *, int, const char *, const char *))&this->f_1c))(a, b, c, d);
}

namespace fn_f8b63219 {

// 0x00094d20 FUN_00094d20 (83 B): equivalent/0x00094d20.cpp
// sym: ?FUN_00094d20@Registry_94d20@fn_f8b63219@@QAEXPBDPAVCUnlockablesManager_94d20@2@P832@AEX0H0000@Z@Z @88f0bf731b98 @w8e5ca56a3c8c @v677b572cf51c
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00094d20 @ 0x00094d20
// FUN_00094d20 @ 0x00094d20  (generated by tools/equiv_gen/reg_helper.py)
void Registry_94d20::FUN_00094d20(const char* a1, CUnlockablesManager_94d20* a2, Fn_94d20 a3) {
    typedef Closure6_94d20<CUnlockablesManager_94d20, void, const char*, int, const char*, const char*, const char*, const char*> Alloc_94d20;
    HULK_SIZE32(Alloc_94d20, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_94d20));
    void* x = 0;
    if (m) {
        ((Raw_94d20*)m)->FUN_00094000(a1, a3);
        x = new (m) Closure6_94d20<CUnlockablesManager_94d20, void, const char*, int, const char*, const char*, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00094d80 FUN_00094d80 (83 B): equivalent/0x00094d80.cpp
// sym: ?FUN_00094d80@Registry_94d80@fn_f8b63219@@QAEXPBDPAVCUnlockablesManager_94d80@2@P832@AEXH0000H@Z@Z @f8a218994029 @wd7a1885fe6ee @vd4cfb8e1fe89
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00094d80 @ 0x00094d80
// FUN_00094d80 @ 0x00094d80  (generated by tools/equiv_gen/reg_helper.py)
void Registry_94d80::FUN_00094d80(const char* a1, CUnlockablesManager_94d80* a2, Fn_94d80 a3) {
    typedef Closure6_94d80<CUnlockablesManager_94d80, void, int, const char*, const char*, const char*, const char*, int> Alloc_94d80;
    HULK_SIZE32(Alloc_94d80, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_94d80));
    void* x = 0;
    if (m) {
        ((Raw_94d80*)m)->FUN_00094100(a1, a3);
        x = new (m) Closure6_94d80<CUnlockablesManager_94d80, void, int, const char*, const char*, const char*, const char*, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00094de0 FUN_00094de0 (83 B): equivalent/0x00094de0.cpp
// sym: ?FUN_00094de0@Registry_94de0@fn_f8b63219@@QAEXPBDPAVCUnlockablesManager_94de0@2@P832@AEXHH_N@Z@Z @7844e44f6703 @w82d77c27511f @vbe09be7e9256
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00094de0 @ 0x00094de0
// FUN_00094de0 @ 0x00094de0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_94de0::FUN_00094de0(const char* a1, CUnlockablesManager_94de0* a2, Fn_94de0 a3) {
    typedef Closure3_94de0<CUnlockablesManager_94de0, void, int, int, bool> Alloc_94de0;
    HULK_SIZE32(Alloc_94de0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_94de0));
    void* x = 0;
    if (m) {
        ((Raw_94de0*)m)->FUN_00094200(a1, a3);
        x = new (m) Closure3_94de0<CUnlockablesManager_94de0, void, int, int, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00094e40 FUN_00094e40 (83 B): equivalent/0x00094e40.cpp
// sym: ?FUN_00094e40@Registry_94e40@fn_f8b63219@@QAEXPBDPAVCUnlockablesManager_94e40@2@P832@AEXH00@Z@Z @ea5e22ca9420 @we7029c6da855 @vd5dab6b70b71
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00094e40 @ 0x00094e40
// FUN_00094e40 @ 0x00094e40  (generated by tools/equiv_gen/reg_helper.py)
void Registry_94e40::FUN_00094e40(const char* a1, CUnlockablesManager_94e40* a2, Fn_94e40 a3) {
    typedef Closure3_94e40<CUnlockablesManager_94e40, void, int, const char*, const char*> Alloc_94e40;
    HULK_SIZE32(Alloc_94e40, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_94e40));
    void* x = 0;
    if (m) {
        ((Raw_94e40*)m)->FUN_000942a0(a1, a3);
        x = new (m) Closure3_94e40<CUnlockablesManager_94e40, void, int, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00094ef0 FUN_00094ef0 (83 B): equivalent/0x00094ef0.cpp
// sym: ?FUN_00094ef0@Registry_94ef0@fn_f8b63219@@QAEXPBDPAVCUnlockablesManager_94ef0@2@P832@AEX0H0000H@Z@Z @18a83c736d1c @w238a7ceac156 @vbcad40d5b813
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00094ef0 @ 0x00094ef0
// FUN_00094ef0 @ 0x00094ef0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_94ef0::FUN_00094ef0(const char* a1, CUnlockablesManager_94ef0* a2, Fn_94ef0 a3) {
    typedef Closure7_94ef0<CUnlockablesManager_94ef0, void, const char*, int, const char*, const char*, const char*, const char*, int> Alloc_94ef0;
    HULK_SIZE32(Alloc_94ef0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_94ef0));
    void* x = 0;
    if (m) {
        ((Raw_94ef0*)m)->FUN_000943c0(a1, a3);
        x = new (m) Closure7_94ef0<CUnlockablesManager_94ef0, void, const char*, int, const char*, const char*, const char*, const char*, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00094f50 FUN_00094f50 (83 B): equivalent/0x00094f50.cpp
// sym: ?FUN_00094f50@Registry_94f50@fn_f8b63219@@QAEXPBDPAVCUnlockablesManager_94f50@2@P832@AEX0H00@Z@Z @062fcc0c9686 @wd6270baa0075 @v8fd698930ede
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00094f50 @ 0x00094f50
// FUN_00094f50 @ 0x00094f50  (generated by tools/equiv_gen/reg_helper.py)
void Registry_94f50::FUN_00094f50(const char* a1, CUnlockablesManager_94f50* a2, Fn_94f50 a3) {
    typedef Closure4_94f50<CUnlockablesManager_94f50, void, const char*, int, const char*, const char*> Alloc_94f50;
    HULK_SIZE32(Alloc_94f50, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_94f50));
    void* x = 0;
    if (m) {
        ((Raw_94f50*)m)->FUN_000944d0(a1, a3);
        x = new (m) Closure4_94f50<CUnlockablesManager_94f50, void, const char*, int, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f8b63219

// 0x00095e80 FUN_00095e80 (35 B): matches/0x00095e80.cpp
// sym: ?FUN_00095e80@Vec3_95e80@owners@@QAEXMPBM@Z
void owners::Vec3_95e80::FUN_00095e80(float s, float const* v) {
    x = s * v[0];
    y = s * v[1];
    z = s * v[2];
}

namespace fn_f8b63219 {

// 0x00095f50 FUN_00095f50 (21 B): matches/0x00095f50.cpp
// sym: ?FUN_00095f50@fn_f8b63219@@YIPAUObj_95f50@1@PAU21@@Z
Obj_95f50* __fastcall FUN_00095f50(Obj_95f50* self) {
    self->a = 0x3a83126f;
    self->b = FUN_00267f80();
    return self;
}


// 0x00095f70 FUN_00095f70 (42 B): matches/0x00095f70.cpp
// sym: ?Delta@Timer@fn_f8b63219@@QAEMXZ
hulk_freg Timer::Delta() {
    unsigned int t = tick_00267f80();
    unsigned int d = t - last;
    hulk_freg result = (hulk_freg)d * scale;
    last = t;
    return result;
}


// 0x00095fa0 FUN_00095fa0 (59 B): equivalent/0x00095fa0.cpp
// sym: _FUN_00095fa0 @2086c6a3a0ff @weeae25799702 @v012116e13557
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00095fa0 @ 0x00095fa0
extern "C" void __cdecl FUN_00095fa0(float *v, float angle) {
    double radians = angle * (*(float*)&DAT_003f32b8);
    double s = sin(radians);
    double c = cos(radians);
    float x = v[0], z = v[2];
    v[0] = (float)(x*c + z*s);
    v[2] = (float)(z*c - x*s);
}


// 0x00096020 FUN_00096020 (229 B): equivalent/0x00096020.cpp
// sym: ?FUN_00096020@fn_f8b63219@@YAXPAUMatrix@1@PBUVec_96020@1@1@Z @22bad220d02e @w11355d5faf2a @v81ceed428834
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_00096020 @ 0x00096020
void __cdecl FUN_00096020(Matrix* out, const Vec_96020* a, const Vec_96020* b) {
    hulk_freg x = b->z*a->y - b->y*a->z;
    hulk_freg y = b->x*a->z - b->z*a->x;
    hulk_freg z = b->y*a->x - b->x*a->y;
    volatile float dot = b->z*a->z + b->y*a->y + a->x*b->x;
    volatile float zz = z*z;
    hulk_freg yy = y*y;
    hulk_freg xx = x*x;
    volatile float f = (1.0f-dot)/(xx+yy+zz);
    out->m[0] = xx*f+dot;
    double xyp = x*y;
    hulk_freg xy = xyp*f;
    out->m[1] = xy+z;
    double xzp = x*z;
    hulk_freg xz = xzp*f;
    volatile float xzf=xz;
    out->m[2] = xz-y;
    out->m[4] = xy-z;
    out->m[5] = yy*f+dot;
    double yzp = y*z;
    hulk_freg yz = yzp*f;
    volatile float yzf=yz;
    out->m[6] = yz+x;
    out->m[8] = xzf+y;
    out->m[9] = yzf-x;
    out->m[10] = zz*f+dot;
}

} // namespace fn_f8b63219

// 0x00096110 FUN_00096110 (291 B): equivalent/0x00096110.cpp [wrapped: conflict: Matrix]
// sym: ?FUN_00096110@fn_00096110@@YAXPAUMatrix@1@PBU21@@Z @6062fde1c940 @w5e9d12730efa @vc00f80531b45
namespace fn_00096110 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00096110 @ 0x00096110
struct Matrix { float m[3][4]; };
void __cdecl FUN_00096110(Matrix* a, const Matrix* b) {
 float r00=(a->m[0][0]*b->m[0][0]+a->m[0][2]*b->m[2][0])+b->m[1][0]*a->m[0][1];
 float r01=(a->m[0][2]*b->m[2][1]+b->m[1][1]*a->m[0][1])+b->m[0][1]*a->m[0][0];
 float r02=(b->m[2][2]*a->m[0][2]+b->m[1][2]*a->m[0][1])+a->m[0][0]*b->m[0][2];
 float r10=(a->m[1][2]*b->m[2][0]+a->m[1][0]*b->m[0][0])+a->m[1][1]*b->m[1][0];
 float r11=(a->m[1][2]*b->m[2][1]+a->m[1][1]*b->m[1][1])+b->m[0][1]*a->m[1][0];
 float r12=(a->m[1][1]*b->m[1][2]+a->m[1][0]*b->m[0][2])+a->m[1][2]*b->m[2][2];
 float r20=(a->m[2][2]*b->m[2][0]+a->m[2][0]*b->m[0][0])+b->m[1][0]*a->m[2][1];
 float r21=(a->m[2][2]*b->m[2][1]+b->m[0][1]*a->m[2][0])+b->m[1][1]*a->m[2][1];
 float r22=(b->m[1][2]*a->m[2][1]+a->m[2][0]*b->m[0][2])+a->m[2][2]*b->m[2][2];
 a->m[0][0]=r00; a->m[0][1]=r01; a->m[0][2]=r02;
 a->m[1][0]=r10; a->m[1][1]=r11; a->m[1][2]=r12;
 a->m[2][0]=r20; a->m[2][1]=r21; a->m[2][2]=r22;
}
} // namespace fn_00096110

namespace fn_f8b63219 {

// 0x000962d0 FUN_000962d0 (87 B): equivalent/0x000962d0.cpp
// sym: ?FUN_000962d0@fn_f8b63219@@YAXPAUVec3@1@PBU21@1M@Z @045f557374d4 @wb2c3e7c90640 @v5db7fa21ae29
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000962d0 @ 0x000962d0
void __cdecl FUN_000962d0(Vec3* out, const Vec3* start, const Vec3* end, float t)
{
    float x = (end->x - start->x) * t + start->x;
    float y = (end->y - start->y) * t + start->y;
    float z = (end->z - start->z) * t + start->z;
    out->x = x;
    out->y = y;
    out->z = z;
}


// 0x000963c0 FUN_000963c0 (88 B): matches/0x000963c0.cpp
// sym: ?FUN_000963c0@fn_f8b63219@@YAMMMMMM@Z
// data: zero_963c0 = DAT_003f32e0
hulk_freg FUN_000963c0(float a, float b, float c, float d, float e) {
    if (!(e <= a)) {
        if (e >= c)
            return d;
        if (c - a > DAT_003f32e0)
            return (d - b) * ((e - a) / (c - a)) + b;
    }
    return b;
}


// 0x00096450 FUN_00096450 (65 B): equivalent/0x00096450.cpp
// sym: _FUN_00096450 @6c74e81b32c4 @w45209d153210 @vc5cb0fded0bf
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_00096450 @ 0x00096450
extern "C" char* __cdecl FUN_00096450(const char* source)
{
    const char* end = source;
    while (*end) ++end;
    unsigned int length = (unsigned int)(end - source) + 1;
    char* destination = (char*)FUN_0008d6d0(length);
    if (!destination) return destination;
    for (unsigned int i = 0; i < length; ++i)
        destination[i] = source[i];
    return destination;
}


// 0x000964a0 FUN_000964a0 (47 B): matches/0x000964a0.cpp
// sym: _FUN_000964a0
// (x64t13) C linkage and its result (eax is _vsnprintf's on every path): the callers' declarations are one name
extern "C" int __cdecl FUN_000964a0(char* buffer, int size, const char* format, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, format);
#else
    char* args = (char*)&format + 4;
#endif
    int result = __vsnprintf(buffer, size, format, args);
    if (size > 0 && result == -1)
        buffer[size - 1] = 0;
    return result;
}

} // namespace fn_f8b63219
