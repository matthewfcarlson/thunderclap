#include "compat/ptr.h"
typedef unsigned int U_2306c0;
struct Obj_2306c0 {
    U_2306c0 a, b, c, d;
    void go(hulk_uintptr);
};
struct H {
    void run(Obj_2306c0*, U_2306c0*);
};
void Obj_2306c0::go(hulk_uintptr arg) {
    U_2306c0 temp[4];
    ((H*)arg)->run(this, temp);
    a = temp[0];
    b = temp[1];
    c = temp[2];
    d = temp[3];
}