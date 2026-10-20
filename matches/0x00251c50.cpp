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
extern char g_bss[];
audio::SeqAction::SeqAction(int flag) {
    vptr = ((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550(g_bss, this);
}
