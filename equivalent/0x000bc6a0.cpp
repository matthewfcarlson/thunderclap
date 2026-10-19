// STATUS: equivalent (tools/equiv.py level 3: 15378 inputs, branch coverage 10/10)
// FUN_000bc6a0 @ 0x000bc6a0
// cl-flags: /GS
int FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct Item;

struct Label_bc6a0 {
    void FUN_00089880(int *a, int *b);
    void FUN_000895e0(Item *item);
    void FUN_00089810(const char *name);
    void FUN_00089300(const char *text);
};

struct Highlight {
    void FUN_00093c40(const char *name);
};

class Menu_bc6a0 {
public:
    char pad0[0x34];
    Label_bc6a0 *label;           // 0x34
    char pad38[0x4c - 0x38];
    Highlight *highlight;   // 0x4c
    Item *FUN_000b4cf0(const char *name);
    void FUN_000bc6a0();
};

void Menu_bc6a0::FUN_000bc6a0()
{
    struct Frame {
        int b;
        int a;
        char name[0x10];
    } fr;
    if (label != 0) {
        label->FUN_00089880(&fr.a, &fr.b);
        if (fr.a > -1 && fr.b > -1) {
            FUN_000964a0(fr.name, 0x10, "c%02dm%02d", fr.a, fr.b);
            Item *item = FUN_000b4cf0(fr.name);
            if (item != 0) {
                if (highlight != 0)
                    highlight->FUN_00093c40(fr.name);
                label->FUN_000895e0(item);
                label->FUN_00089810(fr.name);
                label->FUN_00089300("story");
            }
        }
    }
}
