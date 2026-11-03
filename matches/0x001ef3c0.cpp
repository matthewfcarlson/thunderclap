#include "gen/owners.h"
struct Entry_1ef3c0 {
    char pad[8];
    void Init(void*);
};
struct Helper_1ef3c0 {
    void Finish();
};
void owners::Owner_1ef3c0::FUN_001ef3c0(void* a, void* b) {
    if (count < 8) {
        ((Entry_1ef3c0*)((char*)this + count * 8))->Init(&a);
        ++count;
    }
    ((Helper_1ef3c0*)&a)->Finish();
}