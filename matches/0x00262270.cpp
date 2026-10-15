extern const float minimum;
int convert(float x) {
    if (x < minimum)
        x = -100.0f;
    int n = (int)(x * 100.0f);
    if (n > 0)
        return 0;
    if (n < -10000)
        n = -10000;
    return n;
}