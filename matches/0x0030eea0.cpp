// Same code shape as 0x0030ee70 (propagated; names are from that function)
#include "gen/owners.h"
struct B_30eea0 {
};
struct A_30eea0 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
void A_30eea0::Target(int x) {
    Init();
    ((owners::Obj_30f140 *)(((B_30eea0*)((char*)this + 0x68))))->FUN_0030f140((owners::Obj_30f140 *)(hulk_uintptr)(int)x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}