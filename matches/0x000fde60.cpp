class C_fde60 {
    char pad[0x38];

  public:
    int a, b, c;
    bool f(int* out);
};
bool C_fde60::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}