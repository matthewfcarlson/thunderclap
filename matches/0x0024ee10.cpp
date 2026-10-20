#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" char DAT_0042991c[];
namespace om {
class DynBehaviour {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
} // namespace om
namespace audio {
class ChannelSendVolumeFadeBehaviour : public om::DynBehaviour {
  public:
    virtual ChannelSendVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::ChannelSendVolumeFadeBehaviour* audio::ChannelSendVolumeFadeBehaviour::vfunc_0(int flag) {
    ChannelSendVolumeFadeBehaviour* p = this;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_0042991c);
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e67b8), p);
    return p;
}