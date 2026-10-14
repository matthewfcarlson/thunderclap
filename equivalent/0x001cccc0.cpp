// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 33/34, incomplete)
// FUN_001cccc0 @ 0x001cccc0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

struct Overlay {
    void FUN_000d4620(int one, const char *text, int minusOne, unsigned color, float minusOneF);
};

struct Holder_1cccc0 {
    char pad0[4];
    Overlay *overlay;
};

struct Checker_1cccc0 {
    int FUN_00086280();
};

struct Parent_1cccc0 {
    char pad0[0x3c];
    Holder_1cccc0 *holder;
    char pad40[0x54 - 0x40];
    Checker_1cccc0 *checker;
};

struct Palette_1cccc0 {
    unsigned *FUN_00025930(unsigned *out, int which);
};

struct Globals_1cccc0 {
    char pad0[0x20];
    Palette_1cccc0 *palette;
};

struct Names_1cccc0 {
    Names_1cccc0 *FUN_00086370(const char *name, int flag);
    void FUN_00090720();
};

extern Globals_1cccc0 *DAT_004dd700;
extern Names_1cccc0 *DAT_004dd6ec;

void FUN_00267830(char *dst, const char *src, int n);

struct Frame_1cccc0 {
    union {
        float level;
        unsigned color;
    } slot;
    char text[0x100];
};

class ComboTracker {
public:
    char pad0[4];
    Parent_1cccc0 *parent;
    char pad8[0x11ac - 8];
    int count;
    char pad11b0[4];
    int tierCount;
    float thresholds[16];
    char labels[16][0x20];
    void FUN_001cccc0();
};

void ComboTracker::FUN_001cccc0()
{
    unsigned int cookie = DAT_004d9968;
    Frame_1cccc0 f;
    if (count > 1 && parent && parent->checker && parent->checker->FUN_00086280()
        && parent->holder) {
        Overlay *overlay = parent->holder->overlay;
        if (overlay) {
            if (tierCount > 0) {
                f.slot.level = (float)count;
                if (f.slot.level >= thresholds[0]) {
                    int idx = tierCount - 1;
                    for (int i = tierCount - 2; i >= 1; i--) {
                        if (f.slot.level <= thresholds[i])
                            idx = i;
                    }
                    FUN_00267830(f.text, labels[idx], 0x100);
                    unsigned *c = DAT_004dd700->palette->FUN_00025930(&f.slot.color, 3);
                    overlay->FUN_000d4620(1, f.text, -1, *c, -1.0f);
                }
            }
            DAT_004dd6ec->FUN_00086370("action_combo", 1)->FUN_00090720();
        }
    }
    __security_check_cookie(cookie);
}
