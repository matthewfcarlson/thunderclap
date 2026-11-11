// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001cc5e0..0x001d0360 (kind game, layer game, confidence high), dominant class CScenarioManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3574e0c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3574e0c {} using namespace fn_f3574e0c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3574e0c {
struct Receiver_1ccad0 { void FUN_001d3f00(const char*, const char*); };
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
struct Timer { float remaining; char text[256]; int id; };
struct Owner_1ccad0 {
 char pad[0x110]; Timer timers[16];
 Receiver_1ccad0* FUN_001d4c90();
 void update(float elapsed);
};
struct Overlay_1cccc0 {
    void FUN_000d4620(int one, const char *text, int minusOne, unsigned color, float minusOneF);
};
struct Holder_1cccc0 {
    char pad0[4];
    Overlay_1cccc0 *overlay;
};
struct Checker_1cccc0 {
    int FUN_00086280();
};
struct Parent_1cccc0 {
    char pad0[0x3c];
    Holder_1cccc0 *holder;
    char pad40[0x54 - 0x40];
    Checker_1cccc0 *checker;
};
struct Palette_1cccc0 {
};
} // namespace fn_f3574e0c
struct World {
    char pad0[0x20];
    Palette_1cccc0 *palette;
};
struct Singleton_4dd6ec {
    Singleton_4dd6ec *FUN_00086370();
    void FUN_00090720(const char *name, int flag);
};
namespace fn_f3574e0c {
extern "C" void FUN_00267830(char *dst, const char *src, int n);
struct Frame_1cccc0 {
    union {
        float level;
        unsigned color;
    } slot;
    char text[0x100];
};
class ComboTracker {
public:
    char pad0[4];
    Parent_1cccc0 *parent;
    char pad8[0x11ac - 8];
    int count;
    char pad11b0[4];
    int tierCount;
    float thresholds[16];
    char labels[16][0x20];
    void FUN_001cccc0();
};
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };
class CScenarioManager {
  public:
    virtual void _m_vf0();
};
class MethodBase_1ce990 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1ce990(const char *n, int k) throw();
    void FUN_001d04a0();
};
template <class T, class R, class A>
class Method1 : public MethodBase_1ce990 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1ce990(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};
typedef Closure1<CScenarioManager, void, int> Closure_1ce990;
struct Frame_1ce990 {
    Closure_1ce990 closure;
    Frame_1ce990(const char *n, CScenarioManager *o, Closure_1ce990::Fn f) throw() : closure(n, o, f) {
    }
};
class Registry_1ce990 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1ce990 *m);
    void FUN_001ce990(const char *name, CScenarioManager *owner, Closure_1ce990::Fn f);
};
class __declspec(novtable) MethodBase_1cea20 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cea20(const char* n, int k) throw();
    void FUN_001d04a0();
};
template <class T, class R>
class Method0 : public MethodBase_1cea20 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_1cea20(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e134));
    }
    Fn fn;
};
template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};
struct Frame_1cea20 {
    Closure0<CScenarioManager, int> closure;
    Frame_1cea20(const char* n, CScenarioManager* o, int (CScenarioManager::*f)()) throw() : closure(n, o, f) {
    }
};
struct Registry_1cea20 {
    void FUN_001d26d0(const char*, void*);
    void FUN_001cea20(const char* name, CScenarioManager* owner, int (CScenarioManager::*fn)());
};
struct Closure2_1cefe0 {
    char data[0x24];
    void FUN_001ce7c0(void*, void*, void*);
    void FUN_001d04a0();
};
struct Owner {
    void FUN_001d26d0(void*, Closure2_1cefe0*);
    void FUN_001cefe0(void* a, void* b, void* c);
};
struct Closure2_1cf0c0 {
    char data[36];
    Closure2_1cf0c0(int, int, int);
    void FUN_001d04a0();
};
struct Actor {
    void FUN_001d26d0(int, Closure2_1cf0c0*);
    void FUN_001cf0c0(int a, int b, int c);
};


// 0x001ccad0 FUN_001ccad0 (175 B): matches/0x001ccad0.cpp
// sym: ?update@Owner_1ccad0@fn_f3574e0c@@QAEXM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_001ccad0 @ 0x001ccad0
void Owner_1ccad0::update(float elapsed) {
 Receiver_1ccad0* receiver = FUN_001d4c90();
 if (receiver) {
 char buffer[64];
 for (int i=0;i<16;++i) {
  Timer& timer=timers[i];
  if (!(timer.remaining >= 0.0f)) continue;
  if ((timer.remaining -= elapsed) <= 0.0f) {
   FUN_00267760(buffer,64,"=timer: %.50s",timer.text);
   receiver->FUN_001d3f00(timer.text,buffer);
   timer.remaining=-1.0f;
   timer.text[0]=0;
   timer.id=-1;
  }
 }
 }
}


