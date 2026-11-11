// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b69c0..0x001b6f70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f56ff9f7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f56ff9f7 {} using namespace fn_f56ff9f7;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f56ff9f7 {
class Item_1b69c0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner_1b69c0 {
  public:
    Item_1b69c0* items[32];
    void clear();
};
struct Item {
  public:
    virtual void _m_vf0();
    virtual void release();
    char _m_pad_4[0x4];
    int index;
    void Release() { release(); }
};
struct Arg {
    char pad[8];
    int index;
};
class Slots {
  public:
    Item* items[32];
    bool Remove(Arg* p);
};
inline void Clear(Item*& q) {
    if (q) {
        q->Release();
        q = 0;
    }
}
struct Manager { Item* entries[32]; void FUN_001b6a40(); };
class Item_1b6a90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int arg);
    int pad4;
    int link;
    float timer;
};
class ItemTable_1b6a90 {
public:
    void FUN_001b6a90(hulk_intptr unused, hulk_intptr arg);
    Item_1b6a90 *items[32];
};
class Item_1b6d00 {
  public:
    virtual void Release();
    virtual void AddRef();
};
class Owner_1b6d00 {
  public:
    void Remove_001b69f0(Item_1b6d00*);
    int Set(int index, Item_1b6d00* item);
};
class Data_1b6d60 {
  public:
    int a;
    char pad4[4];
    int b;
    char padc[4];
    int c;
};
struct Count {
    int n;
    Count() : n(0) {}
};
struct Entry {
    unsigned int x;
    int a, b, c;
    Entry() : x(0xbf800000), a(0), b(0), c(0) {}
};
class Obj {
  public:
    Count count;
    Entry entries[80];
    Obj();
};


// 0x001b69c0 FUN_001b69c0 (34 B): matches/0x001b69c0.cpp
// sym: ?clear@Owner_1b69c0@fn_f56ff9f7@@QAEXXZ
void Owner_1b69c0::clear() {
    for (int i = 0; i < 32; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
}


// 0x001b69f0 FUN_001b69f0 (69 B): matches/0x001b69f0.cpp
// sym: ?Remove@Slots@fn_f56ff9f7@@QAE_NPAUArg@2@@Z
bool Slots::Remove(Arg* p) {
    if (!p)
        return false;
    int i = p->index;
    if (i >= 0 && i < 32 && items[i]) {
        Clear(items[i]);
        return true;
    }
    return false;
}


// 0x001b6a40 FUN_001b6a40 (70 B): equivalent/0x001b6a40.cpp
// sym: ?FUN_001b6a40@Manager@fn_f56ff9f7@@QAEXXZ @ba48329ac5aa @w3d7710a63c72
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/16, incomplete)
// FUN_001b6a40 @ 0x001b6a40
void Manager::FUN_001b6a40() { for (int i=0; i<32; ++i) { Item* item=entries[i]; if (item) { int index=item->index; if (index>=0 && index<32) { Item* other=entries[index]; if (other) { other->release(); entries[index]=0; } } } } }


// 0x001b6a90 FUN_001b6a90 (106 B): equivalent/0x001b6a90.cpp
// sym: ?FUN_001b6a90@ItemTable_1b6a90@fn_f56ff9f7@@QAEXHH@Z @ba3b1e035ba7 @w4719717e344a
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/18, incomplete)
// FUN_001b6a90 @ 0x001b6a90
void ItemTable_1b6a90::FUN_001b6a90(hulk_intptr unused, hulk_intptr arg)
{
    for (unsigned int i = 0; i < 32; i++) {
        Item_1b6a90 *item = items[i];
        if (item == 0)
            continue;
        item->vf4(arg);
        if (item->timer <= 0.0f) {
            int link = item->link;
            if (link >= 0 && link < 32 && items[link] != 0) {
                items[link]->vf1();
                items[link] = 0;
            }
        }
    }
}

} // namespace fn_f56ff9f7

