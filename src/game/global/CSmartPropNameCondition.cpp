// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00049450..0x00049740 (kind game, layer game, confidence medium), dominant class CSmartPropNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3758deb {
#define TREE_TU_END }
namespace fn_f3758deb {} using namespace fn_f3758deb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3758deb {
extern int* hulk_at_004dc4b8;
class CCondition_49470 {
  public:
    virtual int vfunc_0(int);
};
struct Pad_494c0;
struct Item_494c0 {
    char pad00[8];
    struct Holder_494c0 *holder;  // 0x8
    int kind;               // 0xc
};
struct Holder_494c0 {
    int FUN_001d64a0();
};
struct Pad_494c0 {
    Item_494c0 *FUN_001d72e0();
};
struct Player_494c0 {
    char pad00[0x3a4];
    Item_494c0 *fallbackItem;     // 0x3a4
    Pad_494c0 *FUN_00035ef0(int index);
};
struct PlayerRef_494c0 {
    Player_494c0 *FUN_00059a30();
};
struct Owner_494c0 {
    PlayerRef_494c0 *FUN_000592a0();
};
extern int* hulk_at_004dc4c0;
class CCondition_49570 {
  public:
    virtual int vfunc_0(int);
};


// 0x00049450 FUN_00049450 (19 B): matches/0x00049450.cpp
// sym: ?FUN_00049450@fn_f3758deb@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049450(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc4b8), ((char*)&DAT_004dc4bc));
}

} // namespace fn_f3758deb

// 0x00049470 CSmartPropTypeCondition::vfunc_0 (16 B): matches/0x00049470.cpp
// sym: ?vfunc_0@CSmartPropTypeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropTypeCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4b8;
    return p[index];
}


// 0x00049480 FUN_00049480 (34 B): matches/0x00049480.cpp [wrapped: conflict: CSmartPropTypeCondition]
// sym: ??0CSmartPropTypeCondition@fn_00049480@@QAE@XZ
namespace fn_00049480 {
class CCondition_49480 {
  public:
    CCondition_49480(int);
    virtual void f();
};
class CSmartPropTypeCondition : public ::CSmartPropTypeCondition {
  public:
    CSmartPropTypeCondition();
};
CSmartPropTypeCondition::CSmartPropTypeCondition() : ::CSmartPropTypeCondition(0) {
    compare = 0;
    type = 0;
}
} // namespace fn_00049480


// 0x000494c0 CSmartPropTypeCondition::vfunc_7 (131 B): matches/0x000494c0.cpp
// sym: ?vfunc_7@CSmartPropTypeCondition@@UAE_NPAX@Z
// CSmartPropTypeCondition::vfunc_7 @ 0x000494c0
bool CSmartPropTypeCondition::vfunc_7(void* __p0) { Owner_494c0 * owner = (Owner_494c0 *)__p0;

    Player_494c0 *player = owner->FUN_000592a0()->FUN_00059a30();

    Item_494c0 *item = 0;
    if (player->FUN_00035ef0(0) != 0)
        item = player->FUN_00035ef0(0)->FUN_001d72e0();
    if (item == 0)
        item = player->fallbackItem;

    int current = 0;
    if (item != 0 && item->kind == 5)
        current = item->holder->FUN_001d64a0();

    switch (this->compare) {
    case 0:
        return this->type == current;
    case 1:
        return this->type != current;
    }
    return false;
}

namespace fn_f3758deb {

// 0x00049550 FUN_00049550 (19 B): matches/0x00049550.cpp
// sym: ?FUN_00049550@fn_f3758deb@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049550(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc4c0), ((char*)&DAT_004dc4c4));
}

} // namespace fn_f3758deb

// 0x00049570 CSmartPropNameCondition::vfunc_0 (16 B): matches/0x00049570.cpp
// sym: ?vfunc_0@CSmartPropNameCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CSmartPropNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc4c0;
    return p[index];
}


