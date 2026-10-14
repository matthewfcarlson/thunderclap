// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 10/10)
// FUN_0003eca0 @ 0x0003eca0
// FUN_0003eca0: look up a named value by key, -1 when absent
struct Key {
    int lo;
    int hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

struct Entry {
    int lo;
    int hi;
    float value;
    int pad;
};

extern Key DAT_004dc2c8;
extern unsigned int DAT_004dc2d0;

void __cdecl FUN_00363ba0();
extern "C" int __cdecl atexit(void (__cdecl *fn)());

class Table {
public:
    char pad00[0x1ba8];
    Entry entries[14];
    int count;

    float FUN_0003eca0(const char *name);
};

float Table::FUN_0003eca0(const char *name)
{
    if (!(DAT_004dc2d0 & 1)) {
        DAT_004dc2d0 |= 1;
        DAT_004dc2c8.FUN_0027af00();
        atexit(FUN_00363ba0);
    }
    DAT_004dc2c8.FUN_0027b040(name);
    for (int i = 0; i < count; i++) {
        if (entries[i].lo == DAT_004dc2c8.lo && entries[i].hi == DAT_004dc2c8.hi)
            return entries[i].value;
    }
    return -1.0f;
}
