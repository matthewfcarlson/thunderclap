class Obj {
  public:
    char pad[0x3c];
    float angle;
    bool SetAngle(float x);
};
bool Obj::SetAngle(float x) {
    angle = x * 0.017453292f;
    return true;
}