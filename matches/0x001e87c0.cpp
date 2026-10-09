extern const float gBias;
extern float gValue;
void __stdcall FUN_001e87c0(int param_1) {
    if (param_1 < 0) {
        gValue -= (float)param_1 + gBias;
    } else {
        gValue -= (float)param_1;
    }
}