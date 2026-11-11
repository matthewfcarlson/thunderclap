// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024d210..0x0024d3c0 (kind game, layer engine, confidence medium), dominant class om::EntityLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/unknown.h"
#define TREE_TU_BEGIN namespace fn_f937dacf {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f937dacf {} using namespace fn_f937dacf;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f937dacf {
class Obj_24d210 {
  public:
    int Fn_00264d20();
};
extern "C" char DAT_00429394[];
class EntityLoader {
  public:
    void* vtable;
    int a;
    void* b;
    EntityLoader(void*);
};


// 0x0024d210 FUN_0024d210 (11 B): matches/0x0024d210.cpp
// sym: ?FUN_0024d210@fn_f937dacf@@YAHXZ
int __cdecl FUN_0024d210() {
    return (*(Obj_24d210**)&DAT_00527c58)->Fn_00264d20();
}

} // namespace fn_f937dacf

// 0x0024d220 om::EntityLoader::vfunc_3 (309 B): equivalent/0x0024d220.cpp [wrapped: conflict: FUN_0024d210]
// sym: ?vfunc_3@EntityLoader@om@fn_0024d220@@UAEXPAPAVEntry_24d220@3@PAUU64_24d220@3@PAXHH@Z @4f898671c9c9 @w281a85562062
namespace fn_0024d220 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// om::EntityLoader::vfunc_3 @ 0x0024d220
struct U64_24d220 {
    unsigned int lo;
    unsigned int hi;
};

struct ContentStream {
    char data[0x20];
    ContentStream *FUN_00247220(void *source);
    void FUN_00246a90();
};

struct StreamRef {
    ContentStream *stream;
    char flag;
    char pad[3];
    StreamRef *FUN_00246da0(ContentStream *s, char f);
};

struct Quad_24d220 {
    void *a, *b, *c, *d;
};

void FUN_0024d210();

struct Functor {
    StreamRef *ref;
    Quad_24d220 *quad;
    void (*fn)();
};

void *FUN_00246c50();
extern "C" void __cdecl FUN_00244d10(Functor *f, U64_24d220 *out);

class Entry_24d220 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(Functor *f);
    bool FUN_00245040(U64_24d220 *id);
    U64_24d220 *FUN_00243390();
};

class Result_24d220 {
public:
    virtual void vf0();
};

Result_24d220 *__cdecl FUN_00244fa0(U64_24d220 *id, void *key);

class Source_24d220 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Entry_24d220 *vf2();
    char pad4[0x2c];
    char key[1];
};

struct Frame_24d220 {
    U64_24d220 id;
    StreamRef ref;
    Functor functor;
    Quad_24d220 quad;
    ContentStream cs;
};

namespace om { class EntityLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Entry_24d220 **outEntry, U64_24d220 *outId, void *streamSource, int unused1, int unused2);
    char pad4[4];
    Source_24d220 *source;
}; }

void om::EntityLoader::vfunc_3(Entry_24d220 **outEntry, U64_24d220 *outId, void *streamSource, int unused1, int unused2)
{
    Frame_24d220 f;
    void *r1 = FUN_00246c50();
    void *r2 = FUN_00246c50();
    void *r3 = FUN_00246c50();
    void *r4 = FUN_00246c50();
    f.quad.a = r4;
    f.quad.b = r3;
    f.quad.c = r2;
    f.quad.d = r1;
    f.cs.FUN_00247220(streamSource);
    f.ref.FUN_00246da0(&f.cs, 0);
    f.functor.ref = &f.ref;
    f.functor.quad = &f.quad;
    f.functor.fn = FUN_0024d210;
    f.id.lo = 0;
    f.id.hi = 0;
    FUN_00244d10(&f.functor, &f.id);

    Entry_24d220 *e = source->vf2();
    e->vf0();
    if (!e->FUN_00245040(&f.id)) {
        e->vf5(&f.functor);
        e->vf1();
        Result_24d220 *r = FUN_00244fa0(&f.id, source->key);
        *outEntry = (Entry_24d220 *)r;
        r->vf0();
        outId->lo = f.id.lo;
        outId->hi = f.id.hi;
        f.cs.FUN_00246a90();
        return;
    }
    e->vf5(&f.functor);
    *outEntry = e;
    U64_24d220 *p = e->FUN_00243390();
    outId->lo = p->lo;
    outId->hi = p->hi;
    f.cs.FUN_00246a90();
}
} // namespace fn_0024d220

namespace fn_f937dacf {

// 0x0024d360 FUN_0024d360 (25 B): matches/0x0024d360.cpp
// sym: ??0EntityLoader@fn_f937dacf@@QAE@PAX@Z
EntityLoader::EntityLoader(void* p) {
    a = 0;
    vtable = (void*)((hulk_intptr)DAT_00429394);
    b = p;
}

} // namespace fn_f937dacf

// 0x0024d380 om::EntityLoader::vfunc_2 (36 B): matches/0x0024d380.cpp [wrapped: conflict: om::EntityLoader]
// sym: ?vfunc_2@EntityLoader@om@fn_0024d380@@QAEPAV123@E@Z
namespace fn_0024d380 {

extern int hulk_at_003f6098;
namespace om { class EntityLoader {
  public:
    hulk_intptr vptr;
    EntityLoader* vfunc_2(unsigned char);
}; }
extern "C" void FUN_00247550(void*, om::EntityLoader*);
om::EntityLoader* om::EntityLoader::vfunc_2(unsigned char param) {
    vptr = (hulk_intptr)&hulk_at_003f6098;
    if (param & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e62d8), this);
    return this;
}
} // namespace fn_0024d380

