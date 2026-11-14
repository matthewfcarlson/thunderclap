// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d7af0..0x000dc230 (kind game, layer game, confidence high), dominant class FEMemCardControl
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f70d8f3f {
#define TREE_TU_END }
namespace fn_f70d8f3f {} using namespace fn_f70d8f3f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f70d8f3f {
class Target;
typedef void (Target::*Fn1_d7c80)(int);
typedef void (Target::*Fn2_d7c80)(int, int);
class Closure_d7c80 {
public:
    Target *object;
    Fn1_d7c80 fn1;
    Fn2_d7c80 fn2;
    int arg1;
    int arg2;
    void Invoke();
};
struct Entry {
    int a, b, c, d;
    Entry() : a(0), b(0), c(0), d(-1) {}
};
class Obj {
    char pad[8];
    Entry x, y;

  public:
    void reset();
};
class Thing_d7d40 {
    char pad[0x30];

  public:
    char a;
    char pad2[7];
    char b;
    Thing_d7d40* Init();
};
struct Sub_d7d60 {
};
struct Obj_d7d60 {
    char pad[0x10];
    Sub_d7d60 sub;
    char pad2[0x23];
    unsigned char flag;
    Obj_d7d60* Run();
};
struct Y_d7ec0 {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
};
struct FEMemCardControl_d7ec0 {
    char p[0x21c];
    int field;
    char q[0x190];
    unsigned char flag;
    Y_d7ec0* getY_000fc3d0();
    void target(int);
};
class Thing_d7ef0 {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
};
Thing_d7ef0* __cdecl GetThing_000fc3d0();
class Control_d7ef0 {
  public:
};
class FEMemCardControl_d7ef0 {
  public:
    char pad0[0x150];
    Control_d7ef0* mControl;
    char pad1[0x21c - 0x154];
    int mState;
    char pad2[0x3b0 - 0x220];
    unsigned char mFlag;
    void Run(int);
};
extern "C" void* __cdecl FUN_000fc3d0();
struct Root_d7f30 {
    char pad[0x2218];
    void* obj;
};
struct Obj_d7f30 {
    char pad[0x9a8];
    unsigned char value;
};
class FEMemCardControl_d7f60 {
  public:
    char pad0[0x1d4];
    int result;
    char pad1[0x78];
    char slots[5][0x3c];
    char pad2[0x2c];
    char flag;
    void update();
};
struct Source {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual int Get();
};
extern Source* __cdecl fetch_000fc3d0();
struct Item {
    int value;
    char rest[0x34];
    void action_000f8500(int, int, int);
};
class Owner {
    char pad[0x35c];
    Item items[1];

  public:
    void Run(int index, int unused);
};
struct Obj_d8150 {
    char pad[0x258];
};
class B_d8170 {
  public:
    hulk_intptr Fnf_000b5000();
};
class C_d8170 {
  public:
    int Fng_000890a0(int, int);
};
class FEMemCardControl_d8170 {
  public:
    char pad[0x150];
    B_d8170* member;
    int target(int a, int b);
};
extern int hulk_at_004dd6ec;
struct R_d8190 {
    int finish_0008b560(int, int, int);
};
struct A_d8190 {
    R_d8190* call_000b5000();
};
struct FEMemCardControl_d8190 {
    char pad[0x150];
    A_d8190* ptr;
    int target(int, int);
};
class Chain_d81c0 {
  public:
    void FnB_0008ca30(int);
    int FnC_000892c0(int, int);
    void FnD_0008c870(int);
};
class Manager_d81c0 {
  public:
    Chain_d81c0* Get_000b5000();
};
class Obj_d81c0 {
  public:
    char pad[0x150];
    Manager_d81c0* m;
};
class B_d8220 {
  public:
    void F1_0008ca30(int);
    int F2_0008c810(int);
    void F3_0008c870(int);
};
class A_d8220 {
  public:
};
class M_d8220 {
  public:
    A_d8220* Get_000b5000();
};
class FEMemCardControl_d8220 {
  public:
    int Run(int x);
    char pad[0x150];
    M_d8220* m;
};
struct Query_d88f0 {
    int FUN_000890a0(int key, int index);
};
struct Table_d88f0 {
};
struct Source_d88f0 {
    Table_d88f0 *FUN_000b5000();
};
struct Row_d88f0 {
    char flag;
    char pad[0x3b];
};
extern "C" unsigned int __cdecl FUN_0008c580();
class FEMemCardControl_d88f0 {
public:
    char pad0[0x150];
    Source_d88f0 *source;     // 0x150
    char pad154[0x258 - 0x154];
    Row_d88f0 rows[1];        // 0x258
    void FUN_000d88f0(int key, char *foundNone, char *foundOther);
};
struct Mgr_d9080 {
    char pad[0x1bc8];
    char flag;
};
struct Mgr2_d9080 {
    Mgr_d9080* Get();
};
extern Mgr2_d9080* g_mgr_d9080;
struct Menu_d9080 {
    void Show_000be230(const char* a, const char* b, const char* f1, const char* f2, const char* ok, int n,
              const char* f3, const char* f4);
};
struct FEMemCardControl_d9080 {
    char pad[0x21c];
    int v21c;
    char pad2[0x3b0 - 0x220];
    char f3b0;
    char pad3[0x3eb - 0x3b1];
    char f3eb;
    Menu_d9080* GetMenu_000fc3d0();
    void Run(int a, int b);
};
struct Mgr_d9100 {
    char pad[0x1bc8];
    char flag;
};
struct Mgr2_d9100 {
    Mgr_d9100* Get();
};
extern Mgr2_d9100* g_mgr_d9100;
struct Menu_d9100 {
    void Show_000be230(const char* a, const char* b, const char* f1, const char* f2, const char* ok, int n,
              const char* f3, const char* f4);
};
struct FEMemCardControl_d9100 {
    char pad[0x21c];
    int v21c;
    char pad2[0x3b0 - 0x220];
    char f3b0;
    char pad3[0x3eb - 0x3b1];
    char f3eb;
    Menu_d9100* GetMenu_000fc3d0();
    void Run(int a, int b);
};
class Obj_d9e40 {
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
};
extern Obj_d9e40* __cdecl getObj_000fc3d0();
class FEMemCardControl_d9e40 {
  public:
    char pad0[0x1d0];
    int value;
    char pad1[0x48];
    int zero;
    char pad2[0x190];
    unsigned char flag;
    void helper_000d8990(int);
    void run(int);
};

} // namespace fn_f70d8f3f

// 0x000d7af0 FUN_000d7af0 (108 B): equivalent/0x000d7af0.cpp [wrapped: conflict: FEBackground; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ??0FEBackground@fn_000d7af0@@QAE@HPBD@Z @9f5af12b49fd @w765acbe3f457
inline void *operator new(size_t, void *p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000d7af0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000d7af0 @ 0x000d7af0
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



namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p);
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}
namespace pure3d { class DrawableHierarchy; }

