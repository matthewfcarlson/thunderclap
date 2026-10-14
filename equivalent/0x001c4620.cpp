// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001c4620 @ 0x001c4620
struct Slot {
    char flag;
    char pad1[3];
    float f4;
    int f8;
    int fc;
    void FUN_001c4580(int arg);
    void clear() {
        f8 = 0;
        f4 = 0;
        fc = 0;
        flag = 0;
    }
};
struct Pair {
    char pad0[0x14];
    Slot b;
    Slot a;
    void FUN_001c4620(int arg);
};

void Pair::FUN_001c4620(int arg)
{
    if (a.flag || b.flag) {
        a.FUN_001c4580(arg);
        b.FUN_001c4580(arg);
        if (!a.flag && !b.flag && (a.f4 == 0.0f || b.f4 == 0.0f)) {
            a.clear();
            b.clear();
        }
    }
}
