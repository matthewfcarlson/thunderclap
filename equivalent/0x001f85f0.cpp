// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f85f0 @ 0x001f85f0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct Name {
    int lo, hi;
    ~Name() throw();
    bool FUN_0027af90(const Name *other) throw();
};
struct Entry_1f85f0 {
    char pad0[8];
    Name key;
};
struct Table_1f85f0 {
    char pad0[0x10];
    Entry_1f85f0 *entries[0x100];
    int count;
    char pad414[0x458 - 0x414];
    int enabled;
    int FUN_001f85f0(Name name);
};

int Table_1f85f0::FUN_001f85f0(Name name)
{
    if (enabled == 0)
        return -1;
    for (int i = 0; i < count; i++) {
        if (entries[i]->key.FUN_0027af90(&name))
            return i;
    }
    return -1;
}
