// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001f47b0 @ 0x001f47b0
struct Key_1f47b0 {
    int lo, hi;
};

struct Timer {
    Key_1f47b0 key;                 // 0x00
    int field08;
    int field0c;
    int field10;
    int field14;
    char field18;
    void FUN_0027af60(int a, int b);
};

struct Target_1f47b0 {
    char pad00[0x10];
    int expected;            // 0x10
    void FUN_001f3400(int amount);
};

int __cdecl FUN_002673a0(int a, int b);

class Owner_1f47b0 {
public:
    char pad00[0x8c];
    Target_1f47b0 *target;          // 0x8c
    char pad90[0x10];
    Timer timer;             // 0xa0
    int FUN_001f31a0(Key_1f47b0 *key);
    bool FUN_001f47b0(Key_1f47b0 *key);
};

bool Owner_1f47b0::FUN_001f47b0(Key_1f47b0 *key) {
    if (key && key->lo == timer.key.lo && key->hi == timer.key.hi) {
        timer.FUN_0027af60(0, 0);
        timer.field08 = 0;
        timer.field0c = FUN_002673a0(0, 0);
        timer.field10 = 999;
        timer.field14 = 0;
        timer.field18 = 0;
    }
    Target_1f47b0 *t = target;
    if (t && t->expected == FUN_001f31a0(key)) {
        t->FUN_001f3400(250);
        return true;
    }
    return false;
}
