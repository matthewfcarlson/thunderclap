// STATUS: equivalent (tools/equiv.py level 3: 19889 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_43 @ 0x0031dba0
#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
struct TextureStage {
    char reserved[0x78];
    unsigned int value;
};

}
void pure3d::pddiBaseContext::vfunc_43(hulk_intptr __p0, int index) { unsigned int * result = (unsigned int *)__p0;

    if (index < 8)
        *result = (*(TextureStage * *)&this->f_50)[index].value;
    else
        *result = 0;
}
