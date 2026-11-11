// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00201740..0x002036c0 (kind game, layer game, confidence high), dominant class CWorldCollisionManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0f2b8a0 {
#define TREE_TU_END }
namespace fn_f0f2b8a0 {} using namespace fn_f0f2b8a0;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0f2b8a0 {
class Obj_201740 {
  public:
    int a;
    int b;
    int c;
    Obj_201740();
};
class Callee_201750 {
  public:
    void f(unsigned short*, int, int, int);
};
class Obj_201750 {
  public:
    char pad[0x284];
    Callee_201750* member;
    unsigned short f();
};
} // namespace fn_f0f2b8a0
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
namespace fn_f0f2b8a0 {
struct Key_2017d0 {
    unsigned int lo, hi;
};
class Obj_201bd0 {
  public:
    char pad[0x20];
    void Target(hulk_intptr);
};
extern "C" void FUN_00267830(void*, int, int);
struct Inner_201c00 {
};
class Thing_201c00 {
  public:
    char pad[0x18];
    int value;
    char pad2[4];
    Inner_201c00 inner;
    void f();
};
struct Entry_201cd0 { unsigned a,b,c; void FUN_00201740(); };
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
extern void __stdcall FUN_00011520(void*,unsigned,int,void (Entry_201cd0::*)());
struct Array_201cd0 { volatile int count; int capacity; Entry_201cd0* volatile data; unsigned char flags; unsigned char manualCopy; void grow(int n); };
struct Inner_201de0 {
};
class Thing_201de0 {
  public:
    char pad[0x18];
    int value;
    char pad2[4];
    Inner_201de0 inner;
    void f();
};
struct Triple_201e00 { unsigned x,y,z; };
struct Triangle_201e00 { char pad[22]; unsigned short flags; };
struct Mesh_201e00 { char pad[24]; Triangle_201e00* triangles; };
struct Object { char pad[68]; Mesh_201e00* mesh; };
struct Hit_201e00 { char pad0[24]; Triple_201e00 normal; char pad1[20]; Triple_201e00 point; void FUN_002f8e10(Object**, unsigned short*); };
struct Manager_201e00 { char pad[432]; Hit_201e00* begin; Hit_201e00* end; bool FUN_002edb20(Object*, void*, int); };
struct Vec3_201f20 { int x, y, z; };
struct Vec3f { float x, y, z; };
struct Entry24 {
    char pad00[0x16];
    unsigned short flags;
};
struct Info_201f20 {
    char pad00[0x18];
    Entry24* table;
};
struct Owner_201f20 {
    char pad00[0x44];
    Info_201f20* info;
};
struct Item_201f20 {
    char pad00[0x18];
    Vec3f dir;
    float f24;
    char pad28[0x38 - 0x28];
    Vec3_201f20 pos;
    bool FUN_002f8e10(Owner_201f20** owner, int* index);
};
struct Manager_201f20 {
    char pad00[0x1b0];
    Item_201f20* begin;
    Item_201f20* end;
    bool FUN_002edb90(int id, int mode);
};
struct Thing_2020a0 {
    bool FUN_00035a90();
};
struct Actor_2020a0 {
    char pad0[0x114];
    int busy;           // 0x114
    char pad118[0x148 - 0x118];
    Thing_2020a0 *thing;       // 0x148
    bool FUN_001d6980();
    int FUN_001d64a0();
};
struct Target_2020a0 {
    char pad0[8];
    Actor_2020a0 *actor;       // 0x8
    int kind;           // 0xc
    char pad10[0x40];
    float x;            // 0x50
    float y;            // 0x54
    float z;            // 0x58
};
struct Vector_2021f0 {
    float x, y, z;
};
class CWorldCollisionManager_2021f0 {
  public:
    Vector_2021f0 Do(Vector_2021f0);
};
typedef Vector_2021f0 (CWorldCollisionManager_2021f0::*Method_2021f0)(Vector_2021f0);
class Function_2021f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
inline Vector_2021f0 Copy(const Vector_2021f0& v) {
    Vector_2021f0 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}
class Dummy_2022b0 {
  public:
    void Call(void*);
};
class Dummy_2023c0 {
  public:
    void Call(void*);
};
extern "C" char DAT_004259f8[];
struct Head_2023e0 {
    int x, y, z;
    char d, e;
    void C(int);
};
struct Obj_2023e0 {
    int v;
    void A();
};
class CWorldCollisionManager_2023e0 {
  public:
    void* vf;
    char pad4[4];
    Head_2023e0 head;
    int value;
    char pad1c[4];
    Obj_2023e0 part;
    char pad24[4];
    char flag;
};
struct Vec3_202460 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
class Mover_202460 {
public:
    int FUN_00201e00(Vec3_202460 *from, Vec3_202460 *to, int a, int b, int c, int d, int e);
    int FUN_00202460(Vec3_202460 *from, Vec3_202460 *direction, float distance, int a, hulk_intptr b, hulk_intptr c, hulk_intptr d, int e);
};
struct Triple { int x,y,z; };
void __stdcall FUN_00201f20(void* input, int count, Triple* result, void* scratch, int a, int b);
struct Vec3_202560 {
    float x, y, z;
};
struct Quad_202560;
struct Hit_202560 {
    float dist;
    Quad_202560 *quad;
    int tri;
};
struct Quad_202560 {
    char pad0[0x18];
    int material;
};
struct Probe_202560 {
    int f0;
    int f4;
    Hit_202560 *hit;
};
struct Trace {
    char pad0[8];
    Probe_202560 probe;
    char FUN_00201f20(Vec3_202560 *from, int a, Vec3_202560 *out, Vec3_202560 *normal, int *c, int zero);
};
struct Collider_202560 {
    char FUN_002ee140(Probe_202560 *probe, Vec3_202560 *from, Vec3_202560 *to, int zero);
};
struct Bridge {
    char pad0[8];
    Collider_202560 *collider;
};
struct Hud_202560 {
};
} // namespace fn_f0f2b8a0
struct World {
    char pad0[0x10];
    Bridge *bridge;
    char pad14[0xc];
    Hud_202560 *hud;
    Trace *trace;
};
namespace fn_f0f2b8a0 {
char FUN_002020a0(int material);
void FUN_002f1ce0(Vec3_202560 *from, int tri, Vec3_202560 *normal, float *out);
class CActorManager_203010 {
  public:
    void invoke(const char*);
};
class CActorManager_203090 {
  public:
    float Get();
};
typedef float (CActorManager_203090::*Fn_203090)();
class CActorManager_203130 {
  public:
    void invoke(const char*);
};
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f0f2b8a0
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f0f2b8a0 {
class Owner {};
typedef void (Owner::*Fn_203380)(float);
class Registry_203380 { public:
    void FUN_00203380(const char* a1, Owner* a2, Fn_203380 a3);
};
class Closure1_203380 { public: void* FUN_00202fa0(const char*, Owner*, Fn_203380); };


// 0x00201740 FUN_00201740 (13 B): matches/0x00201740.cpp
// sym: ??0Obj_201740@fn_f0f2b8a0@@QAE@XZ
Obj_201740::Obj_201740() {
    a = 0;
    b = 0;
    c = 0;
}


// 0x00201750 FUN_00201750 (29 B): matches/0x00201750.cpp
// sym: ?f@Obj_201750@fn_f0f2b8a0@@QAEGXZ
unsigned short Obj_201750::f() {
    unsigned short local;
    member->f(&local, 1, 2, 1);
    return local;
}


// 0x00201780 FUN_00201780 (79 B): matches/0x00201780.cpp
// sym: _FUN_00201780
// data: gCount = DAT_004c8fb8, gPairs = DAT_004e5928, gValues = DAT_004c8fa4
extern "C" int __cdecl FUN_00201780(hulk_intptr x) {
    __int64 n = FUN_002672f0(x, 0, 0);
    int answer = -1;
    for (int i = 0; i < DAT_004c8fb8; ++i) {
        if (((__int64*)&DAT_004e5928)[i] == n) {
            answer = DAT_004c8fa4[i];
            break;
        }
    }
    return answer;
}


// 0x002017d0 FUN_002017d0 (124 B): equivalent/0x002017d0.cpp
// sym: _FUN_002017d0
// STATUS: equivalent (tools/equiv.py level 3: 123 inputs, branch coverage 8/8)
// FUN_002017d0 @ 0x002017d0
// Looks a property name up in the global key table; outputs its two table values.
extern "C" bool FUN_002017d0(const char *name, int *outIndex, int *outValue)
{
    union {
        unsigned __int64 q;
        unsigned int w[2];
    } h;
    h.q = FUN_002672f0(name, 0, 0);
    int n = DAT_004c8fb8;
    *outValue = 0;
    *outIndex = -1;
    for (int i = 0; i < n; i++) {
        if (((Key_2017d0*)&DAT_004e5928)[i].lo == h.w[0] && ((Key_2017d0*)&DAT_004e5928)[i].hi == h.w[1]) {
            *outValue = DAT_004c8f90[i];
            *outIndex = DAT_004c8fa4[i];
            return true;
        }
    }
    return false;
}


// 0x00201bb0 FUN_00201bb0 (1 B): matches/0x00201bb0.cpp
// sym: ?FUN_00201bb0@fn_f0f2b8a0@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00201bb0() {}

} // namespace fn_f0f2b8a0

// 0x00201bc0 FUN_00201bc0 (10 B): matches/0x00201bc0.cpp
// sym: ?FUN_00201bc0@C_201bc0@owners@@QAEXH@Z
void owners::C_201bc0::FUN_00201bc0(int x) {
    m18 = x;
}

namespace fn_f0f2b8a0 {

// 0x00201bd0 FUN_00201bd0 (8 B): matches/0x00201bd0.cpp
// sym: ?Target@Obj_201bd0@fn_f0f2b8a0@@QAEXH@Z
void Obj_201bd0::Target(hulk_intptr a0) {
    char* p = (char*)this;
    p += 0x20;
    ((owners::Target_27b040 *)(((Obj_201bd0*)p)))->FUN_0027b040((hulk_uintptr)a0);
}

} // namespace fn_f0f2b8a0

// 0x00201be0 FUN_00201be0 (22 B): matches/0x00201be0.cpp
// sym: ?FUN_00201be0@X_201be0@owners@@QAEXH@Z
void owners::X_201be0::FUN_00201be0(hulk_intptr value) {
    FUN_00267830((char*)this + 0x28, ((int)value), 0x40);
}

namespace fn_f0f2b8a0 {

// 0x00201c00 FUN_00201c00 (26 B): matches/0x00201c00.cpp
// sym: ?f@Thing_201c00@fn_f0f2b8a0@@QAEXXZ
void Thing_201c00::f() {
    value = 0xc61c4000;
    ((owners::Target_27b040 *)&inner)->FUN_0027b040((hulk_uintptr)0);
    ((char*)this)[0x28] = 0;
}


// 0x00201cd0 FUN_00201cd0 (199 B): equivalent/0x00201cd0.cpp
// sym: ?grow@Array_201cd0@fn_f0f2b8a0@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 267 inputs, branch coverage 15/16, incomplete)
// FUN_00201cd0 @ 0x00201cd0
void Array_201cd0::grow(int n) {
 if(n==0) n=2;
 if(capacity>=n) return;
 unsigned* allocation=(unsigned*)FUN_0008d6d0((unsigned)n*12+4);
 Entry_201cd0* replacement=0;
 if(allocation) { allocation[0]=n; replacement=(Entry_201cd0*)(allocation+1); FUN_00011520(replacement,12,n,&Entry_201cd0::FUN_00201740); }
 int oldCount=count;
 if(oldCount>0) {
  if(manualCopy) { for(int i=0;i<count;++i) { volatile Entry_201cd0* src=data+i; volatile Entry_201cd0* dest=replacement+i; dest->a=src->a; dest->b=src->b; dest->c=src->c; } }
  else { volatile unsigned* dest=(unsigned*)replacement; volatile unsigned* src=(unsigned*)data; unsigned words=((unsigned)oldCount*12)>>2; for(unsigned j=0;j<words;++j) dest[j]=src[j]; }
 }
 Entry_201cd0* previous=data;
 if(previous) FUN_0008d340((unsigned*)previous-1);
 data=replacement; capacity=n;
}


// 0x00201de0 FUN_00201de0 (26 B): matches/0x00201de0.cpp
// sym: ?f@Thing_201de0@fn_f0f2b8a0@@QAEXXZ
// Same code shape as 0x00201c00 (propagated; names are from that function)
void Thing_201de0::f() {
    value = 0xc61c4000;
    ((owners::Target_27b040 *)&inner)->FUN_0027b040((hulk_uintptr)0);
    ((char*)this)[0x28] = 0;
}


// 0x00201e00 FUN_00201e00 (287 B): equivalent/0x00201e00.cpp
// sym: ?FUN_00201e00@fn_f0f2b8a0@@YG_NPAUObject@1@PAXIPAUTriple_201e00@1@2PAPAUTriangle_201e00@1@PAPAU21@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 16/16)
// FUN_00201e00 @ 0x00201e00
bool __stdcall FUN_00201e00(Object* object, void* query, unsigned mask, Triple_201e00* point, Triple_201e00* normal, Triangle_201e00** triangleOut, Object** objectOut) {
 if(triangleOut) *triangleOut=0;
 if(objectOut) *objectOut=0;
 Manager_201e00* manager=(*(Manager_201e00**)&DAT_00554c14);
 if(!manager->FUN_002edb20(object,query,10)) return false;
 hulk_uintptr count=(manager->end-manager->begin);
 if(!count) return false;
 for(unsigned i=0;i<count;++i) {
  unsigned short index;
  manager->begin[i].FUN_002f8e10(&object,&index);
  Triangle_201e00* triangle=&object->mesh->triangles[index];
  if(!(mask & (triangle->flags >> 3))) {
   Triple_201e00* src=&manager->begin[i].point;
   point->x=src->x; point->y=src->y; point->z=src->z;
   src=&manager->begin[i].normal;
   normal->x=src->x; normal->y=src->y; normal->z=src->z;
   if(triangleOut) *triangleOut=triangle;
   if(objectOut) *objectOut=object;
   return true;
  }
 }
 return false;
}


// 0x00201f20 FUN_00201f20 (378 B): equivalent/0x00201f20.cpp
// sym: ?FUN_00201f20@fn_f0f2b8a0@@YG_NHHPAUVec3_201f20@1@0PAPAUEntry24@1@PAPAUOwner_201f20@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 19/20, incomplete)
// FUN_00201f20 @ 0x00201f20
bool __stdcall FUN_00201f20(int id, int mask, Vec3_201f20* outPos, Vec3_201f20* outDir, Entry24** outEntry, Owner_201f20** outOwner)
{
    if (outEntry)
        *outEntry = 0;
    if (outOwner)
        *outOwner = 0;
    Manager_201f20* mgr = (*(Manager_201f20**)&DAT_00554c14);
    if (!mgr->FUN_002edb90(id, 10))
        return false;
    unsigned int count = (unsigned int)(mgr->end - mgr->begin);
    struct Frame { int index; Entry24* entry; int pad; Owner_201f20* owner; } f;
    for (unsigned int i = 0; i < count; i++) {
        Item_201f20* item = &mgr->begin[i];
        if (item->f24 < 0.0f)
            continue;
        item->FUN_002f8e10(&f.owner, &f.index);
        Entry24* e = &f.owner->info->table[(unsigned short)f.index];
        f.entry = e;
        if (mask & (e->flags >> 3))
            continue;
        item = &mgr->begin[i];
        float s = item->dir.z * 0.0f + item->dir.y * -1.0f + item->dir.x * 0.0f;
        if (s > 0.0f)
            continue;
        item = &mgr->begin[i];
        *outPos = item->pos;
        item = &mgr->begin[i];
        outDir->x = *(int*)&item->dir.x;
        outDir->y = *(int*)&item->dir.y;
        outDir->z = *(int*)&item->dir.z;
        if (outEntry)
            *outEntry = f.entry;
        if (outOwner)
            *outOwner = f.owner;
        return true;
    }
    return false;
}


// 0x002020a0 FUN_002020a0 (149 B): equivalent/0x002020a0.cpp
// sym: ?FUN_002020a0@fn_f0f2b8a0@@YA_NPAUTarget_2020a0@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 18/18)
// FUN_002020a0 @ 0x002020a0
bool FUN_002020a0(Target_2020a0 *t)
{
    if (t == 0)
        return false;
    if (sqrt(t->x * t->x + t->y * t->y + t->z * t->z) > 5.0f)
        return false;
    if (t->kind != 5)
        return false;
    Actor_2020a0 *a = t->actor;
    if (a == 0)
        return false;
    if (a->FUN_001d6980())
        return false;
    if (a->busy != 0)
        return false;
    if (a->thing != 0)
        return !a->thing->FUN_00035a90();
    switch (a->FUN_001d64a0()) {
    case 1: case 5: case 12: case 13: case 15: case 16: case 20: case 21:
        return false;
    case 0: case 2: case 3: case 4: case 6: case 7: case 8: case 9: case 10: case 11:
    case 14: case 17: case 18: case 19: case 22:
        return true;
    default:
        return false;
    }
}

} // namespace fn_f0f2b8a0

// 0x002021d0 Method1<CWorldCollisionManager,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x002021d0.cpp
// sym: ??_G?$Method1@VCWorldCollisionManager@@VVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CWorldCollisionManager,math::Vector,math::Vector>::~Method1() {}


// 0x002021f0 Method1<CWorldCollisionManager,math::Vector,math::Vector>::vfunc_2 (90 B): matches/0x002021f0.cpp
// sym: ?vfunc_2@?$Method1@VCWorldCollisionManager@@VVector@math@@V23@@@UAEXPAX00@Z
template <> void Method1<CWorldCollisionManager,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldCollisionManager_2021f0 * obj = (CWorldCollisionManager_2021f0 *)__p0; const Vector_2021f0 * arg = (const Vector_2021f0 *)__p1; Vector_2021f0 * out = (Vector_2021f0 *)__p2;

