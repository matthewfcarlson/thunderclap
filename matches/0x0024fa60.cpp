#include "decls/data/engine/audio.h"
// data: gData_24fa60 = DAT_004e6800

#include "compat/ptr.h"
namespace audio {
class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
extern void Init(void*, void*);
extern int baseVtable;
class SeqActionChannelSends : public SeqAction {
  public:
    virtual SeqActionChannelSends* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
audio::SeqActionChannelSends* audio::SeqActionChannelSends::vfunc_0(int x) {
    *(hulk_ulongptr*)this = (hulk_ulongptr)&baseVtable;
    if (x & 1)
        Init(((char*)&DAT_004e6800), this);
    return this;
}