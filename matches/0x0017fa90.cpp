class Obj {
    char pad[0x40];
    float angle;

  public:
    bool SetAngle(float x);
};
bool Obj::SetAngle(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}