struct Node {
    virtual void AddRef();
};

struct Loader_d7af0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node *v3(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster, unsigned __int64 key);
};

struct FUN_000e9240 {
    virtual void slot0();
    char pad04[0x13c];
    FUN_000e9240(int arg);
};

class FEBackground : public FUN_000e9240 {
public:
    virtual void slot0();
    char pad140;
    char flag141;
    char pad142[0xe];
    Node *drawable;
    FEBackground(int arg, const char *name);
};

FEBackground::FEBackground(int arg, const char *name) : FUN_000e9240(arg)
{
    drawable = 0;
    Loader_d7af0 *loader = (*(Loader_d7af0**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster =
        new (&arg) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
    drawable = loader->v3(caster, FUN_002672f0(name, 0, 0));
    if (drawable)
        drawable->AddRef();
    flag141 = 0;
}
} // namespace fn_000d7af0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000d7be0 FUN_000d7be0 (69 B): equivalent/0x000d7be0.cpp
// sym: ?FUN_000d7be0@Object_d7be0@owners@@QAEXIIIII@Z @e7df448dc865 @w4d8e17a10550
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d7be0 @ 0x000d7be0
void owners::Object_d7be0::FUN_000d7be0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    first = a;
    second = b;
    third = c;
    fourth = d;
    zero1 = 0;
    zero2 = 0;
    zero3 = 0;
    sentinel = 0xffffffff;
    last = e;
}


// 0x000d7c30 FUN_000d7c30 (76 B): equivalent/0x000d7c30.cpp
// sym: ?FUN_000d7c30@Object_d7c30@owners@@QAEXIIIIII@Z @8210e84f8304 @w19bf81db9586
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d7c30 @ 0x000d7c30
void owners::Object_d7c30::FUN_000d7c30(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    state0 = 0;
    state1 = 0;
    value0 = a;
    value1 = b;
    state2 = 0;
    value2 = c;
    state3 = 0xffffffff;
    value3 = d;
    value4 = e;
    value5 = f;
}

