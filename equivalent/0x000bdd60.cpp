// STATUS: equivalent (tools/equiv.py level 3: 12031 inputs, branch coverage 25/25; run with --inputs 12000)
// FUN_000bdd60 @ 0x000bdd60
extern "C" int memcmp(const void *a, const void *b, unsigned int n);

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

class Screen {
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

class Presenter {
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

struct Notifier { void FUN_0023f8f0(); };
struct Widget { void FUN_001bf8b0(); };
struct Overlay {
    void FUN_00293ef0();
    void FUN_00294080();
};

extern Presenter *DAT_0052c2a8;
extern Notifier *DAT_004dd6e8;

void FUN_000fc1a0();
Screen *FUN_000fc310();
FEObject *FUN_000fc260(const char *name);
float FUN_000186b0(float *v, float *lo, float *hi);

class Menu {
public:
    char pad0[0x10];
    unsigned int state;
    char pad14[0x20 - 0x14];
    Overlay *overlay;
    char pad24[0x5c - 0x24];
    Widget *widget;
    char pad60[0x1cfc - 0x60];
    float timer;
    void FUN_000bdd60();
};

void Menu::FUN_000bdd60()
{
    overlay->FUN_00293ef0();
    if (state == 0) {
        FUN_000fc1a0();
        Screen *s = FUN_000fc310();
        if (s != 0) {
            if (memcmp(s->GetName(), "blonsky_file", 13) == 0) {
                if (widget != 0)
                    widget->FUN_001bf8b0();
            }
        }
        DAT_004dd6e8->FUN_0023f8f0();
    } else if (state == 2 || state == 17) {
        DAT_0052c2a8->SetVisible(1);
        FUN_000fc1a0();
    } else if (state >= 18 && state <= 23) {
        FUN_000fc1a0();
        DAT_004dd6e8->FUN_0023f8f0();
    } else if (state == 9) {
        if (FUN_000fc310() != 0) {
            const char *name = FUN_000fc310()->GetName();
            if (name != 0) {
                if (memcmp("fullscreen_message", name, 19) == 0 || memcmp("mission_accept", name, 15) == 0) {
                    TextLabel *label = dynamic_cast<TextLabel *>(FUN_000fc260("DynamicControlButtonLabel"));
                    if (label != 0) {
                        float hi = 1.0f;
                        float lo = 0.01f;
                        float v = (timer - 2.0f) * 8.0f;
                        label->color = ((unsigned int)(int)(FUN_000186b0(&v, &lo, &hi) * 255.0f) << 24) | 0xffffff;
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
