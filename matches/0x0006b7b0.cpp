extern float FUN_0004af40(float, float, float);
class X {
    char pad[0x18];
    float angle;

  public:
    char Set(float v);
};
char X::Set(float v) {
    angle = FUN_0004af40(-180.0f, 180.0f, v) * 0.017453292f;
    return 1;
}