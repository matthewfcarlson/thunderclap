// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 75/76, incomplete)
// FUN_000b7cd0 @ 0x000b7cd0
extern "C" int strcmp(const char* a, const char* b);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct Text_b7cd0 {
    char pad[0x24];
    void FUN_000f7930();
    void FUN_000f79a0(const unsigned short* s, int n);
    void FUN_000f7960();
};

struct Ui_b7cd0 {
    int FUN_000f7d30(const char* name);
    const unsigned short* FUN_000f7220(int index);
};

class UiMgr_b7cd0 {
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
    virtual Ui_b7cd0* v44();
};

class FEObject {
public:
    virtual void v0();
};

class FEControl : public FEObject {
public:
    virtual void v1();
    virtual void v2();
};

class TextSelector : public FEControl {
public:
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
    virtual void v19(Text_b7cd0* item, int a, int b);
    void FUN_000e36c0();
};

struct Unlocks_b7cd0 {
    bool FUN_00092860(int id);
};

FEObject* FUN_000fc260(const char* name);
UiMgr_b7cd0* FUN_000fc3d0();
void FUN_000964a0(char* buf, int size, const char* fmt, ...);
void FUN_000fc020(unsigned short* buf, int count, const unsigned short* fmt, ...);

struct Frame_b7cd0 {
    int count;
    TextSelector* menu;
    const char** np;
    const char* cur;
    int* out;
    void* self;
    Ui_b7cd0* ui;
    const char* names[6];
    Text_b7cd0 text;
    char header[0x40];
    unsigned short label[0x80];
    unsigned int cookie;
};

class HintMenu_b7cd0 {
public:
    char pad00[0x4c];
    Unlocks_b7cd0* unlocks;
    char pad50[0x1a0c - 0x50];
    int ids[64];
    void FUN_000b7cd0();
};

void HintMenu_b7cd0::FUN_000b7cd0()
{
    Frame_b7cd0 f;
    f.cookie = DAT_004d9968;
    f.self = this;
    f.menu = dynamic_cast<TextSelector*>(FUN_000fc260("hint_selector"));
    if (f.menu != 0) {
        f.menu->FUN_000e36c0();
        f.names[0] = "SMASH";
        f.names[1] = "COMBAT";
        f.names[2] = "ADVANCED_COMBAT";
        f.names[3] = "TARGET";
        f.names[4] = "MOVEMENT";
        f.names[5] = 0;
        f.ui = FUN_000fc3d0()->v44();
        f.count = 0;
        f.np = f.names;
        f.cur = f.names[0];
        do {
            f.out = &ids[f.count];
            int n = 0;
            int id = 0x8e;
            do {
                if (!unlocks->FUN_00092860(id)) {
                    const char* cat = 0;
                    if (id >= 0x8f && id <= 0x94)
                        cat = "SMASH";
                    if (id >= 0x95 && id <= 0x98)
                        cat = "SMASH";
                    if (id >= 0x99 && id <= 0x9b)
                        cat = "ADVANCED_COMBAT";
                    if (id >= 0x9c && id <= 0xa1)
                        cat = "SMASH";
                    if (id >= 0xa2 && id <= 0xa4)
                        cat = "SMASH";
                    if (id >= 0xa5 && id <= 0xa9)
                        cat = "TARGET";
                    if (id >= 0xaa && id <= 0xae)
                        cat = "ADVANCED_COMBAT";
                    if (id >= 0xaf && id <= 0xb3)
                        cat = "MOVEMENT";
                    if (id >= 0xb4 && id <= 0xc7)
                        cat = "COMBAT";
                    if (id >= 0xc8 && id <= 0xcb)
                        cat = "MOVEMENT";
                    if (id >= 0xcc && id <= 0xcf)
                        cat = "MOVEMENT";
                    if (id >= 0xd0 && id <= 0xd0)
                        cat = "ADVANCED_COMBAT";
                    if (id >= 0xd1 && id <= 0xd8)
                        cat = "TARGET";
                    if (id >= 0xd9 && id <= 0xdd)
                        cat = "ADVANCED_COMBAT";
                    if (cat != 0 && strcmp(cat, f.cur) == 0) {
                        n++;
                        FUN_000964a0(f.header, 0x40, "TBS_HINT_HEADER_%s", cat);
                        FUN_000fc020(f.label, 0x80, f.ui->FUN_000f7220(f.ui->FUN_000f7d30(f.header)), n);
                        f.text.FUN_000f7930();
                        f.text.FUN_000f79a0(f.label, 0);
                        f.menu->v19(&f.text, 0, 0);
                        *f.out = id;
                        f.count++;
                        f.out++;
                        f.text.FUN_000f7960();
                    }
                }
                id++;
            } while (id <= 0xde);
            f.np++;
            f.cur = *f.np;
        } while (f.cur != 0);
        f.menu->v3();
    }
    __security_check_cookie(f.cookie);
}
