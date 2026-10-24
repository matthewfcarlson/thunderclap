#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_00433424[];
extern "C" char DAT_004334b4[];
void Cleanup(void*);
void __stdcall Release(void*);
struct d3dPrimBuffer_nv_327050 {
    void BaseDestroy();
};

void pure3d::d3dPrimBuffer::FUN_00327050() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004334b4);
    if ((*(void * *)&this->f_2c)) {
        Cleanup((*(void * *)&this->f_2c));
        Release((*(void * *)&this->f_2c));
    }
    if ((*(void * *)&this->f_30)) {
        Cleanup((*(void * *)&this->f_30));
        Release((*(void * *)&this->f_30));
    }
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433424);
    ((d3dPrimBuffer_nv_327050*)this)->BaseDestroy();
}
