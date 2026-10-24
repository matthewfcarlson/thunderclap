// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// CGrabTrack::vfunc_10 @ 0x0005b1a0
#include "gen/global.h"

namespace fight {
class Params_5b1a0 {
public:
    virtual void v0();
};
}

class CFightParams_5b1a0 : public fight::Params_5b1a0 {
public:
    virtual void v1();
    struct Table_5b1a0 *FUN_000592a0();
};

struct Skeleton_5b1a0 {
    int FUN_0027b200(int a, int b);
};

struct Binding_5b1a0 {
    Skeleton_5b1a0 *FUN_002226b0();
};

struct Table_5b1a0 {
    Binding_5b1a0 *FUN_00059a40();
};

class CGrabAction_5b1a0;
void *FUN_0008d690(unsigned int size);

class CGrabAction_5b1a0 {
public:
    CGrabAction_5b1a0 *FUN_0001de50(int a1, void *track, CFightParams_5b1a0 *params, int index);
};

int CGrabTrack::vfunc_10(int a1, int a2, int __p2) { fight::Params_5b1a0 * params = (fight::Params_5b1a0 *)__p2;

    CFightParams_5b1a0 *fp = dynamic_cast<CFightParams_5b1a0 *>(params);
    if (fp == 0)
        return (int)(0);
    Table_5b1a0 *table = fp->FUN_000592a0();
    Binding_5b1a0 *binding = table->FUN_00059a40();
    if (binding == 0)
        return (int)(0);
    int arg1_ = this->f_1c;
    int arg2_ = this->f_18;
    int index = binding->FUN_002226b0()->FUN_0027b200(arg2_, arg1_);
    if (index < 0)
        return (int)(0);
    CGrabAction_5b1a0 *mem = (CGrabAction_5b1a0 *)FUN_0008d690(0x40);
    if (mem == 0)
        return (int)(0);
    return (int)(mem->FUN_0001de50(a1, this, fp, index));
}
