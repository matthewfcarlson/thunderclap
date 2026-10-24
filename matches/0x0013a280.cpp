#include "gen/hulkfight.h"

#include "compat/ptr.h"
typedef unsigned int u32_13a280;
extern u32_13a280 vtable_13a280;
struct Sub_13a280 {
    void Init();
};
struct Base_13a280 {
    void Finish();
};

void hulkfight::motion::AnimationChargeTrack::FUN_0013a280() {
    *(hulk_uintptr*)this = (hulk_uintptr)&vtable_13a280;
    ((Sub_13a280*)((char*)this + 0x28))->Init();
    ((Sub_13a280*)((char*)this + 0x18))->Init();
    ((Base_13a280*)this)->Finish();
}
