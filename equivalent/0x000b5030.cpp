// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b5030 @ 0x000b5030
struct Slot { void FUN_00086420(); };
struct Holder { Slot *FUN_00086270(int a); };
struct Globals {
    char pad00[0x54];
    Holder *holder;
};
extern Globals *DAT_004dd700;

struct Target { void FUN_0008ffe0(); };

struct Panel {
    void FUN_000895c0(int a);
    void FUN_00089830(const char *name);
    bool FUN_000893c0();
    void FUN_000895e0(void *item);
    void FUN_00089810(const char *name);
    void FUN_00089300(const char *name);
};

class Screen {
public:
    char pad00[0x34];
    Panel *panel;
    char pad38[0x50 - 0x38];
    Target *target;
    void *FUN_000b4cf0(const char *name);
    void FUN_000b5030(int a);
};

void Screen::FUN_000b5030(int a)
{
    if (!panel)
        return;
    panel->FUN_000895c0(a);
    panel->FUN_00089830("c00m01");
    void *item = FUN_000b4cf0("c00m01");
    if (!item)
        return;
    if (!panel->FUN_000893c0())
        target->FUN_0008ffe0();
    panel->FUN_000895e0(item);
    panel->FUN_00089810("c00m01");
    panel->FUN_00089300("story");
    DAT_004dd700->holder->FUN_00086270(1)->FUN_00086420();
}
