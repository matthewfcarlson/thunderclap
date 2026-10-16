#include "decls/data/engine/audio.h"

extern "C" char DAT_004298fc[];
namespace audio {
class SeqAction;
class SeqAction {
  public:
    virtual SeqAction* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
class SeqActionVarPosDist : public SeqAction {
  public:
    virtual SeqActionVarPosDist* vfunc_0(int);
};
} // namespace audio
extern void FUN_00247550(void*, void*);
audio::SeqActionVarPosDist* audio::SeqActionVarPosDist::vfunc_0(int x) {
    int* p = (int*)this;
    *p = ((int)DAT_004298fc);
    if (x & 1)
        FUN_00247550((void*)((int)DAT_004e6ff0), this);
    return this;
}