// 0x001cccc0 FUN_001cccc0 (400 B): equivalent/0x001cccc0.cpp
// sym: ?FUN_001cccc0@ComboTracker@fn_f3574e0c@@QAEXXZ @9f6dfffe81d7 @w7278335113ee
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 34/34)
// FUN_001cccc0 @ 0x001cccc0
void ComboTracker::FUN_001cccc0()
{
    Frame_1cccc0 f;
    if (count > 1 && parent && parent->checker && parent->checker->FUN_00086280()
        && parent->holder) {
        Overlay_1cccc0 *overlay = parent->holder->overlay;
        if (overlay) {
            if (tierCount > 0) {
                f.slot.level = (float)count;
                if (f.slot.level >= thresholds[0]) {
                    int idx = tierCount - 1;
                    for (int i = tierCount - 2; i >= 1; i--) {
                        if (f.slot.level <= thresholds[i])
                            idx = i;
                    }
                    FUN_00267830(f.text, labels[idx], 0x100);
                    unsigned *c = ((unsigned *)((owners::Palette_25930 *)(DAT_004dd700->palette))->FUN_00025930((unsigned int *)(&f.slot.color), 3));
                    overlay->FUN_000d4620(1, f.text, -1, *c, -1.0f);
                }
            }
            DAT_004dd6ec->FUN_00086370()->FUN_00090720("action_combo", 1);
        }
    }
}

} // namespace fn_f3574e0c

// 0x001cd220 FUN_001cd220 (417 B): equivalent/0x001cd220.cpp [wrapped: conflict: Singleton_4dd6ec; World]
// sym: ?FUN_001cd220@Mission_1cd220@fn_001cd220@@QAEXD@Z @f71ef481ab1a @waab6ccf581e5
namespace fn_001cd220 {
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 18/18)
// FUN_001cd220 @ 0x001cd220
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

extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct Msg_1cd220 {
    int w0, w1, w2, w3, w4, w5;
    Msg_1cd220 *FUN_001ca060(int v);
    Msg_1cd220 *FUN_001ca0d0();
};

struct Sink_1cd220 {
    int FUN_001cbc20(Msg_1cd220 *m);
};

struct Loader_1cd220 {
};

struct Visibility {
    void FUN_000d6fb0(char v);
};

struct Child_1cd220 {
    char pad00[0x3c];
    Visibility *vis;
};

struct Singleton_4dd6ec {
    char pad00[0xc];
    Child_1cd220 *child;
};


struct Obj24_1cd220 {
    int FUN_001b9130(int v);
};

struct Obj28_1cd220 {
    int FUN_002088a0();
    int FUN_002089f0();
};

struct Obj54_1cd220 {
};

struct World {
    char pad00[0x54];
    Obj54_1cd220 *f54;
};


extern Loader_1cd220 *__cdecl FUN_001d4c90();

struct Names_1cd220 {
    char *FUN_000897e0();
    char *FUN_000897f0();
    char *FUN_0008a2d0();
};

struct Target4 {
    char pad00[0x30];
    Sink_1cd220 *sink;
};

struct Frame_1cd220 {
    Msg_1cd220 msg;
    char buf[0x80];
};

struct Slot_1cd220 {
    char used;
    char pad[0x1f];
};

class Mission_1cd220 {
public:
    char pad00[4];
    Target4 *f4;
    Names_1cd220 *names;
    int f0c;
    char pad10[0x1190 - 0x10];
    int f1190;
    int f1194;
    int f1198;
    float f119c;
    char b11a0;
    char pad11a1[0x1418 - 0x11a1];
    Slot_1cd220 slots[4];
    int slotVals[4];
    void FUN_001cd220(char flag);
};

