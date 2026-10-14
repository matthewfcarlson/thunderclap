class C_2c6f30 {
    char pad[0x18];
    float* arr[1];

  public:
    void F(int a, float* b, int c, float d);
};
void C_2c6f30::F(int a, float* b, int c, float d) {
    float* p = arr[c] + a * 2;
    p[0] = (b[0] - p[0]) * d + p[0];
    p[1] = (b[1] - p[1]) * d + p[1];
}