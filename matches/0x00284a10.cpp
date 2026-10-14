extern const float kZero_284a10;
extern const float kOne;
extern const float kThree;

float FUN_00284a10(float x) {
    if (x <= kZero_284a10)
        return kZero_284a10;
    if (x >= kOne)
        return kOne;
    return (kThree - (x + x)) * x * x;
}
