#include "gen/hulkfight.h"

struct Obj_1822d0 {
    Obj_1822d0* a();
    Obj_1822d0* b();
    unsigned int c();
    unsigned int d(int);
};
struct State_1822d0 {
    char pad[0x10];
    int value;
};

bool hulkfight::motion::PropDropAction::vfunc_3(int x, int y) {
    if ((*(Obj_1822d0 * *)&this->f_20)) {
        Obj_1822d0* p = (*(Obj_1822d0 * *)&this->f_20)->a();
        p = p->b();
        int n = (*(State_1822d0 * *)&this->f_1c)->value;
        if (n < 0) {
            p->c();
            return false;
        }
        p->d(n);
    }
    return false;
}
