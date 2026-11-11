// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0025d640..0x0025e230 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc4af378 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc4af378 {} using namespace fn_fc4af378;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fc4af378 {
struct Node {
    Node* next;
};
struct List_25d640 {
    Node* head;
    Node* tail;
};
class Owner_25d740;
class Item_25d740 {
  public:
    virtual void v0();
    virtual void Act(Owner_25d740*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Check(Owner_25d740*);
};
class Owner_25d740 {
  public:
    char pad[0x40];
    Item_25d740* field;
    char pad2[0x14];
    int state;
    void Run();
};
class Thing_25d780 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void Act(owners::Owner_25d780*);
    virtual void d();
    virtual int Check(owners::Owner_25d780*);
};
class X_25d7c0;
class Other_25d7c0 {
  public:
    virtual void call(X_25d7c0*);
};
class X_25d7c0 {
  public:
    char pad[0x48];
    int state;
    char pad2[4];
    Other_25d7c0* ptr;
};
namespace audio {
class SeqAction {
public:
    virtual void vfunc_0();
    char *link;
};
}
namespace audio {
class SeqActionStream : public SeqAction {
public:
    virtual void vfunc_1();
    char pad08[0x18 - 0x08];
    int index;
};
}
extern "C" int __cdecl FUN_0024afe0(Handle *h);
extern "C" Handle *__cdecl FUN_0024b030(Handle *h);
extern "C" int __cdecl FUN_0024c2d0(Handle *h);
struct SortKey { unsigned value; int index; };
struct Block4_25d7f0 { unsigned a, b, c, d; int index; };
extern "C" void __cdecl FUN_0024b060(Handle *h, SortKey *keys, int count);
extern "C" void __cdecl FUN_0024b050(Handle *h, Block4_25d7f0 *blocks, int count);
struct Sink_25d7f0 {
    virtual void vfunc_0();
    virtual void vfunc_1(void *owner, Handle *h);
};
struct Mgr_25d7f0 {
    char pad[0xac];
    Sink_25d7f0 *sink;
};
struct Owner_25d7f0 {
    char pad[0x3c];
    unsigned *keys;
    unsigned *blocks;
};
struct Frame_25d7f0 {
    char pad0[2];
    char count;
    char missing;
    int savedThis;
    SortKey keys[16];
    Block4_25d7f0 blocks[16];
};
struct Self_25d7f0 {
    char pad0[4];
    Owner_25d7f0 *owner;
    char pad08[0x34 - 8];
    Handle *handle;
    char pad38[4];
    Mgr_25d7f0 *mgr;
    char *streams;
    char pad44[0x54 - 0x44];
    char first;
    char pad55[3];
    int mode;
    char flag5c;

    void FUN_0025d7f0();
};
class Ref_25dbd0 {
  public:
    virtual void A();
    virtual void Release(int);
};
struct Item_25dc20 {
    virtual void f0();
    virtual void f1();
    virtual int Run(void*, int);
};
struct Owner_25dc20 {
    char pad[0x40];
    Item_25dc20* first;
    Item_25dc20* last;
    int count;
    int Add(Item_25dc20*);
};
struct Item {
    virtual void Slot0(int);
    virtual void Destroy(int doDelete);
    Link link;
};
class Controller_25dd00;
class Listener_25dd00 {
public:
    virtual void Tick(Controller_25dd00 *c);
    virtual void v1(Controller_25dd00 *c);
    virtual void v2(Controller_25dd00 *c);
    virtual void v3(Controller_25dd00 *c);
    virtual void Stop(Controller_25dd00 *c);
    virtual int Poll(Controller_25dd00 *c);
    virtual void Release(Controller_25dd00 *c);
    Listener_25dd00 *nextLink;    // intrusive link at +4
};
struct Link_25dd00 {
    Listener_25dd00 *item;
};
struct Handle_25dd00 {
    char pad0[0xc0];
    int state;
};
struct Pending_25dd00 {
    void FUN_0024a280(int arg);
};
int __cdecl FUN_0024afe0(Handle_25dd00 *h);
extern "C" void __cdecl FUN_0024c0c0(Handle_25dd00 *h);
class Controller_25dd00 {
public:
    char pad0[8];
    Pending_25dd00 pending;       // 0x08
    char pad09[0x34 - 9];
    Handle_25dd00 *handle;        // 0x34
    char pad38[0x40 - 0x38];
    char *listeners;       // 0x40, link at +4 inside each Listener
    char pad44[4];
    int busy;              // 0x48
    char pad4c[4];
    char *tickers;         // 0x50
    char pad54[4];
    int state;             // 0x58
    void FUN_0025d7c0();
    void FUN_0025d7f0();
    char FUN_0025da00();
    void FUN_0025dd00(int arg);
};
class C_25ded0 {
  public:
    char pad[0x48];
    int field;
    void Target();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0025dcb0(void *);
struct C_25def0 {
    char pad[0x4c];
};
extern "C" void __cdecl FUN_0025dc60(void *);
class C_25df20 {
    char pad[0x40];

