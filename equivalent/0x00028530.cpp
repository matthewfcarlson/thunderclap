// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00028530 @ 0x00028530
typedef unsigned __int64 Key;
extern "C" int atexit(void (*)());
void FUN_00363b40();
extern Key __cdecl FUN_002672f0(const char*, int, int);

struct NameKey {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};
extern NameKey DAT_004dc128;
extern unsigned int DAT_004dc130;

struct Entry {
    int FUN_00036e70(NameKey* key, int value);
};

struct Owner {
    Entry* FUN_00024280(Key key);
    int FUN_00028530(const char* name, const char* attr, float value);
};

int Owner::FUN_00028530(const char* name, const char* attr, float value)
{
    Entry* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!entry) {
        return 0;
    }
    if ((DAT_004dc130 & 1) == 0) {
        DAT_004dc130 |= 1;
        DAT_004dc128.FUN_0027af00();
        atexit(FUN_00363b40);
    }
    DAT_004dc128.FUN_0027b040(attr);
    return entry->FUN_00036e70(&DAT_004dc128, (int)value);
}
