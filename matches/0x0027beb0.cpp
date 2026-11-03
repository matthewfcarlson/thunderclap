#include "gen/owners.h"
struct Partition_27beb0 {
    virtual void unused();
    char pad[12];
    int value;
    Partition_27beb0() : value(0) {}
};
struct Limb : Partition_27beb0 {
    char extra[20];
    virtual void other();
};
struct Wrapper {
    void FUN_0027beb0(void* arg);
};
void Wrapper::FUN_0027beb0(void* arg) {
    Limb limb;
    ((owners::Buffer_27be00 *)this)->FUN_0027be00((hulk_uintptr)arg, (hulk_intptr)(Limb *)(&limb));
}