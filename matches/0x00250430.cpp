#include "decls/data/engine/audio.h"
// data: global_bss = DAT_004e6960

#include "compat/ptr.h"
extern "C" char DAT_004298fc[];
namespace audio {
class SeqAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
class SeqActionWait : public SeqAction {
  public:
    virtual SeqActionWait* vfunc_0(int);
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
audio::SeqActionWait* audio::SeqActionWait::vfunc_0(int x) {
    SeqActionWait* p = this;
    *(void**)p = (void*)((hulk_intptr)DAT_004298fc);
    if (x & 1)
        FUN_00247550(((int*)((char*)&DAT_004e68f8 + 104)), this);
    return this;
}
