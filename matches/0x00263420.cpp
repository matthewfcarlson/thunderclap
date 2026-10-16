#include "gen/audio.h"

extern "C" char DAT_004e7b50[];
extern "C" char DAT_004e7b98[];
namespace audio {
class Obj_263420 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Aux_263420 {
    void f();
};
} // namespace audio
void FUN_00247550(void*, void*);
void audio::HalRsdFileStream::vfunc_12() {
    if ((*(Obj_263420 * *)&this->f_20))
        (*(Obj_263420 * *)&this->f_20)->f1();
    if ((*(void * *)&this->f_24))
        FUN_00247550((void*)((int)DAT_004e7b50), (*(void * *)&this->f_24));
    ((audio::Aux_263420*)((char*)this + 0x10))->f();
    ((audio::Aux_263420*)((char*)this + 4))->f();
    FUN_00247550((void*)((int)DAT_004e7b98), this);
}
