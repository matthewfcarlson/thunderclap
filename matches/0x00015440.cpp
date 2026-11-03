#include "gen/global.h"
#include "gen/owners.h"

struct C_15440 {
    void run(void*, int, float);
};
struct B_15440 {
    C_15440* getC();
};
struct A_15440 {
};

void CGrappleLocoStrafe4Action::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        B_15440* b = ((B_15440 *)((owners::Object_592a0 *)((*(A_15440 * *)&this->f_1c)))->FUN_000592a0());
        C_15440* c = b->getC();
        if (c)
            c->run((*(void * *)&this->f_24), 0, -1.0f);
    }
}