    Method_2021f0 m = (*(Method_2021f0 *)&this->f_1c);
    Vector_2021f0 v = Copy((obj->*m)(*arg));
    if (out)
        *out = v;
}


// 0x00202290 Method1<CWorldCollisionManager,void,float>::vfunc_0 (30 B): matches/0x00202290.cpp
// sym: ??_G?$Method1@VCWorldCollisionManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CWorldCollisionManager, void, float>::~Method1() {}


// 0x002022b0 Method1<CWorldCollisionManager,void,float>::vfunc_2 (19 B): matches/0x002022b0.cpp
// sym: ?vfunc_2@?$Method1@VCWorldCollisionManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CWorldCollisionManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2022b0* d = (Dummy_2022b0*)a;
    (d->*(*(void (Dummy_2022b0::**)(void *))&this->f_1c))(*b);
}


// 0x00202310 Method0<CWorldCollisionManager,float>::vfunc_0 (30 B): matches/0x00202310.cpp
// sym: ??_G?$Method0@VCWorldCollisionManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CWorldCollisionManager, float>::~Method0() {}


// 0x00202330 Method0<CWorldCollisionManager,float>::vfunc_2 (34 B): matches/0x00202330.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_202330@fn_00202330@@UAEXPAX0PAM@Z
namespace fn_00202330 {
// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_202330 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_202330::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_00202330


// 0x002023a0 Method1<CWorldCollisionManager,void,const_char_*>::vfunc_0 (30 B): matches/0x002023a0.cpp
// sym: ??_G?$Method1@VCWorldCollisionManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CWorldCollisionManager, void, const char *>::~Method1() {}


// 0x002023c0 Method1<CWorldCollisionManager,void,const_char_*>::vfunc_2 (19 B): matches/0x002023c0.cpp
// sym: ?vfunc_2@?$Method1@VCWorldCollisionManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CWorldCollisionManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2023c0* d = (Dummy_2023c0*)a;
    (d->*(*(void (Dummy_2023c0::**)(void *))&this->f_1c))(*b);
}

