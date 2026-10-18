// FUN_001f7080 @ 0x001f7080
struct Id64_1f7080 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Mat4_1f7080 {
    float m[16];
    void FUN_0022b980();
};
struct Fx_1f7080 {
    int FUN_00283a40(Id64_1f7080 *id, Mat4_1f7080 *m, float a, float b);
    void FUN_0027ffb0(int handle);
};
Fx_1f7080 *FUN_0027f250();
struct Weather_1f7080 {
    char pad[0x4c];
    char rainOn; char dustOn;
    int hRain; int hDust;
    char Toggle(char on);
};
char Weather_1f7080::Toggle(char on) {
    char was = dustOn;
    dustOn = on;
    Fx_1f7080 *fx = FUN_0027f250();
    if (fx) {
        if (on) {
            if (!was) {
                Mat4_1f7080 m;
                m.FUN_0022b980();
                Id64_1f7080 id;
                id.FUN_0027b0e0("outskirtsDustStorm");
                hDust = fx->FUN_00283a40(&id, &m, -1.0f, 1.0f);
                id.FUN_0027af50();
            }
        } else {
            fx->FUN_0027ffb0(hDust);
        }
    }
    return was;
}
