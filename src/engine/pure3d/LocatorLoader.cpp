// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c16f0..0x002c1970 (kind game, layer engine, confidence high), dominant class pure3d::LocatorLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f29c4ef1 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f29c4ef1 {} using namespace fn_f29c4ef1;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f29c4ef1 {
class Entity_2c16f0 {
  public:
    Entity_2c16f0();
    virtual void f();
};
class Locator : public Entity_2c16f0 {
  public:
    Locator();
    virtual void f();
    char pad[0x18];
    int a, b, c;
    float d;
};
} // namespace fn_f29c4ef1
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
namespace fn_f29c4ef1 {
void *__cdecl FUN_00263ea0(unsigned int size);
} // namespace fn_f29c4ef1
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f29c4ef1 {
struct Name_2c1770 {
    char data[8];
};
struct Vec3_2c1770 { float x, y, z; };
struct Quat_2c1770 { float x, y, z, w; };
} // namespace fn_f29c4ef1
namespace pure3d {
class __declspec(novtable) Entity_2c1770 {
public:
    virtual void e0_00038290();
    char pad4[4];
    Name_2c1770 name;
    void FUN_0027b070();
    Entity_2c1770() { FUN_0027b070(); }
};
}
namespace pure3d {
class Locator_2c1770 : public Entity_2c1770 {
public:
    virtual void x1_000382a0();
    virtual void* x2_002c1900(char);
    virtual void x3_0027afe0();
    virtual void x4_0027aff0();
    Vec3_2c1770 position;
    Quat_2c1770 rotation;
    Locator_2c1770() {
        rotation.x = 0.0f;
        rotation.y = 0.0f;
        rotation.z = 0.0f;
        rotation.w = 1.0f;
    }
};
}
namespace fn_f29c4ef1 {
struct Reader_2c1770 {
};
struct Stream_2c1770 {
    char pad0[0x284];
    Reader_2c1770 *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
struct Frame_2c1770 {
    char pad[3];
    unsigned char len;
    union {                         // copy temporaries
        Vec3_2c1770 pos;
        Quat_2c1770 quat;
    } tmp;
    Vec3_2c1770 pos;
    Quat_2c1770 quat;
    int count;
    char name[0x100];
};
extern void* hulk_at_0042eb98[];
class Entity_2c1900 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class Locator_2c1900 : public Entity_2c1900 {
  public:
    Locator_2c1900* vfunc_5(signed char flags);
};
extern "C" char DAT_0042ebb0[];
class LocatorLoader : public HulkChunkHandler {
  public:
    LocatorLoader();
};


// 0x002c16f0 FUN_002c16f0 (36 B): matches/0x002c16f0.cpp
// sym: ??0Locator@fn_f29c4ef1@@QAE@XZ
Locator::Locator() {
    _ReadWriteBarrier();
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
}

} // namespace fn_f29c4ef1

// 0x002c1770 pure3d::LocatorLoader::vfunc_5 (388 B): equivalent/0x002c1770.cpp
// sym: ?vfunc_5@LocatorLoader@pure3d@@UAEXPAX00H@Z @d445b8d36bb0 @wb146b3faaaec
// STATUS: equivalent (tools/equiv.py level 3: 15928 inputs, branch coverage 8/8)
// pure3d::LocatorLoader::vfunc_5 @ 0x002c1770
void pure3d::LocatorLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { pure3d::Locator_2c1770 ** out = (pure3d::Locator_2c1770 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_2c1770 * s = (Stream_2c1770 *)__p2; void * ctx = (void *)__p3;

    Frame_2c1770 f;
    Reader_2c1770 *rd = s->reader;
    ((owners::X_2647e0 *)rd)->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);
    f.name[f.len] = 0;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.pos), (hulk_intptr)3, 4, (hulk_intptr)1);

    void *mem = FUN_00263ea0(0x30);
    pure3d::Locator_2c1770 *loc = 0;
    if (mem)
        loc = new (mem) pure3d::Locator_2c1770();
    ((owners::Target_27b040 *)&(loc->name))->FUN_0027b040((hulk_uintptr)(f.name));
    f.tmp.pos = f.pos;
    loc->position = f.tmp.pos;

    while (s->FUN_002669f0()) {
        if (s->FUN_00266a30() == 0x14001) {
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.quat), (hulk_intptr)4, 4, (hulk_intptr)1);
            f.tmp.quat = f.quat;
            loc->rotation = f.tmp.quat;
        }
        s->FUN_00266be0();
    }
    *out = loc;
    *outId = FUN_002672f0(f.name, 0);
}

namespace fn_f29c4ef1 {

// 0x002c1900 pure3d::Locator::vfunc_2 (36 B): matches/0x002c1900.cpp
// sym: ?vfunc_5@Locator_2c1900@fn_f29c4ef1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Locator_2c1900* Locator_2c1900::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042eb98;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002c1930 FUN_002c1930 (27 B): matches/0x002c1930.cpp
// sym: ??0LocatorLoader@fn_f29c4ef1@@QAE@XZ
LocatorLoader::LocatorLoader() {
    refs = 0;
    id = 0x14000;
    f0c = 0;
    f10 = 0;
    vftable = (void*)DAT_0042ebb0;
}

} // namespace fn_f29c4ef1

// 0x002c1950 pure3d::LocatorLoader::vfunc_2 (31 B): matches/0x002c1950.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002c1950@@UAEPAV123@E@Z
namespace fn_002c1950 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2c1950 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2c1950 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002c1950

