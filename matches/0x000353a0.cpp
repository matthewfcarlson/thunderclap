struct Triple_353a0 {
    unsigned a, b, c;
};
class Target_353a0 {
    char pad[0x90];
    unsigned x, y, z;

  public:
    bool Copy(Triple_353a0* out);
};
bool Target_353a0::Copy(Triple_353a0* out) {
    out->a = x;
    out->b = y;
    out->c = z;
    return true;
}