class Obj {
  public:
    char pad[0x28];
    float mAngle;
    char Set(float a);
};

char Obj::Set(float a) {
    mAngle = a * 0.017453292f;
    return 1;
}