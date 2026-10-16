// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d4ae0 @ 0x000d4ae0
#include "decls/data/game/global.h"

struct Clock_d4ae0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float Period();
};

struct Timer {
    char pad0[0x24];
    Clock_d4ae0 *clock;
};

struct Profile_d4ae0 {
    char pad0[0x88];
    int cur;
};


void __cdecl FUN_00294b80(char *text);
int __cdecl FUN_000fb830(char *buf, int size, char *text, float value, int extra);
void __cdecl FUN_000fb690(char *dst, char *src, int size);

class Formatter_d4ae0 {
public:
    char pad0[0xc];
    Timer *timer;
    int FUN_000d4ae0(char *text, Profile_d4ae0 *prof, int extra);
};

int Formatter_d4ae0::FUN_000d4ae0(char *text, Profile_d4ae0 *prof, int extra)
{
    FUN_00294b80(text);
    int r = FUN_000fb830(DAT_004de100, 0x100, text,
                         16.0f / ((14.0f / timer->clock->Period()) * *(float *)((char *)prof + prof->cur * 16 + 8)),
                         extra);
    FUN_000fb690(text, DAT_004de100, 0x100);
    return r;
}
