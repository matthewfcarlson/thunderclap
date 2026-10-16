#include "gen/hulkfight.h"

struct ObjC_194dd0;
struct ObjB_194dd0 {
    ObjC_194dd0* g();
};
struct ObjA_194dd0 {
    ObjB_194dd0* f();
};
struct ObjC_194dd0 {
    void h(int, int, int);
};

void hulkfight::motion::MissilePunchAction::vfunc_4() {
    if ((*(void * *)&this->f_20)) {
        ObjC_194dd0* c = ((ObjA_194dd0*)(*(void * *)&this->f_20))->f()->g();
        c->h(0, 0, 0);
    }
}
