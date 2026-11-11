// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b4cf0..0x000bba40 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f61f5a00 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f61f5a00 {} using namespace fn_f61f5a00;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f61f5a00 {
extern const char *__cdecl FUN_000f7120(int);
extern int __cdecl FUN_000964a0(char *, int, const char *, ...);
struct Resource_b51c0 {
 virtual void slot0(); virtual void release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
 virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
 virtual void slot22(); virtual unsigned char ready();
};
extern void __cdecl thunk_FUN_00271230(Resource_b51c0 **, const char *, int, int, int, int, int, int);
struct Locale {
};
struct TextEntry_b5250 {
};
Locale *__cdecl FUN_000fc1b0();
void __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);
extern "C" void __cdecl FUN_000fc000(char *buf, int size, const char *fmt, ...);


// 0x000b51c0 FUN_000b51c0 (140 B): equivalent/0x000b51c0.cpp
// sym: _FUN_000b51c0 @1b8bec9da421 @w5212cc2e233b
// STATUS: equivalent (tools/equiv.py level 3: 16411 inputs, branch coverage 8/8)
// FUN_000b51c0 @ 0x000b51c0
// FUN_000b51c0 @ 0x000b51c0
extern "C" bool __cdecl FUN_000b51c0(int language) {
 int index=0;
 for (; index<6; ++index) { if (index==language) break; }
 if(index==6) index=0;
 char filename[64];
 FUN_000964a0(filename,64,(*(const char**)&DAT_0049f3b8),FUN_000f7120(index));
 Resource_b51c0 *resource;
 thunk_FUN_00271230(&resource,filename,0,0,1,0,1,1);
 bool result=resource->ready()!=0;
 resource->release();
 return result;
}


// 0x000b5250 FUN_000b5250 (544 B): equivalent/0x000b5250.cpp
// sym: ?FUN_000b5250@fn_f61f5a00@@YGXPAUTextEntry_b5250@1@PBD111111@Z @b0f71453a6a3 @wc3beff6ed1fa
// STATUS: equivalent (tools/equiv.py level 3: 7848 inputs, branch coverage 14/14)
// FUN_000b5250 @ 0x000b5250
void __stdcall FUN_000b5250(TextEntry_b5250 *entry, const char *key, const char *k2, const char *k3,
                            const char *k4, const char *k5, const char *k6, const char *k7)
{
    char buf[0x100];
    Locale *L;
    int id;
    const char *a2;
    const char *a3;
    const char *a4;
    const char *a5;
    const char *a6;
    const char *a7;

    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)key));
    const char *text = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    a2 = k2;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k2));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k2));
        a2 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a3 = k3;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k3));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k3));
        a3 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a4 = k4;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k4));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k4));
        a4 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a5 = k5;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k5));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k5));
        a5 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a6 = k6;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k6));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k6));
        a6 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a7 = k7;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k7));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k7));
        a7 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }

    if (text != 0)
        FUN_000fc020(buf, 0x100, text, a2, a3, a4, a5, a6, a7);
    else
        FUN_000fc000(buf, 0x100, key, a2, a3, a4, a5, a6, a7);
    ((owners::Obj_f79a0 *)entry)->FUN_000f79a0((const short *)buf, (hulk_intptr)0);
}

} // namespace fn_f61f5a00

// 0x000b5670 FUN_000b5670 (146 B): equivalent/0x000b5670.cpp [wrapped: conflict: FUN_000fc020; FUN_000fc1b0; FUN_000fc260]
// sym: _FUN_000b5670@4 @f3e2a63f5acc @wb29615edabf4
namespace fn_000b5670 {
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 3/3)
// FUN_000b5670 @ 0x000b5670
// cl-flags: /GS

struct Label_b5670 {
    void FUN_000f79a0(const char *text, int flag);
};

struct Texts_b5670 {
    int FUN_000f7d30(const char *id);
    const char *FUN_000f7220(int index);
};

class Panel_b5670 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x18 - 4];
    Label_b5670 label;
};

extern Panel_b5670 *__cdecl FUN_000fc260(const char *name);
extern Texts_b5670 *__cdecl FUN_000fc1b0();
extern int __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);

extern "C" void __stdcall FUN_000b5670(hulk_intptr amount)
{
    struct Frame {
        char pad[4];
        char text[0xfc];
    } f;

    Panel_b5670 *panel = FUN_000fc260("side_mission_success_smash_award");
    if (panel != 0) {
        Texts_b5670 *texts = FUN_000fc1b0();
        FUN_000fc020(f.text, 0x80, texts->FUN_000f7220(texts->FUN_000f7d30("TBS_SMASH_POINT_AWARD")), amount);
        panel->label.FUN_000f79a0(f.text, 0);
        panel->vfunc_3();
    }
}
} // namespace fn_000b5670