  public:
    void Finish();
    void Target();
};
struct X_25e090 {
    char pad0[4];
    unsigned int a;
    char pad8[8];
    unsigned char flag;
    char pad11[3];
    unsigned int c;
    unsigned int d;
};
struct Buffer_25e0b0 {
    char p0[4];
    unsigned capacity;
    char p8[8];
    unsigned char full;
    char p11[3];
    unsigned position;
    unsigned end;
    unsigned readCount;
    unsigned writeCount;
    unsigned wraps;
};


// 0x0025d640 FUN_0025d640 (52 B): matches/0x0025d640.cpp
// sym: _FUN_0025d640
extern "C" void FUN_0025d640(void * list, void * item) {
    Node* target = (Node*)((char*)((Node *)item) + 4);
    Node* prev = 0;
    Node* cur = ((List_25d640 *)list)->head;
    if (cur != target) {
        do {
            prev = cur;
            cur = cur->next;
        } while (cur != target);
    }
    if (prev == 0)
        ((List_25d640 *)list)->head = target->next;
    else
        prev->next = target->next;
    if (target->next == 0)
        ((List_25d640 *)list)->tail = prev;
}


// 0x0025d740 FUN_0025d740 (63 B): matches/0x0025d740.cpp
// sym: ?Run@Owner_25d740@fn_fc4af378@@QAEXXZ
void Owner_25d740::Run() {
    if (field != 0) {
        Item_25d740* p = (Item_25d740*)((char*)field - 4);
        if (p != 0) {
            int r = p->Check(this);
            if (r == 2 || r == 4)
                p->Act(this);
        }
    }
    state = 3;
}

} // namespace fn_fc4af378

// 0x0025d780 FUN_0025d780 (58 B): matches/0x0025d780.cpp
// sym: ?FUN_0025d780@Owner_25d780@owners@@QAEXXZ
void owners::Owner_25d780::FUN_0025d780() {
    if (mData) {
        Thing_25d780* t = (Thing_25d780*)(mData - 4);
        if (t && t->Check(this) == 3)
            t->Act(this);
    }
    mState = 4;
}

namespace fn_fc4af378 {

// 0x0025d7c0 FUN_0025d7c0 (40 B): matches/0x0025d7c0.cpp
// sym: ?target@fn_fc4af378@@YIXPAVX_25d7c0@1@@Z
void __fastcall target(X_25d7c0* self) {
    unsigned int i = 0;
    do {
        Other_25d7c0* p = self->ptr;
        if (!p)
            return;
        Other_25d7c0* q = (Other_25d7c0*)((char*)p - 4);
        if (!q)
            return;
        if (self->state == 0x1e)
            return;
        q->call(self);
        ++i;
    } while (i < 5);
}


// 0x0025d7f0 FUN_0025d7f0 (522 B): equivalent/0x0025d7f0.cpp
// sym: ?FUN_0025d7f0@Self_25d7f0@fn_fc4af378@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 46/46)
// FUN_0025d7f0 @ 0x0025d7f0
void Self_25d7f0::FUN_0025d7f0()
{
    Frame_25d7f0 fr;
    first = (char)0xff;
    char *head = streams;
    audio::SeqAction *obj = head ? (audio::SeqAction *)(head - 4) : 0;
    fr.count = 0;
    fr.missing = 0;
    bool skipToNotify = true;
    if (dynamic_cast<audio::SeqActionStream *>(obj) != 0 && obj != 0) {
        do {
            audio::SeqActionStream *s = dynamic_cast<audio::SeqActionStream *>(obj);
            if (s != 0) {
                s->index = fr.count;
                if (fr.missing == 0)
                    first = fr.count;
                fr.count++;
            } else {
                fr.missing = 1;
            }
            char *n = obj->link;
            if (n == 0)
                break;
            obj = (audio::SeqAction *)(n - 4);
        } while (obj != 0);
        skipToNotify = (fr.count == 0 || mode == 5);
    }
    bool other = true;
    if (skipToNotify) {
        if (handle != 0) {
            other = false;
            if (FUN_0024afe0(handle) == 0) {
                Mgr_25d7f0 *m = mgr;
                m->sink->vfunc_1(m, handle);
                handle = 0;
            }
        }
    }
    if (other) {
        if (flag5c != 0 && handle != 0) {
            if (FUN_0024afe0(handle) == 0)
                flag5c = 0;
        }
    }
    if (handle == 0)
        return;
    unsigned *src = owner->keys;
    int n = FUN_0024c2d0(FUN_0024b030(handle));
    if (src != 0) {
        for (int i = 0; i < n; i++) {
            fr.keys[i].value = src[i];
            fr.keys[i].index = i;
        }
        FUN_0024b060(handle, fr.keys, n);
    }
    unsigned *blk = owner->blocks;
    if (blk != 0) {
        for (int i = 0; i < n; i++) {
            fr.blocks[i].a = blk[i * 4];
            fr.blocks[i].b = blk[i * 4 + 1];
            fr.blocks[i].c = blk[i * 4 + 2];
            fr.blocks[i].d = blk[i * 4 + 3];
            fr.blocks[i].index = i;
        }
        FUN_0024b050(handle, fr.blocks, n);
    }
}

} // namespace fn_fc4af378

