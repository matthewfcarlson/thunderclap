#include "decls/data/engine/audio.h"
// data: g_bss = DAT_004e6ce0

#include "compat/ptr.h"
extern "C" char DAT_004298fc[];
namespace audio {
class SeqAction {
  public:
    hulk_intptr vptr;
    SeqAction(int);
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
audio::SeqAction::SeqAction(int flag) {
    vptr = ((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550(((char*)&DAT_004e6ce0), this);
}
