class C {
  public:
    char pad[0x24];
    float mVal;
    char Fn(float x);
};

char C::Fn(float x) {
    mVal = x * 0.0174532925f;
    return 1;
}
