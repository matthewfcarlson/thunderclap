// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000285b0 @ 0x000285b0
typedef unsigned __int64 Key_285b0;
extern "C" int atexit(void (*)());
void FUN_00363b50();
extern Key_285b0 __cdecl FUN_002672f0(const char*, int, int);

struct NameKey_285b0 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};
extern NameKey_285b0 DAT_004dc138;
extern unsigned int DAT_004dc140;

struct Entry_285b0 {
    int FUN_00036e40(NameKey_285b0* key);
};

struct Owner_285b0 {
    Entry_285b0* FUN_00024280(Key_285b0 key);
    int FUN_000285b0(const char* name, const char* attr);
};

int Owner_285b0::FUN_000285b0(const char* name, const char* attr)
{
    Entry_285b0* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        return 0;
    }
    if ((DAT_004dc140 & 1) == 0) {
        DAT_004dc140 |= 1;
        DAT_004dc138.FUN_0027af00();
        atexit(FUN_00363b50);
    }
    DAT_004dc138.FUN_0027b040(attr);
    return entry->FUN_00036e40(&DAT_004dc138);
}
