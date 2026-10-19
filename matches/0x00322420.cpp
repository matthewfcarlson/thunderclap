#include "gen/pure3d.h"

struct Child_322420 {
    void go(int, int);
};
struct Inner_322420 {
    char pad[0x208];
    Child_322420* child;
};

void pure3d::d3dExtVertexProgram::vfunc_1(int a0, int a1) {
    (*(Inner_322420 * *)&this->f_04)->child->go(a0, a1);
}
