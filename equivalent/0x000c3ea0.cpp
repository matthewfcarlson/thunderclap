// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_000c3ea0 @ 0x000c3ea0
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f4a4[];

struct Widget;
extern Widget* __cdecl FUN_000fc260(const char* name);
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern bool FUN_00035da0();

class Selector_c3ea0 {
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
struct Flag_c3ea0 {
    char pad[5];
    unsigned char value;
};
struct Button_c3ea0 {
    char pad[0x74];
    unsigned char f74;
    char pad75[0x141 - 0x75];
    unsigned char f141;
};
struct Panel_c3ea0 {
    unsigned char FUN_000893c0();
};
struct Inner_c3ea0 {
    void FUN_000adc30();
};
struct Holder_c3ea0 {
    Inner_c3ea0* FUN_000b3ec0(int index);
};
class Screen_c3ea0 {
  public:
    char pad[0x34];
    Panel_c3ea0* panel;
    char pad38[0x44 - 0x38];
    Flag_c3ea0* flag;
    char pad48[0x60 - 0x48];
    Holder_c3ea0* holder;
    void FUN_000b5ad0();
    void FUN_000b5b90();
    void FUN_000b63a0();
    void FUN_000b64f0();
    void FUN_000b7660();
    void FUN_000b7cd0();
    void FUN_000b8240();
    void FUN_000b86b0();
    void FUN_000b8860();
    void FUN_000b9930();
    void FUN_000b9ad0();
    void FUN_000b9bf0();
    void FUN_000ba040();
    void FUN_000bb600();
    void FUN_000c3ce0();
    void FUN_000c21b0(int id);
    void FUN_000c3ea0();
};
void Screen_c3ea0::FUN_000c3ea0() {
    Selector_c3ea0* vibration = (Selector_c3ea0*)FUN_00344e74(FUN_000fc260("control_config_vibration_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (vibration && flag)
        vibration->vfunc_25(flag->value == 0);
    FUN_000b5ad0();
    Selector_c3ea0* targeting = (Selector_c3ea0*)FUN_00344e74(FUN_000fc260("targeting_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (targeting) {
        bool off = FUN_00035da0() == 0;
        targeting->vfunc_25(off);
    }
    holder->FUN_000b3ec0(0)->FUN_000adc30();
    FUN_000c3ce0();
    FUN_000b9930();
    FUN_000b5b90();
    FUN_000b9ad0();
    FUN_000b9bf0();
    FUN_000b63a0();
    FUN_000b64f0();
    FUN_000b7660();
    FUN_000bb600();
    FUN_000c21b0(0x266);
    FUN_000c21b0(0x34);
    FUN_000b7cd0();
    FUN_000b8240();
    FUN_000b86b0();
    Button_c3ea0* replay = (Button_c3ea0*)FUN_00344e74(FUN_000fc260("replay_story_mode_button"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    if (panel && replay) {
        unsigned char v = panel->FUN_000893c0();
        replay->f141 = v;
        replay->f74 = v;
    }
    FUN_000b8860();
    FUN_000ba040();
}
