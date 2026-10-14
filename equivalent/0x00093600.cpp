// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 85/86, incomplete)
// FUN_00093600 @ 0x00093600
// equiv-map: ??_R0?AVCUnlockableBlonskyFile@@@8 = 0x0049dad4
// equiv-map: ??_R0?AVCUnlockableMove@@@8 = 0x0049db1c
// equiv-map: ?FUN_000c21b0@Env@@QAEXH@Z = 0x000c2c10
class CUnlockable {
public:
    virtual void v0();
    char pad04[4];
    char flag;
};

class CUnlockableGallery : public CUnlockable {
public:
    char pad0c[0xb0 - 0xc];
    char hidden;
};

class CUnlockableMove : public CUnlockable {
public:
    char pad0c[0x2d - 0xc];
    char hidden;
};

class CUnlockableBlonskyFile : public CUnlockable {
public:
    char pad0c[0xa8 - 0xc];
    char hidden;
};

struct Sound_93600 {
    void FUN_000900a0(int id);
};

struct Env {
    char pad0[0x50];
    Sound_93600 *sound;
    void FUN_000c21b0(int id);
};

struct Menu_93600 {
    CUnlockable *slots[0x266];
    char pad998[0xd88 - 0x998];
    Env *env;
    void FUN_00093600(int index, char on);
    char FUN_00092940(int index);
    void FUN_00092870(int index, int v);
};

void Menu_93600::FUN_00093600(int index, char on)
{
    int id = index;
    if (id == 0x2de || id == 0x2df || id == 0x2e0) {
        if (!on) {
            env->sound->FUN_000900a0(0x1f4);
            return;
        }
    } else if (id == 0x2c || id == 0x2d || id == 0x2e) {
        if (!on && !FUN_00092940(id)) {
            slots[id]->flag = 0;
            FUN_00092870(id, 1);
            env->sound->FUN_000900a0(id == 0x2c ? 0x1388 : id == 0x2d ? 0x2710 : 0x3a98);
            return;
        }
    } else if (id >= 0x1bf && id <= 0x247) {
        CUnlockable **p = &slots[id];
        for (int k = 0; k < 10; k++, p++, id++) {
            CUnlockable *u = *p;
            if (u->flag != on) {
                u->flag = on;
                CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(*p);
                if (g)
                    g->hidden = on == 0;
                if (env)
                    env->FUN_000c21b0(id);
            }
            if (id == 0x1f0 || id == 0x209 || id == 0x22d || id == 0x243 || id == 0x247)
                break;
        }
        return;
    } else if (id == 0x1c) {
        CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(slots[0x1c]);
        if (g)
            g->hidden = on == 0;
        int i;
        for (i = 0x248; i <= 0x257; i++) {
            FUN_00093600(i, 0);
            if (env)
                env->FUN_000c21b0(i);
        }
        for (i = 0x258; i <= 0x260; i++) {
            FUN_00093600(i, 0);
            if (env)
                env->FUN_000c21b0(i);
        }
        return;
    }

    CUnlockable *u = slots[id];
    if (u->flag == on)
        return;
    u->flag = on;
    CUnlockableGallery *g = dynamic_cast<CUnlockableGallery *>(slots[id]);
    if (g)
        g->hidden = on == 0;
    CUnlockableMove *m = dynamic_cast<CUnlockableMove *>(slots[id]);
    if (m)
        m->hidden = on == 0;
    CUnlockableBlonskyFile *b = dynamic_cast<CUnlockableBlonskyFile *>(slots[id]);
    if (b)
        b->hidden = on == 0;
    if (env)
        env->FUN_000c21b0(id);
}
