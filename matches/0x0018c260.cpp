#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041950c[];
struct PropTrack_18c260 {
    void Init();
    unsigned char pad[0x18];
};
void* __cdecl Alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_5() {
    PropTrack_18c260* p = (PropTrack_18c260*)Alloc(0x18);
    if (p) {
        p->Init();
        p->pad[0x14] = 1;
        *(int*)(p->pad + 8) = 1;
        *(hulk_intptr*)p->pad = ((hulk_intptr)DAT_0041950c);
        *(int*)(p->pad + 0xc) = 0;
        *(int*)(p->pad + 0x10) = 0;
    }
    if (!p)
        return (void*)(0);
    return (void*)(p);
}
