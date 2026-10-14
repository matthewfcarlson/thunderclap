// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 10/10)
// FUN_00045f90 @ 0x00045f90
extern "C" int atexit(void (*)());
void FUN_00363bd0();

struct NameKey_45f90 {
    unsigned lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};
extern NameKey_45f90 DAT_004dc330;
extern unsigned int DAT_004dc338;

struct Entry_45f90 {
    unsigned lo, hi;
    float value;
    int pad;
};

class Table_45f90 {
public:
    char pad0[0x480];
    Entry_45f90 entries[14];
    int count;
    float FUN_00045f90(const char *name);
};

float Table_45f90::FUN_00045f90(const char *name)
{
    if ((DAT_004dc338 & 1) == 0) {
        DAT_004dc338 |= 1;
        DAT_004dc330.FUN_0027af00();
        atexit(FUN_00363bd0);
    }
    DAT_004dc330.FUN_0027b040(name);
    for (int i = 0; i < count; i++) {
        if (entries[i].lo == DAT_004dc330.lo && entries[i].hi == DAT_004dc330.hi)
            return entries[i].value;
    }
    return -1.0f;
}
