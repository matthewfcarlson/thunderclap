// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_000b5250 @ 0x000b5250
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Locale {
    int FUN_000f7d30(const char *key);
    const char *FUN_000f7220(int id);
};

struct TextEntry_b5250 {
    void FUN_000f79a0(const char *text, int flag);
};

Locale *__cdecl FUN_000fc1b0();
void __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);
void __cdecl FUN_000fc000(char *buf, int size, const char *fmt, ...);

void __stdcall FUN_000b5250(TextEntry_b5250 *entry, const char *key, const char *k2, const char *k3,
                            const char *k4, const char *k5, const char *k6, const char *k7)
{
    unsigned int cookie = DAT_004d9968;
    char buf[0x100];
    Locale *L;
    int id;
    const char *a2;
    const char *a3;
    const char *a4;
    const char *a5;
    const char *a6;
    const char *a7;

    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(key);
    const char *text = L->FUN_000f7220(id);
    a2 = k2;
    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(k2);
    if (L->FUN_000f7220(id) != 0) {
        L = FUN_000fc1b0();
        id = L->FUN_000f7d30(k2);
        a2 = L->FUN_000f7220(id);
    }
    a3 = k3;
    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(k3);
    if (L->FUN_000f7220(id) != 0) {
        L = FUN_000fc1b0();
        id = L->FUN_000f7d30(k3);
        a3 = L->FUN_000f7220(id);
    }
    a4 = k4;
    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(k4);
    if (L->FUN_000f7220(id) != 0) {
        L = FUN_000fc1b0();
        id = L->FUN_000f7d30(k4);
        a4 = L->FUN_000f7220(id);
    }
    a5 = k5;
    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(k5);
    if (L->FUN_000f7220(id) != 0) {
        L = FUN_000fc1b0();
        id = L->FUN_000f7d30(k5);
        a5 = L->FUN_000f7220(id);
    }
    a6 = k6;
    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(k6);
    if (L->FUN_000f7220(id) != 0) {
        L = FUN_000fc1b0();
        id = L->FUN_000f7d30(k6);
        a6 = L->FUN_000f7220(id);
    }
    a7 = k7;
    L = FUN_000fc1b0();
    id = L->FUN_000f7d30(k7);
    if (L->FUN_000f7220(id) != 0) {
        L = FUN_000fc1b0();
        id = L->FUN_000f7d30(k7);
        a7 = L->FUN_000f7220(id);
    }

    if (text != 0)
        FUN_000fc020(buf, 0x100, text, a2, a3, a4, a5, a6, a7);
    else
        FUN_000fc000(buf, 0x100, key, a2, a3, a4, a5, a6, a7);
    entry->FUN_000f79a0(buf, 0);
    __security_check_cookie(cookie);
}
