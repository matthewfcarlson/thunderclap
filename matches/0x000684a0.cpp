class Obj_684a0 {
  public:
    char pad[0x28];
    float mAngle;
    char Set(float a);
};

char Obj_684a0::Set(float a) {
    mAngle = a * 0.017453292f;
    return 1;
}