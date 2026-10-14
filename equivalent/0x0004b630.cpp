// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CAxisArcCondition::vfunc_10 @ 0x0004b630
// CAxisArcCondition::vfunc_10 @ 0x0004b630: compares the axis value against the stored limit with the configured test
bool FUN_00018960(float a, float b, float epsilon);

struct AxisInput {
    char pad00[0x18];
    float value;
    int state;
};

class CAxisArcCondition {
public:
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
    virtual bool vfunc_10(AxisInput *input, int *outState);
    char pad04[0x14];
    unsigned int mode;
    float limit;
};

bool CAxisArcCondition::vfunc_10(AxisInput *input, int *outState)
{
    *outState = input->state;
    switch (mode) {
    case 0:
        return input->value < limit;
    case 1:
        return input->value <= limit;
    case 2:
        return FUN_00018960(input->value, limit, 1.0e-5f);
    case 3:
        return !FUN_00018960(input->value, limit, 1.0e-5f);
    case 4:
        return input->value >= limit;
    case 5:
        return input->value > limit;
    default:
        return false;
    }
}
