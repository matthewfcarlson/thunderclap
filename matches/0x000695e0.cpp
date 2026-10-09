extern const float minusOne;
class A {
    char pad[0x18];
    float values[8];

  public:
    float f(int i);
};
float A::f(int i) {
    if (i >= 0 && i < 8)
        return values[i];
    return minusOne;
}