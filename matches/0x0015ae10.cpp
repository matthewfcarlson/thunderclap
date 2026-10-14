class C_15ae10 {
  public:
    char pad[0x20];
    float mAngle;
    char Set(float a);
};

char C_15ae10::Set(float a) {
    mAngle = a * 0.017453292f;
    return 1;
}
