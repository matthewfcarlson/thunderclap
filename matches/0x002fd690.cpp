#include "compat/ptr.h"
struct Block_2fd690 {
    unsigned int v[16];
};
extern "C" void * __fastcall FUN_0030edf0(void *);
void* __fastcall FnB(void* p);
struct Target_2fd690 {
    unsigned int first;
    char pad[28];
    Block_2fd690 data;
    void Init(unsigned int arg);
};
void Target_2fd690::Init(unsigned int arg) {
    first = arg;
    void* p = FnB(FUN_0030edf0((void *)(hulk_uintptr)(unsigned int)arg));
    data = *(Block_2fd690*)p;
}
