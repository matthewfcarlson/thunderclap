// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef660..0x001ef6b0 (kind game, layer game, confidence medium), dominant class CSoundCommand_CueNISEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f34f5748 {
#define TREE_TU_END }
namespace fn_f34f5748 {} using namespace fn_f34f5748;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f34f5748 {
struct Global_1ef660 {
    void* a;
    void* b;
};
struct Resolver_1ef660 {
    int Run_001e98b0(void*);
};
struct Player_1ef660 {
    void Run_001f56b0(int, void*);
};

} // namespace fn_f34f5748

// 0x001ef660 CSoundCommand_CueNISEvent::vfunc_1 (45 B): matches/0x001ef660.cpp
// sym: ?vfunc_1@CSoundCommand_CueNISEvent@@UAEXHH@Z
// Same code shape as 0x001ef5b0 (propagated; names are from that function)
// data: gSound_1ef660 = DAT_004e370c
void CSoundCommand_CueNISEvent::vfunc_1(int , int ) {
    Resolver_1ef660* r = (Resolver_1ef660*)(*(Global_1ef660**)&DAT_004e370c)->b;
    int x = r->Run_001e98b0((char*)this + 0x10);
    if (x) {
        Player_1ef660* p = (Player_1ef660*)(*(Global_1ef660**)&DAT_004e370c)->a;
        p->Run_001f56b0(x, (char*)this + 0x18);
    }
}

