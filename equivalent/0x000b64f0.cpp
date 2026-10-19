// STATUS: equivalent (tools/equiv.py level 3: 903 inputs, branch coverage 104/104)
// FUN_000b64f0 @ 0x000b64f0
// cl-flags: /GS
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
#include "decls/address.h"
extern "C" int strcmp(const char *, const char *);

struct String {
    char b[12];
    void FUN_000f7930() throw();
    void FUN_000f8500(const char *s, int a, int b) throw();
    void FUN_000f79a0(const char *s, int a) throw();
    void FUN_000f7960() throw();
};

class FEObject {
public:
    virtual void v0();
};

class TextSelector : public FEObject {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Finish();
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
    virtual void AddHeader(String *s, int a, int b);
    virtual void AddItem(int index, String *s);
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void SetValue(int index, int value);
    void FUN_000e36c0();
};

class CUnlockablesManager {
public:
    bool FUN_00092dc0(int id);
    bool FUN_00092de0(int id);
};

struct Language {
    const char *FUN_000f7d30(const char *key);
    const char *FUN_000f7220(const char *text);
};

struct Costume {
    const char *FUN_00203860();
};

struct Player {
    Costume *FUN_000862a0();
};

struct World {
    char pad0[0x54];
    Player *f54;
};


FEObject *__cdecl FUN_000fc260(const char *name);
Language *__cdecl FUN_000fc1b0();
void __cdecl FUN_000fc020(char *buf, int size, const char *fmt, int value);

struct Frame {
    String s;
    char pad156[24];
    char buf[0x40];
    char pad68[0x40];
};

class CheatMenu {
public:
    char pad0[0x4c];
    CUnlockablesManager *um;
    void FUN_000b64f0();
};

#define CHAR_BLOCK(id, text, name, len) \
    if (!um->FUN_00092dc0(id)) { \
        f.s.FUN_000f8500(text, 0, 1); \
        menu->AddItem(0, &f.s); \
        if (strcmp(name, cur) == 0) \
            menu->SetValue(0, charItem); \
        charItem++; \
    }

#define TOGGLE_BLOCK(id, text) \
    if (!um->FUN_00092dc0(id)) { \
        f.s.FUN_000f8500(text, 0, 1); \
        menu->AddHeader(&f.s, 0, 0); \
        f.s.FUN_000f8500("TBS_MENU_ITEM_CHOICE_ON", 0, 1); \
        menu->AddItem(item, &f.s); \
        f.s.FUN_000f8500("TBS_MENU_ITEM_CHOICE_OFF", 0, 1); \
        menu->AddItem(item, &f.s); \
        menu->SetValue(item, !um->FUN_00092de0(id)); \
        item++; \
    }

#define NUMBER_BLOCK(id, amount, last) \
    if (!um->FUN_00092dc0(id)) { \
        Language *lang = FUN_000fc1b0(); \
        FUN_000fc020(f.buf, 0x40, lang->FUN_000f7220(lang->FUN_000f7d30("TBS_DEMO_END_SMASH")), amount); \
        f.s.FUN_000f79a0(f.buf, 0); \
        menu->AddHeader(&f.s, 0, 0); \
        f.s.FUN_000f8500("TBS_MISSION_OBJECTIVE_STATUS_COMPLETE", 0, 1); \
        menu->AddItem(item, &f.s); \
        menu->SetValue(item, 0); \
        if (!last) \
            item++; \
    }

