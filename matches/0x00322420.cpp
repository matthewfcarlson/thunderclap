#include "gen/pure3d.h"
#include "gen/owners.h"

struct Child_322420 {
};
struct Inner_322420 {
    char pad[0x208];
    Child_322420* child;
};

void pure3d::d3dExtVertexProgram::vfunc_1(int a0, int a1) {
    ((owners::Registry_329320 *)((*(Inner_322420 * *)&this->f_04)->child))->FUN_00329320((const char *)(hulk_uintptr)(int)a0, (unsigned int)a1);
}
