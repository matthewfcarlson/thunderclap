extern const float kZero_15c4f0;
class C_15c4f0 {
  public:
    char pad[0x28];
    float m;
    float f(float x);
};
float C_15c4f0::f(float x) {
    if (x <= kZero_15c4f0)
        return kZero_15c4f0;
    float t = x;
    *(int*)&x = 1;
    if (!(t > kZero_15c4f0))
        *(int*)&x = 0;
    return (float)*(int*)&x * m;
}