void Mission_1cd220::FUN_001cd220(char flag)
{
    Frame_1cd220 f;
    f0c = 0;
    f1198 = 0;
    b11a0 = 0;
    f119c = -1.0f;
    ((owners::C_1ccb80 *)this)->FUN_001ccb80();
    for (int i = 0; i < 4; i++) {
        slots[i].used = 0;
        slotVals[i] = 0;
    }
    Loader_1cd220 *loader = FUN_001d4c90();
    if (loader) {
        Singleton_4dd6ec *h = DAT_004dd6ec;
        if (h && h->child && h->child->vis)
            h->child->vis->FUN_000d6fb0(0);
        ((Obj24_1cd220 *)((owners::Obj_86290 *)(DAT_004dd700->f54))->FUN_00086290())->FUN_001b9130(0);
        if (flag) {
            char *a = names->FUN_000897f0();
            char *b = names->FUN_000897e0();
            FUN_00267760(f.buf, 0x80, "art/locations/%s/%s.lua", b, a);
            ((owners::Object_1d3600 *)loader)->FUN_001d3600((const char *)(f.buf), 0);
            char *c = names->FUN_0008a2d0();
            char *d = names->FUN_0008a2d0();
            FUN_00267760(f.buf, 0x80, "art/missions/%s/%s.lua", d, c);
            ((owners::Object_1d3600 *)loader)->FUN_001d3600((const char *)(f.buf), 0);
        }
        ((Obj28_1cd220 *)((owners::Target_862a0 *)(DAT_004dd700->f54))->FUN_000862a0())->FUN_002088a0();
        ((Obj28_1cd220 *)((owners::Target_862a0 *)(DAT_004dd700->f54))->FUN_000862a0())->FUN_002089f0();
        if (f4) {
            Sink_1cd220 *sink = f4->sink;
            if (sink) {
                if (flag) {
                    f.msg.FUN_001ca0d0();
                } else {
                    f.msg.FUN_001ca060(f1194);
                }
                sink->FUN_001cbc20(&f.msg);
            }
        }
    }
}
} // namespace fn_001cd220
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cd410 FUN_001cd410 (340 B): matches/0x001cd410.cpp [wrapped: conflict: FUN_001d4c90]
// sym: ?FUN_001cd410@Controller_1cd410@fn_001cd410@@QAEXXZ
namespace fn_001cd410 {
// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 24/24)
// FUN_001cd410 @ 0x001cd410
// cl-flags: /GS
extern "C++" __declspec(nothrow) int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct Node { void FUN_001dcac0(); };
struct Part28 { void FUN_001fc7c0(); };
struct Part20 { void FUN_0002b3d0(); };
struct Part3cInner { void FUN_000ce850(); };
struct Part3c { char pad[8]; Part3cInner *inner; };
struct Part38 { void FUN_001f6cb0(); };
struct Part14 { void FUN_001b69c0(); };
struct Part48 { void FUN_001faf70(char *buf); };
struct Part30_1cd410 { void FUN_001cc230(); };
struct Part44 { void FUN_00059db0(); };
struct Target_1cd410 {
    char pad[0x32];
    char flag32;
    void FUN_001b9160(int v);
};
struct Part54_1cd410 {  };
struct Session_1cd410;
struct Holder_1cd410 { void FUN_0009bc60(Session_1cd410 *s); };
struct Session_1cd410 {
    char pad0[8];
    Holder_1cd410 *holder;
    Node *p0c;
    char pad10[4];
    Part14 *p14;
    char pad18[8];
    Part20 *p20;
    char pad24[4];
    Part28 *p28;
    char pad2c[4];
    Part30_1cd410 *p30;
    char pad34[4];
    Part38 *p38;
    Part3c *p3c;
    char pad40[4];
    Part44 *p44;
    Part48 *p48;
    char pad4c[8];
    Part54_1cd410 *p54;
};
struct Names_1cd410 { const char *FUN_0008a2d0(); };
struct Singleton_1cd410 {  };
extern Singleton_1cd410 *FUN_001d4c90();

struct Controller_1cd410 {
    char pad0[4];
    Session_1cd410 *session;
    Names_1cd410 *names;
    char pad0c[0x14a9 - 0xc];
    char busy;
    void FUN_001cd220(int a);
    void FUN_001cd410();
};

struct Frame_1cd410 {
    char buf[0x100];
};

void Controller_1cd410::FUN_001cd410() {
    Frame_1cd410 f;
    char *buf = f.buf;
    busy = 1;
    if (session != 0) {
        if (session->p0c != 0)
            session->p0c->FUN_001dcac0();
        if (session->p28 != 0)
            session->p28->FUN_001fc7c0();
        if (session->p20 != 0)
            session->p20->FUN_0002b3d0();
        if (session->p3c->inner != 0)
            session->p3c->inner->FUN_000ce850();
        if (session->p38 != 0)
            session->p38->FUN_001f6cb0();
        if (session->p14 != 0)
            session->p14->FUN_001b69c0();
        FUN_00267760(buf, 0xff, "art/missions/%s/%s.dh", names->FUN_0008a2d0(), names->FUN_0008a2d0());
        session->p48->FUN_001faf70(buf);
        session->p30->FUN_001cc230();
        session->p44->FUN_00059db0();
    }
    if (session->p54 != 0 && ((Target_1cd410 *)((owners::Obj_86290 *)(session->p54))->FUN_00086290()) != 0) {
        ((Target_1cd410 *)((owners::Obj_86290 *)(session->p54))->FUN_00086290())->FUN_001b9160(0);
        ((Target_1cd410 *)((owners::Obj_86290 *)(session->p54))->FUN_00086290())->flag32 = 0;
    }
    Singleton_1cd410 *s = FUN_001d4c90();
    if (s != 0) {
        FUN_001cd220(0);
        ((owners::Obj_1d40b0 *)s)->FUN_001d40b0();
    }
    if (session != 0 && session->holder != 0)
        session->holder->FUN_0009bc60(session);
    busy = 0;
}
} // namespace fn_001cd410

