extern const float kZero_2f0120;
void F(float a, float b, float* out, char* ok) {
    if (a < -b) {
        *out = -b;
        *ok = 0;
        return;
    }
    if (a < kZero_2f0120) {
        *out = a;
        *ok = 1;
        return;
    }
    if (a < b) {
        *out = a;
        *ok = 1;
        return;
    }
    *out = b;
    *ok = 0;
}
