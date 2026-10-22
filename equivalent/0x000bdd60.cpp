// STATUS: equivalent (tools/equiv.py level 3: 20038 inputs, branch coverage 25/25)
// FUN_000bdd60 @ 0x000bdd60
#include "decls/address.h"
#include "decls/data/game/global.h"
// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
static inline int memcmp_inline(const void *a, const void *b, unsigned n)
{
    const unsigned char *p = (const unsigned char *)a;
    const unsigned char *q = (const unsigned char *)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}

class FEObject {
public:
    virtual void vfunc_0();
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_1();
    char pad04[0x3c - 4];
    unsigned int color;
};

class Screen_bdd60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *GetName();
};

class Gfx {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void SetVisible(int on);
};

struct Notifier_bdd60 { void FUN_0023f8f0(); };
struct Widget_bdd60 { void FUN_001bf8b0(); };
struct Overlay {
    void FUN_00293ef0();
    void FUN_00294080();
};


void FUN_000fc1a0();
Screen_bdd60 *FUN_000fc310();
FEObject *FUN_000fc260(const char *name);
float FUN_000186b0(float *v, float *lo, float *hi);

class Menu_bdd60 {
public:
    char pad0[0x10];
    unsigned int state;
    char pad14[0x20 - 0x14];
    Overlay *overlay;
    char pad24[0x5c - 0x24];
    Widget_bdd60 *widget;
    char pad60[0x1cfc - 0x60];
    float timer;
    void FUN_000bdd60();
};

void Menu_bdd60::FUN_000bdd60()
{
    overlay->FUN_00293ef0();
    if (state == 0) {
        FUN_000fc1a0();
        Screen_bdd60 *s = FUN_000fc310();
        if (s != 0) {
            if (memcmp_inline(s->GetName(), "blonsky_file", 13) == 0) {
                if (widget != 0)
                    widget->FUN_001bf8b0();
            }
        }
        (*(Notifier_bdd60**)&DAT_004dd6e8)->FUN_0023f8f0();
    } else if (state == 2 || state == 17) {
        DAT_0052c2a8->SetVisible(1);
        FUN_000fc1a0();
    } else if (state >= 18 && state <= 23) {
        FUN_000fc1a0();
        (*(Notifier_bdd60**)&DAT_004dd6e8)->FUN_0023f8f0();
    } else if (state == 9) {
        if (FUN_000fc310() != 0) {
            const char *name = FUN_000fc310()->GetName();
            if (name != 0) {
                if (memcmp_inline("fullscreen_message", name, 19) == 0 || memcmp_inline("mission_accept", name, 15) == 0) {
                    TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260("DynamicControlButtonLabel"));
                    if (label != 0) {
                        float hi = 1.0f;
                        float lo = 0.01f;
                        float v = (timer - 2.0f) * 8.0f;
                        label->color = ((unsigned int)(__int64)(int)(__int64)(FUN_000186b0(&v, &lo, &hi) * 255.0f) << 24) | 0xffffff;
                    }
                }
            }
        }
        FUN_000fc1a0();
    } else if (state == 10) {
        FUN_000fc1a0();
    }
    overlay->FUN_00294080();
}
