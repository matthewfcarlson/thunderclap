class Target_77e80 {
  public:
    char pad[0x28];
    float mAngle;
    char SetAngle(float x);
};

char Target_77e80::SetAngle(float x) {
    mAngle = x * 0.017453293f;
    return 1;
}
