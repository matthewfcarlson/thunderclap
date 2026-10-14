// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CButtonCondition::vfunc_9 @ 0x0004b0d0
struct Input { unsigned int unknown; float value; };
extern bool __cdecl FUN_00018960(float a, float b, float tolerance);
struct CButtonCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual bool vfunc_9(Input* input);
    virtual bool FUN_00344f51(Input* input, float* value);
    char padding[12];
    unsigned int operation;
    float threshold;
};
bool CButtonCondition::vfunc_9(Input* input) {
    float value = input->value;
    if (!FUN_00344f51(input, &value)) return false;
    switch (operation) {
    case 0: return value < threshold;
    case 1: return value <= threshold;
    case 2: return FUN_00018960(value, threshold, 0.00001f);
    case 3: return !FUN_00018960(value, threshold, 0.00001f);
    case 4: return value >= threshold;
    case 5: return value > threshold;
    default: return false;
    }
}
