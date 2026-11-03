#include "gen/hulkfight.h"
#include "gen/owners.h"

struct ObjC_194dd0;
struct ObjB_194dd0 {
    ObjC_194dd0* g();
};
struct ObjA_194dd0 {
};
struct ObjC_194dd0 {
    void h(int, int, int);
};

void hulkfight::motion::MissilePunchAction::vfunc_4() {
    if ((*(void * *)&this->f_20)) {
        ObjC_194dd0* c = ((ObjB_194dd0 *)((owners::Object_592a0 *)(((ObjA_194dd0*)(*(void * *)&this->f_20))))->FUN_000592a0())->g();
        c->h(0, 0, 0);
    }
}
