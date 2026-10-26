// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 13/14, incomplete)
// core::ControllerSystemXBox::vfunc_5 @ 0x00269470
#include "compat/ptr.h"
#include "gen/core.h"

namespace core {
struct ControllerDevice {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual const char* vfunc_6();
    char padding[0x4a0 - 4];
};

}
void* core::ControllerSystemXBox::vfunc_5(hulk_intptr __p0) { const char * name = (const char *)__p0;

    for (unsigned i = 0; i < 4; ++i) {
        ControllerDevice* device = &(*(ControllerDevice (*)[4])&this->f_20)[i];
        if (!device->vfunc_3()) continue;
        const char* candidate = device->vfunc_6();
        const char* requested = name;
        while (*candidate && *candidate == *requested) {
            ++candidate;
            ++requested;
        }
        if (*candidate == *requested) return (void*)(device);
    }
    return (void*)(0);
}
