// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ebb90..0x000ec350 (kind game, layer game, confidence medium), dominant class MenuSelector
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9e7f90b {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9e7f90b {} using namespace fn_f9e7f90b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9e7f90b {
struct Item_ebb90 { char pad[0x24]; int a; int b; char tail[12]; void FUN_000f7930(); };
struct FUN_000e9240 { virtual void slot0(); char pad[0x13c]; unsigned char flag; char tail[15]; FUN_000e9240(int); };
struct TextSelector : FUN_000e9240 {
 virtual void slot0();
 int count, index;
 Item_ebb90 items[128];
 int f1d58, f1d5c; char gap60[8];
 float f1d68, f1d6c, f1d70; char gap74[8];
 int f1d7c,f1d80; unsigned char wrap; char gap85[3];
 int f1d88,f1d8c,f1d90,f1d94,f1d98,f1d9c,f1da0; unsigned int color;
 TextSelector(int arg, const char* name);
};
extern void* g_vftable_ebca0[];
class Ref_ebca0 {
  public:
    virtual void F0();
    virtual void Release();
};
} // namespace fn_f9e7f90b
void operator delete[](void*) throw();
namespace fn_f9e7f90b {
struct Mgr_ebca0 {
};
struct Own_ebca0 {
    char p[8];
    Mgr_ebca0* m8;
};
struct Sub_ebca0 {
    char c;
    void Fin() throw();
};
struct Elt {
    Sub_ebca0 s;
    char p[0x27];
    Ref_ebca0* r;
    char p2[0xc];
    void Fin() throw();
};
class TextSelector_ebca0 {
  public:
    void* vptr;
    char p[0x14];
    Sub_ebca0 s18;
    char p2[0x37];
    Ref_ebca0* m50;
    char p3[0xc];
    Ref_ebca0* m60;
    Ref_ebca0* m64;
    char p4[0x40];
    Own_ebca0* ma8;
    char* mac;
    char p5[0xa8];
    Elt e[128];
    char pq[0x34];
    Ref_ebca0* m1d8c;
    Ref_ebca0* m1d90;
    char* m1d94;
    void Pre() throw();
    ~TextSelector_ebca0() throw();
};
class A_ebda0 {
  public:
    virtual void f();
};
class B_ebda0 {
  public:
    virtual void f();
    virtual void g();
};
class C_ebda0 {
    char pad[0x1d8c];
    B_ebda0* m;

  public:
    void set(A_ebda0*);
};
class Thing_ebdd0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_ebdd0 {
  public:
    char pad[0x1d90];
    Thing_ebdd0* ptr;
    void Set(Thing_ebdd0* p);
};
struct Entry_ebe00 {
 char base[0x24];
 int a,b,c,d;
 unsigned char flag;
 char pad[3];
 void FUN_000f83c0(Entry_ebe00*);
};
struct Object {
 char pad0[0x118];
 unsigned int block[10];
 char pad1[0x10];
 int x150,x154;
 Entry_ebe00 entries[128];
 int count;
 int x1d5c;
 char pad2[8];
 int x1d68;
 char pad3[0x10];
 int x1d7c,x1d80;
 void FUN_000e2940(Object*);
 void FUN_000e36c0();
 void FUN_000ebe00(Object* src);
};
extern "C" char DAT_0040c554[];
class MenuSelector {
  public:
    void* vptr;
    char pad[0x1da4];
    unsigned char flag;
    unsigned char data[0x80 * 0x40];
    void Init(unsigned int, unsigned int);
    MenuSelector* Target(unsigned int, unsigned int);
};


// 0x000ebb90 FUN_000ebb90 (260 B): equivalent/0x000ebb90.cpp
// sym: ??0TextSelector@fn_f9e7f90b@@QAE@HPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000ebb90 @ 0x000ebb90
TextSelector::TextSelector(int arg,const char* name) : FUN_000e9240(arg) {
 count=0; index=0;
 for(int i=0;i<128;++i) items[i].FUN_000f7930();
 f1d5c=0; f1d68=1.0f; f1d6c=0.05f; f1d70=0.02f;
 f1d7c=0; f1d80=0; wrap=0; f1d88=0; f1d8c=0; f1d90=0; f1d98=0;
 f1d9c=-1; f1da0=-1; color=0xff000000;
 f1d58=0; count=0; index=0; f1d94=0; flag=0;
 if(name) { const char* s="wrap"; int j=0; for(;j<5;++j) if(name[j]!=s[j]) break; if(j==5) wrap=1; }
 for(int k=0;k<128;++k) { items[k].a=0; items[k].b=0; }
}


// 0x000ebca0 FUN_000ebca0 (245 B): matches/0x000ebca0.cpp
// sym: ??1TextSelector_ebca0@fn_f9e7f90b@@QAE@XZ
TextSelector_ebca0::~TextSelector_ebca0() throw() {
    vptr = g_vftable_ebca0;
    if (m1d94) {
        ((owners::Obj_f8c30 *)(ma8->m8))->FUN_000f8c30((const char *)(m1d94 + 0x18));
        m1d94 = 0;
    }
    Pre();
    for (int i = 0; i < 128; i++)
        if (e[i].r) {
            e[i].r->Release();
            e[i].r = 0;
        }
    if (m1d8c) {
        m1d8c->Release();
        m1d8c = 0;
    }
    if (m1d90) {
        m1d90->Release();
        m1d90 = 0;
    }
    {
        Elt* q = e + 128;
        for (int i = 128; i > 0; i--) {
            q--;
            q->Fin();
        }
    }
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete[](mac);
        mac = 0;
    }
    s18.Fin();
}


// 0x000ebda0 FUN_000ebda0 (44 B): matches/0x000ebda0.cpp
// sym: ?set@C_ebda0@fn_f9e7f90b@@QAEXPAVA_ebda0@2@@Z
void C_ebda0::set(A_ebda0* p) {
    if (p)
        p->f();
    if (m)
        m->g();
    m = (B_ebda0*)p;
}


// 0x000ebdd0 FUN_000ebdd0 (44 B): matches/0x000ebdd0.cpp
// sym: ?Set@Owner_ebdd0@fn_f9e7f90b@@QAEXPAVThing_ebdd0@2@@Z
void Owner_ebdd0::Set(Thing_ebdd0* p) {
    if (p)
        p->A();
    if (ptr)
        ptr->B();
    ptr = p;
}


// 0x000ebe00 FUN_000ebe00 (232 B): equivalent/0x000ebe00.cpp
// sym: ?FUN_000ebe00@Object@fn_f9e7f90b@@QAEXPAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 749 inputs, branch coverage 4/4)
// FUN_000ebe00 @ 0x000ebe00
void Object::FUN_000ebe00(Object* src) {
 FUN_000e2940(src);
 for(int j=0;j<10;++j) block[j]=src->block[j];
 FUN_000e36c0();
 count=src->count;
 x150=src->x150;
 x154=src->x154;
 x1d5c=src->x1d5c;
 x1d68=src->x1d68;
 x1d7c=src->x1d7c;
 x1d80=src->x1d80;
 for(int i=0;i<count;++i) {
 entries[i].FUN_000f83c0(&src->entries[i]);
 entries[i].a=src->entries[i].a;
 entries[i].b=src->entries[i].b;
 entries[i].c=src->entries[i].c;
 entries[i].d=src->entries[i].d;
 entries[i].flag=src->entries[i].flag;
 }
}


// 0x000ebef0 FUN_000ebef0 (63 B): matches/0x000ebef0.cpp
// sym: ?Target@MenuSelector@fn_f9e7f90b@@QAEPAV12@II@Z
MenuSelector* MenuSelector::Target(unsigned int a, unsigned int b) {
    Init(a, b);
    vptr = (void*)((hulk_intptr)DAT_0040c554);
    flag = 1;
    for (int i = 0; i < 0x80; ++i)
        data[i * 0x40] = 0;
    return this;
}

} // namespace fn_f9e7f90b