namespace fn_f3574e0c {

// 0x001ce990 FUN_001ce990 (134 B): matches/0x001ce990.cpp
// sym: ?FUN_001ce990@Registry_1ce990@fn_f3574e0c@@QAEXPBDPAVCScenarioManager@2@P832@AEXH@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ce990 @ 0x001ce990
void Registry_1ce990::FUN_001ce990(const char *name, CScenarioManager *owner, Closure_1ce990::Fn f) {
    Frame_1ce990 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}


// 0x001cea20 FUN_001cea20 (120 B): matches/0x001cea20.cpp
// sym: ?FUN_001cea20@Registry_1cea20@fn_f3574e0c@@QAEXPBDPAVCScenarioManager@2@P832@AEHXZ@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cea20 @ 0x001cea20
void Registry_1cea20::FUN_001cea20(const char* name, CScenarioManager* owner, int (CScenarioManager::*fn)()) {
    Frame_1cea20 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}

} // namespace fn_f3574e0c

// 0x001ceaa0 FUN_001ceaa0 (120 B): matches/0x001ceaa0.cpp [wrapped: conflict: Method0]
// sym: ?FUN_001ceaa0@Registry_1ceaa0@fn_001ceaa0@@QAEXPBDPAVCScenarioManager@2@P832@AEMXZ@Z
namespace fn_001ceaa0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ceaa0 @ 0x001ceaa0
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


