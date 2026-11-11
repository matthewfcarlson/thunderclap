// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef5e0..0x001ef610 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayAmbienceEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f56b0d6d {
#define TREE_TU_END }
namespace fn_f56b0d6d {} using namespace fn_f56b0d6d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f56b0d6d {
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

} // namespace fn_f56b0d6d

// 0x001ef5e0 CSoundCommand_PlayAmbienceEvent::vfunc_1 (45 B): matches/0x001ef5e0.cpp
// sym: ?vfunc_1@CSoundCommand_PlayAmbienceEvent@@UAEXHH@Z
// Same code shape as 0x001ef5b0 (propagated; names are from that function)
// data: gSound_1ef5e0 = DAT_004e370c
void CSoundCommand_PlayAmbienceEvent::vfunc_1(int , int ) {
    Resolver_1ef5e0* r = (Resolver_1ef5e0*)(*(Global_1ef5e0**)&DAT_004e370c)->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef5e0* p = (Player_1ef5e0*)(*(Global_1ef5e0**)&DAT_004e370c)->a;
        p->Run(x, (char*)this + 0x18);
    }
}

