// Same code shape as 0x000906f0 (propagated; names are from that function)
#include "gen/owners.h"
struct Entry_90df0 {
    void Act();
};
void owners::C_90df0::FUN_00090df0(int x) {
    int i = Find(x);
    if (i != -1)
        ((Entry_90df0*)((char*)this + i * 64))->Act();
}