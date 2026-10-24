#include "gen/audio.h"

namespace audio {
class SeqEventVarPitch_253950 : public ::audio::SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventVarPitch_253950* vfunc_4(int);
    void Helper();
};
} // namespace audio
extern void FUN_00247550(void*, audio::SeqEventVarPitch_253950*);
extern char g_4e7198;
audio::SeqEventVarPitch_253950* audio::SeqEventVarPitch_253950::vfunc_4(int x) {
    Helper();
    if (x & 1)
        FUN_00247550(&g_4e7198, this);
    return this;
}
