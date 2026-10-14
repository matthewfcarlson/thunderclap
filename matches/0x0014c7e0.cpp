class C_14c7e0 {
  public:
    char pad[0x18];
    float mDeg;
    char Fn(float x);
};

char C_14c7e0::Fn(float x) {
    mDeg = x * 0.0174532925f;
    return 1;
}
