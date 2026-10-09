class A {
    char pad[0x28];

  public:
    float x;
    float y;
    float F(float v);
};
float A::F(float v) {
    if (v <= 0.0f)
        return 0.0f;
    if (v <= 0.5f)
        return (v + v) * x;
    if (v < 1.0f) {
        float t = v - 0.5f;
        t = t + t;
        return t * y + (1.0f - t) * x;
    }
    return v * y;
}