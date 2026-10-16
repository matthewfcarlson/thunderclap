#include "gen/hulkfight.h"

typedef unsigned char u8;
struct Obj_10dee0 {
    char pad[0x14];
    u8 flag;
};
struct H {
    H* f1();
    void f2();
    H* f3();
    void f4();
};
H* g();

bool hulkfight::ai::TokenSupressAction::vfunc_5(int a, int b) {
    if (!(*(H * *)&this->f_20))
        return false;
    (*(H * *)&this->f_20)->f1()->f2();
    if ((*(Obj_10dee0 * *)&this->f_1c)->flag)
        g()->f4();
    return true;
}
