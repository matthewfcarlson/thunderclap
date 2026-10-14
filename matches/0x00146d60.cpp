class Layout_146d60 {
  public:
    char pad[0x2c];
    float mAngle;
    bool Set(float angle);
};

bool Layout_146d60::Set(float angle) {
    mAngle = angle * 0.017453292519943295f;
    return true;
}
