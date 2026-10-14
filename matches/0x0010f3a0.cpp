struct Pair_10f3a0 {
    unsigned int first, second;
};
struct Settings_10f3a0 {
    char pad[24];
    Pair_10f3a0 pair;
    float value;
};
struct ActorState_10f3a0 {
    void FUN_00059a30();
};
struct Actor_10f3a0 {
    ActorState_10f3a0* FUN_000592a0();
};
struct Manager_10f3a0 {
    void FUN_00067730();
    float FUN_000670e0(Pair_10f3a0*);
    void FUN_000670a0(Pair_10f3a0*, int);
};
Manager_10f3a0* __cdecl FUN_000678d0();
struct StaticObject {
    char data[8];
    void FUN_0027af00();
};
extern StaticObject DAT_004e0bf0;
extern unsigned int DAT_004e0bf8;
void __cdecl FUN_00363ec0();
int __cdecl _atexit(void(__cdecl*)());
namespace hulkfight {
namespace ai {
struct HulkAction {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[24];
    Settings_10f3a0* settings;
    Actor_10f3a0* actor;
};
void HulkAction::vfunc_4() {
    if (!actor)
        return;
    if (!(DAT_004e0bf8 & 1)) {
        DAT_004e0bf8 |= 1;
        DAT_004e0bf0.FUN_0027af00();
        _atexit(FUN_00363ec0);
    }
    actor->FUN_000592a0()->FUN_00059a30();
    FUN_000678d0()->FUN_00067730();
    float value;
    Pair_10f3a0 pair;
    if (settings->value == 0.0f)
        value = 1.0f;
    else if (settings->value < 0.0f) {
        pair = settings->pair;
        value = -FUN_000678d0()->FUN_000670e0(&pair);
    } else
        value = settings->value;
    pair = settings->pair;
    int result = (int)value;
    FUN_000678d0()->FUN_000670a0(&pair, result);
}
} // namespace ai
} // namespace hulkfight
