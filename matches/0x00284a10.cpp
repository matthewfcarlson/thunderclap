extern const float kZero;
extern const float kOne;
extern const float kThree;

float FUN_00284a10(float x) {
    if (x <= kZero) return kZero;
    if (x >= kOne) return kOne;
    return (kThree - (x + x)) * x * x;
}
