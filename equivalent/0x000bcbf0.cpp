// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 26/26)
// FUN_000bcbf0 @ 0x000bcbf0
struct Pair {
    int a;
    int b;
};

struct Manager {
    int FUN_000f7240(int a, int b);
};
Manager *__cdecl FUN_000fc1b0();

struct TextEntry {
    char pad[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f7a10(int id, int flag);
    void FUN_000f8500(const char *name, Manager *manager, int flag);
};

extern char DAT_003f335c[];

class CUnlockable {
public:
    virtual void v0();
};

class CUnlockableMove : public CUnlockable {
public:
    char pad04[0x20 - 4];
    char flag20;
    char pad21[0x30 - 0x21];
    const char *name;
    int pad34;
    Pair id;
    char FUN_00091f40();
    const char *FUN_00092040();
    Pair *FUN_00092050();
};

class CUnlockableCheat : public CUnlockable {
public:
    char pad04[8 - 4];
    char f8;
    char pad09[0x20 - 9];
    char f20;
};

class FEObject {
public:
    virtual void vfunc_0();
};

FEObject *__cdecl FUN_000fc260(const char *name);

class TextSelector : public FEObject {
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
    virtual void vfunc_19(TextEntry *entry, int a, int b);
    virtual void vfunc_20(int index, TextEntry *entry);
    char pad04[0x1d58 - 4];
    int count;
    void FUN_000e36c0();
};

struct Unlockables {
    CUnlockable *FUN_00092ad0(int index);
    Pair *FUN_00092bb0(int index);
    int FUN_000932a0(int index);
};



struct NameSource {
    const char *FUN_0027b010();
};

struct Owner {
    char pad0[0x4c];
    Unlockables *items;
    void FUN_000bcbf0();
};

void Owner::FUN_000bcbf0()
{
    CUnlockableMove *first = dynamic_cast<CUnlockableMove *>(items->FUN_00092ad0(0x266));
    if (first == 0)
        return;
    const char *label = first->FUN_00092040();
    if (label == 0)
        return;
    TextSelector *sel = dynamic_cast<TextSelector *>(FUN_000fc260(label));
    if (sel == 0)
        return;

    char flag = 0;
    CUnlockableCheat *cheat = dynamic_cast<CUnlockableCheat *>(items->FUN_00092ad0(0x1d));
    if (cheat) {
        if (cheat->f8 != 0)
            flag = 0;
        else if (cheat->f20 != 0)
            flag = 1;
        else
            flag = 0;
    }

    TextEntry entry;
    entry.FUN_000f7930();
    entry.FUN_000f8500(DAT_003f335c, FUN_000fc1b0(), 1);
    sel->FUN_000e36c0();

    for (int i = 0x266; i <= 0x2c9; i++) {
        int slot = items->FUN_000932a0(i - 0x266);
        if (slot == -1)
            continue;
        Pair *p = items->FUN_00092bb0(slot);
        if ((p->a | p->b) == 0)
            continue;
        CUnlockableMove *move = dynamic_cast<CUnlockableMove *>(items->FUN_00092ad0(slot));
        if (move == 0)
            continue;
        if (!move->FUN_00091f40() && !flag)
            continue;
        Pair *q = items->FUN_00092bb0(slot);
        int id = FUN_000fc1b0()->FUN_000f7240(q->a, q->b);
        if (id != -1) {
            entry.FUN_000f7a10(id, 0);
        } else {
            Manager *m = FUN_000fc1b0();
            NameSource *ns = (NameSource *)items->FUN_00092bb0(slot);
            entry.FUN_000f8500(ns->FUN_0027b010(), m, 1);
        }
        sel->vfunc_19(&entry, 0, 0);
        Pair *r = move->FUN_00092050();
        int id2 = FUN_000fc1b0()->FUN_000f7240(r->a, r->b);
        entry.FUN_000f7a10(id2, 0);
        sel->vfunc_20(sel->count - 1, &entry);
    }
    sel->vfunc_3();
    entry.FUN_000f7960();
}
