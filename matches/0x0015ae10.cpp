class C {
  public:
    char pad[0x20];
    float mAngle;
    char Set(float a);
};

char C::Set(float a) {
    mAngle = a * 0.017453292f;
    return 1;
}
