// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 51/58, incomplete)
// FUN_00093950 @ 0x00093950
#include "decls/address.h"
#include "gen/owners.h"
class CUnlockable_93950 {
public:
    virtual void v0();
    char pad04[4];
    char flag;
    char pad09[0x10 - 9];
    int pos0;
    int pos1;
    void *obj18;
};

class CUnlockableCheat_93950 : public CUnlockable_93950 {
public:
    char pad1c[0x24 - 0x1c];
    int link;
    char name[1];
};

class FEObject_93950 {
public:
    virtual void vfunc_0();
};

class TextSelector_93950 : public FEObject_93950 {
public:
    char pad04[0x141 - 4];
    char marked;
};

struct Mgr_93950 {
};

struct Holder_93950 {
    Mgr_93950 *FUN_000b5000();
};

struct Menu_93950 {
    CUnlockable_93950 *slots[0x266];
    char pad[0xd88 - 0x998];
    Holder_93950 *holder;

    void FUN_00093600(int index, int arg);
    void FUN_00093950(const char *name, char wait, unsigned char *outFound, char *outLinked, unsigned char *outPicked, int *outPos);
};

FEObject_93950 *__cdecl FUN_000fc260(void *name);

void Menu_93950::FUN_00093950(const char *name, char wait, unsigned char *outFound, char *outLinked, unsigned char *outPicked, int *outPos)
{
    unsigned __int64 h = FUN_0027b020(name);
    *outFound = 0;
    *outLinked = 0;
    *outPicked = 0;
    char ready = 0;
    Mgr_93950 *mgr = 0;
    if (holder)
        mgr = holder->FUN_000b5000();

    int i;
    for (i = 0x261; i <= 0x265; i++) {
        CUnlockableCheat_93950 *c = dynamic_cast<CUnlockableCheat_93950 *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (wait)
                return;
            *outPicked = 1;
            CUnlockable_93950 *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            return;
        }
    }

    for (i = 0; i <= 0x1e; i++) {
        CUnlockableCheat_93950 *c = dynamic_cast<CUnlockableCheat_93950 *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (i == 4 || i == 3) {
                *outLinked = 1;
                if (mgr && ((char)((owners::Target_893c0 *)mgr)->FUN_000893c0()))
                    ready = 1;
            }
            if (c->link != -1) {
                *outLinked = 1;
                if (slots[c->link]->flag == 0)
                    ready = 1;
            }
            if (wait)
                return;
            if (*outLinked != 0 && !ready)
                return;
            *outPicked = 1;
            CUnlockable_93950 *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            TextSelector_93950 *t = dynamic_cast<TextSelector_93950 *>(FUN_000fc260(slots[i]->obj18));
            if (t)
                t->marked = 1;
            return;
        }
    }

    for (i = 0x1f; i <= 0x32; i++) {
        CUnlockableCheat_93950 *c = dynamic_cast<CUnlockableCheat_93950 *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (c->link != -1) {
                *outLinked = 1;
                if (slots[c->link]->flag == 0)
                    ready = 1;
            }
            if (wait)
                return;
            if (*outLinked != 0 && !ready)
                return;
            *outPicked = 1;
            CUnlockable_93950 *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            return;
        }
    }
}
