#include "gen/owners.h"
class Sub_247b30 {
  public:
    int x;
};
class Obj_247b30 {
  public:
    int a0;
    int a4;
    Sub_247b30* sub;
    int aC;
    char pad10[8];
    int a18;
    int a1C;
    int a20;
    char pad24[4];
    int a28;
};
extern "C" void __cdecl FUN_00247b30(int p1, Obj_247b30* p2, unsigned int* p3, int* p4) {
    p2->aC = 5;
    if (p3) {
        p2->a18 = p3[0];
        p2->a1C = p3[1];
    } else {
        p2->a18 = 0;
        p2->a1C = 0;
    }
    p2->a28 = 0;
    p2->a20 = 0;
    if (p4) {
        int t = ((owners::Object_25d3e0 *)(p2->sub))->FUN_0025d3e0();
        if (t == 1 || t == 2 || t == 3 || t == 4)
            ((owners::Obj_25d3f0 *)(p2->sub))->FUN_0025d3f0(p4);
        else
            *p4 = 0;
    }
}