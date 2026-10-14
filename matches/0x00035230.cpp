class Obj_35230 {
    char pad[0x44];
    unsigned a, b, c;

  public:
    bool f(unsigned* out);
};
bool Obj_35230::f(unsigned* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    return true;
}