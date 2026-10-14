// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001f7080 @ 0x001f7080
struct Id64 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Mat4 {
    float m[16];
    void FUN_0022b980();
};
struct Fx {
    int FUN_00283a40(Id64 *id, Mat4 *m, float a, float b);
    void FUN_0027ffb0(int handle);
};
Fx *FUN_0027f250();
struct Weather {
    char pad[0x4c];
    char rainOn; char dustOn;
    int hRain; int hDust;
    char Toggle(char on);
};
char Weather::Toggle(char on) {
    char was = dustOn;
    dustOn = on;
    Fx *fx = FUN_0027f250();
    if (fx) {
        if (on) {
            if (!was) {
                Mat4 m;
                m.FUN_0022b980();
                Id64 id;
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
