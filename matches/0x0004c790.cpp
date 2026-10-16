extern float __cdecl FUN_0004af40(float, float, float);
extern const float scale;
class Thing {
    char pad[0x10];
    float angle;

  public:
    bool Set(float x);
};
bool Thing::Set(float x) {
    angle = FUN_0004af40(0.0f, 360.0f, x) * scale;
    return true;
}