extern float __cdecl FUN_0004af40(float, float, float);
extern const float degToRad;
class Obj {
    char pad[0x18];
    float angle;

  public:
    bool Set(float a);
};
bool Obj::Set(float a) {
    angle = FUN_0004af40(-180.0f, 180.0f, a) * degToRad;
    return true;
}