// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8; --wine 600 inputs)
// CGrabTrack::vfunc_10 @ 0x0005b1a0
#include "gen/global.h"

struct Table_5b1a0;

// the game's CFightParams (from gen/global.h) with the one method this function calls
struct FightParamsView_5b1a0 {
    Table_5b1a0 *FUN_000592a0();
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
    CGrabAction_5b1a0 *FUN_0001de50(hulk_intptr a1, void *track, CFightParams *params, int index);
};

hulk_intptr CGrabTrack::vfunc_10(hulk_intptr a1, hulk_intptr a2, hulk_intptr __p2) { fight::Params * params = (fight::Params *)__p2;

    CFightParams *fp = dynamic_cast<CFightParams *>(params);
    if (fp == 0)
        return (hulk_intptr)(0);
    Table_5b1a0 *table = ((FightParamsView_5b1a0 *)fp)->FUN_000592a0();
    Binding_5b1a0 *binding = table->FUN_00059a40();
    if (binding == 0)
        return (hulk_intptr)(0);
    int arg1_ = this->f_1c;
    int arg2_ = this->f_18;
    int index = binding->FUN_002226b0()->FUN_0027b200(arg2_, arg1_);
    if (index < 0)
        return (hulk_intptr)(0);
    CGrabAction_5b1a0 *mem = (CGrabAction_5b1a0 *)FUN_0008d690(0x40);
    if (mem == 0)
        return (hulk_intptr)(0);
    return (hulk_intptr)(mem->FUN_0001de50(a1, this, fp, index));
}
