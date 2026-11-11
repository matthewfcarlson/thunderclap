// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00231e00..0x00232780 (kind game, layer engine, confidence high), dominant class fight::Action
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7416411 {
#define TREE_TU_END }
namespace fn_f7416411 {} using namespace fn_f7416411;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7416411 {
class C_231e50 {
  public:
    int x[10];
    C_231e50();
};
class C_231e80 {
  public:
    char pad0[0x14];
    struct N_231e80* m;
    bool f(void*);
};
struct N_231e80 {
    char pad0[8];
    N_231e80* next;
    char pad1[0x10];
    void* value;
};
class Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual char v5(int a, int b);
    char _m_pad_4[0x4];
    Node* next;
    unsigned int flags;
    char _m_pad_10[0x8];
    int f18;
    void FnF_00232600(int, int);
    void FUN_00232600(int a, int b);
};
class Owner_231f00 {
  public:
    char pad[0x20];
    Node* head;
    void Run();
};
int __cdecl FUN_00238190(int a);
int __cdecl FUN_00266da0(int a);
struct Target_231f20 {
    char pad0[0x20];
    Node *head;
    void FUN_00231f20(int arg);
};
class Item_232030 {
  public:
    virtual void First();
    virtual void Second();
};
class Holder_232030 {
  public:
    Item_232030* mItem;
    void Set(Item_232030* p);
};
class Ref_232060 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_232060 {
    char pad0[4];
    Ref_232060* first;
    int value;
    Ref_232060* second;
    int limit;

  public:
    bool Set(Ref_232060* a, int b, Ref_232060* c, int d);
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
struct Spec_2320d0 {
    char pad0[0x28];
    void *source;              // 0x28
};
class RefObj_2320d0 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Owner_2320d0;
class QueuedNodeAction_2320d0 : public RefObj_2320d0 {
public:
    char pad04[0x5c - 4];
    QueuedNodeAction_2320d0 *FUN_0023a2a0(Spec_2320d0 *spec, int a, Owner_2320d0 *owner, int b);
    void FUN_002326d0(QueuedNodeAction_2320d0 *other);
};
class Owner_2320d0 {
public:
    char pad0[0x14];
    RefObj_2320d0 *primary;           // 0x14
    QueuedNodeAction_2320d0 *secondary;           // 0x18
    bool FUN_002320d0(Spec_2320d0 *spec, hulk_intptr a, int b);
};
class Ref_232180 {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner_232180 {
  public:
    char pad[0x14];
    Ref_232180* second;
    Ref_232180* first;
    void Clear();
};
class Item_2321b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad14[4];
    Item_2321b0* next;
    unsigned int flags;
    void cleanup_00232600(int, int);
};
class Obj_2321b0 {
  public:
    Item_2321b0* first;
    char pad04[0x18];
    int value;
    Item_2321b0* list;
    Item_2321b0* extra;
    void run();
};
class Ref {
  public:
    virtual void f();
    virtual void release();
};
class Obj {
  public:
    char _m_pad_0[0x4];
    Ref* a;
    char _m_pad_8[0x4];
    Ref* b;
    int c;
    union { Ref* d; int value; };
    Ref* e;
    void Set(int x);
    void reset();
    void init_002321b0();
};
class Item_232290 {
  public:
    virtual void A();
    virtual void B();
    void Handle_002326d0(Item_232290*);
    float pad[3];
    float value;
};
class Owner_232290 {
  public:
    bool Attach(Item_232290* item);
    char pad0[0x1c];
    float amount;
    Item_232290* first;
    Item_232290* second;
};
class Ref_2322f0 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Item_2322f0 : public Ref_2322f0 {
public:
    virtual void v2();
    virtual bool Update(int arg, float dt);
    char pad04[4];
    Item_2322f0 *next;            // 0x08
    unsigned int flags;    // 0x0c
    float time;            // 0x10
    char pad14[4];
    float elapsed;         // 0x18
    void FUN_00232600(unsigned int mask, char set);
    void FUN_002326d0(Item_2322f0 *item);
};
class Sequence;
class Child_2322f0 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual Sequence *Match(int a, Ref_2322f0 *b);
    Child_2322f0 *next;           // 0x04
    void FUN_00236bc0(Ref_2322f0 *ctx, Sequence *seq, Ref_2322f0 *b);
};
class Context : public Ref_2322f0 {
public:
    char pad04[0x28 - 4];
    Child_2322f0 *children;       // 0x28
};
class Sequence {
public:
    Ref_2322f0 *owner;            // 0x00
    Context *ctx;          // 0x04
    int f8;
    Ref_2322f0 *fc;               // 0x0c
    char pad10[4];
    Item_2322f0 *pending;         // 0x14
    Ref_2322f0 *f18;
    float time;            // 0x1c
    Item_2322f0 *active;          // 0x20
    Item_2322f0 *tail;            // 0x24
    void FUN_002321b0();
    void FUN_002322f0(int arg, float dt);
};
class Action_232630 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Action_232650 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Action {
  public:
    virtual ~Action();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    Action();
};
extern "C" char DAT_004276ec[];
struct Ref_2326a0 {
    virtual void A();
    virtual void Release();
};
class Obj_2326d0 {
  public:
    virtual void F0();
    virtual void F1();
};
class Holder_2326d0 {
  public:
    char pad[8];
    Obj_2326d0* p;
    void Set(Obj_2326d0* value);
};
extern void* hulk_at_004276ec[];
extern void FUN_0008d330(void*);
class Ref_232700 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Action_232700 {
    void* vf;
    int p4;
    Ref_232700* p8;
    Action_232700* Dtor(unsigned char flag) throw();
};


// 0x00231e00 FUN_00231e00 (10 B): matches/0x00231e00.cpp
// sym: ?Set@Obj@fn_f7416411@@QAEXH@Z
void Obj::Set(int x) {
    value = x;
}


// 0x00231e50 FUN_00231e50 (34 B): matches/0x00231e50.cpp
// sym: ??0C_231e50@fn_f7416411@@QAE@XZ
C_231e50::C_231e50() {
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    x[5] = 0;
    x[6] = 0;
    x[7] = 0;
    x[8] = 0;
    x[9] = 0;
}


// 0x00231e80 FUN_00231e80 (38 B): matches/0x00231e80.cpp
// sym: ?f@C_231e80@fn_f7416411@@QAE_NPAX@Z
bool C_231e80::f(void* p) {
    N_231e80* n = m;
    while (n) {
        if (n->value == p)
            return true;
        n = n->next;
    }
    return false;
}

} // namespace fn_f7416411

