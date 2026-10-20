// Same code shape as 0x0013a280 (propagated; names are from that function)
#include "compat/ptr.h"
typedef unsigned int u32_143790;
extern u32_143790 vtable_143790;
struct Sub_143790 {
    void Init();
};
struct T_143790 {
    char pad[0x28];
    void Run();
};
struct Base_143790 {
    void Finish();
};
void T_143790::Run() {
    *(hulk_uintptr*)this = (hulk_uintptr)&vtable_143790;
    ((Sub_143790*)((char*)this + 0x28))->Init();
    ((Sub_143790*)((char*)this + 0x18))->Init();
    ((Base_143790*)this)->Finish();
}