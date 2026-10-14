class Base {
  public:
    virtual void F0();
    char pad[0x80];
    float mAngle;
    bool SetRadians(float r);
};
bool Base::SetRadians(float r) {
    float k = 0.017453292f;
    float t = r * k;
    mAngle = t;
    return true;
}
