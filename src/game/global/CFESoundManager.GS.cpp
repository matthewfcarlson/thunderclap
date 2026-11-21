// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c4ef0..0x000c5900 (kind game, layer game, confidence medium), dominant class CFESoundManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#include "decls/managers.h"   // (gfx10) HulkFEManager: Menu_c5180 is CFEManager
#define TREE_TU_BEGIN namespace fn_f65ec8d6 {
#define TREE_TU_END }
namespace fn_f65ec8d6 {} using namespace fn_f65ec8d6;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);
#endif
namespace fn_f65ec8d6 {
class Menu_c5180;
class Node {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual const char *vfunc_8();
};
} // namespace fn_f65ec8d6
class Gfx {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a);
};
namespace fn_f65ec8d6 {
class Timer {
public:
    void FUN_000b0080(HULK_TYPE64(int, float) dt);   // (gfx10) 0x000b0080 takes the float (HULK_FBITS)
};
class Source_c5180 {
public:
    void *FUN_000862d0();
    Timer *FUN_00086330();
    hulk_uintptr FUN_00086300();   // (gfx10) as defined (CTimeManager.cpp: a pointer-sized word)
};
class Probe_c5180 {
public:
    char pad0[0x2218];
    struct Flags_c5180 *flags;
};
struct Flags_c5180 {
    char pad0[0x9a8];
    char enabled;
};
class Block4_c5180 {   // (gfx10) the CFESoundManager (gen: its vftable, then f_04, a pointer: 0x00086a40's C30*)
public:
    void *f0;
    hulk_intptr f4;
};
class Target34 {
public:
};
class Hooked {
public:
    void FUN_00086400();
};
class Aux54 {
public:
};
class Aux5c {
public:
    void FUN_001c04e0(HULK_TYPE64(int, float) dt);   // (gfx10) 0x001c04e0 takes the float (HULK_FBITS)
};
class Aux38 {
public:
};
struct Flag4 {
    void* vftable;   // (gfx2) the drive-error callback (0x0008e090): its vftable, then the flags
    char on;
};
extern "C" void FUN_000fc150();
extern "C" void FUN_000fc280(const char *s);
extern "C" void FUN_000fc340(const char *s);
void FUN_000fc170(int v);
extern "C" void FUN_000fc330();
extern "C" Probe_c5180 *FUN_000fc3d0();
extern "C" Node *FUN_000fc310();
extern "C" Flag4 *FUN_0008e090();
struct Frame_c5180 {
    Node *cur;
    char name[0x40];
};
// (gfx10) CFEManager (decls/managers.h HulkFEManager) at its record's offsets (were 32-bit pads: natively the state, the
// managers and the names were read inside the record's pointer words); a3 / f3c / the sound manager's f4 are the
// pointer 0x00086a40 passes (C30*), pointer-sized natively (hulk_intptr keeps the 32-bit type and mangling)
#if defined(__clang__)
#define HULK_FEM_OFF_c5180(f) __builtin_offsetof(HulkFEManager, f)
#else
#define HULK_FEM_OFF_c5180(f) ((unsigned int)(hulk_uintptr)&((HulkFEManager*)0)->f)
#endif
class Menu_c5180 {
public:
    char pad0[HULK_FEM_OFF_c5180(f10)];
    int state;
    char pad14[HULK_FEM_OFF_c5180(f30) - HULK_FEM_OFF_c5180(f10) - 4];
    void *f30;
    Target34 *f34;
    Aux38 *f38;
    hulk_intptr f3c;
    Block4_c5180 *f40;
    char pad44[HULK_FEM_OFF_c5180(f54) - HULK_FEM_OFF_c5180(f40) - sizeof(void *)];
    Aux54 *f54;
    char pad58[HULK_FEM_OFF_c5180(f5c) - HULK_FEM_OFF_c5180(f54) - sizeof(void *)];
    Aux5c *f5c;
    char pad60[HULK_FEM_OFF_c5180(f1a06) - HULK_FEM_OFF_c5180(f5c) - sizeof(void *)];
    char f1a06;
    char pad1a07[HULK_FEM_OFF_c5180(f1c8c) - HULK_FEM_OFF_c5180(f1a06) - 1];
    char pendingName[0x20];
    char savedName[0x40];
    char pad1cec[HULK_FEM_OFF_c5180(f1cfc) - HULK_FEM_OFF_c5180(f1cac) - 0x40];
    float f1cfc;
    char pad1d00[HULK_FEM_OFF_c5180(f1d34) - HULK_FEM_OFF_c5180(f1cfc) - 4];
    float f1d34;
    void FUN_000bfbe0(Source_c5180 *src, HULK_TYPE64(int, float) dt);   // (gfx10) 0x000bfbe0 takes the float
    void FUN_000b8c50(const char *a, const char *b);
    void FUN_000b9620();
    void FUN_000b9ad0();
    void FUN_000c4220(hulk_uintptr a);   // (gfx10) binds natively like the definition's Player_c4220*
    void FUN_000c2990(hulk_uintptr a);   // (gfx10) binds natively like the definition's Output_c2990*
    void FUN_000c3db0();
    void FUN_000b9650();
    void FUN_000b96e0();
    void FUN_000b9770();
    void FUN_000b9830();
    void FUN_000b97d0();
    void FUN_000bcf40(void *a);
    void FUN_000b90c0(HULK_TYPE64(int, bool) a);   // (gfx10) 0x000b90c0 takes a bool
    void FUN_000c5180(Source_c5180 *src, void *a1, float dt, hulk_intptr a3, Aux54 *a4);
};


// 0x000c5180 FUN_000c5180 (1595 B): equivalent/0x000c5180.cpp
// sym: ?FUN_000c5180@Menu_c5180@fn_f65ec8d6@@QAEXPAVSource_c5180@2@PAXMHPAVAux54@2@@Z @d012a59b714a @wed4f834c8f83 @v4d077d72d0fd
// STATUS: equivalent (tools/equiv.py level 3: 3135 inputs, branch coverage 75/80, incomplete)
// FUN_000c5180 @ 0x000c5180
void Menu_c5180::FUN_000c5180(Source_c5180 *src, void *a1, float dt, hulk_intptr a3, Aux54 *a4)
{
    Frame_c5180 f;
    Block4_c5180 *blk = f40;
    f30 = a1;
    f3c = a3;
    blk->f4 = a3;
    void *res = src->FUN_000862d0();
    int dtBits = *(int *)&dt;
    f54 = a4;
    src->FUN_00086330()->FUN_000b0080(HULK_FBITS(dtBits));
    Probe_c5180 *probe = FUN_000fc3d0();
    if (probe->flags && probe->flags->enabled)
        f1d34 = dt + f1d34;
    f1cfc = dt + f1cfc;

    switch (state) {
    case 0:
        FUN_000fc170(dtBits);
        f.cur = FUN_000fc310();
        if (f.cur) {
            if (strcmp(f.cur->vfunc_8(), "main") == 0)
                FUN_000bfbe0(src, HULK_FBITS(dtBits));
            if (strcmp(f.cur->vfunc_8(), "credits") == 0) {
                FUN_000b9620();
            } else {
                ((owners::A_1b8ae0 *)f54)->FUN_001b8ae0();
            }
        } else {
            ((owners::A_1b8ae0 *)f54)->FUN_001b8ae0();
        }
        if (f1a06 && f3c)
            FUN_000b9ad0();
        if (f.cur && strcmp(f.cur->vfunc_8(), "blonsky_file") == 0) {
            if (f5c)
                f5c->FUN_001c04e0(HULK_FBITS(dtBits));
        }
        break;
    case 1:
        FUN_000fc150();
        FUN_000fc280("splash");
        state = 2;
        break;
    case 2:
        FUN_000fc170(dtBits);
        FUN_000bfbe0(src, HULK_FBITS(dtBits));
        break;
    case 4:
        FUN_0008e090()->on = 1;
        FUN_000fc150();
        FUN_000fc340("main");
        FUN_000fc280("story_mode");
        state = 0;
        if (f34) {
            int *outA = (int *)&dt;
            int *outB = (int *)&src;
            ((owners::C_89880 *)f34)->FUN_00089880((unsigned *)outA, (unsigned *)outB);
            if (*outA >= 0 && *outB >= 0) {
                FUN_000b8c50("story_mode", "story_mode_continue_game");
                FUN_000b8c50("main", "main_story_mode");
            }
        }
        break;
    case 5:
        FUN_0008e090()->on = 1;
        FUN_000fc150();
        FUN_000fc330();
        if (strcmp(pendingName, "computer_interface") == 0) {
            FUN_000fc340("main");
            FUN_000fc340("story_mode");
            FUN_000fc280("computer_interface");
        } else if (strcmp(pendingName, "buy_menu") == 0) {
            FUN_000fc340("main");
            FUN_000fc340("story_mode");
            FUN_000fc340("computer_interface");
            FUN_000fc280("buy_menu");
        } else if (strcmp(pendingName, "side_missions") == 0) {
            FUN_000fc340("main");
            FUN_000fc340("story_mode");
            FUN_000fc340("computer_interface");
            FUN_000fc280("side_missions");
        } else {
            FUN_000fc280("main");
            state = 0;
            break;
        }
        FUN_000b8c50("story_mode", "story_mode_continue_game");
        FUN_000b8c50("main", "main_story_mode");
        state = 0;
        pendingName[0] = 0;
        break;
    case 7:
        FUN_000c4220(src->FUN_00086300());
        break;
    case 8:
        FUN_000fc170(dtBits);
        FUN_000bcf40(res);
        break;
    case 9:
        f.name[0] = 0;
        if (FUN_000fc310()) {
            if (FUN_000fc310()->vfunc_8()) {
                const char *s = FUN_000fc310()->vfunc_8();
                char *d = f.name;
                char c;
                do {
                    c = *s++;
                    *d++ = c;
                } while (c);
            }
        }
        FUN_000fc170(dtBits);
        if (FUN_000fc310() == 0) {
            if (strcmp(f.name, "pause") == 0 || strcmp(f.name, "location_map") == 0 ||
                strcmp(f.name, "mission_objectives") == 0 || strcmp(f.name, "options") == 0 ||
                strcmp(f.name, "move_gallery") == 0)
                strncpy(savedName, f.name, 0x40);
            state = 8;
            if (f30)
                ((Hooked *)f30)->FUN_00086400();
            DAT_004e222c = 1;
            if (((int)((::CScenarioManager *)f38)->FUN_001cc840()) == 5)
                DAT_0052c2a8->vfunc_12(1);
            FUN_000b90c0(0);
        }
        break;
    case 10:
    case 15:
        FUN_000fc170(dtBits);
        break;
    case 12:
        FUN_000c3db0();
        break;
    case 13:
        FUN_000c2990(src->FUN_00086300());
        break;
    case 16:
        FUN_000fc150();
        FUN_000fc280("init_mem_check");
        FUN_000fc170(0);
        state = 0x11;
        break;
    case 17:
        ((owners::Target_b9090 *)this)->FUN_000b9090(dtBits);
        break;
    case 18:
        FUN_000fc170(dtBits);
        FUN_000b9650();
        break;
    case 19:
        FUN_000fc170(dtBits);
        FUN_000b96e0();
        break;
    case 20:
        FUN_000fc170(dtBits);
        FUN_000b9770();
        break;
    case 21:
        FUN_000fc170(dtBits);
        FUN_000b97d0();
        break;
    case 22:
        FUN_000fc170(dtBits);
        FUN_000b9830();
        break;
    case 23:
        FUN_000fc170(dtBits);
        ((owners::Menu_be100 *)this)->FUN_000be100();
        break;
    }
}

} // namespace fn_f65ec8d6
