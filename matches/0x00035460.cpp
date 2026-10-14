class C_35460 {
    char pad[0xa8];
    unsigned a, b, c;

  public:
    bool F(unsigned* out);
};
bool C_35460::F(unsigned* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}