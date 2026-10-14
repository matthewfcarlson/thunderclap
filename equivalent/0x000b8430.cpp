// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 48/48)
// FUN_000b8430 @ 0x000b8430
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f470[];
extern char DAT_0049f48c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);

struct Label_b8430 {
    int f00;
    char f04;
    char pad05[3];
    int f08;
    int f0c;
    char *f10;
    int f14;
    char f18;
    char pad19[3];
    float f1c;
    int f20;
    void FUN_000f8500(const char *text, int a, char flag);
};

class Widget_b8430 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14];
    Label_b8430 label;
};

struct Selector_b8430 {
    char pad00[0x154];
    int index;
};

class HintMenu_b8430 {
public:
    char pad00[0x1b50];
    int shown[32];
    void FUN_000b8430();
};

void HintMenu_b8430::FUN_000b8430()
{
    Widget_b8430 *title = (Widget_b8430 *)FUN_00344e74(FUN_000fc260("smart_hint_title"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (title == 0)
        return;
    Widget_b8430 *text = (Widget_b8430 *)FUN_00344e74(FUN_000fc260("smart_hint_text"), 0, DAT_0049dba4, DAT_0049f470, 0);
    if (text == 0)
        return;
    Selector_b8430 *sel = (Selector_b8430 *)FUN_00344e74(FUN_000fc260("smart_hint_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (sel == 0)
        return;
    if (sel->index < 0)
        return;
    int id = shown[sel->index];
    if (id < 0x2e9 || id > 0x2fd)
        return;
    const char *headText = "";
    const char *bodyText = "";
    switch (id) {
        case 0x2e9:
            headText = "TBS_SH_HEAD_COLLECTIBLE_BOSSMARKER";
            bodyText = "TBS_SH_COLLECTIBLE_BOSSMARKER";
            break;
        case 0x2ea:
            headText = "TBS_SH_HEAD_CHASE_HUD";
            bodyText = "TBS_SH_CHASE_HUD";
            break;
        case 0x2eb:
            headText = "TBS_SH_HEAD_STORY_MODE";
            bodyText = "TBS_SH_STORY_MODE";
            break;
        case 0x2ec:
            headText = "TBS_SH_HEAD_OBJECTIVE_HEALTH";
            bodyText = "TBS_SH_OBJECTIVE_HEALTH";
            break;
        case 0x2ed:
            headText = "TBS_SH_HEAD_BUYMOVES";
            bodyText = "TBS_SH_BUYMOVES";
            break;
        case 0x2ee:
            headText = "TBS_SH_HEAD_SMART_HINTS";
            bodyText = "TBS_SH_SMART_HINTS";
            break;
        case 0x2ef:
            headText = "TBS_SH_HEAD_BLONSKY_FILES";
            bodyText = "TBS_SH_BLONSKY_FILES";
            break;
        case 0x2f0:
            headText = "TBS_SH_HEAD_DEPENDENCIES";
            bodyText = "TBS_SH_DEPENDENCIES";
            break;
        case 0x2f1:
            headText = "TBS_SH_HEAD_BOSS_HEALTH";
            bodyText = "TBS_SH_BOSS_HEALTH";
            break;
        case 0x2f2:
            headText = "TBS_SH_HEAD_TIMER";
            bodyText = "TBS_SH_TIMER";
            break;
        case 0x2f3:
            headText = "TBS_SH_HEAD_NEWMISSION";
            bodyText = "TBS_SH_NEWMISSION";
            break;
        case 0x2f4:
            headText = "TBS_SH_HEAD_STRUGGLE";
            bodyText = "TBS_SH_STRUGGLE";
            break;
        case 0x2f5:
            headText = "TBS_SH_HEAD_ADRENALINE";
            bodyText = "TBS_SH_ADRENALINE";
            break;
        case 0x2f6:
            headText = "TBS_SH_HEAD_GRAB_THROW";
            bodyText = "TBS_SH_GRAB_THROW";
            break;
        case 0x2f7:
            headText = "TBS_SH_HEAD_STRIKE_COMBO";
            bodyText = "TBS_SH_STRIKE_COMBO";
            break;
        case 0x2f8:
            headText = "TBS_SH_HEAD_RUNNING";
            bodyText = "TBS_SH_RUNNING";
            break;
        case 0x2f9:
            headText = "TBS_SH_HEAD_FLOATER";
            bodyText = "TBS_SH_FLOATER";
            break;
        case 0x2fa:
            headText = "TBS_SH_HEAD_SUB_TARGETING";
            bodyText = "TBS_SH_SUB_TARGETING";
            break;
    }
    title->label.FUN_000f8500(headText, 0, 1);
    text->label.FUN_000f8500(bodyText, 0, 1);
    title->vfunc_3();
    text->vfunc_3();
}
