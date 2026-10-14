struct Fader_1b7170 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(float);
    virtual float vf11();
};
struct Overlay {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(int);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58(int);
};
struct Screen_1b7170 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};
struct Global2b4 {
    char pad[0xd8];
    int field_d8;
    void FUN_0028f9a0();
    void FUN_0028faf0(int);
};
struct Global700 {
    char pad[0x50];
    struct Sub_1b7170* sub;
};
struct Sub_1b7170 {
    void FUN_001bf8b0();
};
extern Screen_1b7170* DAT_0052c2a4;
extern Overlay* DAT_0052c2a8;
extern Global2b4* DAT_0052c2b4;
extern Global700* DAT_004dd700;
class CRadMovieRenderLoop {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Fader_1b7170* fader);
    int fade;
    void FUN_001b6fd0(int);
};
void CRadMovieRenderLoop::vfunc_3(Fader_1b7170* fader) {
    DAT_0052c2a4->vf14();
    DAT_0052c2b4->field_d8 = -1;
    DAT_0052c2a8->vf58(0);
    DAT_0052c2a8->vf12(7);
    DAT_0052c2b4->FUN_0028f9a0();
    fader->vf4();
    if (fade == -1)
        FUN_001b6fd0(0xff);
    DAT_004dd700->sub->FUN_001bf8b0();
    if (fade >= 0) {
        float frac = (float)(10 - fade) * 0.1f;
        FUN_001b6fd0((int)(frac * 255.0f));
        fade--;
        float level = fader->vf11() - 0.1f;
        if (level < 0.0f)
            level = 0.0f;
        fader->vf10(level);
    }
    DAT_0052c2b4->FUN_0028faf0(0);
}
