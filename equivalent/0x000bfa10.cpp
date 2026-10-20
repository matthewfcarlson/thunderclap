// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000bfa10 @ 0x000bfa10
// cl-flags: /GS
extern "C" int sprintf(char* buf, const char* fmt, ...);

struct Lookup_bfa10 {
    void FUN_00093950(int a, int b, char* foundOut, char* flagA, char* flagB, int* pairOut);
};

struct Strings_bfa10 {
    int FUN_000f7d30(const char* key);
    const char* FUN_000f7220(int id);
    int FUN_000f7240(int a, int b);
};

struct DialogMgr {
    void FUN_000be230(const char* name, const char* msg, const char* s1, const char* s2, const char* ok, int a, int b, int c);
    void FUN_000be310(const char* name, const char* msg, const char* s1, const char* s2, const char* ok, int a, int b, int c);
};

Strings_bfa10* FUN_000fc1b0();
DialogMgr* FUN_000fc3d0();
extern "C" int FUN_000fc020(char* buf, int size, const char* fmt, ...);

struct Frame_bfa10 {
    char unused;
    char flagA;
    char flagB;
    char found;
    int pair[2];
    char dialog[0x20];
    char text[0x80];
    char rest[0x80];
};

struct UnlockMenu {
    char pad[0x4c];
    Lookup_bfa10* lookup;

    void FUN_000bfa10(int arg1, int arg2);
};

void UnlockMenu::FUN_000bfa10(int arg1, int arg2)
{
    Frame_bfa10 f;
    if (lookup != 0) {
        lookup->FUN_00093950(arg1, arg2, &f.found, &f.flagA, &f.flagB, f.pair);
        if ((char)arg2 != 0)
            sprintf(f.dialog, "%s", "FEGenericSimDialog");
        else
            sprintf(f.dialog, "%s", "FEGenericDialog");

        if (f.found == 0) {
            FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_INVALID_ENTRY", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
        } else if (f.flagB != 0) {
            Strings_bfa10* s = FUN_000fc1b0();
            int key = s->FUN_000f7d30("TBS_UNLOCKABLES_VALID_ENTRY_2");
            const char* fmt = s->FUN_000f7220(key);
            int a = f.pair[0];
            int b = f.pair[1];
            int v = FUN_000fc1b0()->FUN_000f7240(a, b);
            const char* arg = FUN_000fc1b0()->FUN_000f7220(v);
            FUN_000fc020(f.text, 0x80, fmt, arg);
            FUN_000fc3d0()->FUN_000be310(f.dialog, f.text, "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
        } else {
            if (f.flagA != 0)
                FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_INVALID_ENTRY_2", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
            if ((char)arg2 != 0)
                FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_GENERIC_CODE_WRONG_LOCATION_1", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
            else
                FUN_000fc3d0()->FUN_000be230(f.dialog, "TBS_UNLOCKABLES_UP_CODE_WRONG_LOCATION_2", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
        }
    }
}
