#include "gen/hulkfight.h"

struct A_135ba0 {
    A_135ba0* get();
    void init();
    int check();
};
struct Result_135ba0 {
    void apply(int, int);
};
struct FlyingAttackAction_nv_135ba0 {
    void mid();
};

void hulkfight::motion::FlyingAttackAction::vfunc_4() {
    A_135ba0* edi = (*(A_135ba0 * *)&this->f_20)->get();
    edi->init();
    ((FlyingAttackAction_nv_135ba0*)this)->mid();
    int result = edi->check();
    if (result)
        ((Result_135ba0*)result)->apply(this->f_24, 0);
}
