// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
#include "tree_prelude.h"
#include "decls/load_inventory.h"   // (x64t5) HULK_LOADINVENTORY_SIZE
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f71c7272 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f71c7272 {} using namespace fn_f71c7272;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f71c7272 {
class Request {
public:
    virtual void v0();
    virtual void Release();
    char pad08[0xc];
    int state;
    int result;
    bool FUN_00266750();
    int FUN_00266700();
};
class Streamer {
public:
    void FUN_00265810(char* name, Request** out);
    int FUN_00264870();
};
class Inventory {
public:
    void FUN_00266220(int value);
};
struct Frame {
    Request* request;
    char name[0x100];
    int pad104;
    Inventory* inventory;
    int param;
    char flag;
};
class __declspec(novtable) MethodBase_bfd20 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_bfd20(const char* n, int k);
    void FUN_001d04a0();
};
template <class R, class A>
class Function1 : public MethodBase_bfd20 {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) : MethodBase_bfd20(name, 1) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    }
    Fn fn;
};
struct Frame_bfd20 {
    Function1<void, const char*> closure;
    Frame_bfd20(const char* n, void (*f)(const char*)) : closure(n, f) {
    }
};
struct Registry_bfd20 {
    void FUN_001d26d0(const char*, void*);
    void FUN_000bfd20(const char* name, void (*fn)(const char*));
};
class Base_bfda0 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_bfda0(const char*, int);
    void FUN_001d04a0();
};
template<class R>
class Function0 : public Base_bfda0 {
public:
    R (*f)();
    Function0(const char* n, R (*x)()) : Base_bfda0(n, 0) {
        f = x;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
    }
    virtual void v();
};
class Registry_bfda0 {
public:
    void FUN_001d26d0(const char* name, Base_bfda0* fn);
    void FUN_000bfda0(const char* name, void (*fn)());
};
struct Frame_bfda0 {
    Function0<void> closure;
    Frame_bfda0(const char* n, void (*f)()) : closure(n, f) {
    }
};
class Base_c0a20 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_c0a20(const char*, int);
    void FUN_001d04a0();
};
template <class T, class R>
class Method0 : public Base_c0a20 {
public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : Base_c0a20(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
    }
    virtual void v();
    Fn fn;
};
template <class T, class R>
class Closure0 : public Method0<T, R> {
public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    virtual void v();
    T* owner;
};
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };
class MethodBase_c0aa0 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_c0aa0(const char *n, int k);
    void FUN_001d04a0();
};
template <class T, class R, class A>
class Method1 : public MethodBase_c0aa0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_c0aa0(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    virtual void m0();
    Fn fn;
};
template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};
struct Closure2_c0b30 {
    char data[36];
    void FUN_000c0030(int first, int second, int third);
    void FUN_001d04a0();
};
struct Owner {
    void FUN_001d26d0(int first, Closure2_c0b30 *value);
    void FUN_000c0b30(int first, int second, int third);
};
struct Method7_c0b80 {
    virtual void invoke();
    char data[28];
    const char *second;
    Method7_c0b80(const char *, const char *);
    void FUN_001d04a0();
};
struct Closure7 : Method7_c0b80 {
    virtual void invoke();
    Closure7(const char *first, const char *third) : Method7_c0b80(first, third) {}
};
struct Manager {
    void FUN_001d26d0(const char *, Method7_c0b80 *);
    void FUN_000c0b80(const char *, const char *, const char *);
};
struct CFEManager;
struct Closure6 {
    const void* callbackTable;
    char data[0x1c];
    const char* arg2;
    void FUN_000be950(const char*, const char*);
    void FUN_001d04a0();
};
extern const void* DAT_00409300;
} // namespace fn_f71c7272
inline void *operator new(hulk_uintptr, void *p) throw() { return p; }
namespace fn_f71c7272 {
struct Id64_c1430 {
    unsigned int lo, hi;
    void FUN_0027af50();
};
struct Id40 {
    Id64_c1430 a, b, c, d;
    char pad20[8];
};
class Releasable_c1430 {
public:
    virtual void v0();
    virtual void release();
};
class Owned0 {
public:
    virtual ~Owned0();
    virtual void v1();
};
class Owned1 {
public:
    virtual void v0();
    virtual ~Owned1();
};
struct Holder3ef0 {
    char pad0[4];
    void FUN_000b3ef0();
};
class Owned0b : public Owned0 {
public:
    void FUN_000b3ef0();
};
struct Done {
    void FUN_00092be0();
};
class CFEManager {
  public:
    virtual void* m_vf0_000c1f50(char);
    char _m_pad_4[0x18];
    Releasable_c1430 *f1c;
    Releasable_c1430 *f20;
    Releasable_c1430 *f24;
    char _m_pad_28[0x20];
    int f48;
    Done *f4c;
    char _m_pad_50[0x10];
    Owned0b *f60;
    Owned1 *f64;
    Releasable_c1430 *f68;
    void *list6c[0x80];
    void *list26c[0x80];
    char _m_pad_46c[0x4];
    Id40 ids[0x80];
    void FUN_001d26d0(const char*, Closure6*);
    void FUN_000c0be0(const char*, const char*, const char*);
    void FUN_000bc750();
    void FUN_000bc1e0();
    void FUN_000b47b0(const char *, const char *);
    void FUN_000b4850(void*, void*, void*, void*, void*, void*); /* (unb4) as defined; address taken only */
    void FUN_000bc230(void*, void*, void*, void*, void*, void*); /* (unb4) as defined; address taken only */
    void FUN_000bb5c0();
    void FUN_000b4b60(const char *, const char *);
    void FUN_000b43e0();
    void FUN_000b5490();
    void FUN_000b54d0(int, int, int, int, int, int, int); /* (unb4) as defined; address taken only */
    void FUN_000b5530(int, int, int, int, int, int, int); /* (unb4) as defined; address taken only */
    void FUN_000b5590();
    void FUN_000b5670();
    void FUN_000b5710(void*, int, int, int, int, int, int); /* (unb4) as defined; address taken only */
    void FUN_000b5790();
    void FUN_000b57d0();
    void FUN_000b5810(float, float, float, float, float, float, float); /* (unb4) as defined; address taken only */
    void FUN_000c1430();
};
class Registry_c0a20 {
public:
    void FUN_001d26d0(const char* name, Base_c0a20* fn);
    void FUN_000c0a20(const char* name, CFEManager* owner, void (CFEManager::*fn)());
};
struct Frame_c0a20 {
    Closure0<CFEManager, void> closure;
    Frame_c0a20(const char* n, CFEManager* o, void (CFEManager::*f)()) : closure(n, o, f) {
    }
};
typedef Closure1<CFEManager, void, const char *> Closure_c0aa0;
struct Frame_c0aa0 {
    Closure_c0aa0 closure;
    Frame_c0aa0(const char *n, CFEManager *o, Closure_c0aa0::Fn f) : closure(n, o, f) {
    }
};
class Registry_c0aa0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_c0aa0 *m);
    void FUN_000c0aa0(const char *name, CFEManager *owner, Closure_c0aa0::Fn f);
};
class __declspec(novtable) MethodBase_c1430 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_c1430(const char *n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char *, int);
    void FUN_001d04a0();
};
template <class T, class R, class A, class B>
class Method2 : public MethodBase_c1430 {
public:
    typedef R (T::*Fn)(A, B);
    Method2(const char *name, Fn f) : MethodBase_c1430(name, 2) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};
