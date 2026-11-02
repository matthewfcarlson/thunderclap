#include "compat/ptr.h"
// a..d: the 16-byte name key passed by value (the callers' Key: 8-byte name + index bytes).
struct Key_1f9670 {
    int w[4];
};
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
    bool Target(Key_1f9670 a, unsigned short v);
};
extern int Callback();
bool Receiver_1f9670::Target(Key_1f9670 a, unsigned short v) {
    hulk_intptr r = sub->Find(Callback, &a);
    if (!r) {
        ((Temp_1f9670*)&a)->Cleanup();
        return false;
    }
    ((Obj_1f9670*)r)->value = v;
    ((Temp_1f9670*)&a)->Cleanup();
    return true;
}