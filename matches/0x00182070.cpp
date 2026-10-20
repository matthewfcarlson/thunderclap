#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct A_182070 {
    void* f();
};
struct B_182070 {
    int f();
};
struct C_182070 {
    int f(int);
};
struct D {
    int f(int*);
};

bool hulkfight::motion::PropSetStateByNameAction::vfunc_5(int __p0, int __p1) { unsigned int param = (unsigned int)__p0;

    if (param == 0 && (*(A_182070 * *)&this->f_20) != 0) {
        A_182070* p = (A_182070*)(*(A_182070 * *)&this->f_20)->f();
        hulk_intptr x = ((B_182070*)p)->f();
        int index = (*(int * *)&this->f_1c)[4];
        if (x != 0) {
            if (index < 0)
                x = *(int*)((char*)x + 0x128);
            else {
                if (index >= 8)
                    return false;
                x = ((C_182070*)x)->f(index);
            }
            if (x != 0)
                ((D*)x)->f((int*)((char*)(*(int * *)&this->f_1c) + 0x18));
        }
    }
    return false;
}