// 0x0025da00 FUN_0025da00 (296 B): equivalent/0x0025da00.cpp [wrapped: conflict: Node]
// sym: ?run@Owner_25da00@fn_0025da00@@QAE_NXZ
namespace fn_0025da00 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 40/40)
// FUN_0025da00 @ 0x0025da00
struct TypeInfo_25da00 { unsigned int data; }; extern TypeInfo_25da00 DAT_004c7eb4, DAT_004c7ed4;
extern void* __cdecl FUN_00344e74(void*, int, TypeInfo_25da00*, TypeInfo_25da00*, int);
extern bool __cdecl FUN_0024b200(void*);
extern int __cdecl FUN_0024afe0(void*);
extern "C" void __cdecl FUN_0024ba70(void*, int, int);
struct Owner_25da00;
struct Node;
struct Link_25da00 { Node* asNodePadding; }; 
struct Node { virtual void destroy(int); virtual void finish(Owner_25da00*); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual int status(Owner_25da00*); virtual void update(Owner_25da00*); Link_25da00* next; };
extern "C++" __declspec(nothrow) void __cdecl FUN_0025d640(void *, void *);
struct Owner_25da00 { char pad0[0x34]; void* resource; char pad38[8]; Link_25da00* head; char pad44[4]; unsigned int count; Link_25da00* other; char pad50[4]; signed char index; char pad55[3]; int state; unsigned char active; bool run(); };
bool Owner_25da00::run() {
 Node* node = head ? reinterpret_cast<Node*>(reinterpret_cast<char*>(head)-4) : 0;
 while(node) {
  bool before = FUN_00344e74(node,0,&DAT_004c7eb4,&DAT_004c7ed4,0)!=0;
  node->update(this);
  Link_25da00* next = node->next;
  node = next ? reinterpret_cast<Node*>(reinterpret_cast<char*>(next)-4) : 0;
  bool after = FUN_00344e74(node,0,&DAT_004c7eb4,&DAT_004c7ed4,0)!=0;
  if(before!=after) break;
 }
 if(resource && !active && (!other || reinterpret_cast<char*>(other)-4==0 || (unsigned int)(int(index)+1)<count)) {
  if(!FUN_0024b200(resource) && FUN_0024afe0(resource)) {
   void* r=resource; active=1; FUN_0024ba70(r,0,0);
  }
 }
 node = head ? reinterpret_cast<Node*>(reinterpret_cast<char*>(head)-4) : 0;
 if(node) {
  int result=node->status(this);
  if(result==0 && state==3) {
   FUN_0025d640((Link_25da00 * *)(&head),(Node *)node); --count; node->destroy(1); return true;
  }
  if(result==2 && state==3) node->finish(this);
 }
 return false;
}
} // namespace fn_0025da00


