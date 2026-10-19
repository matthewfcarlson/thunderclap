// STATUS: equivalent (tools/equiv.py level 3: 20025 inputs, branch coverage 31/32, incomplete)
// FUN_000bc9f0 @ 0x000bc9f0
// cl-flags: /GS

struct Label_bc9f0 {
    char pad0[0x10];
    void FUN_000f79a0(const unsigned short* text, int flag);
};

struct Owner_bc9f0 {
    char pad0[0x18];
    Label_bc9f0 label;
};

Owner_bc9f0* FUN_000fc260(int id);

class MenuScreen_bc9f0 {
  public:
    int FUN_000bc900(unsigned short* out, int pos, const char* name, int flag);
    void FUN_000bc9f0(int id, int code);
};

void MenuScreen_bc9f0::FUN_000bc9f0(int id, int code)
{
    unsigned short text[0x100];
    Owner_bc9f0* owner = FUN_000fc260(id);
    if (owner) {
        Label_bc9f0* label = &owner->label;
        if (label) {
            int pos = 0;
            if (code == 0) {
                text[0] = 0;
            } else if (code == 12) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT2", 0);
                FUN_000bc900(text, pos, "TBS_CANCEL", 1);
            } else if (code == 11) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT2", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 10) {
                FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT2", 0);
            } else if (code == 9) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_LS_LOAD", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 8) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_CHALLENGE_FE_SAVE", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 7) {
                pos = FUN_000bc900(text, 0, "TBS_FORMAT", 0);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            } else if (code == 6) {
                pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_CHALLENGE_FE_SAVE", 0);
                pos = FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
                FUN_000bc900(text, pos, "TBS_MENU_ITEM_CHALLENGE_FE_DELETE", 2);
            } else if (code == 5) {
                FUN_000bc900(text, 0, "TBS_MENU_CONFIRMATION_ACCEPT1", 0);
            } else if (code == 4) {
                FUN_000bc900(text, 0, "TBS_MENU_ITEM_OK", 0);
            } else {
                if (code == 1 || code == 3)
                    pos = FUN_000bc900(text, 0, "TBS_MENU_ITEM_BONUS_FEATURES_SELECT", 0);
                if (code == 1 || code == 2)
                    FUN_000bc900(text, pos, "TBS_MENU_ITEM_BUTTON_BACK", 1);
            }
            label->FUN_000f79a0(text, 0);
        }
    }
}
