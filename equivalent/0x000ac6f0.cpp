// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000ac6f0 @ 0x000ac6f0
float __stdcall FUN_000ac6a0(float t);

class Curve_ac6f0 {
public:
    char mode;
    char pad01[3];
    float constant;
    float start;
    float length;
    char pad10[4];
    float before;
    float after;
    char dirty;
    void FUN_000ac610();
    float Evaluate(float t, float end);
};

float Curve_ac6f0::Evaluate(float t, float end)
{
    if (mode == 0)
        return constant;
    if (dirty) {
        FUN_000ac610();
        dirty = 0;
    }
    if (length < 0.01f || length > end)
        length = end - start;
    if (start >= t)
        return before;
    if (start + length <= t)
        return after;
    return FUN_000ac6a0((t - start) / length);
}
