#include "gen/owners.h"
struct Entry_1cbcb0 {
    void Set(int, int);
    void Reset(int);
    void Finish(int);
};
bool owners::Owner_1cbcb0::FUN_001cbcb0(int arg) {
    int i = 0;
    Entry_1cbcb0* entry = (Entry_1cbcb0*)((char*)this + 0x24);
    do {
        if (active[i] && i >= 0 && i < 0x18) {
            entry->Set(1, arg);
            entry->Reset(0);
            entry->Finish(1);
            active[i] = 0;
        }
        ++i;
        entry = (Entry_1cbcb0*)((char*)entry + 0x28);
    } while ((unsigned int)i < 0x18);
    return true;
}