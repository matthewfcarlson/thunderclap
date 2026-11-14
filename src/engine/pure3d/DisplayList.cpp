// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0029b490..0x0029c050 (kind game, layer engine, confidence medium), dominant class pure3d::DisplayList
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f6d36770 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f6d36770 {} using namespace fn_f6d36770;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f6d36770 {
class Item_29b690 {
  public:
    virtual void f();
    virtual void g();
};
class Owner_29b690 {
    char pad0[0x10];

  public:
    int index;
    char pad14[8];
    Item_29b690** slots;
    void Add(Item_29b690*);
};
struct Mat_29b750 {
    float m[16];
};
struct V3_29b750 {
    float x, y, z;
};
struct Box_29b750 {
    float f[6];
};
struct RefObj_29b750 {
    virtual void AddRef();
    virtual void Release();
};
struct Elem_29b750 {
    Mat_29b750 mat;
    RefObj_29b750 *ref0;
    RefObj_29b750 *ref1;
};
struct Provider_29b750 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual const Mat_29b750 *v18(int arg);
};
struct Cam_29b750 {
    char pad[0x30];
    V3_29b750 pos;
};
struct CamHolder {
    Cam_29b750 *FUN_0028faa0();
};
struct Hdr_29b750 {
    char pad[0x4c];
    V3_29b750 pos;
};
struct Culler {
    bool FUN_001c2870(const Box_29b750 *box);
};
struct Entry_29b750 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(Elem_29b750 *elem, unsigned int idx, int x);
    char pad04[4];
    char kind;
    char pad09[3];
    unsigned int mask;
    int key;
};
struct Obj_29b750 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual unsigned int v5();
    char pad04[0x10];
    Box_29b750 box;
    int FUN_002a50b0();
};
struct Handler_29b750 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual int v5(int key);
};
struct Item_29b750 {
    Obj_29b750 *obj;
    int pad[3];
};
struct Node : public RefObj_29b750 {
    char pad04[0xc];
    Handler_29b750 *handler;
    char pad14[0x40 - 0x14];
    int extra;
    Node *parent;
    Item_29b750 *begin;
    Item_29b750 *end;
};
class Binder_29b750 {
public:
    char pad0[0x10];
    unsigned int entryCount;
    unsigned int index;
    Hdr_29b750 *hdr;
    Entry_29b750 **entries;
    char pad20[8];
    Elem_29b750 *elems;

    int FUN_0029b750(Node *a1, const Mat_29b750 *a2, RefObj_29b750 *a3);
};
struct Mat64 {
    int w[16];
};
class Counted_29b9d0 {
public:
    virtual void addRef();
    virtual void release();
};
class Provider_29b9d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual Mat64 *getMatrix(int a);
};
class Source_29b9d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual unsigned getMask();
    virtual void v6();
    virtual void *getKey();
    virtual void apply(void *a);
    int FUN_002a50b0();
};
class Target_29b9d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void *v3(void *a);
    virtual void *v4(void *a);
};
struct SourceRef {
    Source_29b9d0 *src;
    char pad[12];
};
struct Entry_29b9d0;
class Listener_29b9d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void onMatch(Entry_29b9d0 *e, int idx, int extra);
    char pad04[4];
    char kind;
    char pad09[3];
    unsigned mask;
    int key;
};
struct Entry_29b9d0 {
    Mat64 mat;
    Counted_29b9d0 *objA;
    Counted_29b9d0 *objB;
};
class Anim_29b9d0 : public Counted_29b9d0 {
public:
    char pad4[0xc];
    Target_29b9d0 *target;
    char pad14[0x40 - 0x14];
    int f40;
    char pad44[4];
    SourceRef *sources;
};
class Mixer {
public:
    char pad0[0x10];
    unsigned listenerCount;
    int cur;
    char pad18[4];
    Listener_29b9d0 **listeners;
    char pad20[8];
    Entry_29b9d0 *entries;
    void FUN_0029b9d0(Anim_29b9d0 *anim, int idx, Mat64 *m, Counted_29b9d0 *q);
};
class Item_29bb60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class Owner_29bb60 {
  public:
    char pad0[0x10];
    unsigned int count;
    char pad14[8];
    Item_29bb60** items;
};
class Item_29bba0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Ref_29bba0 {
  public:
    virtual void a();
    virtual void Destroy();
};
struct Ref_29bc80 {
    virtual void add();
    virtual void release();
};
struct Item_29bc80 {
    char pad[20];
    Ref_29bc80* ref;
};
struct Owner_29bc80 {
    char pad[16];
    unsigned count;
    char pad2[4];
    Ref_29bc80* ref;
    Item_29bc80** items;
    void set(Ref_29bc80* p);
};
extern void* hulk_at_0042d59c[];
} // namespace fn_f6d36770
void operator delete(void*);
namespace fn_f6d36770 {
class Ref_29bdc0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_29bdc0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class DisplayList_29bdc0 : public Entity_29bdc0 {
  public:
    char pad[0xc];
    unsigned m10;
    char pad1[4];
    Ref_29bdc0* m18;
    Ref_29bdc0** m1c;
    char pad2[8];
    void* m28;
    ~DisplayList_29bdc0() throw();
};


// 0x0029b490 FUN_0029b490 (4 B): matches/0x0029b490.cpp
// sym: ?FUN_0029b490@fn_f6d36770@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
hulk_intptr __fastcall FUN_0029b490(hulk_intptr object) {
    return *(int*)(object + 0x18);
}


// 0x0029b690 FUN_0029b690 (50 B): matches/0x0029b690.cpp
// sym: ?Add@Owner_29b690@fn_f6d36770@@QAEXPAVItem_29b690@2@@Z
void Owner_29b690::Add(Item_29b690* item) {
    if (item) {
        Item_29b690** slot = slots + index;
        item->f();
        if (*slot)
            (*slot)->g();
        *slot = item;
        ++index;
    }
}

} // namespace fn_f6d36770