namespace fn_f70d8f3f {

// 0x000d7c80 FUN_000d7c80 (133 B): matches/0x000d7c80.cpp
// sym: ?Invoke@Closure_d7c80@fn_f70d8f3f@@QAEXXZ
// FUN_000d7c80 @ 0x000d7c80
void Closure_d7c80::Invoke()
{
    if (fn1) {
        (object->*fn1)(arg1);
    } else if (fn2) {
        (object->*fn2)(arg1, arg2);
    }
}


// 0x000d7d10 FUN_000d7d10 (47 B): matches/0x000d7d10.cpp
// sym: ?reset@Obj@fn_f70d8f3f@@QAEXXZ
void Obj::reset() {
    x = Entry();
    y = Entry();
}


// 0x000d7d40 FUN_000d7d40 (20 B): matches/0x000d7d40.cpp
// sym: ?Init@Thing_d7d40@fn_f70d8f3f@@QAEPAV12@XZ
Thing_d7d40* Thing_d7d40::Init() {
    ((owners::State_f7930 *)this)->FUN_000f7930();
    a = 0;
    b = 0;
    return this;
}


// 0x000d7d60 FUN_000d7d60 (19 B): matches/0x000d7d60.cpp
// sym: ?Run@Obj_d7d60@fn_f70d8f3f@@QAEPAU12@XZ
Obj_d7d60* Obj_d7d60::Run() {
    ((owners::State_f7930 *)&sub)->FUN_000f7930();
    flag = 0;
    return this;
}

} // namespace fn_f70d8f3f

// 0x000d7db0 FUN_000d7db0 (109 B): equivalent/0x000d7db0.cpp [wrapped: conflict: FEControl; FEMemCardControl]
// sym: ??1FEMemCardControl@fn_000d7db0@@UAE@XZ @e93437c46f7b @w8ed1c24609a7
namespace fn_000d7db0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d7db0 @ 0x000d7db0
// equiv-map: ??1FEControl@@UAE@XZ = 0x000e92b0
// equiv-map: ??1StringPair@@QAE@XZ = 0x000f7960
class RefCounted_d7db0 {
public:
    virtual void v0();
    virtual void Release();
};

struct StringPair {
    char data[0x14];
    ~StringPair();
};

// Five 0x3c-byte cells, each starting with a StringPair, destroyed last-to-first.
struct CellRow {
    char cell[5][0x3c];
    ~CellRow() {
        for (int i = 4; i >= 0; i--)
            ((StringPair *)cell[i])->~StringPair();
    }
};

class FEControl {
public:
    virtual ~FEControl();
    char pad04[0x1cc - 4];
};

class FEMemCardControl : public FEControl {
public:
    virtual ~FEMemCardControl();
    RefCounted_d7db0 *handle;
    char pad1d0[0x220 - 0x1d0];
    CellRow cells;
    char pad34c[0x35c - 0x34c];
    StringPair title;
    char pad370[0x384 - 0x35c - sizeof(StringPair)];
    StringPair subtitle;
    char pad398[0x3f4 - 0x384 - sizeof(StringPair)];
    StringPair footer;
};

FEMemCardControl::~FEMemCardControl()
{
    if (handle != 0) {
        handle->Release();
        handle = 0;
    }
}
} // namespace fn_000d7db0


// 0x000d7e60 FEMemCardControl::vfunc_3 (94 B): matches/0x000d7e60.cpp [wrapped: conflict: FEMemCardControl]
// sym: ?vfunc_3@FEMemCardControl@fn_000d7e60@@UAEXXZ
namespace fn_000d7e60 {
// data: name_d7e60 = DAT_004a0c7c

class Manager_d7e60 {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual int f44();
};
Manager_d7e60* getManager_000fc3d0();
class Field_d7e60 {
  public:
    int val;
    void set_000f8500(char*, int, int);
};
class FEControl_d7e60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3();
};
class FEMemCardControl : public FEControl_d7e60 {
  public:
    char a[0x18 - 4];
    int x18;
    char b[0x1d0 - 0x1c];
    int x1d0;
    char c[0x220 - 0x1d4];
    int x220;
    char d[0x25c - 0x224];
    int x25c;
    char e[0x298 - 0x260];
    int x298;
    char f[0x2d4 - 0x29c];
    int x2d4;
    char g[0x310 - 0x2d8];
    int x310;
    char h[0x384 - 0x314];
    Field_d7e60 field;
    virtual void vfunc_3();
};
void FEMemCardControl::vfunc_3() {
    FEControl_d7e60::vfunc_3();
    x1d0 = 0;
    x18 = 0;
    Manager_d7e60* m = getManager_000fc3d0();
    field.set_000f8500((*(char**)&DAT_004a0c7c), m->f44(), 1);
    field.val = 0;
    x220 = 0;
    x25c = 0;
    x298 = 0;
    x2d4 = 0;
    x310 = 0;
}
} // namespace fn_000d7e60

