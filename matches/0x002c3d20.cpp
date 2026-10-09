class C {
    char pad[0x60];
    int value;

  public:
    void f(int a, int b, int* out);
};
void C::f(int a, int b, int* out) {
    *out = value;
}