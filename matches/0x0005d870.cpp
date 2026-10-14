const float rad = 0.0174533f;
class Obj {
  public:
    char Set(float a);
    char pad[0x14];
    float mAngle;
};

char Obj::Set(float a) {
    mAngle = a * rad;
    return 1;
}
