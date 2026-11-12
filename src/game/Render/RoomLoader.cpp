// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c6cb0..0x001c7500 (kind game, layer game, confidence medium), dominant class Render::RoomLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f74b9f55 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f74b9f55 {} using namespace fn_f74b9f55;
namespace fn_f74b9f55 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_f74b9f55 {
class Ref_1c6cb0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1c6cb0 {
  public:
    char pad[12];
    Ref_1c6cb0* value;
    void Set(Ref_1c6cb0* p);
};
class Item_1c6ce0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_1c6ce0 {
  public:
    char pad[0x10];
    Item_1c6ce0* item;
    void Set(Item_1c6ce0* p);
};
extern "C" char DAT_00421a04[];
struct RoomLoader {
    hulk_intptr vft;
    int a;
    int b;
    int c;
    int d;
    int e;
    RoomLoader(int arg);
};
class SimpleChunkHandler_1c6d40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_1c6d40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
struct Sub_1c6d60 {
    void cleanup_001c2760();
};
struct Item_1c6d60 {
    char pad[4];
};
typedef unsigned int u32_1c6e20;
struct Sub_1c6e20 {
    void clean_001c27c0();
};
void finish_0008d340(hulk_uintptr);
struct Container_1c6e20 {
    char* begin;
    char* end;
};
struct Ref_1c6e60 { virtual void AddRef(); virtual void Release(); };
struct Words3 { unsigned int x,y,z; };
struct Words6_1c6e60 { unsigned int a,b,c,d,e,f; };
struct Words4 { unsigned int a,b,c,d; };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int bytes);
extern void __cdecl FUN_001c6d60(void* begin, void* end);
struct Object {
 char base[8]; unsigned char flag8,flag9; char padA[2];
 Ref_1c6e60* first; Ref_1c6e60* second; void* begin; void* end; unsigned int unused1c;
 Words3 position; Words6_1c6e60 data; Words4 more; unsigned short mode; char pad56[2]; unsigned int zero; float scale;
 void FUN_0027af30(void* arg);
 Object* init(void* arg, Ref_1c6e60* a, Ref_1c6e60* b, unsigned int count, const Words3* p, unsigned short m, const Words6_1c6e60* d, const Words4* e);
};
class Elem_1c6f70 {
  public:
    void Cleanup_001c27c0();
};
class Item_1c6f70 {
    char pad[4];

  public:
    Elem_1c6f70 element;
};
class Ref_1c6f70 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_1c6f70 {
    char pad[0xc];

  public:
    Ref_1c6f70* mA;
    Ref_1c6f70* mB;
    Item_1c6f70* begin;
    Item_1c6f70* end;
    void Clear();
    void Finish_0027af50();
};
void __cdecl thunk_FUN_00267090(Item_1c6f70*);


// 0x001c6cb0 FUN_001c6cb0 (38 B): matches/0x001c6cb0.cpp
// sym: ?Set@Owner_1c6cb0@fn_f74b9f55@@QAEXPAVRef_1c6cb0@2@@Z
// Same code shape as 0x00059760 (propagated; names are from that function)
void Owner_1c6cb0::Set(Ref_1c6cb0* p) {
    if (p)
        p->A();
    if (value)
        value->B();
    value = p;
}


// 0x001c6ce0 FUN_001c6ce0 (38 B): matches/0x001c6ce0.cpp
// sym: ?Set@Owner_1c6ce0@fn_f74b9f55@@QAEXPAVItem_1c6ce0@2@@Z
// Same code shape as 0x00059790 (propagated; names are from that function)
void Owner_1c6ce0::Set(Item_1c6ce0* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x001c6d10 FUN_001c6d10 (36 B): matches/0x001c6d10.cpp
// sym: ??0RoomLoader@fn_f74b9f55@@QAE@H@Z
RoomLoader::RoomLoader(int arg) {
    a = 0;
    c = 0;
    d = 0;
    b = 0x60000701;
    vft = ((hulk_intptr)DAT_00421a04);
    e = arg;
}


// 0x001c6d40 Render::RoomLoader::vfunc_2 (31 B): matches/0x001c6d40.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f74b9f55@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001c6d60 FUN_001c6d60 (41 B): matches/0x001c6d60.cpp
// sym: ?FUN_001c6d60@fn_f74b9f55@@YAXPAUItem_1c6d60@1@0@Z
void __cdecl FUN_001c6d60(Item_1c6d60* a, Item_1c6d60* b) {
    for (; a != b; a = (Item_1c6d60*)((char*)a + 0xa8)) {
        if (a)
            ((Sub_1c6d60*)((char*)a + 4))->cleanup_001c2760();
    }
}


// 0x001c6e20 FUN_001c6e20 (51 B): matches/0x001c6e20.cpp
// sym: ?target@fn_f74b9f55@@YIXPAUContainer_1c6e20@1@@Z
void __fastcall target(Container_1c6e20* self) {
    char* p = self->begin;
    if (p) {
        char* e = self->end;
        for (; p != e; p += 0xa8)
            ((Sub_1c6e20*)(p + 4))->clean_001c27c0();
        finish_0008d340((hulk_uintptr)self->begin);
    }
}


// 0x001c6e60 FUN_001c6e60 (269 B): equivalent/0x001c6e60.cpp
// sym: ?init@Object@fn_f74b9f55@@QAEPAU12@PAXPAURef_1c6e60@2@1IPBUWords3@2@GPBUWords6_1c6e60@2@PBUWords4@2@@Z @eb62a69aa484 @w1c9f81e6178f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001c6e60 @ 0x001c6e60
Object* Object::init(void* arg, Ref_1c6e60* a, Ref_1c6e60* b, unsigned int count, const Words3* p, unsigned short m, const Words6_1c6e60* d, const Words4* e) {
 FUN_0027af30(arg);
 flag8=0; flag9=0; first=0;
 if(a) { a->AddRef(); if(first) first->Release(); }
 first=a;
 second=0;
 if(b) { b->AddRef(); if(second) second->Release(); }
 second=b;
 if(count) {
 unsigned int size=count*0xa8;
 void* allocation=FUN_0008d6d0(size);
 begin=allocation;
 if(allocation) { end=(char*)allocation+size; FUN_001c6d60(allocation,end); }
 else { begin=0; end=0; }
 } else { begin=0; end=0; }
 position.x=p->x; position.y=p->y; position.z=p->z;
 data.a=d->a; data.b=d->b; data.c=d->c; data.d=d->d; data.e=d->e; data.f=d->f;
 more.a=e->a; more.b=e->b; more.c=e->c; more.d=e->d;
 zero=0; mode=m; scale=1.0f;
 return this;
}


// 0x001c6f70 FUN_001c6f70 (97 B): matches/0x001c6f70.cpp
// sym: ?Clear@Owner_1c6f70@fn_f74b9f55@@QAEXXZ
void Owner_1c6f70::Clear() {
    Item_1c6f70* p = begin;
    if (p) {
        Item_1c6f70* e = end;
        if (p != e) {
            do {
                p->element.Cleanup_001c27c0();
                p = (Item_1c6f70*)((char*)p + 0xa8);
            } while (p != e);
        }
        thunk_FUN_00267090(begin);
    }
    {
        Ref_1c6f70* q = mB;
        if (q)
            q->Release();
    }
    {
        Ref_1c6f70** q = &mB;
        *q = 0;
    }
    {
        Ref_1c6f70* q = mA;
        if (q)
            q->Release();
    }
    {
        Ref_1c6f70** q = &mA;
        *q = 0;
    }
    Finish_0027af50();
}

} // namespace fn_f74b9f55
