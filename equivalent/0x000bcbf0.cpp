// STATUS: equivalent (tools/equiv.py level 3: 11601 inputs, branch coverage 26/26)
// FUN_000bcbf0 @ 0x000bcbf0
#include "decls/data/game/global.h"
#include "gen/owners.h"

struct Pair_bcbf0 {
    int a;
    int b;
};

struct Manager_bcbf0 {
    int FUN_000f7240(int a, int b);
};
Manager_bcbf0 *__cdecl FUN_000fc1b0();

struct TextEntry_bcbf0 {
    char pad[0x24];
    void FUN_000f8500(const char *name, Manager_bcbf0 *manager, int flag);
};


class CUnlockable_bcbf0 {
public:
    virtual void v0();
};

class CUnlockableMove_bcbf0 : public CUnlockable_bcbf0 {
public:
    char pad04[0x20 - 4];
    char flag20;
    char pad21[0x30 - 0x21];
    const char *name;
    int pad34;
    Pair_bcbf0 id;
    char FUN_00091f40();
    const char *FUN_00092040();
    Pair_bcbf0 *FUN_00092050();
};

class CUnlockableCheat_bcbf0 : public CUnlockable_bcbf0 {
public:
    char pad04[8 - 4];
    char f8;
    char pad09[0x20 - 9];
    char f20;
};

class FEObject_bcbf0 {
public:
    virtual void vfunc_0();
};

FEObject_bcbf0 *__cdecl FUN_000fc260(const char *name);

class TextSelector_bcbf0 : public FEObject_bcbf0 {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(TextEntry_bcbf0 *entry, int a, int b);
    virtual void vfunc_20(int index, TextEntry_bcbf0 *entry);
    char pad04[0x1d58 - 4];
    int count;
    void FUN_000e36c0();
};

struct Unlockables_bcbf0 {
};



struct NameSource_bcbf0 {
    const char *FUN_0027b010();
};

struct Owner_bcbf0 {
    char pad0[0x4c];
    Unlockables_bcbf0 *items;
    void FUN_000bcbf0();
};

void Owner_bcbf0::FUN_000bcbf0()
{
    CUnlockableMove_bcbf0 *first = dynamic_cast<CUnlockableMove_bcbf0 *>(((CUnlockable_bcbf0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)0x266)));
    if (first == 0)
        return;
    const char *label = first->FUN_00092040();
    if (label == 0)
        return;
    TextSelector_bcbf0 *sel = dynamic_cast<TextSelector_bcbf0 *>(FUN_000fc260(label));
    if (sel == 0)
        return;

    char flag = 0;
    CUnlockableCheat_bcbf0 *cheat = dynamic_cast<CUnlockableCheat_bcbf0 *>(((CUnlockable_bcbf0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)0x1d)));
    if (cheat) {
        if (cheat->f8 != 0)
            flag = 0;
        else if (cheat->f20 != 0)
            flag = 1;
        else
            flag = 0;
    }

    TextEntry_bcbf0 entry;
    ((owners::State_f7930 *)&entry)->FUN_000f7930();
    Manager_bcbf0 * tmp1 = FUN_000fc1b0();
    entry.FUN_000f8500(((char*)&DAT_003f335c), tmp1, 1);
    sel->FUN_000e36c0();

    for (int i = 0x266; i <= 0x2c9; i++) {
        int slot = ((owners::C_932a0 *)items)->FUN_000932a0(i - 0x266);
        if (slot == -1)
            continue;
        Pair_bcbf0 *p = ((Pair_bcbf0 *)((owners::C_92bb0 *)items)->FUN_00092bb0(slot));
        if ((p->a | p->b) == 0)
            continue;
        CUnlockableMove_bcbf0 *move = dynamic_cast<CUnlockableMove_bcbf0 *>(((CUnlockable_bcbf0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)slot)));
        if (move == 0)
            continue;
        if (!move->FUN_00091f40() && !flag)
            continue;
        Pair_bcbf0 *q = ((Pair_bcbf0 *)((owners::C_92bb0 *)items)->FUN_00092bb0(slot));
        int arg1_ = q->b;
        int arg2_ = q->a;
        int id = FUN_000fc1b0()->FUN_000f7240(arg2_, arg1_);
        if (id != -1) {
            ((owners::Obj_f7a10 *)&entry)->FUN_000f7a10((hulk_intptr)id, 0);
        } else {
            Manager_bcbf0 *m = FUN_000fc1b0();
            NameSource_bcbf0 *ns = (NameSource_bcbf0 *)((Pair_bcbf0 *)((owners::C_92bb0 *)items)->FUN_00092bb0(slot));
            const char * tmp2 = ns->FUN_0027b010();
            entry.FUN_000f8500(tmp2, m, 1);
        }
        sel->vfunc_19(&entry, 0, 0);
        Pair_bcbf0 *r = move->FUN_00092050();
        int arg3_ = r->b;
        int arg4_ = r->a;
        int id2 = FUN_000fc1b0()->FUN_000f7240(arg4_, arg3_);
        ((owners::Obj_f7a10 *)&entry)->FUN_000f7a10((hulk_intptr)id2, 0);
        sel->vfunc_20(sel->count - 1, &entry);
    }
    sel->vfunc_3();
    ((owners::Thing_f7960 *)&entry)->FUN_000f7960();
}