namespace fn_f0f2b8a0 {

// 0x002023e0 FUN_002023e0 (79 B): matches/0x002023e0.cpp
// sym: ?FUN_002023e0@fn_f0f2b8a0@@YIPAVCWorldCollisionManager_2023e0@1@PAV21@PAX@Z
// data: global64 = DAT_004d293c
CWorldCollisionManager_2023e0* __fastcall FUN_002023e0(CWorldCollisionManager_2023e0* s, void*) {
    Head_2023e0* h = &s->head;
    s->vf = (void*)((hulk_intptr)DAT_004259f8);
    h->x = 0;
    h->y = 0;
    h->z = 0;
    h->d = 0;
    h->e = 0;
    s->part.A();
    s->value = (int)0xc61c4000;
    ((owners::Target_27b040 *)&(s->part))->FUN_0027b040((hulk_uintptr)0);
    s->flag = 0;
    h->C(DAT_004d293c);
    return s;
}

} // namespace fn_f0f2b8a0

// 0x00202430 FUN_00202430 (38 B): matches/0x00202430.cpp [wrapped: conflict: CWorldCollisionManager]
// sym: ?Init@CWorldCollisionManager@fn_00202430@@QAEXXZ
namespace fn_00202430 {
class Helper_202430 {
  public:
    void Init();
};
extern void* vtable_202430;
void __cdecl thunk_FUN_00267090(void*);
class CWorldCollisionManager {
  public:
    void* vft;
    char pad4[12];
    void* ptr;
    char pad14[12];
    Helper_202430 helper;
    void Init();
};
void CWorldCollisionManager::Init() {
    vft = &vtable_202430;
    helper.Init();
    if (ptr)
        thunk_FUN_00267090((char*)ptr - 4);
}
} // namespace fn_00202430