namespace fn_f70d8f3f {

// 0x000d7ec0 FUN_000d7ec0 (39 B): matches/0x000d7ec0.cpp
// sym: ?target@FEMemCardControl_d7ec0@fn_f70d8f3f@@QAEXH@Z
void FEMemCardControl_d7ec0::target(int arg) {
    Y_d7ec0* y = getY_000fc3d0();
    y->f44();
    flag = 1;
    field = 0;
}


// 0x000d7ef0 FUN_000d7ef0 (57 B): matches/0x000d7ef0.cpp
// sym: ?Run@FEMemCardControl_d7ef0@fn_f70d8f3f@@QAEXH@Z
void FEMemCardControl_d7ef0::Run(int unused) {
    Thing_d7ef0* p = GetThing_000fc3d0();
    p->f44();
    ((owners::MenuScreen_bc9f0 *)mControl)->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", 3);
    mFlag = 1;
    mState = 0;
}


// 0x000d7f30 FUN_000d7f30 (25 B): matches/0x000d7f30.cpp
// sym: ?FUN_000d7f30@fn_f70d8f3f@@YAEPAX@Z
unsigned char __cdecl FUN_000d7f30(void* /*this, unused: callers pass it (unb4)*/) {
    Root_d7f30* r = (Root_d7f30*)FUN_000fc3d0();
    Obj_d7f30* p = (Obj_d7f30*)r->obj;
    if (p)
        return p->value;
    return 0;
}


// 0x000d7f60 FUN_000d7f60 (69 B): matches/0x000d7f60.cpp
// sym: ?update@FEMemCardControl_d7f60@fn_f70d8f3f@@QAEXXZ
void FEMemCardControl_d7f60::update() {
    result = -1;
    int i = 0;
    char* p = &slots[0][0];
    do {
        if (!((flag == 0 && p[8] != 0) || *p == 0)) {
            result = i;
            return;
        }
        ++i;
        p += 0x3c;
    } while (i < 5);
}


// 0x000d7ff0 FUN_000d7ff0 (60 B): matches/0x000d7ff0.cpp
// sym: ?Run@Owner@fn_f70d8f3f@@QAEXHH@Z
void Owner::Run(int index, int unused) {
    Source* s = fetch_000fc3d0();
    int v = s->Get();
    Item* p = &items[index];
    p->value = 0;
    p->action_000f8500(((int*)&DAT_004a0c64)[index], v, 1);
}

} // namespace fn_f70d8f3f

// 0x000d8140 FEMemCardControl::vfunc_14 (3 B): matches/0x000d8140.cpp
// sym: ?vfunc_14@FEMemCardControl@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEMemCardControl::vfunc_14(int a) {
    (void)a;
}

