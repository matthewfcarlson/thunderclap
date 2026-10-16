#include "gen/pure3d.h"

namespace pure3d {
} // namespace pure3d
extern void FUN_002a2560(int*, int*, int, const void*);
void pure3d::TranslucentTraversal::vfunc_3() {
    int* eax = (*(int * *)&this->f_28);
    int* ecx = eax + this->f_18;
    FUN_002a2560(eax, ecx, (int)((char*)ecx - (char*)eax) >> 2, (void*)0x2a18a0);
}
