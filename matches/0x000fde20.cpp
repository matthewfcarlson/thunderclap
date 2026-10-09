class C {
  public:
    char pad[0x74];
    int value;
    int a;
    int b;
    int c;
    int f(int* out);
};
int C::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return value;
}