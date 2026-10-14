// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 7/8, incomplete)
// FUN_00208040 @ 0x00208040
struct Sink {
    void FUN_00086310();
};

struct Table {
    char pad[0x588];
    Sink *sink;
    // equiv-conv absent: plain thiscall members
    unsigned short *FUN_00204060(int a, int b);
    void FUN_00207e80();
    void FUN_00207a00(unsigned short *entry);
    bool FUN_00208040(int a, int b);
};

extern int DAT_004e5a90;

bool Table::FUN_00208040(int a, int b)
{
    unsigned short *entry = FUN_00204060(a, b);
    sink->FUN_00086310();
    if (entry == 0) {
        entry = FUN_00204060(0, b);
        if (entry == 0)
            return false;
    }
    bool wasEmpty = false;
    DAT_004e5a90 = DAT_004e5a90 + 1;
    if (*entry == 0) {
        FUN_00207e80();
        wasEmpty = true;
    }
    FUN_00207a00(entry);
    return wasEmpty;
}
