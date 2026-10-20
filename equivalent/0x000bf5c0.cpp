// STATUS: equivalent (tools/equiv.py level 3: 2244 inputs, branch coverage 10/10)
// FUN_000bf5c0 @ 0x000bf5c0
class CUnlockable {
  public:
    virtual void v0();
};
class CUnlockableMove : public CUnlockable {
  public:
    char pad[4];
    char flag;
    void FUN_00091f30(int arg);
};
class ItemTable_bf5c0 {
  public:
    CUnlockable* FUN_00092ad0(int index);
};
struct Game_bf5c0 {
    char FUN_000be230(const char* cls, const char* msg, const char* title, const char* ok,
                      const char* cancel, int buttons, int a, int b);
};
Game_bf5c0* __cdecl FUN_000fc3d0();

class Screen_bf5c0 {
  public:
    char pad0[0x4c];
    ItemTable_bf5c0* items;
    char FUN_000bf5c0(int lastRow);
};

char Screen_bf5c0::FUN_000bf5c0(int lastRow) {
    int table[7][20] = {
        { -1 },
        { 0x266, 0x267, 0x268, 0x269, 0x26a, 0x2a6, 0x2b0, 0x28f, 0x26d, 0x271, 0x2af, 0x27f, 0x296, -1 },
        { 0x26b, 0x26c, 0x26e, 0x26f, 0x270, 0x283, 0x274, 0x278, 0x27b, 0x2b4, 0x2b5, 0x2b7, 0x2b8,
          0x2b9, 0x27e, 0x2b6, 0x2ab, -1 },
        { 0x272, 0x27c, 0x27d, 0x276, 0x280, 0x273, 0x285, 0x289, 0x28a, 0x28b, 0x2a4, 0x2ad, 0x2b3,
          0x2b1, 0x299, 0x29b, 0x29f, -1 },
        { 0x286, 0x28c, 0x28d, 0x290, 0x293, 0x294, 0x295, 0x298, 0x2a2, 0x2ae, 0x2b2, 0x287, -1 },
        { 0x29c, 0x29e, 0x28e, 0x2a3, 0x2ba, -1 },
        { -1 }
    };
    for (int i = 0; i <= lastRow && i < 7; i++) {
        const int* p = table[i];
        if (*p != -1) {
            do {
                CUnlockableMove* m = dynamic_cast<CUnlockableMove*>(items->FUN_00092ad0(*p));
                if (m) {
                    m->flag = 0;
                    m->FUN_00091f30(1);
                }
                ++p;
            } while (*p != -1);
        }
    }
    return FUN_000fc3d0()->FUN_000be230("FEGenericDialog", "Moves unlocked", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
}
