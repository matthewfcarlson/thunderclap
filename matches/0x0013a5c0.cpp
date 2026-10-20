#include "compat/ptr.h"
struct A_13a5c0 {
    void* Get();
};
struct B_13a5c0 {
    int Check();
};
struct C_13a5c0 {
    bool Finish(void*);
};
struct Target_13a5c0 {
    char pad[0x20];
    A_13a5c0* field20;
    void* field24;
    bool Run();
};
bool Target_13a5c0::Run() {
    void* value = field20->Get();
    hulk_intptr result = ((B_13a5c0*)value)->Check();
    if (!result)
        return true;
    return ((C_13a5c0*)result)->Finish(field24);
}