// 0x001b6b00 FUN_001b6b00 (498 B): equivalent/0x001b6b00.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001b6b00@SlotTable_1b6b00@fn_001b6b00@@QAEHHPAUV3_1b6b00@2@@Z @b6eba24b42de @w493f1e370d85
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001b6b00 {
// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 33/36, incomplete)
// FUN_001b6b00 @ 0x001b6b00
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_1b6b00 {
    float x, y, z;
};

struct Info_1b6b00 {
    char pad[0x114];
    int blocked;
};

class Slot_1b6b00 {
public:
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual V3_1b6b00 *getPos();
    virtual void v4();
    virtual Info_1b6b00 *getInfo();
    char pad08[0x8 - 4];
    int link;                // 0x08
    char pad0c[0x14 - 0xc];
    int priority;            // 0x14
};

struct Camera {
    void FUN_00059a50(V3_1b6b00 *out);
};

struct Reg124_1b6b00 {
    char pad[0x10];
    Camera *cam;
};

struct Reg20_1b6b00 {
    char pad[0x124];
    Reg124_1b6b00 *p124;
};

struct World {
    char pad[0x20];
    Reg20_1b6b00 *p20;
};


class SlotTable_1b6b00 {
public:
    Slot_1b6b00 *slots[32];
    int FUN_001b6b00(int bestPriority, V3_1b6b00 *pt);
};

static double dist2(V3_1b6b00 *a, V3_1b6b00 *b)
{
    double dx = (double)a->x - (double)b->x;
    double dy = (double)a->y - (double)b->y;
    double dz = (double)a->z - (double)b->z;
    return dz * dz + dy * dy + dx * dx;
}

int SlotTable_1b6b00::FUN_001b6b00(int bestPriority, V3_1b6b00 *pt)
{
    int i;
    for (i = 0; i < 32; i++) {
        if (slots[i] == 0)
            return i;
    }
    if (DAT_004dd700 == 0)
        return -1;
    Reg20_1b6b00 *r20 = DAT_004dd700->p20;
    if (r20 == 0)
        return -1;
    Reg124_1b6b00 *r124 = r20->p124;
    if (r124 == 0)
        return -1;

    V3_1b6b00 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    r124->cam->FUN_00059a50(&origin);

    float best = (float)dist2(pt, &origin);
    int bestIndex = -1;
    int prio = bestPriority;
    for (i = 0; i < 32; i++) {
        if (slots[i] == 0)
            continue;
        Info_1b6b00 *info = slots[i]->getInfo();
        if (info != 0 && info->blocked != 0)
            continue;
        int p = slots[i]->priority;
        if (p < prio) {
            bestIndex = i;
            prio = p;
            V3_1b6b00 *pos = slots[i]->getPos();
            best = (float)dist2(pos, &origin);
        } else if (p == prio) {
            V3_1b6b00 *pos = slots[i]->getPos();
            double d = dist2(pos, &origin);
            if (d < best) {
                best = (float)d;
                bestIndex = i;
            }
        }
    }

    if (bestIndex < 0)
        return -1;

    Slot_1b6b00 *s = slots[bestIndex];
    if (s != 0) {
        int j = s->link;
        if (j >= 0 && j < 32) {
            Slot_1b6b00 *t = slots[j];
            if (t != 0) {
                t->release();
                slots[j] = 0;
            }
        }
    }
    return bestIndex;
}
} // namespace fn_001b6b00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f56ff9f7 {

// 0x001b6d00 FUN_001b6d00 (85 B): matches/0x001b6d00.cpp
// sym: ?Set@Owner_1b6d00@fn_f56ff9f7@@QAEHHPAVItem_1b6d00@2@@Z
int Owner_1b6d00::Set(int index, Item_1b6d00* item) {
    if (index < 0)
        return -1;
    if (item == 0)
        return -1;
    Item_1b6d00* old = ((Item_1b6d00**)this)[index];
    if (old)
        Remove_001b69f0(old);
    item->Release();
    old = ((Item_1b6d00**)this)[index];
    if (old)
        old->AddRef();
    ((Item_1b6d00**)this)[index] = item;
    ((int*)item)[2] = index;
    return index;
}