// 0x0029b6d0 FUN_0029b6d0 (23 B): matches/0x0029b6d0.cpp
// sym: ?FUN_0029b6d0@X_29b6d0@owners@@QAEII@Z
hulk_uintptr owners::X_29b6d0::FUN_0029b6d0(unsigned i) {
    if (i < count)
        return items[i];
    return 0;
}

namespace fn_f6d36770 {

// 0x0029b750 FUN_0029b750 (630 B): equivalent/0x0029b750.cpp
// sym: ?FUN_0029b750@Binder_29b750@fn_f6d36770@@QAEHPAUNode@2@PBUMat_29b750@2@PAURefObj_29b750@2@@Z @9e349daa0bae @web9ad2872b3e
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 42/42)
// FUN_0029b750 @ 0x0029b750
int Binder_29b750::FUN_0029b750(Node *a1, const Mat_29b750 *a2, RefObj_29b750 *a3)
{
    struct Frame {
        int count;
        unsigned int i;
        int key;
        union {
            V3_29b750 v3;
            Box_29b750 box;
        } u;
        int extra;
        Obj_29b750 *nodes[256];
    } fr;

    if (hdr != 0 && a1->parent == a1) {
        fr.u.v3 = (*(*(CamHolder***)&DAT_0052c2b0))->FUN_0028faa0()->pos;
        if (a2 != 0)
            ((owners::Obj_22d210 *)&(fr.u.v3))->FUN_0022d210((owners::Obj_22d210 *)(const Mat_29b750 *)a2);
        hdr->pos = fr.u.v3;
        ((owners::Caller_29fd20 *)hdr)->FUN_0029fd20((hulk_intptr)(a1->parent));
    }

    if (a2 != 0) {
        Elem_29b750 *e = &elems[index];
        ((owners::Matrix_22ca90 *)e)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat_29b750 *)a2, (const owners::Matrix_22ca90 *)(const Mat_29b750 *)((*(*(Provider_29b750***)&DAT_0052c2ac))->v18(0)));
    } else {
        Elem_29b750 *e = &elems[index];
        e->mat = *(*(*(Provider_29b750***)&DAT_0052c2ac))->v18(0);
    }

    RefObj_29b750 **slot0 = &elems[index].ref0;
    if (a1 != 0)
        a1->AddRef();
    if (*slot0 != 0)
        (*slot0)->Release();
    *slot0 = a1;

    RefObj_29b750 **slot1 = &elems[index].ref1;
    if (a3 != 0)
        a3->AddRef();
    if (*slot1 != 0)
        (*slot1)->Release();
    *slot1 = a3;

    fr.extra = a1->extra;
    fr.count = a1->end - a1->begin;
    unsigned int n;
    for (n = 0; n < (unsigned int)fr.count; n++) {
        Obj_29b750 *o = a1->begin[n].obj;
        if ((*(Culler**)&DAT_004e2350) != 0) {
            fr.u.box = o->box;
            if ((*(Culler**)&DAT_004e2350)->FUN_001c2870(&fr.u.box))
                fr.nodes[n] = o;
            else
                fr.nodes[n] = 0;
        } else {
            fr.nodes[n] = o;
        }
    }

    for (fr.i = 0; fr.i < (unsigned int)fr.count; fr.i++) {
        Obj_29b750 *o = fr.nodes[fr.i];
        if (o == 0)
            continue;
        fr.key = o->FUN_002a50b0();
        if (a1->handler != 0)
            fr.key = a1->handler->v5(fr.key);
        unsigned int j;
        for (j = 0; j < entryCount; j++) {
            Entry_29b750 *ent = entries[j];
            if (ent->kind == 1) {
                unsigned int m = ent->mask;
                unsigned int r = o->v5();
                if ((m & r) != 0) {
                    Entry_29b750 *ent2 = entries[j];
                    if (ent2->key == fr.key)
                        ent2->v6(&elems[index], fr.i, fr.extra);
                }
            }
        }
    }
    return ++index;
}


