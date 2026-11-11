// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001bddc0..0x001be0e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f79594ae {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f79594ae {} using namespace fn_f79594ae;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f79594ae {
void* __cdecl FUN_000f7120(int key);
int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, ...);
class Console_1bdff0 {
public:
    void FUN_000f7110();
    void FUN_000f7a80(const char* text);
};
class Subtitle {
public:
    char pad0[0x38];
    Console_1bdff0* console;
    char pad3c[0xc];
    int key;
    void FUN_001bdff0(hulk_intptr arg);
};


// 0x001bdff0 FUN_001bdff0 (104 B): matches/0x001bdff0.cpp
// sym: ?FUN_001bdff0@Subtitle@fn_f79594ae@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001bdff0 @ 0x001bdff0
void Subtitle::FUN_001bdff0(hulk_intptr arg) {
    char buf[0x40];
    void* found = FUN_000f7120(key);
    if (found && console) {
        console->FUN_000f7110();
        FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c68), arg, found);
        console->FUN_000f7a80(buf);
    }
}

} // namespace fn_f79594ae
