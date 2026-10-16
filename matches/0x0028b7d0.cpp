#include "gen/pure3d.h"

struct Obj_28b7d0 {
    virtual void v0();
    virtual void Release();
};
void __cdecl Free(void*);
inline void Del(Obj_28b7d0*& p) {
    if (p) {
        p->Release();
        p = 0;
    }
}

void pure3d::EntityChannel::vfunc_1() {
    for (unsigned i = 0; i < this->f_10; i++) {
        Obj_28b7d0** slot = (*(Obj_28b7d0 ** *)&this->f_18) + i;
        Obj_28b7d0* o = *slot;
        if (o) {
            o->Release();
            *slot = 0;
        }
    }
    if ((*(Obj_28b7d0 * *)&this->f_0c) == 0)
        Free((*(Obj_28b7d0 ** *)&this->f_18));
    (*(Obj_28b7d0 ** *)&this->f_18) = 0;
    if ((*(Obj_28b7d0 * *)&this->f_0c) == 0) {
        Free((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
    } else {
        Del((*(Obj_28b7d0 * *)&this->f_0c));
        (*(void * *)&this->f_14) = 0;
    }
}
