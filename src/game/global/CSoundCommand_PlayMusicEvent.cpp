// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef5b0..0x001ef5e0 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayMusicEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fdec2d14 {
#define TREE_TU_END }
namespace fn_fdec2d14 {} using namespace fn_fdec2d14;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdec2d14 {
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

} // namespace fn_fdec2d14

// 0x001ef5b0 CSoundCommand_PlayMusicEvent::vfunc_1 (45 B): matches/0x001ef5b0.cpp
// sym: ?vfunc_1@CSoundCommand_PlayMusicEvent@@UAEXHH@Z
// data: gSound_1ef5b0 = DAT_004e370c
void CSoundCommand_PlayMusicEvent::vfunc_1(int , int ) {
    Resolver_1ef5b0* r = (Resolver_1ef5b0*)(*(Global_1ef5b0**)&DAT_004e370c)->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef5b0* p = (Player_1ef5b0*)(*(Global_1ef5b0**)&DAT_004e370c)->a;
        p->Run(x, (char*)this + 0x18);
    }
}

