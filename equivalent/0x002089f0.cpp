// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 14/14)
// FUN_002089f0 @ 0x002089f0
class Pump_2089f0 {
public:
    void FUN_002089f0();
    void FUN_00207410();
    void FUN_00204e40();
    char FUN_00207850(char flag);
    char FUN_00208920();

    char pad0[0x9a8];
    int busy;
    char pad1[0xaf3 - 0x9ac];
    char pending;
    char dirty;
    char locked;
    char pad2[0xafc - 0xaf6];
    int tick;
};

int FUN_00267f80();

void Pump_2089f0::FUN_002089f0()
{
    tick = FUN_00267f80();
    if (pending)
        FUN_00207410();
    if (busy <= 0 && !locked) {
        if (dirty) {
            FUN_00204e40();
            dirty = 0;
        }
        char again = 0;
        for (;;) {
            FUN_00207410();
            char progressed = FUN_00207850(again);
            if (FUN_00208920()) {
                again = 1;
                continue;
            }
            if (!again)
                break;
            again = progressed;
            if (!progressed)
                break;
        }
    }
    tick = 0;
}