namespace fn_f70d8f3f {

// 0x000d8150 FUN_000d8150 (28 B): matches/0x000d8150.cpp
// sym: ?FUN_000d8150@fn_f70d8f3f@@YIXPAUObj_d8150@1@@Z
void __fastcall FUN_000d8150(Obj_d8150* p) {
    char* q = p->pad + 0x258;
    for (int i = 5; i != 0; --i) {
        q[-8] = 0;
        *q = 0;
        q += 0x3c;
    }
}


// 0x000d8170 FUN_000d8170 (31 B): matches/0x000d8170.cpp
// sym: ?target@FEMemCardControl_d8170@fn_f70d8f3f@@QAEHHH@Z
int FEMemCardControl_d8170::target(int a, int b) {
    return ((C_d8170*)member->Fnf_000b5000())->Fng_000890a0(a, b);
}


// 0x000d8190 FUN_000d8190 (37 B): matches/0x000d8190.cpp
// sym: ?target@FEMemCardControl_d8190@fn_f70d8f3f@@QAEHHH@Z
int FEMemCardControl_d8190::target(int a, int b) {
    return ptr->call_000b5000()->finish_0008b560(a, b, hulk_at_004dd6ec);
}


// 0x000d81c0 FUN_000d81c0 (95 B): matches/0x000d81c0.cpp
// sym: ?target@fn_f70d8f3f@@YIHPAVObj_d81c0@1@PAXHH@Z
int __fastcall target(Obj_d81c0* self, void*, int x, int y) {
    ((Chain_d81c0 *)((owners::Obj_89a50 *)(self->m->Get_000b5000()))->FUN_00089a50())->FnB_0008ca30(x);
    int r = self->m->Get_000b5000()->FnC_000892c0(x, y);
    ((Chain_d81c0 *)((owners::Obj_89a50 *)(self->m->Get_000b5000()))->FUN_00089a50())->FnD_0008c870(x);
    return r;
}


// 0x000d8220 FUN_000d8220 (97 B): matches/0x000d8220.cpp
// sym: ?Run@FEMemCardControl_d8220@fn_f70d8f3f@@QAEHH@Z
int FEMemCardControl_d8220::Run(int x) {
    ((B_d8220 *)((owners::Obj_89a50 *)(m->Get_000b5000()))->FUN_00089a50())->F1_0008ca30(x);
    int r = ((B_d8220 *)((owners::Obj_89a50 *)(m->Get_000b5000()))->FUN_00089a50())->F2_0008c810(x);
    ((B_d8220 *)((owners::Obj_89a50 *)(m->Get_000b5000()))->FUN_00089a50())->F3_0008c870(x);
    return r;
}

} // namespace fn_f70d8f3f

// 0x000d82d0 FUN_000d82d0 (288 B): equivalent/0x000d82d0.cpp [wrapped: conflict: FEMemCardControl]
// sym: ??0FEMemCardControl@fn_000d82d0@@QAE@HH@Z @7542305cceb0 @w5ea31d5aed4b
namespace fn_000d82d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000d82d0 @ 0x000d82d0
struct Item_d82d0 { char data[0x24]; void FUN_000f7930(); };
struct Entry_d82d0 { Item_d82d0 item; char pad[12]; unsigned char active; char pad2[7]; unsigned char flag; char pad3[3]; };
struct CGlowDisplayEffect_d82d0 { char data[0x1c]; void FUN_000dee10(); };
struct CDropShadowDisplayEffect_d82d0 { char data[0x14]; void FUN_000dee40(); };
struct Record_d82d0 { int a,b,c,d; };
struct FUN_000e9240 {
 virtual void slot0();
 char pad0[0x14c]; int owner;
 char pad1[0x78]; int index; int value; int other; unsigned char flag1,flag2; char pad2[0x46];
 FUN_000e9240(int);
};
struct FEMemCardControl : FUN_000e9240 {
 virtual void slot0();
 Entry_d82d0 entries[5];
 char gap[0x10];
 Item_d82d0 item1; unsigned char flag380; char pad380[3];
 Item_d82d0 item2; unsigned char enabled; char pad3a8[3]; int count; unsigned char flag3b0; char pad3b0[3];
 CGlowDisplayEffect_d82d0 stateA; CDropShadowDisplayEffect_d82d0 stateB;
 int stateValue; unsigned char f8,f9,fa,fb,fc; char pad3ed[3]; int stateOther;
 Item_d82d0 item3; int mask; char pad41c[12]; FEMemCardControl* self; char pad42c[4]; Record_d82d0 records[2];
 FEMemCardControl(int first,hulk_intptr second);
};
FEMemCardControl::FEMemCardControl(int first,hulk_intptr second) : FUN_000e9240(first) {
 for(int i=0;i<5;++i) { entries[i].item.FUN_000f7930(); entries[i].active=0; entries[i].flag=0; }
 item1.FUN_000f7930(); flag380=0;
 item2.FUN_000f7930(); stateA.FUN_000dee10(); stateB.FUN_000dee40(); item3.FUN_000f7930();
 records[0].a=0; records[0].b=0; records[0].c=0; records[0].d=-1;
 records[1].a=0; records[1].b=0; records[1].c=0; records[1].d=-1;
 value=0; flag1=0; flag2=0; other=0; count=0; flag3b0=0; stateValue=0; f8=0; f9=0; fc=0; stateOther=0; owner=second; enabled=1; index=0; fb=0; fa=0; mask=31; self=this;
}
} // namespace fn_000d82d0


// 0x000d8680 FEMemCardControl::vfunc_5 (610 B): equivalent/0x000d8680.cpp [wrapped: conflict: FEMemCardControl; FUN_000fc3d0]
// sym: ?vfunc_5@FEMemCardControl@fn_000d8680@@UAEXXZ @da86a90bb16b @wf46154bc50e4
namespace fn_000d8680 {
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 34/34)
// FEMemCardControl::vfunc_5 @ 0x000d8680

