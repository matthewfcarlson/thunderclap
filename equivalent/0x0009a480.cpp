// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_0009a480 @ 0x0009a480
struct Target_9a480 { void FUN_000a0bc0(float v); };
struct State_9a480 { int FUN_00088fa0(); };
struct Provider_9a480 { char pad[0x80]; State_9a480 state; };
struct Root_9a480 { Provider_9a480* FUN_00086310(); };
struct Globals_9a480 { char pad[0x54]; Root_9a480* root; };
extern Globals_9a480* DAT_004dd700;

struct Slider_9a480 {
    char pad0[0xb8];
    Target_9a480* target;
    void FUN_0009a480(float v);
};

void Slider_9a480::FUN_0009a480(float v) {
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
