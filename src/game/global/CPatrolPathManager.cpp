// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001065b0..0x00107000 (kind game, layer game, confidence high), dominant class CPatrolPathManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd31b6ef {
#define TREE_TU_END }
namespace fn_fd31b6ef {} using namespace fn_fd31b6ef;
#include "game/global.h"
#include "game/script_bind.h"

// ---- declarations shared by the functions below
namespace fn_fd31b6ef {
struct Name_106900 {
};
class CPatrolPath_106900 {
public:
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Name_106900 name;
    char pad09[15];
    char flag;
    char pad19[7];
    CPatrolPath_106900* FUN_00106510(int n);
};
unsigned __int64 __cdecl FUN_0027afb0(const char* s);
void* __cdecl thunk_FUN_0008d690(unsigned int size);
class Registry_106900 {
public:
    int FUN_00106290(unsigned __int64 key);
    void FUN_001062d0(CPatrolPath_106900* e);
    bool Add(const char* name, char flag, int n);
};
struct Pair {
    int a, b;
};
Pair __cdecl Lookup_0027afb0(int);
class Obj {
  public:
    int Find_00106290(int, int);
    unsigned char Do_00106360(int);
    unsigned char Run(int);
};
class CPatrolPathManager_106ad0 {
  public:
    bool Find(const char*);
};
class Function_106ad0 {
  public:
    virtual void v0();
    virtual void v1();
};
struct Vector_106b70 { float x, y, z; };
struct Arguments { const char* name; int value; Vector_106b70 position; };
struct CPatrolPathManager_106b70 {
    bool FUN_00106b70(const char*, int, Vector_106b70);
};
struct Function_106b70 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_fd31b6ef
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_fd31b6ef {
class CPatrolPathManager_106d80 {};
typedef bool (CPatrolPathManager_106d80::*Fn_106d80)(const char*, bool, int);
class Registry_106d80 { public:
    void FUN_00106d80(const char* a1, CPatrolPathManager_106d80* a2, Fn_106d80 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_106d80;
template<> class Closure3_106d80<CPatrolPathManager_106d80, bool, const char*, bool, int> : public ScriptFunctionFields { public: virtual void v(); Fn_106d80 fn; CPatrolPathManager_106d80* owner; Closure3_106d80(CPatrolPathManager_106d80* o) { owner = o; } };
class Raw_106d80 { public: void FUN_001069c0(const char*, Fn_106d80); };
} // namespace fn_fd31b6ef
namespace math {
class Vector_106e30 { public: float x, y, z; };
}
namespace fn_fd31b6ef {
class CPatrolPathManager_106e30 {};
typedef bool (CPatrolPathManager_106e30::*Fn_106e30)(const char*, int, math::Vector_106e30);
class Registry_106e30 { public:
    void FUN_00106e30(const char* a1, CPatrolPathManager_106e30* a2, Fn_106e30 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_106e30;
template<> class Closure3_106e30<CPatrolPathManager_106e30, bool, const char*, int, math::Vector_106e30> : public ScriptFunctionFields { public: virtual void v(); Fn_106e30 fn; CPatrolPathManager_106e30* owner; Closure3_106e30(CPatrolPathManager_106e30* o) { owner = o; } };
class Raw_106e30 { public: void FUN_00106af0(const char*, Fn_106e30); };
class pddiObject_106f60 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_106f60 : public pddiObject_106f60 {};
class pddiBaseShader_106f60 : public pddiShader_106f60 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_106f60 : public pddiBaseShader_106f60 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

} // namespace fn_fd31b6ef

// 0x001065b0 CPatrolPathManager::vfunc_1 (840 B): equivalent/0x001065b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_1@CPatrolPathManager@fn_001065b0@@QAEDPAUElement_1065b0@2@@Z @217babd05106 @w676af95f33ac @v9db7a9330a9f
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001065b0 {
// STATUS: equivalent (tools/equiv.py level 3: 1297 inputs, branch coverage 22/22)
// CPatrolPathManager::vfunc_1 @ 0x001065b0
// CPatrolPathManager::vfunc_1 @ 0x001065b0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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
extern "C" char __cdecl FUN_001d04d0(const void*);   // type_info test (compares against DAT_0048e100, ...)


struct V3_1065b0 {
    float x, y, z;
};

struct Mat4_1065b0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022be60(float x, float y, float z);
    void FUN_0022be40(const V3_1065b0 *pos);
    void FUN_0022ca90(const Mat4_1065b0 *a, const Mat4_1065b0 *b);
    void FUN_0022c2b0(V3_1065b0 *in, V3_1065b0 *out);
};

struct NameHolder_1065b0 {
    char data[8];
    void FUN_0027b040(const char *name);
};

struct Table_1065b0 {
    int FUN_00337130(const char *name);
};

struct Element_1065b0 {
    char pad0[4];
    Table_1065b0 *table;
    char pad8[4];
    const char *name;
    char FUN_003358a0(int index, int *out);
    void FUN_00336600(const char *attr, float *x, float *y, float *z);
    char FUN_00335cc0(int index, int i, float *x, float *y, float *z);
    char FUN_003364f0(const char *attr, int *out);
};

struct PathPoint_1065b0 {
    float x, y, z;
    int next;
    float weight;
    int f14;
    int f18;
    int f1c;
    int f20;
};

class __declspec(novtable) PathBase {
public:
    virtual void v0_00038290();
    char pad04[4];
    NameHolder_1065b0 name;
    void FUN_0027b070();
    PathBase() { FUN_0027b070(); }
};

void *thunk_FUN_0008d690(unsigned int size);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)


class CPatrolPath : public PathBase {
public:
    PathPoint_1065b0 *points;   // 0x10
    int count;           // 0x14
    char closed;         // 0x18
    virtual void v1_000382a0();
    CPatrolPath(int n);
};

CPatrolPath::CPatrolPath(int n)
{
    closed = 0;
    points = (PathPoint_1065b0 *)FUN_0008d6d0(n * sizeof(PathPoint_1065b0));
    count = n;
}

struct Sub_1065b0 {
    char FUN_001cd010();
};

struct World {
    void* pad[11];
    Sub_1065b0 *sub;
};

class CPatrolPathManager {
public:
    char pad[4];
    int FUN_001062d0(CPatrolPath *p);
    char vfunc_1(Element_1065b0 *elem);
};

struct PatrolFrame {
    char pad10[3];
    char closed;            // 0x13
    int n;                  // 0x14
    union {
        const char *pathName;
        float a;
    } u18;                  // 0x18
    V3_1065b0 pos;                 // 0x1c
    V3_1065b0 v;                   // 0x28
    int idx;                // 0x34
    float b;                // 0x38
    float c;                // 0x3c
    float sx;               // 0x40
    char pad44[4];
    float ty;               // 0x48
    float rx;               // 0x4c
    float rz;               // 0x50
    float sz;               // 0x54
    float ry;               // 0x58
    float tz;               // 0x5c
    int form;               // 0x60
    float tx;               // 0x64
    float sy;               // 0x68
    Mat4_1065b0 tmp;               // 0x6c
    Mat4_1065b0 rot;               // 0xac
    Mat4_1065b0 moveM;             // 0xec
    Mat4_1065b0 scaleM;            // 0x12c
    Mat4_1065b0 full;              // 0x16c
};

char CPatrolPathManager::vfunc_1(Element_1065b0 *elem)
{
    if (DAT_004dd700->sub->FUN_001cd010())
        return 1;

    PatrolFrame f;
    f.u18.pathName = elem->name;
    f.idx = elem->table->FUN_00337130("controlPoints");
    elem->FUN_003358a0(f.idx, &f.n);

    elem->FUN_00336600("translate", &f.tx, &f.ty, &f.tz);
    elem->FUN_00336600("rotate", &f.rx, &f.ry, &f.rz);
    elem->FUN_00336600("scale", &f.sx, &f.sy, &f.sz);

    f.rot.FUN_0022b980();
    f.rot.FUN_0022bc20(f.rx * -0.017453292f, f.ry * -0.017453292f, f.rz * 0.017453292f);
    f.scaleM.FUN_0022b980();
    f.scaleM.FUN_0022be60(f.sx, f.sy, f.sz);
    f.moveM.FUN_0022b980();
    f.pos.x = f.tx;
    f.pos.y = f.ty;
    f.pos.z = -f.tz;
    f.moveM.FUN_0022be40(&f.pos);
    f.tmp.FUN_0022ca90(&f.rot, &f.scaleM);
    f.full.FUN_0022ca90(&f.tmp, &f.moveM);
    f.tmp = f.full;

    int n = f.n;
    void *mem = thunk_FUN_0008d690((unsigned int)sizeof(::CPatrolPath));
    CPatrolPath *path = 0;
    if (mem)
        path = new (mem) CPatrolPath(n);
    path->v0_00038290();
    path->name.FUN_0027b040(f.u18.pathName);

    elem->FUN_003364f0("form", &f.form);
    f.closed = f.form != 0;
    path->closed = f.closed;

    for (int i = 0; i < f.n; i++) {
        elem->FUN_00335cc0(f.idx, i, &f.u18.a, &f.b, &f.c);
        f.v.x = f.u18.a;
        f.v.y = f.b;
        f.v.z = -f.c;
        f.tmp.FUN_0022c2b0(&f.v, &f.v);
        if (i < path->count) {
            PathPoint_1065b0 *pt = &path->points[i];
            pt->x = f.v.x;
            pt->y = f.v.y;
            pt->z = f.v.z;
        }
        // path->points is re-read before every store: a fuzzed allocation can overlap the path itself
        if (i == f.n - 1) {
            if (f.closed) {
                if (i < path->count) {
                    path->points[i].next = 0;
                    path->points[i].f14 = 0;
                    path->points[i].f18 = 0;
                    path->points[i].f20 = 0;
                    path->points[i].f1c = 0;
                    path->points[i].weight = 0.5f;
                }
            } else {
                if (i < path->count) {
                    path->points[i].next = -1;
                    path->points[i].f14 = 0;
                    path->points[i].f18 = 0;
                    path->points[i].f20 = 0;
                    path->points[i].f1c = 0;
                    path->points[i].weight = 0.5f;
                }
            }
        } else if (i < path->count) {
            path->points[i].next = i + 1;
            path->points[i].f14 = 0;
            path->points[i].f18 = 0;
            path->points[i].f20 = 0;
            path->points[i].f1c = 0;
            path->points[i].weight = 0.5f;
        }
    }
    FUN_001062d0(path);
    path->v1_000382a0();
    return 1;
}
} // namespace fn_001065b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fd31b6ef {

// 0x00106900 FUN_00106900 (128 B): equivalent/0x00106900.cpp
// sym: ?Add@Registry_106900@fn_fd31b6ef@@QAE_NPBDDH@Z @387f093b5205 @we6dd7d1f6a2e @v22e7935e7085
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00106900 @ 0x00106900
// 0x00106900: register a new named entry (with a flag and a size) unless the name is already known
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
bool Registry_106900::Add(const char* name, char flag, int n)
{
    if (FUN_00106290(FUN_0027afb0(name)) != -1)
        return false;
    if (n <= 0)
        return false;

    void* mem = thunk_FUN_0008d690((int)sizeof(CPatrolPath_106900));
    CPatrolPath_106900* e = 0;
    if (mem != 0)
        e = ((CPatrolPath_106900*)mem)->FUN_00106510(n);
    e->v0();
    ((owners::Target_27b040 *)&(e->name))->FUN_0027b040((hulk_uintptr)name);
    e->flag = flag;
    FUN_001062d0(e);
    e->v1();
    return true;
}


// 0x00106980 FUN_00106980 (53 B): matches/0x00106980.cpp
// sym: ?Run@Obj@fn_fd31b6ef@@QAEEH@Z
unsigned char Obj::Run(int x) {
    unsigned char r = 0;
    Pair p = Lookup_0027afb0(x);
    int i = Find_00106290(p.a, p.b);
    if (i != -1)
        r = Do_00106360(i);
    return r;
}

} // namespace fn_fd31b6ef

// 0x001069c0 FUN_001069c0 (89 B): matches/0x001069c0.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_001069c0@@QAE@PBDP8Owner_1069c0@1@AEXXZ@Z
namespace fn_001069c0 {
// (script1) Method3<class CPatrolPathManager,bool,const char *,bool,int>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_0040d5a8[];   // Method3<class CPatrolPathManager,bool,const char *,bool,int>
class Owner_1069c0 {};
typedef void (Owner_1069c0::*Fn_1069c0)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_1069c0 fn;
    Method3(const char* name, Fn_1069c0 function);
};
Method3::Method3(const char* name, Fn_1069c0 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_0040d5a8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
}
} // namespace fn_001069c0


// 0x00106a20 Method3<CPatrolPathManager,bool,const_char_*,bool,int>::vfunc_0 (30 B): matches/0x00106a20.cpp
// sym: ?vfunc_0@Method3_106a20@fn_00106a20@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method3<CPatrolPathManager, bool, const char *,
// bool, int>::~Method3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0,
// then (flags & 1) operator delete.
namespace fn_00106a20 {
struct Method3_106a20 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_106a20::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00106a20


// 0x00106a40 Method3<CPatrolPathManager,bool,const_char_*,bool,int>::vfunc_2 (47 B): matches/0x00106a40.cpp [wrapped: conflict: CPatrolPathManager; Function; Method3]
// sym: ?f2@Method3@fn_00106a40@@QAE_NHPAUArgs_106a40@2@PA_N@Z
namespace fn_00106a40 {
class CPatrolPathManager {
  public:
    bool invoke(const char*, bool, int);
};
struct Args_106a40 {
    const char* s;
    bool b;
    int i;
};
typedef bool (CPatrolPathManager::*Fn_106a40)(const char*, bool, int);
class Function { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void f0();
    void f1();
};
class Method3 : public Function {
  public:
    void f0();
    void f1();
    bool f2(int x, Args_106a40* a, bool* out);
    ScriptFunctionFields fields;   // (script2) Function's fields (was char pad[0x1c - 4])
    Fn_106a40 fn;
};
bool Method3::f2(int x, Args_106a40* a, bool* out) {
    Fn_106a40 f = fn;
    const char* s = a->s;
    bool b = a->b;
    int i = a->i;
    bool r = (((CPatrolPathManager*)x)->*f)(s, b, i);
    if (out)
        *out = r;
    return r;
}
} // namespace fn_00106a40


// 0x00106ab0 Method1<CPatrolPathManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x00106ab0.cpp
// sym: ?vfunc_0@Method1_106ab0@fn_00106ab0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `template <> Method1<CPatrolPathManager, bool, const char *>::~Method1() {}`
// stood for it, which natively defines no function for the vftable slot (with the `??_G` signature, as other views call
// the slot). The destructor's body 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00106ab0 {
struct Method1_106ab0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method1_106ab0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00106ab0
// (x64t21) the destructor itself, which other objects' code references:


// 0x00106ad0 Method1<CPatrolPathManager,bool,const_char_*>::vfunc_2 (29 B): matches/0x00106ad0.cpp
// sym: ?vfunc_2@Method1_106ad0@fn_00106ad0@@QAEXPAX00@Z
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method1<CPatrolPathManager, bool, const char *>::vfunc_2`.
namespace fn_00106ad0 {
struct Method1_106ad0 : hulk_script::FunctionGenView {
    bool (::CPatrolPathManager::*f_1c)(const char *);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method1_106ad0::vfunc_2(void* __p0, void* __p1, void* __p2) { CPatrolPathManager_106ad0 * obj = (CPatrolPathManager_106ad0 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CPatrolPathManager_106ad0::*f)(const char*) = (*(bool (CPatrolPathManager_106ad0::**)(const char *))&this->f_1c);
    const char* x = *arg;
    bool r = (obj->*f)(x);
    if (out)
        *out = r;
}
} // namespace fn_00106ad0


// 0x00106af0 FUN_00106af0 (89 B): matches/0x00106af0.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_00106af0@@QAE@PBDP8Owner_106af0@1@AEXXZ@Z
namespace fn_00106af0 {
// (script1) Method3<class CPatrolPathManager,bool,const char *,int,class math::Vector>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftable by address,
// the member-function pointer, the type codes (0x001d04d0).
extern "C" char DAT_0040d5c8[];   // Method3<class CPatrolPathManager,bool,const char *,int,class math::Vector>
class Owner_106af0 {};
typedef void (Owner_106af0::*Fn_106af0)();
struct Method3 : hulk_script::ScriptFunction {
    Fn_106af0 fn;
    Method3(const char* name, Fn_106af0 function);
};
Method3::Method3(const char* name, Fn_106af0 function) : hulk_script::ScriptFunction(name, 3) {
    vftable = DAT_0040d5c8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    f.argTypes[1] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e134);
    f.argTypes[2] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e10c);
}
} // namespace fn_00106af0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00106b50 Method3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_0 (30 B): matches/0x00106b50.cpp
// sym: ?vfunc_0@Method3_106b50@fn_00106b50@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Method3<CPatrolPathManager, bool, const char *,
// int,math::Vector>::~Method3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body
// 0x001d04a0, then (flags & 1) operator delete.
namespace fn_00106b50 {
struct Method3_106b50 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Method3_106b50::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00106b50


// 0x00106b70 Method3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 (67 B): equivalent/0x00106b70.cpp
// sym: ?vfunc_2@Method3_106b70@fn_00106b70@@QAEXPAX00@Z @45f9773cb776 @w22e531a9c9d9 @vd04ad2ecfba7
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 @ 0x00106b70
// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CPatrolPathManager, bool, const char *, int,math::Vector>::vfunc_2`.
namespace fn_00106b70 {
struct Method3_106b70 : hulk_script::FunctionGenView {
    bool (::CPatrolPathManager::*f_1c)(const char *, int, math::Vector);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_106b70::vfunc_2(void* __p0, void* __p1, void* __p2) { CPatrolPathManager_106b70 * owner = (CPatrolPathManager_106b70 *)__p0; const Arguments * args = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = (owner->*(*(bool (CPatrolPathManager_106b70::**)(const char *, int, Vector_106b70))&this->f_1c))(args->name, args->value, args->position);
    if (result) *result = value;
}
} // namespace fn_00106b70


// 0x00106bf0 Closure3<CPatrolPathManager,bool,const_char_*,bool,int>::vfunc_0 (30 B): matches/0x00106bf0.cpp
// sym: ?vfunc_0@Closure3_106bf0@fn_00106bf0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (script2, D24) an explicit function in D114's form: `template <> Closure3<CPatrolPathManager, bool, const char *,
// bool, int>::~Closure3() {}` stood for it, whose MSVC `??_G` matched only under /GX. The destructor's body 0x001d04a0,
// then (flags & 1) operator delete.
namespace fn_00106bf0 {
struct Closure3_106bf0 {
    void FUN_001d04a0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Closure3_106bf0::vfunc_0(unsigned int flags) {
    FUN_001d04a0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_00106bf0


// 0x00106c50 FUN_00106c50 (76 B): matches/0x00106c50.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00106c50@@QAE@PBDPAVOwner_106c50@1@P821@AEXXZ@Z
namespace fn_00106c50 {
// (script1) Closure1<class CPatrolPathManager,bool,const char *>'s constructor
// on include/game/script_bind.h's records: Function's constructor 0x001d0480, the game's vftables by address,
// the member-function pointer, the type codes (0x001d04d0), the object.
extern "C" char DAT_0040d5b8[];   // Method1<class CPatrolPathManager,bool,const char *>
extern "C" char DAT_0040d5e8[];   // Closure1<class CPatrolPathManager,bool,const char *>
class Owner_106c50 {};
typedef void (Owner_106c50::*Fn_106c50)();
struct Closure1 : hulk_script::ScriptFunction {
    Fn_106c50 fn;
    Owner_106c50* owner;
    Closure1(const char* name, Owner_106c50* object, Fn_106c50 function);
};
Closure1::Closure1(const char* name, Owner_106c50* object, Fn_106c50 function) : hulk_script::ScriptFunction(name, 1) {
    vftable = DAT_0040d5b8;
    fn = function;
    f.retType = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0e4);
    f.argTypes[0] = hulk_script::FUN_001d04d0(hulk_script::DAT_0048e0f0);
    vftable = DAT_0040d5e8;
    owner = object;
}
} // namespace fn_00106c50


// 0x00106cc0 Closure1<CPatrolPathManager,bool,const_char_*>::vfunc_2 (30 B): matches/0x00106cc0.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_00106cc0@@QAEXPAXPAPBDPA_N@Z
namespace fn_00106cc0 {
class Closure1 { void* vftable;   /* (script2) the vftable word, no stand-in vftable */
  public:
    void V0();
    void V1();
    void V2(void*, const char**, bool*);
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
} // namespace fn_00106cc0

namespace fn_fd31b6ef {

// 0x00106d80 FUN_00106d80 (83 B): equivalent/0x00106d80.cpp
// sym: ?FUN_00106d80@Registry_106d80@fn_fd31b6ef@@QAEXPBDPAVCPatrolPathManager_106d80@2@P832@AE_N0_NH@Z@Z @5d370cce7786 @w564778c6c606 @v9334a10cffaa
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00106d80 @ 0x00106d80
// FUN_00106d80 @ 0x00106d80  (generated by tools/equiv_gen/reg_helper.py)
void Registry_106d80::FUN_00106d80(const char* a1, CPatrolPathManager_106d80* a2, Fn_106d80 a3) {
    typedef Closure3_106d80<CPatrolPathManager_106d80, bool, const char*, bool, int> Alloc_106d80;
    HULK_SIZE32(Alloc_106d80, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_106d80));
    void* x = 0;
    if (m) {
        ((Raw_106d80*)m)->FUN_001069c0(a1, a3);
        x = new (m) Closure3_106d80<CPatrolPathManager_106d80, bool, const char*, bool, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00106e30 FUN_00106e30 (83 B): equivalent/0x00106e30.cpp
// sym: ?FUN_00106e30@Registry_106e30@fn_fd31b6ef@@QAEXPBDPAVCPatrolPathManager_106e30@2@P832@AE_N0HVVector_106e30@math@@@Z@Z @7188d32da713 @wf4d6ddab3e84 @v4bce825e84e1
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00106e30 @ 0x00106e30
// FUN_00106e30 @ 0x00106e30  (generated by tools/equiv_gen/reg_helper.py)
void Registry_106e30::FUN_00106e30(const char* a1, CPatrolPathManager_106e30* a2, Fn_106e30 a3) {
    typedef Closure3_106e30<CPatrolPathManager_106e30, bool, const char*, int, math::Vector_106e30> Alloc_106e30;
    HULK_SIZE32(Alloc_106e30, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_106e30));
    void* x = 0;
    if (m) {
        ((Raw_106e30*)m)->FUN_00106af0(a1, a3);
        x = new (m) Closure3_106e30<CPatrolPathManager_106e30, bool, const char*, int, math::Vector_106e30>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_fd31b6ef

// 0x00106e90 FUN_00106e90 (197 B): matches/0x00106e90.cpp [wrapped: macros]
// sym: ??0CPatrolPathManager@fn_00106e90@@QAE@H@Z
void* operator new(hulk_uintptr) throw();
namespace fn_00106e90 {
// FUN_00106e90 @ 0x00106e90
// FUN_00106e90 @ 0x00106e90
// FUN_00106e90 @ 0x00106e90  (generated by tools/equiv_gen/inlined_regs.py)


void* FUN_0008d690(unsigned int);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
extern "C" char __cdecl FUN_001d04d0(const void*);   // (decl1) as defined (Function.cpp)
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char DAT_0048e0e4, DAT_0048e0f0;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
// CPatrolPathManager and the members it binds to Lua (their types are the game's Closure<N> instantiations, see
// matches/0x00106d80.cpp and 0x00106e30.cpp for the helpers'); complete before any pointer to a member is formed.
// (decl2) CPatrolPathManager and the Closure<1> it builds are records with the game's vftables by address
// (CPatrolPathManager's 0x0040d630; Method1 / Closure1<CPatrolPathManager, bool, const char*>'s 0x0040d5b8 /
// 0x0040d5e8, include/game/script_bind.h): the local polymorphic stand-ins had clang's own vftables and a Function
// constructor no build defines natively.
extern "C" char DAT_0040d630[], DAT_0040d5b8[], DAT_0040d5e8[];
class CPatrolPathManager {
public:
    CPatrolPathManager(int a);
    void* vftable;
    int f4;
    int f8;
    void* fc;
    bool FUN_00106900(const char*, bool, int);          // path_Add
    bool FUN_00106980(const char*);                     // path_Remove
    bool FUN_00106440(const char*, int, math::Vector);  // path_SetPoint
};
class Registry { public:
    void FUN_001d3b70(const char*, void*);
    void FUN_00106d80(const char*, CPatrolPathManager*, bool (CPatrolPathManager::*)(const char*, bool, int));
    void FUN_00106e30(const char*, CPatrolPathManager*, bool (CPatrolPathManager::*)(const char*, int, math::Vector));
};
extern "C" Registry* __cdecl FUN_001d4c90(void);   // (decl1) as defined (ScriptHandler.cpp)
#define G1(n, b, R, A1, MV, CV) { r->FUN_001d3b70(n, new hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CPatrolPathManager, R, A1>, CPatrolPathManager>(n, this, &CPatrolPathManager::FUN_##b, DAT_##MV, DAT_##CV)); }
#define O(n, c, b) { r->FUN_##c(n, this, &CPatrolPathManager::FUN_##b); }
CPatrolPathManager::CPatrolPathManager(int a) {
    f4 = a;
    vftable = DAT_0040d630;
    f8 = 0;
    fc = FUN_0008d6d0(a * 4);
    Registry* r = FUN_001d4c90();
    if (r) {
O("path_Add", 00106d80, 00106900)
G1("path_Remove", 00106980, Bool, String, 0040d5b8, 0040d5e8)
O("path_SetPoint", 00106e30, 00106440)
    }
}
} // namespace fn_00106e90
#undef G1
#undef O
#undef tBool
#undef tString


// 0x00106f60 CPatrolPathManager::vfunc_2 (6 B): matches/0x00106f60.cpp
// sym: ?vfunc_2@CPatrolPathManager@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int CPatrolPathManager::vfunc_2() {
    return 1;
}


// 0x00106f70 CPatrolPathManager::vfunc_3 (8 B): matches/0x00106f70.cpp [wrapped: conflict: CDHGameObjectCreator; CPatrolPathManager]
// sym: ?vfunc_3@CPatrolPathManager@fn_00106f70@@UAEPBDPAX@Z
namespace fn_00106f70 {
// Same code shape as 0x00078c40 (propagated; names are from that function)
// data: gWaypoint = DAT_0040d640

class CDHGameObjectCreator {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class CPatrolPathManager : public CDHGameObjectCreator, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* CPatrolPathManager::vfunc_3(void*) {
    return ((char*)&DAT_0040d640);
}
} // namespace fn_00106f70


// 0x00106f80 CPatrolPathManager::vfunc_0 (31 B): matches/0x00106f80.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00106f80@@UAEPAV123@E@Z
namespace fn_00106f80 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CDHGameObjectCreator_106f80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003feefc[];
namespace pure3d {
class NonCopyable : public CDHGameObjectCreator_106f80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003feefc;
    if ((param & 1) != 0)
        ::operator delete(this);
    return this;
}
} // namespace fn_00106f80

