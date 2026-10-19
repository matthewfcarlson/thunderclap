// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 225/250, incomplete)
// FUN_000ba040 @ 0x000ba040
// cl-flags: /GS
// FUN_000ba040 @ 0x000ba040
// Collection screen: counts unlocked/available items per category, then fills in the gallery buttons.

class CUnlockable {
public:
    virtual void vfunc_0();
};
struct Id64 {
    unsigned int lo;
    unsigned int hi;
};
class CUnlockableMove : public CUnlockable {
public:
    virtual void vfunc_1();
    Id64* FUN_00092070();
};

struct Unlocks {
    char FUN_00092860(int index);
    char FUN_00092a40(int index);
    CUnlockable* FUN_00092ad0(int index);
};

struct TextEntry {
    void FUN_000f79a0(const char* text, int flag);
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x10];
    int f14;
    TextEntry entry;
};
class TextButton : public FEObject {
public:
    virtual void vfunc_4();
    char pad1c[0x141 - 0x1c];
    char enabled;
};
class TextSelector : public FEObject {
public:
    virtual void vfunc_4();
    char pad1c[0x1d58 - 0x1c];
    int count;
};

struct TextStore {
    int FUN_000f7d30(const char* id);
    const char* FUN_000f7220(int id);
};

struct ScriptArgs {
    int tag;
    char text[10][0x40];
    int ints[10];
    char kinds[10];
    char pad2b6[2];
    void FUN_001d1630();
};

struct Script {
    int FUN_001d3b00(const char* name, ScriptArgs args);
    const char* FUN_001d27b0(const char* name);
};

extern "C" Script* __cdecl FUN_001d4c90();
extern "C" FEObject* __cdecl FUN_000fc260(const char* name);
extern "C" TextStore* __cdecl FUN_000fc1b0();
extern "C" int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);
extern "C" int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);
extern "C" char* __cdecl FUN_000fb690(char* dst, const char* src, int n);
extern "C" char* __cdecl FUN_000fb790(char* dst, const char* src, int n);

struct Frame {
    // per-category counts: have = items the player has, total = items that exist
    int total4, total2, total1, have3, have7, have1, have8;
    int total5, total7, total3, total8;
    int have2, haveCheat, haveEnemyRender, haveSmartHints, totalEnemyRender;
    int haveHints, have4, have5, have6, total6, totalBlonsky, haveBlonsky, totalBuy, haveBuy;
    int locked;
    int have3a[3], have5a[3], have4a[4], total5a[3], total3a[3], have2a[5], have1a[6];
    int total4a[4], total2a[5], total1a[6];
    char textBuf[0x80];
    char pad1ac[0x80];
    char nameBuf[0x80];
    char labelBuf[0x80];
    ScriptArgs args;
};

class CollectionScreen {
public:
    char pad0[0x4c];
    Unlocks* unlocks;
    void FUN_000ba040();
};

// the flag is stored before the label work in the original (volatile keeps the store from sinking past the calls)
#define SET_ENABLED(b, v) (*(volatile char*)&(b)->enabled = (v))
#define FIND_BUTTON(name) dynamic_cast<TextButton*>(FUN_000fc260(name))

static __forceinline void SetupLabel(Frame& f, TextStore* texts, TextButton* button, const char* labelId, int total)
{
    FUN_000fb690(f.textBuf, texts->FUN_000f7220(texts->FUN_000f7d30(labelId)), 0x80);
    if (total > 0)
        FUN_000fb790(f.textBuf, " \010nu", 0x80);
    button->entry.FUN_000f79a0(f.textBuf, 0);
    button->vfunc_3();
}

static __forceinline void SetupGalleryButton(Frame& f, TextStore* texts, const char* nameFmt, int n, int have, int total)
{
    FUN_000964a0(f.nameBuf, 0x80, nameFmt, n);
    TextButton* button = dynamic_cast<TextButton*>(FUN_000fc260(f.nameBuf));
    if (button) {
        SET_ENABLED(button, have > 0);
        FUN_000964a0(f.labelBuf, 0x80, "TBS_MENU_ITEM_SF_GALLERY_%d", n);
        SetupLabel(f, texts, button, f.labelBuf, total);
    }
}


