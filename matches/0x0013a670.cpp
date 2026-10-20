// Same code shape as 0x0013a5c0 (propagated; names are from that function)
#include "compat/ptr.h"
struct A_13a670 {
    void* Get();
};
struct B_13a670 {
    int Check();
};
struct C_13a670 {
    bool Finish(void*);
};
struct Target_13a670 {
    char pad[0x20];
    A_13a670* field20;
    void* field24;
    bool Run();
};
bool Target_13a670::Run() {
    void* value = field20->Get();
    hulk_intptr result = ((B_13a670*)value)->Check();
    if (!result)
        return true;
    return ((C_13a670*)result)->Finish(field24);
}