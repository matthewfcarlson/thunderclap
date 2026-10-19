// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 66/66)
// FUN_000c2c20 @ 0x000c2c20
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
extern char DAT_0049dba4[];
extern char DAT_0049dab8[];
extern char DAT_0049db1c[];
extern char DAT_0049dbbc[];
extern char DAT_0049f470[];
extern char DAT_0049f48c[];
extern char DAT_0049f4a4[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);
extern int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
extern int __cdecl FUN_000fc020(char *buf, int size, ...);
extern void __cdecl FUN_000fc280(const char *name);

struct Shader;
struct Tex;

struct Name_c2c20 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    Name_c2c20 *FUN_0027b0e0(const char *s);
    void FUN_0027af70(const Name_c2c20 *other);
    void FUN_0027af50();
    const char *FUN_0027b010();
};

struct Loc_c2c20 {
    int FUN_000f7240(unsigned int lo, unsigned int hi);
    const char *FUN_00088ea0(const char *id);
};
extern Loc_c2c20 *__cdecl FUN_000fc1b0();

struct Label_c2c20 {
    void FUN_000f8500(const char *text, Loc_c2c20 *loc, char flag);
    void FUN_000f7a10(int idx, int z);
    void FUN_000f79a0(const char *text, int z);
};

class Widget_c2c20 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x18 - 4];
    Label_c2c20 label;
    char pad2c[0x74 - 0x18 - sizeof(Label_c2c20)];
    char b74;
    char pad75[0x141 - 0x75];
    char b141;
    char pad142[0x154 - 0x142];
    int sel;
    char pad158[0x1d58 - 0x158];
    void *p1d58;
};

struct Unlockable {
    char pad0[0x10];
    Name_c2c20 id;
    const char *FUN_00092040();
    Name_c2c20 *FUN_00092050();
    Name_c2c20 *FUN_00092070();
    const char *FUN_00092090();
    char FUN_00091f40();
    char FUN_00091fb0();
};

struct Unlockables_c2c20 {
    Unlockable *FUN_00092ad0(int id);
    char FUN_00092860(int id);
    int FUN_000932a0(int idx);
    void FUN_000929a0(int id, int z);
};

struct Gate_c2c20 {
    char FUN_000893c0();
};

struct Shader {
    void FUN_000b4280(void *global, Tex *tex);
};
extern int DAT_00584554;
Shader *__cdecl FUN_000c0db0(void *a, const char *name);
Tex *__cdecl FUN_000c1ed0(void *a, const char *name);

struct Holder54_c2c20 {
    struct Pts *FUN_00086370();
};
struct Pts {
    int FUN_00090110();
};
struct World {
    char pad0[0x54];
    Holder54_c2c20 *p54;
};

class MovesMenu {
public:
    char pad0[0x34];
    Gate_c2c20 *p34;
    char pad38[0x4c - 0x38];
    Unlockables_c2c20 *p4c;
    void FUN_000c21b0(int id);
    void FUN_000ba040();
    void FUN_000b8c50(const char *a, const char *b);
    void F();
};

