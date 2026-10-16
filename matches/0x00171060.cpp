#include "gen/hulkfight.h"

struct Thing_171060 {
    int pad[4];
    int value;
};
struct ObjC_171060 {
    void run(int);
};
struct ObjB_171060 {
    ObjC_171060* run();
};
struct ObjA_171060 {
    ObjB_171060* run();
};

bool hulkfight::motion::LocomotionStateAction::vfunc_5(int param, int unused) {
    if (param)
        return true;
    ObjB_171060* b = (*(ObjA_171060 * *)&this->f_20)->run();
    ObjC_171060* c = b->run();
    c->run((*(Thing_171060 * *)&this->f_1c)->value);
    return false;
}
