class Sprite {
  public:
    char pad[0x90];
    unsigned a, b, c, d;
    void vfunc_12(unsigned* out);
};
void Sprite::vfunc_12(unsigned* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = d;
}