struct Metrics_d8680 { int dummy; };

class Fonts_d8680 {
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
    virtual Metrics_d8680 *v44();
};

struct Hold_d8680 {
    char pad0[4];
    Fonts_d8680 *fonts;
};

class Owner_d8680 {
public:
    char pad0[8];
    Hold_d8680 *hold;
};

class Provider_d8680 {
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
    virtual void v15(int a);
    virtual void v16(int a);
};

struct ProviderRef_d8680 {
    Provider_d8680 *provider;
    void FUN_00293d00(void *state);
};

struct Player_d8680 {
    char pad0[0x9a8];
    char busy;
};

class Game_d8680 {
public:
    char pad0[0x2218];
    Player_d8680 *player;
};

Game_d8680 *FUN_000fc3d0();

struct Entry_d8680 {
    int a;
    int b;
    float scale;
};

struct Slot_d8680 {
    float weight;
    int a;
    int b;
    int value;
};

struct SlotStack_d8680 {
    Slot_d8680 slots[8];
    int index;
    float scale;
    void FUN_000f78f0();
};

struct Layout_d8680 {
    Metrics_d8680 *font;
    int current;
    SlotStack_d8680 stack;
    Layout_d8680 *FUN_000f7fe0(Metrics_d8680 *font);
    void FUN_000f87f0(Entry_d8680 *e, void *arg);
    void FUN_000f78e0();
};

struct Item_d8680 {
    Entry_d8680 entry;
    char pad[0x38 - sizeof(Entry_d8680)];
};

struct Rec_d8680 {
    Entry_d8680 entry;
    char pad0c[0x30 - sizeof(Entry_d8680)];
    char hasEntry;
    char pad31[7];
    char selected;
    char pad39[3];
};


class FEMemCardControl {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x14 - 4];
    Owner_d8680 *owner;
    char pad18[0x154 - 0x18];
    char state154[0x178 - 0x154];
    char cells[5][12];
    char pad1b4[0x1d0 - 0x1b4];
    int sel;
    int sel2;
    char pad1d8[0x220 - 0x1d8];
    Rec_d8680 recs[5];
    char pad34c[0x35c - (0x220 + 5 * 0x3c)];
    Item_d8680 items[1];
    char pad394[0x3a8 - (0x35c + 0x38)];
    char flag3a8;
    char pad3a9[0x3ac - 0x3a9];
    int mode;
    char pad3b0[4];
    char block3b4[0x3c4 - 0x3b4];
    unsigned int color3c4;
    char pad3c8[0x3d0 - 0x3c8];
    char block3d0[4];

    float FUN_000e2840();
    float FUN_000e2850();
};

void FEMemCardControl::vfunc_5()
{
    Layout_d8680 layout;
    SlotStack_d8680 *st = &layout.stack;

    layout.FUN_000f7fe0(owner->hold->fonts->v44());
    st->slots[st->index].value = (*(unsigned int*)&DAT_004a0cfc);
    {
        float k = FUN_000e2850();
        st->slots[st->index].weight = FUN_000e2840() * k;
    }
    st->slots[st->index].b = 2;

    Player_d8680 *pl = FUN_000fc3d0()->player;
    if ((pl == 0 || !pl->busy) && mode != 0x20 && (mode == 3 || mode == 5 || mode == 4 || mode == 7)) {
        st->slots[st->index].a = 1;
        (*(ProviderRef_d8680**)&DAT_0052c2ac)->provider->v15(0);
        (*(ProviderRef_d8680**)&DAT_0052c2ac)->FUN_00293d00(state154);
        layout.FUN_000f87f0(&items[sel].entry, 0);
        (*(ProviderRef_d8680**)&DAT_0052c2ac)->provider->v16(0);
        st->slots[st->index].a = 1;

        char *cell = cells[0];
        for (int i = 0; i < 5; i++) {
            if (i > 0 && !recs[i].hasEntry && !recs[i - 1].hasEntry)
                break;
            void *arg = 0;
            st->FUN_000f78f0();
            if (recs[i].selected) {
                st->slots[st->index].value = (*(unsigned int*)&DAT_004a0d08);
                if (i == sel2) {
                    arg = block3b4;
                    color3c4 = (*(unsigned int*)&DAT_004a0d14);
                }
            } else if (i == sel2) {
                st->slots[st->index].value = (*(unsigned int*)&DAT_004a0cfc);
                arg = block3b4;
                color3c4 = (*(unsigned int*)&DAT_004a0d10);
            } else {
                st->slots[st->index].value = (*(unsigned int*)&DAT_004a0d00);
                arg = block3d0;
            }
            (*(ProviderRef_d8680**)&DAT_0052c2ac)->provider->v15(0);
            (*(ProviderRef_d8680**)&DAT_0052c2ac)->FUN_00293d00(cell);
            Entry_d8680 *e;
            if (!recs[i].hasEntry) {
                if (!flag3a8)
                    st->slots[st->index].value = (*(unsigned int*)&DAT_004a0d0c);
                e = (Entry_d8680 *)((char *)items + 0x28);
            } else {
                e = &recs[i].entry;
            }
            layout.FUN_000f87f0(e, arg);
            (*(ProviderRef_d8680**)&DAT_0052c2ac)->provider->v16(0);
            if (st->index > 0)
                st->index--;
            cell += 12;
        }
    }
    layout.FUN_000f78e0();
}
} // namespace fn_000d8680

