union U_14d180 {
    unsigned u;
    float f;
};
static const U_14d180 kU = {0x3c8efa35u};
class C_14d180 {
  public:
    char Fn(float x);
    char pad[0x20];
    float mAngle;
};
char C_14d180::Fn(float x) {
    mAngle = x * kU.f;
    return 1;
}
