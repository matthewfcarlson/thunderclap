// STATUS: equivalent (tools/equiv.py level 3: 135 inputs, branch coverage 36/36)
// FUN_00092540 @ 0x00092540
struct Triple {
    int a;
    int b;
    int c;
    void FUN_0027af50();
};

class Registry {
public:
    bool FUN_00092470(int lo, int hi, const char* fmt, int a, int b, int c);
    void FUN_00092540(int kind, Triple t);
};

void Registry::FUN_00092540(int kind, Triple t)
{
    if (kind == 3) {
        this->FUN_00092470(0x52, 0x8d, "comic_%d", t.a, t.b, t.c);
    } else if (kind == 4) {
        if (this->FUN_00092470(0x8f, 0x94, "hint_EXPERIENCE_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x95, 0x98, "hint_COLLECTIBLES_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x99, 0x9b, "hint_WEAPONIZATION_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x9c, 0xa1, "hint_FRSM_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xa2, 0xa4, "hint_CHURCH_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xa5, 0xa9, "hint_CAMERAS_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xaa, 0xae, "hint_RAGE_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xaf, 0xb3, "hint_MOVEMENT_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xb4, 0xc7, "hint_COMBAT_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xc8, 0xcb, "hint_NAVIGATION_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xcc, 0xcf, "hint_HUD_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xd0, 0xd0, "hint_WEAPON_PODS_C4M5_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xd1, 0xd8, "hint_TARGETING_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        this->FUN_00092470(0xd9, 0xdd, "hint_COMBO_%d_marker", t.a, t.b, t.c);
    } else if (kind == 5) {
        if (this->FUN_00092470(0xe0, 0x11c, "smashMedium%d", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x11d, 0x1af, "smash_%d", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        this->FUN_00092470(0x1b0, 0x1bd, "smashMajor%d", t.a, t.b, t.c);
    }
    t.FUN_0027af50();
}
