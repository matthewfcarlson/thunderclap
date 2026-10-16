#include "gen/global.h"

struct Global_1ef5b0 {
    void* a;
    void* b;
};
extern Global_1ef5b0* gSound_1ef5b0;
struct Resolver_1ef5b0 {
    int Run(void*);
};
struct Player_1ef5b0 {
    void Run(int, void*);
};

void CSoundCommand_PlayMusicEvent::vfunc_1(int , int ) {
    Resolver_1ef5b0* r = (Resolver_1ef5b0*)gSound_1ef5b0->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef5b0* p = (Player_1ef5b0*)gSound_1ef5b0->a;
        p->Run(x, (char*)this + 0x18);
    }
}