void CollectionScreen::FUN_000ba040()
{
    Frame f;
    f.total4 = f.total2 = f.total1 = 0;
    f.have3 = f.have7 = f.have1 = f.have8 = 0;
    f.total5 = f.total7 = f.total3 = f.total8 = 0;
    f.have2 = f.haveCheat = f.haveEnemyRender = f.haveSmartHints = f.totalEnemyRender = 0;
    f.haveHints = f.have4 = f.have5 = f.have6 = f.total6 = 0;
    f.totalBlonsky = f.haveBlonsky = f.totalBuy = f.haveBuy = 0;
    for (int k = 0; k < 3; ++k) { f.have3a[k] = 0; f.have5a[k] = 0; f.total5a[k] = 0; f.total3a[k] = 0; }
    for (int k = 0; k < 4; ++k) { f.have4a[k] = 0; f.total4a[k] = 0; }
    for (int k = 0; k < 5; ++k) { f.have2a[k] = 0; f.total2a[k] = 0; }
    for (int k = 0; k < 6; ++k) { f.have1a[k] = 0; f.total1a[k] = 0; }

    for (int i = 0; i < 0x2fd; ++i) {
        f.locked = unlocks->FUN_00092860(i) == 0;
        int got = 0;
        if (f.locked > 0)
            got = unlocks->FUN_00092a40(i) != 0;
        if (i >= 0x52 && i < 0x8d) {
            int k = (i - 0x52) / 10;
            if (k < 6) {
                f.have1a[k] += f.locked;
                f.total1a[k] += got;
            }
            f.have1 += f.locked;
            f.total1 += got;
        } else if (i >= 0x1bf && i < 0x1e5) {
            int k = (i - 0x1bf) / 10;
            if (k < 5) {
                f.have2a[k] += f.locked;
                f.total2a[k] += got;
            }
            f.have2 += f.locked;
            f.total2 += got;
        } else if (i >= 0x1f1 && i < 0x202) {
            int k = (i - 0x1f1) / 10;
            if (k < 3) {
                f.have3a[k] += f.locked;
                f.total3a[k] += got;
            }
            f.have3 += f.locked;
            f.total3 += got;
        } else if (i >= 0x20a && i < 0x22d) {
            int k = (i - 0x20a) / 10;
            if (k < 4) {
                f.have4a[k] += f.locked;
                f.total4a[k] += got;
            }
            f.have4 += f.locked;
            f.total4 += got;
        } else if (i >= 0x22e && i < 0x243) {
            int k = (i - 0x22e) / 10;
            if (k < 3) {
                f.have5a[k] += f.locked;
                f.total5a[k] += got;
            }
            f.have5 += f.locked;
            f.total5 += got;
        } else if (i >= 0x244 && i < 0x247) {
            f.have6 += f.locked;
            f.total6 += got;
            f.haveEnemyRender += f.locked;
            f.totalEnemyRender += got;
        } else if (i >= 0x258 && i < 0x260) {
            f.have7 += f.locked;
            f.total7 += got;
        } else if (i >= 0x248 && i < 0x257) {
            f.have8 += f.locked;
            f.total8 += got;
        } else if (i >= 0x266 && i < 0x2c9) {
            CUnlockableMove* move = dynamic_cast<CUnlockableMove*>(unlocks->FUN_00092ad0(i));
            if (move) {
                Id64* id = move->FUN_00092070();
                if (id->lo | id->hi) {
                    f.haveBuy += f.locked;
                    f.totalBuy += got;
                }
            }
        } else if (i >= 0x34 && i < 0x51) {
            f.haveBlonsky += f.locked;
            f.totalBlonsky += got;
        } else if (i >= 0x8e && i < 0xde) {
            f.haveHints += f.locked;
        } else if (i >= 0x2e9 && i < 0x2fd) {
            f.haveSmartHints += f.locked;
        } else if (i >= 0 && i < 0x31) {
            Script* script = FUN_001d4c90();
            f.args.FUN_001d1630();
            f.args.tag = 1;
            FUN_00267760(f.args.text[0], 0x40, "%d", i);
            int result = script->FUN_001d3b00("kmcIsCheatComicCollected", f.args);
            if (result == 3 && script->FUN_001d27b0("__IS_CHEAT_COMIC_COLLECTED__") != 0)
                f.haveCheat += 1;
            else
                f.haveCheat += f.locked;
        }
    }

    TextStore* texts = FUN_000fc1b0();
    for (int n = 1; n <= 6; ++n)
        SetupGalleryButton(f, texts, "comic_book_gallery_%d_button", n, f.have1a[n - 1], f.total1a[n - 1]);
    for (int n = 1; n <= 5; ++n)
        SetupGalleryButton(f, texts, "character_gallery_%d_button", n, f.have2a[n - 1], f.total2a[n - 1]);
    for (int n = 1; n <= 3; ++n)
        SetupGalleryButton(f, texts, "enemy_gallery_%d_button", n, f.have3a[n - 1], f.total3a[n - 1]);
    for (int n = 1; n <= 4; ++n)
        SetupGalleryButton(f, texts, "environment_gallery_%d_button", n, f.have4a[n - 1], f.total4a[n - 1]);
    for (int n = 1; n <= 3; ++n)
        SetupGalleryButton(f, texts, "character_render_gallery_%d_button", n, f.have5a[n - 1], f.total5a[n - 1]);

    // enemy render gallery 1
    FUN_000964a0(f.nameBuf, 0x80, "enemy_render_gallery_1_button");
    TextButton* button = FIND_BUTTON(f.nameBuf);
    if (button) {
        SET_ENABLED(button, f.have6 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_GALLERY_1", f.total6);
    }
    button = FIND_BUTTON("comic_book_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have1 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_COMIC_BOOK", f.total1);
    }
    button = FIND_BUTTON("character_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have2 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_CHARACTER", f.total2);
    }
    button = FIND_BUTTON("enemy_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have3 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_ENEMY", f.total3);
    }
    button = FIND_BUTTON("environment_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have4 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_ENVIRONMENT", f.total4);
    }
    button = FIND_BUTTON("character_render_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have5 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_CHARACTER_RENDER", f.total5);
    }
    button = FIND_BUTTON("enemy_render_gallery_button");
    if (button) {
        SET_ENABLED(button, f.haveEnemyRender > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_ENEMY_RENDER", f.totalEnemyRender);
    }
    button = FIND_BUTTON("in_game_movies_button");
    if (button) {
        SET_ENABLED(button, f.have8 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_IN_GAME_MOVIES", f.total8);
    }
    button = FIND_BUTTON("making_of_movies_button");
    if (button) {
        SET_ENABLED(button, f.have7 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_FEATURETTES", f.total7);
    }
    button = FIND_BUTTON("art_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have5 + f.haveEnemyRender + f.have4 + f.have3 + f.have2 + f.have1 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_ART_GALLERY",
                   f.total5 + f.totalEnemyRender + f.total4 + f.total3 + f.total2 + f.total1);
    }
    button = FIND_BUTTON("movie_gallery_button");
    if (button) {
        SET_ENABLED(button, f.have7 + f.have8 > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SF_MOVIE_GALLERY", f.total7 + f.total8);
    }
    button = FIND_BUTTON("menu_item_blonsky_file");
    if (button) {
        SET_ENABLED(button, f.haveBlonsky > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SM_BLONSKY_FILES", f.totalBlonsky);
    }
    button = FIND_BUTTON("menu_item_buy_menu");
    if (button) {
        SET_ENABLED(button, f.haveBuy > 0);
        SetupLabel(f, texts, button, "TBS_MENU_ITEM_SM_BUY_MENU", f.totalBuy);
    }
    button = FIND_BUTTON("hints_button");
    if (button)
        SET_ENABLED(button, f.haveHints > 0);
    button = FIND_BUTTON("smart_hints_button");
    if (button)
        SET_ENABLED(button, f.haveSmartHints > 0);
    button = FIND_BUTTON("cheat_codes_button");
    if (button)
        SET_ENABLED(button, f.haveCheat > 0);
    button = FIND_BUTTON("hints_and_cheat_codes_button");
    if (button)
        SET_ENABLED(button, f.haveCheat + f.haveSmartHints + f.haveHints > 0);

    bool hasStory = false;
    TextSelector* recap = dynamic_cast<TextSelector*>(FUN_000fc260("story_recap_list"));
    if (recap)
        hasStory = recap->count > 0;
    button = FIND_BUTTON("story_recap_list_screen_button");
    if (button)
        SET_ENABLED(button, hasStory);
}