// 0x0029b9d0 FUN_0029b9d0 (396 B): matches/0x0029b9d0.cpp
// sym: ?FUN_0029b9d0@Mixer@fn_f6d36770@@QAEXPAVAnim_29b9d0@2@HPAUMat64@2@PAVCounted_29b9d0@2@@Z
// FUN_0029b9d0 @ 0x0029b9d0
void Mixer::FUN_0029b9d0(Anim_29b9d0 *anim, int idx, Mat64 *m, Counted_29b9d0 *q)
{
    if (m) {
        Entry_29b9d0 *e = &entries[cur];
        Mat64 *src = (*(*(Provider_29b9d0***)&DAT_0052c2ac))->getMatrix(0);
        ((owners::Matrix_22ca90 *)&(e->mat))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat64 *)m, (const owners::Matrix_22ca90 *)(Mat64 *)src);
    } else {
        Entry_29b9d0 *e = &entries[cur];
        Mat64 *src = (*(*(Provider_29b9d0***)&DAT_0052c2ac))->getMatrix(0);
        e->mat = *src;
    }

    Counted_29b9d0 **slotA = &entries[cur].objA;
    if (anim)
        anim->addRef();
    if (*slotA)
        (*slotA)->release();
    *slotA = anim;

    Counted_29b9d0 **slotB = &entries[cur].objB;
    if (q)
        q->addRef();
    if (*slotB)
        (*slotB)->release();
    *slotB = q;

    int extra = anim->f40;
    Source_29b9d0 *r = anim->sources[idx].src;
    Target_29b9d0 *t = anim->target;
    if (t)
        r->apply(t->v3(r->getKey()));

    for (unsigned i = 0; i < listenerCount; i++) {
        Listener_29b9d0 *l = listeners[i];
        if (l->kind == 1) {
            unsigned lm = l->mask;
            if (lm & r->getMask()) {
                int k = listeners[i]->key;
                if (k == r->FUN_002a50b0())
                    listeners[i]->onMatch(&entries[cur], idx, extra);
            }
        }
    }

    t = anim->target;
    if (t)
        r->apply(t->v4(r->getKey()));
    cur++;
}


// 0x0029bb60 FUN_0029bb60 (49 B): matches/0x0029bb60.cpp
// sym: ?FUN_0029bb60@fn_f6d36770@@YIXPAVOwner_29bb60@1@@Z
void __fastcall FUN_0029bb60(Owner_29bb60* self) {
    for (unsigned int i = 0; i < self->count; ++i) {
        self->items[i]->f3();
        self->items[i]->f4();
    }
}

} // namespace fn_f6d36770