namespace fn_f0f2b8a0 {

// 0x00202460 FUN_00202460 (160 B): equivalent/0x00202460.cpp
// sym: ?FUN_00202460@Mover_202460@fn_f0f2b8a0@@QAEHPAUVec3_202460@2@0MHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_00202460 @ 0x00202460
// FUN_00202460 @ 0x00202460
// FUN_00202460 @ 0x00202460: forwards a point offset along a normalised direction to FUN_00201e00
int Mover_202460::FUN_00202460(Vec3_202460 *from, Vec3_202460 *direction, float distance, int a, hulk_intptr b, hulk_intptr c, hulk_intptr d, int e)
{
    Vec3_202460 dir = *direction;
    dir.FUN_0022d110();
    Vec3_202460 to;
    to.x = dir.x * distance + from->x;
    to.y = dir.y * distance + from->y;
    to.z = dir.z * distance + from->z;
    return FUN_00201e00(from, &to, a, b, c, d, e);
}


// 0x00202500 FUN_00202500 (84 B): equivalent/0x00202500.cpp
// sym: ?FUN_00202500@fn_f0f2b8a0@@YGXPAUTriple@1@U21@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_00202500 @ 0x00202500
void __stdcall FUN_00202500(Triple* output, Triple a)
{
    Triple result = {0,0,0};
    char scratch[12];
    FUN_00201f20(&a, 1, &result, scratch, 0, 0);
    *output = result;
}


// 0x00202560 FUN_00202560 (602 B): equivalent/0x00202560.cpp
// sym: _FUN_00202560
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 20/20)
// FUN_00202560 @ 0x00202560
extern "C" char FUN_00202560(Vec3_202560 *start, float depth, int a3, Vec3_202560 *result, Vec3_202560 *normalOut,
                  Vec3_202560 *fallback, int *materialOut, int *c)
{
    World *g = DAT_004dd700;
    Trace *trace = g->trace;
    if (materialOut != 0)
        *materialOut = 0;

    result->x = start->x;
    result->y = start->y;
    result->z = start->z;
    result->y = -3.4028235e+38f;

    char ok = trace->FUN_00201f20(start, a3, result, normalOut, c, 0);
    if (fallback != 0) {
        if (ok) {
            fallback->x = result->x;
            fallback->y = result->y;
            fallback->z = result->z;
        } else {
            fallback->x = start->x;
            fallback->y = start->y;
            fallback->z = start->z;
            fallback->y = -3.4028235e+38f;
        }
    }

    trace->probe.f0 = 0;
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 1;
    (*(float*)&DAT_00554c18) = 0.2f;
    ((owners::Target_25370 *)(g->hud))->FUN_00025370(0);

    float zero = depth * 0.0f;
    Vec3_202560 to;
    to.y = -depth;
    to.z = zero;
    to.x = zero + start->x;
    to.y = to.y + start->y;
    to.z = to.z + start->z;

    if (g->bridge->collider->FUN_002ee140(&trace->probe, start, &to, 0)) {
        Hit_202560 *hit = trace->probe.hit;
        float dist = hit->dist;
        Quad_202560 *quad = hit->quad;
        int tri = hit->tri;
        if (dist > 0.0f && FUN_002020a0(quad->material)) {
            Vec3_202560 n;
            float out = 0.0f;
            FUN_002f1ce0(start, tri, &n, &out);
            if ((n.z * 0.0f + n.x * 0.0f) + n.y > 0.5f) {
                float w = out * 0.0f;
                float px = w + start->x;
                float py = -out + start->y;
                float pz = w + start->z;
                if (py > result->y) {
                    result->x = px;
                    result->y = py;
                    result->z = pz;
                    normalOut->x = n.x;
                    normalOut->y = n.y;
                    normalOut->z = n.z;
                    if (materialOut != 0)
                        *materialOut = quad->material;
                    if (c != 0)
                        *c = 0;
                    ok = 1;
                }
            }
        }
    }
    ((owners::C_25260 *)(g->hud))->FUN_00025260(1, 0, 0);
    return ok;
}

} // namespace fn_f0f2b8a0

// 0x002027c0 FUN_002027c0 (531 B): equivalent/0x002027c0.cpp [wrapped: conflict: DAT_004dd700; World]
// sym: _FUN_002027c0
namespace fn_002027c0 {
// STATUS: equivalent (tools/equiv.py level 3: 19987 inputs, branch coverage 16/16)
// FUN_002027c0 @ 0x002027c0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


struct V3_2027c0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(V3_2027c0 *other, float epsilon);
};

struct Info;

struct Node {
    char pad00[0x18];
    Info *info;
};

struct Hit_2027c0 {
    float scale;
    Node *node;
    int value;
};

struct HitList_2027c0 {
    int count;
    int pad04;
    Hit_2027c0 *hits;
};

struct Probe_2027c0 {
    char pad00[8];
    HitList_2027c0 list;
    bool FUN_00201e00(V3_2027c0 *a, V3_2027c0 *b, int c, V3_2027c0 *d, V3_2027c0 *e, int *f, int g);
};

struct World {
    bool FUN_002ee140(HitList_2027c0 *list, V3_2027c0 *a, V3_2027c0 *b, int c);
};

struct Camera {
};

struct Holder_2027c0 {
    char pad00[8];
    World *world;
};

struct Game_2027c0 {
    char pad00[0x10];
    Holder_2027c0 *holder;
    char pad14[0x20 - 0x14];
    Camera *camera;
    Probe_2027c0 *probe;
};


#define DAT_004dd700 (*(Game_2027c0 * *)&::DAT_004dd700)


void FUN_002f1ce0(V3_2027c0 *a, int value, V3_2027c0 *b, int *outv);

