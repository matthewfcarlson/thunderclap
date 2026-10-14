// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00207850 @ 0x00207850
class Stream {
public:
    char pad0[0x590];
    int pending;            // 0x590
    char pad594[0xaec - 0x594];
    int blocked;            // 0xaec
    int FUN_002037a0();
    int FUN_00204c10(int mode);
    void FUN_00207080(int n);
    void FUN_00207580(int n, int flag);
    bool FUN_00207850(int flag);
};

bool Stream::FUN_00207850(int flag)
{
    if (blocked == 0 && pending != 0) {
        int n = (char)flag ? FUN_002037a0() : FUN_00204c10(1);
        if (n >= 1) {
            FUN_00207580(n, flag);
            return true;
        }
        pending = 0;
        for (;;) {
            int m = FUN_00204c10(0);
            if (m <= 0)
                break;
            FUN_00207080(m);
        }
        return false;
    }
    return pending != 0;
}
