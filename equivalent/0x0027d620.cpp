// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::prop::StateProp::vfunc_12 @ 0x0027d620
#include "gen/pure3d.h"

namespace pure3d { namespace prop {
struct Source {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12();
    char pad[0x10];
    unsigned int position[6];
    unsigned int bounds[4];
};

}}
void pure3d::prop::StateProp::vfunc_12() {
    (*(Source * *)&this->f_9c)->vfunc_12();
    Source *s = (*(Source * *)&this->f_9c);
    for (int i = 0; i < 6; ++i) (*(unsigned int (*)[6])&this->f_14)[i] = s->position[i];
    s = (*(Source * *)&this->f_9c);
    for (int i = 0; i < 4; ++i) (*(unsigned int (*)[4])&this->f_2c)[i] = s->bounds[i];
}