// 0x0025db30 FUN_0025db30 (98 B): equivalent/0x0025db30.cpp [wrapped: conflict: Node]
// sym: ?FUN_0025db30@Owner@fn_0025db30@@QAEXXZ
namespace fn_0025db30 {
// STATUS: equivalent (tools/equiv.py level 3: 1140 inputs, branch coverage 17/18, incomplete)
// FUN_0025db30 @ 0x0025db30
struct Node { virtual void unused(); virtual void destroy(int); Node* next; }; struct Owner { char pad[0x4c]; Node** head; Node** tail; void FUN_0025db30(); }; void Owner::FUN_0025db30() { Node** link = head; if (!link) return; Node* current = (Node*)((char*)link - 4); while (current) { Node** nextLink = (Node**)&current->next; Node* next = *nextLink; Node* following = next ? (Node*)((char*)next - 4) : 0; Node** previous = 0; Node** cursor = head; if (cursor != nextLink) { do { previous = cursor; cursor = (Node**)*cursor; } while (cursor != nextLink); } if (previous) *previous = *nextLink; else head = (Node**)*nextLink; if (!*nextLink) tail = previous; current->destroy(1); current = following; } }
} // namespace fn_0025db30


// 0x0025dba0 FUN_0025dba0 (37 B): matches/0x0025dba0.cpp
// sym: ?FUN_0025dba0@Queue_25dba0@owners@@QAEXPAH@Z
void owners::Queue_25dba0::FUN_0025dba0(int* item) {
    int* node = item + 1;
    *node = 0;
    if (tail == 0) {
        head = node;
        tail = node;
    } else {
        *(hulk_intptr*)tail = (hulk_intptr)node;
        tail = node;
    }
}


// 0x0025dbd0 FUN_0025dbd0 (67 B): matches/0x0025dbd0.cpp
// sym: ?FUN_0025dbd0@Owner_25dbd0@owners@@QAEXPAH@Z
void owners::Owner_25dbd0::FUN_0025dbd0(int* p) {
    int* next = p + 1;
    int* prev = 0;
    int* cur = head;
    while (cur != next) {
        prev = cur;
        cur = (int*)*(hulk_intptr*)cur;
    }
    if (prev == 0) {
        head = (int*)*(hulk_intptr*)next;
    } else {
        *prev = *next;
    }
    if (*next == 0)
        tail = prev;
    if (p != 0)
        ((Ref_25dbd0*)p)->Release(1);
}

namespace fn_fc4af378 {

// 0x0025dc20 FUN_0025dc20 (52 B): matches/0x0025dc20.cpp
// sym: ?Add@Owner_25dc20@fn_fc4af378@@QAEHPAUItem_25dc20@2@@Z
int Owner_25dc20::Add(Item_25dc20* item) {
    int* node = (int*)((char*)item + 4);
    *node = 0;
    if (last == 0)
        first = (Item_25dc20*)node;
    else
        *(hulk_intptr*)last = (hulk_intptr)node;
    last = (Item_25dc20*)node;
    ++count;
    return item->Run(this, 1);
}


// 0x0025dc60 FUN_0025dc60 (74 B): equivalent/0x0025dc60.cpp
// sym: _FUN_0025dc60
// STATUS: equivalent (tools/equiv.py level 3: 1409 inputs, branch coverage 7/7)
// FUN_0025dc60 @ 0x0025dc60
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from list->head), so the search never runs and prev is always 0.
// equiv-dead: +0x1a not taken, +0x26 taken, +0x26 not taken, +0x2a taken, +0x2a not taken: node is always the head
extern "C" void FUN_0025dc60(void * list)
{
    for (;;) {
        Link* node = ((List *)list)->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 4);
        if (item == 0)
            return;
        ((List *)list)->head = node->next;
        if (node->next == 0)
            ((List *)list)->tail = 0;
        item->Destroy(1);
    }
}

} // namespace fn_fc4af378

// 0x0025dcb0 FUN_0025dcb0 (73 B): equivalent/0x0025dcb0.cpp [wrapped: conflict: Item]
// sym: _FUN_0025dcb0
namespace fn_0025dcb0 {
// STATUS: equivalent (tools/equiv.py level 3: 1404 inputs, branch coverage 7/7)
// FUN_0025dcb0 @ 0x0025dcb0
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from list->head), so the search never runs and prev is always 0.
// equiv-dead: +0x1a not taken, +0x26 taken, +0x26 not taken, +0x2a taken, +0x2a not taken: node is always the head
struct Link {
    Link* next;
};

struct Item {
    virtual void Destroy(int doDelete);
    Link link;
};

struct List {
    Link* head;
    Link* tail;
};

