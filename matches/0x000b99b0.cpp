extern char DAT_0049dba4;
extern char DAT_0049dbbc;
extern char DAT_0049f4d8;
extern void* __cdecl FUN_000fc260(const char*);
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Slider {
    void FUN_000f1a70(float);
};
struct Selector {
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
    virtual void v25(int);
};
struct Audio {
    float FUN_001eba70();
    float FUN_001eb9d0();
    float FUN_001eba20();
    int FUN_001ebac0();
};
struct Target {
    char pad[0x3c];
    Audio* audio;
    void update();
};
void Target::update() {
    if (!audio)
        return;
    Slider* dialogue =
        (Slider*)FUN_00344e74(FUN_000fc260("DialogueVolumeSlider"), 0, &DAT_0049dba4, &DAT_0049f4d8, 0);
    Slider* music =
        (Slider*)FUN_00344e74(FUN_000fc260("MusicVolumeSlider"), 0, &DAT_0049dba4, &DAT_0049f4d8, 0);
    Slider* effects =
        (Slider*)FUN_00344e74(FUN_000fc260("SoundFXVolumeSlider"), 0, &DAT_0049dba4, &DAT_0049f4d8, 0);
    Selector* surround =
        (Selector*)FUN_00344e74(FUN_000fc260("SurroundSelector"), 0, &DAT_0049dba4, &DAT_0049dbbc, 0);
    if (dialogue)
        dialogue->FUN_000f1a70(audio->FUN_001eba70());
    if (music)
        music->FUN_000f1a70(audio->FUN_001eb9d0());
    if (effects)
        effects->FUN_000f1a70(audio->FUN_001eba20());
    if (surround)
        surround->v25(audio->FUN_001ebac0());
}