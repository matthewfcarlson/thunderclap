// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0028a1c0 @ 0x0028a1c0
struct Curve_28a1c0 {
    char pad0[4];
    int enabled;
    char pad8[12];
    short* times;
    float* values;
    bool FUN_00289f80(float time, int* first, int* second);
    void FUN_0028a1c0(float time, float* output);
};
void Curve_28a1c0::FUN_0028a1c0(float time, float* output) {
    int first, second;
    if (FUN_00289f80(time, &first, &second) && enabled) {
        double delta = (double)time - times[first];
        if (delta != 0.0f) {
            *output = (float)(((double)values[second] - values[first]) / (times[second] - times[first]) * delta + values[first]);
            return;
        }
    }
    *output = values[first];
}
