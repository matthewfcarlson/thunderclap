struct InputPoint {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
struct Controller_b0f20 {
    char pad0[0x54];
    unsigned int id;
    char pad1[0x490 - 0x58];
    float minimum;
    float maximum;
};
struct Result_b0f20 {
    float value;
    unsigned int id;
    InputPoint* point;
};
struct sControllerInputPointCallback {
    virtual void vfunc_0(unsigned int unused, float value);
    InputPoint* point;
    Controller_b0f20* controller;
    Result_b0f20* result;
};
void sControllerInputPointCallback::vfunc_0(unsigned int unused, float value) {
    point->slot3();
    float low = controller->minimum;
    float high = controller->maximum;
    float normalized;
    if (value < low)
        normalized = 0.0f;
    else if (value > high)
        normalized = 1.0f;
    else
        normalized = (value - low) / (high - low);
    union Bits {
        float f;
        unsigned int u;
    } a, b;
    a.f = normalized;
    a.u &= 0x7fffffff;
    b.f = result->value;
    b.u &= 0x7fffffff;
    if (a.f > b.f) {
        result->value = normalized;
        result->point = point;
        result->id = controller->id;
    }
}
