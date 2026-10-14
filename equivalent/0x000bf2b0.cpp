// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 28/34, incomplete)
// FUN_000bf2b0 @ 0x000bf2b0
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned int n);

struct Counter_bf2b0 {
    int FUN_00088fa0();
};

struct Panel_bf2b0 {
    char pad0[0x80];
    Counter_bf2b0 counter;         // 0x80
    char pad84[0x108 - 0x84];
    int field108;
    void FUN_00089390();
    const char *FUN_0008a310();
    const char *FUN_0008a2d0();
    char FUN_00089a10();
    void FUN_00089a30(int flag);
    void FUN_000895e0(void *item);
    void FUN_00089810(const char *name);
};

struct Widget_bf2b0 {
    void FUN_001cc620(int state);
};

struct Listener_bf2b0 {
    void FUN_00093c40(const char *name);
};

struct Hud_bf2b0 {
    void FUN_000d6fb0(int flag);
};

struct Player_bf2b0 {
    char pad0[0x1b0c];
    float health;            // 0x1b0c
};

struct Party {
    char pad0[0x124];
    Player_bf2b0 *leader;          // 0x124
};

struct Group_bf2b0 {
    char pad0[0x20];
    Party *party;            // 0x20
    char pad24[0x3c - 0x24];
    Hud_bf2b0 *hud;                // 0x3c
};
extern Group_bf2b0 *DAT_004dd700;

struct Game_bf2b0 {
    char FUN_000be230(const char *cls, const char *msg, const char *title, const char *ok,
                      const char *cancel, int buttons, int a, int b);
};
Game_bf2b0 *__cdecl FUN_000fc3d0();
void __cdecl FUN_000fc300();

class Menu_bf2b0 {
public:
    char pad0[0x10];
    int state;               // 0x10
    char pad14[0x34 - 0x14];
    Panel_bf2b0 *panel;            // 0x34
    Widget_bf2b0 *widget;          // 0x38
    char pad3c[0x4c - 0x3c];
    Listener_bf2b0 *listener;      // 0x4c
    char pad50[0x1c8c - 0x50];
    char sideName[0x20];     // 0x1c8c
    void FUN_000b9830();
    void *FUN_000b4cf0(const char *name);
    void FUN_000bf2b0(int confirmed);
};

void Menu_bf2b0::FUN_000bf2b0(int confirmed)
{
    if (!confirmed) {
        FUN_000fc3d0()->FUN_000be230("FEGenericDialog", "TBS_MENU_ITEM_ABORT_NO_SAVE_1", "",
                                     "TBS_MENU_ITEM_OK", "TBS_CANCEL", 2, 0, 0);
        state = 0x16;
        FUN_000b9830();
        return;
    }
    if (!panel)
        return;
    if (!widget)
        return;

    panel->FUN_00089390();
    const char *name = panel->FUN_0008a310();
    if (!name)
        return;

    const char *other = panel->FUN_0008a2d0();
    bool same = true;
    {
        const char *a = name;
        const char *b = other;
        for (;;) {
            if (*a != *b) {
                same = false;
                break;
            }
            if (*a == 0)
                break;
            a++;
            b++;
        }
    }

    Player_bf2b0 *leader = DAT_004dd700->party->leader;
    bool alive = leader && leader->health > 0.0f;

    if (same && alive) {
        widget->FUN_001cc620(0);
        DAT_004dd700->hud->FUN_000d6fb0(1);
    } else {
        int level = panel->counter.FUN_00088fa0();
        if (panel->FUN_00089a10() && level == 10) {
            widget->FUN_001cc620(5);
            panel->FUN_00089a30(1);
            strncpy(sideName, "side_missions", 0x1f);
        } else {
            widget->FUN_001cc620(9);
            panel->FUN_00089a30(0);
            void *item = FUN_000b4cf0(name);
            if (!item)
                return;
            panel->FUN_000895e0(item);
            panel->FUN_00089810(name);
        }
    }
    if (listener)
        listener->FUN_00093c40(name);
    FUN_000fc300();
}
