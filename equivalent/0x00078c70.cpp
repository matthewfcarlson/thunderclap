// STATUS: equivalent (tools/equiv.py level 3: 769 inputs, branch coverage 6/6)
// CAmbientsManager::vfunc_1 @ 0x00078c70
struct Parser_78c70 {
    void FUN_00336690(const char *name, int *out);
    void FUN_003366f0(const char *name, int index, int *out);
};

union Arg_78c70 {
    Parser_78c70 *parser;
    int count;
};

struct OrientSlot {
    int bits;
    short orient;
    char valid;
    char pad07;
};

class CAmbientsManager {
public:
    virtual void vfunc_0();
    OrientSlot slots[0x320];
    bool vfunc_1(Arg_78c70 arg);
};

bool CAmbientsManager::vfunc_1(Arg_78c70 arg)
{
    Parser_78c70 *parser = arg.parser;
    int orientCount;
    int tmp;
    parser->FUN_00336690("Orients", &arg.count);
    parser->FUN_00336690("BitDef", &orientCount);
    for (int i = 0; i < arg.count && i < orientCount; i++) {
        parser->FUN_003366f0("BitDef", i, &slots[i].bits);
        parser->FUN_003366f0("Orients", i, &tmp);
        slots[i].orient = (short)tmp;
        slots[i].valid = 1;
        if (i + 1 >= 0x320)
            break;
    }
    return true;
}
