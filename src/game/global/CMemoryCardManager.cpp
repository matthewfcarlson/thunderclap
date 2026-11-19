// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008c570..0x0008ceb0 (kind game, layer game, confidence medium), dominant class CMemoryCardManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "decls/drive_media.h"
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
// (drive1) the manager's slots (decls/drive_media.h GameMemoryCardSlot, GameMemoryCardManager); were 32-bit pad views
extern "C" void __cdecl FUN_0008c710(void *, unsigned short *);
class SlotSet : public GameMemoryCardManager {
public:
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
class Owner_8c810 : public GameMemoryCardManager {
  public:
    int target(int);
};
struct Resource_8c870 { virtual void slot0(); virtual void release(); };
struct Owner_8c870 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void reset(void*); };
struct Manager_8c870 : GameMemoryCardManager {
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
class Owner_8ca30 : public GameMemoryCardManager {
  public:
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
// sym: ?FUN_0008c740@SlotSet@fn_f93cbeb5@@QAEHHPAIH@Z @78bd4c8ea1d6 @w549fded26c8a @v6bff6200724b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_0008c740 @ 0x0008c740
int SlotSet::FUN_0008c740(int index, unsigned int* outBits, hulk_intptr value) {
    if (value)
        FUN_0008c710(&slots[index].media, (unsigned short *)(hulk_uintptr)(int)value);
    if (outBits) {
        CoreDriveMedia* s = &slots[index].media;
        if (s == 0 || s->result != 0) {
            *outBits = 0;
            return (int)slots[index].media.result;
        }
        *outBits = s->size >> 14;
    }
    return (int)slots[index].media.result;
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
    GameMemoryCardSlot* b;   // (drive1) the slots (decls/drive_media.h GameMemoryCardManager; an int natively missed half)
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
    ((Entry_8c810*)slots[i].drive)->f22();
    if (slots[i].file) {
        ((Entry_8c810*)slots[i].file)->f21();
        Entry_8c810** pp = (Entry_8c810**)&slots[i].file;
        if (*pp) {
            (*pp)->f1();
            *pp = 0;
        }
    }
    return 8;
}


// 0x0008c870 FUN_0008c870 (171 B): equivalent/0x0008c870.cpp
// sym: ?reset@Manager_8c870@fn_f93cbeb5@@QAEXH@Z @55f645ad483b @wd7f39a439211 @vb2f65199adbb
// STATUS: equivalent (tools/equiv.py level 3: 2963 inputs, branch coverage 4/4)
// FUN_0008c870 @ 0x0008c870
void Manager_8c870::reset(int index) {
 slots[index].media.result = 4;
 slots[index].media.label.buffer[0] = 0;
 slots[index].media.label.buffer[1] = 0;
 Resource_8c870** resource = (Resource_8c870**)&slots[index].file;
 if (*resource) {
  (*resource)->release();
  *resource = 0;
 }
 slots[index].status[0] = 1;
 slots[index].status[1] = 1;
 slots[index].status[2] = 1;
 slots[index].status[3] = 1;
 slots[index].status[4] = 1;
 GameMemoryCardSlot* entry = &slots[index];
 if (entry->drive) ((Owner_8c870*)entry->drive)->reset(&entry->pending);
}


// 0x0008ca30 FUN_0008ca30 (58 B): matches/0x0008ca30.cpp
// sym: ?Run@Owner_8ca30@fn_f93cbeb5@@QAEXH@Z
void Owner_8ca30::Run(int index) {
    Item_8ca30** p = (Item_8ca30**)&slots[index].file;
    Item_8ca30* item = *p;
    if (item) {
        item->B();
        *p = 0;
    }
    ((BaseItem*)slots[index].drive)->v22();
}

} // namespace fn_f93cbeb5
