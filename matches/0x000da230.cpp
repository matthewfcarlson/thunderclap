// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_000da230 @ 0x000da230
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Locale {
    int FUN_000f7d30(const char* key);
    const char* FUN_000f7220(int id);
};

struct TextOwner {
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
    virtual Locale* v44();
};

struct Widget_da230 {
    int FUN_000f83f0(Locale* loc, int arg);
    char pad[0x38];
};

struct Settings_da230 {
    char pad[0x1bc8];
    char flag;
};

struct Singleton_4dd6ec {
    Settings_da230* FUN_00086280();
};

struct Screen_da230 {
    void FUN_000be310(const char* font, char* text, const float* a, const void* b, const void* c,
                      int n, const char* s1, const char* s2);
};

class FEMemCardControl_da230 {
public:
    void FUN_000da230(int idx);
    char p0[0x21c];
    int n21c;
    char p1[0x34c - 0x220];
    int offset;
    char p2[0x35c - 0x350];
    Widget_da230 widgets[1];
    char p3[0x3b0 - 0x35c - 0x38];
    char done;
    char p4[0x3ea - 0x3b1];
    char retryMode;
    char alt;
};

extern TextOwner* FUN_000fc3d0();
void FUN_000fc020(char* buf, int n, const char* fmt, ...);

void FEMemCardControl_da230::FUN_000da230(int idx)
{
    char buf[0x400];
    Screen_da230* screen = (Screen_da230*)FUN_000fc3d0();
    Locale* loc = ((TextOwner*)screen)->v44();
    const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30((*(const char**)&DAT_004de668)));
    int v = ((Widget_da230*)((char*)this + 0x35c + idx * 0x38))->FUN_000f83f0(loc, 0);
    FUN_000fc020(buf, 0x200, fmt, v);
    if (retryMode != 0) {
        const char* font;
        if (alt == 0) {
            if (DAT_004dd6ec->FUN_00086280()->flag != 0)
                font = (*(const char**)&DAT_004a0ce4);
            else
                font = (*(const char**)&DAT_004a0ce0);
        } else {
            font = (*(const char**)&DAT_004a0ce8);
        }
        screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), "TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE", "TBS_MENU_ITEM_RETRY", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
    } else {
        const char* font;
        if (alt == 0) {
            if (DAT_004dd6ec->FUN_00086280()->flag != 0)
                font = (*(const char**)&DAT_004a0ce4);
            else
                font = (*(const char**)&DAT_004a0ce0);
        } else {
            font = (*(const char**)&DAT_004a0ce8);
        }
        screen->FUN_000be310(font, buf, ((float*)&DAT_003f335c), ((float*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
    }
    done = 1;
    n21c = 0;
}