template <class T, class R, class A, class B>
class Closure2 : public Method2<T, R, A, B> {
public:
    Closure2(const char *name, T *o, typename Method2<T, R, A, B>::Fn f) : Method2<T, R, A, B>(name, f), owner(o) {}
    T *owner;
};
void FUN_000b45a0(const char *);
void FUN_000b45b0(const char *);
extern "C" void FUN_000b45d0(const char *);
struct CFEManager_c1430;
struct CFEManager_c1430 {
    void FUN_000c0a20(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0aa0(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0b80(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0be0(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0c40(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000c0cc0(const char *, CFEManager *, void (CFEManager::*)());
    void FUN_000bfd20(const char *, void (*)(const char *));
    void FUN_000bfda0(const char *, void (*)(const char *));
    void FUN_001d26d0(const char *, MethodBase_c1430 *);
};
CFEManager_c1430 *FUN_001d4c90();
extern "C" void FUN_000fc3e0();
struct State_c4220;
struct ThisNote_000c3ea0 {
    void FUN_000c3ea0();
};
struct Player_c4220 { void FUN_001b7310(const char*, int, int); };
struct Screen_c4220 { void FUN_001edf60(); void FUN_001ec480(const char*, const char*); };
struct State_c4220 {
 char pad0[8]; unsigned char finished; char pad9[7]; int mode; char pad14[0x28]; Screen_c4220* screen; char pad40[0x1b89]; char suffix[1];
 bool FUN_000c3900(const char*,int,int,int,int,int,int);
 void update(Player_c4220* player);
};

} // namespace fn_f71c7272

// 0x000befc0 FUN_000befc0 (285 B): matches/0x000befc0.cpp
// sym: ?FUN_000befc0@Loader_befc0@owners@@QAEXPBDH_N@Z
// STATUS: equivalent (tools/equiv.py level 3: 2538 inputs, branch coverage 10/10)
// FUN_000befc0 @ 0x000befc0
void owners::Loader_befc0::FUN_000befc0(const char* name, int param, bool pump)
{
    Frame fr;
    fr.inventory = (*(Inventory**)&DAT_004dd9cc);
    fr.request = 0;
    fr.name[0] = 0;
    fr.pad104 = 0;
    fr.param = 0;
    fr.flag = 0;
    if (name != 0)
        _strncpy(fr.name, name, 0xff);
    fr.flag = 0;
    fr.param = param;
    (*(Streamer**)&DAT_00527c58)->FUN_00265810(fr.name, &fr.request);
    int saved = (*(Streamer**)&DAT_00527c58)->FUN_00264870();
    ((owners::C_264860 *)((*(Streamer**)&DAT_00527c58)))->FUN_00264860(250000);
    while (!fr.request->FUN_00266750()) {
        FUN_00087990();
        if (pump)
            FUN_000bd1b0(0);
    }
    ((owners::C_264860 *)((*(Streamer**)&DAT_00527c58)))->FUN_00264860(saved);
    (*(Inventory**)&DAT_004dd9cc)->FUN_00266220(fr.request->FUN_00266700());
    if (fr.request != 0)
        fr.request->Release();
}


// 0x000bfa10 FUN_000bfa10 (455 B): equivalent/0x000bfa10.cpp [wrapped: conflict: FUN_000fc1b0]
// sym: ?FUN_000bfa10@UnlockMenu@fn_000bfa10@@QAEXHH@Z @203d8ff8a617 @wbfee5d32b7ae
namespace fn_000bfa10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000bfa10 @ 0x000bfa10
// cl-flags: /GS

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char* buf, const char* fmt, ...);
#endif


struct Lookup_bfa10 {
    void FUN_00093950(int a, int b, char* foundOut, char* flagA, char* flagB, int* pairOut);
};

struct Strings_bfa10 {
    int FUN_000f7240(int a, int b);
};

struct DialogMgr {
    void FUN_000be230(const char* name, const char* msg, const char* s1, const char* s2, const char* ok, int a, int b, int c);
    void FUN_000be310(const char* name, const char* msg, const char* s1, const char* s2, const char* ok, int a, int b, int c);
};

Strings_bfa10* FUN_000fc1b0();
DialogMgr* FUN_000fc3d0();
extern "C" int FUN_000fc020(char* buf, int size, const char* fmt, ...);

struct Frame_bfa10 {
    char unused;
    char flagA;
    char flagB;
    char found;
    int pair[2];
    char dialog[0x20];
    char text[0x80];
    char rest[0x80];
};

struct UnlockMenu {
    char pad[0x4c];
    Lookup_bfa10* lookup;

    void FUN_000bfa10(int arg1, int arg2);
};

void UnlockMenu::FUN_000bfa10(int arg1, int arg2)
{
    Frame_bfa10 f;
    if (lookup != 0) {
        lookup->FUN_00093950(arg1, arg2, &f.found, &f.flagA, &f.flagB, f.pair);
        if ((char)arg2 != 0)
            sprintf(f.dialog, "%s", "FEGenericSimDialog");
        else
            sprintf(f.dialog, "%s", "FEGenericDialog");

        if (f.found == 0) {
            FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_INVALID_ENTRY", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
        } else if (f.flagB != 0) {
            Strings_bfa10* s = FUN_000fc1b0();
            int key = ((int)((owners::A_f7d30 *)s)->FUN_000f7d30((hulk_intptr)"TBS_UNLOCKABLES_VALID_ENTRY_2"));
            const char* fmt = ((const char *)((owners::C_f7220 *)s)->FUN_000f7220((hulk_intptr)key));
            int a = f.pair[0];
            int b = f.pair[1];
            int v = FUN_000fc1b0()->FUN_000f7240(a, b);
            const char* arg = ((const char *)((owners::C_f7220 *)(FUN_000fc1b0()))->FUN_000f7220((hulk_intptr)v));
            FUN_000fc020(f.text, 0x80, fmt, arg);
            FUN_000fc3d0()->FUN_000be310(f.dialog, f.text, "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
        } else {
            if (f.flagA != 0)
                FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_INVALID_ENTRY_2", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
            if ((char)arg2 != 0)
                FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_GENERIC_CODE_WRONG_LOCATION_1", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
            else
                FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_UP_CODE_WRONG_LOCATION_2", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
        }
    }
}
} // namespace fn_000bfa10

namespace fn_f71c7272 {

// 0x000bfd20 FUN_000bfd20 (118 B): matches/0x000bfd20.cpp
// sym: ?FUN_000bfd20@Registry_bfd20@fn_f71c7272@@QAEXPBDP6AX0@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000bfd20 @ 0x000bfd20
// Function1<R, A> (a static function bound to Lua): Function's fields (include/decls/data/script.h), then the
// function pointer.
void Registry_bfd20::FUN_000bfd20(const char* name, void (*fn)(const char*)) {
    Frame_bfd20 fr(name, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}


// 0x000bfda0 FUN_000bfda0 (104 B): matches/0x000bfda0.cpp
// sym: ?FUN_000bfda0@Registry_bfda0@fn_f71c7272@@QAEXPBDP6AXXZ@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000bfda0 @ 0x000bfda0
// Function0<R> (a static function bound to Lua): Function's fields (include/decls/data/script.h), then the
// function pointer.
void Registry_bfda0::FUN_000bfda0(const char* name, void (*fn)()) {
    Frame_bfda0 fr(name, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}


// 0x000c0a20 FUN_000c0a20 (120 B): matches/0x000c0a20.cpp
// sym: ?FUN_000c0a20@Registry_c0a20@fn_f71c7272@@QAEXPBDPAVCFEManager@2@P832@AEXXZ@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0a20 @ 0x000c0a20
void Registry_c0a20::FUN_000c0a20(const char* name, CFEManager* owner, void (CFEManager::*fn)()) {
    Frame_c0a20 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}


// 0x000c0aa0 FUN_000c0aa0 (134 B): matches/0x000c0aa0.cpp
// sym: ?FUN_000c0aa0@Registry_c0aa0@fn_f71c7272@@QAEXPBDPAVCFEManager@2@P832@AEX0@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0aa0 @ 0x000c0aa0
void Registry_c0aa0::FUN_000c0aa0(const char *name, CFEManager *owner, Closure_c0aa0::Fn f) {
    Frame_c0aa0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}


// 0x000c0b30 FUN_000c0b30 (79 B): matches/0x000c0b30.cpp
// sym: ?FUN_000c0b30@Owner@fn_f71c7272@@QAEXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0b30 @ 0x000c0b30
void Owner::FUN_000c0b30(int first, int second, int third) {
    Closure2_c0b30 value;
    value.FUN_000c0030(first, second, third);
    FUN_001d26d0(first, &value);
    value.FUN_001d04a0();
}


// 0x000c0b80 FUN_000c0b80 (90 B): equivalent/0x000c0b80.cpp
// sym: ?FUN_000c0b80@Manager@fn_f71c7272@@QAEXPBD00@Z @624314ad8c4d @we95606312e5b
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000c0b80 @ 0x000c0b80
void Manager::FUN_000c0b80(const char *first, const char *second, const char *third)
{
    Closure7 closure(first, third);
    closure.second = second;
    FUN_001d26d0(first, &closure);
    closure.FUN_001d04a0();
}


// 0x000c0be0 FUN_000c0be0 (90 B): matches/0x000c0be0.cpp
// sym: ?FUN_000c0be0@CFEManager@fn_f71c7272@@QAEXPBD00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0be0 @ 0x000c0be0
void CFEManager::FUN_000c0be0(const char* first, const char* second, const char* third) {
    Closure6 closure;
    closure.FUN_000be950(first,third);
    closure.arg2=second;
    closure.callbackTable=&DAT_00409300;
    this->FUN_001d26d0(first,&closure);
    closure.FUN_001d04a0();
}

} // namespace fn_f71c7272

// 0x000c0c40 FUN_000c0c40 (120 B): matches/0x000c0c40.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_000c0c40@Registry_c0c40@fn_000c0c40@@QAEXPBDPAVCFEManager@2@P832@AEHXZ@Z
namespace fn_000c0c40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0c40 @ 0x000c0c40
// cl-flags: /GS
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


class CFEManager { public: int FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_c0c40 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_c0c40(const char* n, int k);
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_c0c40 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_c0c40(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e134));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_c0c40 {
    Closure0<CFEManager, int> closure;
    Frame_c0c40(const char* n, CFEManager* o, int (CFEManager::*f)()) : closure(n, o, f) {
    }
};

struct Registry_c0c40 {
    void FUN_001d26d0(const char*, void*);
    void FUN_000c0c40(const char* name, CFEManager* owner, int (CFEManager::*fn)());
};

void Registry_c0c40::FUN_000c0c40(const char* name, CFEManager* owner, int (CFEManager::*fn)()) {
    Frame_c0c40 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_000c0c40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c0cc0 FUN_000c0cc0 (134 B): matches/0x000c0cc0.cpp [wrapped: conflict: Method1]
// sym: ?FUN_000c0cc0@Registry_c0cc0@fn_000c0cc0@@QAEXPBDPAVCFEManager@2@P832@AEXH@Z@Z
namespace fn_000c0cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0cc0 @ 0x000c0cc0
// cl-flags: /GS
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


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };

class CFEManager {
public:
    virtual void vfn0();
};

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class MethodBase_c0cc0 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_c0cc0(const char *n, int k);
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_c0cc0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_c0cc0(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    virtual void m0();
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CFEManager, void, int> Closure_c0cc0;

struct Frame_c0cc0 {
    Closure_c0cc0 closure;
    Frame_c0cc0(const char *n, CFEManager *o, Closure_c0cc0::Fn f) : closure(n, o, f) {
    }
};

class Registry_c0cc0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_c0cc0 *m);
    void FUN_000c0cc0(const char *name, CFEManager *owner, Closure_c0cc0::Fn f);
};

void Registry_c0cc0::FUN_000c0cc0(const char *name, CFEManager *owner, Closure_c0cc0::Fn f) {
    Frame_c0cc0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_000c0cc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f71c7272 {

// 0x000c1430 FUN_000c1430 (853 B): equivalent/0x000c1430.cpp
// sym: ?FUN_000c1430@CFEManager@fn_f71c7272@@QAEXXZ @ef174ec69ea2 @wf8f1281b471e
// STATUS: equivalent (tools/equiv.py level 3: 1176 inputs, branch coverage 26/26)
// FUN_000c1430 @ 0x000c1430
void CFEManager::FUN_000c1430()
{
    new (this) CFEManager;
    CFEManager_c1430 *reg = FUN_001d4c90();
    if (reg) {
        reg->FUN_000c0a20("fe_StartNextMission", this, &CFEManager::FUN_000bc750);
        reg->FUN_000bfd20("fe_changeScreen", FUN_000b45a0);
        reg->FUN_000bfda0("fe_backScreen", FUN_000b45b0);
        reg->FUN_000bfd20("fe_loadScript", FUN_000b45d0);
        reg->FUN_000c0aa0("fe_doScreen", this, &CFEManager::FUN_000bc1e0);
        {
            Closure2<CFEManager, void, const char *, const char *> c("fe_fullscreenMessage", this, &CFEManager::FUN_000b47b0);
            reg->FUN_001d26d0("fe_fullscreenMessage", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_000c0b80("fe_fullscreenMessageEx", this, (void (CFEManager::*)())&CFEManager::FUN_000b4850);
        reg->FUN_000c0be0("fe_fullscreenQuestion", this, (void (CFEManager::*)())&CFEManager::FUN_000bc230);
        reg->FUN_000c0a20("fe_unlockStory", this, &CFEManager::FUN_000bb5c0);
        {
            Closure2<CFEManager, void, const char *, const char *> c("AddValidMission", this, &CFEManager::FUN_000b4b60);
            reg->FUN_001d26d0("AddValidMission", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_000c0c40("fe_GetSelectedMove", this, &CFEManager::FUN_000b43e0);
        reg->FUN_000c0aa0("fe_SetupSMSuccessName", this, &CFEManager::FUN_000b5490);
        reg->FUN_000c0b80("fe_SetupSMSuccessResult", this, (void (CFEManager::*)())&CFEManager::FUN_000b54d0);
        reg->FUN_000c0b80("fe_SetupSMSuccessRecord", this, (void (CFEManager::*)())&CFEManager::FUN_000b5530);
        reg->FUN_000c0cc0("fe_SetupSMSuccessRanking", this, &CFEManager::FUN_000b5590);
        reg->FUN_000c0cc0("fe_SetupSMSuccessSmashPointsAward", this, &CFEManager::FUN_000b5670);
        reg->FUN_000c0b80("fe_SetupSMSuccessNewRecord", this, (void (CFEManager::*)())&CFEManager::FUN_000b5710);
        reg->FUN_000c0aa0("fe_SetupSMFailName", this, &CFEManager::FUN_000b5790);
        reg->FUN_000c0aa0("fe_SetupSMFailHint", this, &CFEManager::FUN_000b57d0);
        reg->FUN_000c0b80("fe_SetupSMFailRecord", this, (void (CFEManager::*)())&CFEManager::FUN_000b5810);
        if (f1c) {
            f1c->release();
            f1c = 0;
        }
        if (f20) {
            f20->release();
            f20 = 0;
        }
        if (f24) {
            f24->release();
            f24 = 0;
        }
        if (f60) {
            f60->FUN_000b3ef0();
            if (f60) {
                delete f60;
                f60 = 0;
            }
        }
        FUN_000fc3e0();
        if (f68) {
            f68->release();
            f68 = 0;
        }
        int i;
        for (i = 0; i < 0x80; i++) {
            if (!list6c[i])
                break;
            FUN_0008d340(list6c[i]);
            list6c[i] = 0;
        }
        for (i = 0; i < 0x80; i++) {
            if (!list26c[i])
                break;
            FUN_0008d340(list26c[i]);
            list26c[i] = 0;
        }
        if (f64) {
            delete f64;
            f64 = 0;
        }
        f4c->FUN_00092be0();
        f4c = 0;
        f48 = 0;
    }
    for (int i = 0x7f; i >= 0; i--) {
        ids[i].d.FUN_0027af50();
        ids[i].c.FUN_0027af50();
        ids[i].b.FUN_0027af50();
        ids[i].a.FUN_0027af50();
    }
}

} // namespace fn_f71c7272

// 0x000c1790 FUN_000c1790 (811 B): equivalent/0x000c1790.cpp [wrapped: conflict: FUN_000964a0; FUN_000fc1b0; FUN_000fc260]
// sym: ?FUN_000c1790@FrontEnd_c1790@fn_000c1790@@QAE_NPBD@Z @b57ebaed9f8b @w8f4c7a0a0779
namespace fn_000c1790 {
// STATUS: equivalent (tools/equiv.py level 3: 6070 inputs, branch coverage 43/46, incomplete)
// FUN_000c1790 @ 0x000c1790
// cl-flags: /GS
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
extern "C" int strncmp(const char* a, const char* b, unsigned int n);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char* a, const char* b);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char* d, const char* s, unsigned int n);
#endif


namespace pure3d { class TextureFont_c1790; }

struct Font {
};

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Loader_c1790 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Font* v3(content::LoadInventory::DynamicCaster<pure3d::TextureFont_c1790>* caster, unsigned __int64 hash);
    void FUN_002665a0();
};

struct Ui_c1790 {
    void FUN_000f7850();
    void FUN_000f89e0();
};

struct Label_c1790 {
};

struct DynamicLabel {
    char pad00[0x18];
    Label_c1790 label;
};

struct Panel_c1790 {
    void FUN_001bde90();
    void FUN_001bdeb0();
};


extern "C" int __cdecl FUN_00266da0(int mode);
Ui_c1790* __cdecl FUN_000fc1b0();
const char* __cdecl FUN_000f7120(int index);
void FUN_000964a0(char* buf, int size, const char* fmt, ...);
bool __cdecl FUN_000fc1c0(const char* path);
DynamicLabel* __cdecl FUN_000fc260(const char* name);

struct Frame_c1790 {
    content::LoadInventory::DynamicCaster<pure3d::TextureFont_c1790> caster;
    void* self;
    Ui_c1790* ui;
    int oldMode;
    char path[0x40];
    unsigned short text[0x100];
};

class FrontEnd_c1790 {
public:
    char pad00[0x5c];
    Panel_c1790* panel;
    char pad60[0x1bc9 - 0x60];
    char lang[8];
    int FUN_000bc900(unsigned short* buf, int pos, const char* key, int idx);
    void FUN_000bc3c0(const char* path, Loader_c1790* loader, int zero);
    bool FUN_000c1790(const char* code);
};

bool FrontEnd_c1790::FUN_000c1790(const char* code)
{
    Frame_c1790 f;
    f.self = this;
    f.oldMode = FUN_00266da0(0xe);
    f.ui = FUN_000fc1b0();
    if (strncmp(code, "en", 2) == 0 && DAT_004dd839)
        code = "uk";
    int idx = -1;
    for (int i = 0; i < 6; i++) {
        if (strncmp(code, FUN_000f7120(i), 2) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1)
        idx = 0;
    FUN_000964a0(f.path, 0x40, (*(const char**)&DAT_0049f3b8), code);
    if (FUN_000fc1c0(f.path)) {
        strncpy(lang, code, 3);
    } else {
        for (int i = 0; i < 6; i++) {
            FUN_000964a0(f.path, 0x40, (*(const char**)&DAT_0049f3b8), FUN_000f7120(i));
            if (FUN_000fc1c0(f.path)) {
                strncpy(lang, FUN_000f7120(i), 3);
                break;
            }
        }
    }
    if (panel)
        ((owners::Thing_1bde50 *)panel)->FUN_001bde50(idx);
    (*(Loader_c1790**)&DAT_004dd9c8)->FUN_002665a0();
    if (f.ui)
        f.ui->FUN_000f7850();
    if (panel)
        panel->FUN_001bde90();
    (*(Loader_c1790**)&DAT_004dd9c8)->FUN_002665a0();
    FUN_000964a0(f.path, 0x40, "art/fonts_%s.p3d", lang);
    this->FUN_000bc3c0(f.path, (*(Loader_c1790**)&DAT_004dd9c8), 0);
    const char* first;
    const char* second;
    if (strncmp("jp", lang, 2) == 0) {
        first = "font_msgothic";
        second = "font_eurostilesmall";
    } else {
        first = "font_futura_lt_med";
        second = "font_serpentine_lt_med";
    }
    {
        Loader_c1790* ld = (*(Loader_c1790**)&DAT_004dd9c8);
        unsigned __int64 h = FUN_0027b020(first);
        new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::TextureFont_c1790>;
        ((owners::C_295250 *)(ld->v3(&f.caster, h)))->FUN_00295250(0xfa0);
    }
    {
        Loader_c1790* ld = (*(Loader_c1790**)&DAT_004dd9c8);
        unsigned __int64 h = FUN_0027b020(second);
        new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::TextureFont_c1790>;
        ((owners::C_295250 *)(ld->v3(&f.caster, h)))->FUN_00295250(0xfa0);
    }
    Ui_c1790* ui = f.ui;
    if (ui) {
        ui->FUN_000f89e0();
        int i = 0;
        do {
            if (strcmp(lang, FUN_000f7120(i)) == 0)
                break;
            i++;
        } while (i < 6);
        if (i >= 6)
            i = 0;
        ((owners::C_f6fe0 *)ui)->FUN_000f6fe0(i);
    }
    if (panel)
        panel->FUN_001bdeb0();
    DynamicLabel* dl = FUN_000fc260("DynamicControlButtonLabel");
    if (dl) {
        Label_c1790* lbl = &dl->label;
        if (lbl) {
            int p = this->FUN_000bc900(f.text, 0, "TBS_MENU_ITEM_BONUS_FEATURES_SELECT", 0);
            this->FUN_000bc900(f.text, p, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            ((owners::Obj_f79a0 *)lbl)->FUN_000f79a0((const short *)(f.text), (hulk_intptr)0);
        }
    }
    FUN_00266da0(f.oldMode);
    return true;
}
} // namespace fn_000c1790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c1b50 FUN_000c1b50 (887 B): equivalent/0x000c1b50.cpp [wrapped: conflict: Frame; content::LoadInventory::DynamicCaster]
// sym: ?FUN_000c1b50@GalleryScreen@fn_000c1b50@@QAEXHHH@Z @d4ba45ad2859 @w644c1f14ca94
namespace fn_000c1b50 {
// STATUS: equivalent (tools/equiv.py level 3: 1706 inputs, branch coverage 45/46, incomplete)
// FUN_000c1b50 @ 0x000c1b50
// cl-flags: /GS



namespace pure3d { class Texture; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); int pad4; }; } }

struct Pair {
    int a;
    int b;
};

struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
};

struct Manager {
    int FUN_000f7240(int a, int b);
    const unsigned short* FUN_000f7220(int id);
};
Manager* __cdecl FUN_000fc1b0();

struct TextEntry {
    char pad[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const char* name, Manager* manager, int flag);
    void FUN_000f79a0(const unsigned short* text, int flag);
};


class FEObject {
public:
    virtual void vfunc_0();
};
FEObject* __cdecl FUN_000fc260(const char* name);

class TextSelector : public FEObject {
public:
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
    virtual void vfunc_19(TextEntry* entry, int a, int b);
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int index);
    char pad04[0x154 - 4];
    int cursor;
    char pad158[0x1d58 - 0x158];
    int count;
    void FUN_000e36c0();
};

class ImageSelector : public FEObject {
public:
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
    virtual void vfunc_19(void* tex, int row, int col, int id, int flag);
    int FUN_000e4000();
};

class CUnlockable {
public:
    virtual void v0();
};

class CUnlockableGallery : public CUnlockable {
public:
    Id64* FUN_00092340(Id64* out);
    int FUN_00092370();
};

struct ItemTable {
    CUnlockable* FUN_00092ad0(int index);
    Pair* FUN_00092bb0(int index);
    const char* FUN_00092bc0(int index);
    char FUN_00092860(int index);
    char FUN_00092a40(int index);
};

struct Holder {
    void* tex;
};

struct Inventory {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void* find(content::LoadInventory::DynamicCaster<pure3d::Texture>* caster, unsigned __int64 key);
};


unsigned short* __cdecl FUN_000fb690(unsigned short* dst, const unsigned short* src, int n);
unsigned short* __cdecl FUN_000fb790(unsigned short* dst, const unsigned short* src, int n);

class GalleryScreen;

// The caster's slot doubles as scratch for the image loop: the original keeps `row` in its
// first word and spills img's vptr into the second (across the FUN_00092370 call), and the
// next lookup's caster still carries that word in its pad.
struct Probe {
    union {
        char caster[sizeof(content::LoadInventory::DynamicCaster<pure3d::Texture>)];  // 0x1c
        struct {
            int row;
            void *imgVtbl;
        } t;
    };
    Id64 id;                                                        // 0x24
};

struct Frame {
    union {
        int *dest;      // 0x10
        int j;
    } u10;
    union {
        int cursor;     // 0x14
        int i;
    } u14;
    GalleryScreen *self;                                           // 0x18
    Probe pr;                                                      // 0x1c
    TextEntry entry2;                                              // 0x2c
    TextEntry entry1;                                              // 0x50
    unsigned short buf[0x80];                                      // 0x74
};

class GalleryScreen {
public:
    char pad0[0x4c];
    ItemTable* items;
    char pad50[0x1ba4 - 0x50];
    int list[1];
    void FUN_000c1b50(int kind, int first, int last);
};

void GalleryScreen::FUN_000c1b50(int kind, int first, int last)
{
    Frame f;
    f.self = this;
    f.entry1.FUN_000f7930();
    f.entry1.FUN_000f8500(((char*)&DAT_003f335c), FUN_000fc1b0(), 1);

    if ((kind >= 0x248 && kind <= 0x257) || (kind >= 0x258 && kind <= 0x260)) {
        const char* name = items->FUN_00092bc0(kind);
        if (name != 0) {
            TextSelector* sel = dynamic_cast<TextSelector*>(FUN_000fc260(name));
            if (sel != 0) {
                f.u14.cursor = sel->cursor;
                sel->FUN_000e36c0();
                f.u10.dest = list;
                for (int i = first; i <= last; i++) {
                    if (items->FUN_00092860(i))
                        continue;
                    Pair* p = items->FUN_00092bb0(i);
                    if ((p->a | p->b) == 0)
                        continue;
                    int id = FUN_000fc1b0()->FUN_000f7240(p->a, p->b);
                    if (id == -1)
                        continue;
                    f.entry2.FUN_000f7930();
                    f.entry2.FUN_000f8500(((char*)&DAT_003f335c), FUN_000fc1b0(), 1);
                    FUN_000fb690(f.buf, FUN_000fc1b0()->FUN_000f7220(id), 0x80);
                    if (items->FUN_00092a40(i))
                        FUN_000fb790(f.buf, L"\x0820\x756e", 0x80);
                    f.entry2.FUN_000f79a0(f.buf, 0);
                    sel->vfunc_19(&f.entry2, 0, 0);
                    if (first == 0x258)
                        *f.u10.dest++ = i;
                    f.entry2.FUN_000f7960();
                }
                int last_index = sel->count - 1;
                int idx;
                if (f.u14.cursor >= 0) {
                    if (f.u14.cursor <= last_index)
                        idx = f.u14.cursor;
                    else
                        idx = last_index;
                } else {
                    if (f.u14.cursor <= last_index)
                        idx = 0;
                    else
                        idx = last_index;
                }
                sel->vfunc_25(idx);
                sel->vfunc_3();
            }
        }
    } else {
        f.u10.j = 0;
        for (f.u14.i = first; f.u14.i <= last; f.u14.i++, f.u10.j++) {
            const char* name = f.self->items->FUN_00092bc0(f.u14.i);
            if (name == 0)
                continue;
            ImageSelector* img = dynamic_cast<ImageSelector*>(FUN_000fc260(name));
            if (img == 0)
                continue;
            CUnlockableGallery* gal = dynamic_cast<CUnlockableGallery*>(f.self->items->FUN_00092ad0(f.u14.i));
            if (gal == 0)
                continue;
            Id64* key = gal->FUN_00092340(&f.pr.id);
            Inventory* inv = (*(Inventory**)&DAT_004dd9cc);
            void* tex = inv->find(new (f.pr.caster) content::LoadInventory::DynamicCaster<pure3d::Texture>, *(unsigned __int64*)key);
            f.pr.id.FUN_0027af50();
            if (tex == 0)
                continue;
            if (f.self->items->FUN_00092860(f.u14.i))
                continue;
            int m = f.u10.j % 10;
            f.pr.t.row = m / img->FUN_000e4000();
            int col = m % img->FUN_000e4000();
            f.pr.t.imgVtbl = *(void **)img;
            img->vfunc_19(tex, f.pr.t.row, col, gal->FUN_00092370(), 0);
        }
    }
    f.entry1.FUN_000f7960();
}
} // namespace fn_000c1b50


// 0x000c1f70 FUN_000c1f70 (573 B): equivalent/0x000c1f70.cpp [wrapped: conflict: FUN_000fc1b0; content::LoadInventory::DynamicCaster]
// sym: ?FUN_000c1f70@BlonskyScreen@fn_000c1f70@@QAEXH@Z @c4200a4dc70c @w573db945596e
namespace fn_000c1f70 {
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 18/18)
// FUN_000c1f70 @ 0x000c1f70
// cl-flags: /GS
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


namespace pure3d { class Texture; class Shader; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Pair_c1f70 {
    int a;
    int b;
};

class CUnlockable {
public:
    virtual void v0();
};

class CUnlockableBlonskyFile : public CUnlockable {
public:
    Pair_c1f70* FUN_00091d00();
    const char* FUN_00091d50();
};

struct ItemTable_c1f70 {
    CUnlockable* FUN_00092ad0(int index);
    Pair_c1f70* FUN_00092bb0(int index);
};

struct Manager_c1f70 {
    int FUN_000f7240(int a, int b);
};
Manager_c1f70* __cdecl FUN_000fc1b0();

struct NameSource_c1f70 {
    const char* FUN_0027b010();
};

struct TextEntry_c1f70 {
    void FUN_000f7a10(int id, int flag);
    void FUN_000f8500(const char* name, Manager_c1f70* manager, int flag);
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14];
    TextEntry_c1f70 entry;
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_4();
};

class TextWindow : public FEObject {
public:
    virtual void vfunc_4();
};

FEObject* __cdecl FUN_000fc260(const char* name);

struct Resource_c1f70 {
    char pad[0x10];
    int f10;
};

struct Slot_c1f70 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void set(int what, int value);
    char pad[0xc];
    Slot_c1f70* inner;
};

struct ShaderHolder {
    char pad[0x10];
    Slot_c1f70* slot;
};

struct LoadInventory_c1f70 {
    virtual void init();
    virtual void release();
    virtual void a2();
    virtual Resource_c1f70* find(content::LoadInventory::DynamicCaster<pure3d::Texture>* caster, unsigned __int64 key);
    LoadInventory_c1f70* FUN_00266480(int size);
};

struct Inventory_c1f70 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual ShaderHolder* find(content::LoadInventory::DynamicCaster<pure3d::Shader>* caster, unsigned __int64 key);
};


void* __cdecl FUN_00263ea0(int size);
int __cdecl FUN_000964a0(char* dst, int size, const char* fmt, ...);

struct Frame_c1f70 {
    char path[0x100];
    char image[0x100];
};

class BlonskyScreen {
public:
    char pad0[0x4c];
    ItemTable_c1f70* items;
    void FUN_000bc3c0(const char* path, LoadInventory_c1f70* loader, int kind);
    void FUN_000c1f70(int index);
};

void BlonskyScreen::FUN_000c1f70(int index)
{
    Frame_c1f70 frame;

    if (items != 0) {
        CUnlockableBlonskyFile* file = dynamic_cast<CUnlockableBlonskyFile*>(items->FUN_00092ad0(index));
        if (file != 0) {
            TextLabel* title = dynamic_cast<TextLabel*>(FUN_000fc260("blonsky_file_title"));
            if (title != 0) {
                Pair_c1f70* p = items->FUN_00092bb0(index);
                int arg1_ = p->b;
                int arg2_ = p->a;
                int id = FUN_000fc1b0()->FUN_000f7240(arg2_, arg1_);
                if (id == -1) {
                    Manager_c1f70* m = FUN_000fc1b0();
                    NameSource_c1f70* ns = (NameSource_c1f70*)items->FUN_00092bb0(index);
                    const char* tmp1 = ns->FUN_0027b010();
                    title->entry.FUN_000f8500(tmp1, m, 1);
                } else {
                    title->entry.FUN_000f7a10(id, 0);
                }
            }
            TextWindow* text = dynamic_cast<TextWindow*>(FUN_000fc260("blonsky_file_text"));
            if (text != 0) {
                Pair_c1f70* q = file->FUN_00091d00();
                int arg3_ = q->b;
                int arg4_ = q->a;
                int id = FUN_000fc1b0()->FUN_000f7240(arg4_, arg3_);
                if (id == -1) {
                    Manager_c1f70* m = FUN_000fc1b0();
                    NameSource_c1f70* ns = (NameSource_c1f70*)file->FUN_00091d00();
                    const char* tmp2 = ns->FUN_0027b010();
                    text->entry.FUN_000f8500(tmp2, m, 1);
                } else {
                    text->entry.FUN_000f7a10(id, 0);
                }
                text->vfunc_3();
            }

            const char* name = file->FUN_00091d50();
            FUN_000964a0(frame.path, 0x100, "art/blonsky_file_images/%s.p3d", name);
            LoadInventory_c1f70* loader = (LoadInventory_c1f70*)FUN_00263ea0(HULK_LOADINVENTORY_SIZE);
            if (loader)
                loader = loader->FUN_00266480(0x400);
            loader->init();
            FUN_000bc3c0(frame.path, loader, 0xb);
            FUN_000964a0(frame.image, 0x100, "%s.png", name);
            unsigned __int64 key = FUN_0027b020(frame.image);
            content::LoadInventory::DynamicCaster<pure3d::Texture> textureCaster;
            Resource_c1f70* tex = loader->find(&textureCaster, key);
            if (tex != 0) {
                Inventory_c1f70* inv = (*(Inventory_c1f70**)&DAT_004dd9cc);
                unsigned __int64 key2 = FUN_0027b020("blonksy_image_shader");
                content::LoadInventory::DynamicCaster<pure3d::Shader> shaderCaster;
                ShaderHolder* shader = inv->find(&shaderCaster, key2);
                if (shader != 0)
                    shader->slot->set(0x584554, tex->f10);
            }
            loader->release();
        }
    }
}
} // namespace fn_000c1f70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c21b0 FUN_000c21b0 (2006 B): equivalent/0x000c21b0.cpp [wrapped: conflict: FUN_000964a0; FUN_000fb690; TextLabel; TextSelector]
// sym: ?FUN_000c21b0@UnlockMenu@fn_000c21b0@@QAEXH@Z @4abeb9d90c6f @w0460a50e73ac
namespace fn_000c21b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20092 inputs, branch coverage 135/136, incomplete)
// FUN_000c21b0 @ 0x000c21b0
// cl-flags: /GS
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


