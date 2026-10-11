// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 22/22)
// FUN_000b86b0 @ 0x000b86b0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_000fc260(const char *name);
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
extern void *__cdecl FUN_000fc000(unsigned short *dst, int n, const char *src);

struct ScriptArgs {
    int tag;
    char text[10][0x40];
    int ints[10];
    char kinds[10];
    char pad2b6[2];
    void FUN_001d1630();
};

struct Script {
    int FUN_001d3b00(const char *name, ScriptArgs args);
    int FUN_001d27b0(const char *name);
};

extern Script *__cdecl FUN_001d4c90();

struct Label {
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
    void FUN_000f79a0(unsigned short *text, int flag);
    void FUN_000f7960();
};

struct Obj893 {
    char FUN_000893c0();
};

struct Obj54 {
    Obj893 *FUN_00086310();
};

struct Game {
    char pad00[0x54];
    Obj54 *f54;
};

extern Game *DAT_004dd700;

struct CodeTable {
    char FUN_00092860(int index);
    char *FUN_00093110(int index);
};

class CheatList {
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
    virtual void vfunc_19(Label *label, int a, int b);
    void FUN_000e36c0();
};

struct Frame {
    Label label;
    unsigned short text[0x40];
    char pad_ac[0x80];
    ScriptArgs args;
    unsigned int cookie;
};

class CheatMenu {
public:
    char pad00[0x4c];
    CodeTable *codes;
    void FUN_000b86b0();
};

void CheatMenu::FUN_000b86b0()
{
    Frame f;
    f.cookie = DAT_004d9968;
    CheatList *list = (CheatList *)FUN_00344e74(FUN_000fc260("cheat_code_list"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (list) {
        list->FUN_000e36c0();
        for (int i = 0; i <= 0x31; i++) {
            if (codes->FUN_00092860(i)) {
                if (i == 3) {
                    if (!DAT_004dd700->f54->FUN_00086310()->FUN_000893c0())
                        continue;
                } else if (i == 1) {
                    if (codes->FUN_00092860(0x21))
                        continue;
                } else {
                    Script *script = FUN_001d4c90();
                    f.args.FUN_001d1630();
                    f.args.tag = 1;
                    FUN_00267760(f.args.text[0], 0x40, "%d", i);
                    if (script->FUN_001d3b00("kmcIsCheatComicCollected", f.args) != 3 ||
                        !script->FUN_001d27b0("__IS_CHEAT_COMIC_COLLECTED__"))
                        continue;
                }
            }
            char *name = codes->FUN_00093110(i);
            if (!name || !*name)
                continue;
            FUN_000fc000(f.text, 0x80, name);
            f.label.FUN_000f7930();
            f.label.FUN_000f79a0(f.text, 0);
            list->vfunc_19(&f.label, 0, 0);
            f.label.FUN_000f7960();
        }
        list->vfunc_3();
    }
    __security_check_cookie(f.cookie);
}
