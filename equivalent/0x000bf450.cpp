// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_000bf450 @ 0x000bf450
// Demo/attract screen: remember the menu name; without a "go back" request show the quit-demo dialog,
// otherwise leave the current screen.
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

class Screen_bf450 {
public:
    void FUN_001cc620(int next);
};

class DialogManager_bf450 {
public:
    void FUN_000be230(const char* dialog, const char* text, const char* extra, const char* ok, const char* cancel, int buttons, int a, int b);
};

DialogManager_bf450* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc300();

class MenuState {
public:
    char pad0[0x10];
    int state;
    char pad14[0x38 - 0x14];
    Screen_bf450* screen;
    char pad3c[0x1c8c - 0x3c];
    char name[0x20];

    void FUN_000b97d0();
    void FUN_000bf450(const char* menuName, int goBack);
};

void MenuState::FUN_000bf450(const char* menuName, int goBack)
{
    strncpy(name, menuName ? menuName : "main", 0x1f);
    if (goBack == 0) {
        FUN_000fc3d0()->FUN_000be230("FEGenericDialog", "TBS_MENU_ITEM_QUIT_DEMO", "", "TBS_MENU_ITEM_OK", "TBS_CANCEL", 2, 0, 0);
        state = 0x15;
        FUN_000b97d0();
        return;
    }
    if (state != 3) {
        if (screen) {
            screen->FUN_001cc620(5);
        }
        FUN_000fc300();
    }
}