// 0x000b63a0 FUN_000b63a0 (336 B): equivalent/0x000b63a0.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260]
// sym: ?FUN_000b63a0@Owner_b63a0@fn_000b63a0@@QAEXXZ @fc40e0077248 @wd4fd4eb26f22
namespace fn_000b63a0 {
// STATUS: equivalent (tools/equiv.py level 3: 1567 inputs, branch coverage 10/10)
// FUN_000b63a0 @ 0x000b63a0
// cl-flags: /GS
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];

class FEObject_b63a0 {
public:
    virtual void vfunc_0();
};

class TextSelector_b63a0 : public FEObject_b63a0 {
public:
    virtual void vfunc_1();
};

class Manager_b63a0 {
public:
    int FUN_000f7240(int a, int b);
};

struct Label_b63a0 {
    char data[0x24];
    void FUN_000f8500(const char *name, Manager_b63a0 *manager, char flag);
};

struct Name_b63a0 {
    const char *FUN_0027b010();
};

struct Row_b63a0 {
    char pad0[8];
    int keyA;
    int keyB;
    char pad10[0x38 - 0x10];
    int value;
};

struct Table_b63a0 {
    char pad0[0xc80];
    int count;
    Row_b63a0 *FUN_00090250(int index);
};

struct RowName {
    char pad0[8];
    Name_b63a0 name;
};

class Owner_b63a0 {
public:
    char pad0[0x50];
    Table_b63a0 *table;
    void FUN_000b63a0();
};

class Selector_b63a0 : public TextSelector_b63a0 {
public:
    virtual void vfunc_2(); virtual void vfunc_3();
};

FEObject_b63a0 *__cdecl FUN_000fc260(const char *name);
Manager_b63a0 *__cdecl FUN_000fc1b0();
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
int __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);

class SelectorView_b63a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(Label_b63a0 *text, int a, int b);
    virtual void v20(int index, Label_b63a0 *text);
    void FUN_000e36c0();
};

void Owner_b63a0::FUN_000b63a0()
{
    if (table) {
        SelectorView_b63a0 *sel = (SelectorView_b63a0 *)FUN_00344e74(FUN_000fc260("stats_table"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (sel) {
            Label_b63a0 label;
            char number[16];
            ((owners::State_f7930 *)&label)->FUN_000f7930();
            sel->FUN_000e36c0();
            for (int i = 1; i < table->count; i++) {
                int value = table->FUN_00090250(i)->value;
                Row_b63a0 *row = table->FUN_00090250(i);
                int ka = row->keyA;
                int kb = row->keyB;
                int idx = FUN_000fc1b0()->FUN_000f7240(ka, kb);
                if (idx != -1) {
                    ((owners::Obj_f7a10 *)&label)->FUN_000f7a10((hulk_intptr)idx, 0);
                } else {
                    Manager_b63a0 *m = FUN_000fc1b0();
                    RowName *rn = (RowName *)table->FUN_00090250(i);
                    label.FUN_000f8500(rn->name.FUN_0027b010(), m, 1);
                }
                sel->v19(&label, 0, 0);
                FUN_000964a0(number, 0x10, "%d", value);
                label.FUN_000f8500(number, FUN_000fc1b0(), 0);
                sel->v20(i - 1, &label);
            }
            sel->v3();
            ((owners::Thing_f7960 *)&label)->FUN_000f7960();
        }
    }
}
} // namespace fn_000b63a0


// 0x000b64f0 FUN_000b64f0 (3765 B): matches/0x000b64f0.cpp [wrapped: macros]
// sym: ?FUN_000b64f0@CheatMenu@fn_000b64f0@@QAEXXZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000b64f0 {
// STATUS: equivalent (tools/equiv.py level 3: 1707 inputs, branch coverage 104/104, incomplete)
// FUN_000b64f0 @ 0x000b64f0
// cl-flags: /GS
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char *, const char *);
#endif


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
void __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);

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
} // namespace fn_000b64f0
#undef CHAR_BLOCK
#undef NUMBER_BLOCK
#undef TOGGLE_BLOCK
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000b79a0 FUN_000b79a0 (813 B): equivalent/0x000b79a0.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260]
// sym: ?FUN_000b79a0@Briefing@fn_000b79a0@@QAEXTSlot_b79a0@2@0@Z @f8e2edf690c5 @w2b79d960d7d2
namespace fn_000b79a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3066 inputs, branch coverage 35/36, incomplete)
// FUN_000b79a0 @ 0x000b79a0
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern "C" int __cdecl _sprintf(char*, const char*, ...);
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f470[];

struct Manager_b79a0 {
    int FUN_000f7240(int a, int b);
};

