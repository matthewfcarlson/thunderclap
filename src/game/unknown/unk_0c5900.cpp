// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c5900..0x000c6a90 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3173163 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3173163 {} using namespace fn_f3173163;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f3173163 {
struct Vec_c5900 {
 float x,y,z;
};
typedef unsigned int U_c5a90;
struct Triple_c5a90 {
    U_c5a90 x, y, z;
};
struct Helper_c5a90 {
    U_c5a90 FnB_002843a0(U_c5a90, U_c5a90);
};
struct Obj_c5a90 {
    Helper_c5a90* h;
    U_c5a90 pad;
    U_c5a90 c;
    U_c5a90 d;
    Triple_c5a90* Go(Triple_c5a90* out);
};
struct Mat {
    int x[16];
};
class Service {
  public:
    int FnB_002843a0(int, int);
    void FnC_00284860(int, int, Mat*);
};
extern int __fastcall Fng_002961d0(void*);
struct S_c5b40 {
    void* p;
    volatile int a;
    char pad[0x3fc];
    volatile int count;
    int result;
    volatile int last;
    void f();
};
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual int count();
 virtual Node* child(int index);
};
struct Entry_c5b80 { Node* node; int index; };
struct Walker_c5b80 {
 int reserved;
 Entry_c5b80 stack[128];
 int depth;
 Node* current;
 int index;
 Node* FUN_000c5b80();
};
struct Triple_c5c40 { unsigned int x,y,z; };
struct Object {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void setPair(unsigned int a,unsigned int b);
    virtual void getPair(unsigned int* a,unsigned int* b);
    virtual void setFirst(float value);
    virtual float getFirst();
    virtual void setSecond(float value);
    virtual float getSecond();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual const Vec_c5900* v14();
    char _m_pad_4[0xcc];
    Triple_c5c40 position;
    Triple_c5c40 first;
    Triple_c5c40 second;
    void FUN_00293ac0(Triple_c5c40* value);
};
struct Obj_c5d60 {
};
struct Entry_c5e60 { int key; int b, c; };
struct Registry_c5e60 {
    void FUN_000af0f0(Entry_c5e60* out);
};
struct Owner_c5e60 { Registry_c5e60* FUN_000af3a0(int id); };
extern "C" bool __cdecl Test_000c5e60(int, int, int, int, int, int, int);
struct Vec {
    int x, y, z;
    inline void set(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
};
class Obj {
  public:
    Service* svc;
    char _m_pad_4[0x4];
    union { int a; Vec* v; };
    int b;
    int* p;
    Mat* Fn(Mat* out);
    void update_0008ef00();
};
struct Vec3_c5fa0 {
    unsigned int x, y, z;
};
struct Buffer_c5fa0 {
    char pad00[8];
    Vec3_c5fa0 *vertex;
    int unused;
    unsigned int *color;
    void FUN_0008ef00();
};
static __forceinline void Emit(Buffer_c5fa0 *buffer, const Vec3_c5fa0 &v, unsigned int color)
{
    *buffer->vertex = v;
    *buffer->color = color;
    buffer->FUN_0008ef00();
}
struct Vec3_c60f0 {
    float x, y, z;
};
class Resource_c60f0;
class Handle;
class Factory_c60f0 {
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
    virtual Resource_c60f0 *v11(const char *name, int flag);
};
class Resource_c60f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int tag, int flag);
};
} // namespace fn_f3173163
class Gfx {
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
    virtual Handle *v30(Resource_c60f0 *r, int count, int a, int b, int c);
    virtual int v31(Handle *h);
};
namespace fn_f3173163 {
void FUN_000c5fa0(Handle *h, Vec3_c60f0 a, Vec3_c60f0 b, unsigned int color);
struct Vec3_c6250 { float x, y, z; };
extern int __cdecl FUN_000c60f0(Vec3_c6250, Vec3_c6250, Vec3_c6250, Vec3_c6250, unsigned int, unsigned int);
struct Vec3_c6840 { float x, y, z; };
void FUN_000c6330(Vec3_c6840 c0, Vec3_c6840 c1, Vec3_c6840 c2, Vec3_c6840 c3, Vec3_c6840 c4, Vec3_c6840 c5, Vec3_c6840 c6, Vec3_c6840 c7,
                  int a, int b);
class Arg_c6a20 {
  public:
    virtual void F();
    int FnG_002961d0();
};
class Obj_c6a20 {
  public:
    Arg_c6a20* mArg;
    volatile int mOne;
    char pad[0x3fc];
    volatile int mIndex;
    int m408;
    int m40c;
    Obj_c6a20* Run(Arg_c6a20*);
};
class X_c6a70 {
  public:
    virtual void a();
    virtual void b();
};
struct C_c6a70 {
    X_c6a70* p;
    void f();
};


// 0x000c5900 FUN_000c5900 (168 B): equivalent/0x000c5900.cpp
// sym: ?FUN_000c5900@fn_f3173163@@YAXPAUObject@1@HM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c5900 @ 0x000c5900
void __cdecl FUN_000c5900(Object* object, int axis, float amount) {
 Vec_c5900 delta;
 delta.x=0.0f; delta.y=0.0f; delta.z=0.0f;
 float y=axis==1?amount:0.0f;
 float z=axis==2?amount:0.0f;
 float x=axis==0?amount:0.0f;
 const Vec_c5900* base=object->v14();
 delta.x=x+delta.x;
 delta.y=y+delta.y;
 delta.z=z+delta.z;
 ((owners::Obj_22d210 *)&delta)->FUN_0022d210((owners::Obj_22d210 *)(const Vec_c5900 *)base);
 ((owners::C_293af0 *)object)->FUN_00293af0((int *)(const Vec_c5900 *)(&delta));
}

} // namespace fn_f3173163

