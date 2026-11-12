// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d0950..0x002d0f10 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f491b664 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f491b664 {} using namespace fn_f491b664;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f491b664 {
struct Item_2d0950 { char pad[8]; unsigned flags; };
extern "C" void FUN_002c96e0(Object*, unsigned char, void*);
extern "C" void FUN_002cb2b0(Object*, int, void*);
extern "C" void FUN_002c7690(Object*, void*, int);
extern "C" void FUN_002c7a50(unsigned char, Object*, void*);
struct State_2d0a50 { char pad[8]; unsigned flags; };
struct Object {
  public:
    char _m_pad_0[0x14];
    union { void* active; void* field14; };
    char _m_pad_18[0x38];
    union { void* field50; void* resource; };
    char _m_pad_54[0x4];
    union { Item_2d0950* item; State_2d0a50* state; };
    unsigned __int64 FUN_002c8a80(void*, void*);
    unsigned __int64 FUN_002c92f0(void*, void*);
    void target(void* arg1, void* arg2, void* arg3);
    void FUN_002c8a80(unsigned,void*);
    void FUN_002c92f0(unsigned,void*);
    void target(unsigned,hulk_uintptr,void*);
};
extern "C" void FUN_002cec10(Object*,bool,unsigned);
extern "C" void FUN_002cd130(Object*,bool,unsigned);
extern "C" void FUN_002c7e40(Object*,bool,unsigned);
extern "C" void FUN_002c8130(bool,Object*,unsigned);
void __fastcall cleanup_002df7d0(void*);
struct Item_2d0d20 {
    char pad[0xc];
    int slot;           // 0xc
};
struct Group_2d0d20 {
    Item_2d0d20** items;
    int a, b;
};
struct Container_2d0d20 {
    char pad[0x14];
    Group_2d0d20* groups;      // 0x14
};
struct Handler_2d0d20 {
    void FUN_002e0cc0(Item_2d0d20* item, int arg);
};
struct Iter_2d0d20 {
    int arg;            // 0x0
    int group;          // 0x4
    int index;          // 0x8
    Container_2d0d20* cont;    // 0xc
    void FUN_002e5850(Container_2d0d20* c, int arg);
    void FUN_002e5310();
};
class Dispatcher_2d0d20 {
public:
    char pad0[8];
    Container_2d0d20* source;      // 0x8
    Handler_2d0d20** handlers;     // 0xc
    void FUN_002d0d20(hulk_intptr selector, int arg);
};
struct Obj_2d0da0 {
    char pad0[0xc];
    int handler;        // 0x0c
};
struct Handler_2d0da0 {
    void FUN_002e1020(Obj_2d0da0* obj, int a, int b);
};
struct Row_2d0da0 {
    Obj_2d0da0** objs;
    int pad[2];
};
struct Table_2d0da0 {
    char pad0[0x14];
    Row_2d0da0* rows;          // 0x14
};
struct Cursor_2d0da0 {
    int pad0;
    int row;            // 0x04
    int index;          // 0x08
    Table_2d0da0* table;       // 0x0c
    void FUN_002e5850(Source* src, int arg);
    void FUN_002e5310();
};
class Dispatcher_2d0da0 {
public:
    char pad0[8];
    Source* source;     // 0x08
    Handler_2d0da0** handlers; // 0x0c
    void FUN_002d0da0(int arg, int a, int b);
};
struct Item_2d0e20 {
    char pad[0xc];
    int slot;           // 0xc
};
struct Group_2d0e20 {
    Item_2d0e20** items;
    int a, b;
};
struct Container_2d0e20 {
    char pad[0x14];
    Group_2d0e20* groups;      // 0x14
};
struct Handler_2d0e20 {
    void FUN_002e11e0(Item_2d0e20* item, int arg);
};
struct Iter_2d0e20 {
    int arg;            // 0x0
    int group;          // 0x4
    int index;          // 0x8
    Container_2d0e20* cont;    // 0xc
    void FUN_002e5850(Container_2d0e20* c, int arg);
    void FUN_002e5310();
};
class Dispatcher_2d0e20 {
public:
    char pad0[8];
    Container_2d0e20* source;      // 0x8
    Handler_2d0e20** handlers;     // 0xc
    void FUN_002d0e20(int selector, int arg);
};
extern "C" void* FUN_0008d6d0(unsigned int);
extern "C" int * __cdecl FUN_002d0cc0(int *, int, const int *);


// 0x002d0950 FUN_002d0950 (244 B): equivalent/0x002d0950.cpp
// sym: ?target@Object@fn_f491b664@@QAEXPAX00@Z @8e80af90cd2c @w32d1f83f67f6
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 20/20)
// FUN_002d0950 @ 0x002d0950
// FUN_002d0950 @ 0x002d0950
// equiv-conv: FUN_002c96e0 eax edx esi
// equiv-conv: FUN_002cb2b0 ecx stack esi
// equiv-conv: FUN_002c7690 eax esi stack
// equiv-conv: FUN_002c7a50 ecx eax esi
void Object::target(void* arg1, void* arg2, void* arg3) {
 Object* self = this;
 bool enabled = arg3 != 0 && self->field50 != 0;
 bool special;
 if (enabled) {
  unsigned __int64 result;
  if (self->item) result = self->FUN_002c8a80(arg2,arg3); else result = self->FUN_002c92f0(arg2,arg3);
  special = self->item != 0 && (self->item->flags & 0xffffffcfU) != 0;
 } else special = self->item != 0;
 if (special) {
  if (self->field14) FUN_002c96e0(self, enabled ? 1 : 0, arg1);
  else FUN_002cb2b0(self, enabled ? 1 : 0, arg1);
 } else {
  if (self->field14) FUN_002c7690(self,arg1,enabled ? 1 : 0);
  else FUN_002c7a50(enabled ? 1 : 0, self, arg1);
 }
}


