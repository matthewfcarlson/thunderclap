// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000bf4e0 @ 0x000bf4e0
struct Dialog_bf4e0 {
    void FUN_000be230(const char* name, const char* title, const char* text, const char* okLabel, const char* cancelLabel, int a, int b, int c);
};
struct Screen_bf4e0 { void FUN_00089a30(char v); };
extern char DAT_003f335c[];
Dialog_bf4e0* FUN_000fc3d0();
void FUN_000fc300();

struct Overlay { void FUN_001cc620(int id); };

struct Menu_bf4e0 {
    char pad0[0x10];
    int state;
    char pad14[0x1c];
    int f30;
    Screen_bf4e0* screen;
    Overlay* overlay;
    void FUN_000b9770();
    void FUN_000bf4e0(int confirmed);
};

void Menu_bf4e0::FUN_000bf4e0(int confirmed) {
    if (f30 == 0 || screen == 0 || overlay == 0)
        return;
    if (confirmed == 0) {
        FUN_000fc3d0()->FUN_000be230("FEGenericDialog", "TBS_MENU_ITEM_RESTART_DEMO", DAT_003f335c,
                                     "TBS_MENU_ITEM_OK", "TBS_CANCEL", 2, 0, 0);
        state = 0x14;
        FUN_000b9770();
    } else {
        overlay->FUN_001cc620(9);
        screen->FUN_00089a30(0);
        FUN_000fc300();
    }
}