void MovesMenu::F()
{
    char flagD, f0e, flagF;
    Name_c2c20 C;
    Name_c2c20 B;
    Name_c2c20 A;
    Name_c2c20 E;
    Name_c2c20 *nameDesc;
    const char *image;
    __declspec(align(8)) char buf[0x100];

    if (!p4c) {
        return;
    }
    Unlockable *unl = (Unlockable *)FUN_00344e74(p4c->FUN_00092ad0(0x266), 0, DAT_0049dab8, DAT_0049db1c, 0);
    if (!unl) {
        return;
    }
    const char *name = unl->FUN_00092040();
    if (!name) {
        return;
    }
    Widget_c2c20 *sel = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260(name), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (!sel || !sel->p1d58 || sel->sel == -1) {
        return;
    }
    int idx = sel->sel;
    f0e = 0;
    if (p34->FUN_000893c0()) {
        if (idx == 0)
            f0e = 1;
        idx--;
    }
    if (!FUN_00344e74(FUN_000fc260(name), 0, DAT_0049dba4, DAT_0049dbbc, 0)) {
        return;
    }
    A.FUN_0027af00();
    B.FUN_0027b0e0("TBS_UNLOCKABLE_MOVE_DESCRIPTION_SAVAGE");
    C.FUN_0027af00();
    Name_c2c20 *combo;
    int id;
    if (f0e) {
        id = 4;
        combo = &A;
        nameDesc = &B;
        image = "savage_banner";
        flagD = p4c->FUN_00092860(id) == 0;
        flagF = 0;
        C.FUN_0027af70(E.FUN_0027b0e0("TBS_CHEAT_SAVAGE_BANNER"));
        E.FUN_0027af50();
    } else {
        id = p4c->FUN_000932a0(idx);
        Unlockable *u2 = (Unlockable *)FUN_00344e74(p4c->FUN_00092ad0(id), 0, DAT_0049dab8, DAT_0049db1c, 0);
        if (!u2) {
            C.FUN_0027af50();
            B.FUN_0027af50();
            A.FUN_0027af50();
            return;
        }
        combo = u2->FUN_00092050();
        nameDesc = u2->FUN_00092070();
        image = u2->FUN_00092090();
        flagD = u2->FUN_00091f40();
        flagF = u2->FUN_00091fb0();
        C.FUN_0027af70(&u2->id);
    }
    p4c->FUN_000929a0(id, 0);
    FUN_000c21b0(id);
    FUN_000ba040();
    FUN_000fc280("MovesDescription");
    if (C.lo | C.hi) {
        Widget_c2c20 *t = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_name"), 0, DAT_0049dba4, DAT_0049f48c, 0);
        if (t) {
            Label_c2c20 *lbl = &t->label;
            int r = FUN_000fc1b0()->FUN_000f7240(C.lo, C.hi);
            if (r == -1)
                lbl->FUN_000f8500(C.FUN_0027b010(), FUN_000fc1b0(), 1);
            else
                lbl->FUN_000f7a10(r, 0);
        }
    }
    if (combo) {
        Widget_c2c20 *t = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_button_combo"), 0, DAT_0049dba4, DAT_0049f48c, 0);
        if (t) {
            Label_c2c20 *lbl = &t->label;
            if (f0e) {
                lbl->FUN_000f8500("", 0, 1);
            } else {
                int r = FUN_000fc1b0()->FUN_000f7240(combo->lo, combo->hi);
                if (r == -1)
                    lbl->FUN_000f8500(combo->FUN_0027b010(), FUN_000fc1b0(), 1);
                else
                    lbl->FUN_000f7a10(r, 0);
            }
        }
    }
    Name_c2c20 *desc = nameDesc;
    if (desc) {
        Widget_c2c20 *t = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_description"), 0, DAT_0049dba4, DAT_0049f470, 0);
        if (t) {
            Label_c2c20 *lbl = &t->label;
            int r = FUN_000fc1b0()->FUN_000f7240(desc->lo, desc->hi);
            if (r == -1)
                lbl->FUN_000f8500(desc->FUN_0027b010(), FUN_000fc1b0(), 1);
            else
                lbl->FUN_000f7a10(r, 0);
            t->vfunc_3();
        }
    }
    const char *img = image;
    if (img) {
        Shader *sh = FUN_000c0db0((*(void**)&DAT_004dd9cc), "moves_gallery_image_shader");
        if (sh) {
            FUN_000964a0(buf, 0x100, "%s.png", img);
            Tex *tex = FUN_000c1ed0((*(void**)&DAT_004dd9cc), buf);
            if (tex)
                sh->FUN_000b4280(&DAT_00584554, tex);
        }
    }
    Widget_c2c20 *btn = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("purchase_move"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    char bl = flagF;
    if (btn) {
        if (!bl && flagD) {
            btn->b141 = bl;
            btn->b74 = bl;
        } else {
            btn->b141 = 1;
            btn->b74 = 1;
        }
        Label_c2c20 *lbl = &btn->label;
        if (bl && flagD)
            FUN_000fc020(buf, 0x40, FUN_000fc1b0()->FUN_00088ea0("TBS_MENU_ITEM_TUTORIAL"));
        else
            FUN_000fc020(buf, 0x40, FUN_000fc1b0()->FUN_00088ea0("TBS_MENU_ITEM_PURCHASE_MOVE"));
        lbl->FUN_000f79a0(buf, 0);
        btn->vfunc_3();
    }
    Widget_c2c20 *pts = (Widget_c2c20 *)FUN_00344e74(FUN_000fc260("enabled_moves_smash_points"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (pts) {
        int p = DAT_004dd700->p54->FUN_00086370()->FUN_00090110();
        FUN_000fc020(buf, 0x40, FUN_000fc1b0()->FUN_00088ea0("TBS_SMASH_POINTS_TOTAL"), p);
        pts->label.FUN_000f79a0(buf, 0);
    }
    if (FUN_00344e74(FUN_000fc260("moves_list_smash_points"), 0, DAT_0049dba4, DAT_0049f48c, 0)) {
        int p = DAT_004dd700->p54->FUN_00086370()->FUN_00090110();
        FUN_000fc020(buf, 0x40, FUN_000fc1b0()->FUN_00088ea0("TBS_SMASH_POINTS_TOTAL"), p);
        pts->label.FUN_000f79a0(buf, 0);
    }
    if (!bl && flagD)
        FUN_000b8c50("MovesDescription", "return_to_move_list");
    C.FUN_0027af50();
    B.FUN_0027af50();
    A.FUN_0027af50();
}
