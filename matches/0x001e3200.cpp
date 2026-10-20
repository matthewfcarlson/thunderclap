#include "gen/global.h"
typedef unsigned int U_1e3200;
struct CSPManager_nv_1e3200 {
    U_1e3200 g(U_1e3200);
};
struct C_1e3200 {
    U_1e3200 h(U_1e3200, U_1e3200, U_1e3200);
};
struct A_1e3200 {
    U_1e3200 pad[2];
    U_1e3200 f(U_1e3200, U_1e3200, U_1e3200);
};
U_1e3200 A_1e3200::f(U_1e3200 a, U_1e3200 b, U_1e3200 c) {
    U_1e3200 x = ((CSPManager_nv_1e3200*)(((CSPManager*)this)))->g(a);
    return ((C_1e3200*)this)->h(x, b, c);
}