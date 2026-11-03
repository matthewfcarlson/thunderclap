#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/global.h"

struct Obj_1822d0 {
    Obj_1822d0* a();
    Obj_1822d0* b();
    unsigned int d(int);
};
struct State_1822d0 {
    char pad[0x10];
    int value;
};

bool hulkfight::motion::PropDropAction::vfunc_3(hulk_intptr x, hulk_intptr y) {
    if ((*(Obj_1822d0 * *)&this->f_20)) {
        Obj_1822d0* p = (*(Obj_1822d0 * *)&this->f_20)->a();
        p = p->b();
        int n = (*(State_1822d0 * *)&this->f_1c)->value;
        if (n < 0) {
            ((unsigned int)((::CCharacter *)p)->FUN_00040170());
            return false;
        }
        p->d(n);
    }
    return false;
}
