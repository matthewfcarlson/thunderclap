class C_2c3d20 {
    char pad[0x60];
    int value;

  public:
    void f(int a, int b, int* out);
};
void C_2c3d20::f(int a, int b, int* out) {
    *out = value;
}