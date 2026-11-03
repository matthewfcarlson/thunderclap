#include "gen/owners.h"
typedef unsigned char u8_1f9130;
typedef unsigned int u32_1f9130;
class Ret_1f9130 {
  public:
};
extern "C" Ret_1f9130* FUN_001d4c90();
char owners::Obj_1f9130::FUN_001f9130(u32_1f9130 p1, u32_1f9130 p2, u32_1f9130 p3, u32_1f9130 p4, u32_1f9130 p5, u32_1f9130 p6, u32_1f9130 p7, u32_1f9130 p8, u32_1f9130 p9, u8_1f9130 p10) {
    char r = Check(p1);
    if (r) {
        a = p2;
        b = p3;
        c = p4;
        d = p5;
        e = p6;
        f = p7;
        g = p8;
        Ret_1f9130* o = FUN_001d4c90();
        ((owners::Obj_1d1900 *)o)->FUN_001d1900((hulk_intptr)h);
        h = p9;
        flag = p10;
    }
    return r;
}