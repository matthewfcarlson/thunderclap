// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 51/58, incomplete)
// FUN_00093950 @ 0x00093950
class CUnlockable {
public:
    virtual void v0();
    char pad04[4];
    char flag;
    char pad09[0x10 - 9];
    int pos0;
    int pos1;
    void *obj18;
};

class CUnlockableCheat : public CUnlockable {
public:
    char pad1c[0x24 - 0x1c];
    int link;
    char name[1];
};

class FEObject {
public:
    virtual void vfunc_0();
};

class TextSelector : public FEObject {
public:
    char pad04[0x141 - 4];
    char marked;
};

struct Mgr {
    char FUN_000893c0();
};

struct Holder {
    Mgr *FUN_000b5000();
};

struct Menu {
    CUnlockable *slots[0x266];
    char pad[0xd88 - 0x998];
    Holder *holder;

    void FUN_00093600(int index, int arg);
    void FUN_00093950(const char *name, char wait, unsigned char *outFound, char *outLinked, unsigned char *outPicked, int *outPos);
};

unsigned __int64 __cdecl FUN_0027b020(const char *s);
FEObject *__cdecl FUN_000fc260(void *name);

void Menu::FUN_00093950(const char *name, char wait, unsigned char *outFound, char *outLinked, unsigned char *outPicked, int *outPos)
{
    unsigned __int64 h = FUN_0027b020(name);
    *outFound = 0;
    *outLinked = 0;
    *outPicked = 0;
    char ready = 0;
    Mgr *mgr = 0;
    if (holder)
        mgr = holder->FUN_000b5000();

    int i;
    for (i = 0x261; i <= 0x265; i++) {
        CUnlockableCheat *c = dynamic_cast<CUnlockableCheat *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (wait)
                return;
            *outPicked = 1;
            CUnlockable *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            return;
        }
    }

    for (i = 0; i <= 0x1e; i++) {
        CUnlockableCheat *c = dynamic_cast<CUnlockableCheat *>(slots[i]);
        if (c && FUN_0027b020(c->name) == h) {
            *outFound = 1;
            if (i == 4 || i == 3) {
                *outLinked = 1;
                if (mgr && mgr->FUN_000893c0())
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
            CUnlockable *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            TextSelector *t = dynamic_cast<TextSelector *>(FUN_000fc260(slots[i]->obj18));
            if (t)
                t->marked = 1;
            return;
        }
    }

    for (i = 0x1f; i <= 0x32; i++) {
        CUnlockableCheat *c = dynamic_cast<CUnlockableCheat *>(slots[i]);
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
            CUnlockable *u = slots[i];
            outPos[0] = u->pos0;
            outPos[1] = u->pos1;
            FUN_00093600(i, 0);
            return;
        }
    }
}
