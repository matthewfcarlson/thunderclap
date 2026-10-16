#include "gen/hulkfight.h"

typedef unsigned int u32_194d90;
struct Obj_194d90 {
    char pad[0x20];
    Obj_194d90* HelperA();
    Obj_194d90* HelperB();
    void DoWork(int, u32_194d90, u32_194d90);
};

bool hulkfight::motion::MissilePunchAction::vfunc_3(int a, int b) {
    if (!(*(Obj_194d90 * *)&this->f_20))
        return (bool)(0);
    Obj_194d90* x = (*(Obj_194d90 * *)&this->f_20)->HelperA();
    x = x->HelperB();
    Obj_194d90* y = (*(Obj_194d90 * *)&this->f_1c);
    x->DoWork(1, *(u32_194d90*)((char*)y + 0x14), *(u32_194d90*)((char*)y + 0x18));
    return (bool)(1);
}
