class O {
  public:
    char pad[0x14];
    float mAngle;
    bool SetAngle(float a);
};
bool O::SetAngle(float a) {
    mAngle = a * 0.017453292519943295f;
    return true;
}