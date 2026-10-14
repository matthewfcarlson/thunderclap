extern const float gBias;
extern float gValue_1e87c0;
void __stdcall FUN_001e87c0(int param_1) {
    if (param_1 < 0) {
        gValue_1e87c0 -= (float)param_1 + gBias;
    } else {
        gValue_1e87c0 -= (float)param_1;
    }
}