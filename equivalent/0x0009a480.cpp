// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_0009a480 @ 0x0009a480
struct Target { void FUN_000a0bc0(float v); };
struct State { int FUN_00088fa0(); };
struct Provider { char pad[0x80]; State state; };
struct Root { Provider* FUN_00086310(); };
struct Globals { char pad[0x54]; Root* root; };
extern Globals* DAT_004dd700;

struct Slider {
    char pad0[0xb8];
    Target* target;
    void FUN_0009a480(float v);
};

void Slider::FUN_0009a480(float v) {
    if (DAT_004dd700->root->FUN_00086310()->state.FUN_00088fa0() != 10 || target == 0)
        return;
    if (v >= 5.0f) {
        if (v > 100.0f)
            v = 100.0f;
    } else {
        v = 5.0f;
    }
    target->FUN_000a0bc0(v);
}
