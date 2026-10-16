extern float __cdecl FUN_0004af40(float, float, float);
class C {
  public:
    char pad[0x18];
    float angle;
    bool Set(float x);
};
bool C::Set(float x) {
    angle = FUN_0004af40(-180.0f, 180.0f, x) * 0.017453292f;
    return true;
}