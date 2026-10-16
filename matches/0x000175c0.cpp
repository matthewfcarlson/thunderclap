#include "gen/global.h"

struct Obj_175c0 {
    Obj_175c0* first();
    Obj_175c0* second();
    void third(int);
    void fourth(int);
};
struct CAction_175c0 {
    virtual void q();
    char pad[0x18];
    Obj_175c0* mObj;
};

bool CInvulnerableAction::vfunc_6(int x) {
    Obj_175c0* a = (*(Obj_175c0 * *)&this->f_1c)->first();
    Obj_175c0* b = a->second();
    b->third(1);
    b->fourth(1);
    return true;
}