// 0x001b6d60 FUN_001b6d60 (11 B): matches/0x001b6d60.cpp
// sym: ?FUN_001b6d60@fn_f56ff9f7@@YIXPAVData_1b6d60@1@@Z
void __fastcall FUN_001b6d60(Data_1b6d60* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
}

} // namespace fn_f56ff9f7

// 0x001b6d70 FUN_001b6d70 (98 B): matches/0x001b6d70.cpp
// sym: ?FUN_001b6d70@Obj_1b6d70@owners@@QAEXM@Z
void owners::Obj_1b6d70::FUN_001b6d70(float dt) {
    if (a != 0) {
        b -= dt;
        if (b <= 0.0f)
            a = 0;
    }
    if (c != 0) {
        d -= dt;
        if (d <= 0.0f)
            c = 0;
    }
    if (e != 0) {
        f -= dt;
        if (f <= 0.0f)
            e = 0;
    }
}


// 0x001b6de0 FUN_001b6de0 (30 B): matches/0x001b6de0.cpp
// sym: ?FUN_001b6de0@C_1b6de0@owners@@QAEXH@Z
void owners::C_1b6de0::FUN_001b6de0(hulk_intptr x) {
    int i = 0;
    do {
        if (a[i * 2] == ((int)x)) {
            a[i * 2] = 0;
            return;
        }
        ++i;
    } while (i < 3);
}


// 0x001b6e00 FUN_001b6e00 (85 B): equivalent/0x001b6e00.cpp [wrapped: merged class would differ: Holder: field entries: Field(+0x0 Entry [3] entries) vs Field(+0x0 Entry [3] entries)]
// sym: ?FUN_001b6e00@Holder@fn_001b6e00@@QAEXH@Z @e1e6512daeaf @w2708fc2302ae
namespace fn_001b6e00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/10, incomplete)
// FUN_001b6e00 @ 0x001b6e00

struct Entry { int id; float time; };
struct Holder { Entry entries[3]; void FUN_001b6e00(int id); };
void Holder::FUN_001b6e00(int id) {
    float oldest = (*(float*)&DAT_00405d2c);
    int selected = -1;
    for (int i = 0; i < 3; ++i) {
        if (entries[i].id == 0) {
            selected = i;
            break;
        }
        if (oldest > entries[i].time) {
            oldest = entries[i].time;
            selected = i;
        }
    }
    if (selected != -1) {
        entries[selected].id = id;
        entries[selected].time = 0.25f;
    }
}
} // namespace fn_001b6e00


// 0x001b6e60 FUN_001b6e60 (37 B): matches/0x001b6e60.cpp
// sym: ?FUN_001b6e60@Thing_1b6e60@owners@@QAEXH@Z
void owners::Thing_1b6e60::FUN_001b6e60(hulk_intptr param) {
    int i = 0;
    do {
        if (a[i * 2] == ((int)param)) {
            a[i * 2 + 1] = 0x3e800000;
            return;
        }
        ++i;
    } while (i < 3);
    fallback(((int)param));
}


// 0x001b6e90 FUN_001b6e90 (27 B): matches/0x001b6e90.cpp
// sym: ?FUN_001b6e90@X_1b6e90@owners@@QAE_NH@Z
bool owners::X_1b6e90::FUN_001b6e90(hulk_intptr v) {
    for (int i = 0; i < 3; ++i) {
        if (*((int*)((char*)this + i * 8)) == ((int)v))
            return true;
    }
    return false;
}

namespace fn_f56ff9f7 {

// 0x001b6ed0 FUN_001b6ed0 (40 B): matches/0x001b6ed0.cpp
// sym: ??0Obj@fn_f56ff9f7@@QAE@XZ
Obj::Obj() {}

} // namespace fn_f56ff9f7

// 0x001b6f00 FUN_001b6f00 (4 B): matches/0x001b6f00.cpp
// sym: ?FUN_001b6f00@Obj_1b6f00@owners@@QAEDXZ
char owners::Obj_1b6f00::FUN_001b6f00() {
    return pad[9];
}

