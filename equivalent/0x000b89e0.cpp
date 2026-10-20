// STATUS: equivalent (tools/equiv.py level 3: 3071 inputs, branch coverage 42/42)
// FUN_000b89e0 @ 0x000b89e0
// cl-flags: /GS
#include "decls/data/game/global.h"

extern "C" int memcmp(const void* a, const void* b, unsigned n);
extern char DAT_0049dba4[];
extern char DAT_0049f470[];
extern char DAT_0049f48c[];
extern char DAT_0049f4a4[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern void* __cdecl FUN_000fc260(const char* name);
extern int __cdecl FUN_000fc1b0();
extern int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);

struct ScriptArgs {
    int tag;
    char text[10][0x40];
    int ints[10];
    char kinds[10];
    char pad2b6[2];
    void FUN_001d1630();
};

struct Script_b89e0 {
    int FUN_001d3b00(const char* name, ScriptArgs args);
    const char* FUN_001d27b0(const char* name);
};

extern Script_b89e0* __cdecl FUN_001d4c90();

struct Label_b89e0 {
    void FUN_000f8500(const char* text, int a, char flag);
};

class Panel_b89e0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x18 - 4];
    Label_b89e0 label;                // 0x18
};

struct TitleText {
    void FUN_000e2a60(const char* text);
};

struct ContinueButton {
    char pad0[0x141];
    char enabled;               // 0x141
    void FUN_000e2a60(const char* text);
};

struct Progress_b89e0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Mission_b89e0 {
    char pad0[0x80];
    Progress_b89e0 progress;          // 0x80
    const char* FUN_0008a2d0();
    const char* FUN_0008a060(const char* id);
};

class MissionFailMenu {
public:
    char pad00[0x34];
    Mission_b89e0* mission;           // 0x34
    char pad38[0x1bcc - 0x38];
    char hint[0x40];            // 0x1bcc
    void FUN_000b89e0();
};

void MissionFailMenu::FUN_000b89e0()
{
    struct Frame {
        ScriptArgs args;
    } f;

    hint[0] = 0;
    const char* id = mission->FUN_0008a2d0();
    const char* state = mission->FUN_0008a060(id);
    if (memcmp(state, "complete", 9) != 0) {
        Script_b89e0* script = FUN_001d4c90();
        if (script != 0) {
            f.args.FUN_001d1630();
            f.args.tag = 0;
            script->FUN_001d3b00("GetMissionFailHint", f.args);
            const char* h = script->FUN_001d27b0("mission_fail_hints_current");
            if (h != 0)
                FUN_00267760(hint, 0x40, "%s", h);
        }
    }

    Panel_b89e0* title = (Panel_b89e0*)FUN_00344e74(FUN_000fc260("Mission_Failure"), 0, DAT_0049dba4, DAT_0049f470, 0);
    if (title != 0) {
        title->label.FUN_000f8500(hint, FUN_000fc1b0(), 1);
        title->vfunc_3();
    }

    bool defeated = false;
    int a = mission->progress.FUN_00088fa0();
    int b = mission->progress.FUN_00088fb0();
    if (a >= 1 && a <= 7) {
        if (b == 0 || memcmp(state, "complete", 9) == 0)
            defeated = true;
    }

    TitleText* heading = (TitleText*)FUN_00344e74(FUN_000fc260("story_mission_fail_title"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (heading != 0)
        heading->FUN_000e2a60(defeated ? "TBS_MISSION_DEFEATED" : "TBS_MISSION_FAIL");

    ContinueButton* cont = (ContinueButton*)FUN_00344e74(FUN_000fc260("story_mission_fail_continue"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    if (cont != 0)
        cont->enabled = !defeated;

    ContinueButton* freeroam = (ContinueButton*)FUN_00344e74(FUN_000fc260("story_mission_fail_return_to_freeroam"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    if (freeroam != 0) {
        char show = 1;
        const char** entry = ((const char**)&DAT_004067a4);
        while (*entry != 0) {
            const char* p = id;
            const char* q = *entry;
            int cmp;
            for (;;) {
                unsigned char pc = *p;
                unsigned char qc = *q;
                if (pc != qc) {
                    cmp = 1;
                    break;
                }
                if (pc == 0) {
                    cmp = 0;
                    break;
                }
                p++;
                q++;
            }
            if (cmp == 0) {
                show = 0;
                break;
            }
            entry++;
        }
        freeroam->enabled = show;
        freeroam->FUN_000e2a60(defeated ? "TBS_CHPT_GEN_57" : "TBS_MENU_ITEM_RETURN_TO_FREEROAM");
    }
}
