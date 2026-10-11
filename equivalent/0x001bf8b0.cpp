// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 31/32, incomplete)
// FUN_001bf8b0 @ 0x001bf8b0
struct Tracker {
    int FUN_000f7240(int a, int b);
};

class Handler {
public:
    void FUN_001bf8b0();
    void FUN_001bea80();
    void FUN_001bec90();
    void FUN_001be4b0(int v);
    void FUN_001be7f0(int v);

    char pad0[0xc];
    char active;
    char forced;
    char pad1[2];
    int keyA;
    int keyB;
    char pad2[0x20 - 0x18];
    int mode;
    char enabled;
    char pad3[0x34 - 0x25];
    Tracker *trackA;
    Tracker *trackB;
    char pad4[0x50 - 0x3c];
    int pending;
};

void Handler::FUN_001bf8b0()
{
    if (enabled && trackA && trackB) {
        if (mode == 0)
            FUN_001bea80();
        else if (mode == 1)
            FUN_001bec90();
    }

    if (active && (forced || pending)) {
        int r;
        if (!trackA && !trackB)
            return;
        bool found = false;
        if (trackA) {
            r = trackA->FUN_000f7240(keyA, keyB);
            found = (r != -1);
        }
        if (!found) {
            if (!trackB)
                return;
            r = trackB->FUN_000f7240(keyA, keyB);
            if (r == -1)
                return;
        }
        if (mode == 0)
            FUN_001be4b0(r);
        else if (mode == 1)
            FUN_001be7f0(r);
    }
}
