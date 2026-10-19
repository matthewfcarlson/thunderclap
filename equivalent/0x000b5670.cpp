// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 3/3)
// FUN_000b5670 @ 0x000b5670
// cl-flags: /GS

struct Label_b5670 {
    void FUN_000f79a0(const char *text, int flag);
};

struct Texts_b5670 {
    int FUN_000f7d30(const char *id);
    const char *FUN_000f7220(int index);
};

class Panel_b5670 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x18 - 4];
    Label_b5670 label;
};

extern Panel_b5670 *__cdecl FUN_000fc260(const char *name);
extern Texts_b5670 *__cdecl FUN_000fc1b0();
extern int __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);

void __stdcall FUN_000b5670(int amount)
{
    struct Frame {
        char pad[4];
        char text[0xfc];
    } f;

    Panel_b5670 *panel = FUN_000fc260("side_mission_success_smash_award");
    if (panel != 0) {
        Texts_b5670 *texts = FUN_000fc1b0();
        FUN_000fc020(f.text, 0x80, texts->FUN_000f7220(texts->FUN_000f7d30("TBS_SMASH_POINT_AWARD")), amount);
        panel->label.FUN_000f79a0(f.text, 0);
        panel->vfunc_3();
    }
}