namespace fn_f70d8f3f {

// 0x000d88f0 FUN_000d88f0 (150 B): equivalent/0x000d88f0.cpp
// sym: ?FUN_000d88f0@FEMemCardControl_d88f0@fn_f70d8f3f@@QAEXHPAD0@Z @fe750c3ad562 @w0a7c09ee1dcb
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 8/8)
// FUN_000d88f0 @ 0x000d88f0
void FEMemCardControl_d88f0::FUN_000d88f0(int key, char *foundNone, char *foundOther)
{
    *foundNone = 0;
    *foundOther = 0;
    // the bound is a constant; the original still fetches the table before asking for it
    unsigned int i = 0;
    ((void *)((owners::Obj_89a50 *)(source->FUN_000b5000()))->FUN_00089a50());
    unsigned int count = FUN_0008c580();
    for (; i < count; i++) {
        int r = ((Query_d88f0 *)source->FUN_000b5000())->FUN_000890a0(key, i);
        if (r == 0) {
            *foundNone = 1;
        } else if (r != 1) {
            *foundOther = 1;
            rows[i].flag = 1;
        }
        ((void *)((owners::Obj_89a50 *)(source->FUN_000b5000()))->FUN_00089a50());
        count = FUN_0008c580();
    }
}


// 0x000d9080 FUN_000d9080 (125 B): matches/0x000d9080.cpp
// sym: ?Run@FEMemCardControl_d9080@fn_f70d8f3f@@QAEXHH@Z
// data: kZero_d9080 = DAT_003f335c
void FEMemCardControl_d9080::Run(int a, int b) {
    Menu_d9080* m = GetMenu_000fc3d0();
    const char* s;
    if (!f3eb) {
        Mgr_d9080* g = g_mgr_d9080->Get();
        if (g->flag)
            s = DAT_004a0ce4;
        else
            s = DAT_004a0ce0;
    } else {
        s = DAT_004a0ce8;
    }
    m->Show_000be230(s, DAT_004a0c90, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c), DAT_00408ee8, 2, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c));
    f3b0 = 1;
    v21c = 0;
}


// 0x000d9100 FUN_000d9100 (125 B): matches/0x000d9100.cpp
// sym: ?Run@FEMemCardControl_d9100@fn_f70d8f3f@@QAEXHH@Z
// data: kZero_d9100 = DAT_003f335c
void FEMemCardControl_d9100::Run(int a, int b) {
    Menu_d9100* m = GetMenu_000fc3d0();
    const char* s;
    if (!f3eb) {
        Mgr_d9100* g = g_mgr_d9100->Get();
        if (g->flag)
            s = DAT_004a0ce4;
        else
            s = DAT_004a0ce0;
    } else {
        s = DAT_004a0ce8;
    }
    m->Show_000be230(s, DAT_004a0c98, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c), DAT_00408ee8, 2, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c));
    f3b0 = 1;
    v21c = 0;
}


// 0x000d9e40 FUN_000d9e40 (53 B): matches/0x000d9e40.cpp
// sym: ?run@FEMemCardControl_d9e40@fn_f70d8f3f@@QAEXH@Z
void FEMemCardControl_d9e40::run(int unused) {
    Obj_d9e40* p = getObj_000fc3d0();
    p->v44();
    helper_000d8990(value);
    flag = 1;
    zero = 0;
}

} // namespace fn_f70d8f3f