class Entry;
class Manager {
  public:
    int FUN_000f7240(unsigned long long key);
    const unsigned short* FUN_000f7220(int id);
    int FUN_000f7d30(const char* name);
};
class Entry {
  public:
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const char* name, Manager* manager, char flag);
    void FUN_000f79a0(const unsigned short* text, int flag);
    void FUN_000f7a10(int id, int flag);
};

class CUnlockable {
  public:
    virtual void v0();
};
class CUnlockableMove : public CUnlockable {
  public:
    int FUN_00091f70();
    char FUN_00091f40();
    int FUN_00091f90();
    const unsigned long long* FUN_00092050();
    const char* FUN_00092040();
};
class UnlockTable {
  public:
    CUnlockable* FUN_00092ad0(int index);
    const unsigned long long* FUN_00092bb0(int index);
    const char* FUN_00092bc0(int index);
    char FUN_00092860(int index);
    char FUN_00092940(int index);
    char FUN_00092a40(int index);
    int FUN_000932a0(int index);
};

class FEControl {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    char pad0[0x141 - 4];
    char enabled;
    char pad1[0x154 - 0x142];
    int selected;
};
class FEObject {
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
};
class IValueChangedReceiver {
  public:
    virtual void h0();
};
class IValueChangedSender {
  public:
    virtual void i0();
};
class TextSelector : public FEControl,
                     public FEObject,
                     public IValueChangedReceiver,
                     public IValueChangedSender {
  public:
    char pad2[0x1d58 - 0x158 - 12];
    int count;
    void FUN_000e36c0();
    virtual void v19(Entry* text, int a, int b);
    virtual void v20(int row, Entry* text);
    virtual void v21(int row, unsigned int enabled);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int selected);
};
class TextButton : public FEControl,
                   public FEObject,
                   public IValueChangedReceiver,
                   public IValueChangedSender {
  public:
};
class TextLabel : public FEObject,
                  public IValueChangedReceiver,
                  public IValueChangedSender {
  public:
    char pad[0x18 - 12];
    Entry text;
};