extern "C" void FUN_0025dcb0(void * list)
{
    for (;;) {
        Link* node = ((List *)list)->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 4);
        if (item == 0)
            return;
        ((List *)list)->head = node->next;
        if (node->next == 0)
            ((List *)list)->tail = 0;
        item->Destroy(1);
    }
}
} // namespace fn_0025dcb0

namespace fn_fc4af378 {

// 0x0025dd00 FUN_0025dd00 (431 B): equivalent/0x0025dd00.cpp
// sym: ?FUN_0025dd00@Controller_25dd00@fn_fc4af378@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 64/71, incomplete)
// FUN_0025dd00 @ 0x0025dd00
void Controller_25dd00::FUN_0025dd00(int arg)
{
    pending.FUN_0024a280(arg);
    switch (state) {
    case 1: {
        FUN_0025d7c0();
        FUN_0025d7f0();
        FUN_0025da00();
        Listener_25dd00 *l = listeners ? (Listener_25dd00 *)(listeners - 4) : 0;
        if (l != 0) {
            int r = l->Poll(this);
            if (r == 2 || r == 0) {
                Handle_25dd00 *h = handle;
                state = 2;
                if (h != 0 && FUN_0024afe0(h) == 2)
                    state = 3;
            }
        } else {
            state = 2;
        }
        break;
    }
    case 3:
        if (busy == 0) {
            if (handle == 0 || FUN_0024afe0(handle) != 2)
                state = 5;
        }
        break;
    case 4: {
        Listener_25dd00 *l = listeners ? (Listener_25dd00 *)(listeners - 4) : 0;
        if (l != 0) {
            if (l->Poll(this) != 4)
                state = 2;
        } else {
            state = 2;
        }
        break;
    }
    case 5: {
        FUN_0025d7f0();
        int active = 0;
        if (handle != 0) {
            int r = FUN_0024afe0(handle);
            if (r != 5 && r != 0)
                FUN_0024c0c0(handle);
            active = 1;
        }
        Listener_25dd00 *l = listeners ? (Listener_25dd00 *)(listeners - 4) : 0;
        while (l != 0) {
            int r = l->Poll(this);
            if (r != 5 && r != 0)
                l->Stop(this);
            if (r != 0)
                active++;
            l->Release(this);
            char *next = (char *)l->nextLink;
            if (next == 0)
                break;
            l = (Listener_25dd00 *)(next - 4);
        }
        if (active == 0)
            state = 0;
        break;
    }
    }
    if (state == 2 || state == 4 || state == 3) {
        unsigned int n = 0;
        do {
            unsigned int i = 0;
            do {
                if (tickers == 0)
                    break;
                Listener_25dd00 *l = (Listener_25dd00 *)(tickers - 4);
                if (l == 0 || busy == 0x1e)
                    break;
                l->Tick(this);
                i++;
            } while (i < 5);
            FUN_0025d7f0();
            n++;
            if (FUN_0025da00() == 0)
                break;
        } while (n < 5);
    }
}


// 0x0025ded0 FUN_0025ded0 (24 B): matches/0x0025ded0.cpp
// sym: ?Target@C_25ded0@fn_fc4af378@@QAEXXZ
void C_25ded0::Target() {
    FUN_0025dcb0((int *)((int*)(pad + 0x40)));
    field = 0;
}


// 0x0025def0 FUN_0025def0 (44 B): matches/0x0025def0.cpp
// sym: ?target@fn_fc4af378@@YIXPAUC_25def0@1@@Z
void __fastcall target(C_25def0* self) {
    FUN_0025dc60(self->pad + 0x4c);
    FUN_0025dcb0(self->pad + 0x40);
    char* p = self->pad + 8;
    FUN_0024a450(p + 0x14);
    FUN_0024a4a0(p);
}


// 0x0025df20 FUN_0025df20 (30 B): matches/0x0025df20.cpp
// sym: ?Target@C_25df20@fn_fc4af378@@QAEXXZ
void C_25df20::Target() {
    FUN_0025dcb0((char*)this + 0x40);
    *(int*)((char*)this + 0x48) = 0;
    Finish();
}

} // namespace fn_fc4af378

