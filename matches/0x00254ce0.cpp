#include "decls/data/engine/audio.h"

class SeqCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
namespace audio { class SeqCommandLogicRepeat : public SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommandLogicRepeat* vfunc_1(int);
}; }
extern int SeqCommand_vftable;
extern void __cdecl FUN_00247550(void*, void*);
audio::SeqCommandLogicRepeat* audio::SeqCommandLogicRepeat::vfunc_1(int x) {
    *(int*)this = (int)&SeqCommand_vftable;
    if (x & 1)
        FUN_00247550((void*)((int)((char*)((char*)&DAT_004e72f8 + 104))), this);
    return this;
}