class Sub {
  public:
    int FUN_00090110();
};
class Core {
  public:
    Sub* FUN_00086370();
};
class World {
  public:
    char pad[0x54];
    Core* core;
};
class Page {
  public:
    char FUN_000893c0();
};

Manager* __cdecl FUN_000fc1b0();
FEObject* __cdecl FUN_000fc260(const char* name);
void __cdecl FUN_000fb690(unsigned short* dst, const unsigned short* src, int count);
void __cdecl FUN_000fb790(unsigned short* dst, const char* src, int count);
void __cdecl FUN_000fc020(unsigned short* dst, int count, const unsigned short* fmt, ...);
void __cdecl FUN_000964a0(char* dst, int size, const char* fmt, ...);

class UnlockMenu {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x34 - 0x14];
    Page* page;
    char pad2[0x4c - 0x38];
    UnlockTable* table;
    void FUN_000b7860(int arg);
    void FUN_000c1b50(int id, int lo, int hi);
    void FUN_000c21b0(volatile int id);
};

void UnlockMenu::FUN_000c21b0(volatile int id) {
    struct Frame {
        volatile int k;  // sel in the first block, loop index in the second
        volatile int row;
        volatile int sel;
        union { unsigned char b; unsigned int w; } unlocked;
        Entry text;
        int nameId;
        char numBuf[0x10];
        unsigned short wide[0x80];
    } frame;
    if (table == 0) {
        return;
    }
    frame.text.FUN_000f7930();
    Manager* tmp1 = FUN_000fc1b0();
    frame.text.FUN_000f8500("", tmp1, 1);
    bool refresh = true;
    do {
        if (id >= 0x34 && id <= 0x51) {
            const char* name = table->FUN_00092bc0(0x34);
            if (name == 0) {
                refresh = false;
                break;
            }
            TextSelector* list = dynamic_cast<TextSelector*>(FUN_000fc260(name));
            if (list == 0) {
                refresh = false;
                break;
            }
            frame.k = list->selected;
            list->FUN_000e36c0();
            for (int i = 0x34; i <= 0x51; i++) {
                const unsigned long long* key = table->FUN_00092bb0(i);
                if (*key == 0)
                    break;
                if (table->FUN_00092860(i))
                    continue;
                key = table->FUN_00092bb0(i);
                if (*key == 0)
                    continue;
                unsigned long long arg1_ = *key;
                int stringId = FUN_000fc1b0()->FUN_000f7240(arg1_);
                if (stringId == -1)
                    continue;
                Manager* tmp2 = FUN_000fc1b0();
                frame.text.FUN_000f8500("", tmp2, 1);
                FUN_000fb690(frame.wide, FUN_000fc1b0()->FUN_000f7220(stringId), 0x80);
                if (table->FUN_00092a40(i))
                    FUN_000fb790(frame.wide, " \bnu", 0x80);
                frame.text.FUN_000f79a0(frame.wide, 0);
                list->v19(&frame.text, 0, 0);
            }
            int last = list->count - 1;
            if (frame.k >= 0) {
                if (frame.k > last)
                    frame.k = last;
            } else if (frame.k <= last) {
                frame.k = 0;
            } else {
                frame.k = last;
            }
            list->v25(frame.k);
            list->f3();
            TextButton* button = dynamic_cast<TextButton*>(FUN_000fc260("menu_item_blonsky_file"));
            if (button)
                button->enabled = (list->count != 0);
            FUN_000b7860(0);
        } else if ((id >= 0x266 && id <= 0x2c9) || id == 0x1d) {
            bool giftedAvailable = false;
            if (!table->FUN_00092860(0x1d))
                giftedAvailable = table->FUN_00092940(0x1d) != 0;
            CUnlockableMove* head = dynamic_cast<CUnlockableMove*>(table->FUN_00092ad0(0x266));
            if (head == 0) {
                refresh = false;
                break;
            }
            const char* listName = head->FUN_00092040();
            if (listName == 0) {
                refresh = false;
                break;
            }
            TextSelector* list = dynamic_cast<TextSelector*>(FUN_000fc260(listName));
            if (list == 0)
                break;
            frame.sel = list->selected;
            list->FUN_000e36c0();
            frame.row = 0;
            if (page->FUN_000893c0()) {
                frame.text.FUN_000f8500("TBS_CHEAT_SAVAGE_BANNER", 0, 1);
                list->v19(&frame.text, 0, 0);
                if (table->FUN_00092860(4)) {
                    FUN_000964a0(frame.numBuf, 0x10, "%d", 1000000);
                    Manager* tmp3 = FUN_000fc1b0();
                    frame.text.FUN_000f8500(frame.numBuf, tmp3, 0);
                } else {
                    Manager* tmp4 = FUN_000fc1b0();
                    frame.text.FUN_000f8500("TBS_UNLOCKABLE_MOVE_ENABLED", tmp4, 1);
                }
                list->v20(0, &frame.text);
                frame.row = 1;
            }
            for (frame.k = 0x266; frame.k <= 0x2c9; frame.k++) {
                int idx = table->FUN_000932a0(frame.k - 0x266);
                if (idx == -1)
                    continue;
                const unsigned long long* key = table->FUN_00092bb0(idx);
                if (*key == 0)
                    continue;
                if (table->FUN_00092860(idx) && !giftedAvailable)
                    continue;
                key = table->FUN_00092bb0(idx);
                if (*key == 0)
                    continue;
                unsigned long long arg2_ = *key;
                int stringId = FUN_000fc1b0()->FUN_000f7240(arg2_);
                if (stringId == -1)
                    continue;
                Manager* tmp5 = FUN_000fc1b0();
                frame.text.FUN_000f8500("", tmp5, 1);
                FUN_000fb690(frame.wide, FUN_000fc1b0()->FUN_000f7220(stringId), 0x80);
                if (table->FUN_00092a40(idx))
                    FUN_000fb790(frame.wide, " \bnu", 0x80);
                frame.text.FUN_000f79a0(frame.wide, 0);
                list->v19(&frame.text, 0, 0);
                CUnlockableMove* move = dynamic_cast<CUnlockableMove*>(table->FUN_00092ad0(idx));
                if (move == 0) {
                    frame.row++;    // the original still counts the row (jumps to the increment)
                    continue;
                }
                int cost = move->FUN_00091f70();
                const unsigned long long* nameKey = move->FUN_00092050();
                unsigned long long arg3_ = *nameKey;
                frame.nameId = FUN_000fc1b0()->FUN_000f7240(arg3_);
                if (cost <= 0) {
                    Manager* tmp6 = FUN_000fc1b0();
                    frame.text.FUN_000f8500("TBS_UNLOCKABLE_MOVE_GIFTED", tmp6, 1);
                } else if (move->FUN_00091f40()) {
                    if (state == 9) {
                        frame.text.FUN_000f7a10(frame.nameId, 0);
                    } else {
                        Manager* tmp7 = FUN_000fc1b0();
                        frame.text.FUN_000f8500("TBS_UNLOCKABLE_MOVE_ENABLED", tmp7, 1);
                    }
                } else {
                    FUN_000964a0(frame.numBuf, 0x10, "%d", cost);
                    Manager* tmp8 = FUN_000fc1b0();
                    frame.text.FUN_000f8500(frame.numBuf, tmp8, 0);
                }
                list->v20(frame.row, &frame.text);
                frame.unlocked.b = 1;
                int requires = move->FUN_00091f90();
                if (requires != -1) {
                    CUnlockableMove* other = dynamic_cast<CUnlockableMove*>(table->FUN_00092ad0(requires));
                    if (other)
                        frame.unlocked.b = other->FUN_00091f40();
                }
                list->v21(frame.row, frame.unlocked.w);
                frame.row++;
            }
            int last = list->count - 1;
            if (frame.sel >= 0) {
                if (frame.sel > last)
                    frame.sel = last;
            } else if (frame.sel <= last) {
                frame.sel = 0;
            } else {
                frame.sel = last;
            }
            list->v25(frame.sel);
            list->f3();
            TextButton* button = dynamic_cast<TextButton*>(FUN_000fc260("menu_item_buy_menu"));
            if (button)
                button->enabled = (list->count != 0);
            TextLabel* label = dynamic_cast<TextLabel*>(FUN_000fc260("moves_list_smash_points"));
            if (label == 0)
                break;
            int points = DAT_004dd700->core->FUN_00086370()->FUN_00090110();
            Manager* strings = FUN_000fc1b0();
            FUN_000fc020(frame.wide, 0x40, strings->FUN_000f7220(strings->FUN_000f7d30("TBS_SMASH_POINTS_TOTAL")), points);
            label->text.FUN_000f79a0(frame.wide, 0);
        } else if (id >= 0x52 && id <= 0x8d) {
            FUN_000c1b50(id, 0x52, 0x8d);
        } else if (id >= 0x1bf && id <= 0x1f0) {
            FUN_000c1b50(id, 0x1bf, 0x1f0);
        } else if (id >= 0x1f1 && id <= 0x209) {
            FUN_000c1b50(id, 0x1f1, 0x209);
        } else if (id >= 0x258 && id <= 0x260) {
            FUN_000c1b50(id, 0x258, 0x260);
        } else if (id >= 0x20a && id <= 0x22d) {
            FUN_000c1b50(id, 0x20a, 0x22d);
        } else if (id >= 0x22e && id <= 0x243) {
            FUN_000c1b50(id, 0x22e, 0x243);
        } else if (id >= 0x244 && id <= 0x247) {
            FUN_000c1b50(id, 0x244, 0x247);
        } else if (id >= 0x248 && id <= 0x257) {
            FUN_000c1b50(id, 0x248, 0x257);
        }
    } while (0);
    if (refresh && id >= 0 && id <= 0x1f && !table->FUN_00092860(id)) {
        const char* name = table->FUN_00092bc0(id);
        if (name != 0) {
            TextSelector* row = dynamic_cast<TextSelector*>(FUN_000fc260(name));
            if (row != 0) {
                char hidden = table->FUN_00092940(id);
                row->enabled = 1;
                row->v25(hidden == 0);
            }
        }
    }
    frame.text.FUN_000f7960();
}
} // namespace fn_000c21b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c2990 FUN_000c2990 (510 B): equivalent/0x000c2990.cpp [wrapped: conflict: FUN_001d4c90]
// sym: ?run@Target_c2990@fn_000c2990@@QAEXPAUOutput_c2990@2@@Z @9a15de49e39b @weaec597f9f38
namespace fn_000c2990 {
// STATUS: equivalent (tools/equiv.py level 3: 3073 inputs, branch coverage 26/26)
// FUN_000c2990 @ 0x000c2990
// cl-flags: /GS
struct Track { const char* FUN_00092330(); int FUN_00092310(); void FUN_00092360(int); };
struct Lookup_c2990 {  };
struct Manager_c2990 {  };
struct Group_c2990 { void FUN_001bdff0(const char*); };
struct Output_c2990 { void FUN_001b7310(const char*,int,int); };
extern int DAT_0049dab8, DAT_0049db80;
extern "C" Track* __cdecl FUN_00344e74(Track*,int,const void*,const void*,int);
extern "C++" Manager_c2990* __cdecl FUN_001d4c90();
extern "C" int __cdecl FUN_000964a0(char*,int,const char*,...);
struct Target_c2990 {
 char pad0[0x10]; int state; char pad14[0x38]; Lookup_c2990* lookup; char pad50[0xc]; Group_c2990* group; char pad60[0x1810]; unsigned char active; char pad1871[3]; int id;
 void FUN_000ba040(); void FUN_000c21b0(int);
 void run(Output_c2990* out);
};
void Target_c2990::run(Output_c2990* out) {
 Track* track = FUN_00344e74(((Track *)((owners::C_92ad0 *)lookup)->FUN_00092ad0((hulk_intptr)id)),0,&DAT_0049dab8,&DAT_0049db80,0);
 if (track) {
  if (!active) {
   char path[64];
   Manager_c2990* manager = FUN_001d4c90();
   FUN_000964a0(path,64,"frontend/lang/subtitles/timings/%s.lua",track->FUN_00092330());
   ((owners::Object_1d3600 *)manager)->FUN_001d3600(path, 0);
   const char* names[8] = {"mog1","mog2","mog3","mog4","mog5","mog6","mog7","mog8"};
   for (int block=0; block<2; ++block) {
    bool matched=false;
    for (int index=0; index<4; ++index) {
     const char* name=track->FUN_00092330();
     const char* expected=names[block*4+index];
     int ch=0;
     while (ch<5 && name[ch]==expected[ch]) ++ch;
     if (ch==5) { matched=true; break; }
    }
    if (matched && group) group->FUN_001bdff0(block==0 ? "mog1-4" : "mog5-8");
   }
   out->FUN_001b7310(track->FUN_00092330(),1000,1);
   active=1;
   track->FUN_00092360(0);
   FUN_000ba040();
   FUN_000c21b0(id);
  } else {
   if (track->FUN_00092310()>1) out->FUN_001b7310(track->FUN_00092330(),1000,1);
   active=0;
   state=0;
  }
 }
}
} // namespace fn_000c2990


