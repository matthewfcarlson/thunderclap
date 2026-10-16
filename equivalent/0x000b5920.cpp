// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000b5920 @ 0x000b5920
#include "decls/data/game/global.h"

struct Control_b5920 {
    char pad00[5];
    char busy;
    char pad06[2];
    void FUN_000afe10(int enable);
    void FUN_000aff30(int a, float x, float y, float z, const char *name);
};

struct Entry_b5920 {
    char pad[0x134];
    char name[1];
};

struct Registry_b5920 {
    Entry_b5920 *FUN_000ae640(int index);
};

struct Panel_b5920 {
    char pad00[0x44];
    Control_b5920 *control;
    char pad48[0x58 - 0x48];
    Registry_b5920 *registry;
    void FUN_000b5920(int enable);
};

void Panel_b5920::FUN_000b5920(int enable)
{
    if (control != 0) {
        char wasBusy = control->busy;
        control->FUN_000afe10(enable);
        if (wasBusy == 0 && (char)enable != 0) {
            const char *name;
            if (registry->FUN_000ae640(0)->name[0] != 0)
                name = registry->FUN_000ae640(0)->name;
            else
                name = DAT_004de768;
            control->FUN_000aff30(0, 100.0f, 100.0f, 0.4f, name);
        }
    }
}