// 0x00231ee0 FUN_00231ee0 (19 B): matches/0x00231ee0.cpp
// sym: ?FUN_00231ee0@C_231ee0@owners@@QAEEXZ
unsigned char owners::C_231ee0::FUN_00231ee0() {
    if (a)
        return 1;
    return b != 0;
}

namespace fn_f7416411 {

// 0x00231f00 FUN_00231f00 (28 B): matches/0x00231f00.cpp
// sym: ?Run@Owner_231f00@fn_f7416411@@QAEXXZ
void Owner_231f00::Run() {
    Node* n = head;
    while (n) {
        n->FnF_00232600(8, 1);
        n = n->next;
    }
}


// 0x00231f20 FUN_00231f20 (109 B): equivalent/0x00231f20.cpp
// sym: ?FUN_00231f20@Target_231f20@fn_f7416411@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2742 inputs, branch coverage 10/10)
// FUN_00231f20 @ 0x00231f20
void Target_231f20::FUN_00231f20(int arg)
{
    int h = FUN_00266da0(FUN_00238190(3));
    for (Node *n = head; n != 0; n = n->next) {
        unsigned int f = n->flags;
        if (((f >> 2) & 1) && !((f >> 3) & 1)) {
            if (!n->v5(arg, n->f18))
                n->FUN_00232600(8, 1);
        }
    }
    FUN_00266da0(h);
}


// 0x00232030 FUN_00232030 (36 B): matches/0x00232030.cpp
// sym: ?Set@Holder_232030@fn_f7416411@@QAEXPAVItem_232030@2@@Z
void Holder_232030::Set(Item_232030* p) {
    if (p)
        p->First();
    if (mItem)
        mItem->Second();
    mItem = p;
}


// 0x00232060 FUN_00232060 (112 B): matches/0x00232060.cpp
// sym: ?Set@Owner_232060@fn_f7416411@@QAE_NPAVRef_232060@2@H0H@Z
bool Owner_232060::Set(Ref_232060* a, int b, Ref_232060* c, int d) {
    if (!a)
        return false;
    if (first && !(d < limit))
        return false;
    a->A();
    if (first)
        first->B();
    first = a;
    value = b;
    if (c)
        c->A();
    if (second)
        second->B();
    Ref_232060** q = &second;
    *q = c;
    limit = d;
    return true;
}


// 0x002320d0 FUN_002320d0 (167 B): equivalent/0x002320d0.cpp
// sym: ?FUN_002320d0@Owner_2320d0@fn_f7416411@@QAE_NPAUSpec_2320d0@2@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_002320d0 @ 0x002320d0
bool Owner_2320d0::FUN_002320d0(Spec_2320d0 *spec, hulk_intptr a, int b)
{
    if (spec == 0)
        return false;
    if (spec->source == 0)
        return true;
    int oldPool = FUN_00266da0(FUN_00238190(3));
    QueuedNodeAction_2320d0 *mem = (QueuedNodeAction_2320d0 *)FUN_0008d690((int)sizeof(QueuedNodeAction_2320d0));
    QueuedNodeAction_2320d0 *inst = 0;
    if (mem)
        inst = mem->FUN_0023a2a0(spec, a, this, b);
    if (secondary == 0) {
        if (inst)
            inst->AddRef();
        if (primary)
            primary->Release();
        primary = inst;
    } else {
        secondary->FUN_002326d0(inst);
    }
    if (inst)
        inst->AddRef();
    if (secondary)
        secondary->Release();
    secondary = inst;
    FUN_00266da0(oldPool);
    return true;
}


// 0x00232180 FUN_00232180 (43 B): matches/0x00232180.cpp
// sym: ?Clear@Owner_232180@fn_f7416411@@QAEXXZ
void Owner_232180::Clear() {
    if (first) {
        first->Release();
        first = 0;
    }
    if (second) {
        second->Release();
        second = 0;
    }
}


// 0x002321b0 FUN_002321b0 (129 B): matches/0x002321b0.cpp
// sym: ?run@Obj_2321b0@fn_f7416411@@QAEXXZ
// data: gCount_2321b0 = DAT_004e5ae8
void Obj_2321b0::run() {
    for (Item_2321b0* i = list; i; i = i->next) {
        bool b = ((i->flags >> 2) & 1) != 0;
        if (b) {
            i->f4();
            --DAT_004e5ae8;
            i->cleanup_00232600(8, 1);
        }
    }
    if (extra) {
        extra->f1();
        extra = 0;
    }
    if (list) {
        list->f1();
        list = 0;
    }
    value = 0;
    if (first)
        first->f1();
    first = 0;
}


// 0x00232240 FUN_00232240 (77 B): matches/0x00232240.cpp
// sym: ?reset@Obj@fn_f7416411@@QAEXXZ
void Obj::reset() {
    init_002321b0();
    if (e) {
        e->release();
        e = 0;
    }
    if (d) {
        d->release();
        d = 0;
    }
    c = 0;
    _ReadWriteBarrier();
    if (b) {
        b->release();
        b = 0;
    }
    if (a) {
        a->release();
        a = 0;
    }
}


// 0x00232290 FUN_00232290 (92 B): matches/0x00232290.cpp
// sym: ?Attach@Owner_232290@fn_f7416411@@QAE_NPAVItem_232290@2@@Z
bool Owner_232290::Attach(Item_232290* item) {
    if (!item)
        return false;
    item->value += amount;
    Item_232290* s0 = second;
    if (s0 == 0) {
        item->A();
        if (first != 0)
            first->B();
        first = item;
    } else {
        s0->Handle_002326d0(item);
    }
    item->A();
    Item_232290* t = second;
    if (t)
        t->B();
    second = item;
    return true;
}


// 0x002322f0 FUN_002322f0 (436 B): equivalent/0x002322f0.cpp
// sym: ?FUN_002322f0@Sequence@fn_f7416411@@QAEXHM@Z
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 42/42)
// FUN_002322f0 @ 0x002322f0
void Sequence::FUN_002322f0(int arg, float dt)
{
    int savedHeap = FUN_00266da0(FUN_00238190(3));

    if (ctx != 0) {
        FUN_002321b0();
        Child_2322f0 *c = ctx->children;
        while (c != 0) {
            if (c->Match(f8, fc) == this)
                c->FUN_00236bc0(ctx, this, fc);
            c = c->next;
        }
        Context *cx = ctx;
        if (cx != 0)
            cx->AddRef();
        if (owner != 0)
            owner->Release();
        owner = cx;
        if (fc != 0) {
            fc->Release();
            fc = 0;
        }
        f8 = 0;
        if (ctx != 0) {
            ctx->Release();
            ctx = 0;
        }
    }

    Item_2322f0 *it = pending;
    while (it != 0) {
        it->time = time + it->time;
        if (tail == 0) {
            it->AddRef();
            if (active != 0)
                active->Release();
            active = it;
        } else {
            tail->FUN_002326d0(it);
        }
        it->AddRef();
        if (tail != 0)
            tail->Release();
        tail = it;
        it = it->next;
    }

    if (f18 != 0) {
        f18->Release();
        f18 = 0;
    }
    if (pending != 0) {
        pending->Release();
        pending = 0;
    }

    float now = dt + time;
    time = now;
    Item_2322f0 *cur = active;
    if (cur != 0) {
        do {
            float t = cur->time;
            if (t <= now) {
                if (((cur->flags >> 2) & 1) != 0) {
                    cur->elapsed = dt;
                } else {
                    cur->FUN_00232600(4, 1);
                    float d = now - t;
                    cur->elapsed = d;
                    bool alive = cur->Update(arg, d);
                    DAT_004e5ae8++;
                    if (DAT_004e5ae8 > DAT_004e5aec)
                        DAT_004e5aec = DAT_004e5ae8;
                    if (!alive)
                        cur->FUN_00232600(8, 1);
                }
            }
            cur = cur->next;
        } while (cur != 0);
    }
    FUN_00266da0(savedHeap);
}

} // namespace fn_f7416411