// 0x000c2c20 FUN_000c2c20 (1462 B): equivalent/0x000c2c20.cpp [wrapped: conflict: DAT_0049dab8; FUN_000fc1b0; FUN_000fc260; World]
// sym: ?F@MovesMenu@fn_000c2c20@@QAEXXZ @6a848bf091c0 @w53c127cc8cae
namespace fn_000c2c20 {
// STATUS: equivalent (tools/equiv.py level 3: 3124 inputs, branch coverage 66/66)
// FUN_000c2c20 @ 0x000c2c20
// cl-flags: /GS
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

extern char DAT_0049dba4[];
extern char DAT_0049dab8[];
extern char DAT_0049db1c[];
extern char DAT_0049dbbc[];
extern char DAT_0049f470[];
extern char DAT_0049f48c[];
extern char DAT_0049f4a4[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);
extern int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
extern int __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);
extern "C" void __cdecl FUN_000fc280(const char *name);

struct Shader;
struct Tex;

struct Name_c2c20 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    Name_c2c20 *FUN_0027b0e0(const char *s);
    void FUN_0027af70(const Name_c2c20 *other);
    void FUN_0027af50();
    const char *FUN_0027b010();
};

struct Loc_c2c20 {
    int FUN_000f7240(unsigned int lo, unsigned int hi);
};
extern Loc_c2c20 *__cdecl FUN_000fc1b0();

