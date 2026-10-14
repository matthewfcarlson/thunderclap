class C_fde40 {
    char pad[0x1c];
    int a;
    int b;
    int c;

  public:
    bool f(int* out);
};
bool C_fde40::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}