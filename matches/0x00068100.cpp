class Obj {
  public:
    char pad[0x38];
    float angle;
    bool SetAngle(float x);
};
bool Obj::SetAngle(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}