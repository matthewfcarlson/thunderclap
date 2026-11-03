// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 34/34)
// FUN_001cccc0 @ 0x001cccc0
// cl-flags: /GS
#include "decls/address.h"
#include "gen/owners.h"

struct Overlay_1cccc0 {
    void FUN_000d4620(int one, const char *text, int minusOne, unsigned color, float minusOneF);
};

struct Holder_1cccc0 {
    char pad0[4];
    Overlay_1cccc0 *overlay;
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
};

struct World {
    char pad0[0x20];
    Palette_1cccc0 *palette;
};

struct Singleton_4dd6ec {
    Singleton_4dd6ec *FUN_00086370();
    void FUN_00090720(const char *name, int flag);
};


extern "C" void FUN_00267830(char *dst, const char *src, int n);

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
    Frame_1cccc0 f;
    if (count > 1 && parent && parent->checker && parent->checker->FUN_00086280()
        && parent->holder) {
        Overlay_1cccc0 *overlay = parent->holder->overlay;
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
                    unsigned *c = ((unsigned *)((owners::Palette_25930 *)(DAT_004dd700->palette))->FUN_00025930((unsigned int *)(&f.slot.color), 3));
                    overlay->FUN_000d4620(1, f.text, -1, *c, -1.0f);
                }
            }
            DAT_004dd6ec->FUN_00086370()->FUN_00090720("action_combo", 1);
        }
    }
}
