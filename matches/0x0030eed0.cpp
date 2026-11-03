// Same code shape as 0x0030ee70 (propagated; names are from that function)
#include "gen/owners.h"
struct B_30eed0 {
};
struct A_30eed0 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
void A_30eed0::Target(int x) {
    Init();
    ((owners::Target_22be40 *)(((B_30eed0*)((char*)this + 0x68))))->FUN_0022be40((const int *)(hulk_uintptr)(int)x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}