// 0x000ebf40 MenuSelector::vfunc_12 (781 B): equivalent/0x000ebf40.cpp [wrapped: conflict: MenuSelector]
// sym: ?vfunc_12@MenuSelector@fn_000ebf40@@UAE_NHH@Z
namespace fn_000ebf40 {
// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 39/42, incomplete)
// MenuSelector::vfunc_12 @ 0x000ebf40
struct ItemNode {
    char pad0[0xab8];
    unsigned char selected;     // 0xab8
};

struct Registry_ebf40 {
    ItemNode *FUN_000e6410(const char *name);
};

struct Inner_ebf40 {
    char pad0[4];
    Registry_ebf40 *registry;
};

struct Outer_ebf40 {
    char pad0[8];
    Inner_ebf40 *inner;
};

class Listener_ebf40 {
public:
    virtual void v0();
    virtual void notifyChanged();
    virtual void v2();
    virtual void v3();
    virtual bool v4(int kind, int id, int oldIndex, int newIndex);
};

struct Scroller {
    void FUN_000f8b90(int index);
};

class MenuSelector {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12(int msg, int arg);

    char pad04[0x10];
    Outer_ebf40 *outer;               // 0x14
    char pad18[0xa8 - 0x18];
    int id;                     // 0xa8
    char padac[0x118 - 0xac];
    Listener_ebf40 *listeners[10];    // 0x118
    char pad140[0x154 - 0x140];
    int sel;                    // 0x154
    char pad158[0x1d58 - 0x158];
    int count;                  // 0x1d58
    char pad1d5c[0x1d84 - 0x1d5c];
    unsigned char wrap;         // 0x1d84
    char pad1d85[0x1d94 - 0x1d85];
    Scroller *scroller;         // 0x1d94
    char pad1d98[0x1da9 - 0x1d98];
    char items[0x80][0x40];     // 0x1da9

