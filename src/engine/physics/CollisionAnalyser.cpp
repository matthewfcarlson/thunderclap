// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030d760..0x0030e630 (kind game, layer engine, confidence high), dominant class physics::CollisionAnalyser
#include "tree_prelude.h"
extern "C" char DAT_00431fe0[];   // (x64t5) a game vftable, stored by address
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f910b875 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f910b875 {} using namespace fn_f910b875;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f910b875 {
struct Vec3_30d760 {
    int a, b, c;
};
class Target_30d760 {
    char pad0[0x14];
    int a0, a1, a2, b0, b1, b2;
    char pad1[0x58];
    char flag;
    char pad2[3];
    int enabled;
    int p0, p1, p2;

  public:
    void Set(Vec3_30d760* a, Vec3_30d760* b, int c, int d, int e);
};
struct Vec3_30d7c0 { float x, y, z; };
struct Target_30d7c0 {
    char pad0[0x14];
    Vec3_30d7c0 sumA;
    Vec3_30d7c0 sumB;
    char pad1[0x88 - 0x2c];
    int n;
    float f8c;
    float f90;
    void FUN_0030d7c0(Vec3_30d7c0 *a, Vec3_30d7c0 *b, float c, float d);
};
struct Inner_30d8c0 {
    char pad[0x6c];
    unsigned int value;
};
struct Param_30d8c0 {
    char pad0[8];
    Inner_30d8c0* p1;
    Inner_30d8c0* p2;
    char pad1[8];
    unsigned int x, y, z;
};
struct CollisionAnalyser_30d900 {
    int pad;
    int* begin;
    int* end;
    hulk_intptr Find(int* key);
};
struct Sub_30d980 {
    void Process_00319f40();
};
struct Item_30d980 {
    char pad[0x10];
    Sub_30d980* sub;
};
struct Owner_30d980 {
    char pad[4];
    Item_30d980* begin;
    Item_30d980* end;
    void Target();
};
struct Sub_30d9b0 {
};
struct Item_30d9b0 {
    char pad[0x10];
    Sub_30d9b0* sub;
};
struct Owner_30d9b0 {
    char pad[4];
    Item_30d9b0* begin;
    Item_30d9b0* end;
    void Target();
};
struct Object {
};
struct Entry_30d9e0 {
    int a;
    int b;
    int key;
    int d;
    Object* object;
};
struct Container_30d9e0 {
    int pad;
    Entry_30d9e0* begin;
    Entry_30d9e0* end;
    void scan(int key);
};
struct Item {
    hulk_intptr a, b, c, d, e;
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_0031a800(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
struct Elem_30df50 {
    char data[0xa4];
    Elem_30df50 *FUN_0031a440();
    void FUN_0031a4f0(Elem_30df50 *src);
    void FUN_0031a800();
};
struct Range_30df50 {
    char pad0[0x10];
    int offset;
};
class CollisionAnalyser_30df50 {
public:
    hulk_intptr FUN_0030df50();

    char pad0[4];
    Range_30df50 *rangesBegin;
    Range_30df50 *rangesEnd;
    char pad0c[0x24 - 0x0c];
    int *freeBegin;
    int *freeEnd;
    char pad2c[0x34 - 0x2c];
    Elem_30df50 *elemBegin;
    Elem_30df50 *elemEnd;
    Elem_30df50 *elemCap;
};
struct Item_30e0a0 { char pad[0x94]; float time;  void FUN_0031a400();  };
struct Entry_30e0a0 { char pad[16]; Item_30e0a0* item; };
void __cdecl FUN_0030dbd0(Entry_30e0a0*,Entry_30e0a0*,Entry_30e0a0*);
struct Manager_30e0a0 { char pad[4]; Entry_30e0a0* first; Entry_30e0a0* last; float cutoff; char pad10[4]; Entry_30e0a0* storage; Entry_30e0a0* end; char pad1c[12]; Item_30e0a0** out; Item_30e0a0** outEnd; void target(); };
struct Elem_30e250 {
    void process_00319f40();
};
struct CollisionAnalyser_nv_30e250 {
    void init_0030e0a0();
};
struct CollisionAnalyser_30e280 {
 char pad0[4];
 Item* first;
 Item* last;
 char pad1[8];
 Item* begin;
 Item* end;
 Item* limit;
 Item* FUN_0030e280();
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned n) throw();
struct Buf_30e480 {
    char* a;
    char* b;
    char* c;
    int pad;
    Buf_30e480() throw() : a(0), b(0), c(0) {}
};
struct Base_30e480 {
    void* vptr;
    Base_30e480() throw() { vptr = (void*)DAT_00431fe0; }   // (x64t5) the vftable by address (common.h's `vA` is a zero stub natively)
};
class CollisionAnalyser_30e480 : public Base_30e480 {
  public:
    int m4, m8, mc;
    char c10;
    Buf_30e480 b0, b1, b2, b3;
    CollisionAnalyser_30e480() throw();
};
extern void* hulk_at_00431fe0[];
class Sub_30e570 {
  public:
    void Fini_00319ef0();
};
struct E1 {
    char pad[0x10];
    Sub_30e570* s;
};
struct E2 {
    char pad[0xa4];
    void Fini_0031a800();
};
class CollisionAnalyser_30e570 {
  public:
    void* vptr;
    E1* m4;
    E1* m8;
    char pad[8];
    void* m14;
    void* m18;
    char pad2[8];
    void* m24;
    void* m28;
    char pad3[8];
    E2* m34;
    E2* m38;
    char pad4[8];
    void* m44;
    void* m48;
    ~CollisionAnalyser_30e570() throw();
};
class CAction_30e610 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_30e610* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CollisionAnalyser_30e610 : public CAction_30e610 {
  public:
    CollisionAnalyser_30e610* vfunc_2(unsigned char);
};
struct CollisionAnalyser_nv_30e610 {
    void FUN_0030e570();
};
extern void thunk_FUN_00267090(CollisionAnalyser_30e610*);


// 0x0030d760 FUN_0030d760 (92 B): matches/0x0030d760.cpp
// sym: ?Set@Target_30d760@fn_f910b875@@QAEXPAUVec3_30d760@2@0HHH@Z
void Target_30d760::Set(Vec3_30d760* a, Vec3_30d760* b, int c, int d, int e) {
    a0 = a->a;
    a1 = a->b;
    a2 = a->c;
    b0 = b->a;
    b1 = b->b;
    b2 = b->c;
    p0 = c;
    p1 = d;
    p2 = e;
    enabled = 1;
    flag = 0;
}


// 0x0030d7c0 FUN_0030d7c0 (108 B): equivalent/0x0030d7c0.cpp
// sym: ?FUN_0030d7c0@Target_30d7c0@fn_f910b875@@QAEXPAUVec3_30d7c0@2@0MM@Z @79e3870176e3 @wcd60ddaec6f7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030d7c0 @ 0x0030d7c0
void Target_30d7c0::FUN_0030d7c0(Vec3_30d7c0 *a, Vec3_30d7c0 *b, float c, float d)
{
    sumA.x = sumA.x + a->x;
    sumA.y = a->y + sumA.y;
    sumA.z = a->z + sumA.z;
    sumB.x = sumB.x + b->x;
    sumB.y = b->y + sumB.y;
    sumB.z = b->z + sumB.z;
    n = n + 1;
    f8c = c + f8c;
    f90 = d + f90;
}

} // namespace fn_f910b875

// 0x0030d850 FUN_0030d850 (65 B): equivalent/0x0030d850.cpp
// sym: ?FUN_0030d850@Range_30d850@owners@@QAEXIIIII@Z @ce5f28068536 @w49bc264b0c5a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0030d850 @ 0x0030d850
void owners::Range_30d850::FUN_0030d850(uint first, uint firstValue, uint second, uint secondValue, hulk_uintptr last)
{
    if (first < second) {
        low = first;
        lowValue = firstValue;
        high = second;
        highValue = secondValue;
    } else {
        low = second;
        lowValue = secondValue;
        high = first;
        highValue = firstValue;
    }
    extra = ((uint)last);
}


// 0x0030d8b0 physics::CollisionAnalyser::vfunc_1 (14 B): matches/0x0030d8b0.cpp
// sym: ?vfunc_1@CollisionAnalyser@physics@@UAEXPAX0@Z
void physics::CollisionAnalyser::vfunc_1(void* __p0, void* __p1) { void * p = (void *)__p1;

    this->f_0c = (hulk_uintptr)p;
    this->f_10 = 1;
}


// 0x0030d8c0 physics::CollisionAnalyser::vfunc_3 (56 B): matches/0x0030d8c0.cpp
// sym: ?vfunc_3@CollisionAnalyser@physics@@UAE_NPAXH@Z
bool physics::CollisionAnalyser::vfunc_3(void* __p0, int unused) { Param_30d8c0 * p = (Param_30d8c0 *)__p0;

    this->f_54 = p->x;
    this->f_58 = p->y;
    this->f_5c = p->z;
    this->f_60 = p->p1->value;
    this->f_64 = p->p2->value;
    this->f_68 = this->f_60 | this->f_64;
    return this->f_68 == 0;
}

namespace fn_f910b875 {

// 0x0030d900 FUN_0030d900 (120 B): matches/0x0030d900.cpp
// sym: ?Find@CollisionAnalyser_30d900@fn_f910b875@@QAEHPAH@Z
// data: gCache_30d900 = DAT_00555494
hulk_intptr CollisionAnalyser_30d900::Find(int* key) {
    int* first = begin;
    int* last = end;
    if (first > last)
        return 0;
    if (!((*(int**)&DAT_00555494) <= last && (*(int**)&DAT_00555494) >= first)) {
        (*(int**)&DAT_00555494) = first;
    }
    int* p = (*(int**)&DAT_00555494);
    int* start = p;
    do {
        if (key[0] == p[0] && key[2] == p[2] && key[1] == p[1] && key[3] == p[3]) {
            (*(int**)&DAT_00555494) = p;
            return p[4];
        }
        if (p == last)
            p = first;
        else
            p += 5;
    } while (p != start);
    (*(int**)&DAT_00555494) = p;
    return 0;
}


// 0x0030d980 FUN_0030d980 (39 B): matches/0x0030d980.cpp
// sym: ?Target@Owner_30d980@fn_f910b875@@QAEXXZ
void Owner_30d980::Target() {
    Item_30d980* p = begin;
    if (p <= end) {
        do {
            p->sub->Process_00319f40();
            Item_30d980* old = p;
            p = (Item_30d980*)((char*)p + 0x14);
            if (old == end)
                break;
        } while (1);
    }
}


// 0x0030d9b0 FUN_0030d9b0 (39 B): matches/0x0030d9b0.cpp
// sym: ?Target@Owner_30d9b0@fn_f910b875@@QAEXXZ
// Same code shape as 0x0030d980 (propagated; names are from that function)
void Owner_30d9b0::Target() {
    Item_30d9b0* p = begin;
    if (p <= end) {
        do {
            ((owners::Thing_319ef0 *)(p->sub))->FUN_00319ef0();
            Item_30d9b0* old = p;
            p = (Item_30d9b0*)((char*)p + 0x14);
            if (old == end)
                break;
        } while (1);
    }
}


// 0x0030d9e0 FUN_0030d9e0 (52 B): matches/0x0030d9e0.cpp
// sym: ?scan@Container_30d9e0@fn_f910b875@@QAEXH@Z
void Container_30d9e0::scan(int key) {
    Entry_30d9e0* p = begin;
    if (p <= end) {
        do {
            if (p->a == key || p->key == key)
                ((owners::Thing_319ef0 *)(p->object))->FUN_00319ef0();
            Entry_30d9e0* last = end;
            Entry_30d9e0* old = p;
            p = (Entry_30d9e0*)((char*)p + 20);
            if (old == last)
                break;
        } while (1);
    }
}


// 0x0030dbd0 FUN_0030dbd0 (65 B): matches/0x0030dbd0.cpp
// sym: ?FUN_0030dbd0@fn_f910b875@@YAPAUItem@1@PAU21@00@Z
Item* __cdecl FUN_0030dbd0(Item* first, Item* last, Item* dest) {
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}


// 0x0030dcd0 FUN_0030dcd0 (30 B): matches/0x0030dcd0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f910b875@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_0031a800((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0030df50 FUN_0030df50 (321 B): equivalent/0x0030df50.cpp
// sym: ?FUN_0030df50@CollisionAnalyser_30df50@fn_f910b875@@QAEHXZ @bb55f6fc2c31 @w0b4373870c47
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 23/26, incomplete)
// FUN_0030df50 @ 0x0030df50
hulk_intptr CollisionAnalyser_30df50::FUN_0030df50()
{
    if ((((char *)freeEnd - (char *)freeBegin) & ~3) != 0) {
        freeEnd = freeEnd - 1;
        return *freeEnd;
    }

    Elem_30df50 tmp;
    Elem_30df50 *added = 0;
    hulk_intptr count = elemEnd - elemBegin;

    if (count == 0) {
        Elem_30df50 *src = tmp.FUN_0031a440();
        bool ok;
        Elem_30df50 *end = elemEnd;
        if (end < elemCap) {
            elemEnd = end + 1;
            if (end)
                end->FUN_0031a4f0(src);
            ok = true;
        } else {
            ok = false;
        }
        tmp.FUN_0031a800();
        if (ok)
            added = elemEnd - 1;
        return (hulk_intptr)added;
    }

    Elem_30df50 *oldBegin = elemBegin;
    Elem_30df50 *src = tmp.FUN_0031a440();
    bool ok;
    Elem_30df50 *end = elemEnd;
    if (end < elemCap) {
        elemEnd = end + 1;
        if (end)
            end->FUN_0031a4f0(src);
        ok = true;
    } else {
        ok = false;
    }
    tmp.FUN_0031a800();
    if (ok)
        added = elemEnd - 1;

    if (oldBegin != elemBegin) {
        hulk_intptr delta = (char *)elemBegin - (char *)oldBegin;
        Range_30df50 *r = rangesBegin;
        if (!(r > rangesEnd)) {
            Range_30df50 *prev;
            do {
                r->offset += delta;
                prev = r;
                r++;
            } while (prev != rangesEnd);
        }
        for (unsigned i = 0; i < (unsigned)(freeEnd - freeBegin); i++)
            freeBegin[i] += delta;
    }
    return (hulk_intptr)added;
}


// 0x0030e0a0 FUN_0030e0a0 (237 B): equivalent/0x0030e0a0.cpp
// sym: ?target@Manager_30e0a0@fn_f910b875@@QAEXXZ @41508ee1a5b4 @wfe72acdc62a4
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 15/16, incomplete)
// FUN_0030e0a0 @ 0x0030e0a0
// FUN_0030e0a0 @ 0x0030e0a0
void Manager_30e0a0::target() {
 Entry_30e0a0* p=last;
 if ((hulk_uintptr)first>(hulk_uintptr)p) return;
 for (;;) {
  if(((owners::Obj_319d20 *)(p->item))->FUN_00319d20()) {
   p->item->FUN_0031a400();
   Item_30e0a0** dest=out;
   if((hulk_uintptr)dest<(hulk_uintptr)outEnd) { out=(Item_30e0a0**)((hulk_uintptr)dest+4); if(dest) *dest=p->item; }
   int index=((int)((hulk_uintptr)p-(hulk_uintptr)first))/20;
   Entry_30e0a0* e=storage+index;
   FUN_0030dbd0(e+1,end,e);
   end=(Entry_30e0a0*)((hulk_uintptr)end-20);
  }
  Entry_30e0a0* prev=p; p=(Entry_30e0a0*)((hulk_uintptr)p-20);
  if(prev==first) break;
 }
 int count=((int)((hulk_uintptr)end-(hulk_uintptr)storage))/20;
 if(!count) { last=0; first=(Entry_30e0a0*)20; return; }
 p=storage; first=p; last=p+count-1;
 for(;;) {
  if((double)p->item->time+(double)(*(float*)&DAT_003f5d00) < (double)cutoff) ((owners::Thing_319ef0 *)(p->item))->FUN_00319ef0();
  Entry_30e0a0* prev=p; p=(Entry_30e0a0*)((hulk_uintptr)p+20);
  if(prev==last) break;
 }
}

} // namespace fn_f910b875