// 0x002324b0 FUN_002324b0 (318 B): equivalent/0x002324b0.cpp [wrapped: conflict: FUN_00266da0]
// sym: ?FUN_002324b0@NodeList_2324b0@fn_002324b0@@QAE_ND@Z
namespace fn_002324b0 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 34/36, incomplete)
// FUN_002324b0 @ 0x002324b0

void *__cdecl FUN_00266da0(hulk_intptr n);
int __cdecl FUN_00238190(int n);

class Node {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void Free();
    char pad4[4];
    Node *next;
    unsigned flags;
    char pad10[4];
    float time;
    float step;

    void FUN_00232600(int a, int b);
    void FUN_002326d0(Node *n);
};

class NodeList_2324b0 {
public:
    int f0;
    char pad4[0x1c];
    Node *head;
    Node *cur;

    void FUN_002321b0();
    bool FUN_002324b0(char flush);
};

bool NodeList_2324b0::FUN_002324b0(char flush)
{
    void *saved = FUN_00266da0(FUN_00238190(3));
    bool keep = false;
    Node *prev = 0;
    Node *n = head;
    while (n != 0) {
        if ((n->flags >> 2) & 1) {
            if ((n->flags >> 3) & 1) {
                n->Free();
                DAT_004e5ae8--;
            } else {
                float t = n->time;
                if (!(t < (*(float*)&DAT_003f32e0))) {
                    t -= n->step;
                    if (t < (*(float*)&DAT_003f32e0)) {
                        n->Free();
                        DAT_004e5ae8--;
                        n->FUN_00232600(8, 1);
                    } else {
                        n->time = t;
                    }
                }
            }
        }
        if ((n->flags >> 3) & 1) {
            if (cur == n) {
                if (prev != 0)
                    prev->AddRef();
                if (cur != 0)
                    cur->Release();
                cur = prev;
            }
            n = n->next;
            if (prev != 0) {
                prev->FUN_002326d0(n);
            } else {
                if (n != 0)
                    n->AddRef();
                if (head != 0)
                    head->Release();
                head = n;
            }
        } else {
            if ((n->flags & 3) == 0)
                keep = true;
            prev = n;
            n = n->next;
        }
    }
    if (!keep) {
        if (flush) {
            if (f0 != 0 || head != 0)
                FUN_002321b0();
        }
    }
    FUN_00266da0((hulk_intptr)saved);
    return keep;
}
} // namespace fn_002324b0

