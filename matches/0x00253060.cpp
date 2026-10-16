#include "gen/audio.h"

class SeqAction_253060 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(void*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
struct Obj_253060 {
    char pad[0x38];
    int value;
};

void audio::SeqActionVarPosDist::vfunc_1(void* __p0) { void * param = (void *)__p0;

    *(int*)((char*)*(int*)((char*)param + 4) + 0x38) = *(int*)((char*)this + 8) + 8;
    *(int*)((char*)this + 0xc) = 0;
}