struct Label_b79a0 {
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
    Panel_b79a0* menu = (Panel_b79a0*)FUN_00344e74(FUN_000fc260(a1.name), 0, DAT_0049dba4, DAT_0049f470, 0);
    if (menu == 0) {
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
        unsigned __int64 key = ((unsigned __int64)((owners::Obj_f72c0 *)(ui->v44()))->FUN_000f72c0((int)itemId));
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
        ((owners::ThisWrap_0008baf0 *)counter)->FUN_0008baf0(&a, &a2.value);
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
        ((owners::Obj_f7a10 *)&(menu->label))->FUN_000f7a10((hulk_intptr)id, 0);
    } else {
        NameSource_b79a0* ns = (NameSource_b79a0*)((char*)this + a1.index * 0x28 + 0x480);
        menu->label.FUN_000f8500(ns->FUN_0027b010(), FUN_000fc1b0(), 1);
    }
    menu->v3();
}
} // namespace fn_000b79a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000b7cd0 FUN_000b7cd0 (800 B): equivalent/0x000b7cd0.cpp [wrapped: conflict: FEControl; FEObject; FUN_000964a0; FUN_000fc3d0 (+1)]
// sym: ?FUN_000b7cd0@HintMenu_b7cd0@fn_000b7cd0@@QAEXXZ @0e4de9b54608 @w58cf47f0bad0
namespace fn_000b7cd0 {
// STATUS: equivalent (tools/equiv.py level 3: 282 inputs, branch coverage 75/76, incomplete)
// FUN_000b7cd0 @ 0x000b7cd0
// cl-flags: /GS

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char* a, const char* b);
#endif


struct Text_b7cd0 {
    char pad[0x24];
    void FUN_000f7930();
    void FUN_000f79a0(const unsigned short* s, int n);
    void FUN_000f7960();
};

struct Ui_b7cd0 {
    int FUN_000f7d30(const char* name);
    const unsigned short* FUN_000f7220(int index);
};

class UiMgr_b7cd0 {
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
    virtual Ui_b7cd0* v44();
};

class FEObject {
public:
    virtual void v0();
};

class FEControl : public FEObject {
public:
    virtual void v1();
    virtual void v2();
};

class TextSelector : public FEControl {
public:
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
    virtual void v19(Text_b7cd0* item, int a, int b);
    void FUN_000e36c0();
};

struct Unlocks_b7cd0 {
    bool FUN_00092860(int id);
};

FEObject* FUN_000fc260(const char* name);
UiMgr_b7cd0* FUN_000fc3d0();
void FUN_000964a0(char* buf, int size, const char* fmt, ...);
void FUN_000fc020(unsigned short* buf, int count, const unsigned short* fmt, ...);

struct Frame_b7cd0 {
    int count;
    TextSelector* menu;
    const char** np;
    const char* cur;
    int* out;
    void* self;
    Ui_b7cd0* ui;
    const char* names[6];
    Text_b7cd0 text;
    char header[0x40];
    unsigned short label[0x80];
};

class HintMenu_b7cd0 {
public:
    char pad00[0x4c];
    Unlocks_b7cd0* unlocks;
    char pad50[0x1a0c - 0x50];
    int ids[64];
    void FUN_000b7cd0();
};

void HintMenu_b7cd0::FUN_000b7cd0()
{
    Frame_b7cd0 f;
    f.self = this;
    f.menu = dynamic_cast<TextSelector*>(FUN_000fc260("hint_selector"));
    if (f.menu != 0) {
        f.menu->FUN_000e36c0();
        f.names[0] = "SMASH";
        f.names[1] = "COMBAT";
        f.names[2] = "ADVANCED_COMBAT";
        f.names[3] = "TARGET";
        f.names[4] = "MOVEMENT";
        f.names[5] = 0;
        f.ui = FUN_000fc3d0()->v44();
        f.count = 0;
        f.np = f.names;
        f.cur = f.names[0];
        do {
            f.out = &ids[f.count];
            int n = 0;
            int id = 0x8e;
            do {
                if (!unlocks->FUN_00092860(id)) {
                    const char* cat = 0;
                    if (id >= 0x8f && id <= 0x94)
                        cat = "SMASH";
                    if (id >= 0x95 && id <= 0x98)
                        cat = "SMASH";
                    if (id >= 0x99 && id <= 0x9b)
                        cat = "ADVANCED_COMBAT";
                    if (id >= 0x9c && id <= 0xa1)
                        cat = "SMASH";
                    if (id >= 0xa2 && id <= 0xa4)
                        cat = "SMASH";
                    if (id >= 0xa5 && id <= 0xa9)
                        cat = "TARGET";
                    if (id >= 0xaa && id <= 0xae)
                        cat = "ADVANCED_COMBAT";
                    if (id >= 0xaf && id <= 0xb3)
                        cat = "MOVEMENT";
                    if (id >= 0xb4 && id <= 0xc7)
                        cat = "COMBAT";
                    if (id >= 0xc8 && id <= 0xcb)
                        cat = "MOVEMENT";
                    if (id >= 0xcc && id <= 0xcf)
                        cat = "MOVEMENT";
                    if (id >= 0xd0 && id <= 0xd0)
                        cat = "ADVANCED_COMBAT";
                    if (id >= 0xd1 && id <= 0xd8)
                        cat = "TARGET";
                    if (id >= 0xd9 && id <= 0xdd)
                        cat = "ADVANCED_COMBAT";
                    if (cat != 0 && strcmp(cat, f.cur) == 0) {
                        n++;
                        FUN_000964a0(f.header, 0x40, "TBS_HINT_HEADER_%s", cat);
                        FUN_000fc020(f.label, 0x80, f.ui->FUN_000f7220(f.ui->FUN_000f7d30(f.header)), n);
                        f.text.FUN_000f7930();
                        f.text.FUN_000f79a0(f.label, 0);
                        f.menu->v19(&f.text, 0, 0);
                        *f.out = id;
                        f.count++;
                        f.out++;
                        f.text.FUN_000f7960();
                    }
                }
                id++;
            } while (id <= 0xde);
            f.np++;
            f.cur = *f.np;
        } while (f.cur != 0);
        f.menu->v3();
    }
}
} // namespace fn_000b7cd0