// 0x002325f0 thunk_FUN_00232240 (5 B): not yet verified

// 0x00232600 FUN_00232600 (40 B): matches/0x00232600.cpp
// sym: ?FUN_00232600@X_232600@owners@@QAEXI_N@Z
void owners::X_232600::FUN_00232600(unsigned int mask, bool enabled) {
    if (enabled)
        flags |= mask;
    else
        flags &= ~mask;
}


// 0x00232630 fight::Action::vfunc_3 (5 B): matches/0x00232630.cpp
// sym: ?vfunc_3@Action@fight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool fight::Action::vfunc_3(hulk_intptr a, hulk_intptr b) {
    return (bool)(1);
}

namespace fn_f7416411 {

// 0x00232640 fight::Action::vfunc_4 (1 B): matches/0x00232640.cpp
// sym: ?FUN_00232640@fn_f7416411@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00232640() {}

} // namespace fn_f7416411

// 0x00232650 fight::Action::vfunc_5 (5 B): matches/0x00232650.cpp
// sym: ?vfunc_5@Action@fight@@UAE_NHH@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool fight::Action::vfunc_5(hulk_intptr a, int b) {
    return (bool)(1);
}

namespace fn_f7416411 {

// 0x00232660 FUN_00232660 (58 B): matches/0x00232660.cpp
// sym: ??0Action@fn_f7416411@@QAE@XZ
// data: gCount_232660 = DAT_004e5af0
Action::Action() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    ++DAT_004e5af0;
    if (DAT_004e5af0 > (*(int*)&DAT_004e5af4))
        (*(int*)&DAT_004e5af4) = DAT_004e5af0;
}

} // namespace fn_f7416411

