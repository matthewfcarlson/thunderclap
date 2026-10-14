const float gRad = 0.0174533f;

class Obj_1927a0 {
  public:
    char Fn(float f);
    char pad[0x14];
    float mAngle;
};

char Obj_1927a0::Fn(float f) {
    mAngle = f * gRad;
    return 1;
}
