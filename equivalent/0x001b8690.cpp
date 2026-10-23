// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001b8690 @ 0x001b8690
#include "gen/pure3d.h"
struct View_nv_1b8690 {
    pure3d::View *FUN_00294880();
    void FUN_00293e40(int a, int b, int c, int d);
    void FUN_00293e90(unsigned int c);
};
extern void *__cdecl FUN_0008d690(unsigned int n);

class Owner_1b8690 {
public:
    void FUN_001b8690();
    int pad0;
    pure3d::View *child;
    int v[4];
};

void Owner_1b8690::FUN_001b8690()
{
    pure3d::View *c = (pure3d::View *)FUN_0008d690(0x140);
    if (c)
        c = ((View_nv_1b8690*)(c))->FUN_00294880();
    child = c;
    c->vfunc_0();
    ((View_nv_1b8690*)(child))->FUN_00293e40(v[0], v[1], v[2], v[3]);
    (*(unsigned int *)&child->f_20) = 0xff000000;
    (*(unsigned int *)&child->f_2c) = 0xffffffff;
    ((View_nv_1b8690*)(child))->FUN_00293e90(0xff000000);
}
