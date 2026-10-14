class A_1434e0 {
  public:
    char pad[0x34];
    float mAngle;
    char SetAngle(float x);
};

char A_1434e0::SetAngle(float x) {
    mAngle = x * 0.017453292f;
    return 1;
}