struct Label_c2c20 {
    void FUN_000f8500(const char *text, Loc_c2c20 *loc, char flag);
};

class Widget_c2c20 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x18 - 4];
    Label_c2c20 label;
    char pad2c[0x74 - 0x18 - sizeof(Label_c2c20)];
    char b74;
    char pad75[0x141 - 0x75];
    char b141;
    char pad142[0x154 - 0x142];
    int sel;
    char pad158[0x1d58 - 0x158];
    void *p1d58;
};

struct Unlockable {
    char pad0[0x10];
    Name_c2c20 id;
    const char *FUN_00092040();
    Name_c2c20 *FUN_00092050();
    Name_c2c20 *FUN_00092070();
    const char *FUN_00092090();
    char FUN_00091f40();
};

struct Unlockables_c2c20 {
    void FUN_000929a0(int id, int z);
};

struct Gate_c2c20 {
};

struct Shader {
    void FUN_000b4280(void *global, Tex *tex);
};
extern int DAT_00584554;
extern "C" Shader *__cdecl FUN_000c0db0(void *a, const char *name);
extern "C" Tex *__cdecl FUN_000c1ed0(void *a, const char *name);

struct Holder54_c2c20 {
    struct Pts *FUN_00086370();
};
struct Pts {
    int FUN_00090110();
};
struct World {
    char pad0[0x54];
    Holder54_c2c20 *p54;
};

class MovesMenu {
public:
    char pad0[0x34];
    Gate_c2c20 *p34;
    char pad38[0x4c - 0x38];
    Unlockables_c2c20 *p4c;
    void FUN_000c21b0(int id);
    void FUN_000ba040();
    void FUN_000b8c50(const char *a, const char *b);
    void F();
};

void MovesMenu::F()
{
    char flagD, f0e, flagF;
    Name_c2c20 C;
    Name_c2c20 B;
    Name_c2c20 A;
    Name_c2c20 E;
    Name_c2c20 *nameDesc;
    const char *image;
    __declspec(align(8)) char buf[0x100];

    if (!p4c) {
        return;
    }
    Unlockable *unl = (Unlockable *)FUN_00344e74(((Unlockable *)((owners::C_92ad0 *)p4c)->FUN_00092ad0((hulk_intptr)0x266)), 0, DAT_0049dab8, DAT_0049db1c, 0);
    if (!unl) {
        return;
    }
    const char *name = unl->FUN_00092040();
    if (!name) {
        return;
    }
    Widget_c2c20 *sel = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260(name), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (!sel || !sel->p1d58 || sel->sel == -1) {
        return;
    }
    int idx = sel->sel;
    f0e = 0;
    if (((char)((owners::Target_893c0 *)p34)->FUN_000893c0())) {
        if (idx == 0)
            f0e = 1;
        idx--;
    }
    if (!FUN_00344e74(FUN_000fc260(name), 0, DAT_0049dba4, DAT_0049dbbc, 0)) {
        return;
    }
    A.FUN_0027af00();
    B.FUN_0027b0e0("TBS_UNLOCKABLE_MOVE_DESCRIPTION_SAVAGE");
    C.FUN_0027af00();
    Name_c2c20 *combo;
    int id;
    if (f0e) {
        id = 4;
        combo = &A;
        nameDesc = &B;
        image = "savage_banner";
        flagD = ((char)((owners::C_92860 *)p4c)->FUN_00092860((hulk_intptr)id)) == 0;
        flagF = 0;
        C.FUN_0027af70(E.FUN_0027b0e0("TBS_CHEAT_SAVAGE_BANNER"));
        E.FUN_0027af50();
    } else {
        id = ((owners::C_932a0 *)p4c)->FUN_000932a0(idx);
        Unlockable *u2 = (Unlockable *)FUN_00344e74(((Unlockable *)((owners::C_92ad0 *)p4c)->FUN_00092ad0((hulk_intptr)id)), 0, DAT_0049dab8, DAT_0049db1c, 0);
        if (!u2) {
            C.FUN_0027af50();
            B.FUN_0027af50();
            A.FUN_0027af50();
            return;
        }
        combo = u2->FUN_00092050();
        nameDesc = u2->FUN_00092070();
        image = u2->FUN_00092090();
        flagD = u2->FUN_00091f40();
        flagF = ((char)((owners::A_91fb0 *)u2)->FUN_00091fb0());
        C.FUN_0027af70(&u2->id);
    }
    p4c->FUN_000929a0(id, 0);
    FUN_000c21b0(id);
    FUN_000ba040();
    FUN_000fc280("MovesDescription");
    if (C.lo | C.hi) {
        Widget_c2c20 *t = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_name"), 0, DAT_0049dba4, DAT_0049f48c, 0);
        if (t) {
            Label_c2c20 *lbl = &t->label;
            unsigned clo = C.lo, chi = C.hi;      // the arguments are read before the receiver is fetched
            int r = FUN_000fc1b0()->FUN_000f7240(clo, chi);
            if (r == -1)
                lbl->FUN_000f8500(C.FUN_0027b010(), FUN_000fc1b0(), 1);
            else
                ((owners::Obj_f7a10 *)lbl)->FUN_000f7a10((hulk_intptr)r, 0);
        }
    }
    if (combo) {
        Widget_c2c20 *t = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_button_combo"), 0, DAT_0049dba4, DAT_0049f48c, 0);
        if (t) {
            Label_c2c20 *lbl = &t->label;
            if (f0e) {
                lbl->FUN_000f8500("", 0, 1);
            } else {
                unsigned clo = combo->lo, chi = combo->hi;      // the arguments are read before the receiver is fetched
                int r = FUN_000fc1b0()->FUN_000f7240(clo, chi);
                if (r == -1)
                    lbl->FUN_000f8500(combo->FUN_0027b010(), FUN_000fc1b0(), 1);
                else
                    ((owners::Obj_f7a10 *)lbl)->FUN_000f7a10((hulk_intptr)r, 0);
            }
        }
    }
    Name_c2c20 *desc = nameDesc;
    if (desc) {
        Widget_c2c20 *t = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_description"), 0, DAT_0049dba4, DAT_0049f470, 0);
        if (t) {
            Label_c2c20 *lbl = &t->label;
            unsigned dlo = desc->lo, dhi = desc->hi;      // the arguments are read before the receiver is fetched
            int r = FUN_000fc1b0()->FUN_000f7240(dlo, dhi);
            if (r == -1)
                lbl->FUN_000f8500(desc->FUN_0027b010(), FUN_000fc1b0(), 1);
            else
                ((owners::Obj_f7a10 *)lbl)->FUN_000f7a10((hulk_intptr)r, 0);
            t->vfunc_3();
        }
    }
    const char *img = image;
    if (img) {
        Shader *sh = FUN_000c0db0((*(void**)&DAT_004dd9cc), "moves_gallery_image_shader");
        if (sh) {
            FUN_000964a0(buf, 0x100, "%s.png", img);
            Tex *tex = FUN_000c1ed0((*(void**)&DAT_004dd9cc), buf);
            if (tex)
                sh->FUN_000b4280(((int*)0x584554), tex);
        }
    }
    Widget_c2c20 *btn = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("purchase_move"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    char bl = flagF;
    if (btn) {
        if (!bl && flagD) {
            btn->b141 = bl;
            btn->b74 = bl;
        } else {
            btn->b141 = 1;
            btn->b74 = 1;
        }
        Label_c2c20 *lbl = &btn->label;
        if (bl && flagD)
            FUN_000fc020(buf, 0x40, ((const char *)((owners::A_88ea0 *)(FUN_000fc1b0()))->FUN_00088ea0((hulk_uintptr)"TBS_MENU_ITEM_TUTORIAL")));
        else
            FUN_000fc020(buf, 0x40, ((const char *)((owners::A_88ea0 *)(FUN_000fc1b0()))->FUN_00088ea0((hulk_uintptr)"TBS_MENU_ITEM_PURCHASE_MOVE")));
        ((owners::Obj_f79a0 *)lbl)->FUN_000f79a0((const short *)buf, (hulk_intptr)0);
        btn->vfunc_3();
    }
    Widget_c2c20 *pts = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_smash_points"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (pts) {
        int p = DAT_004dd700->p54->FUN_00086370()->FUN_00090110();
        FUN_000fc020(buf, 0x40, ((const char *)((owners::A_88ea0 *)(FUN_000fc1b0()))->FUN_00088ea0((hulk_uintptr)"TBS_SMASH_POINTS_TOTAL")), p);
        ((owners::Obj_f79a0 *)&(pts->label))->FUN_000f79a0((const short *)buf, (hulk_intptr)0);
    }
    if (FUN_00344e74(FUN_000fc260("moves_list_smash_points"), 0, DAT_0049dba4, DAT_0049f48c, 0)) {
        int p = DAT_004dd700->p54->FUN_00086370()->FUN_00090110();
        FUN_000fc020(buf, 0x40, ((const char *)((owners::A_88ea0 *)(FUN_000fc1b0()))->FUN_00088ea0((hulk_uintptr)"TBS_SMASH_POINTS_TOTAL")), p);
        ((owners::Obj_f79a0 *)&(pts->label))->FUN_000f79a0((const short *)buf, (hulk_intptr)0);
    }
    if (!bl && flagD)
        FUN_000b8c50("MovesDescription", "return_to_move_list");
    C.FUN_0027af50();
    B.FUN_0027af50();
    A.FUN_0027af50();
}
} // namespace fn_000c2c20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c31e0 FUN_000c31e0 (1814 B): equivalent/0x000c31e0.cpp [wrapped: macros]
// sym: ?FUN_000c31e0@Env@fn_000c31e0@@QAEXPBD@Z @18010c589c55 @w63ec5548467d
namespace fn_000c31e0 {
// STATUS: equivalent (tools/equiv.py level 3: 1585 inputs, branch coverage 147/148, incomplete)
// FUN_000c31e0 @ 0x000c31e0
// cl-flags: /GS
// FUN_000c31e0 @ 0x000c31e0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
// equiv-map: ??_R0?AVImageSelector@@@8 = 0x0049f454
// equiv-map: ??_R0?AVTextLabel@@@8 = 0x0049f48c
// equiv-map: ??_R0?AVCUnlockable@@@8 = 0x0049dab8
// equiv-map: ??_R0?AVCUnlockableMove@@@8 = 0x0049db1c
// equiv-map: ??_R0?AVCUnlockableCheat@@@8 = 0x0049dafc
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


typedef unsigned short wchar_t;


namespace pure3d { class CompositeDrawable; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Inner {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
};

struct Loaded {
    virtual void l0();
    char pad4[0x50 - 4];
    Inner *f50;
};

struct Inventory {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded *find(void *caster, unsigned __int64 key);
};

struct Loc {
    const wchar_t *FUN_00088ea0(const char *key);
};

struct Lab {
    void FUN_000f8500(const char *key, Loc *loc, int one);
};

class FEObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22();
};

class TextSelector : public FEObject {
public:
    char pad_ts[0x154 - 0x4];
    int f154;
    char pad158[0x1d58 - 0x158];
    int f1d58;
};

class ImageSelector : public FEObject {
public:
    virtual int v23();
    int FUN_000e3fe0();
};

class TextLabel : public FEObject {
public:
    char pad_tl[0x18 - 0x4];
    Lab lab;
};

class CUnlockable {
public:
    virtual void u0();
    char pad_cu[4];
    unsigned char b08;
    char FUN_00091f40();
    void FUN_00091f30(int v);
    char FUN_00091fb0();
    int FUN_00091f90();
    int FUN_00091f70();
};

class CUnlockableMove : public CUnlockable {
};

class CUnlockableCheat : public CUnlockable {
public:
    char pad_c[0x20 - 0xc];       // the derived class starts at the base size rounded up to 4
    unsigned char b20;
};

struct Menu {
    const char *FUN_00092bc0(int i);
    int FUN_000932a0(int i);
    char FUN_00092860(int i);
    void FUN_000929a0(int a, int b);
    CUnlockable *FUN_00092ad0(int i);
    char FUN_00092940(int i);
    void FUN_00092870(int i, int v);
    void FUN_00093600(int i, char on);
};

struct Sound {
    int FUN_00090110();
    void FUN_000900a0(int v);
};

struct Flagger {
    char FUN_000893c0();
};

struct Hook {
    void FUN_001b8af0();
};

struct Credits {
    virtual void c0();
    virtual void c1(const char *a, const char *b);
};

struct Dlg {
    void FUN_000be230(const char *cls, const char *msg, const char *s3, const char *s4, const char *s5, int a, int b, int c);
    void FUN_000be310(const char *cls, const wchar_t *msg, const char *s3, const char *s4, const char *s5, int a, int b, int c);
};

FEObject *__cdecl FUN_000fc260(const char *name);
extern "C" void __cdecl FUN_000fc280(const char *s);
Loc *__cdecl FUN_000fc1b0();
Dlg *__cdecl FUN_000fc3d0();
extern "C" int __cdecl FUN_000fb720(const wchar_t *s);
void __cdecl FUN_000fb690(wchar_t *dst, const wchar_t *src, int n);
void __cdecl FUN_000964a0(char *dst, int n, const char *fmt, ...);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char *a, const char *b);
#endif


