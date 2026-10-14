class X {
  public:
    char pad[0x34];
    float mRadians;
    bool Set(float deg);
};

bool X::Set(float deg) {
    mRadians = deg * 0.0174532925f;
    return true;
}
