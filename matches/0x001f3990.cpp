extern float gHundred;
void Apply(int, float);
class Thing_1f3990 {
  public:
    char pad0[0x8c];
    int mA;
    char pad1[0x32c - 0x90];
    int mB;
    void Set(float);
};
void Thing_1f3990::Set(float x) {
    gHundred = x;
    if (mA && !mB) {
        int v = *(int*)(mA + 4);
        if (v)
            Apply(v, x * 0.01f);
    }
}