#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int u32_245640;
extern void* __cdecl FUN_00247530(void*);
extern u32_245640 clipVftable;
extern char allocatorGlobal;
namespace audio {
class Clip_245640 {
  public:
    u32_245640 vft;
    char pad[0x24];
    u32_245640 field28;
    void init(void*);
};

} // namespace audio
void* audio::ClipType::vfunc_2() {
    Clip_245640* p = (Clip_245640*)FUN_00247530(&allocatorGlobal);
    if (p != 0) {
        p->init(&allocatorGlobal);
        p->vft = (hulk_uintptr)&clipVftable;
        p->field28 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
