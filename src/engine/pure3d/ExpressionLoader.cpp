// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002afb30..0x002aff60 (kind game, layer engine, confidence high), dominant class pure3d::ExpressionLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fb28d753 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fb28d753 {} using namespace fn_fb28d753;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fb28d753 {
extern "C" char DAT_0042e30c[];
class Expression {
  public:
    char pad[0x14];
    int a;
    int b;
    void Init_0027b070();
};
} // namespace fn_fb28d753
namespace pure3d {
class Entity_2afb60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_fb28d753 {
extern void* hulk_at_0042e30c[];
} // namespace fn_fb28d753
void operator delete(void*);
namespace fn_fb28d753 {
class Entity_2afb70 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class Expression_2afb70 : public Entity_2afb70 {
  public:
    char pad[0xc];
    void* m10;
    void* m14;
    void* m18;
    ~Expression_2afb70();
};
extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
} // namespace fn_fb28d753
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_fb28d753 {
struct Name_2afba0 {
    char data[8];
};
} // namespace fn_fb28d753
namespace pure3d {
class __declspec(novtable) Entity_2afba0 {
public:
    virtual void e0_00038290();
    char pad4[4];
    Name_2afba0 name;
    void FUN_0027b070();
    Entity_2afba0() throw() { FUN_0027b070(); }
};
}
namespace pure3d {
class Expression_2afba0 : public Entity_2afba0 {
public:
    virtual void x1_000382a0();
    virtual void x2();
    virtual void x3_002afb50();
    virtual void x4_002afb60();
    unsigned int count;
    int *keys;
    float *values;
    Expression_2afba0() throw() { keys = 0; values = 0; }
};
}
namespace fn_fb28d753 {
struct Reader_2afba0 {
};
struct Stream_2afba0 {
    char pad0[0x284];
    Reader_2afba0 *reader;
};
union Cell_2afba0 {
    int i;
    float f;
};
struct Frame_2afba0 {
    char pad[3];
    unsigned char len;
    Cell_2afba0 cell;
    char name[0x100];
};
struct SubItem { bool FUN_0027af90(int key); };
struct Item { char pad[8]; SubItem sub; };
struct Collection { char pad[0x10]; Item **begin; Item **end; int FUN_002afe80(hulk_intptr key); };
extern "C" char DAT_0042e324[];
class ExpressionLoader {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    ExpressionLoader();
};


// 0x002afb30 FUN_002afb30 (26 B): matches/0x002afb30.cpp
// sym: ?FUN_002afb30@fn_fb28d753@@YIPAVExpression@1@PAV21@@Z
Expression* __fastcall FUN_002afb30(Expression* self) {
    self->Init_0027b070();
    self->a = 0;
    self->b = 0;
    *(hulk_intptr*)self = ((hulk_intptr)DAT_0042e30c);
    return self;
}

} // namespace fn_fb28d753

// 0x002afb50 pure3d::Expression::vfunc_3 (3 B): matches/0x002afb50.cpp
// sym: ?vfunc_3@Expression@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Expression::vfunc_3() {
    return (bool)(0);
}


// 0x002afb60 pure3d::Expression::vfunc_4 (3 B): matches/0x002afb60.cpp
// sym: ?vfunc_4@Expression@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Expression::vfunc_4() {
    return (void*)(this);
}

namespace fn_fb28d753 {

// 0x002afb70 FUN_002afb70 (38 B): matches/0x002afb70.cpp
// sym: ??1Expression_2afb70@fn_fb28d753@@QAE@XZ
Expression_2afb70::~Expression_2afb70() {
    vptr = hulk_at_0042e30c;

    operator delete(m14);
    operator delete(m18);
    Fin_0027afd0();
}

} // namespace fn_fb28d753

// 0x002afba0 pure3d::ExpressionLoader::vfunc_5 (363 B): equivalent/0x002afba0.cpp
// sym: ?vfunc_5@ExpressionLoader@pure3d@@UAEXPAX00H@Z @96b7947be2b8 @wf75b213495ce
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::ExpressionLoader::vfunc_5 @ 0x002afba0
void pure3d::ExpressionLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { pure3d::Expression_2afba0 ** out = (pure3d::Expression_2afba0 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_2afba0 * s = (Stream_2afba0 *)__p2; void * ctx = (void *)__p3;

    Frame_2afba0 f;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0x20);
    pure3d::Expression_2afba0 *e = 0;
    if (mem)
        e = new (mem) pure3d::Expression_2afba0();
    ((owners::Target_27b040 *)&(e->name))->FUN_0027b040((hulk_uintptr)(f.name));

    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
    e->count = f.cell.i;
    e->values = (float *)FUN_0008d6d0(f.cell.i * 4);
    e->keys = (int *)FUN_0008d6d0(e->count * 4);
    for (unsigned int i = 0; i < e->count; i++) {
        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
        e->values[i] = f.cell.f;
    }
    for (unsigned int i = 0; i < e->count; i++) {
        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
        e->keys[i] = f.cell.i;
    }
    *out = e;
    *outId = FUN_002672f0(f.name, 0);
}


// 0x002afe40 pure3d::Expression::vfunc_2 (59 B): matches/0x002afe40.cpp [wrapped: conflict: Expression]
// sym: ?f2@Expression@fn_002afe40@@UAEPAV12@H@Z
void __cdecl operator delete[](void*);
namespace fn_002afe40 {
extern const int Expression_vftable;

class Expression {
  public:
    virtual void f0();
    virtual void f1();
    virtual Expression* f2(int);
    virtual void f3();
    virtual void f4();
    int pad[4];
    void* a;
    void* b;
    void Do_0027afd0();
};
extern void __cdecl FreeObj_00263f30(void*);
Expression* Expression::f2(int x) {
    Expression* p = this;
    void* q = p->a;
    *(const int**)p = &Expression_vftable;
    operator delete[](q);
    q = p->b;
    operator delete[](q);
    p->Do_0027afd0();
    if (x & 1)
        FreeObj_00263f30(p);
    return p;
}
} // namespace fn_002afe40

namespace fn_fb28d753 {

// 0x002afe80 FUN_002afe80 (82 B): equivalent/0x002afe80.cpp
// sym: ?FUN_002afe80@Collection@fn_fb28d753@@QAEHH@Z @4d27714530fb @wdaad038e4fd5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002afe80 @ 0x002afe80
int Collection::FUN_002afe80(hulk_intptr key) {
    int bytes = (int)((char*)end - (char*)begin);
    if ((bytes & ~3) <= 0) return -1;
    int i = 0;
    do {
        if (begin[i]->sub.FUN_0027af90(key)) return i;
        ++i;
    } while (i < ((int)((char*)end - (char*)begin) >> 2));
    return -1;
}


// 0x002aff20 FUN_002aff20 (27 B): matches/0x002aff20.cpp
// sym: ??0ExpressionLoader@fn_fb28d753@@QAE@XZ
ExpressionLoader::ExpressionLoader() {
    volatile int* p = &a;
    p[1] = 0;
    p[2] = 0x21000;
    p[3] = 0;
    p[4] = 0;
    p[0] = ((hulk_intptr)DAT_0042e324);
}

} // namespace fn_fb28d753

// 0x002aff40 pure3d::ExpressionLoader::vfunc_2 (31 B): matches/0x002aff40.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002aff40@@UAEPAV123@E@Z
namespace fn_002aff40 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2aff40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2aff40 {
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
} // namespace fn_002aff40

