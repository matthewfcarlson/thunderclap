class C_25240 {
  public:
    char pad[0x340];
    float value;
    void f(float);
};
void C_25240::f(float x) {
    if (x > value)
        value = x;
}