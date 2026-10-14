class X_28a080 {
  public:
    char pad[0x14];
    short* a;
    int* b;
    void f(int i, float* out, int* out2);
};
void X_28a080::f(int i, float* out, int* out2) {
    *out = (float)a[i];
    *out2 = b[i];
}