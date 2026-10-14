// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 16/16)
// FUN_001c0ab0 @ 0x001c0ab0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;
extern "C" int strcmp(const char *a, const char *b);

extern const char *DAT_004c4c5c;
extern const char *DAT_004c4c60;
extern const char *DAT_004c4c64;
extern const char *DAT_004c4c70;
extern const char *DAT_004c4c74;
extern const char *DAT_004c4c78;

int __cdecl FUN_00266da0(int id);
int __cdecl FUN_000f7120(int handle);
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct Label_1c0ab0 {
    void FUN_000f7110();
    void FUN_000f7a80(const char *text);
};

struct Printer_1c0ab0 {
    void FUN_001d3600(const char *text, int flag);
};
Printer_1c0ab0 *__cdecl FUN_001d4c90();

struct Slot_1c0ab0 {
    int pad0[2];
    int f8;
    char fc;
    char padd[3];
    int f10;
    int f14;
    char pad18[4];
    short f1c;
};

class Menu_1c0ab0 {
public:
    char pad00[0x2c];
    Slot_1c0ab0 *slot;              // 0x2c
    char pad30[4];
    Label_1c0ab0 *labelA;           // 0x34
    Label_1c0ab0 *labelB;           // 0x38
    int hasPrinter;          // 0x3c
    int f40;
    char pad44[4];
    int handle;              // 0x48
    char pad4c[0x54 - 0x4c];
    char flag54;

    void FUN_001c0360(int a, int b);
    void FUN_001c0ab0(const char *name);
};

void Menu_1c0ab0::FUN_001c0ab0(const char *name)
{
    unsigned int cookie = DAT_004d9968;
    char buf[0x40];
    int tok = FUN_00266da0(0xe);
    FUN_001c0360(2, 0);
    int h = FUN_000f7120(handle);
    if (h == 0) {
        FUN_00266da0(tok);
        __security_check_cookie(cookie);
        return;
    }

    if (strcmp(name, "fe") == 0) {
        flag54 = 1;
        if (labelA != 0) {
            labelA->FUN_000f7110();
            FUN_000964a0(buf, 0x40, DAT_004c4c64, h);
            labelA->FUN_000f7a80(buf);
        }
        if (hasPrinter != 0) {
            f40 = 0;
            Printer_1c0ab0 *p = FUN_001d4c90();
            int t2 = FUN_00266da0(1);
            p->FUN_001d3600(DAT_004c4c70, 0);
            FUN_00266da0(t2);
        }
    } else {
        flag54 = 0;
        if (labelA != 0) {
            labelA->FUN_000f7110();
            FUN_000964a0(buf, 0x40, DAT_004c4c5c, h);
            labelA->FUN_000f7a80(buf);
        }
        if (labelB != 0) {
            labelB->FUN_000f7110();
            FUN_000964a0(buf, 0x40, DAT_004c4c74, name, name, h);
            labelB->FUN_000f7a80(buf);
        }
        if (hasPrinter != 0) {
            f40 = 0;
            Printer_1c0ab0 *p = FUN_001d4c90();
            int t2 = FUN_00266da0(1);
            p->FUN_001d3600(DAT_004c4c60, 0);
            FUN_000964a0(buf, 0x40, DAT_004c4c78, name, name);
            p->FUN_001d3600(buf, 0);
            FUN_00266da0(t2);
        }
    }

    Slot_1c0ab0 *s = slot;
    if (s != 0) {
        s->fc = 0;
        s->f10 = 0;
        s->f8 = 0;
        s->f14 = 0;
        s->f1c = 0;
    }
    FUN_00266da0(tok);
    __security_check_cookie(cookie);
}