// 0x0025df40 FUN_0025df40 (127 B): equivalent/0x0025df40.cpp
// sym: ?FUN_0025df40@Scheduler_25df40@owners@@QAEPAU12@HHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025df40 @ 0x0025df40
owners::Scheduler_25df40* owners::Scheduler_25df40::FUN_0025df40(hulk_intptr a, hulk_intptr b, hulk_intptr c)
{
    f04 = ((int)a);
    one = 1.0f;
    count0 = 0;
    owners::Scheduler_25df40* n0 = (owners::Scheduler_25df40*)&list0a;
    list0a = n0;
    list0b = n0;
    list0c = n0;
    list0 = n0;
    count1 = 0;
    owners::Scheduler_25df40* n1 = (owners::Scheduler_25df40*)&list1a;
    list1a = n1;
    list1b = n1;
    list1c = n1;
    list1 = n1;
    f30 = ((int)b);
    f38 = 0;
    f3c = ((int)c);
    f40 = 0;
    f44 = 0;
    f4c = 0;
    f50 = 0;
    f58 = 0;
    f34 = 0;
    b54 = (char)0xff;
    b5c = 0;
    f48 = 0;
    FUN_0025dcb0((int *)(&f40));
    f48 = 0;
    FUN_0025db30();
    return this;
}


// 0x0025dfc0 FUN_0025dfc0 (170 B): matches/0x0025dfc0.cpp [wrapped: conflict: Node]
// sym: ?Fn@Obj_25dfc0@fn_0025dfc0@@QAEXPAXD@Z
namespace fn_0025dfc0 {
class Obj_25dfc0;
struct LB_25dfc0 {
    LB_25dfc0* next;
};
class Node : public LB_25dfc0 {
  public:
};
struct NodeA_25dfc0 {
    virtual void A();
    virtual void X();
    virtual void B(Obj_25dfc0*, int);
};
struct Node2_25dfc0 : NodeA_25dfc0, LB_25dfc0 {};
class Inner_25dfc0 {
  public:
    virtual void A();
    virtual void X();
    virtual void B(Obj_25dfc0*);
};
class Obj_25dfc0 {
  public:
    char pad0[0x30];
    Inner_25dfc0* m30;
    void* m34;
    char pad38[8];
    LB_25dfc0* m40;
    void* m44;
    int m48;
    LB_25dfc0* m4c;
    char pad50[8];
    int m58;
    char m5c;
    void Fn(void*, char);
    void End(int);
    void Db30();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_0025dcb0(void *);
extern "C" void FUN_0024bae0(void*, int);
void Obj_25dfc0::Fn(void* p, char mode) {
    m58 = 1;
    m5c = 0;
    if (mode == 1 || ((static_cast<Node2_25dfc0*>(m4c) == 0) && (static_cast<Node2_25dfc0*>(m40) == 0)) ||
        !(*(char*)((char*)m30 + 0x44) & 2)) {
        FUN_0025dcb0(&m40);
        m48 = 0;
        Db30();
        ((Inner_25dfc0*)((char*)m30 + 0x1c))->B(this);
    } else {
        for (Node2_25dfc0* n = static_cast<Node2_25dfc0*>(m40); n; n = static_cast<Node2_25dfc0*>(n->next))
            n->B(this, 0);
    }
    if (p) {
        m34 = p;
        FUN_0024bae0(p, 0);
    }
    End(0);
}
} // namespace fn_0025dfc0

namespace fn_fc4af378 {

// 0x0025e070 FUN_0025e070 (6 B): matches/0x0025e070.cpp
// sym: _FUN_0025e070
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7928: a static om type (records.h)
extern "C" int* FUN_0025e070() {
    return &(*(int*)&DAT_004e7928);
}


// 0x0025e090 FUN_0025e090 (30 B): matches/0x0025e090.cpp
// sym: _FUN_0025e090
extern "C" int __cdecl FUN_0025e090(X_25e090* p) {
    if (p->flag)
        return 0;
    unsigned int v = p->d;
    unsigned int c = p->c;
    if (v > c)
        return v - c;
    return p->a - c;
}


// 0x0025e0b0 FUN_0025e0b0 (125 B): matches/0x0025e0b0.cpp
// sym: _FUN_0025e0b0
extern "C" bool FUN_0025e0b0(Buffer_25e0b0* b, unsigned amount, int mode) {
    if (!amount)
        return true;
    unsigned pos = b->position, end = b->end, available;
    if (pos == end && !b->full)
        available = b->capacity;
    else if (pos > end)
        available = (b->capacity - pos) + end;
    else
        available = end - pos;
    bool overflow = amount > available;
    b->position = (pos + amount) % b->capacity;
    if (b->position == end)
        b->full = 1;
    if (mode == 0)
        b->readCount += amount;
    else if (mode == 1)
        b->writeCount += amount;
    if (overflow)
        b->wraps += b->capacity;
    return !overflow;
}

} // namespace fn_fc4af378
