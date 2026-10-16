#include "gen/fight.h"

extern "C" char DAT_0041932c[];
typedef unsigned int size_t;
extern "C" void* __cdecl Alloc(size_t);
struct Track_18be50 {
    unsigned char pad[0x14];
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropActorThinkingTrack>::vfunc_5() {
    Track_18be50* p = (Track_18be50*)Alloc(0x14);
    if (p) {
        p->Init();
        *(unsigned int*)p = ((int)DAT_0041932c);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
