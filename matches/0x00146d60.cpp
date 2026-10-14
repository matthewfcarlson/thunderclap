class Layout {
  public:
    char pad[0x2c];
    float mAngle;
    bool Set(float angle);
};

bool Layout::Set(float angle) {
    mAngle = angle * 0.017453292519943295f;
    return true;
}
