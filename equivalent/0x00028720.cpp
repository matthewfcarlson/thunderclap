// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00028720 @ 0x00028720
extern "C" int atexit(void (*)());
void FUN_00363b70();

struct NameKey {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

struct Registry {
    void FUN_00065ee0(NameKey* key);
};

Registry* FUN_000678d0();
extern NameKey DAT_004dc158;
extern unsigned int DAT_004dc160;

// Looks up the static name key in the registry.
void __stdcall FUN_00028720(const char* name, int unused)
{
    if ((DAT_004dc160 & 1) == 0) {
        DAT_004dc160 |= 1;
        DAT_004dc158.FUN_0027af00();
        atexit(FUN_00363b70);
    }
    DAT_004dc158.FUN_0027b040(name);
    NameKey key = DAT_004dc158;
    FUN_000678d0()->FUN_00065ee0(&key);
}
