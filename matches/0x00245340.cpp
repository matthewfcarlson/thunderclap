#include "gen/audio.h"

#include "compat/ptr.h"
extern "C" char DAT_0042918c[];
struct Clip_nv_245340 {
    void Finish();
};
void Release(void*);

void audio::Clip::FUN_00245340() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042918c);
    if ((*(void * *)&this->f_28))
        Release((*(void * *)&this->f_28));
    ((Clip_nv_245340*)this)->Finish();
}
