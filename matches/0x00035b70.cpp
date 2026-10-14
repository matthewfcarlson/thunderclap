struct State {
    char pad[0x308];
    float start, duration, end;
    void FUN_00035b70(float a, float b, float c);
};
void State::FUN_00035b70(float a, float b, float c) {
    if (b <= 0.0f)
        return;
    if (start > 0.0f && a > start) {
        b = b - (a - start);
    } else
        start = a;
    if (duration > 0.0f && b < duration) {
        c = c - (duration - b);
    } else
        duration = b;
    if (!(end > 0.0f) || !(c > end))
        end = c;
}
