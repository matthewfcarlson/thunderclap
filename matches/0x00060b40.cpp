#include "compat/ptr.h"
extern "C" char DAT_003faa80[];
typedef unsigned char byte_60b40;
struct Part_60b40 {
    void init();
};
struct CEffectTrack {
    unsigned long vf;
    char p4[20];
    Part_60b40 a18;
    char p1c[15];
    Part_60b40 a28;
    char p2c[7];
    Part_60b40 a30;
    CEffectTrack* vfunc_5(byte_60b40);
    void helper();
};
extern void cleanup(CEffectTrack*);
CEffectTrack* CEffectTrack::vfunc_5(byte_60b40 param_2) {
    vf = ((hulk_intptr)DAT_003faa80);
    a30.init();
    a28.init();
    a18.init();
    helper();
    if (param_2 & 1)
        cleanup(this);
    return this;
}