struct Frame {
    unsigned char pad0[3];
    unsigned char flag;              // E-0x14d
    int pad4;
    int caster;                      // E-0x148
    char buf[0x40];                  // E-0x144
    wchar_t wide[0x80];              // E-0x104
};

#define DIALOG_OK(KEY) FUN_000fc3d0()->FUN_000be230("FEGenericDialog", KEY, "", "", "TBS_MENU_ITEM_OK", 2, 0, 0)
#define DIALOG_YN(KEY) FUN_000fc3d0()->FUN_000be230("FEGenericDialog", KEY, "", "TBS_MENU_ITEM_YES", "TBS_MENU_ITEM_NO", 2, 0, 0)

class Env {
public:
    char pad0[0x10];
    int f10;
    char pad14[0x34 - 0x14];
    Flagger *f34;
    char pad38[0x40 - 0x38];
    Credits *f40;
    char pad44[0x4c - 0x44];
    Menu *f4c;
    Sound *f50;
    Hook *f54;
    char pad58[0x1244 - 0x58];
    int tblBase;                     // 0x1244: int table indexed by id
    char pad1248[0x1874 - 0x1248];
    int f1874;
    unsigned char b1878;
    char pad1879[3];
    int f187c;
    char pad1880[0x1a04 - 0x1880];
    unsigned char b1a04;
    unsigned char b1a05;
    char pad1a06[0x1cec - 0x1a06];
    int f1cec;

    void FUN_000c1f70(int i);
    void FUN_000c21b0(int i);
    void FUN_000ba040();
    void FUN_000be100();
    void FUN_000bb5c0();
    void FUN_000bb600();
    void FUN_000b64f0();
    void FUN_000c2c20();
    void FUN_000c31e0(const char *name);
};

void Env::FUN_000c31e0(const char *name)
{
    Frame f;
    TextSelector *ts = dynamic_cast<TextSelector *>(FUN_000fc260(name));
    ImageSelector *is = dynamic_cast<ImageSelector *>(FUN_000fc260(name));
    int idx;
    do {
        if (ts != 0 && ts->f1d58 != 0) {
            idx = ts->f154;
        } else {
            if (is == 0)
                break;
            if (is->FUN_000e3fe0() == 0)
                break;
            idx = is->v23();
        }
        if (idx == -1)
            break;
        int i;
        for (i = 0; i < 0x2fe; i++) {
            const char *p = f4c->FUN_00092bc0(i);
            if (p == 0)
                continue;
            if (strcmp(p, name) == 0) {
                idx += i;
                break;
            }
        }
        f.flag = 0;
        bool direct = false;
        if (idx >= 0x266 && idx <= 0x2c9) {
            if (f34->FUN_000893c0()) {
                if (idx == 0x266) {
                    f.flag = 1;
                    direct = true;
                } else {
                    idx = idx - 0x267;
                }
            } else {
                idx = idx - 0x266;
            }
            if (!direct)
                idx = f4c->FUN_000932a0(idx);
        }
        if (!direct) {
            if (idx >= 0x258 && idx <= 0x260)
                idx = (&tblBase)[idx];
            if (!f4c->FUN_00092860(idx)) {
                if (idx >= 0x34 && idx <= 0x51) {
                    FUN_000c1f70(idx);
                    TextLabel *tl = dynamic_cast<TextLabel *>(FUN_000fc260("dycrypting_sequence_text"));
                    if (tl != 0)
                        tl->lab.FUN_000f8500("TBS_MENU_ITEM_DECRYPTING_SEQUENCE", FUN_000fc1b0(), 1);
                    Inventory *inv = (*(Inventory**)&DAT_004dd9cc);
                    unsigned __int64 key = FUN_0027b020("decryptingProgressBar");
                    new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>();
                    Loaded *ld = inv->find(&f.caster, key);
                    if (ld != 0) {
                        Inner *in = ld->f50;
                        if (in != 0) {
                            in->v16(2);
                            in->v18(1);
                        }
                    }
                    f4c->FUN_000929a0(idx, 0);
                    FUN_000c21b0(idx);
                    FUN_000ba040();
                    FUN_000fc280("blonsky_file");
                } else if ((idx >= 0x1bf && idx <= 0x1f0) || (idx >= 0x1f1 && idx <= 0x209) ||
                           (idx >= 0x20a && idx <= 0x22d) || (idx >= 0x22e && idx <= 0x243) ||
                           (idx >= 0x244 && idx <= 0x247) || (idx >= 0x52 && idx <= 0x8d)) {
                    f187c = idx;
                    f10 = 0xc;
                    b1878 = 0;
                    b1a04 = 0;
                    b1a05 = 0;
                    break;
                } else if ((idx >= 0x248 && idx <= 0x257) || (idx >= 0x261 && idx <= 0x265) ||
                           (idx >= 0x258 && idx <= 0x260) || idx == 0x32) {
                    f1874 = idx;
                    f10 = 0xd;
                } else if (idx == 0x33) {
                    if (f54 == 0)
                        break;
                    f54->FUN_001b8af0();
                    Credits *c = f40;
                    f10 = 0xe;
                    c->c1("Credits", "Enter");
                    break;
                } else if (idx >= 0 && idx <= 0x1e) {
                    char r = f4c->FUN_00092940(idx);
                    f4c->FUN_00092870(idx, r == 0);
                } else if (idx == 0x1f) {
                    FUN_000bb5c0();
                    f4c->FUN_00092870(idx, 1);
                    DIALOG_OK("TBS_MENU_ITEM_BONUS_FE_CHEATS_UNLOCKED_42");
                    break;
                }
            }
            if (idx < 0x266 || idx > 0x2c9)
                break;
        }

        CUnlockableMove *mv = 0;
        if (!f.flag) {
            mv = dynamic_cast<CUnlockableMove *>(f4c->FUN_00092ad0(idx));
            if (mv == 0)
                break;
        }
        CUnlockableCheat *ch = dynamic_cast<CUnlockableCheat *>(f4c->FUN_00092ad0(0x1d));
        bool confirm = false;
        if (ch != 0 && ch->b08 == 0 && ch->b20 != 0) {
            confirm = true;
        } else if (f.flag) {
            if (!f4c->FUN_00092860(4))
                confirm = true;
        } else {
            if (mv->FUN_00091f40())
                confirm = true;
        }
        if (confirm) {
            if (mv != 0)
                mv->FUN_00091f30(1);
            FUN_000c21b0(idx);
            if (mv != 0 && mv->FUN_00091fb0()) {
                DIALOG_YN("TBS_UNLOCKABLE_MOVE_GO_TO_TUTORIAL");
                f1cec = idx;
                f10 = 0x17;
                FUN_000be100();
            } else {
                DIALOG_OK("TBS_UNLOCKABLE_MOVE_PURCHASED");
            }
            break;
        }

        if (mv != 0) {
            int c = mv->FUN_00091f90();
            if (c >= 0) {
                CUnlockableMove *m2 = dynamic_cast<CUnlockableMove *>(f4c->FUN_00092ad0(c));
                if (m2 != 0 && !m2->FUN_00091f40()) {
                    FUN_000964a0(f.buf, 0x40, "TBS_UNLOCKABLE_MOVE_%d", c - 0x265);
                    Loc *loc = FUN_000fc1b0();
                    int len = FUN_000fb720(loc->FUN_00088ea0("TBS_NEED_TO_BUY"));
                    wchar_t *dst2 = f.wide + len;
                    FUN_000fb690(f.wide, loc->FUN_00088ea0("TBS_NEED_TO_BUY"), len + 1);
                    int len2 = FUN_000fb720(loc->FUN_00088ea0(f.buf));
                    FUN_000fb690(dst2, loc->FUN_00088ea0(f.buf), len2 + 1);
                    FUN_000fc3d0()->FUN_000be310("FEGenericDialog", f.wide, "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
                    break;
                }
            }
        }
        if (f50 == 0)
            break;
        int xp = f50->FUN_00090110();
        int cost;
        if (f.flag)
            cost = 1000000;
        else
            cost = mv->FUN_00091f70();
        if (cost > xp) {
            DIALOG_OK("TBS_UNLOCKABLE_MOVE_NOT_ENOUGH_XP");
            break;
        }
        f50->FUN_000900a0(-cost);
        if (mv != 0)
            mv->FUN_00091f30(1);
        if (f.flag)
            f4c->FUN_00093600(4, 0);
        FUN_000c21b0(idx);
        if (mv != 0 && mv->FUN_00091fb0()) {
            DIALOG_YN("TBS_UNLOCKABLE_MOVE_PURCHASED_GO_TO_TUTORIAL");
            f1cec = idx;
            f10 = 0x17;
            FUN_000be100();
        } else {
            DIALOG_OK("TBS_UNLOCKABLE_MOVE_PURCHASED");
        }
        FUN_000bb600();
        FUN_000c21b0(idx);
        if (f.flag)
            FUN_000b64f0();
        FUN_000c2c20();
    } while (0);
}
} // namespace fn_000c31e0
#undef DIALOG_OK
#undef DIALOG_YN
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c3900 FUN_000c3900 (989 B): equivalent/0x000c3900.cpp [wrapped: macros]
// sym: ?target@Game@fn_000c3900@@QAE_NPBDIIH0II@Z @10832da029fb @wbbe9a71ce634
namespace fn_000c3900 {
// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 62/62)
// FUN_000c3900 @ 0x000c3900
// cl-flags: /GS
// FUN_000c3900 @ 0x000c3900
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

typedef unsigned int U;
struct Obj { virtual void init(); virtual void release(); };
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Inner { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void set(U,U); virtual void enable(U,U); };
struct Resource : Obj { char pad[12]; Inner* inner; Resource* FUN_0028edb0(); };
struct Loader : Obj { virtual void a2(); virtual Obj* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*, unsigned __int64); Loader* FUN_00266480(int); };
#define V(n) virtual void v##n();
struct Gfx { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) virtual void select(int); };
struct Screen { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) virtual void finish(); };
struct Root { char pad[0xe4]; Screen* screen; };
struct Other { void FUN_000929a0(U,int); };
int __cdecl FUN_000964a0(char*,int,const char*,...);
void* __cdecl FUN_00263ea0(int);
extern "C" U __cdecl FUN_00267f80();
extern "C" void __cdecl FUN_000b9230(Obj*);
struct Game { char p0[0x4c]; Other* other; char p1[0x187c-0x50]; U id; char p2[0x1a08-0x1880]; U start;
void FUN_000bc3c0(const char*,Loader*,int); void FUN_000bd050(); void FUN_000b9470(int,Resource*); bool FUN_000bdf50(bool,int); void FUN_000c21b0(U);
bool target(const char*,U,U,int,const char*,U,U);
};
bool Game::target(const char* name,U duration,U threshold,int mode,const char* folder,U unused,U fade) {
 bool result=false;
U elapsed;
if(!start) {
 if((*(Obj**)&DAT_004dde34)){ (*(Obj**)&DAT_004dde34)->release(); (*(Obj**)&DAT_004dde34)=0; }
 if((*(Resource**)&DAT_004dde30)){ (*(Resource**)&DAT_004dde30)->release(); (*(Resource**)&DAT_004dde30)=0; }
 struct Frame { content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster; char path[256]; char image[256]; } frame;
 if(mode==0) FUN_000964a0(frame.path,256,"art/%s.p3d",name);
 else if(mode==1) FUN_000964a0(frame.path,256,"%s/%s.p3d",folder,name);
 Loader* l=(Loader*)FUN_00263ea0(HULK_LOADINVENTORY_SIZE); if(l) l=l->FUN_00266480(1024);
 l->init(); FUN_000bc3c0(frame.path,l,11);
 FUN_000964a0(frame.image,256,"%s.png",name);
 unsigned __int64 key=FUN_0027b020(frame.image);
 (*(Obj**)&DAT_004dde34)=l->find(&frame.caster,key); (*(Obj**)&DAT_004dde34)->init();
 start=FUN_00267f80();
 Resource* r=(Resource*)FUN_00263ea0(32); if(r) r=r->FUN_0028edb0();
 (*(Resource**)&DAT_004dde30)=r; r->init(); (*(Resource**)&DAT_004dde30)->inner->enable(0x444d4c42,1);
 l->release(); (*(unsigned char*)&DAT_004dde2c)=0;
}
if((*(Obj**)&DAT_004dde34)) { DAT_0052c2a8->select(7); FUN_000b9230((*(Obj**)&DAT_004dde34)); }
if(mode==1) FUN_000bd050();
elapsed=FUN_00267f80()-start;
if(elapsed<fade) FUN_000b9470((int)(__int64)(((double)fade-(double)elapsed)/(double)fade*255.0f),(*(Resource**)&DAT_004dde30));
bool fading=false;
if(!(*(unsigned char*)&DAT_004dde2c)) {
 if(mode==0 && elapsed>duration-(*(U*)&DAT_0049fb30)-100) {
 fading=true;
 FUN_000b9470((int)(__int64)((1.0f-((double)duration-((double)elapsed+100.0f))/(double)(*(U*)&DAT_0049fb30))*255.0f),(*(Resource**)&DAT_004dde30));
 }
} else { FUN_000b9470((int)(__int64)((1.0f-(double)((*(U*)&DAT_004dde28)-elapsed)/(double)(*(U*)&DAT_0049fb2c))*255.0f),(*(Resource**)&DAT_004dde30)); }
if(elapsed>threshold && !(*(unsigned char*)&DAT_004dde2c) && !fading) {
 if(FUN_000bdf50(mode==1,0)) { (*(unsigned char*)&DAT_004dde2c)=1; (*(U*)&DAT_004dde28)=(*(U*)&DAT_0049fb2c)+elapsed; }
}
if(((*(unsigned char*)&DAT_004dde2c) && (*(U*)&DAT_004dde28)<elapsed) || (mode==0 && elapsed>duration)) {
 (*(Root**)&DAT_0052c2b4)->screen->finish();
 (*(Resource**)&DAT_004dde30)->inner->set(0x584554,0);
 if((*(Resource**)&DAT_004dde30)){ (*(Resource**)&DAT_004dde30)->release(); (*(Resource**)&DAT_004dde30)=0; }
 if((*(Obj**)&DAT_004dde34)){ (*(Obj**)&DAT_004dde34)->release(); (*(Obj**)&DAT_004dde34)=0; }
 other->FUN_000929a0(id,0); FUN_000c21b0(id); start=0; result=true;
}
 return result;
}
} // namespace fn_000c3900
#undef V
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c4020 FUN_000c4020 (511 B): equivalent/0x000c4020.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260; FUN_000fc3d0]
// sym: ?FUN_000c4020@MissionMenu@fn_000c4020@@QAEXHH@Z @1b4533917c3a @wa4b76275f232
namespace fn_000c4020 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// FUN_000c4020 @ 0x000c4020
// cl-flags: /GS