// 0x0029bba0 FUN_0029bba0 (131 B): matches/0x0029bba0.cpp
// sym: ?FUN_0029bba0@DisplayList@pure3d@@QAEXXZ
void pure3d::DisplayList::FUN_0029bba0() {
    unsigned int i = 0;
    while (i < (*(unsigned int *)&this->f_10)) {
        (*(Item_29bba0 ** *)&this->f_1c)[i]->f();
        ++i;
    }
    unsigned int j = 0;
    unsigned int off = 0;
    while (j < (*(unsigned int *)&this->f_14)) {
        Ref_29bba0** p = (Ref_29bba0**)((char*)(*(void * *)&this->f_28) + off + 0x40);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        p = (Ref_29bba0**)((char*)(*(void * *)&this->f_28) + off + 0x44);
        if (*p) {
            (*p)->Destroy();
            *p = 0;
        }
        ++j;
        off += 0x48;
    }
    (*(unsigned int *)&this->f_14) = 0;
}

namespace fn_f6d36770 {

// 0x0029bc80 FUN_0029bc80 (96 B): matches/0x0029bc80.cpp
// sym: ?set@Owner_29bc80@fn_f6d36770@@QAEXPAURef_29bc80@2@@Z
void Owner_29bc80::set(Ref_29bc80* p) {
    if (p)
        p->add();
    if (ref)
        ref->release();
    ref = p;
    _ReadWriteBarrier();
    for (unsigned i = 0; i < count; ++i) {
        Ref_29bc80** slot = &items[i]->ref;
        if (p)
            p->add();
        if (*slot)
            (*slot)->release();
        *slot = p;
    }
}


// 0x0029bdc0 FUN_0029bdc0 (125 B): matches/0x0029bdc0.cpp
// sym: ??1DisplayList_29bdc0@fn_f6d36770@@QAE@XZ
DisplayList_29bdc0::~DisplayList_29bdc0() throw() {
    vptr = hulk_at_0042d59c;
    _ReadWriteBarrier();
    ((pure3d::DisplayList *)this)->FUN_0029bba0();
    for (unsigned i = 0; i < m10; i++) {
        Ref_29bdc0** p = &m1c[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m28)
        operator delete(m28);
    if (m1c)
        operator delete(m1c);
    Fin_0027afd0();
}

} // namespace fn_f6d36770

// 0x0029bea0 FUN_0029bea0 (160 B): equivalent/0x0029bea0.cpp [wrapped: conflict: pure3d::DisplayList]
// sym: ??0DisplayList@pure3d@fn_0029bea0@@QAE@II@Z @df288fd77dd0 @wc0ad1cb2719b
namespace fn_0029bea0 {
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 8/8)
// FUN_0029bea0 @ 0x0029bea0
void* __cdecl FUN_0008d6d0(unsigned int size);
struct FUN_0027b070 {
 virtual void slot0();
 char padding[12];
 FUN_0027b070();
};
namespace pure3d {
struct DisplayList : FUN_0027b070 {
 virtual void slot0();
 unsigned int field10, field14, field18;
 unsigned int* entries;
 char* entriesEnd;
 unsigned int field24;
 unsigned char* records;
 unsigned char* recordsEnd;
 DisplayList(unsigned int count, unsigned int recordCount);
};
DisplayList::DisplayList(unsigned int count, unsigned int recordCount) {
 field10=0; field14=0; field18=0;
 if(count>0) {
  unsigned int bytes=count*4;
  entries=(unsigned int*)FUN_0008d6d0(bytes);
  if(entries) entriesEnd=(char*)entries+bytes;
  else {entries=0; entriesEnd=0;}
 } else {entries=0; entriesEnd=0;}
 if(recordCount>0) {
  unsigned int bytes=recordCount*72;
  records=(unsigned char*)FUN_0008d6d0(bytes);
  if(records) recordsEnd=records+bytes;
  else {records=0; recordsEnd=0;}
 } else {records=0; recordsEnd=0;}
 unsigned int bytes=recordCount*72;
 unsigned int* destination=(unsigned int*)records;
 for(unsigned int i=0;i<bytes/4;++i) destination[i]=0;
 destination=entries;
 for(unsigned int j=0;j<count;++j) destination[j]=0;
}
}
} // namespace fn_0029bea0


// 0x0029bf40 pure3d::DisplayList::vfunc_2 (30 B): matches/0x0029bf40.cpp
// sym: ??_GDisplayList@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::DisplayList::~DisplayList() {}

