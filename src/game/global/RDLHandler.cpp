// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00044910..0x00044c60 (kind game, layer game, confidence medium), dominant class RDLHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe338dd9 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe338dd9 {} using namespace fn_fe338dd9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe338dd9 {
struct Entry_44910 {
    char pad[0x5c];
    int value;                      // 0x5c
};
struct Registry_44910 {
    Entry_44910 *FUN_00232840(unsigned __int64 key);
};
struct Handle_44910 {
    int first;
    int second;
    int third;
    void FUN_00233fe0(int v);
};
struct Obj_44910 {
    char pad[0xe0];
    Handle_44910 h[6];                    // 0xe0 .. 0x128
    bool FUN_00044910();
};
struct Entry_449c0 {
    char pad[0x5c];
    int value;                      // 0x5c
};
struct Registry_449c0 {
    Entry_449c0 *FUN_00232840(unsigned __int64 key);
};
struct Handle_449c0 {
    int first;
    int second;
    int third;
    void FUN_00234090(int v);
};
struct Obj_449c0 {
    char pad[0xe0];
    Handle_449c0 h[6];                    // 0xe0 .. 0x128
    bool FUN_000449c0();
};
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class RDLHandler_44a80 : public CAction {
  public:
    RDLHandler_44a80* vfunc_2(unsigned char);
};
extern void __fastcall FUN_0027a560(void*);
extern void thunk_FUN_00267090(RDLHandler_44a80*);
typedef unsigned int U32_44ad0;
struct Pair_44ad0 {
    U32_44ad0 lo;
    U32_44ad0 hi;
};
Pair_44ad0 __cdecl Lookup(U32_44ad0);
class RDLHandler_44ad0 {
  public:
    char pad[12];
    int count;
    int* items;
    hulk_intptr Find(U32_44ad0 a, U32_44ad0 b);
};
struct Item_44b30 {
    char pad[0x3b0];
    char a[0x40];
    char b[0x40];
};
long long GetId(void* p);
class Mgr_44b30 {
  public:
    char pad[0xc];
    int mCount;
    Item_44b30** mItems;
    Item_44b30* Find(long long id);
};
class Obj {
  public:
};
struct Item_44c00 {
    void Do();
};
class X_44c00 {
  public:
    char pad[0x0c];
    int count;
    Item_44c00** items;
    bool Run();
};
struct Item_44c30 {
    void Do();
};
class X_44c30 {
  public:
    char pad[0x0c];
    int count;
    Item_44c30** items;
    bool Run();
};


// 0x00044910 FUN_00044910 (163 B): equivalent/0x00044910.cpp
// sym: ?FUN_00044910@Obj_44910@fn_fe338dd9@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00044910 @ 0x00044910
// Look up five-plus-one named entries in the global registry and seed the six handles.
bool Obj_44910::FUN_00044910()
{
    const char *name = (*(const char**)&DAT_0048f698);
    Registry_44910 *reg = (*(Registry_44910**)&DAT_004e5af8);
    h[0].FUN_00233fe0(reg->FUN_00232840(FUN_002672f0(name, 0, 0))->value);
    h[1].FUN_00233fe0(h[0].first);
    h[2].FUN_00233fe0(h[0].first);
    h[3].FUN_00233fe0(h[0].first);
    h[4].FUN_00233fe0(h[0].first);
    name = (*(const char**)&DAT_0048f69c);
    reg = (*(Registry_44910**)&DAT_004e5af8);
    h[5].FUN_00233fe0(reg->FUN_00232840(FUN_002672f0(name, 0, 0))->value);
    return true;
}


