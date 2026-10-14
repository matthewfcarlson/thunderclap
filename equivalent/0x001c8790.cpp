// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c8790 @ 0x001c8790
struct Id64_1c8790 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
    void FUN_0027af70(const Id64_1c8790* src);
    Id64_1c8790* FUN_0027b0e0(const char* name);
};
extern char DAT_003f335c[];
extern char DAT_004e23b0;

struct Holder_1c8790 {
    char pad0[0x10];
    Id64_1c8790 id;
    const Id64_1c8790* FUN_001c8060(const char* name, void* table);
    bool FUN_001c8790(const char* name);
};

bool Holder_1c8790::FUN_001c8790(const char* name) {
    Id64_1c8790 tmp;
    tmp.FUN_0027b0e0(DAT_003f335c);
    const Id64_1c8790* found = FUN_001c8060(name, &DAT_004e23b0);
    if (found)
        tmp.FUN_0027af70(found);
    if ((tmp.lo | tmp.hi) != 0) {
        id.FUN_0027af70(&tmp);
        if ((tmp.lo | tmp.hi) != 0) {
            tmp.FUN_0027af50();
            return true;
        }
    }
    tmp.FUN_0027af50();
    return false;
}
