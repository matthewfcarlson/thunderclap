// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3670..0x002c3aa0 (kind game, layer engine, confidence high), dominant class pure3d::TextBible
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f533db88 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f533db88 {} using namespace fn_f533db88;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f533db88 {
struct Obj_2c3670 {
    char pad[0x26];
    short count;
};
void thunk_FUN_0035a720(void*);
struct Obj_2c3690 {
    char pad[0x26];
    short count;
};
void __cdecl thunk_FUN_0035a740(void*);
struct Item {
    char pad[0x10];
    char value;
};
struct Holder {
    char pad[0x14];
    Item** begin;
    Item** end;
    char pad2[8];
    unsigned short index;
    void FUN_002c3770(char value);
};
class Impl_2c3810 {
  public:
    void Helper(int);
};
class Adj {
  public:
    virtual void a();
    virtual void b();
    virtual void c(int);
};
struct Sub_2c3930 {
    char p[8];
};
struct Entity_2c3930 {
    Entity_2c3930();
    virtual void h();
    int x;
    Sub_2c3930 s;
};
struct ILanguageChangeCallback_2c3930 {
    virtual void f();
};
extern "C" void* FUN_0008d6d0(hulk_uintptr);
struct TextBible : Entity_2c3930, ILanguageChangeCallback_2c3930 {
    virtual void g();
    int* mBegin;
    int* mEnd;
    int* mCap;
    int pad2;
    short mA;
    short mB;
    TextBible(int a, int n);
};
class IRefCount_2c39c0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};


// 0x002c3670 FUN_002c3670 (28 B): matches/0x002c3670.cpp
// sym: ?FUN_002c3670@fn_f533db88@@YIXPAUObj_2c3670@1@@Z
void __fastcall FUN_002c3670(Obj_2c3670* self) {
    if (self->count == 0)
        thunk_FUN_0035a720((char*)self + 0x10);
    ++self->count;
}


// 0x002c3690 FUN_002c3690 (36 B): matches/0x002c3690.cpp
// sym: ?FUN_002c3690@fn_f533db88@@YIXPAUObj_2c3690@1@@Z
void __fastcall FUN_002c3690(Obj_2c3690* self) {
    if (self->count > 0) {
        if (self->count == 1)
            thunk_FUN_0035a740((char*)self + 0x10);
        --self->count;
    }
}


// 0x002c3770 FUN_002c3770 (61 B): matches/0x002c3770.cpp
// sym: ?FUN_002c3770@Holder@fn_f533db88@@QAEXD@Z
void Holder::FUN_002c3770(char value) {
    Item** it = begin;
    unsigned int i = 0;
    for (; i < (unsigned int)(((hulk_intptr)end - (hulk_intptr)begin) >> 2); ++i, ++it) {
        if ((*it)->value == value) {
            index = (unsigned short)i;
            return;
        }
    }
}


// 0x002c3810 pure3d::TextBible::vfunc_2_adj10 (8 B): matches/0x002c3810.cpp
// sym: ?c@Adj@fn_f533db88@@UAEXH@Z
void Adj::c(int a0) {
    Impl_2c3810* p = (Impl_2c3810*)((char*)this + (-16));
    p->Helper(a0);
}


// 0x002c3930 FUN_002c3930 (132 B): matches/0x002c3930.cpp
// sym: ??0TextBible@fn_f533db88@@QAE@HH@Z
TextBible::TextBible(int a, int n) {
    mBegin = 0;
    mEnd = 0;
    mCap = 0;
    mA = -1;
    mB = 0;
    if (a)
        ((owners::Target_27b040 *)&s)->FUN_0027b040((hulk_uintptr)a);
    if (n) {
        mBegin = (int*)FUN_0008d6d0(n * 4);
        if (mBegin) {
            mCap = mBegin + n;
            mEnd = mBegin;
            return;
        }
    } else
        mBegin = 0;
    mEnd = 0;
    mCap = 0;
}

} // namespace fn_f533db88

// 0x002c39c0 pure3d::TextBible::vfunc_0 (4 B): matches/0x002c39c0.cpp
// sym: ?vfunc_0@TextBible@pure3d@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void pure3d::TextBible::vfunc_0() {
    ++this->f_04;
}

