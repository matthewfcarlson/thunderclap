#include "gen/pure3d.h"

struct State_331b60 {
    char pad[0xe4];
    int value;
};
extern int globalFlags;
extern int globalState_331b60;

void pure3d::d3dSpheremapVertexShader::vfunc_13() {
    if ((*(struct State_331b60 * *)&this->f_14)->value != 1) {
        (*(struct State_331b60 * *)&this->f_14)->value = 1;
        globalFlags |= 0x800;
        globalState_331b60 = 1;
    }
}