// 0x000449c0 FUN_000449c0 (172 B): equivalent/0x000449c0.cpp
// sym: ?FUN_000449c0@Obj_449c0@fn_fe338dd9@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000449c0 @ 0x000449c0
// Look up two named entries in the global registry and seed the six handles (reverse order of FUN_00044910).
bool Obj_449c0::FUN_000449c0()
{
    const char *name = (*(const char**)&DAT_0048f69c);
    Registry_449c0 *reg = (*(Registry_449c0**)&DAT_004e5af8);
    h[5].FUN_00234090(reg->FUN_00232840(FUN_002672f0(name, 0, 0))->value);
    name = (*(const char**)&DAT_0048f698);
    reg = (*(Registry_449c0**)&DAT_004e5af8);
    Entry_449c0 *entry = reg->FUN_00232840(FUN_002672f0(name, 0, 0));
    h[4].FUN_00234090(h[0].first);
    h[3].FUN_00234090(h[0].first);
    h[2].FUN_00234090(h[0].first);
    h[1].FUN_00234090(h[0].first);
    h[0].FUN_00234090(entry->value);
    return true;
}


// 0x00044a80 RDLHandler::vfunc_1 (30 B): matches/0x00044a80.cpp
// sym: ?vfunc_2@RDLHandler_44a80@fn_fe338dd9@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
RDLHandler_44a80* RDLHandler_44a80::vfunc_2(unsigned char flags) {
    FUN_0027a560((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fe338dd9

// 0x00044ab0 FUN_00044ab0 (27 B): matches/0x00044ab0.cpp
// sym: ?FUN_00044ab0@C_44ab0@owners@@QAEHH@Z
hulk_intptr owners::C_44ab0::FUN_00044ab0(int i) {
    if (i >= 0 && i < count)
        return items[i];
    return 0;
}

namespace fn_fe338dd9 {

// 0x00044ad0 FUN_00044ad0 (85 B): matches/0x00044ad0.cpp
// sym: ?Find@RDLHandler_44ad0@fn_fe338dd9@@QAEHII@Z
hulk_intptr RDLHandler_44ad0::Find(U32_44ad0 a, U32_44ad0 b) {
    int i = 0;
    while (i < count) {
        int item = items[i];
        if (item) {
            Pair_44ad0 v = Lookup((U32_44ad0)(item + 0x3b0));
            if (v.lo == a && v.hi == b)
                return items[i];
        }
        ++i;
    }
    return 0;
}


// 0x00044b30 FUN_00044b30 (113 B): matches/0x00044b30.cpp
// sym: ?Find@Mgr_44b30@fn_fe338dd9@@QAEPAUItem_44b30@2@_J@Z
Item_44b30* Mgr_44b30::Find(long long id) {
    for (int i = 0; i < mCount; i++) {
        Item_44b30* it = mItems[i];
        if (it) {
            bool hit = GetId(it->b) == id;
            if (!hit) {
                Item_44b30* q = mItems[i];
                hit = GetId(q->a) == id;
            }
            if (hit)
                return mItems[i];
        }
    }
    return 0;
}


// 0x00044be0 FUN_00044be0 (18 B): matches/0x00044be0.cpp
// sym: ?FUN_00044be0@fn_fe338dd9@@YIXPAX0PAVObj@1@@Z
void __fastcall FUN_00044be0(void* p, void* unused, Obj* obj) {
    ((owners::Obj_27a590 *)obj)->FUN_0027a590((hulk_intptr)"RdlCharacterTemplate", (hulk_intptr)p);
}


// 0x00044c00 FUN_00044c00 (44 B): matches/0x00044c00.cpp
// sym: ?Run@X_44c00@fn_fe338dd9@@QAE_NXZ
bool X_44c00::Run() {
    int i;
    for (i = 0; i < count; ++i) {
        Item_44c00* p = items[i];
        if (p)
            p->Do();
    }
    return true;
}


// 0x00044c30 FUN_00044c30 (44 B): matches/0x00044c30.cpp
// sym: ?Run@X_44c30@fn_fe338dd9@@QAE_NXZ
// Same code shape as 0x00044c00 (propagated; names are from that function)
bool X_44c30::Run() {
    int i;
    for (i = 0; i < count; ++i) {
        Item_44c30* p = items[i];
        if (p)
            p->Do();
    }
    return true;
}

} // namespace fn_fe338dd9
