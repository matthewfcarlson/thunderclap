#include "gen/global.h"

struct C_15440 {
    void run(void*, int, float);
};
struct B_15440 {
    C_15440* getC();
};
struct A_15440 {
    B_15440* get();
};

void CGrappleLocoStrafe4Action::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        B_15440* b = (*(A_15440 * *)&this->f_1c)->get();
        C_15440* c = b->getC();
        if (c)
            c->run((*(void * *)&this->f_24), 0, -1.0f);
    }
}