extern "C" bool FUN_002027c0(V3_2027c0 *from, V3_2027c0 *to, float radius, int a4, V3_2027c0 *a5, V3_2027c0 *a6, int *a7, int *a8)
{
    struct Frame {
        char pad00[3];
        bool hit1;
        Game_2027c0 *game;
        float dist;
        int tmp;
        Info *info;
        V3_2027c0 q;
    } fr;

    if (from->FUN_0022d2b0(to, 1e-5f))
        return false;

    fr.game = DAT_004dd700;
    Probe_2027c0 *probe = fr.game->probe;
    if (a7)
        *a7 = 0;
    fr.hit1 = probe->FUN_00201e00(from, to, a4, a5, a6, a8, 0);
    fr.dist = 3.4028235e38f;
    if (fr.hit1) {
        fr.q = *a5;
        hulk_freg dx = fr.q.x - from->x;
        hulk_freg dy = fr.q.y - from->y;
        hulk_freg dz = fr.q.z - from->z;
        fr.dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }

    probe->list.count = 0;
    HitList_2027c0 *list = &probe->list;
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 1;
    (*(float*)&DAT_00554c18) = radius;
    ((owners::C_25260 *)(fr.game->camera))->FUN_00025260(0, 0, 0);

    bool result = fr.hit1;
    if (fr.game->holder->world->FUN_002ee140(list, from, to, 0)) {
        Hit_2027c0 *h = list->hits;
        hulk_freg t = h->scale;
        Node *node = h->node;
        int value = h->value;
        fr.q.x = t;
        if (t > 0.0f && t < fr.dist) {
            fr.info = node->info;
            *a5 = *to;
            a5->x = a5->x - from->x;
            a5->y = a5->y - from->y;
            a5->z = a5->z - from->z;
            a5->FUN_0022d110();
            fr.tmp = 0;
            hulk_freg px = fr.q.x * a5->x;
            hulk_freg py = fr.q.x * a5->y;
            hulk_freg pz = fr.q.x * a5->z;
            a5->x = px;
            a5->y = py;
            a5->z = pz;
            a5->x = px + from->x;
            a5->y = py + from->y;
            a5->z = pz + from->z;
            FUN_002f1ce0(from, value, a6, &fr.tmp);
            if (a7)
                *(hulk_intptr*)a7 = (hulk_intptr)fr.info;
            if (a8)
                *a8 = 0;
            result = true;
        }
    }
    ((owners::C_25260 *)(fr.game->camera))->FUN_00025260(1, 0, 0);
    return result;
}
} // namespace fn_002027c0
#undef DAT_004dd700


// 0x002029e0 FUN_002029e0 (581 B): equivalent/0x002029e0.cpp [wrapped: conflict: Node; World]
// sym: _FUN_002029e0
namespace fn_002029e0 {
// STATUS: equivalent (tools/equiv.py level 3: 19948 inputs, branch coverage 21/22, incomplete)
// FUN_002029e0 @ 0x002029e0
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


struct Vec3_2029e0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Flagged_2029e0 {
    char pad00[0x72];
    char hidden;            // 0x72
};

struct Actor_2029e0 {
    char pad00[0xa9];
    char ghost;             // 0xa9
};

struct Fighter_2029e0 {
    char pad00[0x11c];
    Actor_2029e0* actor;           // 0x11c
};

struct Node {
    char pad00[8];
    Fighter_2029e0* fighter;       // 0x08
    int kind;               // 0x0c
    char pad10[0x74 - 0x10];
    Flagged_2029e0* blocker;       // 0x74
};

struct Entity {
    char pad00[0x18];
    Node* node;             // 0x18
};

struct Body_2029e0 {
    int dummy;
};

struct SweepEntry_2029e0 {
    float t;                // 0x00
    Entity* entity;         // 0x04
    Body_2029e0* body;             // 0x08
};

struct SweepList_2029e0 {
    int count;              // 0x00
    char pad04[4];
    SweepEntry_2029e0* entries;    // 0x08
};

struct Sweeper_2029e0 {
    bool FUN_002ee140(SweepList_2029e0* list, Vec3_2029e0* from, Vec3_2029e0* to, int flags);
};

struct Space_2029e0 {
    char pad00[8];
    SweepList_2029e0 list;         // 0x08
    bool FUN_00201e00(Vec3_2029e0* from, Vec3_2029e0* to, int mode, Vec3_2029e0* outPoint, Vec3_2029e0* outNormal,
                      void* out1, void* out2);
};

struct Hub_2029e0 {
    char pad00[8];
    Sweeper_2029e0* sweeper;       // 0x08
};

struct Notifier_2029e0 {
};

struct World {
    char pad00[0x10];
    Hub_2029e0* hub;               // 0x10
    char pad14[0x20 - 0x14];
    Notifier_2029e0* notifier;     // 0x20
    Space_2029e0* space;           // 0x24
};

// the callee's out-parameter block: its contents are visible to the callee
struct Contact_2029e0 {
    int zero;
    float t;
    float py;
    Body_2029e0* body;
};


void FUN_002f1ce0(Vec3_2029e0* from, Body_2029e0* body, Vec3_2029e0* outNormal, Contact_2029e0* contact);

extern "C" bool FUN_002029e0(Vec3_2029e0* from, Vec3_2029e0* to, int tag, int mode, Vec3_2029e0* outPoint, Vec3_2029e0* outNormal)
{
    World* world = DAT_004dd700;
    Space_2029e0* space = world->space;
    Flagged_2029e0* hidden[8];
    Contact_2029e0 contact;
    int hiddenCount;
    hulk_freg dist;

    bool result = space->FUN_00201e00(from, to, mode, outPoint, outNormal, 0, 0);
    dist = 3.40282347e+38f;
    if (result) {
        hulk_freg dx = outPoint->x - from->x;
        hulk_freg dy = outPoint->y - from->y;
        hulk_freg dz = outPoint->z - from->z;
        contact.py = outPoint->y;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }

    space->list.count = 0;
    SweepList_2029e0* list = &space->list;
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 1;
    DAT_00554c18 = tag;
    ((owners::C_25260 *)(world->notifier))->FUN_00025260(0, 0, 0);

    Sweeper_2029e0* sweeper = world->hub->sweeper;
    hiddenCount = 0;
    if (sweeper->FUN_002ee140(list, from, to, 0)) {
        for (;;) {
            SweepEntry_2029e0* e = list->entries;
            hulk_freg t = e->t;
            Entity* entity = e->entity;
            Body_2029e0* body = e->body;
            if (!(t > 0.0f))
                break;
            if (!(t < dist))
                break;

            Node* node = entity->node;
            bool passThrough;
            if (node->kind == 5)
                passThrough = node->fighter->actor->ghost != 0;
            else
                passThrough = node->kind == 7;

            if (passThrough && hiddenCount < 8) {
                Flagged_2029e0* f = node->blocker;
                hidden[hiddenCount] = f;
                hiddenCount++;
                f->hidden = 0;
                if (sweeper->FUN_002ee140(list, from, to, 0))
                    continue;
                break;
            }

            // first solid contact: point = from + t * normalize(to - from); report it and stop
            outPoint->x = to->x;
            outPoint->y = to->y;
            outPoint->z = to->z;
            outPoint->x = outPoint->x - from->x;
            outPoint->y = outPoint->y - from->y;
            outPoint->z = outPoint->z - from->z;
            outPoint->FUN_0022d110();
            contact.zero = 0;
            contact.t = t;
            contact.body = body;
            hulk_freg tx = t * outPoint->x;
            hulk_freg ty = t * outPoint->y;
            hulk_freg tz = t * outPoint->z;
            outPoint->x = tx;
            outPoint->y = ty;
            outPoint->z = tz;
            outPoint->x = tx + from->x;
            outPoint->y = ty + from->y;
            outPoint->z = tz + from->z;
            FUN_002f1ce0(from, body, outNormal, &contact);
            result = true;
            break;
        }
    }

    while (hiddenCount > 0) {
        Flagged_2029e0* f = hidden[hiddenCount - 1];
        hiddenCount--;
        f->hidden = 1;
    }
    ((owners::C_25260 *)(world->notifier))->FUN_00025260(1, 0, 0);
    return result;
}
} // namespace fn_002029e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00202c30 FUN_00202c30 (711 B): equivalent/0x00202c30.cpp [wrapped: conflict: World]
// sym: ?FUN_00202c30@fn_00202c30@@YA_NPAUV3_202c30@1@0HH00PAPAUShape_202c30@1@PAU31@DPAUProbe_202c30@1@@Z
namespace fn_00202c30 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 32/32)
// FUN_00202c30 @ 0x00202c30
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


