// FUN_001fa7d0 @ 0x001fa7d0
// (integ4, post; rev5) a found encounter's index from the stubbed 0x001f87e0: its postcondition (index below encounterCount when it returns true) draws it in range on both sides: the encounter it selects is the same one (a fuzzed index fell outside the array: false layout)
#include "tree_prelude.h"
#include "compat/hulk_annot.h"
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
    void FUN_001f9810(int value);
};
struct Gen {
    void* vftable;
    int refs;
    unsigned int entityName[2];
    void* items[256];
    int count HULK_RANGE(0, 256);   // the entries: 0x001f8fe0 / 0x001f8f70 append, at most 256
    char pad414[0x44];
    int state;
    char pad45c[0x28c];
    Enc encounters[16];
    int encounterCount HULK_RANGE(0, 16);   // 0x001fa1c0 appends below 16
};
// 0x001f87e0 FUN_001f87e0 (the callee's postcondition as its tree block states it: tools/equiv64.py post_contracts)
// post: ge(*arg3, 0) lt(*arg3, *this+0xc68) when ret
struct Object : Gen {
    bool FUN_001f9040(void* input, void* item);
    bool FUN_001f87e0(void* input, void* item, int* index);
    void FUN_001fa1c0(void* input, void* item);
    void FUN_001fa3a0(int index);
    bool FUN_001fa7d0(hulk_intptr input, int value);
};
bool Object::FUN_001fa7d0(hulk_intptr input, int value) {
    if (!input || state != 2) return false;
    bool result = false;
    for (int i = 0; i < count; ++i) {
        int index = -1;
        bool first = FUN_001f9040((void*)input, items[i]);
        bool second = FUN_001f87e0((void*)input, items[i], &index);
        if (first) {
            if (second) encounters[index].FUN_001f9810(value);
            else FUN_001fa1c0((void*)input, items[i]);
            result = true;
        } else if (second) FUN_001fa3a0(index);
    }
    return result;
}
