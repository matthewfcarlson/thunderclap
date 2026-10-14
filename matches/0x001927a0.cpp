const float gRad = 0.0174533f;

class Obj {
  public:
    char Fn(float f);
    char pad[0x14];
    float mAngle;
};

char Obj::Fn(float f) {
    mAngle = f * gRad;
    return 1;
}
