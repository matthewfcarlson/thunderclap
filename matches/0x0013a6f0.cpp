// Same code shape as 0x0013a5c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
struct A_13a6f0 {
};
struct B_13a6f0 {
    int Check();
};
struct C_13a6f0 {
    bool Finish(void*);
};
struct Target_13a6f0 {
    char pad[0x20];
    A_13a6f0* field20;
    void* field24;
    bool Run();
};
bool Target_13a6f0::Run() {
    void* value = ((void *)((owners::Object_592a0 *)field20)->FUN_000592a0());
    hulk_intptr result = ((B_13a6f0*)value)->Check();
    if (!result)
        return true;
    return ((C_13a6f0*)result)->Finish(field24);
}