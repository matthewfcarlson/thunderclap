const float rad_5d870 = 0.017453292f;
class Obj_5d870 {
  public:
    char Set(float a);
    char pad[0x14];
    float mAngle;
};

char Obj_5d870::Set(float a) {
    mAngle = a * rad_5d870;
    return 1;
}
