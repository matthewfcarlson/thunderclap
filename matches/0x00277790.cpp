#include "gen/core.h"

void core::CementLibrary::vfunc_0() {
    struct Sub {
        virtual void first();
        virtual void second();
        int count;
    };
    Sub* p = (Sub*)((char*)this + 0x10);
    p->first();
    ++p->count;
    p->second();
}