// 0x0030e190 FUN_0030e190 (15 B): matches/0x0030e190.cpp
// sym: ?FUN_0030e190@A_30e190@owners@@QAEXH@Z
void owners::A_30e190::FUN_0030e190(int x) {
    value = x;
    refresh();
}


// 0x0030e250 physics::CollisionAnalyser::vfunc_2 (46 B): matches/0x0030e250.cpp
// sym: ?vfunc_2@CollisionAnalyser@physics@@UAEXHH@Z
void physics::CollisionAnalyser::vfunc_2(int , int ) {
    ((CollisionAnalyser_nv_30e250*)this)->init_0030e0a0();
    unsigned char* p = (*(unsigned char * *)&this->f_04);
    this->f_10 = 0;
    if (p <= (*(unsigned char * *)&this->f_08)) {
        do {
            ((Elem_30e250*)*(void**)(p + 0x10))->process_00319f40();
            unsigned char* old = p;
            p += 0x14;
            if (old == (*(unsigned char * *)&this->f_08))
                break;
        } while (1);
    }
}

namespace fn_f910b875 {

// 0x0030e280 FUN_0030e280 (89 B): equivalent/0x0030e280.cpp
// sym: ?FUN_0030e280@CollisionAnalyser_30e280@fn_f910b875@@QAEPAUItem@2@XZ @53f8cef330f7 @w4d70593c8693
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_0030e280 @ 0x0030e280
Item* CollisionAnalyser_30e280::FUN_0030e280() {
 Item* result = 0;
 if ((hulk_ulongptr)end < (hulk_ulongptr)limit) {
  Item* p = end;
  end = p + 1;
  if (p) { p->a=0; p->c=0; p->b=0; p->d=0; p->e=0; }
  result = end - 1;
 }
 first = begin;
 last = (Item*)((char*)begin + (((int)((char*)end-(char*)begin)/20)*20) - 20);
 return result;
}


// 0x0030e480 FUN_0030e480 (228 B): matches/0x0030e480.cpp
// sym: ??0CollisionAnalyser_30e480@fn_f910b875@@QAE@XZ
CollisionAnalyser_30e480::CollisionAnalyser_30e480() throw() {
    m8 = 0;
    m4 = 0x14;
    mc = 0;
    c10 = 0;
    char* p = (char*)FUN_0008d6d0(0x28000);
    b0.a = p;
    if (p) {
        b0.b = p;
        b0.c = p + 0x28000;
    } else {
        b0.b = 0;
        b0.c = 0;
    }
    p = (char*)FUN_0008d6d0(0x8000);
    b1.a = p;
    if (p) {
        b1.b = p;
        b1.c = p + 0x8000;
    } else {
        b1.b = 0;
        b1.c = 0;
    }
    p = (char*)FUN_0008d6d0(0x148000);
    b2.a = p;
    if (p) {
        b2.b = p;
        b2.c = p + 0x148000;
    } else {
        b2.b = 0;
        b2.c = 0;
    }
    p = (char*)FUN_0008d6d0(0x8000);
    b3.a = p;
    if (p) {
        b3.b = p;
        b3.c = p + 0x8000;
    } else {
        b3.b = 0;
        b3.c = 0;
    }
}


// 0x0030e570 FUN_0030e570 (146 B): matches/0x0030e570.cpp
// sym: ??1CollisionAnalyser_30e570@fn_f910b875@@QAE@XZ
CollisionAnalyser_30e570::~CollisionAnalyser_30e570() throw() {
    vptr = hulk_at_00431fe0;
    E1* p = m4;
    if (p <= m8) {
        E1* c;
        do {
            p->s->Fini_00319ef0();
            c = p;
            p++;
        } while (c != m8);
    }
    m48 = m44;
    if (m44)
        operator delete(m44);
    E2* e = m38;
    for (E2* q = m34; q != e; q++)
        q->Fini_0031a800();
    m38 = m34;
    if (m34)
        operator delete(m34);
    m28 = m24;
    if (m24)
        operator delete(m24);
    m18 = m14;
    if (m14)
        operator delete(m14);
}


// 0x0030e610 physics::CollisionAnalyser::vfunc_0 (30 B): matches/0x0030e610.cpp
// sym: ?vfunc_2@CollisionAnalyser_30e610@fn_f910b875@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CollisionAnalyser_30e610* CollisionAnalyser_30e610::vfunc_2(unsigned char flags) {
    ((CollisionAnalyser_nv_30e610*)(((physics::CollisionAnalyser*)(this))))->FUN_0030e570();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f910b875