// 0x000c59b0 FUN_000c59b0 (174 B): equivalent/0x000c59b0.cpp [wrapped: conflict: Object]
// sym: ?FUN_000c59b0@fn_000c59b0@@YAXPAUObject@1@HM@Z
namespace fn_000c59b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c59b0 @ 0x000c59b0
struct Matrix { float m[16];  };
struct Vector { float x,y,z;  };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual Matrix* v14();
};
void __cdecl FUN_000c59b0(Object* object,int axis,float angle) {
 Vector value; value.x=0.0f; value.y=0.0f; value.z=1.0f;
 float x=0.0f,y=0.0f,z=0.0f;
 if(axis==2) z=angle; else if(axis==1) y=angle;
 if(axis==0) x=angle;
 Matrix* original=object->v14();
 Matrix rotation;
 ((owners::Matrix_22bc20 *)&rotation)->FUN_0022bc20(x, y, z);
 ((owners::Obj_22d260 *)&value)->FUN_0022d260((owners::Obj_22d260 *)(Matrix *)(&rotation));
 ((owners::Obj_22d260 *)&value)->FUN_0022d260((owners::Obj_22d260 *)(Matrix *)original);
 ((owners::C_293a90 *)object)->FUN_00293a90((int *)(Vector *)(&value));
}
} // namespace fn_000c59b0

