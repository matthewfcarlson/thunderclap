extern const float oneThird;
void FUN(float* out, int mode, float* range, float value) {
    *out = 1.0f;
    if (mode == 1) {
        if (value < range[0]) {
            *out = 1.0f;
            return;
        }
        if (value < range[1]) {
            *out = oneThird - (value - range[0]) / (range[1] - range[0]);
            return;
        }
        *out = 0.0f;
    }
}