// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ad990..0x000ae9a0 (kind game, layer game, confidence medium), dominant class CController
// (tree_prelude.h: not needed)


// 0x000ae660 FUN_000ae660 (457 B): matches/0x000ae660.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?FUN_000ae660@Controls@fn_fe2f6d8e@@QAEXXZ
#include "gen/owners.h"
#include "decls/data/game/global.h"
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_fe2f6d8e {} using namespace fn_fe2f6d8e;
namespace fn_fe2f6d8e {
// FUN_000ae660 @ 0x000ae660
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Snapshot {
    float f[17];
};

struct PadDevice {
    char pad00[0x18];
    char padbody[0x100];
    void FUN_000ada90(Snapshot* out);
    void FUN_000ad9f0();
};

struct Audio_ae660 {
    void FUN_00086180(int a, int b, int c, int d);
};

struct World {
    char pad00[0x54];
    Audio_ae660* audio;
};

struct InputHub {
    void FUN_0023f6d0();
    void FUN_0023f6e0();
    void FUN_0023f6f0();
    void FUN_0023f700();
    char FUN_0023f710();
};


struct Controls {
    char pad00[4];
    PadDevice* device;
    char pad08[0x1b - 8];
    char g1b, g1c, g1d, g1e, g1f, g20, g21;
    void FUN_000ae660();
};

void Controls::FUN_000ae660()
{
    Snapshot a;
    Snapshot b;
    ((owners::Obj_ada70 *)device)->FUN_000ada70((Snapshot *)(&a));
    device->FUN_000ada90(&b);
    if (!(b.f[8] > 0.2f))
        return;
    if (g1b == 0) {
        if (a.f[3] > 0.2f) {
            DAT_004dd700->audio->FUN_00086180(0x2d, 0, 0, 0);
            g1b = 1;
        }
    } else if (a.f[3] < 0.2f) {
        g1b = 0;
    }
    if (g1c == 0) {
        if (a.f[0] > 0.2f) {
            DAT_004dd700->audio->FUN_00086180(0x3d, 0, 0, 0);
            g1c = 1;
        }
    } else if (a.f[0] < 0.2f) {
        g1c = 0;
    }
    if (g1f == 0) {
        if (b.f[10] > 0.2f) {
            DAT_004dd700->audio->FUN_00086180(0x5c, 0, 0, 0);
            g1f = 1;
        }
    } else if (b.f[10] < 0.2f) {
        g1f = 0;
    }
    if (g1d == 0) {
        if (a.f[2] > 0.2f) {
            (*(InputHub**)&DAT_004dd6e8)->FUN_0023f6e0();
            g1d = 1;
        }
    } else if (a.f[2] < 0.2f) {
        g1d = 0;
    }
    if (g1e == 0) {
        if (a.f[1] > 0.2f) {
            (*(InputHub**)&DAT_004dd6e8)->FUN_0023f6d0();
            g1e = 1;
        }
    } else if (a.f[1] < 0.2f) {
        g1e = 0;
    }
    if (g20 == 0) {
        if (a.f[7] > 0.2f) {
            (*(InputHub**)&DAT_004dd6e8)->FUN_0023f700();
            g20 = 1;
        }
    } else if (a.f[7] < 0.2f) {
        g20 = 0;
    }
    if (g21 == 0) {
        if (a.f[8] > 0.2f) {
            (*(InputHub**)&DAT_004dd6e8)->FUN_0023f6f0();
            g21 = 1;
        }
    } else if (a.f[8] < 0.2f) {
        g21 = 0;
    }
    if ((*(InputHub**)&DAT_004dd6e8)->FUN_0023f710() != 0)
        device->FUN_000ad9f0();
}
} // namespace fn_fe2f6d8e
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

