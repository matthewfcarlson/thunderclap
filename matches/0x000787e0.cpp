class R {
  public:
    unsigned a, b;
    float Next(float lo, float hi);
};
inline unsigned Step(unsigned* s, unsigned m) {
    *s = (*s & 0xffff) * m + (*s >> 16);
    return *s;
}
float R::Next(float lo, float hi) {
    Step(&a, 0x9069);
    unsigned t = Step(&b, 18000);
    unsigned u = (a << 16) + (t & 0xffff) & 0x7fffff | 0x3f800000;
    return (*(float*)&u - 1.0f) * (hi - lo) + lo;
}