    void FUN_000e30a0();
};

bool MenuSelector::vfunc_12(int msg, int arg)
{
    if (msg == 2) {
        int cur = sel;
        if (cur != 0x7f && items[cur + 1][0] != 0) {
            Registry_ebf40 *reg = outer->inner->registry;
            reg->FUN_000e6410(items[cur])->selected = 0;
            reg = outer->inner->registry;
            reg->FUN_000e6410(items[sel + 1])->selected = 1;
            int old = sel;
            for (int i = 0; i < 10 && listeners[i] != 0; i++) {
                if (listeners[i]->v4(4, id, old, old + 1))
                        listeners[i]->notifyChanged();
            }
            sel = sel + 1;
            FUN_000e30a0();
            return true;
        }
        if (!wrap)
            return true;
        Registry_ebf40 *reg = outer->inner->registry;
        reg->FUN_000e6410(items[cur])->selected = 0;
        reg = outer->inner->registry;
        reg->FUN_000e6410(items[0])->selected = 1;
        int old = sel;
        for (int i = 0; i < 10 && listeners[i] != 0; i++) {
            if (listeners[i]->v4(4, id, old, 0))
                    listeners[i]->notifyChanged();
        }
        sel = 0;
        if (scroller != 0)
            scroller->FUN_000f8b90(0);
        vfunc_0();
        return true;
    }
    if (msg != 6)
        return false;

    int cur = sel;
    if (cur == 0) {
        if (!wrap)
            return true;
        Registry_ebf40 *reg = outer->inner->registry;
        reg->FUN_000e6410(items[0])->selected = 0;
        reg = outer->inner->registry;
        reg->FUN_000e6410(items[count - 1])->selected = 1;
        int last = count - 1;
        int old = sel;
        for (int i = 0; i < 10 && listeners[i] != 0; i++) {
            if (listeners[i]->v4(4, id, old, last))
                    listeners[i]->notifyChanged();
        }
        sel = count - 1;
        FUN_000e30a0();
        return true;
    }
    Registry_ebf40 *reg = outer->inner->registry;
    reg->FUN_000e6410(items[cur])->selected = 0;
    reg = outer->inner->registry;
    reg->FUN_000e6410(items[sel - 1])->selected = 1;
    int old = sel;
    for (int i = 0; i < 10 && listeners[i] != 0; i++) {
        if (listeners[i]->v4(4, id, old, old - 1))
                listeners[i]->notifyChanged();
    }
    int next = sel - 1;
    sel = next;
    if (scroller != 0)
        scroller->FUN_000f8b90(next);
    vfunc_0();
    return true;
}
} // namespace fn_000ebf40


// 0x000ec250 MenuSelector::vfunc_25 (187 B): matches/0x000ec250.cpp [wrapped: conflict: MenuSelector]
// sym: ?vfunc_25@MenuSelector@fn_000ec250@@QAEXH@Z
namespace fn_000ec250 {
struct Item_ec250 {
    char pad[0xab8];
    unsigned char active;
};
struct Lookup_ec250 {
    Item_ec250* FUN_000e6410(const char*);
};
struct ContextInner_ec250 {
    char pad[4];
    Lookup_ec250* lookup;
};
struct Context {
    char pad[8];
    ContextInner_ec250* inner;
};
struct Receiver_ec250 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned char slot4(int, int, int, int);
};
struct SelectionSink {
    void FUN_000f8b90(int);
};
struct MenuSelector {
    virtual void vfunc_0();
    char pad04[0x10];
    Context* context;
    char pad18[0x90];
    int id;
    char padac[0x6c];
    Receiver_ec250* receivers[10];
    char pad140[0x14];
    int selected;
    char pad158[0x1c00];
    int count;
    char pad1d5c[0x38];
    SelectionSink* sink;
    char pad1d98[0x11];
    char names[1][64];
    void vfunc_25(int index);
};
void MenuSelector::vfunc_25(int index) {
    context->inner->lookup->FUN_000e6410(names[selected])->active = 0;
    context->inner->lookup->FUN_000e6410(names[index])->active = 1;
    int next = (index + 1) % count;
    for (int i = 0; i < 10 && receivers[i]; ++i) {
        if (receivers[i]->slot4(4, id, next, index))
            receivers[i]->slot1();
    }
    SelectionSink* currentSink = sink;
    selected = index;
    if (currentSink)
        currentSink->FUN_000f8b90(index);
    vfunc_0();
}
} // namespace fn_000ec250