namespace fn_f3173163 {

// 0x000c5a60 FUN_000c5a60 (1 B): matches/0x000c5a60.cpp
// sym: _FUN_000c5a60
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_000c5a60() {}


// 0x000c5a90 FUN_000c5a90 (78 B): matches/0x000c5a90.cpp
// sym: ?Go@Obj_c5a90@fn_f3173163@@QAEPAUTriple_c5a90@2@PAU32@@Z
Triple_c5a90* Obj_c5a90::Go(Triple_c5a90* out) {
    Triple_c5a90 t;
    ((owners::C_284820 *)h)->FUN_00284820((hulk_intptr)0);
    U_c5a90 r = h->FnB_002843a0(c, d);
    ((owners::Obj_2848b0 *)h)->FUN_002848b0((hulk_intptr)r, 0, (int *)(Triple_c5a90 *)(&t));
    *out = t;
    return out;
}


// 0x000c5ae0 FUN_000c5ae0 (71 B): matches/0x000c5ae0.cpp
// sym: ?Fn@Obj@fn_f3173163@@QAEPAUMat@2@PAU32@@Z
Mat* Obj::Fn(Mat* out) {
    Mat m;
    ((owners::C_284820 *)svc)->FUN_00284820((hulk_intptr)0);
    int v = svc->FnB_002843a0(a, b);
    svc->FnC_00284860(v, 0, &m);
    *out = m;
    return out;
}


// 0x000c5b40 FUN_000c5b40 (53 B): matches/0x000c5b40.cpp
// sym: ?f@S_c5b40@fn_f3173163@@QAEXXZ
void S_c5b40::f() {
    if (p) {
        count = 0;
        a = 0;
        *(int*)((char*)this + count * 8 + 8) = 0;
        result = Fng_002961d0(p);
        last = 0;
    }
}


// 0x000c5b80 FUN_000c5b80 (183 B): equivalent/0x000c5b80.cpp
// sym: ?FUN_000c5b80@Walker_c5b80@fn_f3173163@@QAEPAUNode@2@XZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000c5b80 @ 0x000c5b80
Node* Walker_c5b80::FUN_000c5b80() {
 while (current) {
  int size = current->count();
  if (index < size) {
   ++depth;
   if (depth >= 128) return 0;
   stack[depth].node = current;
   stack[depth].index = index;
   Node* next = current->child(index);
   current = next;
   index = 0;
   return next;
  }
  current = stack[depth].node;
  int previous = stack[depth].index;
  index = previous;
  --depth;
  index = previous + 1;
 }
 return current;
}


// 0x000c5c40 FUN_000c5c40 (217 B): equivalent/0x000c5c40.cpp
// sym: ?FUN_000c5c40@fn_f3173163@@YAXPAUObject@1@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c5c40 @ 0x000c5c40
void __cdecl FUN_000c5c40(Object* source,Object* destination) {
 destination->setFirst(source->getFirst());
 destination->setSecond(source->getSecond());
 unsigned int a,b;
 source->getPair(&a,&b);
 destination->setPair(a,b);
 Triple_c5c40 value = source->first;
 ((owners::C_293a90 *)destination)->FUN_00293a90((int *)(Triple_c5c40 *)(&value));
 value = source->second;
 destination->FUN_00293ac0(&value);
 value = source->position;
 ((owners::C_293af0 *)destination)->FUN_00293af0((int *)(Triple_c5c40 *)(&value));
}


// 0x000c5d60 FUN_000c5d60 (87 B): matches/0x000c5d60.cpp
// sym: _FUN_000c5d60
extern "C" bool FUN_000c5d60(Obj_c5d60* obj, int index) {
    int local[41];
    for (int i = 0; i < 1; ++i) {
        Obj_c5d60* p = ((Obj_c5d60 *)((owners::C_af3a0 *)obj)->FUN_000af3a0(i));
        ((owners::C_af0f0 *)p)->FUN_000af0f0(local);
        if (local[index * 3] == 1)
            return true;
    }
    return false;
}


// 0x000c5e60 FUN_000c5e60 (137 B): equivalent/0x000c5e60.cpp
// sym: ?HasEntry@fn_f3173163@@YA_NPAUOwner_c5e60@1@HHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c5e60 @ 0x000c5e60
bool __cdecl HasEntry(Owner_c5e60* owner, int id, int key, int i0, int i1, int i2, int i3) {
    struct Frame { int idx[4]; int buf[41]; } f;
    f.idx[0] = i0; f.idx[1] = i1; f.idx[2] = i2; f.idx[3] = i3;
    owner->FUN_000af3a0(id)->FUN_000af0f0((Entry_c5e60*)f.buf);
    for (int i = 0; i < 4; i++) {
        int k = f.idx[i];
        if (k != -1 && f.buf[k * 3] == key) return true;
    }
    return false;
}


// 0x000c5ef0 FUN_000c5ef0 (67 B): matches/0x000c5ef0.cpp
// sym: _FUN_000c5ef0
extern "C" bool __cdecl FUN_000c5ef0(int a, int b, int c, int d, int e, int f) {
    int i = 0;
    do {
        if (Test_000c5e60(a, i, b, c, d, e, f))
            return true;
        ++i;
    } while (i < 1);
    return false;
}


// 0x000c5f40 FUN_000c5f40 (84 B): matches/0x000c5f40.cpp
// sym: ?fun@fn_f3173163@@YAXPAVObj@1@HHHHHHHH@Z
void fun(Obj* o, int a, int b, int c, int d, int e, int f, int g, int h) {
    o->v->set(a, b, c);
    *o->p = g;
    o->update_0008ef00();
    o->v->set(d, e, f);
    *o->p = h;
    o->update_0008ef00();
}


// 0x000c5fa0 FUN_000c5fa0 (135 B): equivalent/0x000c5fa0.cpp
// sym: ?FUN_000c5fa0@fn_f3173163@@YAXPAUBuffer_c5fa0@1@UVec3_c5fa0@1@1I@Z
// STATUS: equivalent (tools/equiv.py level 3: 2235 inputs, branch coverage 0/0)
// FUN_000c5fa0 @ 0x000c5fa0
// Emits two vertices (a line) with the same colour into the buffer.
// The original builds the first vertex in the (dead) argument slots of the second one;
// the volatile writes keep that, because the tail call hands its argument block on.
void __cdecl FUN_000c5fa0(Buffer_c5fa0 *buffer, Vec3_c5fa0 from, Vec3_c5fa0 to, unsigned int color)
{
    Vec3_c5fa0 second = to;
    volatile Vec3_c5fa0 *slot = &to;
    slot->x = from.x;
    slot->y = from.y;
    slot->z = from.z;
    Emit(buffer, to, color);
    Emit(buffer, second, color);
}


// 0x000c60f0 FUN_000c60f0 (346 B): equivalent/0x000c60f0.cpp
// sym: ?FUN_000c60f0@fn_f3173163@@YAHUVec3_c60f0@1@000IH@Z
// STATUS: equivalent (tools/equiv.py level 3: 16394 inputs, branch coverage 4/4)
// FUN_000c60f0 @ 0x000c60f0
// FUN_000c60f0 @ 0x000c60f0
int FUN_000c60f0(Vec3_c60f0 a, Vec3_c60f0 b, Vec3_c60f0 c, Vec3_c60f0 d, unsigned int color, int count)
{
    if ((*(Resource_c60f0**)&DAT_004dde68) == 0) {
        (*(Resource_c60f0**)&DAT_004dde68) = (*(Factory_c60f0**)&DAT_0052c2a0)->v11("simple", 0);
        (*(Resource_c60f0**)&DAT_004dde68)->v0();
        (*(Resource_c60f0**)&DAT_004dde68)->v6(0x444d4c42, 1);
    }
    Handle *h = DAT_0052c2a8->v30((*(Resource_c60f0**)&DAT_004dde68), count, 0x2020, 8, 0);
    if (h) {
        FUN_000c5fa0(h, a, b, color);
        FUN_000c5fa0(h, b, d, color);
        FUN_000c5fa0(h, d, c, color);
        FUN_000c5fa0(h, c, a, color);
    }
    return DAT_0052c2a8->v31(h);
}


// 0x000c6250 FUN_000c6250 (213 B): equivalent/0x000c6250.cpp
// sym: ?FUN_000c6250@fn_f3173163@@YAHMMMMMMII@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c6250 @ 0x000c6250
int __cdecl FUN_000c6250(float x1, float y1, float unused1, float x2, float y2, float unused2, unsigned int a7, unsigned int a8)
{
    Vec3_c6250 v1, v2, v3, v4;
    v1.x=x1; v1.y=y1; v1.z=0.0f;
    v2.x=x2; v2.y=y1; v2.z=0.0f;
    v3.x=x1; v3.y=y2; v3.z=0.0f;
    v4.x=x2; v4.y=y2; v4.z=0.0f;
    return FUN_000c60f0(v1,v2,v3,v4,a7,a8);
}

} // namespace fn_f3173163

