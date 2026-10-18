// FUN_000285b0 @ 0x000285b0
#include "decls/address.h"
#include "decls/data/game/unknown.h"
typedef unsigned __int64 Key_285b0;
extern "C" int atexit(void (*)());
void FUN_00363b50();

struct NameKey_285b0 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

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
    if (((*(unsigned int*)&DAT_004dc140) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc140) |= 1;
        (*(NameKey_285b0*)&DAT_004dc138).FUN_0027af00();
        atexit(FUN_00363b50);
    }
    (*(NameKey_285b0*)&DAT_004dc138).FUN_0027b040(attr);
    return entry->FUN_00036e40(((NameKey_285b0*)&DAT_004dc138));
}
