// Same code shape as 0x001ef5b0 (propagated; names are from that function)
#include "gen/global.h"

struct Global_1ef5e0 {
    void* a;
    void* b;
};
extern Global_1ef5e0* gSound_1ef5e0;
struct Resolver_1ef5e0 {
    int Run(void*);
};
struct Player_1ef5e0 {
    void Run(int, void*);
};

void CSoundCommand_PlayAmbienceEvent::vfunc_1(int , int ) {
    Resolver_1ef5e0* r = (Resolver_1ef5e0*)gSound_1ef5e0->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef5e0* p = (Player_1ef5e0*)gSound_1ef5e0->a;
        p->Run(x, (char*)this + 0x18);
    }
}
