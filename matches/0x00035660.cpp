class C_35660 {
    char pad[0x74];
    int a, b, c;

  public:
    bool f(int* out);
};
bool C_35660::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}