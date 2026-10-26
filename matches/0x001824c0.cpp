#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Helper_1824c0 {
    void* f();
    void* g();
};

bool hulkfight::motion::ShieldArcAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    if ((*(Helper_1824c0 * *)&this->f_20)) {
        void* a = (*(Helper_1824c0 * *)&this->f_20)->f();
        void* b = ((Helper_1824c0*)a)->g();
        *(int*)((char*)b + 0x628) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    }
    return false;
}