class CScenarioManager { public: float FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1ceaa0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1ceaa0(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_1ceaa0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_1ceaa0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_1ceaa0 {
    Closure0<CScenarioManager, float> closure;
    Frame_1ceaa0(const char* n, CScenarioManager* o, float (CScenarioManager::*f)()) throw() : closure(n, o, f) {
    }
};

struct Registry_1ceaa0 {
    void FUN_001d26d0(const char*, void*);
    void FUN_001ceaa0(const char* name, CScenarioManager* owner, float (CScenarioManager::*fn)());
};

void Registry_1ceaa0::FUN_001ceaa0(const char* name, CScenarioManager* owner, float (CScenarioManager::*fn)()) {
    Frame_1ceaa0 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001ceaa0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ceb20 FUN_001ceb20 (134 B): matches/0x001ceb20.cpp [wrapped: conflict: Method1]
// sym: ?FUN_001ceb20@Registry_1ceb20@fn_001ceb20@@QAEXPBDPAVCScenarioManager@2@P832@AEXM@Z@Z
namespace fn_001ceb20 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ceb20 @ 0x001ceb20
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

class CScenarioManager {
public:
    virtual void vfn0();
};

// Function's fields (include/decls/data/script.h) after the vftable.
class MethodBase_1ceb20 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1ceb20(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1ceb20 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1ceb20(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, void, float> Closure_1ceb20;

struct Frame_1ceb20 {
    Closure_1ceb20 closure;
    Frame_1ceb20(const char *n, CScenarioManager *o, Closure_1ceb20::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_1ceb20 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1ceb20 *m);
    void FUN_001ceb20(const char *name, CScenarioManager *owner, Closure_1ceb20::Fn f);
};

void Registry_1ceb20::FUN_001ceb20(const char *name, CScenarioManager *owner, Closure_1ceb20::Fn f) {
    Frame_1ceb20 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001ceb20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cebb0 FUN_001cebb0 (134 B): matches/0x001cebb0.cpp [wrapped: conflict: Method1]
// sym: ?FUN_001cebb0@Registry_1cebb0@fn_001cebb0@@QAEXPBDPAVCScenarioManager@2@P832@AEX_N@Z@Z
namespace fn_001cebb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cebb0 @ 0x001cebb0
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

class CScenarioManager {
public:
    virtual void vfn0();
};

// Function's fields (include/decls/data/script.h) after the vftable.
class MethodBase_1cebb0 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1cebb0(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cebb0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1cebb0(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, void, bool> Closure_1cebb0;

struct Frame_1cebb0 {
    Closure_1cebb0 closure;
    Frame_1cebb0(const char *n, CScenarioManager *o, Closure_1cebb0::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_1cebb0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1cebb0 *m);
    void FUN_001cebb0(const char *name, CScenarioManager *owner, Closure_1cebb0::Fn f);
};

void Registry_1cebb0::FUN_001cebb0(const char *name, CScenarioManager *owner, Closure_1cebb0::Fn f) {
    Frame_1cebb0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001cebb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cec40 FUN_001cec40 (120 B): matches/0x001cec40.cpp [wrapped: conflict: Method0]
// sym: ?FUN_001cec40@Registry_1cec40@fn_001cec40@@QAEXPBDPAVCScenarioManager@2@P832@AE_NXZ@Z
namespace fn_001cec40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cec40 @ 0x001cec40
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


class CScenarioManager { public: bool FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cec40 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cec40(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_1cec40 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_1cec40(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_1cec40 {
    Closure0<CScenarioManager, bool> closure;
    Frame_1cec40(const char* n, CScenarioManager* o, bool (CScenarioManager::*f)()) throw() : closure(n, o, f) {
    }
};

struct Registry_1cec40 {
    void FUN_001d26d0(const char*, void*);
    void FUN_001cec40(const char* name, CScenarioManager* owner, bool (CScenarioManager::*fn)());
};

void Registry_1cec40::FUN_001cec40(const char* name, CScenarioManager* owner, bool (CScenarioManager::*fn)()) {
    Frame_1cec40 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001cec40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cecc0 FUN_001cecc0 (134 B): matches/0x001cecc0.cpp [wrapped: conflict: Method1]
// sym: ?FUN_001cecc0@Registry_1cecc0@fn_001cecc0@@QAEXPBDPAVCScenarioManager@2@P832@AEMH@Z@Z
namespace fn_001cecc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cecc0 @ 0x001cecc0
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

class CScenarioManager {
public:
    virtual void vfn0();
};

// Function's fields (include/decls/data/script.h) after the vftable.
class MethodBase_1cecc0 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1cecc0(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cecc0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1cecc0(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, float, int> Closure_1cecc0;

struct Frame_1cecc0 {
    Closure_1cecc0 closure;
    Frame_1cecc0(const char *n, CScenarioManager *o, Closure_1cecc0::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_1cecc0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1cecc0 *m);
    void FUN_001cecc0(const char *name, CScenarioManager *owner, Closure_1cecc0::Fn f);
};

void Registry_1cecc0::FUN_001cecc0(const char *name, CScenarioManager *owner, Closure_1cecc0::Fn f) {
    Frame_1cecc0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001cecc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cee40 FUN_001cee40 (120 B): matches/0x001cee40.cpp [wrapped: conflict: Method0]
// sym: ?FUN_001cee40@Registry_1cee40@fn_001cee40@@QAEXPBDPAVCScenarioManager@2@P832@AEXXZ@Z
namespace fn_001cee40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cee40 @ 0x001cee40
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


class CScenarioManager { public: void FUN_dummy(); };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cee40 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_1cee40(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_1cee40 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_1cee40(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_1cee40 {
    Closure0<CScenarioManager, void> closure;
    Frame_1cee40(const char* n, CScenarioManager* o, void (CScenarioManager::*f)()) throw() : closure(n, o, f) {
    }
};

struct Registry_1cee40 {
    void FUN_001d26d0(const char*, void*);
    void FUN_001cee40(const char* name, CScenarioManager* owner, void (CScenarioManager::*fn)());
};

void Registry_1cee40::FUN_001cee40(const char* name, CScenarioManager* owner, void (CScenarioManager::*fn)()) {
    Frame_1cee40 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001cee40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ceec0 FUN_001ceec0 (134 B): matches/0x001ceec0.cpp [wrapped: conflict: Method1]
// sym: ?FUN_001ceec0@Registry_1ceec0@fn_001ceec0@@QAEXPBDPAVCScenarioManager@2@P832@AEX0@Z@Z
namespace fn_001ceec0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ceec0 @ 0x001ceec0
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

class CScenarioManager {
public:
    virtual void vfn0();
};

// Function's fields (include/decls/data/script.h) after the vftable.
class MethodBase_1ceec0 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1ceec0(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1ceec0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1ceec0(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, void, const char *> Closure_1ceec0;

struct Frame_1ceec0 {
    Closure_1ceec0 closure;
    Frame_1ceec0(const char *n, CScenarioManager *o, Closure_1ceec0::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_1ceec0 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1ceec0 *m);
    void FUN_001ceec0(const char *name, CScenarioManager *owner, Closure_1ceec0::Fn f);
};

void Registry_1ceec0::FUN_001ceec0(const char *name, CScenarioManager *owner, Closure_1ceec0::Fn f) {
    Frame_1ceec0 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001ceec0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001cef50 FUN_001cef50 (134 B): matches/0x001cef50.cpp [wrapped: conflict: Method1]
// sym: ?FUN_001cef50@Registry_1cef50@fn_001cef50@@QAEXPBDPAVCScenarioManager@2@P832@AEPBDH@Z@Z
namespace fn_001cef50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cef50 @ 0x001cef50
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

class CScenarioManager {
public:
    virtual void vfn0();
};

// Function's fields (include/decls/data/script.h) after the vftable.
class MethodBase_1cef50 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1cef50(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cef50 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1cef50(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, const char *, int> Closure_1cef50;

struct Frame_1cef50 {
    Closure_1cef50 closure;
    Frame_1cef50(const char *n, CScenarioManager *o, Closure_1cef50::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_1cef50 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1cef50 *m);
    void FUN_001cef50(const char *name, CScenarioManager *owner, Closure_1cef50::Fn f);
};

void Registry_1cef50::FUN_001cef50(const char *name, CScenarioManager *owner, Closure_1cef50::Fn f) {
    Frame_1cef50 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001cef50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3574e0c {

// 0x001cefe0 FUN_001cefe0 (79 B): matches/0x001cefe0.cpp
// sym: ?FUN_001cefe0@Owner@fn_f3574e0c@@QAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cefe0 @ 0x001cefe0
void Owner::FUN_001cefe0(void* a, void* b, void* c) {
    Closure2_1cefe0 temp;
    temp.FUN_001ce7c0(a,b,c);
    FUN_001d26d0(a,&temp);
    temp.FUN_001d04a0();
}

} // namespace fn_f3574e0c

// 0x001cf030 FUN_001cf030 (134 B): matches/0x001cf030.cpp [wrapped: conflict: Method1]
// sym: ?FUN_001cf030@Registry_1cf030@fn_001cf030@@QAEXPBDPAVCScenarioManager@2@P832@AE?AW4eMissionObjectiveState@2@H@Z@Z
namespace fn_001cf030 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cf030 @ 0x001cf030
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


enum eMissionObjectiveState { MOS_Dummy };
template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<eMissionObjectiveState> { static const void *get() { return &DAT_004c55f0; } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };

class CScenarioManager {
public:
    virtual void vfn0();
};

// Function's fields (include/decls/data/script.h) after the vftable.
class MethodBase_1cf030 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1cf030(const char *n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cf030 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) throw() : MethodBase_1cf030(name, 1) {
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
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    virtual void m0();
    T *owner;
};

typedef Closure1<CScenarioManager, eMissionObjectiveState, int> Closure_1cf030;

struct Frame_1cf030 {
    Closure_1cf030 closure;
    Frame_1cf030(const char *n, CScenarioManager *o, Closure_1cf030::Fn f) throw() : closure(n, o, f) {
    }
};

class Registry_1cf030 {
public:
    void FUN_001d26d0(const char *name, MethodBase_1cf030 *m);
    void FUN_001cf030(const char *name, CScenarioManager *owner, Closure_1cf030::Fn f);
};

void Registry_1cf030::FUN_001cf030(const char *name, CScenarioManager *owner, Closure_1cf030::Fn f) {
    Frame_1cf030 fr(name, owner, f);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
} // namespace fn_001cf030
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3574e0c {

// 0x001cf0c0 FUN_001cf0c0 (79 B): matches/0x001cf0c0.cpp
// sym: ?FUN_001cf0c0@Actor@fn_f3574e0c@@QAEXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cf0c0 @ 0x001cf0c0
void Actor::FUN_001cf0c0(int a, int b, int c)
{
    Closure2_1cf0c0 value(a, b, c);
    FUN_001d26d0(a, &value);
    value.FUN_001d04a0();
}

} // namespace fn_f3574e0c

// 0x001cf690 FUN_001cf690 (1154 B): equivalent/0x001cf690.cpp [wrapped: conflict: FUN_001d4c90]
// sym: ?FUN_001cf690@CScenarioManager@fn_001cf690@@QAEXXZ @4fd73f524ff2 @w6cbb96b7d848
inline void *operator new(hulk_uintptr, void *p) throw() { return p; }
namespace fn_001cf690 {
// STATUS: equivalent (tools/equiv.py level 3: 7663 inputs, branch coverage 2/2)
// FUN_001cf690 @ 0x001cf690
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



template <class T> struct Tid;
template <> struct Tid<void> { static const char *p() { return ((const char*)&DAT_0048e100); } };
template <> struct Tid<int> { static const char *p() { return ((const char*)&DAT_0048e134); } };
template <> struct Tid<float> { static const char *p() { return ((const char*)&DAT_0048e128); } };
template <> struct Tid<const char *> { static const char *p() { return ((const char*)&DAT_0048e0f0); } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) MethodBase_1cf690 : public ScriptFunctionFields {
public:
    virtual void m0();
    MethodBase_1cf690(const char *n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char *, int);
    void FUN_001d04a0();
};

template <class T, class R, class A, class B>
class Method2 : public MethodBase_1cf690 {
public:
    typedef R (T::*Fn)(A, B);
    Method2(const char *name, Fn f) : MethodBase_1cf690(name, 2) {
        fn = f;
        this->retType = FUN_001d04d0(Tid<R>::p());
        this->argTypes[0] = FUN_001d04d0(Tid<A>::p());
        this->argTypes[1] = FUN_001d04d0(Tid<B>::p());
    }
    Fn fn;
};

template <class T, class R, class A, class B>
class Closure2 : public Method2<T, R, A, B> {
public:
    Closure2(const char *name, T *o, typename Method2<T, R, A, B>::Fn f) : Method2<T, R, A, B>(name, f), owner(o) {}
    T *owner;
};

class CScenarioManager {
public:
    CScenarioManager() {}
    virtual void* v0_001d0340(char);
    char pad04[0x1c];
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
    int FUN_001ccfa0(int);
    void FUN_001ccfc0(int, int);
    void FUN_001ccfe0(bool);
    bool FUN_001ccff0();
    void FUN_001cd5b0(float);
    void FUN_001cf690();
};

struct Registry_1cf690 {
    void FUN_001ce990(const char *, CScenarioManager *, void (CScenarioManager::*)(int));
    void FUN_001cea20(const char *, CScenarioManager *, int (CScenarioManager::*)());
    void FUN_001ceaa0(const char *, CScenarioManager *, float (CScenarioManager::*)());
    void FUN_001ceb20(const char *, CScenarioManager *, void (CScenarioManager::*)(float));
    void FUN_001cebb0(const char *, CScenarioManager *, void (CScenarioManager::*)(bool));
    void FUN_001cec40(const char *, CScenarioManager *, bool (CScenarioManager::*)());
    void FUN_001cecc0(const char *, CScenarioManager *, float (CScenarioManager::*)(int));
    void FUN_001cee40(const char *, CScenarioManager *, void (CScenarioManager::*)());
    void FUN_001ceec0(const char *, CScenarioManager *, void (CScenarioManager::*)(const char *));
    void FUN_001cef50(const char *, CScenarioManager *, const char * (CScenarioManager::*)(int));
    void FUN_001cf030(const char *, CScenarioManager *, int (CScenarioManager::*)(int));
    void FUN_001d26d0(const char *, MethodBase_1cf690 *);
};

Registry_1cf690 *FUN_001d4c90();

void CScenarioManager::FUN_001cf690()
{
    new (this) CScenarioManager;
    FUN_001cced0();
    Registry_1cf690 *reg = FUN_001d4c90();
    if (reg) {
        reg->FUN_001ce990("sm_SetMissionState", this, &CScenarioManager::FUN_001cc620);
        reg->FUN_001cea20("sm_GetMissionState", this, &CScenarioManager::FUN_001cc840);
        reg->FUN_001ceaa0("sm_GetTimeElapsed", this, &CScenarioManager::FUN_001cc860);
        reg->FUN_001ceb20("sm_SetTimeElapsed", this, &CScenarioManager::FUN_001cc870);
        reg->FUN_001ceaa0("sm_GetTime", this, &CScenarioManager::FUN_001cc8a0);
        reg->FUN_001ceaa0("sm_GetScenarioEndTime", this, &CScenarioManager::FUN_001cc880);
        reg->FUN_001ceb20("sm_SetScenarioEndTime", this, &CScenarioManager::FUN_001cc890);
        reg->FUN_001cebb0("sm_FreezeTime", this, &CScenarioManager::FUN_001cc8e0);
        reg->FUN_001cec40("sm_IsTimeFrozen", this, &CScenarioManager::FUN_001cc8f0);
        reg->FUN_001cea20("sm_GetCheckpoint", this, &CScenarioManager::FUN_001cc900);
        reg->FUN_001ce990("sm_SetCheckpoint", this, &CScenarioManager::FUN_001cc910);
        reg->FUN_001cecc0("sm_GetVar", this, &CScenarioManager::FUN_001cc990);
        {
            Closure2<CScenarioManager, void, int, float> c("sm_SetVar", this, &CScenarioManager::FUN_001cc9b0);
            reg->FUN_001d26d0("sm_SetVar", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cea20("sm_GetMaxVarCount", this, &CScenarioManager::FUN_001cc5e0);
        {
            Closure2<CScenarioManager, int, float, const char *> c("sm_StartTimer", this, &CScenarioManager::FUN_001cc9d0);
            reg->FUN_001d26d0("sm_StartTimer", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001ce990("sm_CancelTimer", this, &CScenarioManager::FUN_001cca80);
        reg->FUN_001ceaa0("sm_GetComboTimerLimit", this, &CScenarioManager::FUN_001ccc00);
        reg->FUN_001ceaa0("sm_GetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc20);
        reg->FUN_001cea20("sm_GetComboHitCount", this, &CScenarioManager::FUN_001ccc80);
        reg->FUN_001ceaa0("sm_GetComboScore", this, &CScenarioManager::FUN_001ccca0);
        reg->FUN_001ceb20("sm_SetComboTimerLimit", this, &CScenarioManager::FUN_001ccc10);
        reg->FUN_001ceb20("sm_SetComboTimerCurrent", this, &CScenarioManager::FUN_001ccc30);
        reg->FUN_001ce990("sm_SetComboHitCount", this, &CScenarioManager::FUN_001ccc90);
        reg->FUN_001ceb20("sm_SetComboScore", this, &CScenarioManager::FUN_001cccb0);
        reg->FUN_001ceb20("sm_Combo", this, &CScenarioManager::FUN_001cd5b0);
        {
            Closure2<CScenarioManager, void, float, const char *> c("sm_AddComboGrade", this, &CScenarioManager::FUN_001cce80);
            reg->FUN_001d26d0("sm_AddComboGrade", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cee40("sm_ResetComboSystem", this, &CScenarioManager::FUN_001cced0);
        reg->FUN_001ceec0("sm_SetComboHitText", this, &CScenarioManager::FUN_001cce60);
        reg->FUN_001cef50("sm_GetMissionObjective", this, &CScenarioManager::FUN_001ccf50);
        {
            Closure2<CScenarioManager, void, int, const char *> c("sm_SetMissionObjective", this, &CScenarioManager::FUN_001ccf70);
            reg->FUN_001d26d0("sm_SetMissionObjective", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cf030("sm_GetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfa0);
        {
            Closure2<CScenarioManager, void, int, int> c("sm_SetMissionObjectiveState", this, &CScenarioManager::FUN_001ccfc0);
            reg->FUN_001d26d0("sm_SetMissionObjectiveState", &c);
            c.FUN_001d04a0();
        }
        reg->FUN_001cebb0("sm_SetTutorialMode", this, &CScenarioManager::FUN_001ccfe0);
        reg->FUN_001cec40("sm_GetTutorialMode", this, &CScenarioManager::FUN_001ccff0);
    }
}
} // namespace fn_001cf690
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