// 0x002326a0 FUN_002326a0 (42 B): matches/0x002326a0.cpp
// sym: ?FUN_002326a0@Action@fight@@QAEXXZ
// data: g_count_2326a0 = DAT_004e5af0
void fight::Action::FUN_002326a0() {
    *(void* volatile*)this = (void*)((hulk_intptr)DAT_004276ec);
    _ReadWriteBarrier();
    Ref_2326a0* m = *(Ref_2326a0**)((char*)this + 8);
    if (m) {
        m->Release();
        *(Ref_2326a0**)((char*)this + 8) = 0;
    }
    --DAT_004e5af0;
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
}

namespace fn_f7416411 {

// 0x002326d0 FUN_002326d0 (38 B): matches/0x002326d0.cpp
// sym: ?Set@Holder_2326d0@fn_f7416411@@QAEXPAVObj_2326d0@2@@Z
void Holder_2326d0::Set(Obj_2326d0* value) {
    if (value)
        value->F0();
    if (p)
        p->F1();
    p = value;
}


// 0x00232700 fight::Action::vfunc_2 (70 B): matches/0x00232700.cpp
// sym: ?Dtor@Action_232700@fn_f7416411@@QAEPAU12@E@Z
Action_232700* Action_232700::Dtor(unsigned char flag) throw() {
    vf = hulk_at_004276ec;
    _ReadWriteBarrier();
    if (p8) {
        p8->Release();
        p8 = 0;
    }
    DAT_004e5af0 = DAT_004e5af0 - 1;
    vf = vIRef;
    if (flag & 1)
        FUN_0008d330(this);
    return this;
}

} // namespace fn_f7416411
