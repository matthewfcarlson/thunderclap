#include "decls/data/engine/audio.h"

extern "C" char DAT_004298fc[];
class SeqAction {
  public:
    int mVptr;
};
extern void Register(void*, void*);
class SeqActionVarPitchRand : public SeqAction {
  public:
    SeqActionVarPitchRand* vfunc_0(int);
};
SeqActionVarPitchRand* SeqActionVarPitchRand::vfunc_0(int flag) {
    SeqActionVarPitchRand* self = this;
    self->mVptr = ((int)DAT_004298fc);
    if (flag & 1)
        Register((void*)((int)DAT_004e70a0), self);
    return self;
}