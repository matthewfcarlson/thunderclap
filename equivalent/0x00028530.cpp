// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00028530 @ 0x00028530
#include "decls/address.h"
typedef unsigned __int64 Key_28530;
extern "C" int atexit(void (*)());
void FUN_00363b40();

struct NameKey_28530 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};
extern NameKey_28530 DAT_004dc128;
extern unsigned int DAT_004dc130;

struct Entry_28530 {
    int FUN_00036e70(NameKey_28530* key, int value);
};

struct Owner_28530 {
    Entry_28530* FUN_00024280(Key_28530 key);
    int FUN_00028530(const char* name, const char* attr, float value);
};

int Owner_28530::FUN_00028530(const char* name, const char* attr, float value)
{
    Entry_28530* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
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
