class C_15ade0 {
  public:
    char pad[0x1c];
    float mAngle;
    char Fn(float x);
};

char C_15ade0::Fn(float x) {
    mAngle = x * 0.0174532925f;
    return 1;
}
