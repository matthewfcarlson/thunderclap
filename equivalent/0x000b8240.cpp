// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 42/42)
// FUN_000b8240 @ 0x000b8240
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);

struct Label_b8240 {
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
    void FUN_000f7930();
    void FUN_000f8500(const char *text, int a, char flag);
    void FUN_000f7960();
};

class Anim_b8240 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
};
Anim_b8240 *__cdecl FUN_000fc3d0();

class HintList {
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(Label_b8240 *label, int a, int b);
    void FUN_000e36c0();
};

struct CodeTable_b8240 {
    char FUN_00092860(int index);
};

class HintMenu_b8240 {
public:
    char pad00[0x4c];
    CodeTable_b8240 *codes;        // 0x4c
    char pad50[0x1b50 - 0x50];
    int shown[32];           // 0x1b50
    void FUN_000b8240();
};

void HintMenu_b8240::FUN_000b8240()
{
    Label_b8240 label;
    HintList *list = (HintList *)FUN_00344e74(FUN_000fc260("smart_hint_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (list) {
        list->FUN_000e36c0();
        FUN_000fc3d0()->v44();
        int *out = shown;
        for (int id = 0x2e9; id <= 0x2fd; id++) {
            if (codes->FUN_00092860(id))
                continue;
            const char *name = 0;
            switch (id) {
            case 0x2e9: name = "TBS_SH_HEAD_COLLECTIBLE_BOSSMARKER"; break;
            case 0x2ea: name = "TBS_SH_HEAD_CHASE_HUD"; break;
            case 0x2eb: name = "TBS_SH_HEAD_STORY_MODE"; break;
            case 0x2ec: name = "TBS_SH_HEAD_OBJECTIVE_HEALTH"; break;
            case 0x2ed: name = "TBS_SH_HEAD_BUYMOVES"; break;
            case 0x2ee: name = "TBS_SH_HEAD_SMART_HINTS"; break;
            case 0x2ef: name = "TBS_SH_HEAD_BLONSKY_FILES"; break;
            case 0x2f0: name = "TBS_SH_HEAD_DEPENDENCIES"; break;
            case 0x2f1: name = "TBS_SH_HEAD_BOSS_HEALTH"; break;
            case 0x2f2: name = "TBS_SH_HEAD_TIMER"; break;
            case 0x2f3: name = "TBS_SH_HEAD_NEWMISSION"; break;
            case 0x2f4: name = "TBS_SH_HEAD_STRUGGLE"; break;
            case 0x2f5: name = "TBS_SH_HEAD_ADRENALINE"; break;
            case 0x2f6: name = "TBS_SH_HEAD_GRAB_THROW"; break;
            case 0x2f7: name = "TBS_SH_HEAD_STRIKE_COMBO"; break;
            case 0x2f8: name = "TBS_SH_HEAD_RUNNING"; break;
            case 0x2f9: name = "TBS_SH_HEAD_FLOATER"; break;
            case 0x2fa: name = "TBS_SH_HEAD_SUB_TARGETING"; break;
            }
            if (name == 0)
                continue;
            label.FUN_000f7930();
            label.FUN_000f8500(name, 0, 1);
            list->vfunc_19(&label, 0, 0);
            *out = id;
            out++;
            label.FUN_000f7960();
        }
        list->vfunc_3();
    }
}
