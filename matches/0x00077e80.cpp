class Target {
  public:
    char pad[0x28];
    float mAngle;
    char SetAngle(float x);
};

char Target::SetAngle(float x) {
    mAngle = x * 0.017453293f;
    return 1;
}