void CheatMenu::FUN_000b64f0()
{
    Frame f;
    TextSelector *menu = dynamic_cast<TextSelector *>(FUN_000fc260("unlocked_cheats"));
    if (menu) {
        int i = 0;
        int item = 0;
        f.s.FUN_000f7930();
        menu->FUN_000e36c0();
        int count = 0;
        for (i = 0; i <= 0xc; i++) {
            if (!um->FUN_00092dc0(i))
                count++;
        }
        if (count != 0) {
            const char *cur;
            int charItem;
            f.s.FUN_000f8500("TBS_CHEAT_CHARACTER", 0, 1);
            menu->AddHeader(&f.s, 0, 0);
            cur = DAT_004dd700->f54->FUN_000862a0()->FUN_00203860();
            f.s.FUN_000f8500("TBS_CHEAT_HULK", 0, 1);
            menu->AddItem(0, &f.s);
            charItem = 1;
            CHAR_BLOCK(1, "TBS_CHEAT_GREY_HULK", "grey_hulk", 10)
            CHAR_BLOCK(2, "TBS_CHEAT_JOE_FIXIT", "joefixit", 9)
            CHAR_BLOCK(5, "TBS_CHEAT_FLAG_CANADA", "hulk_canada", 12)
            CHAR_BLOCK(6, "TBS_CHEAT_FLAG_AMERICA", "hulk_us", 8)
            CHAR_BLOCK(7, "TBS_CHEAT_FLAG_ENGLAND", "hulk_uk", 8)
            CHAR_BLOCK(8, "TBS_CHEAT_FLAG_FRANCE", "hulk_france", 12)
            CHAR_BLOCK(9, "TBS_CHEAT_FLAG_GERMANY", "hulk_german", 12)
            CHAR_BLOCK(0xa, "TBS_CHEAT_FLAG_ITALY", "hulk_italy", 11)
            CHAR_BLOCK(0xb, "TBS_CHEAT_FLAG_SPAIN", "hulk_spain", 11)
            CHAR_BLOCK(0xc, "TBS_CHEAT_FLAG_JAPAN", "hulk_japan", 11)
            CHAR_BLOCK(0, "TBS_CHEAT_FLAG_AUSTRALIA", "hulk_australia", 15)
            CHAR_BLOCK(4, "TBS_CHEAT_SAVAGE_BANNER", "banner_savage", 14)
            CHAR_BLOCK(3, "TBS_CHEAT_ABOMINATION", "abomination_ashulk", 19)
            item = 1;
        }
        if (!(um->FUN_00092dc0(0xe) && um->FUN_00092dc0(0xd))) {
            int on;
            f.s.FUN_000f8500("TBS_CHEAT_RENDER_MODE", 0, 1);
            menu->AddHeader(&f.s, 0, 0);
            f.s.FUN_000f8500("TBS_CHEAT_RENDER_MODE_NORMAL", 0, 1);
            menu->AddItem(item, &f.s);
            on = 1;
            if (!um->FUN_00092dc0(0xe)) {
                f.s.FUN_000f8500("TBS_CHEAT_SEPIA", 0, on);
                menu->AddItem(item, &f.s);
                if (um->FUN_00092de0(0xe))
                    menu->SetValue(item, on);
                on = 2;
            }
            if (!um->FUN_00092dc0(0xd)) {
                f.s.FUN_000f8500("TBS_CHEAT_BLACK_AND_WHITE", 0, 1);
                menu->AddItem(item, &f.s);
                if (um->FUN_00092de0(0xd))
                    menu->SetValue(item, on);
            }
            item++;
        }
        TOGGLE_BLOCK(0x2e4, "TBS_CHEAT_INVULNERABILITY")
        TOGGLE_BLOCK(0x1d, "TBS_CHEAT_UNLOCK_ALL_MOVES")
        TOGGLE_BLOCK(0x14, "TBS_CHEAT_DOUBLE_DAMAGE")
        TOGGLE_BLOCK(0x15, "TBS_CHEAT_DOUBLE_HEALTH_COLLECTABLE")
        TOGGLE_BLOCK(0x16, "TBS_CHEAT_CABS")
        TOGGLE_BLOCK(0x1a, "TBS_CHEAT_GIANT_BLUE_GORILLA")
        TOGGLE_BLOCK(0x13, "TBS_CHEAT_LOW_GRAVITY")
        TOGGLE_BLOCK(0x25, "TBS_CHEAT_ROAD_RAGE")
        TOGGLE_BLOCK(0x26, "TBS_CHEAT_MASS_TRANSIT")
        TOGGLE_BLOCK(0x2f, "TBS_CHEAT_COW_MISSILES")
        TOGGLE_BLOCK(0x27, "TBS_CHEAT_COLOUR_CONCEPT_1")
        TOGGLE_BLOCK(0x28, "TBS_CHEAT_COLOUR_CONCEPT_2")
        TOGGLE_BLOCK(0x29, "TBS_CHEAT_COLOUR_CONCEPT_3")
        NUMBER_BLOCK(0x2c, 0x1388, 0)
        NUMBER_BLOCK(0x2d, 0x2710, 0)
        NUMBER_BLOCK(0x2e, 0x3a98, 1)
        menu->Finish();
        f.s.FUN_000f7960();
    }
}
