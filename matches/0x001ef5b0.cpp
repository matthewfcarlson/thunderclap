#include "gen/global.h"
#include "decls/data/game/unknown.h"
// data: gSound_1ef5b0 = DAT_004e370c

struct Global_1ef5b0 {
    void* a;
    void* b;
};
struct Resolver_1ef5b0 {
    int Run(void*);
};
struct Player_1ef5b0 {
    void Run(int, void*);
};

void CSoundCommand_PlayMusicEvent::vfunc_1(int , int ) {
    Resolver_1ef5b0* r = (Resolver_1ef5b0*)(*(Global_1ef5b0**)&DAT_004e370c)->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef5b0* p = (Player_1ef5b0*)(*(Global_1ef5b0**)&DAT_004e370c)->a;
        p->Run(x, (char*)this + 0x18);
    }
}
