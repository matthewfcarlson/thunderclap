// STATUS: equivalent (tools/equiv.py level 3: 3045 inputs, branch coverage 34/36, incomplete)
// FUN_000b79a0 @ 0x000b79a0
#include "decls/address.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl _sprintf(char*, const char*, ...);
extern unsigned int DAT_004d9968;
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f470[];

struct Manager_b79a0 {
    unsigned __int64 FUN_000f72c0(unsigned int id);
    int FUN_000f7240(int a, int b);
};

struct Label_b79a0 {
    void FUN_000f7a10(int id, int flag);
    void FUN_000f8500(const char* text, Manager_b79a0* mgr, int flag);
};

class Widget_b79a0 {
public:
    virtual void v0();
};

class UiMgr_b79a0 {
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Manager_b79a0* v44();
};

class Panel_b79a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    char pad04[0x14];
    Label_b79a0 label;
};

struct Item_b79a0 {
    char pad00[0x14];
    unsigned int f14;
    char pad18[0x38 - 0x18];
};

struct Selector_b79a0 {
    char pad00[0x154];
    int cur;
    Item_b79a0 items[1];
    char pad_[0x1d58 - 0x154 - 4 - 0x38];
    int count;
};

struct NameSource_b79a0 {
    const char* FUN_0027b010();
};

struct Entry_b79a0 {
    unsigned __int64 id;
    unsigned __int64 key;
    int nameLo;
    int nameHi;
    int f18;
    int f1c;
    int f20;
    int f24;
};

struct Counter_b79a0 {
    void FUN_0008baf0(int* a, int* b);
};

struct Briefings {
    void* FUN_001ec480(const char* name, const char* arg);
};

union Slot_b79a0 {
    const char* name;
    unsigned int index;
    int value;
};

Widget_b79a0* __cdecl FUN_000fc260(const char* name);
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
UiMgr_b79a0* __cdecl FUN_000fc3d0();
Manager_b79a0* __cdecl FUN_000fc1b0();
int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);

class Briefing {
public:
    char pad00[0x34];
    Counter_b79a0* counter;           // 0x34
    char pad38[4];
    Briefings* briefings;       // 0x3c
    char pad40[0x26c - 0x40];
    const char* names[1];       // 0x26c
    char pad270[0x470 - 0x270];
    Entry_b79a0 entries[0x80];        // 0x470
    void FUN_000b79a0(Slot_b79a0 a1, Slot_b79a0 a2);
};

void Briefing::FUN_000b79a0(Slot_b79a0 a1, Slot_b79a0 a2)
{
    unsigned int cookie = DAT_004d9968;
    Panel_b79a0* menu = (Panel_b79a0*)FUN_00344e74(FUN_000fc260(a1.name), 0, DAT_0049dba4, DAT_0049f470, 0);
    if (menu == 0) {
        __security_check_cookie(cookie);
        return;
    }
    Selector_b79a0* sel = (Selector_b79a0*)FUN_00344e74(FUN_000fc260(a2.name), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    Selector_b79a0* missions = (Selector_b79a0*)FUN_00344e74(FUN_000fc260("mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    FUN_00344e74(FUN_000fc260("story_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    FUN_00344e74(FUN_000fc260("side_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);

    int id = -1;
    if (sel != 0 && sel->count > 0) {
        Item_b79a0* item = &sel->items[sel->cur];
        UiMgr_b79a0* ui = FUN_000fc3d0();
        unsigned int itemId = item->f14;
        unsigned __int64 key = ui->v44()->FUN_000f72c0(itemId);
        unsigned __int64 key2 = 0;
        if (sel == missions)
            key2 = FUN_0027b020(names[sel->cur]);
        for (int i = 0; i < 0x80; i++) {
            Entry_b79a0* e = &entries[i];
            if (e->id == 0)
                break;
            if ((e->key == key || e->id == key2) && e->f20 >= 0 && e->f24 >= 0) {
                a1.index = i;
                UiMgr_b79a0* ui2 = FUN_000fc3d0();
                int lo = e->nameLo;
                int hi = e->nameHi;
                Manager_b79a0* mgr = ui2->v44();
                id = mgr->FUN_000f7240(lo, hi);
                char buf[0x20];
                FUN_000964a0(buf, 0x20, "c%02dm%02d", e->f20, e->f24);
                briefings->FUN_001ec480("Briefings", buf);
                break;
            }
        }
    } else if (counter != 0) {
        int a;
        counter->FUN_0008baf0(&a, &a2.value);
        char buf[8] = "";
        _sprintf(buf, "c%2dm%2d", a, a2.value);
        briefings->FUN_001ec480("Briefings", buf);
        for (int i = 0; i < 0x80; i++) {
            Entry_b79a0* e = &entries[i];
            if (e->id == 0)
                break;
            if (e->f20 == a && e->f24 == a2.value) {
                a1.index = i;
                UiMgr_b79a0* ui2 = FUN_000fc3d0();
                int lo = e->nameLo;
                int hi = e->nameHi;
                Manager_b79a0* mgr = ui2->v44();
                id = mgr->FUN_000f7240(lo, hi);
                break;
            }
        }
    }
    if (id != -1) {
        menu->label.FUN_000f7a10(id, 0);
    } else {
        NameSource_b79a0* ns = (NameSource_b79a0*)((char*)this + a1.index * 0x28 + 0x480);
        menu->label.FUN_000f8500(ns->FUN_0027b010(), FUN_000fc1b0(), 1);
    }
    menu->v3();
    __security_check_cookie(cookie);
}
