// FUN_001f87e0 @ 0x001f87e0
// (integ4, post; rev5) the found index is below encounterCount when it returns true: checked on every input of the original (post_checked)
#include "compat/pre.h"
#include "compat/hulk_annot.h"
struct Key64 { unsigned int lo, hi; };
struct Ref_1f87e0 { void* vftable; int refs; unsigned int name[2]; int* target; };
struct Request { void* vftable; int refs; Key64 key; };
struct Enc {
    void* vftable;
    int f04;
    void* table;
    char name[0x20];
    int f2c;
    unsigned int key[4];
    int f40, f44, f48, f4c;
    unsigned char b50, b51;
    unsigned short w52;
    int f54;
};
unsigned __int64 FUN_0027b020(const char* s);
struct SlotTable {
    void* vftable;
    int refs;
    unsigned int entityName[2];
    void* items[256];
    int count;
    char pad414[0x44];
    int state;
    char pad45c[0x28c];
    Enc encounters[16];
    int encounterCount;
    bool FUN_001f87e0(Ref_1f87e0* ref, Request* req, unsigned int* outIndex);
};
// post: ge(*arg3, 0) lt(*arg3, *this+0xc68) when ret
bool SlotTable::FUN_001f87e0(Ref_1f87e0* ref, Request* req, unsigned int* outIndex) {
    if (state == 0)
        return false;
    for (int i = 0; i < encounterCount; i++) {
        Enc* slot = &encounters[i];
        unsigned int lo = req->key.lo;
        unsigned int hi = req->key.hi;
        unsigned __int64 id = FUN_0027b020(slot->name);
        if ((unsigned int)id == lo && (unsigned int)(id >> 32) == hi && slot->f40 == *ref->target) {
            *outIndex = i;
            HULK_POST_GE((int)*outIndex, 0);
            HULK_POST_LT((int)*outIndex, encounterCount);
            return true;
        }
    }
    return false;
}
