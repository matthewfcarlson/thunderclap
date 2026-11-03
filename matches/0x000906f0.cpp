#include "gen/owners.h"
struct Entry_906f0 {
    void Act();
};
void owners::C_906f0::FUN_000906f0(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry_906f0*)((char*)this + i * 64))->Act();
}