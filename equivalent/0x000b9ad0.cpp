// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_000b9ad0 @ 0x000b9ad0
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f4d8[];

struct Widget;
extern Widget* __cdecl FUN_000fc260(const char* name);
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Slider {
    void FUN_000f1a70(float value);
};
class Selector {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int value);
};
struct Settings {
    float FUN_001eba70();
    float FUN_001eb9d0();
    float FUN_001eba20();
    int FUN_001ebac0();
};
class OptionsMenu {
  public:
    char pad[0x3c];
    Settings* settings;
    char pad40[0x1a06 - 0x40];
    unsigned char ready;
    void FUN_000b9ad0();
};
void OptionsMenu::FUN_000b9ad0() {
    if (!settings) {
        ready = 1;
        return;
    }
    Slider* dialogue = (Slider*)FUN_00344e74(FUN_000fc260("DialogueVolumeSlider"), 0, DAT_0049dba4, DAT_0049f4d8, 0);
    Slider* music = (Slider*)FUN_00344e74(FUN_000fc260("MusicVolumeSlider"), 0, DAT_0049dba4, DAT_0049f4d8, 0);
    Slider* fx = (Slider*)FUN_00344e74(FUN_000fc260("SoundFXVolumeSlider"), 0, DAT_0049dba4, DAT_0049f4d8, 0);
    Selector* surround = (Selector*)FUN_00344e74(FUN_000fc260("SurroundSelector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (dialogue)
        dialogue->FUN_000f1a70(settings->FUN_001eba70());
    if (music)
        music->FUN_000f1a70(settings->FUN_001eb9d0());
    if (fx)
        fx->FUN_000f1a70(settings->FUN_001eba20());
    if (surround)
        surround->vfunc_25(settings->FUN_001ebac0());
    ready = 0;
}
