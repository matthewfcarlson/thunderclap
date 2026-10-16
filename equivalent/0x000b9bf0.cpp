// STATUS: equivalent (tools/equiv.py level 3: 971 inputs, branch coverage 39/40, incomplete)
// FUN_000b9bf0 @ 0x000b9bf0
#include "decls/address.h"
#include "decls/data/game/global.h"
extern char DAT_0049dba4[];          // FEObject type descriptor
extern char DAT_0049dbbc[];          // TextSelector type descriptor
extern char DAT_0049f4a4[];          // TextButton type descriptor
extern char DAT_0049f4f0[];          // FEControl type descriptor
extern unsigned int DAT_004d9968;
   // zero-terminated list of "cNmM" side mission names
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl memcmp(const void *, const void *, unsigned int);

class FEObject {
public:
    virtual void vfunc_0();
};

class FEControl : public FEObject {
public:
    char pad04[0x141 - 4];
    char flag141;
};

class TextButton : public FEControl {
};

class Manager_b9bf0 {
public:
    int FUN_000f7240(int a, int b);
};

struct Label_b9bf0 {
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f7a10(int index, int flag);
    void FUN_000f8500(const char *name, Manager_b9bf0 *manager, char flag);
};

struct Args_b9bf0 {
    int count;
    char text[0x40];
    char rest[0x2b8 - 0x44];
    void FUN_001d1630();
};

struct Registry_b9bf0 {
    int FUN_001d3b00(const char *name, Args_b9bf0 args);
    const char *FUN_001d27b0(const char *name);
};

class SelectorView_b9bf0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(Label_b9bf0 *text, int a, int b);
    virtual void v20(int index, Label_b9bf0 *text);
    void FUN_000e36c0();
};

struct Progress_b9bf0 {
    const char *FUN_0008a060(const char *key);
    char FUN_000893c0();
};

FEObject *__cdecl FUN_000fc260(const char *name);
Manager_b9bf0 *__cdecl FUN_000fc1b0();
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
int __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);
int __cdecl FUN_00267760(char *dst, int size, const char *fmt, ...);
int __cdecl FUN_00345804(const char *s, const char *fmt, int *a, int *b);
Registry_b9bf0 *__cdecl FUN_001d4c90();

class SideMissionMenu {
public:
    char pad00[0x34];
    Progress_b9bf0 *progress;              // 0x34
    void FUN_000b9bf0();
};

void SideMissionMenu::FUN_000b9bf0()
{
    struct Frame {
        int count;                   // 0x00
        SelectorView_b9bf0 *sel;           // 0x04
        const char **entry;          // 0x08
        int a;                       // 0x0c
        int b;                       // 0x10
        SideMissionMenu *self;       // 0x14
        Label_b9bf0 label;                 // 0x18
        Label_b9bf0 medal;                 // 0x3c
        union {
            char name[0x20];
            Label_b9bf0 story;
        } u;                         // 0x60
        char pad80[4];
        Args_b9bf0 args;                   // 0x84
        unsigned int cookie;         // 0x33c
    } f;
    f.cookie = DAT_004d9968;
    f.self = this;

    char done = 0;
    if (progress != 0) {
        const char *state = progress->FUN_0008a060("c00m01");
        if (state != 0 && memcmp(state, "complete", 9) == 0)
            done = 1;
        else if (progress->FUN_000893c0() != 0)
            done = 1;
        else
            done = 0;
    }
    FEControl *cont = (FEControl *)FUN_00344e74(FUN_000fc260("story_mode_continue_game"), 0, DAT_0049dba4, DAT_0049f4f0, 0);
    if (cont != 0)
        cont->flag141 = done;
    FEControl *save = (FEControl *)FUN_00344e74(FUN_000fc260("options_save"), 0, DAT_0049dba4, DAT_0049f4f0, 0);
    if (save != 0)
        save->flag141 = done;

    if (progress != 0) {
        f.label.FUN_000f7930();
        f.sel = (SelectorView_b9bf0 *)FUN_00344e74(FUN_000fc260("side_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (f.sel != 0) {
            f.sel->FUN_000e36c0();
            f.count = 0;
            if (((const char**)&DAT_00406140)[0] != 0) {
                f.entry = ((const char**)&DAT_00406140);
                do {
                    f.a = -1;
                    f.b = -1;
                    FUN_00345804(*f.entry, "c%dm%d", &f.a, &f.b);
                    FUN_000964a0(f.u.name, 0x20, "%s_score", *f.entry);
                    const char *score = progress->FUN_0008a060(f.u.name);
                    if (*score != 0) {
                        FUN_000964a0(f.u.name, 0x20, "TBS_C%dM%d_NAME", f.a, f.b);
                        unsigned __int64 key = FUN_0027b020(f.u.name);
                        int idx = FUN_000fc1b0()->FUN_000f7240((int)key, (int)(key >> 32));
                        if (idx != -1)
                            f.label.FUN_000f7a10(idx, 0);
                        else
                            f.label.FUN_000f8500(f.u.name, FUN_000fc1b0(), 0);
                        f.sel->v19(&f.label, 0, 0);
                        Registry_b9bf0 *reg = FUN_001d4c90();
                        f.args.FUN_001d1630();
                        f.args.count = 1;
                        FUN_00267760(f.args.text, 0x40, "%s", *f.entry);
                        if (reg->FUN_001d3b00("kmcGetSideMissionAward", f.args) == 3) {
                            const char *medal = reg->FUN_001d27b0("__SIDEMISSION_MEDAL__");
                            if (medal != 0) {
                                f.medal.FUN_000f7930();
                                f.medal.FUN_000f8500(medal, 0, 1);
                                f.sel->v20(f.count, &f.medal);
                                f.medal.FUN_000f7960();
                            }
                        }
                        f.count++;
                    }
                    f.entry++;
                } while (*f.entry != 0);
            }
            f.sel->v3();
            TextButton *btn = (TextButton *)FUN_00344e74(FUN_000fc260("menu_item_side_missions"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
            if (btn != 0)
                btn->flag141 = f.count != 0;
        }
        f.label.FUN_000f7960();
    } else {
        f.u.story.FUN_000f7930();
        SelectorView_b9bf0 *story = (SelectorView_b9bf0 *)FUN_00344e74(FUN_000fc260("story_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (story != 0) {
            story->FUN_000e36c0();
            unsigned __int64 key = FUN_0027b020("TBS_CHPT_GEN_60");
            int idx = FUN_000fc1b0()->FUN_000f7240((int)key, (int)(key >> 32));
            if (idx != -1)
                f.u.story.FUN_000f7a10(idx, 0);
            else
                f.u.story.FUN_000f8500("TBS_CHPT_GEN_60", FUN_000fc1b0(), 0);
            story->v19(&f.u.story, 0, 0);
            story->v3();
        }
        SelectorView_b9bf0 *side = (SelectorView_b9bf0 *)FUN_00344e74(FUN_000fc260("side_mission_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
        if (side != 0) {
            side->FUN_000e36c0();
            unsigned __int64 key = FUN_0027b020("TBS_CHPT_GEN_11");
            int idx = FUN_000fc1b0()->FUN_000f7240((int)key, (int)(key >> 32));
            if (idx != -1)
                f.u.story.FUN_000f7a10(idx, 0);
            else
                f.u.story.FUN_000f8500("TBS_CHPT_GEN_11", FUN_000fc1b0(), 0);
            side->v19(&f.u.story, 0, 0);
            side->v3();
        }
        f.u.story.FUN_000f7960();
    }
    __security_check_cookie(f.cookie);
}