struct Label_c4020 {
    int f00;
    char f04;
    char pad05[3];
    int f08;
    int f0c;
    char* f10;
    int f14;
    char f18;
    char pad19[3];
    float f1c;
    int f20;
    void FUN_000f8500(const char* text, void* manager, char flag);
};

class TextManager_c4020 {
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
};

class FEObject_c4020 {
  public:
    virtual void v0();
};

class TextSelector_c4020 : public FEObject_c4020 {
  public:
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
    virtual void vfunc_19(Label_c4020* label, int a, int b);
};

class Manager_c4020 {
  public:
    char pad[4];
};

class Ref_c4020 {
  public:
    virtual void v0();
    virtual void v1();
};

struct Handle_c4020 {
    void FUN_00294980(Ref_c4020* r);
};

struct FrontEnd_c4020 {
    void FUN_001c0ab0(const char* name);
};

struct Timer {
    void FUN_002665a0();
};

extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

extern "C" int __cdecl FUN_00266da0(int mode);
TextManager_c4020* __cdecl FUN_000fc3d0();
FEObject_c4020* __cdecl FUN_000fc260(const char* name);
Manager_c4020* __cdecl FUN_000fc1b0();
extern "C" void __cdecl FUN_000fc100(int a, int b);
int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);
int FUN_00345804(const char* str, const char* fmt, ...);

class MissionMenu {
  public:
    char pad0[8];
    char f08;
    char pad09[7];
    int f10;
    char pad14[0xc];
    Handle_c4020* f20;
    Ref_c4020* f24;
    char f28;
    char pad29[0x5c - 0x29];
    FrontEnd_c4020* f5c;
    char pad60[0x26c - 0x60];
    const char* names[0x80];
    char pad46c[0x1880 - 0x46c];
    int f1880;
    void FUN_000befc0(int a, int b, int c);
    void FUN_000b8f20();
    void FUN_000bb600();
    void FUN_000c3ea0();
    void FUN_000c4020(int a, int b);
};

void MissionMenu::FUN_000c4020(int a, int b)
{
    struct Frame {
        int mission;
        int chapter;
        int prev;
        Label_c4020 entry;
        char buf[0x20];
    } fr;
    fr.prev = FUN_00266da0(0xb);
    if (!f28) {
        TextManager_c4020* tm = FUN_000fc3d0();
        if (tm)
            tm->v66();
        if (f5c)
            f5c->FUN_001c0ab0("fe");
        f28 = 1;
        (*(Timer**)&DAT_004dd9cc)->FUN_002665a0();
        FUN_000befc0(DAT_0049f3bc, 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3c8), 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3cc), 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3d4), 0xb, 1);
        FUN_000befc0((*(hulk_intptr*)&DAT_0049f3d0), 0xb, 1);
        f20->FUN_00294980(f24);
        f10 = 3;
        if (!(*(char*)&DAT_0049fb3c) && f08) {
            f10 = 5;
        } else {
            f10 = 7;
            (*(char*)&DAT_0049fb3c) = 0;
        }
        FUN_000fc100((*(hulk_intptr*)&DAT_0049f3ac), 0);
        ((owners::State_f7930 *)&(fr.entry))->FUN_000f7930();
        TextSelector_c4020* sel = (TextSelector_c4020*)FUN_00344e74(FUN_000fc260("mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (sel) {
            for (int i = 0; i < 0x80; i++) {
                if (!names[i])
                    break;
                fr.chapter = -1;
                fr.mission = -1;
                FUN_00345804(names[i], "c%dm%d", &fr.chapter, &fr.mission);
                FUN_000964a0(fr.buf, 0x20, "Chapter %d Mission %d", fr.chapter, fr.mission);
                fr.entry.FUN_000f8500(fr.buf, FUN_000fc1b0(), 0);
                sel->vfunc_19(&fr.entry, 0, 0);
            }
        }
        FUN_000b8f20();
        FUN_000bb600();
        FUN_000c3ea0();
        ((owners::Thing_f7960 *)&(fr.entry))->FUN_000f7960();
    }
    f1880 = 0;
    FUN_00266da0(fr.prev);
}
} // namespace fn_000c4020

namespace fn_f71c7272 {

// 0x000c4220 FUN_000c4220 (348 B): equivalent/0x000c4220.cpp
// sym: ?update@State_c4220@fn_f71c7272@@QAEXPAUPlayer_c4220@2@@Z @e4adf6679b7d @wacbf346f47c1
// STATUS: equivalent (tools/equiv.py level 3: 19408 inputs, branch coverage 19/19)
// FUN_000c4220 @ 0x000c4220
// FUN_000c4220 @ 0x000c4220
void State_c4220::update(Player_c4220* player) {
 struct Buffer { char text[64];  } buffer;
 switch((*(unsigned int*)&DAT_0049fb40)) {
 case 0: {
 const char* prefix="copyright-";
 unsigned int i;
 for(i=0;i<11;++i) buffer.text[i]=prefix[i];
 for(;i<64;++i) buffer.text[i]=0;
 const char* end=suffix;
 while(*end++) {}
 hulk_uintptr count=end-suffix;
 char* dst=buffer.text;
 while(*dst) ++dst;
 const char* src=suffix;
 for(i=0;i<count/4;++i) {
 *(unsigned int*)dst=*(const unsigned int*)src;
 dst+=4; src+=4;
 }
 for(i=0;i<count%4;++i) *dst++=*src++;
 if(FUN_000c3900(buffer.text,5000,5000,0,0,0,0)) ++(*(unsigned int*)&DAT_0049fb40);
 break;
 }
 case 1: player->FUN_001b7310("dolby",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 2: player->FUN_001b7310("marvel",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 3: player->FUN_001b7310("radical",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 4: player->FUN_001b7310("sierra",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 5: player->FUN_001b7310("attract",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 6: finished=1; break;
 }
 if(finished) {
 ((ThisNote_000c3ea0*)(this))->FUN_000c3ea0();
 Screen_c4220* current=screen;
 (*(unsigned int*)&DAT_0049fb40)=0;
 if(current) { current->FUN_001edf60(); screen->FUN_001ec480("main","FE_screen_enter_start"); }
 mode=1;
 }
}

} // namespace fn_f71c7272
