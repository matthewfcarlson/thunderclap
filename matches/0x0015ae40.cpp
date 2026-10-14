class C_15ae40 {
  public:
    char pad[0x24];
    float mVal;
    char Fn(float x);
};

char C_15ae40::Fn(float x) {
    mVal = x * 0.0174532925f;
    return 1;
}
