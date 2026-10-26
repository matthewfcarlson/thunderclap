// Same code shape as 0x001ef5b0 (propagated; names are from that function)
#include "gen/global.h"
#include "decls/data/game/unknown.h"
// data: gSound_1ef5e0 = DAT_004e370c

struct Global_1ef5e0 {
    void* a;
    void* b;
};
struct Resolver_1ef5e0 {
    int Run(void*);
};
struct Player_1ef5e0 {
    void Run(int, void*);
};

void CSoundCommand_PlayAmbienceEvent::vfunc_1(int , int ) {
    Resolver_1ef5e0* r = (Resolver_1ef5e0*)(*(Global_1ef5e0**)&DAT_004e370c)->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef5e0* p = (Player_1ef5e0*)(*(Global_1ef5e0**)&DAT_004e370c)->a;
        p->Run(x, (char*)this + 0x18);
    }
}