// 0x000b86b0 FUN_000b86b0 (418 B): equivalent/0x000b86b0.cpp [wrapped: conflict: FUN_000fc260]
// sym: ?FUN_000b86b0@CheatMenu_b86b0@fn_000b86b0@@QAEXXZ @26f9d94393bc @wbdddd09d2189
namespace fn_000b86b0 {
// STATUS: equivalent (tools/equiv.py level 3: 370 inputs, branch coverage 22/22)
// FUN_000b86b0 @ 0x000b86b0
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
extern void *__cdecl FUN_000fc000(unsigned short *dst, int n, const char *src, ...);

struct ScriptArgs {
    int tag;
    char text[10][0x40];
    int ints[10];
    char kinds[10];
    char pad2b6[2];
    void FUN_001d1630();
};

struct Script_b86b0 {
    int FUN_001d3b00(const char *name, ScriptArgs args);
    int FUN_001d27b0(const char *name);
};

extern Script_b86b0 *__cdecl FUN_001d4c90();

struct Label_b86b0 {
    int f00;
    char f04;
    char pad05[3];
    int f08;
    int f0c;
    char *f10;
    int f14;
    char f18;
    char pad19[3];
    float f1c;
    int f20;
    void FUN_000f7930();
    void FUN_000f79a0(unsigned short *text, int flag);
    void FUN_000f7960();
};

struct Obj893 {
    char FUN_000893c0();
};

struct Obj54_b86b0 {
    Obj893 *FUN_00086310();
};

struct World {
    char pad00[0x54];
    Obj54_b86b0 *f54;
};


struct CodeTable_b86b0 {
    char FUN_00092860(int index);
    char *FUN_00093110(int index);
};

class CheatList {
public:
    virtual void vfunc_0();
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
    virtual void vfunc_19(Label_b86b0 *label, int a, int b);
    void FUN_000e36c0();
};

struct Frame_b86b0 {
    Label_b86b0 label;
    unsigned short text[0x40];
    char pad_ac[0x80];
    ScriptArgs args;
};

class CheatMenu_b86b0 {
public:
    char pad00[0x4c];
    CodeTable_b86b0 *codes;
    void FUN_000b86b0();
};

void CheatMenu_b86b0::FUN_000b86b0()
{
    Frame_b86b0 f;
    CheatList *list = (CheatList *)FUN_00344e74(FUN_000fc260("cheat_code_list"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (list) {
        list->FUN_000e36c0();
        for (int i = 0; i <= 0x31; i++) {
            if (codes->FUN_00092860(i)) {
                if (i == 3) {
                    if (!DAT_004dd700->f54->FUN_00086310()->FUN_000893c0())
                        continue;
                } else if (i == 1) {
                    if (codes->FUN_00092860(0x21))
                        continue;
                } else {
                    Script_b86b0 *script = FUN_001d4c90();
                    f.args.FUN_001d1630();
                    f.args.tag = 1;
                    FUN_00267760(f.args.text[0], 0x40, "%d", i);
                    if (script->FUN_001d3b00("kmcIsCheatComicCollected", f.args) != 3 ||
                        !script->FUN_001d27b0("__IS_CHEAT_COMIC_COLLECTED__"))
                        continue;
                }
            }
            char *name = codes->FUN_00093110(i);
            if (!name || !*name)
                continue;
            FUN_000fc000(f.text, 0x80, name);
            f.label.FUN_000f7930();
            f.label.FUN_000f79a0(f.text, 0);
            list->vfunc_19(&f.label, 0, 0);
            f.label.FUN_000f7960();
        }
        list->vfunc_3();
    }
}
} // namespace fn_000b86b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000b89e0 FUN_000b89e0 (615 B): equivalent/0x000b89e0.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260; FUN_001d4c90]
// sym: ?FUN_000b89e0@MissionFailMenu@fn_000b89e0@@QAEXXZ @bce601f476fc @wbe949d59b2ca
namespace fn_000b89e0 {
// STATUS: equivalent (tools/equiv.py level 3: 19950 inputs, branch coverage 42/42)
// FUN_000b89e0 @ 0x000b89e0
// cl-flags: /GS

// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
static inline int memcmp_inline(const void *a, const void *b, unsigned n)
{
    const unsigned char *p = (const unsigned char *)a;
    const unsigned char *q = (const unsigned char *)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}
extern char DAT_0049dba4[];
extern char DAT_0049f470[];
extern char DAT_0049f48c[];
extern char DAT_0049f4a4[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern void* __cdecl FUN_000fc260(const char* name);
extern int __cdecl FUN_000fc1b0();
extern "C" int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);

struct ScriptArgs {
    int tag;
    char text[10][0x40];
    int ints[10];
    char kinds[10];
    char pad2b6[2];
    void FUN_001d1630();
};

struct Script_b89e0 {
    int FUN_001d3b00(const char* name, ScriptArgs args);
    const char* FUN_001d27b0(const char* name);
};

extern Script_b89e0* __cdecl FUN_001d4c90();

struct Label_b89e0 {
    void FUN_000f8500(const char* text, int a, char flag);
};

class Panel_b89e0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x18 - 4];
    Label_b89e0 label;                // 0x18
};

struct TitleText {
    void FUN_000e2a60(const char* text);
};

struct ContinueButton {
    char pad0[0x141];
    char enabled;               // 0x141
    void FUN_000e2a60(const char* text);
};

struct Progress_b89e0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Mission_b89e0 {
    char pad0[0x80];
    Progress_b89e0 progress;          // 0x80
    const char* FUN_0008a2d0();
};

class MissionFailMenu {
public:
    char pad00[0x34];
    Mission_b89e0* mission;           // 0x34
    char pad38[0x1bcc - 0x38];
    char hint[0x40];            // 0x1bcc
    void FUN_000b89e0();
};

void MissionFailMenu::FUN_000b89e0()
{
    struct Frame {
        ScriptArgs args;
    } f;

    hint[0] = 0;
    const char* id = mission->FUN_0008a2d0();
    const char* state = ((const char *)((owners::Obj_8a060 *)mission)->FUN_0008a060((hulk_intptr)id));
    if (memcmp_inline(state, "complete", 9) != 0) {
        Script_b89e0* script = FUN_001d4c90();
        if (script != 0) {
            f.args.FUN_001d1630();
            f.args.tag = 0;
            script->FUN_001d3b00("GetMissionFailHint", f.args);
            const char* h = script->FUN_001d27b0("mission_fail_hints_current");
            if (h != 0)
                FUN_00267760(hint, 0x40, "%s", h);
        }
    }

    Panel_b89e0* title = (Panel_b89e0*)FUN_00344e74(FUN_000fc260("Mission_Failure"), 0, DAT_0049dba4, DAT_0049f470, 0);
    if (title != 0) {
        title->label.FUN_000f8500(hint, FUN_000fc1b0(), 1);
        title->vfunc_3();
    }

    bool defeated = false;
    int a = mission->progress.FUN_00088fa0();
    int b = mission->progress.FUN_00088fb0();
    if (a >= 1 && a <= 7) {
        if (b == 0 || memcmp_inline(state, "complete", 9) == 0)
            defeated = true;
    }

    TitleText* heading = (TitleText*)FUN_00344e74(FUN_000fc260("story_mission_fail_title"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (heading != 0)
        heading->FUN_000e2a60(defeated ? "TBS_MISSION_DEFEATED" : "TBS_MISSION_FAIL");

    ContinueButton* cont = (ContinueButton*)FUN_00344e74(FUN_000fc260("story_mission_fail_continue"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    if (cont != 0)
        cont->enabled = !defeated;

    ContinueButton* freeroam = (ContinueButton*)FUN_00344e74(FUN_000fc260("story_mission_fail_return_to_freeroam"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    if (freeroam != 0) {
        char show = 1;
        const char** entry = ((const char**)&DAT_004067a4);
        while (*entry != 0) {
            const char* p = id;
            const char* q = *entry;
            int cmp;
            for (;;) {
                unsigned char pc = *p;
                unsigned char qc = *q;
                if (pc != qc) {
                    cmp = 1;
                    break;
                }
                if (pc == 0) {
                    cmp = 0;
                    break;
                }
                p++;
                q++;
            }
            if (cmp == 0) {
                show = 0;
                break;
            }
            entry++;
        }
        freeroam->enabled = show;
        freeroam->FUN_000e2a60(defeated ? "TBS_CHPT_GEN_57" : "TBS_MENU_ITEM_RETURN_TO_FREEROAM");
    }
}
} // namespace fn_000b89e0


// 0x000b8f20 FUN_000b8f20 (364 B): equivalent/0x000b8f20.cpp [wrapped: conflict: FEObject; FUN_000fc1b0; TextLabel; TextSelector]
// sym: ?FUN_000b8f20@TextHost@fn_000b8f20@@QAEXXZ @18fffc06c0cc @wda554c50c6da
namespace fn_000b8f20 {
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 16/16)
// FUN_000b8f20 @ 0x000b8f20
// cl-flags: /GS

class Manager_b8f20 { public: char pad[4]; };
Manager_b8f20 *__cdecl FUN_000fc1b0();

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
int FUN_00345804(const char *str, const char *fmt, ...);

struct TextEntry_b8f20 {
    void FUN_000f8500(const char *name, Manager_b8f20 *manager, char flag);
};

class FEObject {
public:
    virtual void vfunc_0();
};

FEObject *__cdecl FUN_000fc260(const char *name);

class TextSelector : public FEObject {
public:
    virtual void vfunc_1();
    char pad04[0x154 - 4];
    int selected;
    char pad158[0x1d58 - 0x158];
    void *field1d58;
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_1();
    char pad04[0x14];
    TextEntry_b8f20 entry;
    void FUN_000e2a60(void *p);
};

class TextHost : public FEObject {
public:
    char pad04[0x6c - 4];
    void *locations[0x80];
    const char *names[0x80];
    void FUN_000b8f20();
};

void TextHost::FUN_000b8f20()
{
    char name[0x80];
    TextSelector *sel = dynamic_cast<TextSelector *>(FUN_000fc260("mission_selector"));
    if (sel != 0 && sel->field1d58 != 0) {
        int idx = sel->selected;
        if (idx >= 0 && idx < 0x80 && names[idx] != 0) {
            FUN_000964a0(name, 0x80, "%s", names[idx]);
            if (locations[idx] != 0) {
                // the original casts "location_label" to TextLabel too (RTTI 0x0049f48c)
                TextLabel *loc = dynamic_cast<TextLabel *>(FUN_000fc260("location_label"));
                if (loc != 0)
                    loc->FUN_000e2a60(locations[idx]);
                TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260("description_label"));
                if (label != 0) {
                    int a = 0;
                    int b = 0;
                    char key[0x40];
                    FUN_00345804(name, "c%dm%d", &a, &b);
                    FUN_000964a0(key, 0x40, "TBS_MISSION_DESCRIPTION_C%02dM%02d", a, b);
                    label->entry.FUN_000f8500(key, FUN_000fc1b0(), 1);
                }
            }
        }
    }
}
} // namespace fn_000b8f20


// 0x000b9930 FUN_000b9930 (128 B): equivalent/0x000b9930.cpp [wrapped: conflict: FUN_000fc1b0; FUN_000fc260; _sprintf]
// sym: ?FUN_000b9930@Hud_b9930@fn_000b9930@@QAEXXZ @7530c00db498 @w7bb10212b465
namespace fn_000b9930 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000b9930 @ 0x000b9930
// cl-flags: /GS
// 0x000b9930: show the experience points value in its HUD label
extern int __cdecl _sprintf(char*, const char*, ...);
extern char DAT_0049dba4[];
extern char DAT_0049f48c[];
void* __cdecl FUN_000fc260(const char* name);
void* __cdecl FUN_00344e74(void* a, int b, const char* c, const char* d, int e);
int __stdcall FUN_000fc1b0();

struct Stats_b9930 {
    int FUN_00090110();
};

struct Text_b9930 {
    void FUN_000f8500(const char* text, int style, int extra);
};

struct Label_b9930 {
    char pad[0x18];
    Text_b9930 text;
};

class Hud_b9930 {
public:
    char pad[0x50];
    Stats_b9930* stats;
    void FUN_000b9930();
};

void Hud_b9930::FUN_000b9930()
{
    char buf[60];
    if (stats != 0) {
        Label_b9930* label = (Label_b9930*)FUN_00344e74(FUN_000fc260("experience_points_label"), 0, DAT_0049dba4, DAT_0049f48c, 0);
        if (label != 0) {
            _sprintf(buf, "%d", stats->FUN_00090110());
            label->text.FUN_000f8500(buf, FUN_000fc1b0(), 0);
        }
    }
}
} // namespace fn_000b9930


// 0x000b9bf0 FUN_000b9bf0 (1090 B): equivalent/0x000b9bf0.cpp [wrapped: macros]
// sym: ?FUN_000b9bf0@SideMissionMenu@fn_000b9bf0@@QAEXXZ @2d485c14e695 @we039c97b18d5
namespace fn_000b9bf0 {
// STATUS: equivalent (tools/equiv.py level 3: 609 inputs, branch coverage 40/40)
// FUN_000b9bf0 @ 0x000b9bf0
// cl-flags: /GS
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern char DAT_0049dba4[];          // FEObject type descriptor
extern char DAT_0049dbbc[];          // TextSelector type descriptor
extern char DAT_0049f4a4[];          // TextButton type descriptor
extern char DAT_0049f4f0[];          // FEControl type descriptor
   // zero-terminated list of "cNmM" side mission names

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl memcmp(const void *, const void *, unsigned int);
#endif

#pragma intrinsic(memcmp)
#if defined(__clang__)
static inline int hulk_memcmp(const void *pa, const void *pb, unsigned int n) { const unsigned char *a = (const unsigned char *)pa, *b = (const unsigned char *)pb; for (; n; --n, ++a, ++b) if (*a != *b) return *a < *b ? -1 : 1; return 0; }
#define memcmp hulk_memcmp
#endif

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strcmp(const char *, const char *);
#endif

#pragma intrinsic(strcmp)
#if defined(__clang__)
#define strcmp(s, e) (*(s) != 0)
#endif

class FEObject_b9bf0 {
public:
    virtual void vfunc_0();
};

class FEControl_b9bf0 : public FEObject_b9bf0 {
public:
    char pad04[0x141 - 4];
    char flag141;
};

class TextButton_b9bf0 : public FEControl_b9bf0 {
};

class Manager_b9bf0 {
public:
    int FUN_000f7240(int a, int b);
};

struct Label_b9bf0 {
    char data[0x24];
    void FUN_000f8500(const char *name, Manager_b9bf0 *manager, char flag);
};

struct Args_b9bf0 {
    int count;
    char text[0x40];
    char rest[0x2b8 - 0x44];
    void FUN_001d1630();
};

struct Registry_b9bf0 {
    int FUN_001d3b00(const char *name, Args_b9bf0 args);
    const char *FUN_001d27b0(const char *name);
};

class SelectorView_b9bf0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(Label_b9bf0 *text, int a, int b);
    virtual void v20(int index, Label_b9bf0 *text);
    void FUN_000e36c0();
};

struct Progress_b9bf0 {
};

FEObject_b9bf0 *__cdecl FUN_000fc260(const char *name);
Manager_b9bf0 *__cdecl FUN_000fc1b0();
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
int __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);
extern "C" int __cdecl FUN_00267760(char *dst, int size, const char *fmt, ...);
int __cdecl FUN_00345804(const char *s, const char *fmt, int *a, int *b);
Registry_b9bf0 *__cdecl FUN_001d4c90();

class SideMissionMenu {
public:
    char pad00[0x34];
    Progress_b9bf0 *progress;              // 0x34
    void FUN_000b9bf0();
};

void SideMissionMenu::FUN_000b9bf0()
{
    struct Frame {
        int count;                   // 0x00
        SelectorView_b9bf0 *sel;           // 0x04
        const char **entry;          // 0x08
        int a;                       // 0x0c
        int b;                       // 0x10
        SideMissionMenu *self;       // 0x14
        Label_b9bf0 label;                 // 0x18
        Label_b9bf0 medal;                 // 0x3c
        union {
            char name[0x20];
            Label_b9bf0 story;
        } u;                         // 0x60
        char pad80[4];
        Args_b9bf0 args;                   // 0x84
    } f;
    f.self = this;

    char done = 0;
    if (progress != 0) {
        const char *state = ((const char *)((owners::Obj_8a060 *)progress)->FUN_0008a060((hulk_intptr)"c00m01"));
        if (state != 0 && memcmp(state, "complete", 9) == 0)
            done = 1;
        else if (((char)((owners::Target_893c0 *)progress)->FUN_000893c0()) != 0)
            done = 1;
        else
            done = 0;
    }
    FEControl_b9bf0 *cont = (FEControl_b9bf0 *)FUN_00344e74(FUN_000fc260("story_mode_continue_game"), 0, DAT_0049dba4, DAT_0049f4f0, 0);
    if (cont != 0)
        cont->flag141 = done;
    FEControl_b9bf0 *save = (FEControl_b9bf0 *)FUN_00344e74(FUN_000fc260("options_save"), 0, DAT_0049dba4, DAT_0049f4f0, 0);
    if (save != 0)
        save->flag141 = done;

    if (progress != 0) {
        ((owners::State_f7930 *)&(f.label))->FUN_000f7930();
        f.sel = (SelectorView_b9bf0 *)FUN_00344e74(FUN_000fc260("side_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (f.sel != 0) {
            f.sel->FUN_000e36c0();
            f.count = 0;
            if (((const char**)&DAT_00406140)[0] != 0) {
                f.entry = ((const char**)&DAT_00406140);
                do {
                    f.a = -1;
                    f.b = -1;
                    FUN_00345804(*f.entry, "c%dm%d", &f.a, &f.b);
                    FUN_000964a0(f.u.name, 0x20, "%s_score", *f.entry);
                    const char *score = ((const char *)((owners::Obj_8a060 *)progress)->FUN_0008a060((hulk_intptr)(f.u.name)));
                    if (strcmp(score, "") != 0) {
                        FUN_000964a0(f.u.name, 0x20, "TBS_C%dM%d_NAME", f.a, f.b);
                        unsigned __int64 key = FUN_0027b020(f.u.name);
                        int idx = FUN_000fc1b0()->FUN_000f7240((int)key, (int)(key >> 32));
                        if (idx != -1)
                            ((owners::Obj_f7a10 *)&(f.label))->FUN_000f7a10((hulk_intptr)idx, 0);
                        else
                            f.label.FUN_000f8500(f.u.name, FUN_000fc1b0(), 0);
                        f.sel->v19(&f.label, 0, 0);
                        Registry_b9bf0 *reg = FUN_001d4c90();
                        f.args.FUN_001d1630();
                        f.args.count = 1;
                        FUN_00267760(f.args.text, 0x40, "%s", *f.entry);
                        if (reg->FUN_001d3b00("kmcGetSideMissionAward", f.args) == 3) {
                            const char *medal = reg->FUN_001d27b0("__SIDEMISSION_MEDAL__");
                            if (medal != 0) {
                                ((owners::State_f7930 *)&(f.medal))->FUN_000f7930();
                                f.medal.FUN_000f8500(medal, 0, 1);
                                f.sel->v20(f.count, &f.medal);
                                ((owners::Thing_f7960 *)&(f.medal))->FUN_000f7960();
                            }
                        }
                        f.count++;
                    }
                    f.entry++;
                } while (*f.entry != 0);
            }
            f.sel->v3();
            TextButton_b9bf0 *btn = (TextButton_b9bf0 *)FUN_00344e74(FUN_000fc260("menu_item_side_missions"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
            if (btn != 0)
                btn->flag141 = f.count != 0;
        }
        ((owners::Thing_f7960 *)&(f.label))->FUN_000f7960();
    } else {
        ((owners::State_f7930 *)&(f.u.story))->FUN_000f7930();
        SelectorView_b9bf0 *story = (SelectorView_b9bf0 *)FUN_00344e74(FUN_000fc260("story_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (story != 0) {
            story->FUN_000e36c0();
            unsigned __int64 key = FUN_0027b020("TBS_CHPT_GEN_60");
            int idx = FUN_000fc1b0()->FUN_000f7240((int)key, (int)(key >> 32));
            if (idx != -1)
                ((owners::Obj_f7a10 *)&(f.u.story))->FUN_000f7a10((hulk_intptr)idx, 0);
            else
                f.u.story.FUN_000f8500("TBS_CHPT_GEN_60", FUN_000fc1b0(), 0);
            story->v19(&f.u.story, 0, 0);
            story->v3();
        }
        SelectorView_b9bf0 *side = (SelectorView_b9bf0 *)FUN_00344e74(FUN_000fc260("side_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (side != 0) {
            side->FUN_000e36c0();
            unsigned __int64 key = FUN_0027b020("TBS_CHPT_GEN_11");
            int idx = FUN_000fc1b0()->FUN_000f7240((int)key, (int)(key >> 32));
            if (idx != -1)
                ((owners::Obj_f7a10 *)&(f.u.story))->FUN_000f7a10((hulk_intptr)idx, 0);
            else
                f.u.story.FUN_000f8500("TBS_CHPT_GEN_11", FUN_000fc1b0(), 0);
            side->v19(&f.u.story, 0, 0);
            side->v3();
        }
        ((owners::Thing_f7960 *)&(f.u.story))->FUN_000f7960();
    }
}
} // namespace fn_000b9bf0
#undef memcmp
#undef strcmp
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000bb600 FUN_000bb600 (108 B): matches/0x000bb600.cpp [wrapped: conflict: FUN_001d4c90]
// sym: ?FUN_000bb600@fn_000bb600@@YAXXZ
namespace fn_000bb600 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000bb600 @ 0x000bb600
// cl-flags: /GS
struct Parameters_bb600 {
    unsigned int first;
    char rest[0x2b4];
    void FUN_001d1630();
};
struct Manager_bb600 {
    void FUN_001d3b00(const char* name, Parameters_bb600 parameters);
};
extern Manager_bb600* __cdecl FUN_001d4c90();
void __cdecl FUN_000bb600() {
    Manager_bb600* manager = FUN_001d4c90();
    if (manager) {
        Parameters_bb600 parameters;
        parameters.FUN_001d1630();
        parameters.first = 0;
        manager->FUN_001d3b00("UpdateMoveList", parameters);
    }
}
} // namespace fn_000bb600