// 0x002d0a50 FUN_002d0a50 (160 B): equivalent/0x002d0a50.cpp
// sym: ?target@Object@fn_f491b664@@QAEXIIPAX@Z @ef91f7c8d485 @we399d3a8f43a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_002d0a50 @ 0x002d0a50
// equiv-conv: FUN_002cec10 ecx edx esi
// equiv-conv: FUN_002cd130 eax edx esi
// equiv-conv: FUN_002c7e40 eax ecx esi
// equiv-conv: FUN_002c8130 ecx eax esi
void Object::target(unsigned c,hulk_uintptr v,void* d) { bool e=d && resource; bool s; if(e) { if(state) FUN_002c8a80(v,d); else FUN_002c92f0(v,d); s=state && (state->flags&0xffffffcfU); } else s=state!=0; if(s) {if(active) FUN_002cd130(this,e,c); else FUN_002cec10(this,e,c);} else {if(active) FUN_002c7e40(this,e,c); else FUN_002c8130(e,this,c);} }

} // namespace fn_f491b664

// 0x002d0c80 FUN_002d0c80 (44 B): matches/0x002d0c80.cpp
// sym: ?FUN_002d0c80@X_2d0c80@owners@@QAEXXZ
void owners::X_2d0c80::FUN_002d0c80() {
    hulk_uintptr n = ((char*)end - (char*)begin) >> 2;
    for (unsigned int i = 0; i < n; ++i) {
        void* p = begin[i];
        if (p)
            cleanup_002df7d0(p);
    }
}

namespace fn_f491b664 {

// 0x002d0cc0 FUN_002d0cc0 (40 B): matches/0x002d0cc0.cpp
// sym: _FUN_002d0cc0
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002d0cc0(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}


// 0x002d0d20 FUN_002d0d20 (113 B): equivalent/0x002d0d20.cpp
// sym: ?FUN_002d0d20@Dispatcher_2d0d20@fn_f491b664@@QAEXHH@Z @0e2e2bb788ea @w4863873a0787
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0d20 @ 0x002d0d20
// Walks the selected group from its last item down to the first and dispatches each to its handler.
void Dispatcher_2d0d20::FUN_002d0d20(hulk_intptr selector, int arg)
{
    Iter_2d0d20 it;
    it.FUN_002e5850(source, selector);
    if (it.index >= 0) {
        do {
            Item_2d0d20* item = 0;
            if (it.index >= 0)
                item = it.cont->groups[it.group].items[it.index];
            handlers[item->slot]->FUN_002e0cc0(item, arg);
            if (it.index < 0)
                break;
            it.index--;
        } while (it.index >= 0);
    }
    it.FUN_002e5310();
}


// 0x002d0da0 FUN_002d0da0 (126 B): equivalent/0x002d0da0.cpp
// sym: ?FUN_002d0da0@Dispatcher_2d0da0@fn_f491b664@@QAEXHHH@Z @a1617df590d0 @w9756665ce29e
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0da0 @ 0x002d0da0
// Walks a cursor from its index down to 0, sending each object to its handler.
void Dispatcher_2d0da0::FUN_002d0da0(int arg, int a, int b)
{
    Cursor_2d0da0 c;
    c.FUN_002e5850(source, arg);
    int i = c.index;
    while (i >= 0) {
        Obj_2d0da0* obj = c.table->rows[c.row].objs[i];
        handlers[obj->handler]->FUN_002e1020(obj, a, b);
        i = c.index;
        if (i < 0)
            break;
        c.index = --i;
    }
    c.FUN_002e5310();
}


// 0x002d0e20 FUN_002d0e20 (113 B): equivalent/0x002d0e20.cpp
// sym: ?FUN_002d0e20@Dispatcher_2d0e20@fn_f491b664@@QAEXHH@Z @4b59ae6b168e @wa4615a4b63d7
// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0e20 @ 0x002d0e20
// Walks the selected group from its last item down to the first and dispatches each to its handler.
void Dispatcher_2d0e20::FUN_002d0e20(int selector, int arg)
{
    Iter_2d0e20 it;
    it.FUN_002e5850(source, selector);
    if (it.index >= 0) {
        do {
            Item_2d0e20* item = 0;
            if (it.index >= 0)
                item = it.cont->groups[it.group].items[it.index];
            handlers[item->slot]->FUN_002e11e0(item, arg);
            if (it.index < 0)
                break;
            it.index--;
        } while (it.index >= 0);
    }
    it.FUN_002e5310();
}

} // namespace fn_f491b664

// 0x002d0eb0 FUN_002d0eb0 (95 B): matches/0x002d0eb0.cpp
// sym: ?FUN_002d0eb0@Buffer_2d0eb0@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2d0eb0::FUN_002d0eb0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)FUN_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002d0cc0((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