struct V3_202c30 {
    float x, y, z;
    float FUN_0022d110();
};

struct Info_202c30 {
    char pad0[0xa9];
    char flagA9;
};

struct Ent_202c30 {
    char pad0[0x11c];
    Info_202c30 *info;
};

struct Shape_202c30 {
    char pad0[8];
    Ent_202c30 *ent;           // 8
    int kind;           // 0xc
    char pad10[0x62];
    char b72;
    char pad73;
    Shape_202c30 *f74;
};

struct Node {
    char pad0[0x18];
    Shape_202c30 *shape;
};

struct Rec_202c30 {
    float t;
    Node *node;
    float c;
};

struct HitList_202c30 {
    int count;
    char pad4[4];
    Rec_202c30 *recs;          // 8
};

struct Caster_202c30 {
    char pad0[8];
    HitList_202c30 list;       // 8
    bool FUN_00201e00(V3_202c30 *origin, V3_202c30 *end, int mask, V3_202c30 *hit, V3_202c30 *normal, void **out1, void **out2);
};

struct Holder_202c30 {
    char pad0[0x1b0];
    int f1b0;
};

struct Probe_202c30 {
    char pad0[0x11c];
    Holder_202c30 *holder;
    void FUN_000368d0(int v);
};

struct World20_202c30 {
    void FUN_00025260(int a, int b, int c);
    void FUN_00025310(int a, int b);
};

struct Scene_202c30 {
    bool FUN_002ee140(HitList_202c30 *list, V3_202c30 *origin, V3_202c30 *end, int z);
};

struct Sub10_202c30 {
    char pad0[8];
    Scene_202c30 *scene;
};

struct World {
    char pad0[0x10];
    Sub10_202c30 *sub10;
    char pad14[0xc];
    World20_202c30 *w20;       // 0x20
    Caster_202c30 *caster;     // 0x24
};

void __cdecl FUN_002f1ce0(V3_202c30 *origin, float c, V3_202c30 *normal, int *slot);

bool FUN_00202c30(V3_202c30 *origin, V3_202c30 *end, int a3, int mask, V3_202c30 *hit, V3_202c30 *normal, Shape_202c30 **shapeOut, Shape_202c30 *skip,
                  char flag, Probe_202c30 *probe)
{
    Shape_202c30 *saved[8];
    World *w = DAT_004dd700;
    Caster_202c30 *caster = w->caster;
    if (shapeOut != 0)
        *shapeOut = 0;
    bool result = caster->FUN_00201e00(origin, end, mask, hit, normal, 0, 0);
    float dist = 3.4028235e38f;
    if (result) {
        float ax = hit->x;
        float ay = hit->y;
        float az = hit->z;
        double dx = ax - origin->x;
        double dy = ay - origin->y;
        double dz = az - origin->z;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }
    caster->list.count = 0;
    HitList_202c30 *list = &caster->list;
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 1;
    DAT_00554c18 = a3;
    w->w20->FUN_00025260(0, 0, 0);
    if (flag != 0 && probe != 0) {
        w->w20->FUN_00025310(probe->holder->f1b0, 1);
        probe->FUN_000368d0(0);
    }
    Scene_202c30 *scene = w->sub10->scene;
    int count = 0;
    if (scene->FUN_002ee140(list, origin, end, 0)) {
        for (;;) {
            Rec_202c30 *r = list->recs;
            float t = r->t;
            Node *node = r->node;
            float c = r->c;
            if (!(t > 0.0f))
                break;
            if (!(t < dist))
                break;
            Shape_202c30 *shape = node->shape;
            if (shape != skip) {
                bool requery = false;
                int kind = shape->kind;
                if (kind == 5)
                    requery = shape->ent->info->flagA9 != 0;
                else if (kind == 7)
                    requery = true;
                if (requery && count < 8) {
                    Shape_202c30 *s2 = shape->f74;
                    saved[count] = s2;
                    count++;
                    s2->b72 = 0;
                    if (scene->FUN_002ee140(list, origin, end, 0))
                        continue;
                    break;
                }
            }
            *hit = *end;
            hit->x = hit->x - origin->x;
            hit->y = hit->y - origin->y;
            hit->z = hit->z - origin->z;
            hit->FUN_0022d110();
            double px = hit->x * t;
            hit->x = (float)px;
            double py = hit->y * t;
            hit->y = (float)py;
            double pz = hit->z * t;
            volatile float tz = (float)pz;
            hit->z = (float)pz;
            hit->x = (float)(px + origin->x);
            hit->y = (float)(py + origin->y);
            hit->z = tz + origin->z;
            a3 = 0;
            FUN_002f1ce0(origin, c, normal, &a3);
            if (shapeOut != 0)
                *shapeOut = shape;
            result = true;
            break;
        }
    }
    while (count > 0) {
        Shape_202c30 *s = saved[count - 1];
        count--;
        s->b72 = 1;
    }
    w->w20->FUN_00025260(1, 0, 0);
    return result;
}
} // namespace fn_00202c30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00202f00 FUN_00202f00 (18 B): matches/0x00202f00.cpp [wrapped: conflict: World]
// sym: _FUN_00202f00
namespace fn_00202f00 {
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

struct Inner {
    char pad[8];
    int value;
};
struct World {
    char pad[0x24];
    Inner* inner;
};
extern "C" int* FUN_00202f00() {
    Inner* p = DAT_004dd700->inner;
    p->value = 0;
    return &p->value;
}
} // namespace fn_00202f00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00202f20 FUN_00202f20 (76 B): matches/0x00202f20.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_00202f20@@QAE@PAX00@Z
namespace fn_00202f20 {
typedef unsigned char u8;
extern u8 __cdecl query(const char*);
extern const char label[];
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
};
class Closure1_202f20 : public Base {
  public:
    Closure1_202f20(void*, void*, void*);
    virtual void f();
    u8 a;
    char gap[7];
    u8 b;
    char gap2[3];
    void* p;
};
class Closure1 : public Closure1_202f20 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* q;
};
Closure1_202f20::Closure1_202f20(void* x, void* y, void* z) : Base(x, 1) {
    p = z;
    b = query(label);
    a = query(label);
}
Closure1::Closure1(void* x, void* y, void* z) : Closure1_202f20(x, y, z) {
    q = y;
}
} // namespace fn_00202f20


