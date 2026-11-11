// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00291dc0..0x002926d0 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x002923b0 FUN_002923b0 (60 B): matches/0x002923b0.cpp [isolated: lost its match in the tree (codegen differs (11 of 13 instructions))]
// sym: ?FUN_002923b0@fn_f399830a@@YIPAUConfig_2923b0@1@PAU21@@Z
#include "gen/owners.h"
namespace fn_f399830a {} using namespace fn_f399830a;
namespace fn_f399830a {
struct Config_2923b0 {
    int a;
    int b;
    int c;
    int d;
    int e;
    char pad[0x10];
    int f;
    int g;
};
Config_2923b0* __fastcall FUN_002923b0(Config_2923b0* p) {
    ((owners::Settings_292330 *)p)->FUN_00292330();
    p->a = 0x280;
    p->b = 0x1e0;
    p->c = 0x20;
    p->d = 2;
    p->e = 3;
    p->f = 0x11;
    p->g = 0;
    return p;
}
} // namespace fn_f399830a

