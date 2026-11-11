// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001efb80..0x001f0290 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb2fda35 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb2fda35 {} using namespace fn_fb2fda35;
#include "game/unknown.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_fb2fda35 {
struct Name {
    unsigned int lo, hi;
    void FUN_0027af00();
};
struct NamePath {
    Name names[8];
    int count;
    NamePath(const char* path);
};


// 0x001f0090 FUN_001f0090 (177 B): matches/0x001f0090.cpp
// sym: ??0NamePath@fn_fb2fda35@@QAE@PBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2549 inputs, branch coverage 10/10)
// FUN_001f0090 @ 0x001f0090
NamePath::NamePath(const char* path) {
    struct {
        char buf[0x40];
    } fr;
    for (int i = 0; i < 8; i++)
        names[i].FUN_0027af00();
    count = 0;
    const char* segment = path;
    const char* dot = strchr(segment, '.');
    while (dot) {
        hulk_intptr len = dot - segment;
        strncpy(fr.buf, segment, len);
        fr.buf[len] = 0;
        if (count < 8) {
            ((owners::Target_27b040 *)&(names[count]))->FUN_0027b040((hulk_uintptr)(fr.buf));
            count++;
        }
        segment = dot + 1;
        dot = strchr(segment, '.');
    }
    if (count < 8) {
        ((owners::Target_27b040 *)&(names[count]))->FUN_0027b040((hulk_uintptr)segment);
        count++;
    }
}

} // namespace fn_fb2fda35
