// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 39/40, incomplete)
// FUN_001cbfe0 @ 0x001cbfe0
#include "decls/address.h"
#include "gen/global.h"
extern "C" void __cdecl qsort(void *base, unsigned int count, unsigned int size,
                              int (__cdecl *cmp)(const void *, const void *));

struct Item_1cbfe0 {
    int pad0;
    int type;
    char pad1[0xe0 - 8];
};

struct Event_1cbfe0 {
    int words[6];
    void FUN_001caf10(float dt);
};

struct CScenarioParams_1cbfe0 {
    CScenarioParams *FUN_001d0360(const Item_1cbfe0 *item);
};

class Node_1cbfe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual Node_1cbfe0 *vf8(CScenarioParams *task, int arg);
    char FUN_00232ed0(Node_1cbfe0 *other);
    Node_1cbfe0 *FUN_00231a00(CScenarioParams *task);
};

class Slot_1cbfe0 {
public:
    void FUN_002322f0(int a, float dt);
    void FUN_00231f20(int a);
    void FUN_002324b0(int a);
    char pad[0x28];
};

class Gfx {
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
};

int __cdecl FUN_00266da0(int value);
void *__cdecl FUN_0008d690(unsigned int size);
int __cdecl FUN_001cb3a0(const Item_1cbfe0 *a, const Item_1cbfe0 *b);

struct ItemVec_1cbfe0 {
    Item_1cbfe0 *begin;
    Item_1cbfe0 *end;
    void FUN_001cbd40(Item_1cbfe0 *first, Item_1cbfe0 *last);
};

class ItemQueue {
public:
    void FUN_001cbfe0(float dt);
    bool FUN_001cbc20(Event_1cbfe0 *ev);
    char FUN_001cb400(Item_1cbfe0 *item);
    unsigned int FUN_001cb7c0(Node_1cbfe0 *node, CScenarioParams *task);
    char FUN_001cbcb0(float dt);

    char pad0[0xc];
    ItemVec_1cbfe0 vec;
    char pad1[8];
    char sorted;
    char pad2[3];
    Node_1cbfe0 *owner;
    Slot_1cbfe0 slots[24];
    char free[24];
    char active;
    char pad3[3];
    Node_1cbfe0 *current;
};

void ItemQueue::FUN_001cbfe0(float dt)
{
    int old = FUN_00266da0(0xd);
    if (active && dt > 0.0f) {
        Event_1cbfe0 ev;
        ev.FUN_001caf10(dt);
        FUN_001cbc20(&ev);
    }
    for (int i = 0; i < 24; i++)
        free[i] = 1;
    qsort(vec.begin, vec.end - vec.begin, 0xe0, (int (__cdecl *)(const void *, const void *))FUN_001cb3a0);
    Item_1cbfe0 *last = vec.end;
    if (last != vec.begin) {
        if (sorted) {
            Item_1cbfe0 *item = last;
            do {
                item = item - 1;
                if (!FUN_001cb400(item)) {
                    void *mem = FUN_0008d690(0xf0);
                    CScenarioParams *task;
                    if (mem)
                        task = ((CScenarioParams_1cbfe0*)(((CScenarioParams *)mem)))->FUN_001d0360(item);
                    else
                        task = 0;
                    task->vfunc_0();
                    Node_1cbfe0 *o = owner;
                    if (o) {
                        if (current)
                            current->vf1();
                        current = 0;
                        Node_1cbfe0 *node = o->vf8(task, 0);
                        while (node) {
                            unsigned int idx = FUN_001cb7c0(node, task);
                            if (idx != (unsigned int)-1) {
                                bool match = false;
                                if (node == current || node->FUN_00232ed0(current))
                                    match = true;
                                if (item->type == 0xe || match) {
                                    if ((int)idx >= 0 && (int)idx < 24) {
                                        slots[idx].FUN_002322f0(1, dt);
                                        slots[idx].FUN_00231f20(0);
                                        slots[idx].FUN_002324b0(1);
                                        free[idx] = 0;
                                    }
                                }
                            }
                            node = node->FUN_00231a00(task);
                        }
                    }
                    task->vfunc_1();
                }
            } while (item != vec.begin);
        }
        Item_1cbfe0 *p = last;
        do {
            p = p - 1;
            if (p->type == 2)
                DAT_0052c2a8->v91();
        } while (p != vec.begin);
        vec.FUN_001cbd40(vec.begin, last);
    }
    FUN_001cbcb0(dt);
    FUN_00266da0(old);
}
