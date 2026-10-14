// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_000d9180 @ 0x000d9180
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

struct Widget_d9180 {
    int FUN_000f83f0(Locale* loc, int arg);
    char pad[0x38];
};

struct Settings_d9180 {
    char pad[0x1bc8];
    char flag;
};

struct Singleton_d9180 {
    Settings_d9180* FUN_00086280();
};

struct Screen_d9180 {
    void FUN_000be310(const char* font, char* text, const float* a, const float* b, const char* name,
                      int n, const char* s1, const char* s2);
};

class Menu_d9180 {
public:
    void run(int idx);
    char p0[0x21c];
    int n21c;
    char p1[0x34c - 0x220];
    int offset;
    char p2[0x35c - 0x350];
    Widget_d9180 widgets[1];
    char p3[0x3b0 - 0x35c - 0x38];
    char done;
    char p4[0x3eb - 0x3b1];
    char alt;
};

extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern TextOwner* FUN_000fc3d0();
void FUN_000fc020(char* buf, int n, const char* fmt, ...);
extern const char* DAT_004a0c60;
extern const char* DAT_004a0ca4;
extern const char* DAT_004a0cc4;
extern const char* DAT_004a0ce0;
extern const char* DAT_004a0ce4;
extern const char* DAT_004a0ce8;
extern Singleton_d9180* DAT_004dd6ec;
extern float DAT_003f335c;

void Menu_d9180::run(int idx)
{
    unsigned int cookie = DAT_004d9968;
    char buf[0x400];
    Screen_d9180* screen = (Screen_d9180*)FUN_000fc3d0();
    Locale* loc = ((TextOwner*)screen)->v44();
    if (idx == 0) {
        int remaining = 4 - offset;
        const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30(DAT_004a0cc4));
        FUN_000fc020(buf, 0x200, fmt, remaining);
    } else {
        const char* fmt = loc->FUN_000f7220(loc->FUN_000f7d30(DAT_004a0ca4));
        int v = ((Widget_d9180*)((char*)this + 0x35c + idx * 0x38))->FUN_000f83f0(loc, 0);
        FUN_000fc020(buf, 0x200, fmt, v, 4);
    }
    const char* font;
    if (alt == 0) {
        if (DAT_004dd6ec->FUN_00086280()->flag != 0)
            font = DAT_004a0ce4;
        else
            font = DAT_004a0ce0;
    } else {
        font = DAT_004a0ce8;
    }
    screen->FUN_000be310(font, buf, &DAT_003f335c, &DAT_003f335c, "TBS_MENU_ITEM_OK", 2, DAT_004a0c60, DAT_004a0c60);
    done = 1;
    n21c = 0;
    __security_check_cookie(cookie);
}
