#include "decls/data/engine/audio.h"
// data: gBss_24dbb0 = DAT_004e65b8

extern void FUN_00247550(const void*, void*);
namespace audio { class ListenerEffectWin32 {
  public:
    virtual void a();
    virtual void b();
    virtual ListenerEffectWin32* vfunc_2(int);
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    void BaseCall();
}; }
audio::ListenerEffectWin32* audio::ListenerEffectWin32::vfunc_2(int flag) {
    BaseCall();
    if (flag & 1)
        FUN_00247550(((int*)&DAT_004e65b8), this);
    return this;
}