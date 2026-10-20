#include "compat/ptr.h"
struct Obj_1f9670 {
    char pad[0x20];
    unsigned short value;
};
struct Sub_1f9670 {
    int Find(int (*cb)(), void*);
};
struct Temp_1f9670 {
    void Cleanup();
};
struct Receiver_1f9670 {
    char pad[0xc6c];
    Sub_1f9670* sub;
    bool Target(int a, int b, int c, int d, unsigned short v);
};
extern int Callback();
bool Receiver_1f9670::Target(int a, int b, int c, int d, unsigned short v) {
    hulk_intptr r = sub->Find(Callback, &a);
    if (!r) {
        ((Temp_1f9670*)&a)->Cleanup();
        return false;
    }
    ((Obj_1f9670*)r)->value = v;
    ((Temp_1f9670*)&a)->Cleanup();
    return true;
}