// 0x000c6330 FUN_000c6330 (856 B): equivalent/0x000c6330.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_000c6330@fn_000c6330@@YAXUV3_c6330@1@0000000IH@Z
namespace fn_000c6330 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c6330 @ 0x000c6330
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

struct V3_c6330 {
    float x, y, z;
};

class Shader {
public:
    virtual void AddRef();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void setParam(unsigned int tag, int value);
};

class ShaderLib {
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
    virtual Shader *find(const char *name, int flag);
};

class Prim;

class Gfx {
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
    virtual Prim *begin(Shader *shader, int count, int kind, int stride, int flags);
    virtual void end(Prim *prim);
};


void __cdecl FUN_000c5fa0(Prim *prim, V3_c6330 a, V3_c6330 b, unsigned int color);

void FUN_000c6330(V3_c6330 c0, V3_c6330 c1, V3_c6330 c2, V3_c6330 c3, V3_c6330 c4, V3_c6330 c5, V3_c6330 c6, V3_c6330 c7, unsigned int color, int count)
{
    if ((*(Shader**)&DAT_004dde68) == 0) {
        (*(Shader**)&DAT_004dde68) = (*(ShaderLib**)&DAT_0052c2a0)->find("simple", 0);
        (*(Shader**)&DAT_004dde68)->AddRef();
        (*(Shader**)&DAT_004dde68)->setParam(0x444d4c42, 1);
    }
    Prim *prim = DAT_0052c2a8->begin((*(Shader**)&DAT_004dde68), count, 0x2020, 0x18, 0);
    if (prim) {
        FUN_000c5fa0(prim, c0, c1, color);
        FUN_000c5fa0(prim, c1, c3, color);
        FUN_000c5fa0(prim, c3, c2, color);
        FUN_000c5fa0(prim, c2, c0, color);
        FUN_000c5fa0(prim, c4, c5, color);
        FUN_000c5fa0(prim, c5, c7, color);
        FUN_000c5fa0(prim, c7, c6, color);
        FUN_000c5fa0(prim, c6, c4, color);
        FUN_000c5fa0(prim, c0, c4, color);
        FUN_000c5fa0(prim, c1, c5, color);
        FUN_000c5fa0(prim, c2, c6, color);
        FUN_000c5fa0(prim, c3, c7, color);
    }
    DAT_0052c2a8->end(prim);
}
} // namespace fn_000c6330
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3173163 {

// 0x000c6840 FUN_000c6840 (445 B): equivalent/0x000c6840.cpp
// sym: ?FUN_000c6840@fn_f3173163@@YAXUVec3_c6840@1@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000c6840 @ 0x000c6840
void FUN_000c6840(Vec3_c6840 extent, int a, int b)
{
    float hx = extent.x * 0.5f;
    float hy = extent.y * 0.5f;
    float hz = extent.z * 0.5f;
    Vec3_c6840 c0 = { -hx,  hy, -hz };
    Vec3_c6840 c1 = {  hx,  hy, -hz };
    Vec3_c6840 c2 = { -hx, -hy, -hz };
    Vec3_c6840 c3 = {  hx, -hy, -hz };
    Vec3_c6840 c4 = { -hx,  hy,  hz };
    Vec3_c6840 c5 = {  hx,  hy,  hz };
    Vec3_c6840 c6 = { -hx, -hy,  hz };
    Vec3_c6840 c7 = {  hx, -hy,  hz };
    FUN_000c6330(c0, c1, c2, c3, c4, c5, c6, c7, a, b);
}


// 0x000c6a20 FUN_000c6a20 (69 B): matches/0x000c6a20.cpp
// sym: ?Run@Obj_c6a20@fn_f3173163@@QAEPAV12@PAVArg_c6a20@2@@Z
Obj_c6a20* Obj_c6a20::Run(Arg_c6a20* arg) {
    mArg = arg;
    if (arg) {
        arg->F();
        if (mArg) {
            mIndex = 0;
            mOne = 0;
            ((int*)this)[mIndex * 2 + 2] = 0;
            m408 = mArg->FnG_002961d0();
            m40c = 0;
        }
    }
    return this;
}


// 0x000c6a70 FUN_000c6a70 (22 B): matches/0x000c6a70.cpp
// sym: ?f@C_c6a70@fn_f3173163@@QAEXXZ
// Same code shape as 0x00045820 (propagated; names are from that function)
void C_c6a70::f() {
    if (p) {
        p->b();
        p = 0;
    }
}

} // namespace fn_f3173163
