#include "decls/data/engine/audio.h"
// data: seqActionBss = DAT_004e6b80

extern void* seqActionVtable;
extern void __cdecl FUN_00247550(void*, void*);
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
namespace audio {
class SeqActionStopTrack : public SeqAction {
  public:
    virtual SeqAction* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
SeqAction* audio::SeqActionStopTrack::vfunc_0(int flags) {
    *(void**)this = &seqActionVtable;
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e6b80), this);
    return this;
}