// 0x000495b0 FUN_000495b0 (31 B): matches/0x000495b0.cpp [wrapped: conflict: CCondition; CSmartPropNameCondition]
// sym: ?Fn@CSmartPropNameCondition@fn_000495b0@@QAEXXZ
namespace fn_000495b0 {
extern "C" char DAT_003f6d50[];
extern "C" char DAT_003f719c[];
class Inner {
  public:
    Inner();
};
class CCondition {
  public:
    void Finish_002345b0();
};
class CSmartPropNameCondition {
  public:
    int pad[6];
    Inner m;
    void Fn();
};
void CSmartPropNameCondition::Fn() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f719c);
    m.Inner::Inner();
    *(void**)this = (void*)((hulk_intptr)DAT_003f6d50);
    ((CCondition*)this)->Finish_002345b0();
}
} // namespace fn_000495b0


// 0x000495d0 CSmartPropNameCondition::vfunc_7 (359 B): equivalent/0x000495d0.cpp [wrapped: conflict: CSmartPropNameCondition]
// sym: ?vfunc_7@CSmartPropNameCondition@fn_000495d0@@UAE_NPAX@Z @6e2154a02cb1 @wbc9b46102dd4
namespace fn_000495d0 {
// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 51/52, incomplete)
// CSmartPropNameCondition::vfunc_7 @ 0x000495d0
struct Value_495d0 {
    char pad00[0xc0];
    unsigned long long raw;
};
extern "C" unsigned long long __fastcall FUN_001d4f70(Value_495d0* v);

struct Key_495d0 {
    char pad00[8];
    unsigned int lo;
    unsigned int hi;
};

struct Item_495d0 {
    char pad00[0x9c];
    Key_495d0* key;
    char padA0[0x4c];
    Value_495d0* value;
};

struct Current_495d0 {
    char pad00[8];
    Item_495d0* item;
    int kind;
};

struct Fighter_495d0 {
    char pad00[0x3a4];
    Current_495d0* current;
    Item_495d0* FUN_00035ef0(int index);
};

void* __fastcall FUN_000592a0(void* owner);
extern "C" Fighter_495d0* __fastcall FUN_00059a30(void* holder);

class CSmartPropNameCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(void* params);
    char pad04[8];
    int mode;
    int slot;
    char pad14[4];
    unsigned int keyLo;
    unsigned int keyHi;
};

bool CSmartPropNameCondition::vfunc_7(void* params)
{
    if ((keyLo | keyHi) == 0)
        return false;

    Fighter_495d0* fighter = FUN_00059a30(FUN_000592a0(params));
    Item_495d0* item;

    if (slot == -1) {
        bool none = true;
        for (int i = 0; i < 8; i++) {
            item = fighter->FUN_00035ef0(i);
            if (!item)
                continue;
            none = false;
            int m = mode;
            Key_495d0* key = item->key;
            if (m == 0) {
                unsigned int lo = keyLo;
                unsigned int hi = keyHi;
                if (lo == key->lo && hi == key->hi)
                    return true;
                unsigned long long v = FUN_001d4f70(item->value);
                if (lo == (unsigned int)v && hi == (unsigned int)(v >> 32))
                    return true;
            } else if (m == 1) {
                unsigned int lo = keyLo;
                unsigned int hi = keyHi;
                if (lo != key->lo || hi != key->hi) {
                    unsigned long long v = FUN_001d4f70(item->value);
                    if (lo != (unsigned int)v || hi != (unsigned int)(v >> 32))
                        return true;
                }
            }
        }
        if (!none)
            return false;
        Current_495d0* cur = fighter->current;
        if (!cur || cur->kind != 5)
            return false;
        item = cur->item;
    } else {
        item = fighter->FUN_00035ef0(slot);
        if (!item) {
            Current_495d0* cur = fighter->current;
            if (!cur || cur->kind != 5)
                return false;
            item = cur->item;
        }
    }

    int m = mode;
    Key_495d0* key = item->key;
    if (m == 0) {
        unsigned int lo = keyLo;
        unsigned int hi = keyHi;
        if (lo == key->lo && hi == key->hi)
            return true;
        unsigned long long v = FUN_001d4f70(item->value);
        if (lo == (unsigned int)v && hi == (unsigned int)(v >> 32))
            return true;
    } else if (m == 1) {
        unsigned int lo = keyLo;
        if (lo != key->lo || keyHi != key->hi)
            FUN_001d4f70(item->value);
    }
    return false;
}
} // namespace fn_000495d0