// 0x000dbe20 FEMemCardControl::vfunc_12 (994 B): equivalent/0x000dbe20.cpp [wrapped: conflict: FEMemCardControl]
// sym: ?vfunc_12@FEMemCardControl@fn_000dbe20@@UAEDHH@Z @d6911d159515 @w6e1ab15f3147
namespace fn_000dbe20 {
// STATUS: equivalent (tools/equiv.py level 3: 3105 inputs, branch coverage 59/66, incomplete)
// FEMemCardControl::vfunc_12 @ 0x000dbe20
class Sink_dbe20 {
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
    virtual void v48(int mode);
};

struct Hub_dbe20 {
    char pad0[4];
    Sink_dbe20 *sink;
};

struct Holder_dbe20 {
    char pad0[8];
    Hub_dbe20 *hub;
};

struct Entry_dbe20 {
    char valid;
    char pad01[7];
    char locked;
    char pad09[0x3c - 9];
};

extern "C" int __cdecl FUN_0009fa70(int *v, int *lo, int *hi);

class FEMemCardControl {
public:
    virtual void vfunc_0();
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
    virtual char vfunc_12(int cmd, int unused);
    char pad04[0x10];
    Holder_dbe20 *holder;
    char pad18[0x1d0 - 0x18];
    int cursorId;
    int sel;
    char pad1d8[0x250 - 0x1d8];
    Entry_dbe20 entries[5];
    char pad37c[0x3a8 - 0x37c];
    char useMouse;
    char pad3a9[3];
    int state;
    char dirty;
    void FUN_000d9e40(int id);
    void FUN_000d8990(int id);
    void FUN_000d8dd0(int id);
    void FUN_000d8a90(int id);
    void FUN_000d9790(int id);
};

char FEMemCardControl::vfunc_12(int cmd, int unused)
{
    if (state != 3)
        return 1;
    switch (cmd) {
    case 8:
    case 11:
        if (useMouse) {
            int s = sel;
            if (entries[s].locked) {
                holder->hub->sink->v48(0);
                state = 0x19;
                FUN_000d9e40(cursorId);
                return 1;
            }
            if (entries[s].valid) {
                holder->hub->sink->v48(0);
                state = 8;
                FUN_000d8990(cursorId);
                return 1;
            }
            holder->hub->sink->v48(0);
            state = 4;
            FUN_000d8dd0(cursorId);
            return 1;
        }
        if (sel >= 0) {
            holder->hub->sink->v48(0);
            state = 9;
            FUN_000d8a90(cursorId);
            dirty = 1;
        }
        return 1;
    case 0:
        if (useMouse) {
            int old = sel;
            int v = old - 1;
            int lo = 0;
            int hi = 4;
            int r = FUN_0009fa70(&v, &lo, &hi);
            if (r == old)
                return 1;
            holder->hub->sink->v48(2);
            sel = r;
            return 1;
        } else {
            int old = sel;
            sel = old - 1;
            while (sel != -1) {
                int c = sel;
                if (c < 0)
                    c = 0;
                else if (c > 4)
                    c = 4;
                sel = c;
                if (entries[c].valid && !entries[c].locked) {
                    holder->hub->sink->v48(2);
                    return 1;
                }
                if (c == 0)
                    break;
                sel = sel - 1;
            }
            sel = old;
            return 1;
        }
    case 4: {
        int old = sel;
        if (old < 4 && !entries[old].valid && !entries[old + 1].valid)
            return 1;
        if (useMouse) {
            int v = old + 1;
            int lo = 0;
            int hi = 4;
            int r = FUN_0009fa70(&v, &lo, &hi);
            if (r == old)
                return 1;
            holder->hub->sink->v48(2);
            sel = r;
            return 1;
        }
        int c;
        do {
            c = sel + 1;
            if (c < 0)
                c = 0;
            else if (c > 4)
                c = 4;
            sel = c;
            if (entries[c].valid && !entries[c].locked) {
                holder->hub->sink->v48(2);
                return 1;
            }
        } while (c != 4);
        sel = old;
        return 1;
    }
    case 10:
        holder->hub->sink->v48(1);
        state = 0x1f;
        return 1;
    case 9:
        if (!useMouse)
            return 1;
        if (sel < 0)
            return 1;
        if (!entries[sel].valid)
            return 1;
        holder->hub->sink->v48(0);
        state = 0xd;
        FUN_000d9790(cursorId);
        dirty = 1;
        return 1;
    }
    return 0;
}
} // namespace fn_000dbe20