// 0x002c39d0 pure3d::TextBible::vfunc_1 (5 B): not yet verified
namespace fn_f533db88 {

// 0x002c39e0 pure3d::TextBible::vfunc_3_adj10 (3 B): matches/0x002c39e0.cpp
// sym: ?GetZero@fn_f533db88@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f533db88

// 0x002c39f0 pure3d::TextBible::vfunc_0_adj10 (8 B): matches/0x002c39f0.cpp [wrapped: conflict: content::LoadObject; pure3d::Entity; pure3d::TextBible]
// sym: ?vfunc_1@TextBible@pure3d@fn_002c39f0@@WBA@AEXXZ
namespace fn_002c39f0 {
namespace pure3d {
class Entity {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[12];
};
} // namespace pure3d
namespace content {
class LoadObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
} // namespace content
extern void work(void*);
namespace pure3d {
class TextBible : public Entity, public content::LoadObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
void TextBible::vfunc_0() {
    TextBible obj;
    work(&obj);
}
} // namespace pure3d
} // namespace fn_002c39f0


// 0x002c3a00 pure3d::TextBible::vfunc_1_adj10 (8 B): matches/0x002c3a00.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ?vfunc_1@TextBible@pure3d@fn_002c3a00@@WBA@AEXXZ
namespace fn_002c3a00 {
namespace pure3d {
class Entity {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[12];
};
} // namespace pure3d
namespace content {
class LoadObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
} // namespace content
namespace pure3d {
class TextBible : public Entity, public content::LoadObject {
  public:
    virtual void vfunc_1();
};
TextBible globalTextBible;
} // namespace pure3d
} // namespace fn_002c3a00


// 0x002c3a10 pure3d::TextBible::vfunc_4_adj10 (8 B): equivalent/0x002c3a10.cpp [wrapped: conflict: pure3d::TextBible]
// sym: ?vfunc_4_adj10@TextBible@pure3d@fn_002c3a10@@QAEXI@Z
namespace fn_002c3a10 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// pure3d::TextBible::vfunc_4_adj10 @ 0x002c3a10
namespace pure3d { struct TextBible { void vfunc_2(unsigned flags); void vfunc_4_adj10(unsigned flags); }; void TextBible::vfunc_4_adj10(unsigned flags) { TextBible *object = reinterpret_cast<TextBible *>(reinterpret_cast<char *>(this) - 16); object->vfunc_2(flags); } }
} // namespace fn_002c3a10


// 0x002c3a20 FUN_002c3a20 (95 B): matches/0x002c3a20.cpp [wrapped: conflict: core::ILanguageChangeCallback; pure3d::Entity; pure3d::TextBible]
// sym: ??1TextBible@pure3d@fn_002c3a20@@UAE@XZ
namespace fn_002c3a20 {
extern void Free(void*) throw();
class Item_2c3a20 {
  public:
    void Fini() throw();
};
namespace core {
struct ILanguageChangeCallback {
    virtual void a() = 0;
    virtual void b() = 0;
    virtual void c() = 0;
    virtual ~ILanguageChangeCallback() throw() {}
    virtual void e() = 0;
};
} // namespace core
template <class T> struct Vec_2c3a20 {
    T* b;
    T* e;
    T* c;
    unsigned size() const { return (unsigned)(e - b); }
    T& operator[](unsigned i) { return b[i]; }
    void clear() { e = b; }
    ~Vec_2c3a20() throw() {
        e = b;
        if (b)
            Free(b);
    }
};
namespace pure3d {
class Entity {
  public:
    virtual ~Entity() throw();
    char pad[0xc];
};
class TextBible : public Entity, public core::ILanguageChangeCallback {
  public:
    Vec_2c3a20<Item_2c3a20*> items;
    virtual ~TextBible() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void e();
};
TextBible::~TextBible() throw() {
    for (unsigned i = 0; i < items.size(); i++)
        items[i]->Fini();
    items.clear();
}
} // namespace pure3d
} // namespace fn_002c3a20

