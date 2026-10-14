// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000286b0 @ 0x000286b0
extern "C" int atexit(void (*)());
void FUN_00363b60();

struct NameKey {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

struct Registry {
    void FUN_00066a10(NameKey* key);
};

Registry* FUN_000678d0();
extern NameKey DAT_004dc148;
extern unsigned int DAT_004dc150;

// Looks up the static name key in the registry.
void __stdcall FUN_000286b0(int unused, const char* name)
{
    if ((DAT_004dc150 & 1) == 0) {
        DAT_004dc150 |= 1;
        DAT_004dc148.FUN_0027af00();
        atexit(FUN_00363b60);
    }
    DAT_004dc148.FUN_0027b040(name);
    NameKey key = DAT_004dc148;
    FUN_000678d0()->FUN_00066a10(&key);
}
