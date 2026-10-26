#include "decls/data/game/global.h"
// data: gZero_354c0 = DAT_003f32e0

struct Inner_354c0 {
    char pad[0x10];
    void* Get();
    float Calc();
};
struct Owner_354c0 {
    char pad[0x10];
    Inner_354c0* m;
    float f();
};
float Owner_354c0::f() {
    Inner_354c0* p = m;
    void* q = p->Get();
    if (!q)
        return DAT_003f32e0;
    return ((Inner_354c0*)((char*)q + 0x10))->Calc();
}