// 0x00202f70 Closure1<CWorldCollisionManager,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x00202f70.cpp
// sym: ??_G?$Method1@VCWorldCollisionManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CWorldCollisionManager,math::Vector,math::Vector>::~Closure1() {}


// 0x00202f90 Closure1<CWorldCollisionManager,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x00202f90.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_00202f90@@UAEXHHH@Z
namespace fn_00202f90 {
// Same code shape as 0x0002ff10 (propagated; names are from that function)
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_00202f90


// 0x00202fa0 FUN_00202fa0 (76 B): matches/0x00202fa0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_00202fa0@@QAE@HHH@Z
namespace fn_00202fa0 {
// data: key1 = DAT_0048e100, key2 = DAT_0048e128

extern "C++" __declspec(nothrow) unsigned char __cdecl Check(const char*);
class Function_202fa0 {
  public:
    Function_202fa0(int, int);
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
};
class Method1 : public Function_202fa0 {
  public:
    Method1(int p, int x) : Function_202fa0(p, 1) {
        this->x = x;
        b = Check(((char*)&DAT_0048e100));
        a = Check(((char*)&DAT_0048e128));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(hulk_intptr p, hulk_intptr y, hulk_intptr x);
    virtual void f();
    int y;
};
Closure1::Closure1(hulk_intptr p, hulk_intptr y, hulk_intptr x) : Method1(p, x) {
    this->y = y;
}
} // namespace fn_00202fa0


// 0x00202ff0 Closure1<CWorldCollisionManager,void,float>::vfunc_0 (30 B): matches/0x00202ff0.cpp
// sym: ??_G?$Method1@VCWorldCollisionManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CWorldCollisionManager, void, float>::~Closure1() {}


// 0x00203010 Closure1<CWorldCollisionManager,void,float>::vfunc_2 (18 B): matches/0x00203010.cpp
// sym: ?vfunc_2@?$Closure1@VCWorldCollisionManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CWorldCollisionManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_203010 * *)&this->f_20)->*(*(void (CActorManager_203010::**)(const char *))&this->f_1c))(*b);
}


// 0x00203090 Closure0<CWorldCollisionManager,float>::vfunc_2 (35 B): matches/0x00203090.cpp
// sym: ?vfunc_2@?$Closure0@VCWorldCollisionManager@@M@@UAEXPAX00@Z
// Same code shape as 0x0002fe60 (propagated; names are from that function)
template <> void Closure0<CWorldCollisionManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_203090* m = (*(CActorManager_203090 * *)&this->f_20);
    Fn_203090 fn = (*(Fn_203090 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}


// 0x002030c0 FUN_002030c0 (76 B): matches/0x002030c0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_002030c0@@QAE@PBDPAVCWorldCollisionManager@1@P8ScriptBoundClass@@AEXXZ@Z
namespace fn_002030c0 {
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

class CWorldCollisionManager;
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2030c0 : public CtorV_001d0480 {
  public:
    Function_2030c0(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_2030c0 {
  public:
    virtual void Invoke();
    ScriptMemberFn fn;  // 0x1c
    Method1(const char* s, ScriptMemberFn o) : Function_2030c0(s) {
        fn = o;
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke();
    CWorldCollisionManager* owner;  // 0x20
    Closure1(const char*, CWorldCollisionManager*, ScriptMemberFn);
};
Closure1::Closure1(const char* s, CWorldCollisionManager* d, ScriptMemberFn o) : Method1(s, o) {
    owner = d;
}
} // namespace fn_002030c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00203130 Closure1<CWorldCollisionManager,void,const_char_*>::vfunc_2 (18 B): matches/0x00203130.cpp
// sym: ?vfunc_2@?$Closure1@VCWorldCollisionManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CWorldCollisionManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_203130 * *)&this->f_20)->*(*(void (CActorManager_203130::**)(const char *))&this->f_1c))(*b);
}


// 0x00203150 CWorldCollisionManager::vfunc_0 (58 B): matches/0x00203150.cpp [wrapped: conflict: CWorldCollisionManager]
// sym: ?vfunc_0@CWorldCollisionManager@fn_00203150@@QAEPAV12@E@Z
namespace fn_00203150 {
class SubObj_203150 {
  public:
    void Clear();
};

extern void* worldVtable;

class CWorldCollisionManager {
  public:
    void* vptr;
    char pad4[0x0C];
    hulk_intptr mCount;
    char pad14[0x0C];
    SubObj_203150 mSub;
    CWorldCollisionManager* vfunc_0(unsigned char param);
};

void FreeMemA(void* p);
void FreeMemB(void* p);

CWorldCollisionManager* CWorldCollisionManager::vfunc_0(unsigned char param) {
    vptr = &worldVtable;
    mSub.Clear();
    if (mCount) {
        FreeMemA((void*)(mCount - 4));
    }
    if (param & 1) {
        FreeMemB(this);
    }
    return this;
}
} // namespace fn_00203150


// 0x00203190 FUN_00203190 (401 B): equivalent/0x00203190.cpp [wrapped: conflict: World]
// sym: _FUN_00203190
namespace fn_00203190 {
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 13/14, incomplete)
// FUN_00203190 @ 0x00203190
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

struct V3_203190 {
    float x, y, z;
};

struct Hit_203190 {
    int kind;
    int pad4[5];
    char flag;
};

struct Target_203190 {
    char pad0[0xc];
    int kind;
};

struct Weapon_203190 {
    char pad0[0x1b0];
    int f1b0;
};

struct Actor_203190 {
    char pad0[0x11c];
    Weapon_203190 *weapon;
    char pad120[0x1ca4 - 0x120];
    struct Tracer_203190 *tracer;
    void FUN_000368d0(int a);
};

struct World;

struct Tracer_203190 {
    bool FUN_0010aa90(World *g, V3_203190 *a, V3_203190 *b, float scale, V3_203190 *o3, V3_203190 *o2, V3_203190 *o1,
                      Actor_203190 *actor, Target_203190 *t, int zero0, int zero1);
};

struct Probe_203190 {
    bool FUN_00201e00(V3_203190 *a, V3_203190 *b, int one, V3_203190 *o1, V3_203190 *o2, int zero0, int zero1);
};

struct Camera {
    void FUN_00025310(int a, int b);
};

struct Exec {
    bool FUN_002edce0(Hit_203190 *h, V3_203190 *a, V3_203190 *b, int zero);
};

struct Holder10_203190 {
    char pad0[8];
    Exec *exec;
};

struct World {
    char pad0[0x10];
    Holder10_203190 *holder;
    char pad14[0x20 - 0x14];
    Camera *camera;
    Probe_203190 *probe;
};


bool __cdecl FUN_00202c30(V3_203190 *a, V3_203190 *b, float c, int one, V3_203190 *o3, V3_203190 *o2, int p3, Target_203190 *t, int p5, Actor_203190 *actor);

struct Frame_203190 {
    V3_203190 diff;
    V3_203190 o2;
    V3_203190 o3;
    Hit_203190 hit;
};

extern "C" bool FUN_00203190(V3_203190 *a1, V3_203190 *a2, int a3, Target_203190 *a4, int a5, Actor_203190 *a6)
{
    Frame_203190 f;
    World *game = DAT_004dd700;

    if (a4 && a4->kind != 1) {
        f.diff.x = a2->x - a1->x;
        f.diff.y = a2->y - a1->y;
        f.diff.z = a2->z - a1->z;
        if (a6 && a6->tracer)
            return a6->tracer->FUN_0010aa90(game, a1, a2, 0.5f, &f.o3, &f.o2, &f.diff, a6, a4, 0, 0);
        return FUN_00202c30(a1, a2, 0.1f, 1, &f.o3, &f.o2, a3, a4, a5, a6);
    }

    if (game->probe->FUN_00201e00(a1, a2, 1, &f.o2, &f.o3, 0, 0))
        return false;

    Camera *cam = game->camera;
    ((owners::C_25260 *)cam)->FUN_00025260(0, 0, 0);
    ((owners::Target_253c0 *)cam)->FUN_000253c0(0);
    if (a6) {
        cam->FUN_00025310(a6->weapon->f1b0, 1);
        a6->FUN_000368d0(0);
    }
    f.hit.kind = 2;
    f.hit.pad4[0] = 0;
    f.hit.pad4[1] = 0;
    f.hit.pad4[2] = 0;
    f.hit.pad4[3] = 0;
    f.hit.pad4[4] = 0;
    f.hit.flag = 1;
    bool hit = game->holder->exec->FUN_002edce0(&f.hit, a1, a2, 0);
    ((owners::Target_253c0 *)cam)->FUN_000253c0(1);
    ((owners::C_25260 *)cam)->FUN_00025260(1, 0, 0);
    return !hit;
}
} // namespace fn_00203190
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f0f2b8a0 {

// 0x00203380 FUN_00203380 (70 B): equivalent/0x00203380.cpp
// sym: ?FUN_00203380@Registry_203380@fn_f0f2b8a0@@QAEXPBDPAVOwner@2@P832@AEXM@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00203380 @ 0x00203380
// FUN_00203380 @ 0x00203380  (generated by tools/equiv_gen/reg_helper.py)
void Registry_203380::FUN_00203380(const char* a1, Owner* a2, Fn_203380 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_203380* e = (Closure1_203380*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_00202fa0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f0f2b8a0

// 0x002033d0 FUN_002033d0 (109 B): equivalent/0x002033d0.cpp [wrapped: conflict: CWorldCollisionManager; Closure0; Method0]
// sym: ?FUN_002033d0@Registry_2033d0@fn_002033d0@@QAEXPBDPAVCWorldCollisionManager@2@P832@AEMXZ@Z
namespace fn_002033d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002033d0 @ 0x002033d0
// FUN_002033d0 @ 0x002033d0  (generated by work/closure/gen.py)
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


class CWorldCollisionManager { public: float FUN_dummy(); };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_2033d0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_2033d0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_2033d0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_2033d0(name, 0) {
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

struct Registry_2033d0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_002033d0(const char* name, CWorldCollisionManager* owner, float (CWorldCollisionManager::*fn)());
};

void Registry_2033d0::FUN_002033d0(const char* name, CWorldCollisionManager* owner, float (CWorldCollisionManager::*fn)()) {
    typedef Closure0<CWorldCollisionManager, float> Closure_t;
    HULK_SIZE32(Closure_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CWorldCollisionManager, float>));
    Closure0<CWorldCollisionManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CWorldCollisionManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_002033d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00203490 FUN_00203490 (449 B): equivalent/0x00203490.cpp [wrapped: conflict: CWorldCollisionManager; Closure1; Method1]
// sym: ?FUN_00203490@CWorldCollisionManager@fn_00203490@@QAEXXZ
namespace fn_00203490 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00203490 @ 0x00203490
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

namespace math { class Vector; }

extern char DAT_0048e10c;
extern "C" void* FUN_0008d690(unsigned size);


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<float> { static const void* get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<const char*> { static const void* get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<math::Vector> { static const void* get() { return &DAT_0048e10c; } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_203490 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_203490(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_203490 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) : MethodBase_203490(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T* owner;
};

class CWorldCollisionManager;

struct Registry_203490 {
    void FUN_001d3b70(const char* name, void* closure);
    void FUN_002033d0(const char* name, CWorldCollisionManager* owner, float (CWorldCollisionManager::*fn)());
};
extern "C" Registry_203490* FUN_001d4c90();

class CWorldCollisionManager {
  public:
    math::Vector FUN_00202500(math::Vector);
    float FUN_00034e60();
    void FUN_00201bc0(float);
    void FUN_00201bd0(const char*);
    void FUN_00201be0(const char*);
    void FUN_00203490();
};

void CWorldCollisionManager::FUN_00203490()
{
    Registry_203490* reg = FUN_001d4c90();
    if (reg) {
        void* mem;

        { typedef Closure1<CWorldCollisionManager, math::Vector, math::Vector> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldCollisionManager, math::Vector, math::Vector>));
        Closure1<CWorldCollisionManager, math::Vector, math::Vector>* c1 = 0;
        if (mem)
            c1 = new (mem) Closure1<CWorldCollisionManager, math::Vector, math::Vector>("wcm_IntersectGround", this, &CWorldCollisionManager::FUN_00202500);
        reg->FUN_001d3b70("wcm_IntersectGround", c1);

        { typedef Closure1<CWorldCollisionManager, void, float> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldCollisionManager, void, float>));
        Closure1<CWorldCollisionManager, void, float>* c2 = 0;
        if (mem)
            c2 = new (mem) Closure1<CWorldCollisionManager, void, float>("wcm_SetWaterHeight", this, &CWorldCollisionManager::FUN_00201bc0);
        reg->FUN_001d3b70("wcm_SetWaterHeight", c2);

        reg->FUN_002033d0("wcm_GetWaterHeight", this, &CWorldCollisionManager::FUN_00034e60);

        { typedef Closure1<CWorldCollisionManager, void, const char*> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldCollisionManager, void, const char*>));
        Closure1<CWorldCollisionManager, void, const char*>* c3 = 0;
        if (mem)
            c3 = new (mem) Closure1<CWorldCollisionManager, void, const char*>("wcm_SetWaterEffectName", this, &CWorldCollisionManager::FUN_00201bd0);
        reg->FUN_001d3b70("wcm_SetWaterEffectName", c3);

        { typedef Closure1<CWorldCollisionManager, void, const char*> Sized; HULK_SIZE32(Sized, 0x24); }
        mem = FUN_0008d690((int)sizeof(Closure1<CWorldCollisionManager, void, const char*>));
        Closure1<CWorldCollisionManager, void, const char*>* c4 = 0;
        if (mem)
            c4 = new (mem) Closure1<CWorldCollisionManager, void, const char*>("wcm_SetWaterSound", this, &CWorldCollisionManager::FUN_00201be0);
        reg->FUN_001d3b70("wcm_SetWaterSound", c4);
    }
}
} // namespace fn_00203490
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

