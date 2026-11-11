// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f2db0..0x001f2e40 (kind game, layer game, confidence medium), dominant class CSoundStreamAllocator
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f1b52646 {
#define TREE_TU_END }
namespace fn_f1b52646 {} using namespace fn_f1b52646;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f1b52646 {
class Checker_1f2db0 {
  public:
    bool check_001e8780(int);
};
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, unsigned int);
extern "C" int __cdecl FUN_0024be00(int, int, int, int, int, int, int);
class StreamPlayerAllocator_1f2db0 {
  public:
    virtual int vfunc_0(int, int, int, int);
    virtual int vfunc_1();
};
extern int __cdecl FUN_0024b030(int);
extern int __cdecl FUN_0024c590(int, int);
struct Receiver_1f2e00 {
    void run_001e87c0(int);
};
extern "C" void __cdecl FUN_0024bf90(int);
extern int hulk_at_004c6f4c;

} // namespace fn_f1b52646

// 0x001f2db0 CSoundStreamAllocator::vfunc_0 (75 B): matches/0x001f2db0.cpp
// sym: ?vfunc_0@CSoundStreamAllocator@@UAEHHHHH@Z
// data: g_checker = DAT_004e3690, g_size_1f2db0 = DAT_004c6f4c
int CSoundStreamAllocator::vfunc_0(int a, int b, int c, int d) {
    int x = ((int)FUN_0026fd50((int)d, (int)DAT_004c6f4c));
    if (!(*(Checker_1f2db0**)&DAT_004e3690)->check_001e8780(x))
        return 0;
    return FUN_0024be00(c, 0, b, x, 0, 0, 1);
}


// 0x001f2e00 CSoundStreamAllocator::vfunc_1 (63 B): matches/0x001f2e00.cpp
// sym: ?vfunc_1@CSoundStreamAllocator@@UAEXHH@Z
// data: receiver = DAT_004e3690
void CSoundStreamAllocator::vfunc_1(int a, int c) {
    int x = FUN_0024b030(c);
    x = FUN_0024c590(x, 3000);
    x = ((int)FUN_0026fd50((hulk_intptr)x, (int)hulk_at_004c6f4c));
    (*(Receiver_1f2e00**)&DAT_004e3690)->run_001e87c0(x);
    FUN_0024bf90(c);
}

