// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008c570..0x0008ceb0 (kind game, layer game, confidence medium), dominant class CMemoryCardManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f93cbeb5 {
#define TREE_TU_END }
namespace fn_f93cbeb5 {} using namespace fn_f93cbeb5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f93cbeb5 {
struct S_8c710 {
    char pad[0x10];
    unsigned char b[0x20];
};
struct Slot_8c740 {
    int owner;
    unsigned int bits;
    char rest[0xc0];
};
struct SlotTable_8c740 {
    char pad0[0x5c];
    Slot_8c740 slots[1];
};
extern "C" void __cdecl FUN_0008c710(void *, unsigned short *);
class SlotSet {
public:
    char pad0[8];
    SlotTable_8c740* table;
    int FUN_0008c740(int index, unsigned int* outBits, hulk_intptr value);
};
class Entry_8c810 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
};
struct Slot_8c810 {
    Entry_8c810* first;
    Entry_8c810* second;
    char pad[192];
};
class Owner_8c810 {
  public:
    char pad[8];
    Slot_8c810* h;
    int target(int);
};
struct Resource_8c870 { virtual void slot0(); virtual void release(); };
struct Owner_8c870 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void reset(void*); };
struct Entry_8c870 {
 Owner_8c870* owner;
 Resource_8c870* resource;
 char data[0x54];
 int state;
 char pad60[12];
 unsigned char flag6c, flag6d;
 char pad6e[0x46];
 int enabled[5];
};
struct Manager_8c870 {
 char pad[8];
 Entry_8c870* entries;
 void reset(int index);
};
class Item_8ca30 {
  public:
    virtual void A();
    virtual void B();
};
class BaseItem {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
};
struct Record_8ca30 {
    BaseItem* first;
    Item_8ca30* second;
    char pad[192];
};
class Owner_8ca30 {
  public:
    char pad[8];
    Record_8ca30* items;
    void Run(int index);
};


// 0x0008c570 FUN_0008c570 (6 B): matches/0x0008c570.cpp
// sym: ?FUN_0008c570@fn_f93cbeb5@@YAHXZ
int FUN_0008c570() {
    return 1;
}


// 0x0008c580 FUN_0008c580 (6 B): matches/0x0008c580.cpp
// sym: _FUN_0008c580
extern "C" int FUN_0008c580() {
    return 5;
}


// 0x0008c710 FUN_0008c710 (48 B): matches/0x0008c710.cpp
// sym: _FUN_0008c710
extern "C" void FUN_0008c710(void * a, unsigned short* d) {
    if (d) {
        unsigned char* p = ((S_8c710 *)a)->b;
        int i = 0;
        do {
            if (p[0] == 0)
                break;
            d[i] = p[i];
            i++;
        } while (i < 0x1f);
        d[i] = 0;
    }
}


// 0x0008c740 FUN_0008c740 (121 B): equivalent/0x0008c740.cpp
// sym: ?FUN_0008c740@SlotSet@fn_f93cbeb5@@QAEHHPAIH@Z @78bd4c8ea1d6 @w7205194c5dfd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_0008c740 @ 0x0008c740
int SlotSet::FUN_0008c740(int index, unsigned int* outBits, hulk_intptr value) {
    if (value)
        FUN_0008c710((Slot_8c740 *)(&table->slots[index]), (unsigned short *)(hulk_uintptr)(int)value);
    if (outBits) {
        Slot_8c740* s = (Slot_8c740*)((char*)table + 0x5c + index * sizeof(Slot_8c740));
        if (s == 0 || s->owner != 0) {
            *outBits = 0;
            return table->slots[index].owner;
        }
        *outBits = s->bits >> 14;
    }
    return table->slots[index].owner;
}

} // namespace fn_f93cbeb5

// 0x0008c7c0 CMemoryCardManager::vfunc_0 (5 B): matches/0x0008c7c0.cpp
// sym: ?vfunc_0@CMemoryCardManager@@UAE_NPAX0000@Z
bool CMemoryCardManager::vfunc_0(void* __p0, void* __p1, void* __p2, void* __p3, void* __p4) {
    return false;
}


// 0x0008c7f0 FUN_0008c7f0 (17 B): matches/0x0008c7f0.cpp [wrapped: conflict: CMemoryCardManager]
// sym: ??0CMemoryCardManager@fn_0008c7f0@@QAE@XZ
namespace fn_0008c7f0 {
class CMemoryCardManager {
  public:
    virtual bool Fnf_0008c7c0(void*, void*, void*, void*, void*);
    int a;
    int b;
    CMemoryCardManager();
};
CMemoryCardManager::CMemoryCardManager() {
    a = 0;
    b = 0;
}
} // namespace fn_0008c7f0

namespace fn_f93cbeb5 {

// 0x0008c810 FUN_0008c810 (83 B): matches/0x0008c810.cpp
// sym: ?target@Owner_8c810@fn_f93cbeb5@@QAEHH@Z
int Owner_8c810::target(int i) {
    h[i].first->f22();
    if (h[i].second) {
        h[i].second->f21();
        Entry_8c810** pp = &h[i].second;
        if (*pp) {
            (*pp)->f1();
            *pp = 0;
        }
    }
    return 8;
}


// 0x0008c870 FUN_0008c870 (171 B): equivalent/0x0008c870.cpp
// sym: ?reset@Manager_8c870@fn_f93cbeb5@@QAEXH@Z @55f645ad483b @wd7f39a439211
// STATUS: equivalent (tools/equiv.py level 3: 2963 inputs, branch coverage 4/4)
// FUN_0008c870 @ 0x0008c870
void Manager_8c870::reset(int index) {
 entries[index].state = 4;
 entries[index].flag6c = 0;
 entries[index].flag6d = 0;
 Resource_8c870** resource = &entries[index].resource;
 if (*resource) {
  (*resource)->release();
  *resource = 0;
 }
 entries[index].enabled[0] = 1;
 entries[index].enabled[1] = 1;
 entries[index].enabled[2] = 1;
 entries[index].enabled[3] = 1;
 entries[index].enabled[4] = 1;
 Entry_8c870* entry = &entries[index];
 if (entry->owner) entry->owner->reset(entry->data);
}


// 0x0008ca30 FUN_0008ca30 (58 B): matches/0x0008ca30.cpp
// sym: ?Run@Owner_8ca30@fn_f93cbeb5@@QAEXH@Z
void Owner_8ca30::Run(int index) {
    Item_8ca30** p = &items[index].second;
    Item_8ca30* item = *p;
    if (item) {
        item->B();
        *p = 0;
    }
    items[index].first->v22();
}

} // namespace fn_f93cbeb5
